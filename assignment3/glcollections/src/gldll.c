#include "gldll.h"
#include "defines.h"
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

bool
gldll_node_init(gldll_node_t *self)
{
  assert(self);

  CLEAR(self, gldll_node_t);

  return true;
}

void
gldll_node_finalize(gldll_node_t *self)
{
  assert(self);
}

bool
gldll_init(gldll_t *self)
{
  assert(self);

  CLEAR(self, gldll_t);

  return true;
}

void
gldll_finalize(gldll_t *self)
{
  assert(self);
}

gldll_t *
gldll_new(void)
{
  gldll_t *new_object = NULL;

  ALLOCATE_FAIL(new_object, gldll_t);
  TRY_FAIL(
    gldll_init(new_object),
    "Glued doubly linked list initialization failed");

  return new_object;

fail:
  if (new_object)
    free(new_object);

  return new_object;
}

void
gldll_destroy(gldll_t *self)
{
  if (self) {
    gldll_finalize(self);
    free(self);
  }
}
