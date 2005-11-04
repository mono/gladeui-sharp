lib_LTLIBRARIES = libgladeuisharpglue.la

BASESOURCES = \
	glue.c		\
	#

libgladeuisharpglue_la_LDFLAGS = -module -avoid-version

libgladeuisharpglue_la_SOURCES = 	\
	$(BASESOURCES) 

libgladeuisharpglue_la_LIBADD = $(BASE_DEPENDENCIES_LIBS) $(GLADEUI_LIBS)

INCLUDES = -I$(top_srcdir) $(BASE_DEPENDENCIES_CFLAGS) $(GLADEUI_CFLAGS)

CLEANFILES = lib*.a

