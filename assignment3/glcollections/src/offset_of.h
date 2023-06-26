#ifndef OFFSET_OF_H
#define OFFSET_OF_H

#define offset_of(type, field) (size_t) & ((type *)NULL)->field

#endif /* OFFSET_OF_H */
