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

# unit tests

test_test_kata_LDADD = \
	$(CPPUTEST_LIBS)

check_PROGRAMS = \
	test/test_kata

TESTS = \
	$(check_PROGRAMS)

test_test_kata_SOURCES = \
	$(kata_CLASSES) \
	test/AllTests.cpp \
	test/Console_test.cpp
