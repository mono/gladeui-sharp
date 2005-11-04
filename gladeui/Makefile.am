MCS=mcs
RAW_API=gladeui-api.raw
API=gladeui-api.xml
METADATA=gladeui.metadata

ASSEMBLY_NAME= gladeui-sharp
ASSEMBLY= $(ASSEMBLY_NAME).dll

if WINBUILD
CODEGEN=gapi_codegen.exe
FIXUP=gapi-fixup.exe
else
CODEGEN=gapi2-codegen
FIXUP=gapi2-fixup
endif

build_sources = AssemblyInfo.cs

customs = App.custom

CLEANFILES = gladeui-sharp.dll generated-stamp generated/*.cs $(API) gladeui-sharp.snk

DISTCLEANFILES= AssemblyInfo.cs

noinst_DATA = gladeui-sharp.dll

all: generated-stamp gladeui-sharp.dll

$(API): $(srcdir)/$(RAW_API) $(srcdir)/$(METADATA)
	cp $(srcdir)/$(RAW_API) $(API)
	chmod u+w $(API)
	$(FIXUP) --api=$(srcdir)/$(API) --metadata=$(srcdir)/$(METADATA)

generated-stamp: $(API)
	 $(CODEGEN) --generate $(srcdir)/$(API) $(GTK_SHARP_CFLAGS) --outdir=generated --customdir=$(srcdir) --assembly-name=gladeui-sharp && touch generated-stamp

gladeui-sharp.snk: $(top_srcdir)/gladeui-sharp.snk
	cp $(top_srcdir)/gladeui-sharp.snk .

gladeui-sharp.dll: $(build_sources) generated-stamp gladeui-sharp.snk
	$(MCS) -nowarn:169 -unsafe -target:library $(GTK_SHARP_LIBS) \
	$(build_sources) generated/*.cs -out:gladeui-sharp.dll

install-data-local:
	echo "$(GACUTIL) /i $(ASSEMBLY) /f $(GACUTIL_FLAGS)";  \
        $(GACUTIL) /i $(ASSEMBLY) /f $(GACUTIL_FLAGS) || exit 1;

uninstall-local:
	echo "$(GACUTIL) /u $(ASSEMBLY_NAME) $(GACUTIL_FLAGS)"; \
        $(GACUTIL) /u $(ASSEMBLY_NAME) $(GACUTIL_FLAGS) || exit 1;

EXTRA_DIST = $(RAW_API) $(sources) $(customs) $(METADATA) AssemblyInfo.cs.in gladeui-sharp.dll.config.in $(API)
