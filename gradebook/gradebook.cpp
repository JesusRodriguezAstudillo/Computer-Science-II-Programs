#include "header.h"

int main()
{
	// declared struct objects
	students student_arr;
	courses course_arr;
	Enrollment enroll_arr;	

	// initialized counters to zero
	student_arr.stu_counter = 0;
	course_arr.course_counter = 0;
	enroll_arr.enroll_counter = 0;
	enroll_arr.grade_counter = 0;
	enroll_arr.most_grades = 0;

	// initilize and size trackers
	course_arr.course_size = student_arr.student_size = enroll_arr.enroll_size = enroll_arr.grade_size = SIZE;

	// allocate memory for the initial arrays
	student_arr.student_list = new student[SIZE];
	course_arr.course_list = new course[SIZE];
	enroll_arr.enroll_list = new Enroll[SIZE];

	// allocate memrory for the array of grades
	for(int i = 0; i < SIZE; i++)
	{
		enroll_arr.enroll_list[i].grade = new int[SIZE];
	}

	int response;

	// initilalized all the arrays used
	initialize_array(enroll_arr, student_arr, course_arr);

	header();

	// menu prompt
	do
	{
		cout << "\n\t1) Enter course information. \n";
		cout << "\t2) Enter student information. \n";
		cout << "\t3) Enroll a student to a course. \n";
		cout << "\t4) Enter grades for a student. \n";
		cout << "\t5) Print the grades for a specific student. \n";
		cout << "\t6) Print a list of all students in a specific course. \n";
		cout << "\t7) Calculate the grade average for a student in a course. \n";
		cout << "\t8) Print course information. \n";
		cout << "\t9) Print a list of all students. \n";
		cout << "\t10) Calculate the average grade for a course.\n";
		cout << "\t11) Write all information to a file. \n";
		cout << "\t12) Load information from a file. \n"; //function not finished
		cout << "\t0) Exit grade book program. \n";
		cout << "Select a number from the menu or enter 0 to exit: ";
		cin  >> response;

		// only allow valid responses from the menu
		switch(response)
		{
			case 1:
				Course_info(course_arr);
				break;
			case 2:
				student_info(student_arr);
				break;
			case 3:
				enroll(enroll_arr, course_arr, student_arr);	
				break;
			case 4:
				add_grades(enroll_arr);
				break;
			case 5:
				display_grades(enroll_arr);
				break;
			case 6:
				course_enrollment(enroll_arr);	
				break;
			case 7:
				grade_average(enroll_arr);	
				break;
			case 8:
				Print_Course_info(course_arr);
				break;
			case 9:
				print_student_info(student_arr);
				break;
			case 10:
				course_grade_average(enroll_arr);
				break;
			case 11:
				save_file(enroll_arr, course_arr, student_arr);
				break;
			case 12:
				load_file(enroll_arr, course_arr, student_arr);
				break;
			case 0:
				break;
			default:
					cout << "The value that you entered is not valid.\n";
			}
	}while(response != 0);// End of do while loop if the response is 0

	// delete the arrays and return the memory to the heap
	delete []course_arr.course_list;
	delete []student_arr.student_list;
	for(int d = 0; d < enroll_arr.enroll_counter; d++)
	{
		delete[] enroll_arr.enroll_list[d].grade;
	}
	delete []enroll_arr.enroll_list;

	return 0;
}
