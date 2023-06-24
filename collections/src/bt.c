#include "bt.h"
#include "defines.h"
#include "ll.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static bt_node_t *bt_node_leftmost(bt_node_t *self);
static bt_node_t *bt_node_up_right(bt_node_t *self);

static bt_node_t *bt_find_node(bt_t *self, void *data);
static bt_node_t *bt_get_deepest_rightmost_node(bt_t *self);

bt_node_t *
bt_node_leftmost(bt_node_t *self)
{
  bt_node_t *next = self;

  if (next)
    while (next->left)
      next = next->left;

  return next;
}

bt_node_t *
bt_node_up_right(bt_node_t *self)
{
  assert(self);

  bt_node_t *next = NULL;
  bt_node_t *current = self;

  while (!next && current->up) {
    if (current == current->up->left) {
      next = current->up;
    } else {
      current = current->up;
    }
  }

  return next;
}

bt_node_t *
bt_find_node(bt_t *self, void *data)
{
  assert(self);
  assert(data);

  bt_node_t *node = NULL;

  node = bt_get_first_node_inorder(self);
  while (node && node->data != data)
    node = bt_node_next_inorder(node);

  return node;
}

bt_node_t *
bt_get_deepest_rightmost_node(bt_t *self)
{
  assert(self);

  bt_node_t *retval = NULL;
  bt_node_t *node = NULL;
  bt_node_t *current = NULL;
  ll_t *queue = NULL;

  if (self->root) {
    TRY_DONE(queue = ll_new(), "queue creation failed");
    TRY_DONE(ll_push_tail(queue, self->root), "node push failed");
    while (!ll_is_empty(queue)) {
      current = ll_pop_head(queue);
      if (current->left) {
        TRY_DONE(ll_push_tail(queue, current->left), "node push failed");
      }
      if (current->right) {
        TRY_DONE(ll_push_tail(queue, current->right), "node push failed");
      }
      if (!current->left && !current->right) {
        node = current;
      }
    }

    retval = node;
  }

done:
  ll_destroy(queue);

  return retval;
}

bool
bt_node_init(bt_node_t *self, void *data)
{
  assert(self);
  assert(data);

  CLEAR(self, bt_node_t);
  self->data = data;

  return true;
}

void
bt_node_finalize(bt_node_t *self)
{
  assert(self);

  if (self->right)
    bt_node_destroy(self->right);
  if (self->left)
    bt_node_destroy(self->left);
}

bt_node_t *
bt_node_new(void *data)
{
  assert(data);

  bt_node_t *new_object = NULL;

  ALLOCATE_FAIL(new_object, bt_node_t);
  TRY_FAIL(bt_node_init(new_object, data), "node initialization failed");

  return new_object;

fail:
  if (new_object)
    free(new_object);

  return NULL;
}

void
bt_node_destroy(bt_node_t *self)
{
  if (self) {
    bt_node_finalize(self);
    free(self);
  }
}

bt_node_t *
bt_node_next_inorder(bt_node_t *self)
{
  bt_node_t *next = NULL;

  if (self) {
    if (self->right) {
      next = bt_node_leftmost(self->right);
    } else {
      next = bt_node_up_right(self);
    }
  }

  return next;
}

void *
bt_node_get(bt_node_t *self)
{
  assert(self);

  return self->data;
}

void
bt_node_detach(bt_node_t *self)
{
  assert(self);

  if (self->up) {
    if (self->up->left == self) {
      self->up->left = NULL;
    } else {
      self->up->right = NULL;
    }
  }
}

bool
bt_init(bt_t *self)
{
  assert(self);

  CLEAR(self, bt_t);

  return true;
}

void
bt_finalize(bt_t *self)
{
  assert(self);

  bt_node_destroy(self->root);
}

bt_t *
bt_new(void)
{
  bt_t *new_object = NULL;

  ALLOCATE_FAIL(new_object, bt_t);
  TRY_FAIL(bt_init(new_object), "binary tree initialization failed");

  return new_object;

fail:
  if (new_object)
    free(new_object);

  return NULL;
}

void
bt_destroy(bt_t *self)
{
  if (self) {
    bt_finalize(self);
    free(self);
  }
}

bool
bt_insert(bt_t *self, void *data)
{
  assert(self);
  assert(data);

  bool ok = false;
  bt_node_t *new_node = NULL;
  bt_node_t *current = NULL;
  ll_t *queue = NULL;

  TRY_DONE(new_node = bt_node_new(data), "node creation failed");
  if (!self->root) {
    self->root = new_node;
  } else {
    TRY_DONE(queue = ll_new(), "queue creation failed");
    TRY_DONE(ll_push_tail(queue, self->root), "node insertion failed");
    while (!new_node->up && !ll_is_empty(queue)) {
      current = ll_pop_head(queue);
      if (current->right && current->left) {
        TRY_DONE(ll_push_tail(queue, current->left), "node insertion failed");
        TRY_DONE(ll_push_tail(queue, current->right), "node insertion failed");
      } else {
        if (!current->left) {
          current->left = new_node;
        } else {
          current->right = new_node;
        }
        new_node->up = current;
      }
    }
  }

  ok = true;

done:
  if (!ok)
    bt_node_destroy(new_node);

  ll_destroy(queue);

  return ok;
}

bool
bt_delete(bt_t *self, void *data)
{
  assert(self);
  assert(data);

  bool ok = self->root != NULL;
  bt_node_t *searched_node = NULL;
  bt_node_t *deepest_rightmost_node = NULL;

  if (ok) {
    searched_node = bt_find_node(self, data);
    deepest_rightmost_node = bt_get_deepest_rightmost_node(self);
    ok = searched_node && deepest_rightmost_node;

    if (ok) {
      if (deepest_rightmost_node == self->root) {
        self->root = NULL;
      } else {
        searched_node->data = deepest_rightmost_node->data;
        bt_node_detach(deepest_rightmost_node);
      }
      bt_node_destroy(deepest_rightmost_node);
    }
  }

  return ok;
}

bool
bt_is_empty(bt_t *self)
{
  assert(self);

  return self->root == NULL;
}

bt_node_t *
bt_get_first_node_inorder(bt_t *self)
{
  assert(self);

  return bt_node_leftmost(self->root);
}
