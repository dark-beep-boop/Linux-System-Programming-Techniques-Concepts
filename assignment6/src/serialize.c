#include "serialize.h"

bool
serializer_buffer_init(serializer_buffer_t *self)
{
  return false;
}

bool
serializer_buffer_init_with_size(serializer_buffer_t *self, int size)
{
  return false;
}

void
serializer_buffer_finalize(serializer_buffer_t *self)
{
}

serializer_buffer_t *
serializer_buffer_new(void)
{
  return NULL;
}

serializer_buffer_t *
serializer_buffer_new_with_size(int size)
{
  return NULL;
}

void
serializer_buffer_destroy(serializer_buffer_t *self)
{
}
