#include "bitmap.h"
#include <check.h>
#include <stdbool.h>

START_TEST(test_bitmap_new)
{
  bitmap_t *bitmap = NULL;

  ck_assert_ptr_ne(bitmap = bitmap_new(2), NULL);
  ck_assert(!bitmap_is_bit_set(bitmap, 0));
  ck_assert(!bitmap_is_bit_set(bitmap, 1));

  bitmap_destroy(bitmap);
}
END_TEST

START_TEST(test_bitmap_set_then_unset)
{
  bitmap_t *bitmap = NULL;

  ck_assert_ptr_ne(bitmap = bitmap_new(2), NULL);
  ck_assert(!bitmap_is_bit_set(bitmap, 0));
  ck_assert(!bitmap_is_bit_set(bitmap, 1));
  bitmap_set_bit(bitmap, 0);
  ck_assert(bitmap_is_bit_set(bitmap, 0));
  ck_assert(!bitmap_is_bit_set(bitmap, 1));
  bitmap_unset_bit(bitmap, 0);
  ck_assert(!bitmap_is_bit_set(bitmap, 0));
  ck_assert(!bitmap_is_bit_set(bitmap, 1));

  bitmap_destroy(bitmap);
}
END_TEST

START_TEST(test_bitmap_set_all_then_clear)
{
  bitmap_t *bitmap = NULL;

  ck_assert_ptr_ne(bitmap = bitmap_new(9), NULL);
  ck_assert(!bitmap_is_bit_set(bitmap, 0));
  ck_assert(!bitmap_is_bit_set(bitmap, 1));
  ck_assert(!bitmap_is_bit_set(bitmap, 2));
  ck_assert(!bitmap_is_bit_set(bitmap, 3));
  ck_assert(!bitmap_is_bit_set(bitmap, 4));
  ck_assert(!bitmap_is_bit_set(bitmap, 5));
  ck_assert(!bitmap_is_bit_set(bitmap, 6));
  ck_assert(!bitmap_is_bit_set(bitmap, 7));
  ck_assert(!bitmap_is_bit_set(bitmap, 8));
  bitmap_set_all(bitmap);
  ck_assert(bitmap_is_bit_set(bitmap, 0));
  ck_assert(bitmap_is_bit_set(bitmap, 1));
  ck_assert(bitmap_is_bit_set(bitmap, 2));
  ck_assert(bitmap_is_bit_set(bitmap, 3));
  ck_assert(bitmap_is_bit_set(bitmap, 4));
  ck_assert(bitmap_is_bit_set(bitmap, 5));
  ck_assert(bitmap_is_bit_set(bitmap, 6));
  ck_assert(bitmap_is_bit_set(bitmap, 7));
  ck_assert(bitmap_is_bit_set(bitmap, 8));
  bitmap_clear(bitmap);
  ck_assert(!bitmap_is_bit_set(bitmap, 0));
  ck_assert(!bitmap_is_bit_set(bitmap, 1));
  ck_assert(!bitmap_is_bit_set(bitmap, 2));
  ck_assert(!bitmap_is_bit_set(bitmap, 3));
  ck_assert(!bitmap_is_bit_set(bitmap, 4));
  ck_assert(!bitmap_is_bit_set(bitmap, 5));
  ck_assert(!bitmap_is_bit_set(bitmap, 6));
  ck_assert(!bitmap_is_bit_set(bitmap, 7));
  ck_assert(!bitmap_is_bit_set(bitmap, 8));

  bitmap_destroy(bitmap);
}
END_TEST

START_TEST(test_bitmap_set_all_one_by_one_then_check_full)
{
  bitmap_t *bitmap = NULL;

  ck_assert_ptr_ne(bitmap = bitmap_new(9), NULL);
  ck_assert(!bitmap_is_bit_set(bitmap, 0));
  ck_assert(!bitmap_is_bit_set(bitmap, 1));
  ck_assert(!bitmap_is_bit_set(bitmap, 2));
  ck_assert(!bitmap_is_bit_set(bitmap, 3));
  ck_assert(!bitmap_is_bit_set(bitmap, 4));
  ck_assert(!bitmap_is_bit_set(bitmap, 5));
  ck_assert(!bitmap_is_bit_set(bitmap, 6));
  ck_assert(!bitmap_is_bit_set(bitmap, 7));
  ck_assert(!bitmap_is_bit_set(bitmap, 8));
  bitmap_set_bit(bitmap, 0);
  bitmap_set_bit(bitmap, 1);
  bitmap_set_bit(bitmap, 2);
  bitmap_set_bit(bitmap, 3);
  bitmap_set_bit(bitmap, 4);
  bitmap_set_bit(bitmap, 5);
  bitmap_set_bit(bitmap, 6);
  bitmap_set_bit(bitmap, 7);
  bitmap_set_bit(bitmap, 8);
  ck_assert(bitmap_is_bit_set(bitmap, 0));
  ck_assert(bitmap_is_bit_set(bitmap, 1));
  ck_assert(bitmap_is_bit_set(bitmap, 2));
  ck_assert(bitmap_is_bit_set(bitmap, 3));
  ck_assert(bitmap_is_bit_set(bitmap, 4));
  ck_assert(bitmap_is_bit_set(bitmap, 5));
  ck_assert(bitmap_is_bit_set(bitmap, 6));
  ck_assert(bitmap_is_bit_set(bitmap, 7));
  ck_assert(bitmap_is_bit_set(bitmap, 8));
  ck_assert(bitmap_is_full(bitmap));

  bitmap_destroy(bitmap);
}
END_TEST

