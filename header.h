#ifndef HEADER_H
#define HEADER_H

#define MAX_STUDENTS 10
#define MAX_SUBJECTS 3

typedef struct
{
  char name[50];
  int isa1[MAX_SUBJECTS];
  int isa2[MAX_SUBJECTS];
  int esa[MAX_SUBJECTS];
  int internal[MAX_SUBJECTS];
  int credits[MAX_SUBJECTS];
  float sgpa;
} Student;

int get_num_students(void);
void load_student_data(Student students[], int *num_students);
void save_student_data(Student students[], int num_students);
void calculate_sgpa(Student students[], int num_students);
void display_grade_card(Student students[], int num_students);
void update_student_details(Student students[], int num_students);

#endif
