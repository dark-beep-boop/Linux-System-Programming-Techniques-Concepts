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

struct gldll
{
  gldll_node_t *head;
};
typedef struct gldll gldll_t;

bool gldll_node_init(gldll_node_t *self);
void gldll_node_finalize(gldll_node_t *self);
gldll_node_t *gldll_node_remove(gldll_node_t *node);

bool gldll_init(gldll_t *self);
void gldll_finalize(gldll_t *self);
gldll_t *gldll_new(void);
void gldll_destroy(gldll_t *self);
void gldll_push_head(gldll_t *self, gldll_node_t *node);
gldll_node_t *gldll_pop_head(gldll_t *self);
bool gldll_is_empty(const gldll_t *self);

#define GLDLL_FOR_EACH_BEGIN(self, node)                                       \
  {                                                                            \
    gldll_node_t _next = NULL;                                                 \
    for (node = self->head; node != NULL; node = _next) {                      \
      _node = node->right;

#define GLDLL_FOR_EACH_END                                                     \
  }                                                                            \
  }

#endif /* GLDLL_H */
