/*                                                                                 Tee stream
                                        TEE STREAM
                                             
 */
/*
**      (c) COPYRIGHT MIT 1995.
**      Please first read the full copyright statement in the file COPYRIGH.
*/
/*

   The Tee stream just writes everything you put into it into two oter streams. One use
   (the only use?!) is for taking a cached copey on disk while loading the main copy,
   without having to wait for the disk copy to be finished and reread it.
   
   You can create a T stream using this method. Each stream returns a return value and in
   order to resolve conflicts in the return code you can specify a resolver callback
   function. Each time any of the data methods are called the resolver function is then
   called with the return codes from the two streams. The return code of the T stream
   itself will be the result of the resolver function. If you pass NULL as the resolver
   routine then a default resolver is used.
   
   This module is implemented by HTTee.c, and it is a part of the  W3C Reference Library.
   
 */
#include "HTStream.h"
#include "HTArray.h"

extern HTStream * HTTee (HTStream * s1, HTStream * s2, HTComparer * resolver);
/*

   End of definition  */
