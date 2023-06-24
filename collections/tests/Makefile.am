TESTS = check_collections
check_PROGRAMS = check_collections
check_collections_SOURCES = check_collections.c\
														ll_suite.c ll_suite.h\
														dll_suite.c dll_suite.h\
														bt_suite.c bt_suite.h
check_collections_CPPFLAGS = -I$(top_srcdir)/src
check_collections_CFLAGS = @CHECK_CFLAGS@
check_collections_LDADD = $(top_builddir)/src/libcollections.la @CHECK_LIBS@
