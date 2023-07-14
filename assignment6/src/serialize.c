#include "serialize.h"
#include "defines.h"
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

static void serializer_buffer_clear(serializer_buffer_t *self);

void
serializer_buffer_clear(serializer_buffer_t *self)
{
  memset(self, 0, sizeof(serializer_buffer_t));
}

bool
serializer_buffer_init(serializer_buffer_t *self)
{
  assert(self);

  return serializer_buffer_new_with_size(SERIALIZE_BUFFER_DEFAULT_SIZE);
}

bool
serializer_buffer_init_with_size(serializer_buffer_t *self, int size)
{
  assert(self);

  serializer_buffer_clear(self);

  ALLOCATE_MANY_FAIL(self->buffer, char, size);
  self->size = size;

  return true;

fail:
  return false;
}

void
serializer_buffer_finalize(serializer_buffer_t *self)
{
  assert(self);

  if (self->buffer)
    free(self->buffer);
}

serializer_buffer_t *
serializer_buffer_new(void)
{
  return serializer_buffer_new_with_size(SERIALIZE_BUFFER_DEFAULT_SIZE);
}

serializer_buffer_t *
serializer_buffer_new_with_size(int size)
{
  serializer_buffer_t *new_object = NULL;

  ALLOCATE_FAIL(new_object, serializer_buffer_t);
  TRY_FAIL(
    serializer_buffer_init_with_size(new_object, size),
    "seralizer buffer initialization failed");

  return new_object;

fail:
  if (new_object)
    free(new_object);

  return NULL;
}

void
serializer_buffer_destroy(serializer_buffer_t *self)
{
  if (self) {
    serializer_buffer_finalize(self);
    free(self);
  }
}

bool
serializer_buffer_is_empty(const serializer_buffer_t *self)
{
  return self->next == 0;
}

bool
serializer_buffer_serialize_string(
  serializer_buffer_t *self,
  const char *string,
  int len)
{
  assert(self);
  assert(string);

  while (self->size < self->next + len) {
    REALLOCATE_MANY_FAIL(self->buffer, char, self->size * 2);
    self->size *= 2;
  }

  memcpy(self->buffer + self->next, string, len);
  self->next += len;

  return true;

fail:
  return false;
}

bool
serializer_buffer_deserialize_string(
  serializer_buffer_t *self,
  char *dest,
  int len)
{
  assert(self);
  assert(dest);

  bool ok = self->next + len <= self->size;

  if (ok) {
    memcpy(dest, self->buffer + self->next, len);
    self->next += len;
  }

  return ok;
}

bool
serializer_buffer_copy_by_offset(
  serializer_buffer_t *self,
  int offset,
  const char *orig,
  int len)
{
  assert(self);
  assert(orig);

  bool ok = offset + len <= self->size;

  if (ok)
    memcpy(self->buffer + offset, orig, len);

  return ok;
}

void
serializer_buffer_mark_checkpoint(serializer_buffer_t *self)
{
  assert(self);

  self->checkpoint = self->next;
}

int
serializer_buffer_get_checkpoint(const serializer_buffer_t *self)
{
  assert(self);

  return self->checkpoint;
}

bool
serializer_buffer_skip(serializer_buffer_t *self, int skip)
{
  assert(self);

  bool ok = 0 <= self->next + skip && self->next + skip <= self->size;

  if (ok)
    self->next += skip;

  return ok;
}
