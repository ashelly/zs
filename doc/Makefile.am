################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
MAN1 = zs.1
MAN3 = zs_pipe.3 zs_repl.3
MAN7 = 
MAN_DOC = $(MAN1) $(MAN3) $(MAN7)

MAN_TXT = $(MAN1:%.1=%.txt)
MAN_TXT += $(MAN3:%.3=%.txt)
MAN_TXT += $(MAN7:%.7=%.txt)

EXTRA_DIST = asciidoc.conf $(MAN_TXT)

if BUILD_DOC
if INSTALL_MAN
dist_man_MANS = $(MAN_DOC)
endif

MAINTAINERCLEANFILES = $(MAN_DOC)

dist-hook : $(MAN_DOC)

SUFFIXES=.txt .xml .1 .3 .7

.txt.xml:
	asciidoc -d manpage -b docbook -f $(srcdir)/asciidoc.conf \
        -azs_version=@PACKAGE_VERSION@ -o$@ $<
.xml.1:
	xmlto man $<
.xml.3:
	xmlto man $<
.xml.7:
	xmlto man $<

zs_pipe.txt:
	zproject_mkman $@
zs_repl.txt:
	zproject_mkman $@
zs.txt:
	zproject_mkman $@
clean:
	rm -f *.1 *.3
	zproject_mkman zs_pipe zs_repl zs 
endif
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