START_TEST(test_bitmap_set_some_one_by_one_then_check_not_full)
{
  bitmap_t *bitmap = NULL;

  ck_assert_ptr_ne(bitmap = bitmap_new(9), NULL);
  ck_assert(!bitmap_is_bit_set(bitmap, 0));
  ck_assert(!bitmap_is_bit_set(bitmap, 1));
  ck_assert(!bitmap_is_bit_set(bitmap, 2));
  ck_assert(!bitmap_is_bit_set(bitmap, 3));
  ck_assert(!bitmap_is_bit_set(bitmap, 4));
  ck_assert(!bitmap_is_bit_set(bitmap, 5));
  ck_assert(!bitmap_is_bit_set(bitmap, 6));
  ck_assert(!bitmap_is_bit_set(bitmap, 7));
  ck_assert(!bitmap_is_bit_set(bitmap, 8));
  bitmap_set_bit(bitmap, 0);
  bitmap_set_bit(bitmap, 1);
  bitmap_unset_bit(bitmap, 2);
  bitmap_set_bit(bitmap, 3);
  bitmap_set_bit(bitmap, 4);
  bitmap_unset_bit(bitmap, 5);
  bitmap_set_bit(bitmap, 6);
  bitmap_set_bit(bitmap, 7);
  bitmap_unset_bit(bitmap, 8);
  ck_assert(bitmap_is_bit_set(bitmap, 0));
  ck_assert(bitmap_is_bit_set(bitmap, 1));
  ck_assert(!bitmap_is_bit_set(bitmap, 2));
  ck_assert(bitmap_is_bit_set(bitmap, 3));
  ck_assert(bitmap_is_bit_set(bitmap, 4));
  ck_assert(!bitmap_is_bit_set(bitmap, 5));
  ck_assert(bitmap_is_bit_set(bitmap, 6));
  ck_assert(bitmap_is_bit_set(bitmap, 7));
  ck_assert(!bitmap_is_bit_set(bitmap, 8));
  ck_assert(!bitmap_is_full(bitmap));

  bitmap_destroy(bitmap);
}
END_TEST

START_TEST(test_bitmap_pattern_match)
{
  bitmap_t *bitmap = NULL;
  char *binary_string = "10xx01xx0";
  int binary_string_size = 9;
  int index = 0;

  ck_assert_ptr_ne(bitmap = bitmap_new(11), NULL);
  ck_assert(!bitmap_is_bit_set(bitmap, 0));
  ck_assert(!bitmap_is_bit_set(bitmap, 1));
  ck_assert(!bitmap_is_bit_set(bitmap, 2));
  ck_assert(!bitmap_is_bit_set(bitmap, 3));
  ck_assert(!bitmap_is_bit_set(bitmap, 4));
  ck_assert(!bitmap_is_bit_set(bitmap, 5));
  ck_assert(!bitmap_is_bit_set(bitmap, 6));
  ck_assert(!bitmap_is_bit_set(bitmap, 7));
  ck_assert(!bitmap_is_bit_set(bitmap, 8));
  ck_assert(!bitmap_is_bit_set(bitmap, 9));
  ck_assert(!bitmap_is_bit_set(bitmap, 10));
  bitmap_set_bit(bitmap, 0);
  bitmap_set_bit(bitmap, 1);
  bitmap_unset_bit(bitmap, 2);
  bitmap_unset_bit(bitmap, 3);
  bitmap_set_bit(bitmap, 4);
  bitmap_unset_bit(bitmap, 5);
  bitmap_set_bit(bitmap, 6);
  bitmap_unset_bit(bitmap, 7);
  bitmap_set_bit(bitmap, 8);
  bitmap_unset_bit(bitmap, 9);
  bitmap_unset_bit(bitmap, 10);
  ck_assert(bitmap_is_bit_set(bitmap, 0));
  ck_assert(bitmap_is_bit_set(bitmap, 1));
  ck_assert(!bitmap_is_bit_set(bitmap, 2));
  ck_assert(!bitmap_is_bit_set(bitmap, 3));
  ck_assert(bitmap_is_bit_set(bitmap, 4));
  ck_assert(!bitmap_is_bit_set(bitmap, 5));
  ck_assert(bitmap_is_bit_set(bitmap, 6));
  ck_assert(!bitmap_is_bit_set(bitmap, 7));
  ck_assert(bitmap_is_bit_set(bitmap, 8));
  ck_assert(!bitmap_is_bit_set(bitmap, 9));
  ck_assert(!bitmap_is_bit_set(bitmap, 10));
  ck_assert(
    bitmap_pattern_match(bitmap, binary_string, binary_string_size, &index));
  ck_assert_int_eq(index, 1);

  bitmap_destroy(bitmap);
}
END_TEST

