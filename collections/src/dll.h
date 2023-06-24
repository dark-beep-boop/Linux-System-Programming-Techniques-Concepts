/*Header file for Doubly Linked List*/

#include <stdbool.h>
struct dll_node
{
  void *data;
  struct dll_node *left;
  struct dll_node *right;
};
typedef struct dll_node dll_node_t;

struct dll
{
  dll_node_t *head;
  dll_node_t *tail;
};
typedef struct dll dll_t;

bool dll_node_init(dll_node_t *self, void *data);
void dll_node_finalize(dll_node_t *self);
dll_node_t *dll_node_new(void *data);
void dll_node_destroy(dll_node_t *self);
dll_node_t *dll_node_next(dll_node_t *self);
void *dll_node_get(dll_node_t *self);

bool dll_init(dll_t *self);
void dll_finalize(dll_t *self);
dll_t *dll_new(void);
void dll_destroy(dll_t *self);
bool dll_push_head(dll_t *self, void *data);
bool dll_push_tail(dll_t *self, void *data);
void *dll_pop_head(dll_t *self);
void *dll_pop_tail(dll_t *self);
bool dll_is_empty(dll_t *self);
dll_node_t *dll_get_head(dll_t *self);
