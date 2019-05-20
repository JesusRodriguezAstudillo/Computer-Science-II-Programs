#include "header.h"

/*
=================================================================================
Function:	Header 
Parameters:	none
Return:		nothing
Description:	This function is simply used to called it in the main body and 
		display the header
==================================================================================
*/

void header()
{
	cout << "\t+-----------------------------------------------+ \n";
	cout << "\t|	Computer Science and Engineering	| \n";
	cout << "\t|	CSCE 1040 - Computer Science II		| \n";
	cout << "\t|	Homework 2  				| \n";
	cout << "\t| 	Jesus Rodriguez		 jr0463		| \n";
	cout << "\t|	jr0463@unt.edu				| \n";
	cout << "\t+-----------------------------------------------+ \n";
	cout << endl;

	return;
}

/*
=================================================================================
Function:	student_info 
Parameters:	the students struct passed by reference
Return:		
Description:	This function is used to prompt the user to enter the id numbers 
		and the names of students which are then recorded in the student
		struct array
==================================================================================
*/
void student_info(students &s_arr)
{
	int student_count;
	int student_id;
	char answer;

	// prompt for how many students to add
	do
	{
		cout << "\tPlease enter the student's id number: ";
		cin  >> student_id;
		// Check that the id has already been recorded
		if(student_search(s_arr, student_id))
		{
			cout << "That student has already been registered.\n";
		}
		// Avoid invalid values
		else if(student_id < 0)
		{
			cout << "The ID value that you entered is not valid.\n";
		}
		else
		{
			// else save information to the array
			s_arr.student_list[s_arr.stu_counter].id_number = student_id;
			cout << "\tPlease enter the student's name: ";
			cin >> s_arr.student_list[s_arr.stu_counter].name;
			s_arr.stu_counter++;
		}
		cout << "Would you like to enter more student information? Y/N: ";
		cin  >> answer;

		// call function to allocate memory if the student counter is larger than than the size
		student_allocation(s_arr);

	}while((answer != 'n') && (answer != 'N'));

	return;
}

/* 
=================================================================================
Function:	Print_student_info
Parameters:	the struct students variable
Return:		
Description:	This function is simply used to called it in the main body and 
		display the header
==================================================================================
*/
void print_student_info(students &s_arr)
{
	// for loop to display all of the array contents
	for(int i = 0; i < s_arr.stu_counter; i++)
	{
		cout << "\tStudent ID Number: " << s_arr.student_list[i].id_number;
		cout << "\tStudent Name: " << s_arr.student_list[i].name << endl;
	}

	return;
}

/* 
=================================================================================
Function:	Course_info
Parameters:	The courses struct variable
Return:		
Description:	This function is used to prompt the user for the id of a course 
		and the name of a course. The id and the name are then recorded
		in an index location of the array
==================================================================================
*/
void Course_info(courses &c_arr)
{
	char response;
	int course_id;

	do
	{	// prompt for the course id
		cout << "\tPlease enter the course's ID number: ";
		cin  >> course_id;
		
		// check if the id is already enrolled 
		if(course_search(c_arr, course_id))
		{
			cout << "That course has already been registered.\n";
		}
		else if(course_id < 0)
		{
			cout << "The ID value that you entered is not valid. \n";
		}
		else
		{
			// Save the id and the name to the course array
			c_arr.course_list[c_arr.course_counter].course_number = course_id;
			cout << "\tPlease enter the course's name ";
			cin  >>	c_arr.course_list[c_arr.course_counter].name;
			c_arr.course_counter++;
		}
		cout << "Would you like to enter another course? Y/N: ";
		cin  >> response;
		
		// call function to allocate more memory if necessary
		course_allocation(c_arr);

	}while((response != 'n') && (response != 'N'));

	return;
}

/* 
=================================================================================
Function:	Print_Course_info
Parameters:	The courses struct
Return:		
Description:	This function is used to display all of the course id numbers and
		their names
==================================================================================
*/
void Print_Course_info(courses &c_arr)
{
	// for loop to display course information
	for(int i = 0; i < c_arr.course_counter; i++)
	{
		c_arr.course_list[i].course_number;
		// the if statement only displays the names and ids of courses entered by the user
		if(c_arr.course_list[i].course_number > -1)
		{
			cout << "\tCourse ID Number: " << c_arr.course_list[i].course_number;
			cout << "\tCourse Name: " << c_arr.course_list[i].name << endl;
		}
	}
	return;
}

