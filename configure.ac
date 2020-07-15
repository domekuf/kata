AC_INIT([kata], [0.1], [dome.diiorio@gmail.com], [kata])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])

# The argument to AM_INIT_AUTOMAKE is a list of options for automake (see Options). -Wall and -Werror ask automake to turn on all warnings and report them as errors. We are speaking of Automake warnings here, such as dubious instructions in Makefile.am. This has absolutely nothing to do with how the compiler will be called, even though it may support options with similar names.

# foreign: The foreign option tells Automake that this package will not follow the GNU Standards. GNU packages should always distribute additional files such as ChangeLog, AUTHORS, etc.

# subdir-objects: If this option is specified, then objects are placed into the subdirectory of the build directory corresponding to the subdirectory of the source file. For instance, if the source file is subdir/file.cxx, then the output file would be subdir/file.o

AM_INIT_AUTOMAKE([-Wall -Werror foreign subdir-objects])

# You must use this macro when you use the archiver in your project. Use this if compiling libraries
AM_PROG_AR

# This macro adds many new tests to the configure script so that the generated libtool script will understand the characteristics of the host.
LT_INIT

# If the macro is invoked without an argument, then search for a C++ compiler under the likely names (first g++ and c++ then other names). If none of those checks succeed, then as a last resort set CXX to g++.
AC_PROG_CXX
AC_PROG_CC

test "$GCC" == yes || AC_MSG_ERROR([GCC is required])

CC="$CC -m64"

PKG_CHECK_MODULES([CPPUTEST], [cpputest])
PKG_CHECK_MODULES([LIBODB], [libodb])
PKG_CHECK_MODULES([LIBODB_SQL3], [libodb-sqlite])
PKG_CHECK_MODULES([LIBODB_BOOST], [libodb-boost])
PKG_CHECK_MODULES([SQL3], [sqlite3])

AC_SUBST([GCC_FLAGS_GLOBAL], ["\
          -g \
          -Wall \
          -Wextra \
          -Wpedantic \
          -Werror \
          -Wformat=2 \
          -O2 \
		  -DNDEBUG"])

AC_CONFIG_FILES([
	Makefile
	src/Makefile
    src/lib-parser/Makefile
    src/lib-core/Makefile
    src/kata/Makefile
])

AC_OUTPUT
