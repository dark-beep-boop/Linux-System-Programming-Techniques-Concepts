#include "bitmap.h"
#include "defines.h"
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

static unsigned bitmap_bytesize(const bitmap_t *self);
static int bitmap_bitindex_to_byteindex(const bitmap_t *self, int index);
static bool bitmap_read_pattern_byte(
  const char *binary_string,
  int n_bits,
  int *binary_string_index,
  uint8_t *byte_mask,
  uint8_t *byte_pattern,
  int *byte_pattern_size);
static bool bitmap_match_first_byte_of_pattern(
  const bitmap_t *self,
  uint8_t byte_mask,
  uint8_t byte_pattern,
  int pattern_size_from_byte,
  int *index);

unsigned
bitmap_bytesize(const bitmap_t *self)
{
  assert(self);

  return BITSIZE_TO_BYTESIZE(self->size);
}

int
bitmap_bitindex_to_byteindex(const bitmap_t *self, int index)
{
  assert(self);
  assert(index < self->size);

  return BITINDEX_TO_BYTEINDEX(self, index);
}

static bool
bitmap_read_pattern_byte(
  const char *binary_string,
  int n_bits,
  int *binary_string_index,
  uint8_t *byte_mask,
  uint8_t *byte_pattern,
  int *byte_pattern_size)
{
  assert(binary_string);
  assert(binary_string_index);
  assert(byte_mask);
  assert(byte_pattern);
  assert(byte_pattern_size);

  bool ok = *binary_string_index < n_bits && *byte_pattern_size < 8;
  uint8_t aux_mask = *byte_mask;
  uint8_t aux_pattern = *byte_pattern;
  int index = 0;

  while (ok && index + *binary_string_index < n_bits &&
         index + *byte_pattern_size < 8) {
    switch (binary_string[index + *binary_string_index]) {
      case '0':
        SET_BIT(aux_mask, index + *byte_pattern_size);
        UNSET_BIT(aux_pattern, index + *byte_pattern_size);
        break;

      case '1':
        SET_BIT(aux_mask, index + *byte_pattern_size);
        SET_BIT(aux_pattern, index + *byte_pattern_size);
        break;

      case 'x':
      case 'X':
        UNSET_BIT(aux_mask, index + *byte_pattern_size);
        UNSET_BIT(aux_pattern, index + *byte_pattern_size);
        break;

      default:
        ok = false;
    }

    ++index;
  }

  if (ok) {
    *binary_string_index += index;
    *byte_pattern_size += index;
    *byte_mask = aux_mask;
    *byte_pattern = aux_pattern;
  }

  return ok;
}

bool
bitmap_match_first_byte_of_pattern(
  const bitmap_t *self,
  uint8_t byte_mask,
  uint8_t byte_pattern,
  int pattern_size_from_byte,
  int *index)
{
  assert(self);
  assert(index);
  assert(0 < byte_mask);
  assert(0 < pattern_size_from_byte);
  assert(pattern_size_from_byte <= self->size);

  bool matched = false;
  int aux_index = *index;
  uint8_t aux_mask = byte_mask;
  uint8_t aux_pattern = byte_pattern;

  while (!matched && aux_index + pattern_size_from_byte <= self->size) {
    matched = MATCH_BITS(
      self->bit_array[bitmap_bitindex_to_byteindex(self, aux_index)],
      aux_mask,
      aux_pattern);

    if (!matched) {
      ++aux_index;
      if (aux_index % 8) {
        aux_mask <<= 1;
        aux_pattern <<= 1;
      } else {
        aux_mask = byte_mask;
        aux_pattern = byte_pattern;
      }
    }
  }

  *index = aux_index;

  return matched;
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
    printf(
      "%d",
      GET_BIT(
        self->bit_array[bitmap_bitindex_to_byteindex(self, index)],
        index % 8));
  }
}

void
bitmap_set_bit(bitmap_t *self, int index)
{
  assert(self);
  assert(index < self->size);

  SET_BIT(
    self->bit_array[bitmap_bitindex_to_byteindex(self, index)],
    index % 8);
}

void
bitmap_unset_bit(bitmap_t *self, int index)
{
  assert(self);
  assert(index < self->size);

  UNSET_BIT(
    self->bit_array[bitmap_bitindex_to_byteindex(self, index)],
    index % 8);
}

bool
bitmap_is_bit_set(const bitmap_t *self, int index)
{
  assert(self);
  assert(index < self->size);

  return IS_BIT_SET(
    self->bit_array[bitmap_bitindex_to_byteindex(self, index)],
    index % 8);
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

bool
bitmap_is_full(bitmap_t *self)
{
  assert(self);

  bool is_full;
  unsigned index;
  uint8_t pattern;

  /* The first bytes may have unuseful bits */
  pattern = 0xff >> (8 - (self->size % 8));
  if (self->size % 8) {
    is_full = MATCH_BITS(self->bit_array[0], pattern, pattern);
  }

  index = bitmap_bytesize(self) - 1;
  while (is_full && index > 0) {
    is_full = self->bit_array[index] == (char)0xff;
    --index;
  }

  return is_full;
}

bool
bitmap_pattern_match(bitmap_t *self, char *binary_string, int n_bits, int *i)
{
  assert(self);
  assert(binary_string);

  bool ok = true;
  bool match = false;

  int binary_string_index = 0;

  uint8_t byte_mask = 0;
  uint8_t byte_pattern = 0;
  int byte_pattern_size = 0;

  int aux_first_index = 0;

  int aux_next_index;
  int byte_pattern_shift;
  int byte_index;

  while (ok && !match && aux_first_index + n_bits <= self->size) {
    ok = bitmap_read_pattern_byte(
      binary_string,
      n_bits,
      &binary_string_index,
      &byte_mask,
      &byte_pattern,
      &byte_pattern_size);

    if (ok) {
      match = bitmap_match_first_byte_of_pattern(
        self,
        byte_mask,
        byte_pattern,
        byte_pattern_size + n_bits - binary_string_index,
        &aux_first_index);

      if (match && binary_string_index < n_bits) {
        aux_next_index = aux_first_index + byte_pattern_size;
        byte_pattern_shift = 8 - (aux_next_index % 8);

        byte_mask >>= byte_pattern_shift;
        byte_pattern >>= byte_pattern_shift;
        byte_pattern_size -= byte_pattern_shift;
        byte_index = bitmap_bitindex_to_byteindex(self, aux_next_index);
      }
    }

    while (ok && match && binary_string_index < n_bits) {
      ok = bitmap_read_pattern_byte(
        binary_string,
        n_bits,
        &binary_string_index,
        &byte_mask,
        &byte_pattern,
        &byte_pattern_size);

      if (ok) {
        match =
          MATCH_BITS(self->bit_array[byte_index], byte_mask, byte_pattern);
        ++byte_index;
        byte_mask = 0;
        byte_pattern = 0;
        byte_pattern_size = 0;
      }
    }
  }

  if (match)
    *i = aux_first_index;

  return match;
}