/*
=================================================================================
Function:	enroll
Parameters:	The enrollment struct, the courses struct, and the students struct
		variables all passed by reference
Return:		
Description:	This function is used to enroll a specific id number with a specific 
		course id number together to a single index location on the enroll
		array
==================================================================================
*/
void enroll(Enrollment &e_arr, courses &c_arr, students &s_arr)
{
	// Variables that hold values from user input
	char answer;
	int course_id, student_id;
	
	bool enroll_check;

	do
	{
		// reset variables
		enroll_check = false;

		// prompt the user
		cout << "\tEnter the students ID number: ";
		cin  >> student_id;
		cout << "\tEnter the course ID number: ";
		cin  >> course_id;

		//check for the validity of id numbers by calling a bool function
		if(!student_search(s_arr, student_id) || !course_search(c_arr, course_id))
		{
			cout << "One or both of the IDs hat you tried to enroll is not registered. \n";
			cout << "Return to the main menu to enter or check information. \n";
		}
		else
		{
			// for loop to check all of the values of the enrollment array
			for(int i = 0; i < e_arr.enroll_counter; i++)
			{
				// check if the course and student are already enrolled together
				if((e_arr.enroll_list[i].student_id == student_id) && (e_arr.enroll_list[i].course_id == course_id))
				{
					enroll_check = true;
				}
			}
			if(enroll_check == true)
			{
				cout << "You cannot enroll the student in the same class.\n";
			}
			else
			{
				e_arr.enroll_list[e_arr.enroll_counter].student_id = student_id;
				e_arr.enroll_list[e_arr.enroll_counter].course_id = course_id;
				e_arr.enroll_counter++;
			}
		}
		cout << "Would you like to enroll another student? Y/N: ";
		cin  >> answer;

		// call function to allocate more memory to the enrollment array if necessary
		enrollment_allocation(e_arr);

	}while((answer != 'n') && (answer != 'N'));

	return;
}

/* 
=================================================================================
Function:	student_search
Parameters:	the students struct variable and an int representing an id 
Return:		a bool representing whether the student was not found
Description:	This function is used to check that a specific student id has 
		already been registered before being enrolled
==================================================================================
*/
bool student_search(students s_arr, int id) 
{
	// for loop checks for the id that the user entered
	for(int i = 0; i < s_arr.stu_counter; i++)
	{
		s_arr.student_list[i].id_number;
		if(s_arr.student_list[i].id_number == id)
		{
			// if the id is found the function returns true
			return true;
		}
	}
	return false;
}

/* 
=================================================================================
Function:	course_search
Parameters:	The courses struct variable and an int representin an id
Return:		a bool representing the validity of the id 
Description:	This function is used to check for the validity of the course id
		entered by the user before it is enrolled
==================================================================================
*/
bool course_search(courses c_arr, int id)
{
	// for loop checks all indec locations for the ide
	for(int i = 0; i < c_arr.course_counter; i++)
	{
		c_arr.course_list[i].course_number;
		if(c_arr.course_list[i].course_number == id)
		{
			// if the id is found the function returns true
			return true;
		}
	}
	return false;
}

/* 
=================================================================================
Function:	id_search
Parameters:	The enrollment struct variable, an int representing a student id, an int
		representing a course id, and a char that determines whether to 
		check for single id or both ids.
Return:		a bool that represents the validity of the id
Description:	This function is used to check that the course id exists in the 
		enrollment array
==================================================================================
*/

bool id_search(Enrollment e_arr, int stu_id, int c_id, char check)
{	
	if(check == 'a')
	{
		// the for loop checks all of the index locations
		for(int c = 0; c < e_arr.enroll_counter; c++)
		{
			e_arr.enroll_list[c].course_id;
			if(e_arr.enroll_list[c].course_id == c_id)
			{
				// if the id is found the function returns true
				return true;
			}
		}
	}
	else if(check == 'b')
	{
		for(int d = 0; d < e_arr.enroll_counter; d++)
		{
			e_arr.enroll_list[d].course_id;
			e_arr.enroll_list[d].student_id;
			if((e_arr.enroll_list[d].course_id == c_id) && (e_arr.enroll_list[d].student_id == stu_id))
			{
				return true;
			}
		}
	}

	return false;
}
/* 
=================================================================================
Function:	get_index
Parameters:	The enrollment struct variable, an int representing a student id, and an 
		int represeting a course id
Return:		an int represeting the index location of both ids
Description:	This function searches the enroll array using ids passed as parameters
		in order to determine and return the index location of the ids.
==================================================================================
*/
int get_index(Enrollment e_arr, int stu_id, int c_id)
{
	for(int i = 0; i < e_arr.enroll_counter; i++)
	{
		// check that the parameters are together in the enroll array
		if((e_arr.enroll_list[i].course_id == c_id) && (e_arr.enroll_list[i].student_id == stu_id))
		{
			return i;
		}
	}
}
	
