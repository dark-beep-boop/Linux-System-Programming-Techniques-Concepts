#include "bt.h"
#include "diff.h"
#include "dll.h"
#include "ll.h"
#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Step 2 is implemented in collections/src/dll.c */
/* Step 3 is implemented in src/student.c */
/* Step 4 is implemented in collections/src/dll.c */

int
main(int argc, char **argv)
{
  /* Student database list 1 */
  student_t *student1 = student_new();
  student_set_name(student1, "Abhishek");
  student_set_year_of_birth(student1, 2000);
  student_set_height(student1, 167);
  student_set_weight(student1, 80);
  student_set_total_marks(student1, 90);

  student_t *student2 = student_new();
  student_set_name(student2, "Sagar");
  student_set_year_of_birth(student2, 2001);
  student_set_height(student2, 170);
  student_set_weight(student2, 82);
  student_set_total_marks(student2, 80);

  student_t *student3 = student_new();
  student_set_name(student3, "Vineet");
  student_set_year_of_birth(student3, 2002);
  student_set_height(student3, 161);
  student_set_weight(student3, 62);
  student_set_total_marks(student3, 72);

  student_t *student4 = student_new();
  student_set_name(student4, "Neeraj");
  student_set_year_of_birth(student4, 1998);
  student_set_height(student4, 167);
  student_set_weight(student4, 76);
  student_set_total_marks(student4, 67);

  dll_t *student_db1 = dll_new();
  dll_push_head(student_db1, student1);
  dll_push_head(student_db1, student2);
  dll_push_head(student_db1, student3);
  dll_push_head(student_db1, student4);

  /* Student database list 2 */
  student_t *student5 = student_new();
  student_set_name(student5, "Abhishek");
  student_set_year_of_birth(student5, 2000);
  student_set_height(student5, 167);
  student_set_weight(student5, 80);
  student_set_total_marks(student5, 90);

  student_t *student6 = student_new();
  student_set_name(student6, "Sagar");
  student_set_year_of_birth(student6, 2001);
  student_set_height(student6, 170);
  student_set_weight(student6, 82);
  student_set_total_marks(student6, 80);

  student_t *student7 = student_new();
  student_set_name(student7, "Vineet");
  student_set_year_of_birth(student7, 2002);
  student_set_height(student7, 161);
  student_set_weight(student7, 62);
  student_set_total_marks(student7, 72);

  student_t *student8 = student_new();
  student_set_name(student8, "Neeraj");
  student_set_year_of_birth(student8, 1998);
  student_set_height(student8, 167);
  student_set_weight(student8, 76);
  student_set_total_marks(student8, 67);

  dll_t *student_db2 = dll_new();
  dll_push_head(student_db2, student5);
  dll_push_head(student_db2, student6);
  dll_push_head(student_db2, student7);
  dll_push_head(student_db2, student8);

  /* Student database list 3 */
  dll_t *student_db3 = dll_new();

  /* Student database list 4 */
  dll_t *student_db4 = dll_new();

  student_t *student9 = student_new();
  student_set_name(student9, "Abhishek");
  student_set_year_of_birth(student9, 2000);
  student_set_height(student9, 167);
  student_set_weight(student9, 80);
  student_set_total_marks(student9, 90);

  student_t *student10 = student_new();
  student_set_name(student10, "Sagar");
  student_set_year_of_birth(student10, 2001);
  student_set_height(student10, 170);
  student_set_weight(student10, 82);
  student_set_total_marks(student10, 80);

  student_t *student11 = student_new();
  student_set_name(student11, "Vineet");
  student_set_year_of_birth(student11, 2002);
  student_set_height(student11, 161);
  student_set_weight(student11, 62);
  student_set_total_marks(student11, 72);

  student_t *student12 = student_new();
  student_set_name(student12, "Neeraj");
  student_set_year_of_birth(student12, 1998);
  student_set_height(student12, 167);
  student_set_weight(student12, 76);
  student_set_total_marks(student12, 67);

  /* Student database list 5 */
  ll_t *student_db5 = ll_new();
  ll_push_head(student_db5, student9);
  ll_push_head(student_db5, student10);
  ll_push_head(student_db5, student11);
  ll_push_head(student_db5, student12);

  /* Student database list 6 */
  ll_t *student_db6 = ll_new();
  ll_push_head(student_db6, student9);
  ll_push_head(student_db6, student10);
  ll_push_head(student_db6, student11);
  ll_push_head(student_db6, student12);

  student_t *student13 = student_new();
  student_set_name(student13, "Abhishek");
  student_set_year_of_birth(student13, 2000);
  student_set_height(student13, 167);
  student_set_weight(student13, 80);
  student_set_total_marks(student13, 90);

  student_t *student14 = student_new();
  student_set_name(student14, "Sagar");
  student_set_year_of_birth(student14, 2001);
  student_set_height(student14, 170);
  student_set_weight(student14, 82);
  student_set_total_marks(student14, 80);

  student_t *student15 = student_new();
  student_set_name(student15, "Vineet");
  student_set_year_of_birth(student15, 2002);
  student_set_height(student15, 161);
  student_set_weight(student15, 62);
  student_set_total_marks(student15, 72);

  student_t *student16 = student_new();
  student_set_name(student16, "Neeraj");
  student_set_year_of_birth(student16, 1998);
  student_set_height(student16, 167);
  student_set_weight(student16, 76);
  student_set_total_marks(student16, 67);

  /* Student database binary tree 7 */
  bt_t *student_db7 = bt_new();
  bt_insert(student_db7, student13);
  bt_insert(student_db7, student14);
  bt_insert(student_db7, student15);
  bt_insert(student_db7, student16);

  /* Student database binary tree 8 */
  bt_t *student_db8 = bt_new();
  bt_insert(student_db8, student13);
  bt_insert(student_db8, student14);
  bt_insert(student_db8, student15);
  bt_insert(student_db8, student16);

  /* Step 6 */
  if (
    diff(
      (void *)dll_get_head(student_db1),
      (void *)dll_get_head(student_db2),
      (iterator_t)dll_node_next,
      (comparator_t)student_compare,
      (get_app_data_t)dll_node_get) == 0)
    printf("Data sructures 1 and 2 are equal\n");
  else
    printf("Data sructures 1 and 2 are not equal\n");

  if (
    diff(
      (void *)dll_get_head(student_db1),
      (void *)dll_get_head(student_db3),
      (iterator_t)dll_node_next,
      (comparator_t)student_compare,
      (get_app_data_t)dll_node_get) == 0)
    printf("Data sructures 1 and 3 are equal\n");
  else
    printf("Data sructures 1 and 3 are not equal\n");

  if (
    diff(
      (void *)dll_get_head(student_db3),
      (void *)dll_get_head(student_db4),
      (iterator_t)dll_node_next,
      (comparator_t)student_compare,
      (get_app_data_t)dll_node_get) == 0)
    printf("Data sructures 3 and 4 are equal\n");
  else
    printf("Data sructures 3 and 4 are not equal\n");

  if (
    diff(
      (void *)ll_get_head(student_db5),
      (void *)ll_get_head(student_db6),
      (iterator_t)ll_node_next,
      (comparator_t)student_compare,
      (get_app_data_t)ll_node_get) == 0)
    printf("Data sructures 5 and 6 are equal\n");
  else
    printf("Data sructures 5 and 6 are not equal\n");

  if (
    diff(
      (void *)bt_get_first_node_inorder(student_db7),
      (void *)bt_get_first_node_inorder(student_db8),
      (iterator_t)bt_node_next_inorder,
      (comparator_t)student_compare,
      (get_app_data_t)bt_node_get) == 0)
    printf("Data sructures 7 and 8 are equal\n");
  else
    printf("Data sructures 7 and 8 are not equal\n");

  bt_destroy(student_db8);
  bt_destroy(student_db7);
  ll_destroy(student_db6);
  ll_destroy(student_db5);
  dll_destroy(student_db4);
  dll_destroy(student_db3);
  dll_destroy(student_db2);
  dll_destroy(student_db1);
  student_destroy(student16);
  student_destroy(student15);
  student_destroy(student14);
  student_destroy(student13);
  student_destroy(student12);
  student_destroy(student11);
  student_destroy(student10);
  student_destroy(student9);
  student_destroy(student8);
  student_destroy(student7);
  student_destroy(student6);
  student_destroy(student5);
  student_destroy(student4);
  student_destroy(student3);
  student_destroy(student2);
  student_destroy(student1);

  return 0;
}
