#include "ll.h"
#include "defines.h"
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

bool
ll_node_init(ll_node_t *self, void *data)
{
  assert(self);
  assert(data);

  CLEAR(self, ll_node_t);
  self->data = data;

  return true;
}

void
ll_node_finalize(ll_node_t *self)
{
  assert(self);
}

ll_node_t *
ll_node_new(void *data)
{
  assert(data);

  ll_node_t *new_object = NULL;

  ALLOCATE_FAIL(new_object, ll_node_t);
  TRY_FAIL(ll_node_init(new_object, data), "node initialization failed");

  return new_object;

fail:
  if (new_object)
    free(new_object);

  return NULL;
}

void
ll_node_destroy(ll_node_t *self)
{
  if (self) {
    ll_node_finalize(self);
    free(self);
  }
}

ll_node_t *
ll_node_next(ll_node_t *self)
{
  ll_node_t *next = NULL;

  if (self)
    next = self->next;

  return next;
}

void *
ll_node_get(ll_node_t *self)
{
  assert(self);

  return self->data;
}

bool
ll_init(ll_t *self)
{
  assert(self);

  CLEAR(self, ll_t);

  return true;
}

void
ll_finalize(ll_t *self)
{
  assert(self);

  while (!ll_is_empty(self))
    ll_pop_head(self);
}

ll_t *
ll_new(void)
{
  ll_t *new_object = NULL;

  ALLOCATE_FAIL(new_object, ll_t);
  TRY_FAIL(ll_init(new_object), "linked list initialization failed");

  return new_object;

fail:
  if (new_object)
    free(new_object);

  return NULL;
}

void
ll_destroy(ll_t *self)
{
  if (self) {
    ll_finalize(self);
    free(self);
  }
}

bool
ll_push_head(ll_t *self, void *data)
{
  assert(self);
  assert(data);

  ll_node_t *new_node = NULL;

  TRY_FAIL(new_node = ll_node_new(data), "node creation failed");
  if (!self->tail)
    self->tail = new_node;
  if (self->head)
    new_node->next = self->head;
  self->head = new_node;

  return true;

fail:
  return false;
}

bool
ll_push_tail(ll_t *self, void *data)
{
  assert(self);
  assert(data);

  ll_node_t *new_node = NULL;

  TRY_FAIL(new_node = ll_node_new(data), "node creation failed");
  if (!self->head)
    self->head = new_node;
  if (self->tail)
    self->tail->next = new_node;
  self->tail = new_node;

  return true;

fail:
  return false;
}

void *
ll_pop_head(ll_t *self)
{
  assert(self);

  void *retval = NULL;
  ll_node_t *old_head = NULL;

  if (self->head) {
    old_head = self->head;
    retval = old_head->data;
    self->head = old_head->next;
    ll_node_destroy(old_head);
    if (!self->head) {
      self->tail = NULL;
    }
  }

  return retval;
}

bool
ll_is_empty(ll_t *self)
{
  assert(self);

  return self->head == NULL;
}

ll_node_t *
ll_get_head(ll_t *self)
{
  assert(self);

  return self->head;
}
