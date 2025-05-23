/*								      HTMulti.c
**	MULTIFORMAT HANDLING
**
**	(c) COPYRIGHT MIT 1995.
**	Please first read the full copyright statement in the file COPYRIGH.
**
** History:
**	March 94  AL	Separated from HTFile.c because
**			multiformat handling would be a mess in VMS.
*/

/* Library include files */
#include "tcp.h"
#include "HTUtils.h"
#include "HTString.h"
#include "HTMulti.h"
#include "HTFile.h"
#include "HTBind.h"
#include "HTList.h"
#include "HTReqMan.h"

PRIVATE HTList * welcome_names = NULL;	/* Welcome.html, index.html etc. */


/* PUBLIC						HTSplitFilename()
**
**	Split the filename to an array of suffixes.
**	Return the number of parts placed to the array.
**	Array should have MAX_SUFF+1 items.
*/
PRIVATE int HTSplitFilename (char * s_str, char ** s_arr)
{
    CONST char *delimiters = HTBind_delimiters();
    char * start = s_str;
    char * end;
    char save;
    int i;

    if (!s_str || !s_arr) return 0;

    for (i=0; i < MAX_SUFF && *start; i++) {
	for(end=start+1; *end && !strchr(delimiters, *end); end++);
	save = *end;
	*end = 0;
	StrAllocCopy(s_arr[i], start);	/* Frees the previous value */
	*end = save;
	start = end;
    }
    HT_FREE(s_arr[i]);       /* Terminating NULL */
    return i;
}


/*
**	Set default file name for welcome page on each directory.
*/
PUBLIC void HTAddWelcome (char * name)
{
    if (name) {
	char * mycopy = NULL;
	StrAllocCopy(mycopy,name);

	if (!welcome_names)
	    welcome_names = HTList_new();
	HTList_addObject(welcome_names, (void*)mycopy);
    }
}


#ifdef GOT_READ_DIR

