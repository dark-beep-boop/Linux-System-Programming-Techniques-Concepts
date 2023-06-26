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
