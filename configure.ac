#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_INIT(Sikozu, 0.1, victor-sikozu@boivie.com)
AM_INIT_AUTOMAKE(Sikozu, 0.1)

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_INSTALL

# Checks for libraries.
AC_CHECK_HEADER(event.h, [], [AC_MSG_ERROR([header file <event.h> is required for libevent])])
AC_LANG_PUSH([C++])
AC_CHECK_HEADER(google/protobuf/message.h, [], [AC_MSG_ERROR([header file <google/protobuf/message.h> is required for protobuf])])
AC_CHECK_HEADER(boost/thread/mutex.hpp, [], [AC_MSG_ERROR([header file <boost/thread/mutex.hpp> is required for boost])])
AC_CHECK_HEADER(boost/program_options.hpp, [], [AC_MSG_ERROR([header file <boost/program_options.hpp> is required for boost])])
LIBS="$LIBS -levent -lprotobuf -lboost_thread-mt -lboost_program_options-mt -lboost_date_time-mt -ldl"

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_SIZE_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT8_T

# Checks for library functions.
AC_CHECK_FUNCS([memset socket])

AC_OUTPUT(Makefile src/Makefile)

