# * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
#
#   @file       src/Makefile.am
#   @author     Domenico Di Iorio <dome.diiorio@gmail.com>
#   @copyright  Copyright - Domenico Di Iorio. All rights reserved.
#
#   This code is intellectual property of Domenico Di Iorio and is
#   subject to the terms and conditions defined in 'LICENSE.txt'
#   which is part of this source code package. All rights reserved.
#
#   Any unauthorized reproduction or redistribution of the Software is
#   expressly prohibited, and will be prosecuted to the full extent of
#   applicable local and international law.
#
#   @brief      autotool Makefile for project root
#
# * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

ACLOCAL_AMFLAGS = -I m4

LIBTOOL_DEPS = @LIBTOOL_DEPS@
libtool: $(LIBTOOL_DEPS)
	$(SHELL) ./config.status libtool

# DISTCHECK_CONFIGURE_FLAGS = --with-systemdsystemunitdir=$$dc_install_base/$(systemdsystemdir)
# 
#clean-local:
#	$(RM) kata.pc
#	$(RM) kata.conf
#
#pkgconfdir = \
#	$(libdir)/pkgconfig
#
#pkgconf_DATA = \
#	kata.pc
#
#ldsoconfdir = \
#	$(sysconfdir)/ld.so.conf.d
#
#ldsoconf_DATA = \
#	kata.conf
#
#EXTRA_DIST = \
#	kata.pc.in \
#	kata.conf.in

SUBDIRS = src
