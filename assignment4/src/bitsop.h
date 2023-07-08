#include <stdbool.h>
#include <stdint.h>

#define MASK(bit) (1 << bit)

/* Exercise 2 */
#define SET_BIT(n, bit) (n |= MASK(bit))
/* Exercise 3 */
#define UNSET_BIT(n, bit) (n &= ~MASK(bit))
/* Exercise 4 */
#define IS_BIT_SET(n, bit) (((n)&MASK(bit)) != 0)
/* Extra exercise */
#define GET_BIT(n, bit) (((n)&MASK(bit)) >> bit)
/* Exercise 5 */
#define TOGGLE_BIT(n, bit) (n ^= MASK(bit))
/* Exercise 6 */
#define COMPLEMENT(n) (~(n))

/* Exercise 1 */
void print_bit_pattern(uint32_t n);
/* Exercise 7 */
uint8_t count_bit_set(uint32_t n);
/* Exercise 8 */
uint32_t rotate_right(uint32_t n, uint8_t k);
/* Extra exercise */
uint32_t rotate_left(uint32_t n, uint8_t k);
/* Exercise 9 */
void print_address_bit_pattern(const char *addr);
/* Exercise 10 */
uint32_t mask_bits(uint32_t n, uint8_t p, uint8_t q);
/* Exercise 11 */
bool is_power_of_two(uint32_t n);
/* Extra exercise */
uint32_t reverse_bits(uint32_t n);