/* 
=================================================================================
Function:	grade_count
Parameters:	the enrollment struct variable and an int representing the index
		of the student and the course
Return:		an int representing the amount of grades that the student has 
		in a particular course
Description:	This fucntion is used to figure out the total amout of grades
		for a specific student in a specific course
==================================================================================
*/
int grade_count(Enrollment e_arr, int index)
{
	int grade_amount = 0;

	// the for loop checks the grade array within the struct for all values between -1 and 101 exclusively
	for(int i = 0; i < e_arr.grade_size; i++)
	{
		if((e_arr.enroll_list[index].grade[i] < 101) && (e_arr.enroll_list[index].grade[i] > -1))
		{
			// the grade amount increases for every valid grade
			grade_amount++;
		}
	}

	return grade_amount;
}

/* 
=================================================================================
Function:	course_enrollment
Parameters:	the enrollment struct variable
Return:		
Description:	This function is used to prompt the user for the id of a course
		and then display all of the ids that are enrolled in that course
==================================================================================
*/
void course_enrollment(Enrollment &e_arr)
{
	int course_id;
	int num = 0;
	char check = 'a';
	
	// prompt for id
	cout << "\tEnter the course ID to display the students enrolled in that course: ";
	cin  >> course_id;

	// check to see that the id exists
	if(!id_search(e_arr, num, course_id, check))
	{
		cout << "The course ID that you entered has no students enrolled or does not exist. \n";
	}
	// check all index locations for the id number
	else
	{
		for(int i = 0; i < e_arr.enroll_counter; i++)
		{
			e_arr.enroll_list[i].course_id;
			if(e_arr.enroll_list[i].course_id == course_id)
			{
				// print the id of the students when found
				cout << "\tStudent ID: " << e_arr.enroll_list[i].student_id << endl;
			}
		}
	}

	return;
}

/* 
=================================================================================
Function:	add_grades
Parameters:	The enrollment struct variable
Return:		
Description:	This function is used to prompt the user for the number of grades 
		to add to a student in a specific course
==================================================================================
*/
void add_grades(Enrollment &e_arr)
{
	// declare vairables
	int student_id, course_id, index_value;
	int grade;
	int grade_counter = 0;
	bool roll_check;
	char answer;
	
	do
	{	// reset values
		roll_check = false;
		e_arr.grade_counter = 0;

		// prompt the user
		cout << "\tEnter the ID number of the student to add grades: ";
		cin  >> student_id;
		cout << "\tEnter the course ID number that the student is enrolled in: ";
		cin  >> course_id;

		// check that the course and student id are together in the same array index
		if(!id_search(e_arr, student_id, course_id, 'b'))
		{
			cout << "The student ID: " << student_id << " is not enrolled in course: "<< course_id <<".\n";
			cout << "Return to the main menu to enroll the student in the course.\n";
		}
		else
		{
			index_value = get_index(e_arr, student_id, course_id);

			do
			{
				// prompt for grade value
				cout << "\tEnter a grade value between 0 and 100 ";
				cout << "or enter -1 to exit: ";
				cin  >> grade;
		
				// call function to check for amount of grades
				grade_counter = grade_count(e_arr, index_value);

				// assign the grade counter to the struct grade counter
				e_arr.grade_counter = grade_counter;
			
				// if the counter is larger than the largest amount of grades, reassign the value
				if(e_arr.grade_counter > e_arr.most_grades)
				{
					e_arr.most_grades = e_arr.grade_counter;
				}

				// call function to expand the size of the grade array
				grade_allocation(e_arr);			

				// allow only valid input
				if((grade < -1) || (grade > 100))
				{
					cout << "The grade that you entered is not valid.\n";
				}
				else
				{
					// save grade
					e_arr.enroll_list[index_value].grade[grade_counter] = grade;
				}
			}while(grade != -1);
		}

		cout << "Would you like to enter more grades? Y/N ";
		cin  >> answer;
		
	}while((answer != 'n') && (answer != 'N'));
	
	return;
}
  
