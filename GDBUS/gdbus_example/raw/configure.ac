################################################################################
#
# Author: Jean-Pierre.Bogler@continental-corporation.com
#
# Configure template for the gdbus example
#
# Process this file with autoconf to produce a configure script.
#
# Copyright (C) 2013 Continental Automotive Systems, Inc.
#
################################################################################

# Initialize autoconf
AC_INIT([conti-gdbus-example], [1.0.0])
AC_PREREQ([2.50])
AC_COPYRIGHT([Copyright (c) 2013 Continental Automotive GmbH])

# Initialize automake
AM_INIT_AUTOMAKE([tar-ustar foreign])

# Check for basic programs
AC_PROG_CC
AM_PROG_CC_C_O
AC_PROG_INSTALL

# Check for basic headers

# Check for basic types

# Check for basic functions

# Check for required packages
PKG_CHECK_MODULES([GIO],      [gio-2.0                    >= 2.30.0 ])
PKG_CHECK_MODULES([GIO_UNIX], [gio-unix-2.0               >= 2.30.0 ])
PKG_CHECK_MODULES([GLIB],     [glib-2.0                   >= 2.30.0 ])
PKG_CHECK_MODULES([GOBJECT],  [gobject-2.0                >= 2.30.0 ])
PKG_CHECK_MODULES([DBUS],     [dbus-1                     >= 1.4.10 ])

# Derive path for storing 'dbus' interface files (e. g. /usr/share/dbus-1/interfaces)
AC_ARG_WITH([dbusinterfacesdir],
        AS_HELP_STRING([--with-dbusinterfacesdir=DIR], [Directory for D-Bus interface files]),
        [],
        [with_dbusinterfacesdir=$(pkg-config --silence-errors --variable=interfaces_dir dbus-1)])
AC_SUBST([dbusinterfacesdir], [$with_dbusinterfacesdir])

# Define configure output
AC_CONFIG_FILES([ Makefile ])
AC_OUTPUT
