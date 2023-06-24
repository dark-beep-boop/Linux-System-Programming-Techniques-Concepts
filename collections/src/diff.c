#include <stdio.h>
#include <stdlib.h>

#include "diff.h"

/*Step 5 : */

/* Return 0 if ds1 and ds2 are clones, else return -1 */
int
diff(
  void *root_first,            /* Pointer to Data structure 1 */
  void *root_second,           /* Pointer to data structure 2 */
  iterator_t iterator,         /* Iterator function callback */
  comparator_t comparator,     /* Comparison function callback */
  get_app_data_t get_app_data) /* Data getter callback */
{
  int is_different = 0;
  void *current1 = root_first;
  void *current2 = root_second;

  if (
    current1 && current2 &&
    (*comparator)((*get_app_data)(current1), (*get_app_data)(current2)))
    is_different = -1;
  current1 = (*iterator)(current1);
  current2 = (*iterator)(current2);
  while (current1 && current2 && current1 != root_first &&
         current2 != root_second && !is_different) {
    if ((*comparator)((*get_app_data)(current1), (*get_app_data)(current2)))
      is_different = -1;
    current1 = (*iterator)(current1);
    current2 = (*iterator)(current2);
  }

  if (
    (!current1 && current2 || current1 && !current2) ||
    (current1 == root_first && current2 != root_second ||
     current1 != root_first && current2 == root_second))
    is_different = -1;

  return is_different;
}
