#ifndef TRY_H
#define TRY_H

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _STRINGFY(expr) #expr
#define STRINGFY(expr) _STRINGFY(expr)

#define _JOIN(left, right) left##right
#define JOIN(left, right) _JOIN(left, right)

#define LOG(fmt, ...) fprintf(stderr, fmt, __VA_ARGS__)

#define TRYCATCH(cond, action, msg)                                            \
  if (cond) {                                                                  \
    LOG(                                                                       \
      "EXCEPTION at %s, function %s, line %d: %s\n",                           \
      __FILE__,                                                                \
      __func__,                                                                \
      __LINE__,                                                                \
      msg);                                                                    \
    action;                                                                    \
  }                                                                            \
  NULL

#define TRY(expr, action, msg) TRYCATCH(!(expr), action, msg)
#define TRYC(expr, action, msg) TRYCATCH((expr) < 0, action, msg)

#define TRY_FAIL(expr, msg) TRY(expr, goto fail, msg)
#define TRY_DONE(expr, msg) TRY(expr, goto done, msg)

#define TRYC_FAIL(expr, msg) TRYC(expr, goto fail, msg)
#define TRYC_DONE(expr, msg) TRYC(expr, goto done, msg)

#define TRY_PERROR_FAIL(expr) TRY_FAIL(expr, strerror(errno))
#define TRY_PERROR_DONE(expr) TRY_DONE(expr, strerror(errno))

#define TRYC_PERROR_FAIL(expr) TRYC_FAIL(expr, strerror(errno))
#define TRYC_PERROR_DONE(expr) TRYC_DONE(expr, strerror(errno))

#define ALLOCATE_MANY_FAIL(dest, type, num)                                    \
  TRY_PERROR_FAIL(dest = (type *)calloc(num, sizeof(type)))
#define ALLOCATE_MANY_DONE(dest, type, num)                                    \
  TRY_PERROR_DONE(dest = (type *)calloc(num, sizeof(type)))

#define ALLOCATE_FAIL(dest, type) ALLOCATE_MANY_FAIL(dest, type, 1)
#define ALLOCATE_DONE(dest, type) ALLOCATE_MANY_DONE(dest, type, 1)

#define REALLOCATE_MANY_FAIL(dest, type, num)                                  \
  TRY_PERROR_FAIL(dest = (type *)realloc(dest, num * sizeof(type)))
#define REALLOCATE_MANY_DONE(dest, type, num)                                  \
  TRY_PERROR_DONE(dest = (type *)realloc(dest, num * sizeof(type)))

#define REALLOCATE_FAIL(dest, type) REALLOCATE_MANY_FAIL(dest, type, 1)
#define REALLOCATE_DONE(dest, type) REALLOCATE_MANY_DONE(dest, type, 1)

#define CLEAR(object, type) memset(object, 0, sizeof(type))

#endif /* TRY_H */
