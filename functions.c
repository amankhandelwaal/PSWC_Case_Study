#include <stdio.h>
#include <string.h>
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

void load_student_data(Student students[], int *num_students)
{
  FILE *file = fopen("students.csv", "r");
  if (!file)
  {
    printf("Error opening file.\n");
    return;
  }

  char line[256];
  int i = 0;
  fgets(line, sizeof(line), file); // Skip header line

  while (fgets(line, sizeof(line), file) && i < MAX_STUDENTS)
  {
    sscanf(line, "%[^,],%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",
           students[i].name,
           &students[i].isa1[0], &students[i].isa2[0], &students[i].esa[0], &students[i].internal[0], &students[i].credits[0],
           &students[i].isa1[1], &students[i].isa2[1], &students[i].esa[1], &students[i].internal[1], &students[i].credits[1],
           &students[i].isa1[2], &students[i].isa2[2], &students[i].esa[2], &students[i].internal[2], &students[i].credits[2]);
    i++;
  }

  *num_students = i;
  fclose(file);
}

void save_student_data(Student students[], int num_students)
{
  FILE *file = fopen("students.csv", "w");
  if (!file)
  {
    printf("Error opening file.\n");
    return;
  }

  fprintf(file, "Name,ISA1_1,ISA2_1,ESA_1,Internal_1,Credits_1,ISA1_2,ISA2_2,ESA_2,Internal_2,Credits_2,ISA1_3,ISA2_3,ESA_3,Internal_3,Credits_3\n");

  for (int i = 0; i < num_students; i++)
  {
    fprintf(file, "%s,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",
            students[i].name,
            students[i].isa1[0], students[i].isa2[0], students[i].esa[0], students[i].internal[0], students[i].credits[0],
            students[i].isa1[1], students[i].isa2[1], students[i].esa[1], students[i].internal[1], students[i].credits[1],
            students[i].isa1[2], students[i].isa2[2], students[i].esa[2], students[i].internal[2], students[i].credits[2]);
  }

  fclose(file);
}

void calculate_sgpa(Student students[], int num_students)
{
  for (int i = 0; i < num_students; i++)
  {
    float total_grade_points = 0.0f;
    float total_credits = 0.0f;

    for (int j = 0; j < MAX_SUBJECTS; j++)
    {
      int total_marks = (students[i].isa1[j] / 2) + (students[i].isa2[j] / 2) + (students[i].esa[j] / 2) + students[i].internal[j];
      int grade_points = 0;

      if (total_marks >= 90)
        grade_points = 10;
      else if (total_marks >= 80)
        grade_points = 9;
      else if (total_marks >= 70)
        grade_points = 8;
      else if (total_marks >= 60)
        grade_points = 7;
      else if (total_marks >= 50)
        grade_points = 6;
      else if (total_marks >= 40)
        grade_points = 5;
      else
        grade_points = 0;

      // output for debugging
      printf("Student: %s, Subject: %d, ISA1: %d, ISA2: %d, ESA: %d, Internal: %d, Credits: %d\n",
             students[i].name, j + 1, students[i].isa1[j], students[i].isa2[j], students[i].esa[j], students[i].internal[j], students[i].credits[j]);
      printf("Total Marks: %d, Grade Points: %d\n", total_marks, grade_points);

      total_grade_points += grade_points * students[i].credits[j];
      total_credits += students[i].credits[j];
    }

    if (total_credits > 0.0f)
    {
      students[i].sgpa = total_grade_points / total_credits;
    }
    else
    {
      students[i].sgpa = 0.0f;
    }

    printf("Student: %s, SGPA: %.2f\n", students[i].name, students[i].sgpa);
  }
}

void display_grade_card(Student students[], int num_students)
{
  printf("\nGrade Card:\n");
  printf("Name                 Subject 1                Subject 2                Subject 3           SGPA\n");
  printf("---------------------------------------------------------------------------------------------------\n");
  printf("                 ISA1 ISA2 ESA Int Cr     ISA1 ISA2 ESA Int Cr     ISA1 ISA2 ESA Int Cr\n");
  for (int i = 0; i < num_students; i++)
  {
    printf("%-15s", students[i].name);
    for (int j = 0; j < MAX_SUBJECTS; j++)
    {
      printf("%4d %4d %4d %3d %2d    ", students[i].isa1[j], students[i].isa2[j], students[i].esa[j], students[i].internal[j], students[i].credits[j]);
    }
    printf("%5.2f\n", students[i].sgpa);
  }
}

void update_student_details(Student students[], int num_students)
{
  if (num_students == 0)
  {
    printf("No student data available. Please enter student details first.\n");
    return;
  }

  int student_index, subject_index, exam_index;

  printf("Select the student to update (1-%d): ", num_students);
  scanf("%d", &student_index);
  student_index--; // Adjust index to array index

  if (student_index < 0 || student_index >= num_students)
  {
    printf("Invalid student index.\n");
    return;
  }

  printf("Selected Student: %s\n", students[student_index].name);

  printf("Select the subject to update (1-%d): ", MAX_SUBJECTS);
  scanf("%d", &subject_index);
  subject_index--; // Adjust index to array index

  if (subject_index < 0 || subject_index >= MAX_SUBJECTS)
  {
    printf("Invalid subject index.\n");
    return;
  }

  printf("Selected Subject %d\n", subject_index + 1);

  printf("Select the exam to update:\n");
  printf("1. ISA1\n");
  printf("2. ISA2\n");
  printf("3. ESA\n");
  printf("4. Internal\n");
  printf("Enter your choice: ");
  scanf("%d", &exam_index);
  exam_index--; // Adjust index to array index

  if (exam_index < 0 || exam_index >= 4)
  {
    printf("Invalid exam index.\n");
    return;
  }

  printf("Old marks: %d\n", exam_index == 0   ? students[student_index].isa1[subject_index]
                            : exam_index == 1 ? students[student_index].isa2[subject_index]
                            : exam_index == 2 ? students[student_index].esa[subject_index]
                                              : students[student_index].internal[subject_index]);

  printf("Enter the new marks: ");
  int new_marks;
  scanf("%d", &new_marks);

  if (exam_index == 0)
  {
    students[student_index].isa1[subject_index] = new_marks;
  }
  else if (exam_index == 1)
  {
    students[student_index].isa2[subject_index] = new_marks;
  }
  else if (exam_index == 2)
  {
    students[student_index].esa[subject_index] = new_marks;
  }
  else
  {
    students[student_index].internal[subject_index] = new_marks;
  }

  printf("Marks updated successfully.\n");
}
