#  Make WWW under unix for linux
#

# For W3 distribution, machine type for subdirectories
WWW_MACH = linux

CFLAGS = -g -Wall -DPOSIXWAIT -DNO_TIMEZONE -DNO_GMTOFF -DHAVE_STRERROR -Wno-error=implicit-function-declaration
LFLAGS =
CC = cc

# Directory for installed binary:
BINDIR = /usr/arena/bin

# Where is the W3 object library to be installed (not normally done)?
LIBDIR = $(WWW)/Library/Implementation/$(WWW_MACH)

#_________________ OK if normal W3 distribution
# Where is the WWW source root?
WWW = ../..

#  Where should temporary (object) files go?
WTMP = ../..


#
#	WHEN COMPILING WITH DIRECT WAIS SUPPORT:
#
#	Uncomment these six lines (and edit them, if necessary).
#
# WAIS = ../../../freeWAIS
# WAISLIB =  $(WAIS)/bin/client.a $(WAIS)/bin/wais.a
# MATHLIB = -lm
# WAISINC = -I$(WAIS)/include
# WAISCFLAGS = -DHT_DIRECT_WAIS
# HTWAIS = $(WTMP)/Library/$(WWW_MACH)/HTWAIS.o

VC = 4.1
#	Common Makefile for W3C Reference Library
#	-----------------------------------------
#
#	(c) COPYRIGHT MIT 1995.
#	Please first read the full copyright statement in the file COPYRIGH.
#
# This file should be invariant between systems.
#	DEPENDENCIES NOT COMPLETE @@
#
#	make		Compile and link the software (private version)
#	make install	Copy it into the system (implies make)
#	make update	Copy installed version into installed version
#	make uninstall	Unlink installed version from the system
#	make clean	Remove intermediate files
#	make cleanall	Remove intremediate files and products
#	
# Macros required to be defined already for make:
#
# CC		The C compiler
# CFLAGS	Flags for $(CC) -- except the -I which are below
# LFLAGS	Flags for ld
#
# WWW           The WWW source tree directory
#
# Macros needed for make install:
#
# LIBDIR	Directory for installed library
#______________________________________________________________________

#  If this env var is set to something else Some makes will use that instead
SHELL = /bin/sh

#	.h files are distributed but originally are made from the
#	self-documenting hypertext files.
.SUFFIXES: .h .html
.html.h:
	#www -w90 -na -p -to text/x-c $*.html > $*.h

#	If this is actually run in a subdirectory,
# WWW = ../../..
# WWW = ../..

#	Directories
LOB = $(WTMP)/Library/$(WWW_MACH)
CMN = $(WWW)/Library/Implementation/
DOC = $(WWW)/Library/User
EXP = $(WWW)/Library/Examples
ICON= $(WWW)/Icons
TOP = $(WWW)/..
VMS = $(CMN)vms
WIN = $(CMN)windows
PROD= libwww
FTP = /afs/w3.org/devel/Dist/$(PROD)

CFLAGS2 = $(CFLAGS) $(WAISCFLAGS) -I$(CMN) $(SOCKS_FLAGS)

