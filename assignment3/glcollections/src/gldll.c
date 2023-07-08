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

gldll_node_t *
gldll_node_remove(gldll_node_t *node)
{
  assert(node);

  if (node->left)
    node->left->right = node->right;
  if (node->right)
    node->right->left = node->left;

  return node;
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

  while (!gldll_is_empty(self))
    gldll_pop_head(self);
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

bool
gldll_is_empty(const gldll_t *self)
{
  assert(self);

  return self->head == NULL;
}

void
gldll_push_head(gldll_t *self, gldll_node_t *node)
{
  assert(self);
  assert(node);

  if (self->head) {
    node->right = self->head;
    self->head->left = node;
  }
  self->head = node;
}

gldll_node_t *
gldll_pop_head(gldll_t *self)
{
  assert(self);

  gldll_node_t *node = NULL;

  if (self->head) {
    node = self->head;
    self->head = node->right;
    if (self->head) {
      self->head->left = NULL;
      node->right = NULL;
    }
  }

  return node;
}
