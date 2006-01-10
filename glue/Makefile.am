lib_LTLIBRARIES = libgladeuisharpglue.la

libgladeuisharpglue_la_SOURCES = \
	glue.c \
	widget.c

libgladeuisharpglue_la_LDFLAGS = -module -avoid-version -no-undefined

libgladeuisharpglue_la_LIBADD = $(BASE_DEPENDENCIES_LIBS) $(GLADEUI_LIBS)

INCLUDES = -I$(top_srcdir) $(BASE_DEPENDENCIES_CFLAGS) $(GLADEUI_CFLAGS)

CLEANFILES = lib*.a

