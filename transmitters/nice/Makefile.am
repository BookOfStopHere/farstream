
plugindir = $(FS_PLUGIN_PATH)

plugin_LTLIBRARIES = libnice-transmitter.la

# sources used to compile this lib
libnice_transmitter_la_SOURCES = \
	fs-nice-transmitter.c \
	fs-nice-stream-transmitter.c \
	fs-nice-agent.c

# flags used to compile this plugin
libnice_transmitter_la_CFLAGS = \
	$(FS_INTERNAL_CFLAGS) \
	$(FS_CFLAGS) \
	$(GST_PLUGINS_BASE_CFLAGS) \
	$(GST_CFLAGS) \
	$(NICE_CFLAGS)
libnice_transmitter_la_LDFLAGS = $(FS_PLUGIN_LDFLAGS)
libnice_transmitter_la_LIBTOOLFLAGS = $(PLUGIN_LIBTOOLFLAGS)
libnice_transmitter_la_LIBADD = \
	$(top_builddir)/farstream/libfarstream-@FS_APIVERSION@.la \
	$(FS_LIBS) \
	$(GST_BASE_LIBS) \
	$(GST_LIBS) \
	$(NICE_LIBS)

noinst_HEADERS = \
	fs-nice-transmitter.h \
	fs-nice-stream-transmitter.h \
	fs-nice-agent.h
