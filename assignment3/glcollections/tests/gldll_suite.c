#include "gldll.h"
#include <check.h>

START_TEST(test_gldll_new)
{
  gldll_t *gldll = NULL;

  ck_assert_ptr_eq(gldll = gldll_new(), NULL);
  ck_assert(gldll_is_empty(gldll));
  gldll_destroy(gldll);

  gldll = NULL;
}
END_TEST

Suite *
gldll_suite(void)
{
  Suite *s = NULL;
  TCase *tc_core = NULL;

  s = suite_create("Glued doubly linked list");

  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_gldll_new);
  suite_add_tcase(s, tc_core);

  return s;
}
