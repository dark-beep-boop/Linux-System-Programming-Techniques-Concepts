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

START_TEST(test_serialize_and_deserialize_string)
{
  serializer_buffer_t *buffer = NULL;
  char *orig = "hell";
  char dest[32] = {};

  ck_assert_ptr_ne(buffer = serializer_buffer_new(), NULL);
  serializer_buffer_serialize_string(buffer, orig, 5);
  serializer_buffer_deserialize_string(buffer, dest, 5);
  ck_assert_str_eq(orig, dest);

  serializer_buffer_destroy(buffer);
}
END_TEST

START_TEST(test_serialize_and_deserialize_string_bigger_than_the_buffer)
{
  serializer_buffer_t *buffer = NULL;
  char *orig = "hello, this is hell";
  char dest[32] = {};

  ck_assert_ptr_ne(buffer = serializer_buffer_new_with_size(16), NULL);
  serializer_buffer_serialize_string(buffer, orig, 20);
  serializer_buffer_deserialize_string(buffer, dest, 20);
  ck_assert_str_eq(orig, dest);

  serializer_buffer_destroy(buffer);
}
END_TEST

START_TEST(test_deserialize_empty_buffer)
{
  serializer_buffer_t *buffer = NULL;
  char dest[32] = {};

  ck_assert_ptr_ne(buffer = serializer_buffer_new(), NULL);
  serializer_buffer_deserialize_string(buffer, dest, 5);
  ck_assert_str_eq("", dest);

  serializer_buffer_destroy(buffer);
}
END_TEST

START_TEST(test_serialize_and_deserialize_after_end_of_buffer)
{
  serializer_buffer_t *buffer = NULL;
  char *orig = "hello, this is hell";
  char dest[32] = {};

  ck_assert_ptr_ne(buffer = serializer_buffer_new_with_size(16), NULL);
  serializer_buffer_serialize_string(buffer, orig, 20);
  serializer_buffer_deserialize_string(buffer, dest, 20);
  ck_assert_str_eq(orig, dest);
  serializer_buffer_deserialize_string(buffer, dest, 20);
  ck_assert_str_eq("", dest);

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
  tcase_add_test(tc_core, test_serialize_and_deserialize_string);
  tcase_add_test(
    tc_core,
    test_serialize_and_deserialize_string_bigger_than_the_buffer);
  tcase_add_test(tc_core, test_serialize_and_deserialize_after_end_of_buffer);
  suite_add_tcase(s, tc_core);

  return s;
}
