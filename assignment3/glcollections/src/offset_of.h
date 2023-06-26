#ifndef OFFSET_OF_H
#define OFFSET_OF_H

#define offset_of(type, field) (size_t) & ((type *)NULL)->field
#define container_of(element, type, field)                                     \
  (type *)(((size_t)element) - offset_of(type, field))

#endif /* OFFSET_OF_H */