START_TEST(test_bitmap_pattern_not_match)
{
  bitmap_t *bitmap = NULL;
  char *binary_string = "00xx01xx0";
  int binary_string_size = 9;
  int index = 0;

  ck_assert_ptr_ne(bitmap = bitmap_new(11), NULL);
  ck_assert(!bitmap_is_bit_set(bitmap, 0));
  ck_assert(!bitmap_is_bit_set(bitmap, 1));
  ck_assert(!bitmap_is_bit_set(bitmap, 2));
  ck_assert(!bitmap_is_bit_set(bitmap, 3));
  ck_assert(!bitmap_is_bit_set(bitmap, 4));
  ck_assert(!bitmap_is_bit_set(bitmap, 5));
  ck_assert(!bitmap_is_bit_set(bitmap, 6));
  ck_assert(!bitmap_is_bit_set(bitmap, 7));
  ck_assert(!bitmap_is_bit_set(bitmap, 8));
  ck_assert(!bitmap_is_bit_set(bitmap, 9));
  ck_assert(!bitmap_is_bit_set(bitmap, 10));
  bitmap_set_bit(bitmap, 0);
  bitmap_set_bit(bitmap, 1);
  bitmap_unset_bit(bitmap, 2);
  bitmap_unset_bit(bitmap, 3);
  bitmap_set_bit(bitmap, 4);
  bitmap_unset_bit(bitmap, 5);
  bitmap_set_bit(bitmap, 6);
  bitmap_unset_bit(bitmap, 7);
  bitmap_set_bit(bitmap, 8);
  bitmap_unset_bit(bitmap, 9);
  bitmap_unset_bit(bitmap, 10);
  ck_assert(bitmap_is_bit_set(bitmap, 0));
  ck_assert(bitmap_is_bit_set(bitmap, 1));
  ck_assert(!bitmap_is_bit_set(bitmap, 2));
  ck_assert(!bitmap_is_bit_set(bitmap, 3));
  ck_assert(bitmap_is_bit_set(bitmap, 4));
  ck_assert(!bitmap_is_bit_set(bitmap, 5));
  ck_assert(bitmap_is_bit_set(bitmap, 6));
  ck_assert(!bitmap_is_bit_set(bitmap, 7));
  ck_assert(bitmap_is_bit_set(bitmap, 8));
  ck_assert(!bitmap_is_bit_set(bitmap, 9));
  ck_assert(!bitmap_is_bit_set(bitmap, 10));
  ck_assert(
    !bitmap_pattern_match(bitmap, binary_string, binary_string_size, &index));
  ck_assert_int_eq(index, 0);

  bitmap_destroy(bitmap);
}
END_TEST

START_TEST(test_bitmap_pattern_too_big)
{
  bitmap_t *bitmap = NULL;
  char *binary_string = "xxxxxxxxxxxxxxxxxxxx";
  int binary_string_size = 20;
  int index = 0;

  ck_assert_ptr_ne(bitmap = bitmap_new(11), NULL);
  ck_assert(!bitmap_is_bit_set(bitmap, 0));
  ck_assert(!bitmap_is_bit_set(bitmap, 1));
  ck_assert(!bitmap_is_bit_set(bitmap, 2));
  ck_assert(!bitmap_is_bit_set(bitmap, 3));
  ck_assert(!bitmap_is_bit_set(bitmap, 4));
  ck_assert(!bitmap_is_bit_set(bitmap, 5));
  ck_assert(!bitmap_is_bit_set(bitmap, 6));
  ck_assert(!bitmap_is_bit_set(bitmap, 7));
  ck_assert(!bitmap_is_bit_set(bitmap, 8));
  ck_assert(!bitmap_is_bit_set(bitmap, 9));
  ck_assert(!bitmap_is_bit_set(bitmap, 10));
  bitmap_set_bit(bitmap, 0);
  bitmap_set_bit(bitmap, 1);
  bitmap_unset_bit(bitmap, 2);
  bitmap_unset_bit(bitmap, 3);
  bitmap_set_bit(bitmap, 4);
  bitmap_unset_bit(bitmap, 5);
  bitmap_set_bit(bitmap, 6);
  bitmap_unset_bit(bitmap, 7);
  bitmap_set_bit(bitmap, 8);
  bitmap_unset_bit(bitmap, 9);
  bitmap_unset_bit(bitmap, 10);
  ck_assert(bitmap_is_bit_set(bitmap, 0));
  ck_assert(bitmap_is_bit_set(bitmap, 1));
  ck_assert(!bitmap_is_bit_set(bitmap, 2));
  ck_assert(!bitmap_is_bit_set(bitmap, 3));
  ck_assert(bitmap_is_bit_set(bitmap, 4));
  ck_assert(!bitmap_is_bit_set(bitmap, 5));
  ck_assert(bitmap_is_bit_set(bitmap, 6));
  ck_assert(!bitmap_is_bit_set(bitmap, 7));
  ck_assert(bitmap_is_bit_set(bitmap, 8));
  ck_assert(!bitmap_is_bit_set(bitmap, 9));
  ck_assert(!bitmap_is_bit_set(bitmap, 10));
  ck_assert(
    !bitmap_pattern_match(bitmap, binary_string, binary_string_size, &index));
  ck_assert_int_eq(index, 0);

  bitmap_destroy(bitmap);
}
END_TEST

