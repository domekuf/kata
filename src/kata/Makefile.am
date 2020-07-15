# * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
#
#   @file       src/kata/Makefile.am
#   @author     Domenico Di Iorio <dome.diiorio@gmail.com>
#
# Any unauthorized reproduction or redistribution of the Software is
# expressly prohibited, and will be prosecuted to the full extent of
# applicable local and international law.
#
#   @brief      autotool Makefile for kata
#
# * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

# GNU compiler flags common to C and C++
GCC_FLAGS = $(GCC_FLAGS_GLOBAL)

AM_CFLAGS = $(GCC_FLAGS) -std=c99
AM_CXXFLAGS = $(GCC_FLAGS) -std=c++11

AM_CPPFLAGS = \
	-D_FORTIFY_SOURCE=1

bin_PROGRAMS = \
	kata

kata_CLASSES = \
	Console.cpp \
	Console.hpp

kata_SOURCES = \
	$(kata_CLASSES) \
	kata.cpp

kata_DEPENDENCIES= \
	$(top_builddir)/src/lib-core/libcoreschema.a

kata_CXXFLAGS= \
	$(LIBODB_CFLAGS) \
	$(LIBODB_SQL3_CFLAGS) \
	-I$(top_srcdir)/src/lib-core \
	-I$(top_srcdir)/src/lib-parser

kata_LDFLAGS= \
	$(LIBODB_LIBS) \
	$(LIBODB_SQL3_LIBS) \
	-Wl,--whole-archive,$(top_builddir)/src/lib-core/libcoreschema.a,--no-whole-archive

kata_LDADD= \
	$(top_builddir)/src/lib-core/libcore.la \
	$(top_builddir)/src/lib-parser/libparser.la

# unit tests

test_test_kata_LDADD = \
	$(kata_LDADD) \
	$(CPPUTEST_LIBS)

test_test_kata_CXXFLAGS = \
	$(kata_CXXFLAGS)

check_PROGRAMS = \
	test/test_kata

TESTS = \
	$(check_PROGRAMS)

test_test_kata_SOURCES = \
	$(kata_CLASSES) \
	test/AllTests.cpp \
	test/Console_test.cpp
