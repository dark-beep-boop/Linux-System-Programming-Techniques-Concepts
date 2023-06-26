TESTS = check_glcollections
check_PROGRAMS = check_glcollections
check_glcollections_SOURCES = check_glcollections.c\
														gldll_suite.c gldll_suite.h
check_glcollections_CPPFLAGS = -I$(top_srcdir)/src
check_glcollections_CFLAGS = @CHECK_CFLAGS@
check_glcollections_LDADD = $(top_builddir)/src/libglcollections.la @CHECK_LIBS@