START_TEST(test_bitmap_check_while_iterating)
{
  bitmap_t *bitmap = NULL;
  int values[11] = { 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0 };
  int bit_state;
  int i;

  ck_assert_ptr_ne(bitmap = bitmap_new(11), NULL);
  ck_assert(!bitmap_is_bit_set(bitmap, 0));
  ck_assert(!bitmap_is_bit_set(bitmap, 1));
  ck_assert(!bitmap_is_bit_set(bitmap, 2));
  ck_assert(!bitmap_is_bit_set(bitmap, 3));
  ck_assert(!bitmap_is_bit_set(bitmap, 4));
  ck_assert(!bitmap_is_bit_set(bitmap, 5));
  ck_assert(!bitmap_is_bit_set(bitmap, 6));
  ck_assert(!bitmap_is_bit_set(bitmap, 7));
  ck_assert(!bitmap_is_bit_set(bitmap, 8));
  ck_assert(!bitmap_is_bit_set(bitmap, 9));
  ck_assert(!bitmap_is_bit_set(bitmap, 10));
  bitmap_set_bit(bitmap, 0);
  bitmap_set_bit(bitmap, 1);
  bitmap_unset_bit(bitmap, 2);
  bitmap_unset_bit(bitmap, 3);
  bitmap_set_bit(bitmap, 4);
  bitmap_unset_bit(bitmap, 5);
  bitmap_set_bit(bitmap, 6);
  bitmap_unset_bit(bitmap, 7);
  bitmap_set_bit(bitmap, 8);
  bitmap_unset_bit(bitmap, 9);
  bitmap_unset_bit(bitmap, 10);
  ck_assert(bitmap_is_bit_set(bitmap, 0));
  ck_assert(bitmap_is_bit_set(bitmap, 1));
  ck_assert(!bitmap_is_bit_set(bitmap, 2));
  ck_assert(!bitmap_is_bit_set(bitmap, 3));
  ck_assert(bitmap_is_bit_set(bitmap, 4));
  ck_assert(!bitmap_is_bit_set(bitmap, 5));
  ck_assert(bitmap_is_bit_set(bitmap, 6));
  ck_assert(!bitmap_is_bit_set(bitmap, 7));
  ck_assert(bitmap_is_bit_set(bitmap, 8));
  ck_assert(!bitmap_is_bit_set(bitmap, 9));
  ck_assert(!bitmap_is_bit_set(bitmap, 10));

  i = 0;
  BITMAP_FOREACH_BEGIN(bitmap, bit_state)
  {
    bit_state = values[i];
    ++i;
  }
  BITMAP_FOREACH_END

  bitmap_destroy(bitmap);
}
END_TEST

Suite *
bitmap_suite(void)
{
  Suite *s = NULL;
  TCase *tc_core = NULL;

  s = suite_create("Bitmap");

  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_bitmap_new);
  tcase_add_test(tc_core, test_bitmap_set_then_unset);
  tcase_add_test(tc_core, test_bitmap_set_all_then_clear);
  tcase_add_test(tc_core, test_bitmap_set_all_one_by_one_then_check_full);
  tcase_add_test(tc_core, test_bitmap_set_some_one_by_one_then_check_not_full);
  tcase_add_test(tc_core, test_bitmap_pattern_match);
  tcase_add_test(tc_core, test_bitmap_pattern_not_match);
  tcase_add_test(tc_core, test_bitmap_pattern_too_big);
  tcase_add_test(tc_core, test_bitmap_check_while_iterating);
  suite_add_tcase(s, tc_core);

  return s;
}
