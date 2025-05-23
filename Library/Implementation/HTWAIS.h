/*                                                                       WAIS protocol module
                                 WAIS PROTOCOL INTERFACE
                                             
 */
/*
**      (c) COPYRIGHT MIT 1995.
**      Please first read the full copyright statement in the file COPYRIGH.
*/
/*

   This module does not actually perform the WAIS protocol directly, but it does using one
   or more libraries of the freeWAIS distribution. The ui.a library came with the old free
   WAIS from TMC,  the client.a and wais.a libraries are needed from the freeWAIS from
   CNIDR.
   
   Note: The current version suppored is freeWAIS-0.3, June 1994
   
   If you include this module in the library, you must also
   
       Register the HTWAIS protocol at initialisation (e.g. HTInit or HTSInit)      by
      compiling it with -DHT_DIRECT_WAIS
      
       Link with the WAIS libraries
      
   The wais source files are parsed by a separate and independent module, HTWSRC.  You can
   include HTWSRC without including direct wais using this module, and your WWW code will
   be able to read source files, and access WAIS indexes through a gateway.
   
   A WAIS-WWW gateway is just a normal W3 server with a libwww compiled with this module.
   
   This module is implemented by HTWAIS.c, and it is a part of the W3C Reference Library.
   
 */
#ifndef HTWAIS_H
#define HTWAIS_H

#include "HTEvntrg.h"
/*

Control Flags

   The number of lines handled from a WAIS search is determined by this variable. The
   default value is 100 (this is defined in the module)
   
 */
extern int HTMaxWAISLines;

extern HTEventCallback HTLoadWAIS;
/*

   End of Difinition module
   
 */
#endif

/*

                                                                                    Tim BL
                                                                                          
    */
