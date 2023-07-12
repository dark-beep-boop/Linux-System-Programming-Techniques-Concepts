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

#endif /* SERIALIZE_H */
