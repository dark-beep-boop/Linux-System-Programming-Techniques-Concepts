#ifndef BITMAP_H
#define BITMAP_H

#include <stdbool.h>

#define _MASK(bit) (1 << (bit))
#define MASK(bit) _MASK(bit)

#define _COMPLEMENT(n) (~(n))
#define COMPLEMENT(n) _COMPLEMENT(n)

#define _SET_BIT(n, bit) (n |= MASK(bit))
#define SET_BIT(n, bit) _SET_BIT(n, bit)

#define _UNSET_BIT(n, bit) (n &= COMPLEMENT(MASK(bit)))
#define UNSET_BIT(n, bit) _UNSET_BIT(n, bit)

#define _IS_BIT_SET(n, bit) (((n)&MASK(bit)) != 0)
#define IS_BIT_SET(n, bit) _IS_BIT_SET(n, bit)

#define _GET_BIT(n, bit) (((n)&MASK(bit)) >> (bit))
#define GET_BIT(n, bit) _GET_BIT(n, bit)

#define _TOGGLE_BIT(n, bit) (n ^= MASK(bit))
#define TOGGLE_BIT(n, bit) _TOGGLE_BIT(n, bit)

#define _MATCH_BITS(n, mask, pattern) (((n) & (mask)) == (pattern))
#define MATCH_BITS(n, mask, pattern) _MATCH_BITS(n, mask, pattern)

#define _BITSIZE_TO_BYTESIZE(size) ((size) / 8 + ((size) % 8 ? 1 : 0))
#define BITSIZE_TO_BYTESIZE(size) _BITSIZE_TO_BYTESIZE(size)

#define _BITINDEX_TO_BYTEINDEX(bitmap_ptr, index)                              \
  (BITSIZE_TO_BYTESIZE(bitmap_ptr->size) - 1 - (index) / 8)
#define BITINDEX_TO_BYTEINDEX(bitmap_ptr, index)                               \
  _BITINDEX_TO_BYTEINDEX(bitmap_ptr, index)

#define _INTERNAL_BITINDEX(index) ((index) % 8)
#define INTERNAL_BITINDEX(index) _INTERNAL_BITINDEX(index)

struct bitmap
{
  char *bit_array;
  int size;
};
typedef struct bitmap bitmap_t;

bool bitmap_init(bitmap_t *self, int size);
void bitmap_finalize(bitmap_t *self);
bitmap_t *bitmap_new(int size);
void bitmap_destroy(bitmap_t *self);
void bitmap_print(const bitmap_t *self);
void bitmap_set_bit(bitmap_t *self, int index);
void bitmap_unset_bit(bitmap_t *self, int index);
bool bitmap_is_bit_set(const bitmap_t *self, int index);
void bitmap_clear(bitmap_t *self);
void bitmap_set_all(bitmap_t *self);
bool bitmap_is_full(bitmap_t *self);
bool bitmap_pattern_match(
  bitmap_t *bitmap,
  char *binary_string,
  int n_bits,
  int *i);

#define BITMAP_FOREACH_BEGIN(bitmap_ptr, bit_state)                            \
  {                                                                            \
    int index;                                                                 \
    for (index = 0; index < bitmap_ptr->size; ++index) {                       \
      bit_state = GET_BIT(                                                     \
        bitmap_ptr->bit_array[BITINDEX_TO_BYTEINDEX(bitmap_ptr, index)],       \
        INTERNAL_BITINDEX(index));

#define BITMAP_FOREACH_END                                                     \
  }                                                                            \
  }

#endif /* BITMAP_H */
