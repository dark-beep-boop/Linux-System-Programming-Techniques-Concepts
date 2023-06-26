#ifndef STUDENT_H
#define STUDENT_H

#include <stdbool.h>

#define NAME_MAX_LEN 32

struct student
{
  char name[NAME_MAX_LEN];
  unsigned int year_of_birth;
  unsigned int height;
  unsigned int weight;
  unsigned int total_marks;
};
typedef struct student student_t;

bool student_init(student_t *self);
void student_finalize(student_t *self);
student_t *student_new(void);
void student_destroy(student_t *self);

bool student_set_name(student_t *self, const char *name);
bool student_set_year_of_birth(student_t *self, unsigned int year_of_birth);
bool student_set_height(student_t *self, unsigned int height);
bool student_set_weight(student_t *self, unsigned int weight);
bool student_set_total_marks(student_t *self, unsigned int total_marks);

const char *student_get_name(student_t *self);
unsigned int student_get_year_of_birth(student_t *self);
unsigned int student_get_height(student_t *self);
unsigned int student_get_weight(student_t *self);
unsigned int student_get_total_marks(student_t *self);

int student_compare(student_t *self, student_t *other);

#endif /* STUDENT_H */
