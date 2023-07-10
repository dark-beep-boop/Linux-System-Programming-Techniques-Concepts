#include "bitmap.h"
#include <check.h>
#include <stdbool.h>

START_TEST(test_bitmap_new)
{
  bitmap_t *bitmap = NULL;

  ck_assert_ptr_ne(bitmap = bitmap_new(2), NULL);
  ck_assert_int_eq(bitmap_is_bit_set(bitmap, 0), false);
  ck_assert_int_eq(bitmap_is_bit_set(bitmap, 1), false);

  bitmap_destroy(bitmap);
}
END_TEST

START_TEST(test_bitmap_set_then_unset)
{
  bitmap_t *bitmap = NULL;

  ck_assert_ptr_ne(bitmap = bitmap_new(2), NULL);
  ck_assert_int_eq(bitmap_is_bit_set(bitmap, 0), false);
  ck_assert_int_eq(bitmap_is_bit_set(bitmap, 1), false);
  bitmap_set_bit(bitmap, 0);
  ck_assert_int_eq(bitmap_is_bit_set(bitmap, 0), true);
  ck_assert_int_eq(bitmap_is_bit_set(bitmap, 1), false);
  bitmap_unset_bit(bitmap, 0);
  ck_assert_int_eq(bitmap_is_bit_set(bitmap, 0), false);
  ck_assert_int_eq(bitmap_is_bit_set(bitmap, 1), false);

  bitmap_destroy(bitmap);
}
END_TEST

START_TEST(test_bitmap_set_all_then_clear)
{
  bitmap_t *bitmap = NULL;

  ck_assert_ptr_ne(bitmap = bitmap_new(9), NULL);
  ck_assert_int_eq(bitmap_is_bit_set(bitmap, 0), false);
  ck_assert_int_eq(bitmap_is_bit_set(bitmap, 1), false);
  ck_assert_int_eq(bitmap_is_bit_set(bitmap, 2), false);
  ck_assert_int_eq(bitmap_is_bit_set(bitmap, 3), false);
  ck_assert_int_eq(bitmap_is_bit_set(bitmap, 4), false);
  ck_assert_int_eq(bitmap_is_bit_set(bitmap, 5), false);
  ck_assert_int_eq(bitmap_is_bit_set(bitmap, 6), false);
  ck_assert_int_eq(bitmap_is_bit_set(bitmap, 7), false);
  ck_assert_int_eq(bitmap_is_bit_set(bitmap, 8), false);
  bitmap_set_all(bitmap);
  ck_assert_int_eq(bitmap_is_bit_set(bitmap, 0), true);
  ck_assert_int_eq(bitmap_is_bit_set(bitmap, 1), true);
  ck_assert_int_eq(bitmap_is_bit_set(bitmap, 2), true);
  ck_assert_int_eq(bitmap_is_bit_set(bitmap, 3), true);
  ck_assert_int_eq(bitmap_is_bit_set(bitmap, 4), true);
  ck_assert_int_eq(bitmap_is_bit_set(bitmap, 5), true);
  ck_assert_int_eq(bitmap_is_bit_set(bitmap, 6), true);
  ck_assert_int_eq(bitmap_is_bit_set(bitmap, 7), true);
  ck_assert_int_eq(bitmap_is_bit_set(bitmap, 8), true);
  bitmap_clear(bitmap);
  ck_assert_int_eq(bitmap_is_bit_set(bitmap, 0), false);
  ck_assert_int_eq(bitmap_is_bit_set(bitmap, 1), false);
  ck_assert_int_eq(bitmap_is_bit_set(bitmap, 2), false);
  ck_assert_int_eq(bitmap_is_bit_set(bitmap, 3), false);
  ck_assert_int_eq(bitmap_is_bit_set(bitmap, 4), false);
  ck_assert_int_eq(bitmap_is_bit_set(bitmap, 5), false);
  ck_assert_int_eq(bitmap_is_bit_set(bitmap, 6), false);
  ck_assert_int_eq(bitmap_is_bit_set(bitmap, 7), false);
  ck_assert_int_eq(bitmap_is_bit_set(bitmap, 8), false);

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
  suite_add_tcase(s, tc_core);

  return s;
}
