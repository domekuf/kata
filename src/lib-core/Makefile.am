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

noinst_LIBRARIES = \
    libcoreschema.a

libcoreschema_a_SOURCES = \
	$(kata_schema_src)

pkginclude_HEADERS = \
	$(libcore_hpp)

libcore_la_LDFLAGS = \
    $(LIBODB_LIBS) \
    $(LIBODB_SQL3_LIBS) \
    $(LIBODB_BOOST_LIBS) \
    $(SQL3_LIBS) \
	-shared \
    -version-info 1:0:0

libcore_la_LIBADD = \
	$(top_builddir)/src/lib-parser/libparser.la

libcore_la_CXXFLAGS = \
    $(LIBODB_CFLAGS) \
    $(LIBODB_SQL3_CFLAGS) \
    $(SQL3_CFLAGS) \
	$(GCC_FLAGS) \
    $(AM_CXXFLAGS) \
	-I$(top_srcdir)/src/lib-parser

kata_odb_hpp = \
	Object.hpp \
	Post.hpp \
	User.hpp

libcore_hpp = \
	$(kata_odb_hpp) \
	TimeAgo.hpp \
	Core.hpp \
	Wall.hpp

libcore_la_SOURCES = \
	$(libcore_hpp) \
	Core.cpp \
	Post.cpp \
	TimeAgo.cpp \
	User.cpp \
	Wall.cpp

kata_odb_headers = \
    kata-odb.hxx \
    kata-odb.ixx

kata_odb_src = \
	$(kata_odb_headers) \
    kata-odb.cxx \
    kata.sql

kata_schema_src = \
    kata-schema.cxx

BUILT_SOURCES = \
	$(kata_odb_src) \
	$(kata_schema_src)

MOSTLYCLEANFILES = \
	$(kata_odb_src) \
	$(kata_schema_src) \
	kata.stamp

ODB = odb

kata.stamp: $(kata_odb_hpp)
	@rm -f kata.tmp
	@touch kata.tmp
	$(ODB) --database sqlite \
		--schema-name kata \
		--generate-query \
		--generate-prepared \
		--generate-session \
		--generate-schema \
		--default-pointer std::shared_ptr \
		--schema-format separate \
		--schema-format sql \
		--at-once \
		--input-name kata \
		--std c++11 \
		--warn-hard \
		--index-suffix _idx \
		--sql-name-case upper \
		--show-sloc \
		--sloc-limit 10000 \
		--sqlite-override-null \
		-I. \
		--hxx-prologue '#include "Core.hpp"' \
		--profile boost/optional \
		$^
	@mv -f kata.tmp $@

$(kata_odb_src) $(kata_schema_src): kata.stamp
	@if test -f $@; then :; else \
	    rm -r kata.stamp; \
	    $(MAKE) $(AM_MAKEFILES) kata.stamp; \
	fi

# unit tests

check_PROGRAMS = \
	test/test_libcore

TESTS = \
	$(check_PROGRAMS)

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
	test/Post_test.cpp \
	test/TimeAgo_test.cpp \
	test/User_test.cpp \
	$(libcore_hpp) \
	$(libcore_la_SOURCES)
