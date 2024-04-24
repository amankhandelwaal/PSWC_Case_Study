#include <stdio.h>
#include "header.h"

int main()
{
  int num_students;
  Student students[MAX_STUDENTS];

  num_students = get_num_students();
  if (num_students == -1)
  {
    printf("Invalid number of students. Exiting.\n");
    return 1;
  }

  enter_student_details(students, num_students);
  calculate_sgpa(students, num_students);
  display_grade_card(students, num_students);

  return 0;
}
