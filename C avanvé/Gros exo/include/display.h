/**
 * @file display.h
 * @brief Display functions for grades, courses, students, and the promotion.
 */

#ifndef DISPLAY_H
#define DISPLAY_H

#include "class.h"

/**
 * @brief Displays all grades stored in a Grades structure.
 * @param grades Pointer to the Grades structure to display.
 */
void display_grades(const Grades *grades);

/**
 * @brief Displays a course's name, coefficient, average, and list of grades.
 * @param course Pointer to the Course structure to display.
 */
void display_course(const Course *course);

/**
 * @brief Displays a student's personal info, general average, and all courses.
 * @param student Pointer to the Student structure to display.
 */
void display_student(const Student *student);

/**
 * @brief Displays all students in the promotion.
 * @param promo Pointer to the Class structure to display.
 */
void display_class(const Class *promo);

#endif