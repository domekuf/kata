# * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
#
#   @file       src/lib-core/Makefile.am
#   @author     Domenico Di Iorio <dome.diiorio@gmail.com>
#   @copyright  Copyright - Domenico Di Iorio. All rights reserved.
#
# This code is intellectual property of Domenico Di Iorio and is
# subject to the terms and conditions defined in 'LICENSE.txt'
# which is part of this source code package. All rights reserved.
#
# Any unauthorized reproduction or redistribution of the Software is
# expressly prohibited, and will be prosecuted to the full extent of
# applicable local and international law.
#
#   @brief      autotool Makefile for lib-core
#
# * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

# GNU compiler flags common to C and C++
GCC_FLAGS = $(GCC_FLAGS_GLOBAL)

AM_CFLAGS = $(GCC_FLAGS) -std=c99
AM_CXXFLAGS = $(GCC_FLAGS) -std=c++11

AM_CPPFLAGS = \
	-D_FORTIFY_SOURCE=2

pkglib_LTLIBRARIES = \
	libcore.la
pkginclude_HEADERS = \
	$(libcore_hpp)

libcore_la_LDFLAGS = \
	-shared \
    -version-info 1:0:0

libcore_la_LIBADD =

libcore_la_CXXFLAGS = \
	$(GCC_FLAGS) \
    $(AM_CXXFLAGS)

libcore_hpp = \
	Core.hpp \
	Post.hpp \
	User.hpp \
	Wall.hpp

libcore_la_SOURCES = \
	$(libcore_hpp) \
	Core.cpp \
	Post.cpp \
	User.cpp \
	Wall.cpp

# unit tests

check_PROGRAMS = \
	test/test_libcore

TESTS = \
	$(check_PROGRAMS)

# Adding /src/lib-kata to use macros.hpp
test_test_libcore_CXXFLAGS = \
	$(libcore_la_CXXFLAGS)

test_test_libcore_LDFLAGS = \
	$(libcore_la_LDFLAGS)

test_test_libcore_LDADD = \
	$(libcore_la_LIBADD) \
	$(CPPUTEST_LIBS)

test_test_libcore_SOURCES = \
	test/AllTests.cpp \
	test/Core_test.cpp \
	test/User_test.cpp \
	$(libcore_hpp) \
	$(libcore_la_SOURCES)
