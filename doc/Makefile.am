docfiles = tutorial.tex

if HAVE_PDFLATEX
docfiles += tutorial.pdf
MANNAME = tutorial
MANTEXSRC = $(MANNAME).tex
MANAUX = $(MANNAME).aux
MANPDF = $(MANNAME).pdf

CLEANFILES = $(MANPDF) $(MANNAME).log $(MANNAME).idx $(MANNAME).out $(MANNAME).toc $(MANAUX)

$(MANPDF): $(srcdir)/$(MANTEXSRC)
	$(PDFLATEX) $<
endif

dist_doc_DATA = $(docfiles)
