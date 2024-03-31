#include <stdio.h>
#include <string.h>
#include "header.h"

int get_num_students(void)
{
  int num_students;
  printf("Enter the number of students (maximum %d): ", MAX_STUDENTS);
  scanf("%d", &num_students);

  if (num_students > MAX_STUDENTS)
  {
    printf("Error: Maximum number of students is %d.\n", MAX_STUDENTS);
    return -1; 
  }

  return num_students;
}

void get_student_details(char names[][100], int isa1[][MAX_SUBJECTS], int isa2[][MAX_SUBJECTS], int esa[][MAX_SUBJECTS], int internal[][MAX_SUBJECTS], int credits[][MAX_SUBJECTS])
{
  for (int i = 0; i < MAX_STUDENTS; i++)
  {
    printf("\nEnter details for student %d:\n", i + 1);

    printf("Name: ");
    getchar();
    fgets(names[i], sizeof(names[i]), stdin);

    size_t len = strlen(names[i]);
    if (names[i][len - 1] == '\n')
    {
      names[i][len - 1] = '\0';
    }

    for (int j = 0; j < MAX_SUBJECTS; j++)
    {
      printf("Enter marks for Subject %d - ISA1: ", j + 1);
      scanf("%d", &isa1[i][j]);

      printf("Enter marks for Subject %d - ISA2: ", j + 1);
      scanf("%d", &isa2[i][j]);

      printf("Enter marks for Subject %d - ESA: ", j + 1);
      scanf("%d", &esa[i][j]);

      printf("Enter internal marks for Subject %d: ", j + 1);
      scanf("%d", &internal[i][j]);

      printf("Enter credits for Subject %d: ", j + 1);
      scanf("%d", &credits[i][j]);
    }

    while (getchar() != '\n')
      ;
  }
}

float calculate_sgpa(int isa1[][MAX_SUBJECTS], int isa2[][MAX_SUBJECTS], int esa[][MAX_SUBJECTS], int internal[][MAX_SUBJECTS], int credits[][MAX_SUBJECTS], int num_students)
{
  float total_credit_weighted_points = 0.0f;
  float total_credits = 0.0f;

  for (int i = 0; i < num_students; i++)
  {
    float total_points = 0.0f;
    for (int j = 0; j < MAX_SUBJECTS; j++)
    {
      int total_marks = isa1[i][j] + isa2[i][j] + esa[i][j] + internal[i][j];

      int grade_points = 0;
      if (total_marks >= 91 && total_marks <= 100)
      {
        grade_points = 10;
      }
      else if (total_marks >= 81 && total_marks <= 90)
      {
        grade_points = 9;
      }
      else if (total_marks >= 71 && total_marks <= 80)
      {
        grade_points = 8;
      }
      else if (total_marks >= 61 && total_marks <= 70)
      {
        grade_points = 7;
      }
      else if (total_marks >= 51 && total_marks <= 60)
      {
        grade_points = 6;
      }
      else if (total_marks >= 41 && total_marks <= 50)
      {
        grade_points = 5;
      }
      else
      {
        grade_points = 0;
      }
      total_points += grade_points * credits[i][j];
    }

    total_credit_weighted_points += total_points;

    for (int j = 0; j < MAX_SUBJECTS; j++)
    {
      total_credits += credits[i][j];
    }
  }

  if (total_credits == 0.0f)
  {
    return -1.0f; 
  }

  return total_credit_weighted_points / (total_credits * num_students);
}

void display_grade_card(char name[], int isa1[][MAX_SUBJECTS], int isa2[][MAX_SUBJECTS], int esa[][MAX_SUBJECTS], int internal[][MAX_SUBJECTS], int credits[][MAX_SUBJECTS], int num_students)
{
  printf("\nGrade Card for Student: %s\n", name);
  printf("Subject\tCredits\tISA1\tISA2\tESA\tInternal\tTotal\tGrade\n");
  for (int i = 0; i < num_students; i++)
  {
    printf("------------------------------------------------------------\n");
    for (int j = 0; j < MAX_SUBJECTS; j++)
    {
      int total_marks = isa1[i][j] + isa2[i][j] + esa[i][j] + internal[i][j];
      int grade_points = 0;
      if (total_marks >= 91 && total_marks <= 100)
      {
        grade_points = 10;
      }
      else if (total_marks >= 81 && total_marks <= 90)
      {
        grade_points = 9;
      }
      else if (total_marks >= 71 && total_marks <= 80)
      {
        grade_points = 8;
      }
      else if (total_marks >= 61 && total_marks <= 70)
      {
        grade_points = 7;
      }
      else if (total_marks >= 51 && total_marks <= 60)
      {
        grade_points = 6;
      }
      else if (total_marks >= 41 && total_marks <= 50)
      {
        grade_points = 5;
      }
      else
      {
        grade_points = 0;
      }
      printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", j + 1, credits[i][j], isa1[i][j], isa2[i][j], esa[i][j], internal[i][j], total_marks, grade_points);
    }
  }
}
