#ifndef SERIALIZE_H
#define SERIALIZE_H

#include <stdbool.h>
#include <stddef.h>

#define SERIALIZE_BUFFER_DEFAULT_SIZE 512

struct serializer_buffer
{
  void *buffer;
  int size;
  int next;
  int checkpoint;
};
typedef struct serializer_buffer serializer_buffer_t;

bool serializer_buffer_init(serializer_buffer_t *self);
bool serializer_buffer_init_with_size(serializer_buffer_t *self, int size);
void serializer_buffer_finalize(serializer_buffer_t *self);
serializer_buffer_t *serializer_buffer_new(void);
serializer_buffer_t *serializer_buffer_new_with_size(int size);
void serializer_buffer_destroy(serializer_buffer_t *self);
bool serializer_buffer_is_empty(const serializer_buffer_t *self);
bool serializer_buffer_serialize_string(
  serializer_buffer_t *self,
  const char *orig,
  int len);
bool serializer_buffer_deserialize_string(
  serializer_buffer_t *self,
  char *dest,
  int len);
bool serializer_buffer_copy_by_offset(
  serializer_buffer_t *self,
  int offset,
  const char *orig,
  int len);
void serializer_buffer_mark_checkpoint(serializer_buffer_t *self);
int serializer_buffer_get_checkpoint(const serializer_buffer_t *self);
bool serializer_buffer_skip(serializer_buffer_t *self, int skip);

#endif /* SERIALIZE_H */
