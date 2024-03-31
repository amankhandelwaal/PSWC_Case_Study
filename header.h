#ifndef HEADER_H
#define HEADER_H

#define MAX_STUDENTS 10
#define MAX_SUBJECTS 5

int get_num_students(void);
void get_student_details(char names[][100], int isa1[][MAX_SUBJECTS], int isa2[][MAX_SUBJECTS], int esa[][MAX_SUBJECTS], int internal[][MAX_SUBJECTS], int credits[][MAX_SUBJECTS]);
float calculate_sgpa(int isa1[][MAX_SUBJECTS], int isa2[][MAX_SUBJECTS], int esa[][MAX_SUBJECTS], int internal[][MAX_SUBJECTS], int credits[][MAX_SUBJECTS], int num_students);
void display_grade_card(char name[], int isa1[][MAX_SUBJECTS], int isa2[][MAX_SUBJECTS], int esa[][MAX_SUBJECTS], int internal[][MAX_SUBJECTS], int credits[][MAX_SUBJECTS], int num_students);

#endif
