#ifndef LL_H
#define LL_H

#include <stdbool.h>

struct ll_node
{
  void *data;
  struct ll_node *next;
};
typedef struct ll_node ll_node_t;

struct ll
{
  ll_node_t *head;
  ll_node_t *tail;
};
typedef struct ll ll_t;

bool ll_node_init(ll_node_t *self, void *data);
void ll_node_finalize(ll_node_t *self);
ll_node_t *ll_node_new(void *data);
void ll_node_destroy(ll_node_t *self);
ll_node_t *ll_node_next(ll_node_t *self);
void *ll_node_get(ll_node_t *self);

bool ll_init(ll_t *self);
void ll_finalize(ll_t *self);
ll_t *ll_new(void);
void ll_destroy(ll_t *self);
bool ll_push_head(ll_t *self, void *data);
bool ll_push_tail(ll_t *self, void *data);
void *ll_pop_head(ll_t *self);
bool ll_is_empty(ll_t *self);
ll_node_t *ll_get_head(ll_t *self);

#define LL_FOR_EACH_BEGIN(ll_ptr, node_ptr)                                    \
  {                                                                            \
    ll_node_t *_next_ptr = NULL;                                               \
    for (node_ptr = ll_ptr->head; node_ptr != NULL; node_ptr = _next_ptr) {    \
      _next_ptr = node_ptr->next;

#define LL_FOR_EACH_END                                                        \
  }                                                                            \
  }

#endif /* LL_H */
