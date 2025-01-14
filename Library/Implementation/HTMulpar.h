/*                                                           MIME Multipart Stream Definition
                             MIME MULTIPART STREAM DEFINITION
                                             
 */
/*
**      (c) COPYRIGHT MIT 1995.
**      Please first read the full copyright statement in the file COPYRIGH.
*/
/*

   This module is a part of the  W3C Reference Library.
   
 */
#ifndef HTMULPAR_H
#define HTMULPAR_H

#include "HTStream.h"
#include "HTList.h"
/*

   The MIME multipart stream is used to parse MIME multipart messages. It works a bit like
   a structured stream in that it has some methods to begin and end MIME body just as a
   structured stream has methods for beginning and ending tags.
   
   The HTMultipart stream is a subclass of a Generic Stream Object. As always, we don't
   have classes in basic C so we have to do this by hand!
   
 */
typedef struct _HTMultipart HTMultipart;

typedef struct _HTMultipartClass {

    char * name;

    int (*flush)        (HTMultipart *  me);

    int (*_free)        (HTMultipart *  me);

    int (*abort)        (HTMultipart *  me, HTList * errorlist);

    int (*put_character)(HTMultipart *  me, char ch);

    int (*put_string)   (HTMultipart *  me, CONST char * str);

    int (*put_block)    (HTMultipart *  me, CONST char * str, int len);
/*

   See the Generic Stream Definition for an explanation of these methods. Note that they
   all have a HTMultipart object a the parameter, not a generic stream. This is to avoid
   incompatible pointer warnings
   
 */
    int (*begin_part)   (HTMultipart *  me, CONST char * boundary);

    int (*end_part)     (HTMultipart *  me);

    int (*preamble)     (HTMultipart *  me, CONST char * pre);

    int (*epilogue)     (HTMultipart *  me, CONST char * epi);
                
} HTMultipartClass;

#endif
/*

   End of Multipart Stream definition */