COMMON=	$(LOB)/HTList.o $(LOB)/HTString.o $(LOB)/HTAtom.o \
	$(LOB)/HTArray.o $(LOB)/HTBTree.o $(LOB)/HTChunk.o \
	$(LOB)/HTParse.o $(LOB)/HTAccess.o $(LOB)/HTProxy.o \
	$(LOB)/HTMethod.o $(LOB)/HTProt.o $(LOB)/HTCache.o \
	$(LOB)/HTNet.o $(LOB)/HTReqMan.o $(LOB)/HTBind.o \
	$(LOB)/HTTCP.o $(LOB)/HTDNS.o $(LOB)/HTAlert.o \
	$(LOB)/HTNetTxt.o $(LOB)/HTConLen.o $(LOB)/HTHeader.o \
	$(LOB)/SGML.o $(LOB)/HTML.o $(LOB)/HTMLPDTD.o \
	$(LOB)/HTPlain.o $(LOB)/HTWriter.o $(LOB)/HTFWrite.o \
	$(LOB)/HTMLGen.o $(LOB)/HTTee.o $(LOB)/HTXParse.o $(LOB)/HTEPtoCl.o \
	$(LOB)/HTAnchor.o $(LOB)/HTStyle.o $(LOB)/HTWWWStr.o \
	$(LOB)/HTRules.o $(LOB)/HTFormat.o $(LOB)/HTMemory.o \
	$(LOB)/HTInit.o $(LOB)/HTBInit.o \
	$(LOB)/HTMIME.o $(LOB)/HTMIMERq.o $(LOB)/HTBound.o \
	$(LOB)/HTHist.o $(LOB)/HTSocket.o $(LOB)/HTEvntrg.o \
	$(LOB)/HTUU.o $(LOB)/HTMulti.o $(LOB)/HTTeXGen.o \
	$(LOB)/HTAAUtil.o $(LOB)/HTAABrow.o $(LOB)/HTAssoc.o \
	$(LOB)/HTIcons.o $(LOB)/HTError.o $(LOB)/HTLog.o \
	$(LOB)/HTHome.o $(LOB)/HTDialog.o \
	$(LOB)/HTEscape.o $(LOB)/HTDescpt.o $(LOB)/HTGuess.o \
	$(LOB)/HTTelnet.o $(LOB)/HTWSRC.o $(HTWAIS) $(LOB)/HTGopher.o \
	$(LOB)/HTTP.o $(LOB)/HTTPServ.o \
	$(LOB)/HTTPGen.o $(LOB)/HTTPReq.o $(LOB)/HTTPRes.o \
	$(LOB)/HTFile.o $(LOB)/HTDir.o \
	$(LOB)/HTNews.o $(LOB)/HTNewsRq.o $(LOB)/HTNDir.o $(LOB)/HTNewsLs.o \
	$(LOB)/HTFTP.o  $(LOB)/HTFTPDir.o 

CFILES = $(CMN)HTParse.c $(CMN)HTAccess.c $(CMN)HTProxy.c \
	$(CMN)HTMethod.c $(CMN)HTProt.c $(CMN)HTCache.c \
	$(CMN)HTReqMan.c $(CMN)HTDNS.c $(CMN)HTArray.c \
        $(CMN)HTFile.c $(CMN)HTBTree.c $(CMN)HTMulti.c \
	$(CMN)HTFTP.c $(CMN)HTTCP.c     $(CMN)SGML.c $(CMN)HTML.c \
	$(CMN)HTMLPDTD.c $(CMN)HTDir.c $(CMN)HTFTPDir.c \
	$(CMN)HTPlain.c	$(CMN)HTWriter.c  $(CMN)HTFWrite.c \
        $(CMN)HTMLGen.c	$(CMN)HTTee.c $(CMN)HTXParse.c $(CMN)HTEPtoCl.c \
	$(CMN)HTChunk.c $(CMN)HTAtom.c   $(CMN)HTAnchor.c $(CMN)HTStyle.c \
	$(CMN)HTList.c  $(CMN)HTString.c $(CMN)HTAlert.c $(CMN)HTRules.c \
	$(CMN)HTFormat.c $(CMN)HTHist.c $(CMN)HTMemory.c \
	$(CMN)HTInit.c $(CMN)HTBInit.c \
	$(CMN)HTMIME.c $(CMN)HTMIMERq.c $(CMN)HTBound.c \
	$(CMN)HTConLen.c $(CMN)HTHeader.c \
	$(CMN)HTGopher.c $(CMN)HTTelnet.c \
	$(CMN)HTWAIS.c  $(CMN)HTWSRC.c $(CMN)HTSocket.c \
	$(CMN)HTAAUtil.c $(CMN)HTAABrow.c $(CMN)HTAssoc.c \
	$(CMN)HTUU.c $(CMN)HTTeXGen.c \
	$(CMN)HTDescpt.c $(CMN)HTGuess.c $(CMN)HTWWWStr.c \
	$(CMN)HTIcons.c $(CMN)HTError.c $(CMN)HTLog.c \
	$(CMN)HTHome.c $(CMN)HTDialog.c \
	$(CMN)HTTP.c $(CMN)HTTPServ.c \
	$(CMN)HTTPGen.c $(CMN)HTTPReq.c $(CMN)HTTPRes.c \
	$(CMN)HTNet.c $(CMN)HTEvntrg.c \
	$(CMN)HTNews.c $(CMN)HTNewsRq.c $(CMN)HTNDir.c $(CMN)HTNewsLs.c \
	$(CMN)HTEscape.c $(CMN)HTNetTxt.c $(CMN)HTBind.c

