# * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
#
#   @file       src/lib-parser/Makefile.am
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
#   @brief      autotool Makefile for lib-parser
#
# * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

# GNU compiler flags common to C and C++
GCC_FLAGS = $(GCC_FLAGS_GLOBAL)

AM_CFLAGS = $(GCC_FLAGS) -std=c99
AM_CXXFLAGS = $(GCC_FLAGS) -std=c++11

AM_CPPFLAGS = \
	-D_FORTIFY_SOURCE=2

pkglib_LTLIBRARIES = \
	libparser.la
pkginclude_HEADERS = \
	$(libparser_hpp)

libparser_la_LDFLAGS = \
	-shared \
    -version-info 1:0:0

libparser_la_LIBADD = -lboost_regex

libparser_la_CXXFLAGS = \
	$(GCC_FLAGS) \
    $(AM_CXXFLAGS)

libparser_hpp = \
	Phrase.hpp

libparser_la_SOURCES = \
	$(libparser_hpp) \
	Phrase.cpp

# unit tests

check_PROGRAMS = \
	test/test_libparser

TESTS = \
	$(check_PROGRAMS)

# Adding /src/lib-kata to use macros.hpp
test_test_libparser_CXXFLAGS = \
	$(libparser_la_CXXFLAGS)

test_test_libparser_LDFLAGS = \
	$(libparser_la_LDFLAGS)

test_test_libparser_LDADD = \
	$(libparser_la_LIBADD) \
	$(CPPUTEST_LIBS)

test_test_libparser_SOURCES = \
	test/AllTests.cpp \
	test/Phrase_test.cpp \
	$(libparser_hpp) \
	$(libparser_la_SOURCES)