/*
=================================================================================
Function:	initialize_array
Parameters:	the enrollment struct, the students struct, and the courses struct 
		variables
Return:		
Description:	This function initilizes all int array values to -1 and all 
		string values to " ".
==================================================================================
*/
void initialize_array(Enrollment &e_arr, students &s_arr, courses &c_arr)
{
	// for loops initialize all index locations
	for(int i = 0; i < e_arr.enroll_size; i++)
	{
		e_arr.enroll_list[i].student_id = -1;
		e_arr.enroll_list[i].course_id = -1;
		for(int j = 0; j < e_arr.grade_size; j++)
		{
			e_arr.enroll_list[i].grade[j] = -1;
		}
	}

	for(int j = 0; j < s_arr.student_size; j++)
	{
		s_arr.student_list[j].name = " ";
		s_arr.student_list[j].id_number = -1;
	}

	for(int k = 0; k < c_arr.course_size; k++)
	{
		c_arr.course_list[k].name = " ";
		c_arr.course_list[k].course_number = -1;
	}

	return;
}

/*
=================================================================================
Function:	display_grades
Parameters:	The enrollment struct variable
Return:		
Description:	This function prompts the user for an a course and student id 
		in order to display the grades for those specific values
==================================================================================
*/
void display_grades(Enrollment e_arr)
{
	// declare variables
	int student_id, course_id, index_value;
	bool roll_check = false;
	int grade_counter = 0;
	
	// prompt for ids
	cout << "Enter the student's ID number and the course ID to display their grades.\n";
	cout << "\tStudent ID: ";
	cin  >> student_id;
	cout << "\tCourse ID: ";
	cin  >> course_id;

	// check that the student is enrolled in the course
	if(!id_search(e_arr, student_id, course_id, 'b'))
	{
		cout << "The student ID: " << student_id << " is not enrolled in course: "<< course_id <<".\n";
		cout << "Return to the main menu to enroll the student in the course.\n\n";
	}
	else
	{
		// gather the index value
		index_value = get_index(e_arr, student_id, course_id);
	
		// print grades for values other than those that were initialized
		grade_counter = grade_count(e_arr, index_value);
		if(grade_counter == 0)
		{
			// output message if the student has no recorded grades
			cout << "The student has no recorded grades.\n";
		}	
		else
		{
			cout << "\nGrades for student: " << student_id << " in course: ";
			cout << course_id << endl;

			for(int j = 0; j < grade_counter; j++)
			{
				cout << '\t' << j+1 << ")" << e_arr.enroll_list[index_value].grade[j] << endl;
			}
		}
	}
	return;
}

/*
=================================================================================
Function:	grade_average
Parameters:	the enrollment struct variable
Return:		
Description:	This function is used to calculate the average grade of a student
		in a specific course.
==================================================================================
*/
void grade_average(Enrollment e_arr)
{
	// declare variables
	int student_id, course_id, index_value;
	int grade_counter = 0;
	double avg = 0;
	
	// prompt for ids
	cout << "\tEnter the student's ID number and the course ID to display their grades.\n";
	cout << "\tStudent ID: ";
	cin  >> student_id;
	cout << "\tCourse ID: ";
	cin  >> course_id;

	// check that the student is enrolled in the courses
	if(!id_search(e_arr, student_id, course_id, 'b'))
	{
		cout << "The student ID: " << student_id << " is not enrolled in course: "<< course_id <<".\n";
		cout << "Return to the main menu to enroll the student in the course.\n\n";
	}
	else
	{
		// gather the index value
		index_value = get_index(e_arr, student_id, course_id);

		//calculate average by calling another function
		avg = grade_avg(e_arr, index_value);

		// display message if the student has no grades to calculate an average
		if(avg == -1)
		{
			cout << "The student has no grades to calculate an average.\n";
		}
		else
		{
			// output the average
			cout << "\tThe student's, " << student_id << ", average in the class, " << course_id;
			cout << " is: " << avg << endl;
		}
	}
	return;
}

/*
=================================================================================
Function:	grade_avg
Parameters:	the enrollment struct variable and an int representing the index
		of the student and the course
Return:		a double representing the grade avg
Description:	This function calculates the average grade for a student in a course
		by checking the the array of grades within the given index
==================================================================================
*/
double grade_avg(Enrollment e_arr, int index_value)
{
	// declare variables
	int grade_counter = 0;
	double grade_sum = 0;
	
	// call grade count function to determine how many grades to divide by
	grade_counter = grade_count(e_arr, index_value);

	// Check if the students has no recorded grades to avoid division by zero
	if(grade_counter == 0)
	{
		return -1;
	}
	else
	{
		for(int j = 0; j < grade_counter; j++)
		{
			// add all of the grades other than the inintialized values
			grade_sum = grade_sum + e_arr.enroll_list[index_value].grade[j];
		}
		// return results
		return (grade_sum / grade_counter);
	}
}

