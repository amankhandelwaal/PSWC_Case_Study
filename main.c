#include <stdio.h>
#include "header.h"

int main()
{
  Student students[MAX_STUDENTS];
  int num_students = 0;

  load_student_data(students, &num_students);

  int choice;
  do
  {
    printf("\nMenu:\n");
    printf("1. Update student details\n");
    printf("2. Calculate SGPA\n");
    printf("3. Display grade card\n");
    printf("4. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      update_student_details(students, num_students);
      break;
    case 2:
      calculate_sgpa(students, num_students);
      printf("SGPA calculation completed successfully.\n");
      break;
    case 3:
      display_grade_card(students, num_students);
      break;
    case 4:
      save_student_data(students, num_students);
      printf("Data saved successfully.\n");
      break;
    default:
      printf("Invalid choice. Please try again.\n");
      break;
    }
  } while (choice != 4);

  return 0;
}
