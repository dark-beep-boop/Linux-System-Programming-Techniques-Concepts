#include "bitmap.h"
#include "bitsop.h"
#include "defines.h"
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

static unsigned bitmap_bytesize(const bitmap_t *self);

unsigned
bitmap_bytesize(const bitmap_t *self)
{
  assert(self);

  return self->size / 8 + (self->size % 8 ? 1 : 0);
}

bool
bitmap_init(bitmap_t *self, int size)
{
  assert(self);

  CLEAR(self, bitmap_t);

  self->size = size;
  ALLOCATE_MANY_FAIL(self->bit_array, char, bitmap_bytesize(self));

  return true;

fail:
  if (self->bit_array)
    free(self->bit_array);

  return false;
}

void
bitmap_finalize(bitmap_t *self)
{
  assert(self);

  if (self->bit_array)
    free(self->bit_array);
}

bitmap_t *
bitmap_new(int size)
{
  bitmap_t *new_object = NULL;

  ALLOCATE_FAIL(new_object, bitmap_t);
  TRY_FAIL(bitmap_init(new_object, size), "Bitmap initialization failed");

  return new_object;

fail:
  if (new_object)
    free(new_object);

  return NULL;
}

void
bitmap_destroy(bitmap_t *self)
{
  if (self) {
    bitmap_finalize(self);
    free(self);
  }
}

void
bitmap_print(const bitmap_t *self)
{
  assert(self);

  unsigned index;

  for (index = 0; index < self->size; ++index) {
    printf("%d", GET_BIT(self->bit_array[index / 8], index % 8));
  }
}

void
bitmap_set_bit(bitmap_t *self, int index)
{
  assert(self);
  assert(index < self->size);

  SET_BIT(self->bit_array[index / 8], index % 8);
}

void
bitmap_unset_bit(bitmap_t *self, int index)
{
  assert(self);
  assert(index < self->size);

  UNSET_BIT(self->bit_array[index / 8], index % 8);
}

bool
bitmap_is_bit_set(const bitmap_t *self, int index)
{
  assert(self);
  assert(index < self->size);

  return IS_BIT_SET(self->bit_array[index / 8], index % 8);
}

void
bitmap_clear(bitmap_t *self)
{
  assert(self);

  memset(self->bit_array, 0, bitmap_bytesize(self));
}

void
bitmap_set_all(bitmap_t *self)
{
  assert(self);

  memset(self->bit_array, 0xff, bitmap_bytesize(self));
}
