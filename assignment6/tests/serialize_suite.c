#include "serialize.h"
#include <check.h>
#include <stdbool.h>

START_TEST(test_serialize_new) {}
END_TEST

Suite *
bitmap_suite(void)
{
  Suite *s = NULL;
  TCase *tc_core = NULL;

  s = suite_create("Serialize");

  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_serialize_new);
  suite_add_tcase(s, tc_core);

  return s;
}
