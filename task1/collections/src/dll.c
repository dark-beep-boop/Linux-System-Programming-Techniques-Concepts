#include "dll.h"
#include "defines.h"
#include <assert.h>
#include <math.h>
#include <memory.h>
#include <stdbool.h>
#include <stdlib.h>

bool
dll_node_init(dll_node_t *self, void *data)
{
  assert(self);
  assert(data);

  CLEAR(self, dll_node_t);
  self->data = data;

  return true;
}

void
dll_node_finalize(dll_node_t *self)
{
  assert(self);
}

dll_node_t *
dll_node_new(void *data)
{
  assert(data);

  dll_node_t *new_object = NULL;

  ALLOCATE_FAIL(new_object, dll_node_t);
  TRY_FAIL(dll_node_init(new_object, data), "node initialization failed");

  return new_object;

fail:
  if (new_object)
    free(new_object);

  return NULL;
}

void
dll_node_destroy(dll_node_t *self)
{
  if (self) {
    dll_node_finalize(self);
    free(self);
  }
}

/* Step 2 : Implement list iterator function here */
dll_node_t *
dll_node_next(dll_node_t *node)
{
  dll_node_t *next = NULL;

  if (node)
    next = node->right;

  return next;
}

/* Step 4: implement get_app_data_from_list_node function */
void *
dll_node_get(dll_node_t *self)
{
  assert(self);

  return self->data;
}

bool
dll_init(dll_t *self)
{
  assert(self);

  CLEAR(self, dll_t);

  return true;
}

void
dll_finalize(dll_t *self)
{
  assert(self);

  while (!dll_is_empty(self))
    dll_pop_head(self);
}

/* Public Function Implementation to create and return
 * new empty doubly linked list*/
dll_t *
dll_new(void)
{
  dll_t *new_object = NULL;

  ALLOCATE_FAIL(new_object, dll_t);
  TRY_FAIL(dll_init(new_object), "doubly linked list initialization failed");

  return new_object;

fail:
  if (new_object)
    free(new_object);

  return NULL;
}

void
dll_destroy(dll_t *self)
{
  if (self) {
    dll_finalize(self);
    free(self);
  }
}

/* Public Function Implementation to add a new application
 * data to DLL */
bool
dll_push_head(dll_t *self, void *data)
{
  assert(self);
  assert(data);

  dll_node_t *new_node = NULL;

  TRY_FAIL(new_node = dll_node_new(data), "node creation failed");
  if (!self->tail)
    self->tail = new_node;
  if (self->head) {
    new_node->right = self->head;
    self->head->left = new_node;
  }
  self->head = new_node;

  return true;

fail:
  return false;
}

bool
dll_push_tail(dll_t *self, void *data)
{
  assert(self);
  assert(data);

  dll_node_t *new_node = NULL;

  TRY_FAIL(new_node = dll_node_new(data), "node creation failed");
  if (!self->head)
    self->head = new_node;
  if (self->tail) {
    new_node->left = self->tail;
    self->tail->right = new_node;
  }
  self->tail = new_node;

  return true;

fail:
  return false;
}

void *
dll_pop_head(dll_t *self)
{
  assert(self);

  void *retval = NULL;
  dll_node_t *old_head = NULL;

  if (self->head) {
    old_head = self->head;
    retval = old_head->data;
    self->head = old_head->right;
    dll_node_destroy(old_head);
    if (self->head) {
      self->head->left = NULL;
    } else {
      self->tail = NULL;
    }
  }

  return retval;
}

void *
dll_pop_tail(dll_t *self)
{
  assert(self);

  void *retval = NULL;
  dll_node_t *old_tail = NULL;

  if (self->tail) {
    old_tail = self->tail;
    retval = old_tail->data;
    self->tail = old_tail->left;
    dll_node_destroy(old_tail);
    if (self->tail) {
      self->tail->right = NULL;
    } else {
      self->head = NULL;
    }
  }

  return retval;
}

bool
dll_is_empty(dll_t *self)
{
  assert(self);

  return !self->head;
}

dll_node_t *
dll_get_head(dll_t *self)
{
  assert(self);

  return self->head;
}
