/*                                                                                File Access
                                       FILE ACCESS
                                             
 */
/*
**      (c) COPYRIGHT MIT 1995.
**      Please first read the full copyright statement in the file COPYRIGH.
*/
/*

   These are routines for local file access used by WWW browsers and servers.
   
   This module is implemented by HTFile.c, and it is a part of the  W3C Reference Library.
   
 */
#ifndef HTFILE_H
#define HTFILE_H

#include "HTEvntrg.h"

extern HTEventCallback HTLoadFile;
/*

Directory Access

   You can define the directory access for file URLs by using the following function.
   
 */
typedef enum _HTDirAccess {
    HT_DIR_FORBID,                      /* Altogether forbidden */
    HT_DIR_SELECTIVE,                   /* Only if "selfile" exists */
    HT_DIR_OK                           /* Directory reading always OK */
} HTDirAccess;

#define DEFAULT_DIR_FILE        ".www_browsable"    /* If exists, can browse */

extern HTDirAccess  HTFile_dirAccess    (void);
extern BOOL HTFile_setDirAccess         (HTDirAccess mode);
/*

Readme Files

   You can specify the module to look for a README file and to put into a directory
   listing. These are the possibilities:
   
 */
typedef enum _HTDirReadme {
    HT_DIR_README_NONE,
    HT_DIR_README_TOP,
    HT_DIR_README_BOTTOM
} HTDirReadme;

#define DEFAULT_README          "README"

extern HTDirReadme  HTFile_dirReadme    (void);
extern BOOL HTFile_setDirReadme         (HTDirReadme mode);
/*

 */
#endif /* HTFILE_H */
/*

   End of declaration of HTFile module  */
