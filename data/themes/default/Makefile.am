MAINTAINERCLEANFILES = Makefile.in


EDCS = default.edc
EDJS = $(EDCS:%.edc=%.edj)

default_DEPS = default.edc

EXTRA_DIST = $(EDCS)

CLEANFILES = $(EDJS)

themedir = $(pkgdatadir)/themes/default
theme_DATA = $(EDJS)

all: $(EDJS)

default.edj: ${default_DEPS}

SUFFIXES = .edc .edj
.edc.edj:
	edje_cc -id $(top_srcdir)/data/themes/default/images -fd $(top_srcdir)/data/themes/default/fonts $< $(top_builddir)/data/themes/default/$(@F)
