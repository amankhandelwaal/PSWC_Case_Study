#include <stdio.h>
#include <string.h>
#include <math.h>
#include "header.h"

int get_num_students(void)
{
  int num_students;
  printf("Enter the number of students (maximum %d): ", MAX_STUDENTS);
  scanf("%d", &num_students);

  if (num_students <= 0 || num_students > MAX_STUDENTS)
  {
    printf("Invalid number of students.\n");
    return -1;
  }

  return num_students;
}

void enter_student_details(Student students[], int num_students)
{
  for (int i = 0; i < num_students; i++)
  {
    printf("\nEnter details for student %d:\n", i + 1);

    printf("Name: ");
    getchar();
    fgets(students[i].name, sizeof(students[i].name), stdin);
    students[i].name[strcspn(students[i].name, "\n")] = '\0';

    for (int j = 0; j < MAX_SUBJECTS; j++)
    {
      printf("Enter marks for Subject %d (ISA1, ISA2, ESA, Internal, Credits): ", j + 1);
      scanf("%d %d %d %d %d",
            &students[i].isa1[j], &students[i].isa2[j], &students[i].esa[j],
            &students[i].internal[j], &students[i].credits[j]);
    }
  }
}

void calculate_sgpa(Student students[], int num_students)
{
  for (int i = 0; i < num_students; i++)
  {
    float total_grade_points = 0.0f;
    float total_credits = 0.0f;

    for (int j = 0; j < MAX_SUBJECTS; j++)
    {
      // Calculate total marks for the subject
      int total_marks = students[i].isa1[j] + students[i].isa2[j] + (students[i].esa[j] / 2) + students[i].internal[j];

      // Determine grade points based on total marks
      int grade_points = 0;
      if (total_marks >= 90 && total_marks <= 100)
        grade_points = 10; // S grade
      else if (total_marks >= 80 && total_marks <= 89)
        grade_points = 9; // A grade
      else if (total_marks >= 70 && total_marks <= 79)
        grade_points = 8; // B grade
      else if (total_marks >= 60 && total_marks <= 69)
        grade_points = 7; // C grade
      else if (total_marks >= 50 && total_marks <= 59)
        grade_points = 6; // D grade
      else if (total_marks >= 40 && total_marks <= 49)
        grade_points = 5; // E grade
      else
        grade_points = 4; // F grade

      float subject_score = grade_points * students[i].credits[j];
      total_grade_points += subject_score;
      total_credits += students[i].credits[j];
    }

    // Calculate SGPA for a student
    if (total_credits > 0.0f)
      students[i].sgpa = total_grade_points / total_credits;
    else
      students[i].sgpa = -1.0f;

    // Round off SGPA
    students[i].sgpa = roundf(students[i].sgpa * 100) / 100;
  }
}

void display_grade_card(Student students[], int num_students)
{
  printf("\nGrade Card:\n");
  printf("Name\t\tSubject 1\t\tSubject 2\t\tSubject 3\tSGPA\n");
  printf("--------------------------------------------------------------------------------------\n");

  for (int i = 0; i < num_students; i++)
  {
    printf("%s\t", students[i].name);
    for (int j = 0; j < MAX_SUBJECTS; j++)
    {
      printf("%d\t%d\t%d\t",
             students[i].isa1[j], students[i].isa2[j], students[i].esa[j]);
    }
    printf("%.2f\n", students[i].sgpa);
  }
}
