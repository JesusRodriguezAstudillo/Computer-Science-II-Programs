#include "libraries.h"
#include "functions.h"

/*
Name:		header
Parameters:
Return:
Description:	This function is used to display the header
*/
void header()
{
	cout << "\t+-----------------------------------------------+ \n";
	cout << "\t|	Computer Science and Engineering	| \n";
	cout << "\t|	CSCE 1040 - Computer Science II		| \n";
	cout << "\t|	Homework 6  				| \n";
	cout << "\t| 	Jesus Rodriguez		 jr0463		| \n";
	cout << "\t|	jr0463@unt.edu				| \n";
	cout << "\t+-----------------------------------------------+ \n";
	cout << endl;

	return;
}
/*
Name:		SetLibraryValues
Parameters:	a Library_Values object representing the list of loan periods and fees
Return:
Description:	This function is used to set the loan periods and fee
		costs for the library items. It also displays the current values.
*/
void SetLibraryValues(Library_Values &ValueList)
{
	int choice = -1, days = 0; // the menu selection and the number of days
	double amount = 0; // an amount of money

	// display the meny with a while loop
	do
	{
		cout << "Choose a selection from the menu below.\n";
		cout << "\t(0) Return to the Main Menu.\n";
		cout << "\t(1) Display All Current Values.\n";
		cout << "\t(2) Set/Change Book Loan Period.\n";
		cout << "\t(3) Set/Change Book Fee.\n";
		cout << "\t(4) Set/Change DVD Loan Period.\n";
		cout << "\t(5) Set/Change DVD Fee.\n";
		cout << "\t(6) Set/Change Videogame Loan Period.\n";
		cout << "\t(7) Set/Change Videogame Fee.\n";
		cout << "Selection: ";
		cin  >> choice;

		// modify the ostream to display money
		cout.precision(2);

		switch(choice)
		{
			case 0:
				break;
			case 1:
				// display current values
				cout << "Current book loan period is " << ValueList.BookLoanPeriod << " days\n";
				cout << "Current book fine is $" << fixed << ValueList.BookFee << endl;
				cout << "Current DVD loan period is " << ValueList.DVDLoanPeriod << " days\n";
				cout << "Current DVD fine is $" << fixed << ValueList.DVDFee << endl;
				cout << "Current videogame loan period is " << ValueList.VideogameLoanPeriod << " days\n";
				cout << "Current videogame fine is $" << fixed <<ValueList.VideogameFee << endl;
				break;
				// prompt for new values
			case 2:
				do
				{
					cout << "Enter the amount of days that a book is allowed to be loaned.\n";
					cout << "Number of days: ";
					cin  >> ValueList.BookLoanPeriod;

					if(ValueList.BookLoanPeriod < 0)
					{
						cout << "The value is not valid.\n";
					}

				}while(ValueList.BookLoanPeriod < 0);	

				break;
			case 3:
				do
				{
					cout << "Enter the fee charged for an overdue book.\n";
					cout << "Fee per day overdue: $";
					cin  >> ValueList.BookFee;
					if(ValueList.BookFee < 0)
					{
						cout << "The value is not valid.\n";
					}

				}while(ValueList.BookFee < 0);	
			
				break;
			case 4:
				do
				{
					cout << "Enter the amount of days that a DVD is allowed to be loaned.\n";
					cout << "Number of days: ";
					cin  >> ValueList.DVDLoanPeriod;
					if(ValueList.DVDLoanPeriod < 0)
					{
						cout << "The value is not valid.\n";
					}

				}while(ValueList.DVDLoanPeriod < 0);	
			
				break;
			case 5:
				do
				{
					cout << "Enter the fee charged for an overdue DVD.\n";
					cout << "Fee per day overdue: $";
					cin  >> ValueList.DVDFee;
					if(ValueList.DVDFee < 0)
					{
						cout << "The value is not valid.\n";
					}

				}while(ValueList.DVDFee < 0);	
			
				break;
			case 6:
				do
				{
					cout << "Enter the amount of days that a videogame is allowed to be loaned.\n";
					cout << "Number of days: ";
					cin  >> ValueList.VideogameLoanPeriod;
					if(ValueList.VideogameLoanPeriod < 0)
					{
						cout << "The value is not valid.\n";
					}

				}while(ValueList.VideogameLoanPeriod < 0);	
				break;
			case 7:
				do
				{
					cout << "Enter the fee charged for an overdue videogame.\n";
					cout << "Fee per day overdue: $";
					cin  >> ValueList.VideogameFee;
					if(ValueList.VideogameFee < 0)
					{
						cout << "The value is not valid.\n";
					}

				}while(ValueList.VideogameFee < 0);	
				break;
			default:
				cout << "The value entered is not valid.\n";
		}
	}while(choice != 0);

	return;
}
/*
Name:		SaveLibraryValues
Parameters:	A Libray_Values object
Return:
Description:	This function is used to save the values from one Library_Values
		object
*/
void SaveLibraryValues(Library_Values ValueList)
{
	ofstream out; // the output stream object

	out.open("Values.txt"); // open the file

	// make sure the file opend correctly
	if(out.fail())
	{
		// display message and exit
		cout << "Failed to open the file.\n";
		exit(EXIT_FAILURE);
	}
	else
	{
		// else save the values
		out << ValueList.BookLoanPeriod << endl;
		out << ValueList.BookFee << endl;
		out << ValueList.DVDLoanPeriod << endl;
		out << ValueList.DVDFee << endl;
		out << ValueList.VideogameLoanPeriod << endl;
		out << ValueList.VideogameFee << endl;
	}

	return;
}
/*
Name:		LoadLibraryValues
Parameters:	A Libray_Values object representing the loan periods and fees
Return:
Description:	This function is used to read values from a file and save them into a Library_Values
		object
*/
void LoadLibraryValues(Library_Values &ValueList)
{
	ifstream in; // the input stream object

	in.open("Values.txt"); // opened the file
	
	// check that the file opened correctly
	if(in.fail())
	{
		// exit if fail and display message
		cout << "Failed to open the file.\n";
		exit(EXIT_FAILURE);
	}
	else
	{
		// else read the values and save them
		in >> ValueList.BookLoanPeriod;
		in >> ValueList.BookFee;
		in >> ValueList.DVDLoanPeriod;
		in >> ValueList.DVDFee;
		in >> ValueList.VideogameLoanPeriod;
		in >> ValueList.VideogameFee;
	}

	return;
}
/*
Name:		read_Game
Parameters:	the input stream and a string representing the type of item being read
Return:		a Videogames pointer representing an item passed back into the map
Description:	this function is used to read in the values for a single videogame object
		using the input stream from the load function
*/
Videogames* read_Game(ifstream& in, string type)
{
	Videogames *tempGame; // the object that will be added to the map
	tempGame = new Videogames; // allocate memory for the object

	int temp; // temp integer to gather integer values
	double tempprc; // temp double to gather price of object
	string tempstr; // temp string to gather strings

	// set the media type to the string passed in the function
	tempGame->set_Media_Type(type);

	// gather the values from the input stream
	in >> temp;
	tempGame->set_ID(temp);

	in >> temp;
	tempGame->set_Avail(temp);

	in >> temp;
	tempGame->set_Loan_Period(temp);

	in >> tempprc;
	tempGame->set_Price(tempprc);

	in.ignore();
	getline(in, tempstr);
	tempGame->set_Title(tempstr);

	in >> tempstr;
	tempGame->set_Rating(tempstr);

	in.ignore();
	getline(in, tempstr);
	tempGame->set_Platform(tempstr);

	getline(in, tempstr);
	tempGame->set_Developer(tempstr);

	return tempGame; // return the object
}