/*
=================================================================================
Function:	course_grade_avg
Parameters:	the enrollment struct variable
Return:		
Description:	This function calculates the average grade for a course by calling
		the grade_avg function for all instances of a course id
==================================================================================
*/
void course_grade_average(Enrollment e_arr)
{
	// declare variables
	int course_id, index_value;
	index_value = 0;
	bool roll_check = false;
	int counter = 0;
	double grade_sum = 0;
	double stu_avg = 0;
	
	cout << "Enter the couse ID number to calculate the class average.\n";
	cout << "\tCourse ID: ";
	cin  >> course_id;

	for(int i = 0; i < e_arr.enroll_counter; i++)
	{
		e_arr.enroll_list[i].course_id;
		if(e_arr.enroll_list[i].course_id == course_id)
		{
			// check validity of id and gather index location
			index_value = i;
			
			// call grade_avg function for all instances of the course id
			if(grade_avg(e_arr, index_value) == -1)
			{
				//ignore all instance of students who don't have grades recorded
			}
			else
			{
				// add the averages for each student with grades in the course
				grade_sum = grade_sum + grade_avg(e_arr, index_value);	
				// counter keeps track of enrolled students to divide the sum by
				counter++;
			}	
			roll_check = true;
		}
	}
	if(roll_check == false)
	{
		// display message if the id was not found
		cout << "The ID number that you entered was not found.\n";
	}
	else if((counter == 0) && (grade_sum == 0))
	{
		// output a message if the enrolled students don't have grades
		cout << "Cannot calculate an average because none of the students in the course have";
		cout << " grades recorded. " << endl;
	}
	else
	{
		// output the results
		cout << "The average grade for the course is " << (grade_sum/counter) << endl;
		cout << "Students without recorded grades were ignored.\n";
	}
	return;
}

/*
=================================================================================
Function:	save_file
Parameters:	the enrollment struct, the courses struct, and the students struct
		variables.
Return:		
Description:	This function prompts the user for names of a file and the writes
		the information from the arrays to the file name chosen by the user
==================================================================================
*/
void save_file(Enrollment e_arr, courses c_arr, students s_arr)
{
	// declare ofstream variable
	ofstream out_stream;
	char file_name[256];
	
	// propmt
	cout << "\tEnter the name a file name to save all of the course information: ";
	cin  >> file_name;
	
	// open file
	out_stream.open(file_name);

	// check if it opened correctly
	if(out_stream.fail())
	{
		cout << "Failed to open file.\n";
		exit(EXIT_FAILURE);
	}

	// write a tag for the file
	out_stream << "Courses" << endl;

	// write the size and the counter in order to read them back into the program
	out_stream << c_arr.course_size << '\t' << c_arr.course_counter << endl;

	// write information
	for(int i = 0; i < c_arr.course_counter; i++)
	{
		out_stream << c_arr.course_list[i].course_number << '\t' << c_arr.course_list[i].name;
		out_stream << endl;
	}

	cout << "\tAll course information has been written to: " << file_name << endl;

	// close file
	out_stream.close();

	// reprompt
	cout << "\tEnter the name a file name to save all of the student information: ";
	cin  >> file_name;
	
	// open file
	out_stream.open(file_name);

	// check if it opened correctly
	if(out_stream.fail())
	{
		cout << "Failed to open file.\n";
		exit(EXIT_FAILURE);
	}

	// write a tag to the file
	out_stream << "Students" << endl;

	// write the size and counter for students
	out_stream << s_arr.student_size << '\t' << s_arr.stu_counter << endl;

	// write information
	for(int j = 0; j < s_arr.stu_counter; j++)
	{
		out_stream << s_arr.student_list[j].id_number << '\t' << s_arr.student_list[j].name;
		out_stream << endl;
	}

	cout << "\tAll student information has been written to: " << file_name << endl;

	// close file
	out_stream.close();

	// reprompt
	cout << "\tEnter the name a file name to save all of the enrollment information: ";
	cin  >> file_name;
	
	// open file
	out_stream.open(file_name);

	// check if it opened correctly
	if(out_stream.fail())
	{
		cout << "Failed to open file.\n";
		exit(EXIT_FAILURE);
	}
	
	// write a tag to the file
	out_stream << "Enrollment" << endl;	

	// output the sizes and counters of the 2d array
	out_stream << e_arr.enroll_size << '\t' << e_arr.enroll_counter << endl;
	out_stream << e_arr.grade_size << '\t' << e_arr.most_grades << endl;

	// write information
	for(int k = 0; k < e_arr.enroll_counter; k++)
	{
		out_stream << e_arr.enroll_list[k].course_id << '\t' << e_arr.enroll_list[k].student_id << '\t';

		for(int m = 0; m < grade_count(e_arr, k); m++)
		{
			out_stream << "  " << e_arr.enroll_list[k].grade[m];
		}	
		out_stream << endl;
	}

	cout << "\tAll grades and enrollment information has been written to: " << file_name << endl;

	// close file
	out_stream.close();

	return;
}

