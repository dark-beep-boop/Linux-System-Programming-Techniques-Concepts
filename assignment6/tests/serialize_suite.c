#include "serialize.h"
#include <check.h>
#include <stdbool.h>
#include <string.h>

START_TEST(test_serialize_new)
{
  serializer_buffer_t *buffer = NULL;

  ck_assert_ptr_ne(buffer = serializer_buffer_new(), NULL);
  ck_assert_int_eq(0, buffer->next);

  serializer_buffer_destroy(buffer);
}
END_TEST

START_TEST(test_serialize_new_with_size)
{
  serializer_buffer_t *buffer = NULL;

  ck_assert_ptr_ne(buffer = serializer_buffer_new_with_size(16), NULL);
  ck_assert_int_eq(16, buffer->size);
  ck_assert_int_eq(0, buffer->next);

  serializer_buffer_destroy(buffer);
}
END_TEST

START_TEST(test_empty_buffer)
{
  serializer_buffer_t *buffer = NULL;

  ck_assert_ptr_ne(buffer = serializer_buffer_new(), NULL);
  ck_assert(serializer_buffer_is_empty(buffer));

  serializer_buffer_destroy(buffer);
}
END_TEST

START_TEST(test_non_empty_buffer)
{
  serializer_buffer_t *buffer = NULL;

  ck_assert_ptr_ne(buffer = serializer_buffer_new(), NULL);
  serializer_buffer_serialize_string(buffer, "hello", 5);
  ck_assert(!serializer_buffer_is_empty(buffer));

  serializer_buffer_destroy(buffer);
}
END_TEST

START_TEST(test_serialize_string)
{
  serializer_buffer_t *buffer = NULL;

  ck_assert_ptr_ne(buffer = serializer_buffer_new(), NULL);
  ck_assert(serializer_buffer_serialize_string(buffer, "hell", 5));
  ck_assert_str_eq("hell", buffer->buffer);
  ck_assert_int_eq(5, buffer->next);
  ck_assert_int_lt(5, buffer->size);

  serializer_buffer_destroy(buffer);
}
END_TEST

START_TEST(test_serialize_string_bigger_than_the_buffer)
{
  serializer_buffer_t *buffer = NULL;

  ck_assert_ptr_ne(buffer = serializer_buffer_new_with_size(16), NULL);
  ck_assert(
    serializer_buffer_serialize_string(buffer, "hello, this is hell", 20));
  ck_assert_str_eq("hello, this is hell", buffer->buffer);
  ck_assert_int_eq(20, buffer->next);
  ck_assert_int_lt(20, buffer->size);

  serializer_buffer_destroy(buffer);
}
END_TEST

START_TEST(test_serialize_2_strings)
{
  serializer_buffer_t *buffer = NULL;

  ck_assert_ptr_ne(buffer = serializer_buffer_new_with_size(1), NULL);
  ck_assert(serializer_buffer_serialize_string(buffer, "hello", 5));
  ck_assert_str_eq("hello", buffer->buffer);
  ck_assert_int_eq(5, buffer->next);
  ck_assert_int_lt(5, buffer->size);
  ck_assert(serializer_buffer_serialize_string(buffer, ", this is hell", 15));
  ck_assert_str_eq("hello, this is hell", buffer->buffer);
  ck_assert_int_eq(20, buffer->next);
  ck_assert_int_lt(20, buffer->size);

  serializer_buffer_destroy(buffer);
}
END_TEST

START_TEST(test_deserialize_string)
{
  serializer_buffer_t *buffer = NULL;
  char dest[5] = {};

  ck_assert_ptr_ne(buffer = serializer_buffer_new_with_size(5), NULL);
  memcpy(buffer->buffer, "hell", 5);
  ck_assert_int_eq(0, buffer->next);
  ck_assert(serializer_buffer_deserialize_string(buffer, dest, 5));
  ck_assert_int_eq(5, buffer->next);
  ck_assert_str_eq("hell", dest);

  serializer_buffer_destroy(buffer);
}
END_TEST

START_TEST(test_deserialize_2_strings)
{
  serializer_buffer_t *buffer = NULL;
  char first[6] = {};
  char second[15] = {};

  ck_assert_ptr_ne(buffer = serializer_buffer_new_with_size(20), NULL);
  memcpy(buffer->buffer, "hello, this is hell", 20);
  ck_assert_int_eq(0, buffer->next);
  ck_assert(serializer_buffer_deserialize_string(buffer, first, 5));
  ck_assert_int_eq(5, buffer->next);
  ck_assert_str_eq("hello", first);
  ck_assert(serializer_buffer_deserialize_string(buffer, second, 15));
  ck_assert_int_eq(20, buffer->next);
  ck_assert_str_eq(", this is hell", second);

  serializer_buffer_destroy(buffer);
}
END_TEST

