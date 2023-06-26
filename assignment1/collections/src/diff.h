#ifndef DIFF_H
#define DIFF_H

typedef void *(*iterator_t)(void *);
typedef void *(*comparator_t)(void *, void *);
typedef void *(*get_app_data_t)(void *);

int diff(
  void *root_first,
  void *root_second,
  iterator_t,
  comparator_t,
  get_app_data_t);

#endif /* DIFF_H */
