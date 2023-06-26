#ifndef OFFSET_OF_H
#define OFFSET_OF_H

#include "defines.h"

#define offset_of(type, field) (size_t) & ((type *)NULL)->field
#define container_of(element, type, field)                                     \
  (type *)(((size_t)element) - offset_of(type, field))
#define convert_to_container_func(type, field, field_type)                     \
  type *JOIN(field_type, JOIN(_to_, type))(field_type * _field)                \
  {                                                                            \
    return container_of(_field, type, field);                                  \
  }

#endif /* OFFSET_OF_H */
