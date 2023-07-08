#ifndef BITMAP_H
#define BITMAP_H

#include <stdbool.h>

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

#endif /* BITMAP_H */
