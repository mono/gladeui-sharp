if ENABLE_MONODOC
docdir = `pkg-config monodoc --variable=sourcesdir`
doc_DATA = gladeui-sharp-docs.zip gladeui-sharp-docs.tree gladeui-sharp-docs.source
endif

noinst_DATA = $(TARGETS)

ASSEMBLER = mdassembler
UPDATER = monodocer

gladeui-sharp-docs.zip gladeui-sharp-docs.tree: $(srcdir)/en/*/*.xml $(srcdir)/en/*.xml
	$(ASSEMBLER) --ecma $(srcdir)/en -o gladeui-sharp-docs

update:
		$(UPDATER) -assembly:../gladeui/gladeui-sharp.dll -path ./en

CLEANFILES = gladeui-sharp-docs.zip gladeui-sharp-docs.tree

EXTRA_DIST = gladeui-sharp-docs.source gladeui-sharp-docs.tree gladeui-sharp-docs.zip

dist-hook:
	mkdir -p $(distdir)/en
	cp $(srcdir)/en/*.xml $(distdir)/en/
	mkdir -p $(distdir)/en/Glade
	cp $(srcdir)/en/Glade/*.xml $(distdir)/en/Glade/