HFILES = $(CMN)HTParse.h $(CMN)HTAccess.h  $(CMN)HTProxy.h $(CMN)HTFile.h \
	$(CMN)HTMethod.h $(CMN)HTProt.h $(CMN)HTCache.h \
	$(CMN)HTReqMan.h $(CMN)HTReq.h  $(CMN)HTDNS.h $(CMN)HTArray.h \
	$(CMN)HTMulti.h $(CMN)HTBTree.h $(CMN)HTFTP.h $(CMN)HTTCP.h \
	$(CMN)SGML.h $(CMN)HTML.h $(CMN)HTMLPDTD.h $(CMN)HTChunk.h \
	$(CMN)HTNet.h $(CMN)HTNetMan.h $(CMN)HTFTPDir.h \
	$(CMN)HTPlain.h		$(CMN)HTWriter.h \
	$(CMN)HTFWrite.h 	$(CMN)HTMLGen.h	\
	$(CMN)HTEvntrg.h \
	$(CMN)HTStream.h $(CMN)HTStruct.h $(CMN)HTMulpar.h \
	$(CMN)HTTee.h $(CMN)HTXParse.h $(CMN)HTEPtoCl.h \
	$(CMN)HTAtom.h $(CMN)HTAnchor.h $(CMN)HTAncMan.h $(CMN)HTStyle.h \
	$(CMN)HTList.h $(CMN)HTWWWStr.h $(CMN)HTMemory.h \
	$(CMN)HTString.h $(CMN)HTAlert.h $(CMN)HTRules.h \
	$(CMN)HTFormat.h \
	$(CMN)HTInit.h $(CMN)HTBInit.h \
	$(CMN)HTMIME.h $(CMN)HTMIMERq.h $(CMN)HTBound.h \
	$(CMN)HTConLen.h $(CMN)HTHeader.h \
	$(CMN)HTHist.h \
	$(CMN)HTGopher.h $(CMN)HTDir.h \
	$(CMN)HTUtils.h $(CMN)tcp.h $(CMN)HText.h \
	$(CMN)HTTelnet.h \
	$(CMN)HTWAIS.h  $(CMN)HTWSRC.h $(CMN)HTSocket.h \
	$(CMN)HTAAUtil.h $(CMN)HTAABrow.h $(CMN)HTAssoc.h \
	$(CMN)HTUU.h $(CMN)HTTeXGen.h \
	$(CMN)HTDescpt.h $(CMN)HTGuess.h \
	$(CMN)HTIcons.h $(CMN)HTError.h $(CMN)HTLog.h \
	$(CMN)HTHome.h $(CMN)HTDialog.h \
	$(CMN)HTTP.h $(CMN)HTTPServ.h \
	$(CMN)HTTPGen.h $(CMN)HTTPReq.h $(CMN)HTTPRes.h \
	$(CMN)HTTPUtil.h \
	$(CMN)HTNews.h $(CMN)HTNewsRq.h $(CMN)HTNDir.h $(CMN)HTNewsLs.h \
	$(CMN)HTEscape.h $(CMN)HTNetTxt.h $(CMN)HTBind.h \
	$(CMN)WWWUtil.h $(CMN)WWWCore.h $(CMN)WWWLib.h \
	$(CMN)WWWDir.h $(CMN)WWWFTP.h $(CMN)WWWFile.h $(CMN)WWWGophe.h \
	$(CMN)WWWGuess.h $(CMN)WWWHTML.h $(CMN)WWWHTTP.h $(CMN)WWWMIME.h \
	$(CMN)WWWNews.h $(CMN)WWWRules.h $(CMN)WWWTelnt.h $(CMN)WWWWAIS.h \
	$(CMN)WWWCache.h $(CMN)WWWApp.h $(CMN)WWWInit.h

SOURCES = $(CFILES) $(HFILES) \
	$(CMN)Version.make \
	$(CMN)CommonMakefile \
	$(CMN)README \
	$(WWW)/Library/README \
	$(WWW)/Makefile \
	$(WWW)/BUILD \
	$(WWW)/BUILD.SH

