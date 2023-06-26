#ifndef GLDLL_H
#define GLDLL_H

#include <stdbool.h>
#include <stddef.h>

struct gldll_node
{
  struct gldll_node *left;
  struct gldll_node *right;
};
typedef struct gldll_node gldll_node_t;

bool gldll_node_init(gldll_node_t *self);
void gldll_node_finalize(gldll_node_t *self);

#endif /* GLDLL_H */
