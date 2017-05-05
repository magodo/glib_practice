################################################################################
#
# Author: Jean-Pierre.Bogler@continental-corporation.com
#
# Makefile template for the conti-gdbus-example
#
# Process this file with automake to produce a Makefile.in.
#
# Copyright (C) 2013 Continental Automotive Systems, Inc.
#
################################################################################

# Programs built by the Makefile
bin_PROGRAMS          = server client

# Build the server
server_SOURCES        = server.c           \
                        common.h

nodist_server_SOURCES = common-generated.c \
                        common-generated.h

server_CFLAGS         = $(GIO_CFLAGS)       \
                        $(GLIB_CFLAGS)      \
                        $(GIO_UNIX_CFLAGS)  \
                        $(GOBJECT_CFLAGS)

server_LDADD          = $(GIO_LIBS)        \
                        $(GLIB_LIBS)       \
                        $(GOBJECT_LIBS)    \
                        $(GIO_UNIX_LIBS)

# Build the client
client_SOURCES        = client.c           \
                        common.h

nodist_client_SOURCES = common-generated.c \
                        common-generated.h

client_CFLAGS         = $(GIO_CFLAGS)       \
                        $(GLIB_CFLAGS)      \
                        $(GIO_UNIX_CFLAGS)  \
                        $(GOBJECT_CFLAGS)

client_LDADD          = $(GIO_LIBS)        \
                        $(GLIB_LIBS)       \
                        $(GOBJECT_LIBS)    \
                        $(GIO_UNIX_LIBS)

BUILT_SOURCES         = common-generated.c \
                        common-generated.h

# Create generated sources during the build
common-generated.c common-generated.h: com.contiautomotive.Gdbus.Example.xml
	gdbus-codegen --interface com.contiautomotive. --c-namespace Conti --generate-c-code common-generated com.contiautomotive.Gdbus.Example.xml


