SOURCE_DIR = glade-3-2.90.0

api: $(SOURCE_DIR)/src/*.h
	PERLLIB=$(GTKSHARP_PREFIX)/share/perl5  \
	PATH=$(GTKSHARP_PREFIX)/bin:$$PATH \
	gapi2-parser gladeui-sharp-sources.xml
	cp gladeui-api.raw ../gladeui

get-sources:
	rm -rf $(SOURCE_DIR)
	wget http://ftp.gnome.org/pub/GNOME/sources/glade-3/2.90/glade-3-2.90.0.tar.gz
	tar xvfz glade-3-2.90.0.tar.gz
	for i in `ls $(SOURCE_DIR)/src/*.h`; do                  \
		sed -e "s/LIBGLADEUI_API//" -i $$i; \
	done;

clean:
	rm -rf $(SOURCE_DIR)