START_TEST(test_deserialize_more_than_available)
{
  serializer_buffer_t *buffer = NULL;
  char dest[5] = {};

  ck_assert_ptr_ne(buffer = serializer_buffer_new_with_size(5), NULL);
  memcpy(buffer->buffer, "hell", 5);
  ck_assert_int_eq(0, buffer->next);
  ck_assert(!serializer_buffer_deserialize_string(buffer, dest, 20));
  ck_assert_int_eq(0, buffer->next);
  ck_assert_str_eq("", dest);

  serializer_buffer_destroy(buffer);
}
END_TEST

START_TEST(test_copy_in_zero)
{
  serializer_buffer_t *buffer = NULL;

  ck_assert_ptr_ne(buffer = serializer_buffer_new_with_size(5), NULL);
  ck_assert(serializer_buffer_copy_by_offset(buffer, 0, "hell", 5));
  ck_assert_int_eq(0, buffer->next);
  ck_assert_int_eq(5, buffer->size);
  ck_assert_str_eq("hell", buffer->buffer);

  serializer_buffer_destroy(buffer);
}
END_TEST

START_TEST(test_copy_in_one)
{
  serializer_buffer_t *buffer = NULL;

  ck_assert_ptr_ne(buffer = serializer_buffer_new_with_size(6), NULL);
  ck_assert(serializer_buffer_copy_by_offset(buffer, 1, "hell", 5));
  ck_assert_int_eq(0, buffer->next);
  ck_assert_int_eq(6, buffer->size);
  ck_assert_str_eq("", buffer->buffer);
  ck_assert_str_eq("hell", buffer->buffer + 1);

  serializer_buffer_destroy(buffer);
}
END_TEST

START_TEST(test_copy_beyond_buffer_size)
{
  serializer_buffer_t *buffer = NULL;

  ck_assert_ptr_ne(buffer = serializer_buffer_new_with_size(5), NULL);
  ck_assert(!serializer_buffer_copy_by_offset(buffer, 1, "hell", 5));
  ck_assert_int_eq(0, buffer->next);
  ck_assert_int_eq(5, buffer->size);
  ck_assert_str_eq("", buffer->buffer);
  ck_assert_str_eq("", buffer->buffer + 1);

  serializer_buffer_destroy(buffer);
}
END_TEST

START_TEST(test_serialize_mark_checkpoint_then_serialize)
{
  serializer_buffer_t *buffer = NULL;

  ck_assert_ptr_ne(buffer = serializer_buffer_new(), NULL);
  ck_assert(serializer_buffer_serialize_string(buffer, "hell", 4));
  ck_assert_int_eq(4, buffer->next);
  ck_assert_int_lt(4, buffer->size);
  ck_assert_str_eq("hell", buffer->buffer);
  serializer_buffer_mark_checkpoint(buffer);
  ck_assert_int_eq(4, buffer->checkpoint);
  ck_assert_int_eq(4, serializer_buffer_get_checkpoint(buffer));
  ck_assert(serializer_buffer_serialize_string(buffer, "o, this is hell", 16));
  ck_assert_int_eq(20, buffer->next);
  ck_assert_int_lt(20, buffer->size);
  ck_assert_str_eq("hello, this is hell", buffer->buffer);
  ck_assert_int_eq(4, buffer->checkpoint);
  ck_assert_int_eq(4, serializer_buffer_get_checkpoint(buffer));

  serializer_buffer_destroy(buffer);
}
END_TEST

START_TEST(test_skip_backwards_then_forwards_then_deserialize)
{
  serializer_buffer_t *buffer = NULL;
  char dest[8] = {};

  ck_assert_ptr_ne(buffer = serializer_buffer_new(), NULL);
  ck_assert(
    serializer_buffer_serialize_string(buffer, "hello, this is hell", 20));
  ck_assert_int_eq(20, buffer->next);
  ck_assert_int_lt(20, buffer->size);
  ck_assert_str_eq("hello, this is hell", buffer->buffer);
  ck_assert(serializer_buffer_skip(buffer, -10));
  ck_assert_int_eq(10, buffer->next);
  ck_assert_int_lt(20, buffer->size);
  ck_assert_str_eq("hello, this is hell", buffer->buffer);
  ck_assert(serializer_buffer_skip(buffer, 2));
  ck_assert_int_eq(12, buffer->next);
  ck_assert_int_lt(20, buffer->size);
  ck_assert_str_eq("hello, this is hell", buffer->buffer);
  ck_assert(serializer_buffer_deserialize_string(buffer, dest, 8));
  ck_assert_int_eq(20, buffer->next);
  ck_assert_int_lt(20, buffer->size);
  ck_assert_str_eq("hello, this is hell", buffer->buffer);
  ck_assert_str_eq("is hell", dest);

  serializer_buffer_destroy(buffer);
}
END_TEST