ICONS = $(ICON)/WWW/Bug48x.gif \
	$(ICON)/WWW/Lib48x.gif \
	$(ICON)/WWW/w3c_48x48.gif \
	$(ICON)/WWW/Platform48x.gif \
	$(ICON)/WWW/design48x.gif \
	$(ICON)/WWW/doc48x.gif \
	$(ICON)/WWW/guide48x.gif \
	$(ICON)/WWW/internals48x.gif \
	$(ICON)/WWW/install48x.gif \
	$(ICON)/WWW/relnotes48x.gif \
	$(ICON)/WWW/bullet.gif \
	$(ICON)/32x32/smiley.gif \
	$(ICON)/32x32/caution.gif

LEGAL =	$(TOP)/WELCOME \
	$(WWW)/README \
	$(WWW)/COPYRIGH \
	$(WWW)/PATCHES \
	$(WWW)/CERN

DOCS =	$(CMN)*.html \
	`find $(DOC) -follow \( -name \*.html -o -name \*.gif \) -print`

SPECIFIC = \
	$(WWW)/All/Makefile.include \
	$(WWW)/All/*/Makefile.include \
	$(WWW)/All/Implementation/Makefile \
	$(DOC)/Patch/*.fix \
	$(WIN)/Makefile \
	$(WIN)/*.bat \
	$(WIN)/*.pl \
	$(EXP)/*.c \
	$(WIN)/*.mak \
	$(WIN)/*.def \
	$(WIN)/*.c \
	$(WIN)/*.h \
	$(WIN)/*.txt \
	$(VMS)/descrip.mms  $(VMS)/COPYING.LIB \
 	$(VMS)/build_multinet.com $(VMS)/build_multinet.com_alpha \
	$(VMS)/multinet.opt $(VMS)/multinet.opt_alpha \
	$(VMS)/build_ucx.com $(VMS)/build_ucx.com_alpha \
	$(VMS)/ucx.opt $(VMS)/ucx.opt_alpha \
	$(VMS)/patchlevel.h $(VMS)/ufc-crypt.h \
	$(VMS)/crypt.c $(VMS)/crypt_util.c \
	$(VMS)/getline.c $(VMS)/getpass.c \
	$(VMS)/HTVMSUtils.h $(VMS)/HTVMSUtils.c \
	$(VMS)/dirent.h $(VMS)/dirent.c $(VMS)/sys_dirent.h

TOTAL =	$(LEGAL) \
	$(SOURCES) \
	$(ICONS) \
	$(DOCS) \
	$(SPECIFIC)

all : inc $(LOB)/$(PROD).a

#	Library
#
#  On SGI, ranlib is unnecessary and does not exist so we ignore errors
# for that step.
#  On next 3.1 and following, the archive must be deleted before being
#	build, because has ranlib turned it from an archive of fat files
#	into a fat file of archives. Next time round, ar(1) is 
#	confused as the .a is now a fat file, not an archive.
#
$(LOB)/$(PROD).a : $(COMMON)
	- rm $(LOB)/$(PROD).a
	ar r $(LOB)/$(PROD).a $(COMMON)
	-ranlib $(LOB)/$(PROD).a

#	Include files 
inc : $(HFILES)
	@echo Include files generated from hypertext.

#	Clean up everything generatable except final products
clean :
	rm $(LOB)/*.o $(LOB)/.created
	-rmdir $(LOB)

#	Clean up everything generatable including final products

cleanall : clean
	rm $(LOB)/$(PROD).a

#	Install W3 library into system space (not normally necessary)

install : $(PROD).a
	if [ ! -r $(LIBDIR) ] mkdir $(LIBDIR)
	cp $(PROD).a $(LIBDIR)/$(PROD).a
	
uninstall :
	rm $(LIBDIR)/$(PROD).a

#		Distribution use only:
#		----------------------

#	Needs www version 2.4 or later to do this
$(FTP)/$(WWW_MACH)/$(PROD)_$(VC).a : $(PROD).a
	-mkdir $(FTP)/$(WWW_MACH)
	cp $(PROD).a $(FTP)/$(WWW_MACH)/$(PROD)_$(VC).a

#	Make a new branch (for main releases only)
maindist : inc $(LEGAL) $(SOURCES)
	(cd $(WWW)/..; WWW=WWW ABS=`pwd`/ make $(MFLAGS) \
	-f WWW/Library/Implementation/Version.make \
	-f WWW/Library/Implementation/CommonMakefile \
	$(FTP)/$(PROD)_$(VC)_src.tar.Z)
	(cd $(WWW); cvs tag -b \
	    `sed -e 's/VC = /v/' Library/Implementation/Version.make | sed -e 's?\.?/?'` \
	    Library)
	@echo MAIN RELEASE of Library version $(VC) up to date.

#	Make a new CVS release
distribute : inc $(LEGAL) $(SOURCES)
	(cd $(WWW)/..; WWW=WWW ABS=`pwd`/ make $(MFLAGS) \
	-f WWW/Library/Implementation/Version.make \
	-f WWW/Library/Implementation/CommonMakefile \
	$(FTP)/$(PROD)_$(VC)_src.tar.Z)
	(cd $(WWW); cvs tag \
	    `sed -e 's/VC = /v/' Library/Implementation/Version.make | sed -e 's?\.?/?'` \
	    Library)
	@echo Distribution of Library version $(VC) up to date.

#	Source Snapshot without CVS update
snapshot : inc $(LEGAL) $(SOURCES)
	(cd $(WWW)/..; WWW=WWW ABS=`pwd`/ make $(MFLAGS) \
	-f WWW/Library/Implementation/Version.make \
	-f WWW/Library/Implementation/CommonMakefile \
	$(FTP)/$(PROD)_$(VC)_src.tar.Z)
	@echo Snapshot of Library version $(VC) up to date.

$(FTP)/$(PROD)_$(VC)_src.tar.Z : $(SOURCES)
	tar cvhf $(FTP)/$(PROD)_$(VC)_src.tar $(TOTAL)
	cp $(FTP)/$(PROD)_$(VC)_src.tar $(FTP)/temp.tar
	compress -f $(FTP)/$(PROD)_$(VC)_src.tar
	mv $(FTP)/temp.tar $(FTP)/$(PROD)_$(VC)_src.tar
	gzip -f $(FTP)/$(PROD)_$(VC)_src.tar

# This only works on Linux or other platforms with 'zip'
zip : $(LEGAL) $(SOURCES)
	(cd $(WWW)/..; WWW=WWW ABS=`pwd`/ make $(MFLAGS) \
	-f WWW/Library/Implementation/Version.make \
	-f WWW/Library/Implementation/CommonMakefile \
	$(FTP)/$(PROD)_$(VC)_src.zip)
	@echo Distribution of Library version $(VC) up to date.

$(FTP)/$(PROD)_$(VC)_src.zip : $(SOURCES)
	zip -v $(FTP)/$(PROD)_$(VC)_src.zip $(TOTAL)

#	Hypertext supplied in text format
#	---------------------------------

$(TOP)/WELCOME : /afs/w3.org/devel/WELCOME.html
	www -p -na http://www.w3.org/devel/WELCOME.html -o $(TOP)/WELCOME

$(WWW)/README : /afs/w3.org/devel/WWW/README.html
	www -p -na http://www.w3.org/devel/WWW/README.html -o $(WWW)/README

$(WWW)/COPYRIGH : /afs/w3.org/devel/WWW/COPYRIGHT.html
	www -p -na http://www.w3.org/devel/WWW/COPYRIGHT.html -o $(WWW)/COPYRIGH

$(WWW)/PATCHES : /afs/w3.org/devel/WWW/PATCHES.html
	www -p -na http://www.w3.org/devel/WWW/PATCHES.html -o $(WWW)/PATCHES

$(WWW)/CERN : /afs/w3.org/devel/WWW/CERN.html
	www -p -na http://www.w3.org/devel/WWW/CERN.html -o $(WWW)/CERN

# 			Common code
#			-----------

#	Directory for object files - .created checks it exists

OE = $(LOB)/.created
$(OE) :
	if [ ! -r $(WTMP) ] ; then mkdir $(WTMP); else echo OK ; fi
	if [ ! -r $(WTMP)/Library ] ; then mkdir $(WTMP)/Library; else echo OK ; fi
	if [ ! -r $(WTMP)/Library/$(WWW_MACH) ] ; \
		then mkdir $(WTMP)/Library/$(WWW_MACH); else echo OK ; fi
	touch $@

# BASIC UTILITY MODULES

$(LOB)/HTList.o : $(OE) $(CMN)HTList.c $(CMN)HTUtils.h $(CMN)HTList.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTList.c

$(LOB)/HTMemory.o : $(OE) $(CMN)HTMemory.c $(CMN)HTUtils.h $(CMN)HTMemory.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTMemory.c

$(LOB)/HTAtom.o : $(OE) $(CMN)HTAtom.c $(CMN)HTUtils.h $(CMN)HTList.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTAtom.c

$(LOB)/HTChunk.o : $(OE) $(CMN)HTChunk.c $(CMN)HTChunk.h $(CMN)HTUtils.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTChunk.c

$(LOB)/HTArray.o : $(OE) $(CMN)HTArray.c $(CMN)HTArray.h $(CMN)HTUtils.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTArray.c

$(LOB)/HTString.o : $(OE) $(CMN)HTString.c $(CMN)HTUtils.h $(CMN)Version.make
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTString.c

$(LOB)/HTBTree.o : $(OE) $(CMN)HTBTree.c $(CMN)HTUtils.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTBTree.c

$(LOB)/HTAssoc.o : $(OE) $(CMN)HTAssoc.c $(CMN)HTAssoc.h $(CMN)HTUtils.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTAssoc.c

$(LOB)/HTUU.o : $(OE) $(CMN)HTUU.c $(CMN)HTUU.h $(CMN)HTUtils.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTUU.c

# CORE MODULES

$(LOB)/HTNet.o : $(OE) $(CMN)HTNet.c $(CMN)HTNet.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTNet.c

$(LOB)/HTEvntrg.o : $(OE) $(CMN)HTEvntrg.c $(CMN)HTEvntrg.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTEvntrg.c

$(LOB)/HTAccess.o : $(OE) $(CMN)HTAccess.c $(CMN)HTAccess.h $(CMN)HTUtils.h
	$(CC) -c -o $@ $(CFLAGS2) -DVC=\"$(VC)\" $(CMN)HTAccess.c

$(LOB)/HTReqMan.o : $(OE)  $(CMN)HTReqMan.c $(CMN)HTReqMan.h $(CMN)HTReq.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTReqMan.c

$(LOB)/HTProt.o : $(OE)  $(CMN)HTProt.c $(CMN)HTProt.h $(CMN)HTUtils.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTProt.c

$(LOB)/HTCache.o : $(OE)  $(CMN)HTCache.c $(CMN)HTCache.h $(CMN)HTUtils.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTCache.c

$(LOB)/HTProxy.o : $(OE)  $(CMN)HTProxy.c $(CMN)HTProxy.h $(CMN)HTUtils.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTProxy.c

$(LOB)/HTParse.o : $(OE) $(CMN)HTParse.c $(CMN)HTParse.h $(CMN)HTUtils.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTParse.c

$(LOB)/HTEscape.o : $(OE) $(CMN)HTEscape.c $(CMN)HTEscape.h $(CMN)HTUtils.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTEscape.c

$(LOB)/HTError.o : $(OE) $(CMN)HTError.c $(CMN)HTError.h $(CMN)HTUtils.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTError.c

$(LOB)/HTAnchor.o : $(OE) $(CMN)HTAnchor.c $(CMN)HTAnchor.h $(CMN)HTAncMan.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTAnchor.c

$(LOB)/HTMethod.o : $(OE) $(CMN)HTMethod.c $(CMN)HTMethod.h $(CMN)HTUtils.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTMethod.c

$(LOB)/HTFormat.o : $(OE) $(CMN)HTFormat.c $(CMN)HTFormat.h $(CMN)HTUtils.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTFormat.c

$(LOB)/HTBind.o : $(OE) $(CMN)HTBind.c $(CMN)HTBind.h $(CMN)HTUtils.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTBind.c

$(LOB)/HTNetTxt.o : $(OE) $(CMN)HTNetTxt.c $(CMN)HTNetTxt.h $(CMN)HTUtils.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTNetTxt.c

$(LOB)/HTConLen.o : $(OE) $(CMN)HTConLen.c $(CMN)HTConLen.h $(CMN)HTUtils.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTConLen.c

$(LOB)/HTWWWStr.o : $(OE) $(CMN)HTWWWStr.c $(CMN)HTUtils.h $(CMN)Version.make
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTWWWStr.c

$(LOB)/HTTee.o : $(OE) $(CMN)HTTee.c $(CMN)HTTee.h $(CMN)HTStream.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTTee.c

$(LOB)/HTSocket.o : $(OE) $(CMN)HTSocket.c $(CMN)HTSocket.h $(CMN)HTUtils.h 
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTSocket.c

$(LOB)/HTWriter.o : $(OE) $(CMN)HTWriter.c $(CMN)HTWriter.h $(CMN)HTStream.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTWriter.c

$(LOB)/HTFWrite.o : $(OE) $(CMN)HTFWrite.c $(CMN)HTFWrite.h $(CMN)HTStream.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTFWrite.c

$(LOB)/HTTCP.o : $(OE) $(CMN)HTTCP.c $(CMN)HTTCP.h $(CMN)HTUtils.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTTCP.c

$(LOB)/HTDNS.o : $(OE) $(CMN)HTDNS.c $(CMN)HTDNS.h $(CMN)HTUtils.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTDNS.c

$(LOB)/HTAlert.o : $(OE) $(CMN)HTAlert.c $(CMN)HTUtils.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTAlert.c

# APPLICATION MODULES

$(LOB)/HTInit.o : $(OE) $(CMN)HTInit.c $(CMN)HTInit.h $(CMN)HTUtils.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTInit.c

$(LOB)/HTBInit.o : $(OE) $(CMN)HTBInit.c $(CMN)HTBInit.h $(CMN)HTUtils.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTBInit.c

$(LOB)/HTHist.o : $(OE) $(CMN)HTHist.c $(CMN)HTHist.h $(CMN)HTUtils.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTHist.c

$(LOB)/HTRules.o : $(OE) $(CMN)HTRules.c $(CMN)HTRules.h $(CMN)HTUtils.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTRules.c

$(LOB)/HTLog.o : $(OE) $(CMN)HTLog.c $(CMN)HTLog.h $(CMN)HTUtils.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTLog.c

$(LOB)/HTHome.o : $(OE) $(CMN)HTHome.c $(CMN)HTHome.h $(CMN)HTUtils.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTHome.c

$(LOB)/HTDialog.o : $(OE) $(CMN)HTDialog.c $(CMN)HTDialog.h $(CMN)HTUtils.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTDialog.c

# DYNAMIC MODULES

$(LOB)/HTWAIS.o : $(OE) $(CMN)HTWAIS.c $(CMN)HTUtils.h $(CMN)HTList.h
	$(CC) -c -o $@ $(CFLAGS2) $(WAISINC) $(CMN)HTWAIS.c

$(LOB)/HTNews.o : $(OE) $(CMN)HTNews.c $(CMN)HTNews.h $(CMN)HTUtils.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTNews.c

$(LOB)/HTNewsRq.o : $(OE) $(CMN)HTNewsRq.c $(CMN)HTNewsRq.h $(CMN)HTUtils.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTNewsRq.c

$(LOB)/HTNDir.o : $(OE) $(CMN)HTNDir.c $(CMN)HTNDir.h $(CMN)HTUtils.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTNDir.c

$(LOB)/HTNewsLs.o : $(OE) $(CMN)HTNewsLs.c $(CMN)HTNewsLs.h $(CMN)HTUtils.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTNewsLs.c

$(LOB)/HTGopher.o : $(OE) $(CMN)HTGopher.c $(CMN)HTGopher.h $(CMN)HTUtils.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTGopher.c

$(LOB)/HTTelnet.o : $(OE) $(CMN)HTTelnet.c $(CMN)HTUtils.h $(CMN)HTTelnet.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTTelnet.c

$(LOB)/HTStyle.o : $(OE) $(CMN)HTStyle.c $(CMN)HTUtils.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTStyle.c

$(LOB)/SGML.o : $(OE) $(CMN)SGML.c $(CMN)HTUtils.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)SGML.c

$(LOB)/HTML.o : $(OE) $(CMN)HTML.c $(CMN)HTUtils.h $(CMN)HTMLPDTD.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTML.c

$(LOB)/HTMLGen.o : $(OE) $(CMN)HTMLGen.c $(CMN)HTUtils.h $(CMN)HTMLPDTD.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTMLGen.c

$(LOB)/HTTeXGen.o : $(OE) $(CMN)HTTeXGen.c $(CMN)HTUtils.h $(CMN)HTMLPDTD.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTTeXGen.c

$(LOB)/HTMLPDTD.o : $(OE) $(CMN)HTMLPDTD.c $(CMN)SGML.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTMLPDTD.c

$(LOB)/HTPlain.o : $(OE) $(CMN)HTPlain.c $(CMN)HTPlain.h $(CMN)HTStream.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTPlain.c

$(LOB)/HTHeader.o : $(OE) $(CMN)HTHeader.c $(CMN)HTHeader.h $(CMN)HTUtils.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTHeader.c

$(LOB)/HTMIME.o : $(OE) $(CMN)HTMIME.c $(CMN)HTMIME.h $(CMN)HTUtils.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTMIME.c

$(LOB)/HTMIMERq.o : $(OE) $(CMN)HTMIMERq.c $(CMN)HTMIMERq.h $(CMN)HTUtils.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTMIMERq.c

$(LOB)/HTBound.o : $(OE) $(CMN)HTBound.c $(CMN)HTBound.h $(CMN)HTUtils.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTBound.c

$(LOB)/HTAAUtil.o : $(OE) $(CMN)HTAAUtil.c $(CMN)HTAAUtil.h \
	 $(CMN)HTUtils.h $(CMN)HTString.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTAAUtil.c

$(LOB)/HTAABrow.o : $(OE) $(CMN)HTAABrow.c $(CMN)HTAABrow.h \
	 $(CMN)HTAAUtil.h $(CMN)HTUU.h \
	 $(CMN)HTUtils.h $(CMN)HTString.h \
	 $(CMN)HTParse.h $(CMN)HTList.h $(CMN)HTAlert.h \
	 $(CMN)HTAssoc.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTAABrow.c

$(LOB)/HTGuess.o : $(OE) $(CMN)HTGuess.c $(CMN)HTGuess.h $(CMN)HTUtils.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTGuess.c

$(LOB)/HTFile.o : $(OE) $(CMN)HTFile.c $(CMN)HTFile.h $(CMN)HTUtils.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTFile.c

$(LOB)/HTDir.o : $(OE) $(CMN)HTDir.c $(CMN)HTDir.h $(CMN)HTUtils.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTDir.c

$(LOB)/HTIcons.o : $(OE) $(CMN)HTIcons.c $(CMN)HTIcons.h $(CMN)HTUtils.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTIcons.c

$(LOB)/HTDescpt.o : $(OE) $(CMN)HTDescpt.c $(CMN)HTDescpt.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTDescpt.c

$(LOB)/HTMulti.o : $(OE) $(CMN)HTMulti.c $(CMN)HTUtils.h \
	 $(CMN)HTFile.h $(CMN)HTMulti.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTMulti.c

$(LOB)/HTFTP.o : $(OE) $(CMN)HTFTP.c $(CMN)HTFTP.h $(CMN)HTUtils.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTFTP.c

$(LOB)/HTFTPDir.o : $(OE) $(CMN)HTFTPDir.c $(CMN)HTFTPDir.h $(CMN)HTUtils.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTFTPDir.c

$(LOB)/HTXParse.o : $(OE) $(CMN)HTXParse.c $(CMN)HTXParse.h $(CMN)HTStream.h $(CMN)HTEPtoCl.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTXParse.c

$(LOB)/HTEPtoCl.o : $(OE) $(CMN)HTEPtoCl.c $(CMN)HTEPtoCl.h $(CMN)HTStream.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTEPtoCl.c

$(LOB)/HTWSRC.o : $(OE) $(CMN)HTWSRC.c $(CMN)HTUtils.h $(CMN)HTList.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTWSRC.c

$(LOB)/HTTP.o : $(OE) $(CMN)HTTP.c $(CMN)HTTP.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTTP.c

$(LOB)/HTTPServ.o : $(OE) $(CMN)HTTPServ.c $(CMN)HTTPServ.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTTPServ.c

$(LOB)/HTTPReq.o : $(OE) $(CMN)HTTPReq.c $(CMN)HTTPReq.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTTPReq.c

$(LOB)/HTTPGen.o : $(OE) $(CMN)HTTPGen.c $(CMN)HTTPGen.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTTPGen.c

$(LOB)/HTTPRes.o : $(OE) $(CMN)HTTPRes.c $(CMN)HTTPRes.h
	$(CC) -c -o $@ $(CFLAGS2) $(CMN)HTTPRes.c


