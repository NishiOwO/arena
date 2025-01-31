/*                                        ExtParse: Module to get unparsed stream from libwww
                    XPARSE: MODULE TO GET UNPARSED STREAM FROM LIBWWW
                                             
 */
/*
**      (c) COPYRIGHT MIT 1995.
**      Please first read the full copyright statement in the file COPYRIGH.
*/
/*

   This version of the stream object is a hook for clients that want an unparsed stream
   from libwww. The HTXParse_put_* and HTXParse_write routines copy the content of the
   incoming buffer into a buffer that is realloced whenever necessary. This buffer is
   handed over to the client in HTXParse_free. See also HTFWriter for writing to C files.
   
  BUGS:
  
      strings written must be less than buffer size.
      
   This module is implemented by HTXParse.c, and it is a part of the  W3C Reference
   Library.
   
 */
#ifndef HTXPARSE_H
#define HTXPARSE_H

#include "HTStream.h"
#include "HTReq.h"

typedef struct _HTXParseStruct HTXParseStruct;

typedef void CallClient (HTXParseStruct * me);

struct _HTXParseStruct {
        CallClient      *call_client;
        int             used;         /* how much of the buffer is being used*/
        BOOL            finished;     /* document loaded? */
        int             length;       /* how long the buffer is */
        char *          buffer;       /* storage in until client takes over */
        char *          content_type;
        HTRequest *     request;      /* the request structure */
};

extern HTConverter HTXParse;

#endif
/*

   End of declaration */