START_TEST(test_skip_backwards_on_empty_buffer)
{
  serializer_buffer_t *buffer = NULL;

  ck_assert_ptr_ne(buffer = serializer_buffer_new(), NULL);
  ck_assert(!serializer_buffer_skip(buffer, -10));
  ck_assert_int_eq(0, buffer->next);
  ck_assert_str_eq("", buffer->buffer);

  serializer_buffer_destroy(buffer);
}
END_TEST

START_TEST(test_skip_forwards_beyond_buffer_size)
{
  serializer_buffer_t *buffer = NULL;

  ck_assert_ptr_ne(buffer = serializer_buffer_new_with_size(5), NULL);
  ck_assert(!serializer_buffer_skip(buffer, 10));
  ck_assert_int_eq(0, buffer->next);
  ck_assert_str_eq("", buffer->buffer);

  serializer_buffer_destroy(buffer);
}
END_TEST

START_TEST(test_skip_forwards_just_until_buffer_size)
{
  serializer_buffer_t *buffer = NULL;

  ck_assert_ptr_ne(buffer = serializer_buffer_new_with_size(5), NULL);
  ck_assert(serializer_buffer_skip(buffer, 5));
  ck_assert_int_eq(5, buffer->next);
  ck_assert_str_eq("", buffer->buffer);

  serializer_buffer_destroy(buffer);
}
END_TEST

START_TEST(test_skip_backwards_just_until_buffer_begin_then_deserialize)
{
  serializer_buffer_t *buffer = NULL;
  char dest[20] = {};

  ck_assert_ptr_ne(buffer = serializer_buffer_new(), NULL);
  ck_assert(
    serializer_buffer_serialize_string(buffer, "hello, this is hell", 20));
  ck_assert_int_eq(20, buffer->next);
  ck_assert_int_lt(20, buffer->size);
  ck_assert_str_eq("hello, this is hell", buffer->buffer);
  ck_assert(serializer_buffer_skip(buffer, -20));
  ck_assert_int_eq(0, buffer->next);
  ck_assert_int_lt(20, buffer->size);
  ck_assert_str_eq("hello, this is hell", buffer->buffer);
  ck_assert(serializer_buffer_deserialize_string(buffer, dest, 20));
  ck_assert_int_eq(20, buffer->next);
  ck_assert_int_lt(20, buffer->size);
  ck_assert_str_eq("hello, this is hell", buffer->buffer);
  ck_assert_str_eq("hello, this is hell", dest);

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
  tcase_add_test(tc_core, test_empty_buffer);
  tcase_add_test(tc_core, test_non_empty_buffer);
  tcase_add_test(tc_core, test_serialize_string);
  tcase_add_test(tc_core, test_serialize_string_bigger_than_the_buffer);
  tcase_add_test(tc_core, test_serialize_2_strings);
  tcase_add_test(tc_core, test_deserialize_string);
  tcase_add_test(tc_core, test_deserialize_2_strings);
  tcase_add_test(tc_core, test_deserialize_more_than_available);
  tcase_add_test(tc_core, test_copy_in_zero);
  tcase_add_test(tc_core, test_copy_in_one);
  tcase_add_test(tc_core, test_copy_beyond_buffer_size);
  tcase_add_test(tc_core, test_serialize_mark_checkpoint_then_serialize);
  tcase_add_test(tc_core, test_skip_backwards_then_forwards_then_deserialize);
  tcase_add_test(tc_core, test_skip_backwards_on_empty_buffer);
  tcase_add_test(tc_core, test_skip_forwards_beyond_buffer_size);
  tcase_add_test(
    tc_core,
    test_skip_backwards_just_until_buffer_begin_then_deserialize);
  tcase_add_test(tc_core, test_skip_forwards_just_until_buffer_size);
  suite_add_tcase(s, tc_core);

  return s;
}
