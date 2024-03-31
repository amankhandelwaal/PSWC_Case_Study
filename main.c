#include <stdio.h>
#include <string.h>
#include "header.h"



int main()
{
  int choice;
  int num_students = 0;
  char student_names[MAX_STUDENTS][100];
  int isa1[MAX_STUDENTS][MAX_SUBJECTS], isa2[MAX_STUDENTS][MAX_SUBJECTS];
  int esa[MAX_STUDENTS][MAX_SUBJECTS], internal[MAX_STUDENTS][MAX_SUBJECTS];
  int credits[MAX_STUDENTS][MAX_SUBJECTS];

  do
  {
    printf("\nOptions:\n");
    printf("1. Enter student details\n");
    printf("2. Calculate SGPA\n");
    printf("3. Display grade card\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      get_student_details(student_names, isa1, isa2, esa, internal, credits);
      break;
    case 2:
      if (num_students > 0)
      {
        float sgpa = calculate_sgpa(isa1, isa2, esa, internal, credits, num_students);
        if (sgpa == -1.0f)
        {
          printf("Error: No credits entered.\n");
        }
        else
        {
          printf("SGPA: %.2f\n", sgpa);
        }
      }
      else
      {
        printf("Error: No student details entered.\n");
      }
      break;
    case 3:
      if (num_students > 0)
      {
        for (int i = 0; i < num_students; i++)
        {
          display_grade_card(student_names[i], isa1, isa2, esa, internal, credits, num_students);
        }
      }
      else
      {
        printf("Error: No student details entered.\n");
      }
      break;
    case 4:
      printf("Exiting program.\n");
      break;
    default:
      printf("Invalid choice. Please enter a number between 1 and 4.\n");
    }
  } while (choice != 4);


  return 0;
}