/*
Name:		read_DVD
Parameters:	the input stream object and a string representing the type of 
		library item
Return:		a DVD object pointer representing a DVD read from a save file
Description:	This function is used to read a DVD object from an input file
		and return the object
*/
DVD* read_DVD(ifstream& in, string type)
{
	DVD *tempDVD; // the temporary object
	tempDVD = new DVD; // allocate memory

	int temp; // integer values from the file
	double tempprc; // the price
	string tempstr; // string values

	// set the media type
	tempDVD->set_Media_Type(type);

	// read values from the input stream
	in >> temp;
	tempDVD->set_ID(temp);

	in >> temp;
	tempDVD->set_Avail(temp);

	in >> temp;
	tempDVD->set_Loan_Period(temp);

	in >> tempprc;
	tempDVD->set_Price(tempprc);

	in.ignore();
	getline(in, tempstr);
	tempDVD->set_Title(tempstr);

	in >> tempstr;
	tempDVD->set_Rating(tempstr);

	in.ignore();
	getline(in, tempstr);
	tempDVD->set_Director(tempstr);

	getline(in, tempstr);
	tempDVD->set_Actors(tempstr);

	return tempDVD; // return the object
}
/*
Name:		read_Book
Parameters:	an input stream and a string representing the type of item
		read from the input stream
Return:		a Book pointer representing a book read from the input file
Description:	This function is used to read the values from an input file 
		and assign the values to an object that is returned to the load function
*/
Book* read_Book(ifstream& in, string type)
{
	Book *tempBook; // a temporary book to hold the values
	tempBook = new Book; // allocate memory

	int temp; // integer values
	double tempprc; // the price of the book
	string tempstr; // string values

	// set the media type to the parameter
	tempBook->set_Media_Type(type);

	// read in values from the input stream
	in >> temp;
	tempBook->set_ID(temp);

	in >> temp;
	tempBook->set_Avail(temp);
	
	in >> temp;
	tempBook->set_Loan_Period(temp);

	in >> tempprc;
	tempBook->set_Price(tempprc);

	in.ignore();
	getline(in, tempstr);
	tempBook->set_Title(tempstr);

	getline(in, tempstr);
	tempBook->set_Author(tempstr);
	
	getline(in, tempstr);
	tempBook->set_Publisher(tempstr);

	getline(in, tempstr);
	tempBook->set_Publish_Date(tempstr);

	return tempBook; // return the object
}