/*
=================================================================================
Function:	load_file
Parameters:	The enrollment struct, the courses struct, and the students struct
		variables.
Return:		
Description:	This function writes information from files back into the arrays of 
		the program
==================================================================================
*/
void load_file(Enrollment &e_arr, courses &c_arr, students &s_arr)
{
	// declare variables
	ifstream in_stream;
	char file_name[256];
	char ch;
	int size, counter, id, index;
	string name;

	// prompt for name
	cout << "\tEnter the name of the course file that you wish to load.\n";
	cout << "\tName: ";
	cin  >> file_name;

	// open the file and check if it opened
	in_stream.open(file_name);
	if(in_stream.fail())
	{
		cout << "Failed to open the file.\n";
		exit(EXIT_FAILURE);
	}

	// check the tag of the file
	in_stream >> name;
	if(name != "Courses")
	{
		// output a message for the wrong type of file
		cout << "The file that you tried to load does not contain course information.\n";
	}
	else
	{
		// if the file is of the right type write all information to the arrays
		// read in the size and the counter
		in_stream >> size;
		in_stream >> counter;	

		// write the values into the courses struct
		c_arr.course_size = size;
		c_arr.course_counter = counter;

		// allocate memory depending on the size and initialize the values
		c_arr.course_list = new course[size];
		for(int i = 0; i < size; i++)
		{
			c_arr.course_list[i].course_number = -1;
			c_arr.course_list[i].name = " ";
		}
	
		for(index = 0; index < c_arr.course_counter; index++)
		{
			// read the information from the file
			in_stream >> id;
			in_stream >> name;
	
			// write the information to the arrays
			c_arr.course_list[index].course_number = id;
			c_arr.course_list[index].name = name;
		}
	}

	// close the file
	in_stream.close();

	// reprompt for the name
	cout << "\tEnter the name of the student file that you wish to loadi.\n";
	cout << "\tName: ";
	cin  >> file_name;

	// open the file and check if it opened
	in_stream.open(file_name);
	if(in_stream.fail())
	{
		cout << "Failed to open the file.\n";
		exit(EXIT_FAILURE);
	}
	
	// check the tag of the file
	in_stream >> name;
	if(name != "Students")
	{
		// output a message for attempting to read the wrong type of file
		cout << "The file that you tried to load does not contain student information.\n";
	}
	else
	{
		// write all information from the file to the arrays
		// read in the size and the counter
		in_stream >> size;
		in_stream >> counter;
	
		// write the size and the counter the students struct
		s_arr.student_size = size;
		s_arr.stu_counter = counter;
	
		// allocate memory to the student array and initialize all values
		s_arr.student_list = new student[size];
		for(int i = 0; i < size; i++)
		{
			s_arr.student_list[i].id_number = -1;
			s_arr.student_list[i].name = " ";
		}
	
	
		for(index = 0; index < s_arr.stu_counter; index++)
		{
			// read information from file
			in_stream >> id;
			in_stream >> name;
	
			// write information to the student array
			s_arr.student_list[index].id_number = id;
			s_arr.student_list[index].name = name;
		}	
	}

	// close the file
	in_stream.close();


	// reprompt
	cout << "\tEnter the name of the enrollment file that you wish to load.\n";
	cout << "\tName: ";
	cin  >> file_name;

	// Check if the file opened correctly
	in_stream.open(file_name);
	if(in_stream.fail())
	{
		cout << "Failed to open the file.\n";
		exit(EXIT_FAILURE);
	}

	// check the tag of the file
	in_stream >> name;
	if(name != "Enrollment")
	{
		cout << "The file that you tried to load does not contain enrollment information.\n";
	}
	else
	{
		// write all information from the file to the array
		// read in the size and counter for the enrollment array
		in_stream >> size >> counter;
	
		// initialize the enrollment struct variables
		e_arr.enroll_size = size;
		e_arr.enroll_counter = counter;

		// read in the size and the counter representing the student with the most grades
		in_stream >> size >> counter;

		// initialize the grade struct variables
		e_arr.grade_size = size;
		e_arr.grade_counter = counter;

		// allocate memory for the enrollment and grade arrays
		e_arr.enroll_list = new Enroll[e_arr.enroll_size];
		for(int i = 0; i < e_arr.enroll_size; i++)
		{
			e_arr.enroll_list[i].grade = new int[e_arr.grade_size];
		}
	
		// initialize the variables of the new arrays
		for(int j = 0; j < e_arr.enroll_size; j++)
		{
			e_arr.enroll_list[j].course_id = -1;
			e_arr.enroll_list[j].student_id = -1;
			for(int k = 0; k < e_arr.grade_size; k++)
			{
				e_arr.enroll_list[j].grade[k] = -1;
			}
		}

		// read an endline to ignore
		in_stream.get(ch);
	
		// read the first number after the endline
		in_stream.get(ch);

		// declare new variables to read in 2d array
		int position = 0;
		int grade_index = 0;
		index = 0;

		while(!in_stream.eof())
		{
			// check if the character is a digit
			if(isdigit(ch))
			{
				// return the character and read it as an int
				in_stream.putback(ch);
				int element;
				in_stream >> element;
				
				// save the int as the course id
				if(position == 0)
				{
					e_arr.enroll_list[index].course_id = element;
					position++;
				}
				// save the int as a student id
				else if(position == 1)
				{
					e_arr.enroll_list[index].student_id = element;
					position++;
				}
				// save the rest of the numbers as grades
				else if(position > 1)
				{
					e_arr.enroll_list[index].grade[grade_index] = element;
					grade_index++;
				}
				
			}
			// move to read the next ids and grades
			else if(ch == '\n')
			{
				index++;
				position = grade_index = 0;
			}
	
			in_stream.get(ch);
		}
	
	}
	// close the file
	in_stream.close();

	return;
}
/* 
=================================================================================
Function:	course_allocation
Parameters:	the courses struct 
Return:		
Description:	This function allocates more memory to the courses struct by
		declaring a temporary array that copies all elements of the original
		struct. The original struct is deleted before using the new function
		to allocate more memory. All elements are copied back to the struct
		before deleting the temporary struct.
==================================================================================
*/
void course_allocation(courses &c_arr)
{
	if(c_arr.course_counter >= c_arr.course_size)
	{
		// Declare a temporary struct and allocate memory to it
		courses temp;
		temp.course_list = new course[c_arr.course_size];

		// copy the information in the index
		for(int i = 0; i < c_arr.course_counter; i++)
		{
			temp.course_list[i] = c_arr.course_list[i];
		}

		// delete the array
		delete []c_arr.course_list;

		// Allocate more memory to the new course struct
		c_arr.course_list = new course[SIZE + c_arr.course_size];

		// Copy the information back into the array
		for(int j = 0; j < c_arr.course_counter; j++)
		{
			c_arr.course_list[j] = temp.course_list[j];
		}
		
		// Delete the temporaty array
		delete []temp.course_list;

		// Initialize the values of all new index locations
		for(int c = c_arr.course_counter; c < (c_arr.course_size + SIZE); c++)
		{
			c_arr.course_list[c].course_number = -1;
			c_arr.course_list[c].name = " ";
		}

		// increase the size of the course size
		c_arr.course_size = c_arr.course_size + SIZE;
	}

	return;
}
/* 
=================================================================================
Function:	student_allocation
Parameters:	a students struct
Return:		
Description:	This function is used to allocate more memory to the student dynamic
		array. A temporary struct is first declared to copy all elements
		before declaring a new struct array of students with more elements
		available.
==================================================================================
*/
void student_allocation(students &s_arr)
{
	if(s_arr.stu_counter >= s_arr.student_size)
	{
		// declare a temporary struct and allocate memory to the temporary struct
		students temp;
		temp.student_list = new student[s_arr.student_size];
	
		// copy all index values to the temporary struct
		for(int i = 0; i < s_arr.stu_counter; i++)
		{
			temp.student_list[i] = s_arr.student_list[i];
		}
	
		// delete original struct
		delete []s_arr.student_list;
	
		// allocate more memory to the new struct array
		s_arr.student_list = new student[SIZE + s_arr.student_size];
	
		// copy all values back into the array
		for(int j = 0; j < s_arr.stu_counter; j++)
		{
			s_arr.student_list[j] = temp.student_list[j];
		}
		
		// initialize the values of the new index locations
		for(int c = s_arr.stu_counter ;c < (SIZE + s_arr.student_size); c++)
		{
			s_arr.student_list[c].id_number = -1;
			s_arr.student_list[c].name = " ";
		}

		// delete the temporary struct
		delete []temp.student_list;

		// increase the size of the student size
		s_arr.student_size = s_arr.student_size + SIZE;
	}

	return;
}
/* 
=================================================================================
Function:	enrollment_allocation
Parameters:	an Enrollment struct
Return:		
Description:	This function allocates more memory to the enrollment dynamic
		array. The function declares a temporary struct to copy all elments
		then erases the old array before allocating more memory to a new
		array and copying all elemets back. The temporary struct is then 
		deleted
==================================================================================
*/
void enrollment_allocation(Enrollment &e_arr)
{
	if(e_arr.enroll_counter >= e_arr.enroll_size)
	{
		// declare a temporary array to hold all of the old information
		Enrollment temp;
		temp.enroll_list = new Enroll[e_arr.enroll_size];
	
		// copy all of the information to the temporary array
		for(int i = 0; i < e_arr.enroll_counter; i++)
		{
			temp.enroll_list[i] = e_arr.enroll_list[i];
		}
		
		// Delete the grades and the enrollment information
		delete []e_arr.enroll_list;
	
		// Redeclare the array with more allocated memory
		e_arr.enroll_list = new Enroll[SIZE + e_arr.enroll_size];
		for(int i = 0; i < (SIZE + e_arr.enroll_size); i++)
		{
			// allocate memory to the new index locations for the grades array
			e_arr.enroll_list[i].grade = new int[SIZE + e_arr.grade_size];
		}
	
		// copy all of the information from the temporary array
		for(int j = 0; j < e_arr.enroll_counter; j++)
		{
			e_arr.enroll_list[j] = temp.enroll_list[j];
		}

		// Delete the temp enrollment information
		delete []temp.enroll_list;

		// initialize the values of the new index locations
		for(int a = e_arr.enroll_counter; a < (SIZE + e_arr.enroll_size); a++)
		{
			e_arr.enroll_list[a].course_id = -1;
			e_arr.enroll_list[a].student_id = -1;
			for(int b = 0; b < (SIZE + e_arr.grade_size); b++)
			{
				e_arr.enroll_list[a].grade[b] = -1;
			}
		}
		
		// increase the size of the enrollment size
		e_arr.enroll_size = (e_arr.enroll_size + SIZE);
	}

	return;
}
/* 
=================================================================================
Function:	grade_allocation
Parameters:	an Enrollment struct
Return:		
Description:	This function serves to allocate more memory to the grade array 
		that is inside the Enrollment struct
==================================================================================
*/
void grade_allocation(Enrollment &e_arr)
{
	if(e_arr.grade_counter >= e_arr.grade_size)
	{
		// declare and allocate memory for a temporary struct
		Enrollment temp;
		temp.enroll_list = new Enroll[SIZE + e_arr.enroll_size];
		for(int i = 0; i < e_arr.enroll_counter; i++)
		{
			temp.enroll_list[i].grade = new int[e_arr.grade_size];
		}
		
		// copy all the grades from the array to them temporary one
		for(int j = 0; j < e_arr.enroll_counter; j++)
		{
			for(int k = 0; k < e_arr.grade_size; k++)
			{
				temp.enroll_list[j].grade[k] = e_arr.enroll_list[j].grade[k];
			}
		}
	
		// erase only the enroll grades
		for(int d = 0; d < e_arr.enroll_counter; d++)
		{
			delete [] e_arr.enroll_list[d].grade;
		}

		// allocate more memory for grades
		for(int i = 0; i < e_arr.enroll_counter; i++)
		{
			e_arr.enroll_list[i].grade = new int[SIZE + e_arr.grade_size];
		}
		
		// copy the values back into the newly allocated array
		for(int j = 0; j < e_arr.enroll_counter; j++)
		{
			for(int k = 0; k < e_arr.grade_size; k ++)
			{
				e_arr.enroll_list[j].grade[k] = temp.enroll_list[j].grade[k];
			}
		}

		// need to delete all position that were declared not just the ones that were accounted for
		// delete the temp array
		for(int d = 0; d < e_arr.enroll_counter; d++)
		{
			delete [] temp.enroll_list[d].grade;
		}
		delete []temp.enroll_list;

		// initialize the new indices of array grades
		for(int l = 0; l < e_arr.enroll_counter; l++)
		{
			for(int m = e_arr.grade_size; m < (SIZE + e_arr.grade_size); m++)
			{
				e_arr.enroll_list[l].grade[m] = -1;
			}
		}

		// increase the size of the grade size member
		e_arr.grade_size = (e_arr.grade_size + SIZE);
	}

	return;
}
