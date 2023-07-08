#include "bitsop.h"
#include "defines.h"
#include <assert.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
print_bit_pattern(uint32_t n)
{
  const uint8_t word = 32;
  const uint8_t section = 4;
  uint8_t i;
  uint8_t j;

  for (i = 0; i < word; ++i) {
    for (j = 0; j < section; ++j) {
      printf("%d", GET_BIT(n, i));
    }
    printf(" ");
  }
}

uint8_t
count_bit_set(uint32_t n)
{
  const uint8_t word = 32;
  uint8_t count = 0;
  uint8_t i;

  for (i = 0; i < word; ++i) {
    count += GET_BIT(n, i);
  }

  return count;
}

uint32_t
rotate_right(uint32_t n, uint8_t k)
{
  const uint8_t word = 32;

  return n >> (k % word) | n << (word - (k % word));
}

uint32_t
rotate_left(uint32_t n, uint8_t k)
{
  const uint8_t word = 32;

  return n << (k % word) | n >> (word - (k % word));
}

void
print_address_bit_pattern(const char *addr)
{
  uint32_t int_addr;
  uint32_t mask;

  char addrcpy[19] = {};
  char *saveptr = NULL;
  char *token = NULL;
  uint8_t int_token;

  /* Make a safe copy of addr, so it terminates in null character */
  strncat(addrcpy, addr, 18);

  /* Parse address and mask */
  TRY_FAIL(token = strtok_r(addrcpy, ".", &saveptr), "failed to parse address");
  TRY_FAIL(int_token = atoi(token), "failed to parse address");
  int_addr = int_token << 24;

  TRY_FAIL(token = strtok_r(NULL, ".", &saveptr), "failed to parse address");
  TRY_FAIL(int_token = atoi(token), "failed to parse address");
  int_addr |= int_token << 16;

  TRY_FAIL(token = strtok_r(NULL, ".", &saveptr), "failed to parse address");
  TRY_FAIL(int_token = atoi(token), "failed to parse address");
  int_addr |= int_token << 8;

  TRY_FAIL(token = strtok_r(NULL, "/", &saveptr), "failed to parse address");
  TRY_FAIL(int_token = atoi(token), "failed to parse address");
  int_addr |= int_token;

  TRY_FAIL(token = strtok_r(NULL, "/", &saveptr), "failed to parse mask");
  TRY_FAIL(int_token = atoi(token), "failed to parse mask");
  int_addr |= 0xff << (32 - int_token);

  /* Apply mask */
  int_addr &= mask;

  print_bit_pattern(int_addr);

  return;

fail:
  return;
}

uint32_t
mask_bits(uint32_t n, uint8_t p, uint8_t q)
{
  assert(p >= 0);
  assert(p < q);
  assert(q < 32);

  const uint8_t word = 32;
  const uint8_t full_mask = 0xff;

  return n & (full_mask << p) & (full_mask >> (word - 1 - q));
}

bool
is_power_of_two(uint32_t n)
{
  uint8_t count = 0;
  uint8_t i;

  while (count < 2) {
    count += GET_BIT(n, i);
  }

  return count < 2;
}

uint32_t
reverse_bits(uint32_t n)
{
  const uint8_t word = 32;
  uint8_t i;
  uint32_t reversed = 0x00;

  for (i = 0; i < word; ++i) {
    reversed <<= 1;
    reversed |= GET_BIT(n, i);
  }

  return reversed;
}
