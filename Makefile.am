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

SUBDIRS = src
