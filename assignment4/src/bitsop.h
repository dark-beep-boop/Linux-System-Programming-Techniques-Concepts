#include <stdbool.h>
#include <stdint.h>

#define MASK(bit) (1 << bit)
#define SET_BIT(n, bit) (n |= MASK(bit))
#define UNSET_BIT(n, bit) (n &= ~MASK(bit))
#define IS_BIT_SET(n, bit) ((n)&MASK(bit))
#define GET_BIT(n, bit) (((n)&MASK(bit)) >> bit)
#define TOGGLE_BIT(n, bit) (n ^= MASK(bit))
#define COMPLEMENT(n) (~(n))

void print_bit_pattern(uint32_t n);
uint8_t count_bit_set(uint32_t n);
uint32_t rotate_right(uint32_t n, uint8_t k);
uint32_t rotate_left(uint32_t n, uint8_t k);
void print_address_bit_pattern(const char *addr);
uint32_t mask_bits(uint32_t n, uint8_t p, uint8_t q);
bool is_power_of_two(uint32_t n);
uint32_t reverse_bits(uint32_t n);
