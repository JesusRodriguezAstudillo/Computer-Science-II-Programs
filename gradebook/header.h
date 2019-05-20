/*
=================================================================================
name:		Grade_Book.cpp
Author:		Jesus Rodriguez
Version:
Copyright:
Description:	This program is used as a grade book. The user can create courses
		and students and they can enroll students to specific courses.
		After enrolling students to specific courses, the user can begin 
		to add grades for the students. A function allows the user to 
		calculate the average for a specific student in a course or to
		calculate the average for an entire course.  
=================================================================================
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cctype>
using namespace std;

// Global constants to declare the size of arrays
const int SIZE = 10;

// declare structs for students, courses, and enrollment 
struct student
{
	int id_number;
	string name;
};

struct course
{
	int course_number;
	string name;
};

struct Enroll
{
	int course_id;
	int student_id;
	int *grade;
};

struct students
{
	student *student_list;
	int stu_counter;
	int student_size;
};

struct courses
{
	course *course_list;
	int course_counter;
	int course_size;
};

struct Enrollment
{
	Enroll *enroll_list;
	int multi;
	int enroll_size;
	int enroll_counter;
	int grade_counter;
	int grade_size;
	int most_grades;
};

//void function to display block header
void header();

//void function to gather student information
void student_info(students &s_arr);

//void funtion to print student information
void print_student_info(students &s_arr);

//void function to gather course information
void Course_info(courses &c_arr);

//void function to print course information
void Print_Course_info(courses &c_arr);

//void function that enrolls a student to a course
void enroll(Enrollment &e_arr, courses &c_arr, students &s_arr);

//void function that prints the students enrolled in a course
void course_enrollment(Enrollment &e_arr);

//void funtion to add grades
void add_grades(Enrollment &e_arr);

//void function to display the total amount of grades in a course
void display_grades(Enrollment e_arr);

//void function that displays the grade average for a student in a course
void grade_average(Enrollment e_arr);

//void function that displays the grade average in a course
void course_grade_average(Enrollment e_arr);

//void funtio to save the contents entered
void save_file(Enrollment e_arr, courses c_arr, students s_arr);

//void function to load a file (not finished)
void load_file(Enrollment &e_arr, courses &c_arr, students &s_arr);

//void function that initializes the array 
void initialize_array(Enrollment &e_arr, students &s_arr, courses &c_arr);

// void functions that allocate more memory to their respective arrays
void course_allocation(courses &c_arr);

void student_allocation(students &s_arr);

void enrollment_allocation(Enrollment &e_arr);

void grade_allocation(Enrollment &e_arr);

//search functions to check the validity of id numbers
bool student_search(students s_arr, int id); 

bool course_search(courses c_arr, int id);

bool id_search(Enrollment e_arr, int stu_id, int c_id, char check);

int get_index(Enrollment e_arr, int stu_id, int c_id);

//int function to calculate the amount of grades entered
int grade_count(Enrollment e_arr, int index);

//double function that calculates the average grade for a student in a course
double grade_avg(Enrollment e_arr, int index_value);