/* PRIVATE						multi_match()
**
**	Check if actual filename (split in parts) fulfills
**	the requirements.
*/
PRIVATE BOOL multi_match (char ** required, int m, char ** actual, int n)
{
    int c;
    int i,j;

#ifdef VMS
    for(c=0;  c<m && c<n && !strcasecomp(required[c], actual[c]);  c++);
#else /* not VMS */
    for(c=0;  c<m && c<n && !strcmp(required[c], actual[c]);  c++);
#endif /* not VMS */

    if (!c) return NO;		/* Names differ rigth from start */

    for(i=c; i<m; i++) {
	BOOL found = NO;
	for(j=c; j<n; j++) {
#ifdef VMS
	    if (!strcasecomp(required[i], actual[j])) {
#else /* not VMS */
	    if (!strcmp(required[i], actual[j])) {
#endif /* not VMS */
		found = YES;
		break;
	    }
	}
	if (!found) return NO;
    }
    return YES;
}


/*
**	Get multi-match possibilities for a given file
**	----------------------------------------------
** On entry:
**	path	absolute path to one file in a directory,
**		may end in .multi.
** On exit:
**	returns	a list of ContentDesription structures
**		describing the mathing files.
**
*/
PRIVATE HTList * dir_matches (char * path)
{
    static char * required[MAX_SUFF+1];
    static char * actual[MAX_SUFF+1];
    int m,n;
    char * dirname = NULL;
    char * basename = NULL;
    int baselen;
    char * multi = NULL;
    DIR * dp;
    STRUCT_DIRENT * dirbuf;
    HTList * matches = NULL;
#ifdef HT_REENTRANT
    STRUCT_DIRENT result;				    /* For readdir_r */
#endif

    if (!path) return NULL;

    StrAllocCopy(dirname, path);
    basename = (strrchr(dirname, '/'));
    if (!basename)
	goto dir_match_failed;
    *basename++ = 0;

    multi = strrchr(basename, MULTI_SUFFIX[0]);
    if (multi && !strcasecomp(multi, MULTI_SUFFIX))
	*multi = 0;
    baselen = strlen(basename);

    m = HTSplitFilename(basename, required);

    dp = opendir(dirname);
    if (!dp) {
	if (PROT_TRACE)
	    TTYPrint(TDEST,"Warning..... Can't open directory %s\n", dirname);
	goto dir_match_failed;
    }

    matches = HTList_new();
#ifdef HT_REENTRANT
	while ((dirbuf = (STRUCT_DIRENT *) readdir_r(dp, &result))) {
#else
	while ((dirbuf = readdir(dp))) {
#endif /* HT_REENTRANT */
#ifndef __QNX__ /* doesn't return unused directory slots */
	if (!dirbuf->d_ino) continue;	/* Not in use */
#endif
	if (!strcmp(dirbuf->d_name,".") ||
	    !strcmp(dirbuf->d_name,"..") ||
	    !strcmp(dirbuf->d_name, DEFAULT_DIR_FILE))
	    continue;

	/* Use of direct->namlen is only valid in BSD'ish system */
	/* Thanks to chip@chinacat.unicom.com (Chip Rosenthal) */
	/* if ((int)(dirbuf->d_namlen) >= baselen) { */
	if ((int) strlen(dirbuf->d_name) >= baselen) {
	    n = HTSplitFilename(dirbuf->d_name, actual);
	    if (multi_match(required, m, actual, n)) {
		HTContentDescription * cd;
		cd = HTBind_getDescription(dirbuf->d_name);
		if (cd) {
		    if (cd->content_type) {
			if ((cd->filename = (char *) HT_MALLOC(strlen(dirname) + 2 + strlen(dirbuf->d_name))) == NULL)
			    HT_OUTOFMEM("dir_matches");
			sprintf(cd->filename, "%s/%s",
				dirname, dirbuf->d_name);
			HTList_addObject(matches, (void*)cd);
		    }
		    else HT_FREE(cd);
		}
	    }
	}
    }
    closedir(dp);

  dir_match_failed:
    HT_FREE(dirname);
    return matches;
}


/*
**	Get the best match for a given file
**	-----------------------------------
** On entry:
**	req->conversions  accepted content-types
**	req->encodings	  accepted content-transfer-encodings
**	req->languages	  accepted content-languages
**	path		  absolute pathname of the filename for
**			  which the match is desired.
** On exit:
**	returns	a newly allocated absolute filepath.
*/
PRIVATE char * HTGetBest (HTRequest * req, char * path)
{
    HTList * matches;
    HTList * cur;
    HTContentDescription * cd;
    HTContentDescription * best = NULL;
    char * best_path = NULL;

    if (!path || !*path) return NULL;

    matches = dir_matches(path);
    if (!matches) {
	if (PROT_TRACE)
	    TTYPrint(TDEST, "No matches.. for \"%s\"\n", path);
	return NULL;
    }

    /* BEGIN DEBUG */
    cur = matches;
    if (PROT_TRACE)
	TTYPrint(TDEST, "Multi....... Possibilities for \"%s\"\n", path);
    if (PROT_TRACE)
	TTYPrint(TDEST, "\nCONTENT-TYPE  LANGUAGE  ENCODING  QUALITY  FILE\n");
    while ((cd = (HTContentDescription*)HTList_nextObject(cur))) {
	if (PROT_TRACE)
	   TTYPrint(TDEST, "%s\t%s\t%s\t  %.5f  %s\n",
		   cd->content_type    ?HTAtom_name(cd->content_type)  :"-\t",
		   cd->content_language?HTAtom_name(cd->content_language):"-",
		   cd->content_encoding?HTAtom_name(cd->content_encoding):"-",
		   cd->quality,
		   cd->filename        ?cd->filename                     :"-");
    }
    if (PROT_TRACE) TTYPrint(TDEST, "\n");
    /* END DEBUG */

    /*
    ** Finally get best that is readable
    */
    if (HTRank(matches, req->conversions, req->languages, req->encodings)) {
	cur = matches;
	while ((best = (HTContentDescription*)HTList_nextObject(cur))) {
	    if (best && best->filename) {
		if (access(best->filename, R_OK) != -1) {
		    StrAllocCopy(best_path, best->filename);
		    break;
		} else if (PROT_TRACE)
		    TTYPrint(TDEST, "Bad News.... \"%s\" is not readable\n",
			    best->filename);
	    }
	}
    } /* Select best */

    cur = matches;
    while ((cd = (HTContentDescription*)HTList_nextObject(cur))) {
	if (cd->filename) HT_FREE(cd->filename);
	HT_FREE(cd);
    }
    HTList_delete(matches);

    return best_path;
}



PRIVATE int welcome_value (char * name)
{
    HTList * cur = welcome_names;
    char * welcome;
    int v = 0;

    while ((welcome = (char*)HTList_nextObject(cur))) {
	v++;
	if (!strcmp(welcome,name)) return v;
    }
    return 0;
}



PRIVATE char * get_best_welcome (char * path)
{
    char * best_welcome = NULL;
    int best_value = 0;
    DIR * dp;
    STRUCT_DIRENT * dirbuf;
    char * last = strrchr(path, '/');

    if (!welcome_names) {
	HTAddWelcome("Welcome.html");
	HTAddWelcome("welcome.html");
#if 0
	HTAddWelcome("Index.html");
#endif
	HTAddWelcome("index.html");
    }

    if (last && last!=path) *last = 0;
    dp = opendir(path);
    if (last && last!=path) *last='/';
    if (!dp) {
	if (PROT_TRACE)
	    TTYPrint(TDEST, "Warning..... Can't open directory %s\n",path);
	return NULL;
    }
    while ((dirbuf = readdir(dp))) {
	if (
#ifndef __QNX__ /* doesn't return unused directory slots */
	    !dirbuf->d_ino ||
#endif
	    !strcmp(dirbuf->d_name,".") ||
	    !strcmp(dirbuf->d_name,"..") ||
	    !strcmp(dirbuf->d_name, DEFAULT_DIR_FILE))
	    continue;
	else {
	    int v = welcome_value(dirbuf->d_name);
	    if (v > best_value) {
		best_value = v;
		StrAllocCopy(best_welcome, dirbuf->d_name);
	    }
	}
    }
    closedir(dp);

    if (best_welcome) {
	char * welcome;
	if ((welcome = (char *) HT_MALLOC(strlen(path) + strlen(best_welcome)+2)) == NULL)
	    HT_OUTOFMEM("get_best_welcome");
	sprintf(welcome, "%s%s%s", path, last ? "" : "/", best_welcome);
	HT_FREE(best_welcome);
	if (PROT_TRACE)
	    TTYPrint(TDEST,"Welcome..... \"%s\"\n",welcome);
	return welcome;
    }
    return NULL;
}

#endif /* GOT_READ_DIR */


/*
**	Do multiformat handling
**	-----------------------
** On entry:
**	req->conversions  accepted content-types
**	req->encodings	  accepted content-transfer-encodings
**	req->languages	  accepted content-languages
**	path		  absolute pathname of the filename for
**			  which the match is desired.
**	stat_info	  pointer to result space.
**
** On exit:
**	returns	a newly allocated absolute filepath of the best
**		match, or NULL if no match.
**	stat_info	  will contain inode information as
**			  returned by stat().
*/
PUBLIC char * HTMulti (HTRequest *	req,
		       char *		path,
		       struct stat *	stat_info)
{
    char * new_path = NULL;
    int stat_status = -1;

    if (!req || !path || !*path || !stat_info)
	return NULL;

#ifdef GOT_READ_DIR
    if (*(path+strlen(path)-1) == '/') {	/* Find welcome page */
	new_path = get_best_welcome(path);
	if (new_path) path = new_path;
    }
    else{
	char * multi = strrchr(path, MULTI_SUFFIX[0]);
	if (multi && !strcasecomp(multi, MULTI_SUFFIX)) {
	    if (PROT_TRACE)
		TTYPrint(TDEST, "Multi....... by %s suffix\n", MULTI_SUFFIX);
	    if (!(new_path = HTGetBest(req, path))) {
		if (PROT_TRACE)
		    TTYPrint(TDEST, "Multi....... failed -- giving up\n");
		return NULL;
	    }
	    path = new_path;
	}
	else {
	    stat_status = HT_STAT(path, stat_info);
	    if (stat_status == -1) {
		if (PROT_TRACE)
		    TTYPrint(TDEST,
			    "AutoMulti... can't stat \"%s\"(errno %d)\n",
			    path, errno);
		if (!(new_path = HTGetBest(req, path))) {
		    if (PROT_TRACE)
			TTYPrint(TDEST, "AutoMulti... failed -- giving up\n");
		    return NULL;
		}
		path = new_path;
	    }
	}
    }
#endif /* GOT_READ_DIR */

    if (stat_status == -1)
	stat_status = HT_STAT(path, stat_info);
    if (stat_status == -1) {
	if (PROT_TRACE)
	    TTYPrint(TDEST, "Stat fails.. on \"%s\" -- giving up (errno %d)\n",
		    path, errno);
	return NULL;
    }
    else {
	if (!new_path) {
	    StrAllocCopy(new_path, path);
	    return new_path;
	}
	else return path;
    }
}


