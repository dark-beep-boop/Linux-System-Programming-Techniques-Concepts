#ifndef EMP_H
#define EMP_H

#include "gldll.h"
#include <stdbool.h>

#define EMP_STR_MAXSIZE 30

struct emp
{
  char name[EMP_STR_MAXSIZE];
  unsigned int salary;
  char designation[EMP_STR_MAXSIZE];
  unsigned int emp_id;
  gldll_node_t glnode;
};
typedef struct emp emp_t;

bool emp_init(emp_t *self);
void emp_finalize(emp_t *self);
emp_t *emp_new(void);
void emp_destroy(emp_t *self);
void emp_set_name(emp_t *self, const char *name);
void emp_set_salary(emp_t *self, unsigned int salary);
void emp_set_designation(emp_t *self, const char *designation);
void emp_set_id(emp_t *self, unsigned int id);
const char *emp_get_name(const emp_t *self);
unsigned int emp_get_salary(const emp_t *self);
const char *emp_get_designation(const emp_t *self);
unsigned int emp_get_id(const emp_t *self);
void emp_print(emp_t *self);
void emp_print_contents(gldll_node_t *node);

#endif /* EMP_H */
