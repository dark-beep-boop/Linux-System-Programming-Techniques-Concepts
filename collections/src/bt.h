#ifndef BT_H
#define BT_H

#include "ll.h"
#include <stdbool.h>

struct bt_node
{
  void *data;
  struct bt_node *left;
  struct bt_node *right;
  struct bt_node *up;
};
typedef struct bt_node bt_node_t;

struct bt
{
  bt_node_t *root;
};
typedef struct bt bt_t;

bool bt_node_init(bt_node_t *self, void *data);
void bt_node_finalize(bt_node_t *self);
bt_node_t *bt_node_new(void *data);
void bt_node_destroy(bt_node_t *self);
bt_node_t *bt_node_next_inorder(bt_node_t *self);
void *bt_node_get(bt_node_t *self);
void bt_node_detach(bt_node_t *self);

bool bt_init(bt_t *self);
void bt_finalize(bt_t *self);
bt_t *bt_new(void);
void bt_destroy(bt_t *self);
bool bt_insert(bt_t *self, void *data);
bool bt_delete(bt_t *self, void *data);
bool bt_is_empty(bt_t *self);
bt_node_t *bt_get_first_node_inorder(bt_t *self);

#endif /* BT_H */
