#include "serialize.h"
#include <check.h>
#include <stdbool.h>

START_TEST(test_serialize_new)
{
  serializer_buffer_t *buffer = NULL;

  ck_assert_ptr_ne(buffer = serializer_buffer_new(), NULL);

  serializer_buffer_destroy(buffer);
}
END_TEST

START_TEST(test_serialize_new_with_size)
{
  serializer_buffer_t *buffer = NULL;

  ck_assert_ptr_ne(buffer = serializer_buffer_new_with_size(16), NULL);

  serializer_buffer_destroy(buffer);
}
END_TEST

Suite *
serialize_suite(void)
{
  Suite *s = NULL;
  TCase *tc_core = NULL;

  s = suite_create("Serialize");

  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_serialize_new);
  tcase_add_test(tc_core, test_serialize_new_with_size);
  suite_add_tcase(s, tc_core);

  return s;
}
