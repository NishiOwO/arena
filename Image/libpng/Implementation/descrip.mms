
cc_defs = /inc=$(ZLIBSRC)
c_deb = 

.ifdef __DECC__
pref = /prefix=all
.endif



OBJS = png.obj, pngrcb.obj, pngrutil.obj, pngtrans.obj, pngwutil.obj,\
	pngread.obj, pngmem.obj, pngwrite.obj, pngrtran.obj, pngwtran.obj,\
	pngio.obj, pngerror.obj, pngpread.obj


CFLAGS= $(C_DEB) $(CC_DEFS) $(PREF)

all : pngtest.exe libpng.olb
		@ write sys$output " pngtest available"

libpng.olb : libpng.olb($(OBJS))
	@ write sys$output " Libpng available"


pngtest.exe : pngtest.obj libpng.olb
              link pngtest,libpng.olb/lib,$(ZLIBSRC)libz.olb/lib

test : pngtest.exe
   run pngtest

clean :
	delete *.obj;*,*.exe;*


# Other dependencies.
png.obj : png.h, pngconf.h
pngpread.obj : png.h, pngconf.h
pngrcb.obj : png.h, pngconf.h
pngread.obj : png.h, pngconf.h
pngrtran.obj : png.h, pngconf.h
pngrutil.obj : png.h, pngconf.h
pngerror.obj : png.h, pngconf.h
pngmem.obj : png.h, pngconf.h
pngio.obj : png.h, pngconf.h
pngtest.obj : png.h, pngconf.h
pngtrans.obj : png.h, pngconf.h
pngwrite.obj : png.h, pngconf.h
pngwtran.obj : png.h, pngconf.h
pngwutil.obj : png.h, pngconf.h

