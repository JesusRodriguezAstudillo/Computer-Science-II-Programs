#include "libraries.h"
#include "functions.h"

/*
Name:		Loan_Item
Parameters:	A Library_Items object that represents the list of all library items,
		the Patrons object that represents the list of all patrons, and a Library_Values object that
		represens the fees and loan periods
Return:
Description:	This function is used to prompt for a specific item and patron ID in order to loan
		the item to the specific ID. The information is saved into a map for loans using the items
		id as the key
*/
void Loans::Loan_Item(Library_Items &Itemlist, Patrons &Patronlist, struct Library_Values values)
{
	int patron_id, item_id; // the patron's id and the items id
	Loan *newLoan; // create a new loan object
	string temp; // string to hold copies of the book's title and the patron's name
	time_t duedate;	// the date that the item will due

	newLoan = new Loan; // allocate memory for the Loan
	
	// prompt for the ids
	cout << "Enter the item's ID: ";
	cin  >> item_id;
	cout << "Enter the patron's ID: ";
	cin  >> patron_id;
	
	// check if the ids are valid index values
	if((Itemlist.Check_ID(item_id)) && (Patronlist.check_ID(patron_id)))
	{
		// check if the book is loaned out
		if((Itemlist.Get_Availability(item_id) > 0))
		{
			cout << "The book cannot be loaned because it has been marked as already loaned.\n";
			cout << "Make sure that the book has been returned before loaning it.\n";
		}
		else
		{
			// set the values of the new loan
			newLoan->set_PatronID(patron_id);
			newLoan->set_ItemID(item_id);
			newLoan->set_Due_Date(Itemlist.Get_Loan_Period(item_id));
			newLoan->set_Fined_Status(0);

			// change the books availability inside the item object
			Itemlist.Change_Availability(item_id, 1);

			temp = Itemlist.Get_MediaType(item_id);

			// set the specific fee for the object
			if(temp == "Videogame")
			{
				newLoan->set_Fee(values.VideogameFee);
			}
			else if(temp == "DVD")
			{
				newLoan->set_Fee(values.DVDFee);
			}
			else if(temp == "Book")
			{
				newLoan->set_Fee(values.BookFee);
			}

			// show that the patron has added one more loan to their object
			Patronlist.Add_Loaned(patron_id, 1);

			// save the new loan
			Loan_ListB[item_id] = newLoan;

			// show when the book will be due
			duedate = newLoan->show_Due_Date();
			cout << "The item will be due on " << ctime(&duedate);
		}
	}
	else
	{	// the ids are not valid
		cout << "One or both of the IDs that were entered are not valid.\n";
	}
	return;
}
/*
Name:		Return_Item
Parameters:	The LibraryItems object representing the list of all items and the Patrons object representing the 
		list of all patrons
Return:
Description:	This function is used to remove an object from the Loan_List map which represents
		the returning of an item
*/
void Loans::Return_Item(Library_Items &Itemlist, Patrons &Patronlist)
{
	int patron_id, item_id; // the patron id and the item id
	time_t return_date, due_date; // the current date and the due date
	double difference, finenum; // the difference between the current time and the due time and the fine amount

	// call function to set the return_date to the current time
	time(&return_date); 
	
	// prompt for the item's id
	cout << "Enter the item's ID: ";
	cin  >> item_id;

	// check if the id is a valid index location
	if(Loan_ListB[item_id] == NULL)
	{
		// output message and erase the empty map location
		cout << "The loan information was not found.\n";
		cout << "Make sure that the ID is correct.\n";
		Loan_ListB.erase(item_id);
	}
	else
	{
		// retrieve the patron's id
		patron_id = Loan_ListB[item_id]->get_PatronID();
	
		// retrive the due date
		due_date = Loan_ListB[item_id]->show_Due_Date();

		// calculate the difference between the dates
		difference = difftime(return_date, due_date);
		
		// if the difference is greater than zero the book is overdue
		if(difference > 0)
		{
			// calculate the amount of money due and display
			finenum = Loan_ListB[item_id]->get_Fee() * Loan_ListB[item_id]->show_Fined_Status();
			cout << "The item was overdue and the charge is $" << finenum << endl;
		}
	
		// reset the availability of the item
		Itemlist.Change_Availability(item_id, 0);
	
		// remove one loan from the patron
		Patronlist.Add_Loaned(patron_id, -1);

		// erase the map location
		Loan_ListB.erase(item_id);
		
		cout << "\t*The item has been returned.\n";
	}

	return;
}
/*
Name:		Delete
Parameters:
Return:
Description:	This function is used to clear the Loan_ListB map
*/
void Loans::Delete()
{
	// call function to clear the map
	Loan_ListB.clear();	

	return;
}
/*
Name:		set_PatrontID
Parameters:	an int representing a patron's id
Return:
Description:	This function is used to set the Patron_ID attribute to the parameter
*/
void Loan::set_PatronID(int ID)
{
	// set the patron_ID equal to the parameter
	Patron_ID = ID;

	return;
}
/*
Name:		get_PatronID
Parameters:
Return:		an int representing the patron's id
Description:	This function is used to return the Patron's ID
*/
int Loan::get_PatronID()
{
	return Patron_ID;
}
/*
Name:		set_ItemID
Parameters:	an int representing the item's id
Return:
Description:	this function is used to assign the ID value to the Item_ID attribute
*/
void Loan::set_ItemID(int id)
{
	Item_ID = id;

	return;
}
/*
Name:		get_ItemID
Parameters:
Return:		an int representing an item's ID
Description:	this function is used to return the Item's ID
*/
int Loan::get_ItemID()
{
	return Item_ID;
}
/*
Name:		set_Fee
Parameters:	a double representing the fee for the overdue item
Return:		
Description:	this function is used to assign the Fee attribute
*/
void Loan::set_Fee(double fee)
{
	Fee = fee;

	return;
}
/*
Name:		get_Fee
Parameters:
Return:		a double representing the Fee per day for an overdue item
Description:	this function is used to return the Fee attribute
*/
double Loan::get_Fee()
{
	return Fee;
}
/*
Name:		set_Due_Date
Parameters:	an int representing the Loan period
Return:		
Description:	This function is used to adjust a time_t value by adding the attribute period to it.
*/
void Loan::set_Due_Date(int LoanPeriod)
{
	struct tm *return_date; // the time struct that will be modified
	time_t temp; // the value that will initialize the value of the struct object

	time(&temp); // call function to gather the current time

	return_date = localtime(&temp); // set time object to the current time
	return_date->tm_mday += LoanPeriod; // increment the due date by the parameter time
	return_date->tm_hour = return_date->tm_hour + (23 - return_date->tm_hour); 
	return_date->tm_min = return_date->tm_min + (59 - return_date->tm_min); 
	return_date->tm_sec = return_date->tm_sec + (59 - return_date->tm_sec); 

	Due_Date = mktime(return_date); // set the Due_Date attribute to the future return date

	return;
}
/*
Name:		show_Due_Date
Parameters:	
Return:		a time_t value that represents the Loan due date
Description:	This function is used to return the Due_Date
*/
time_t Loan::show_Due_Date()
{
	return Due_Date;
}
/*
Name:		Update_Date
Parameters:	the Library_Items object representing the list of all items and the patrons object representing the 
		list of all patrons
Return:		
Description:	This function is used to loop through the Loan_ListB map to check whether the an item is overdue
*/
void Loans::Update_Date(Library_Items &Itemlist, Patrons &Patronlist)
{
	time_t temp, duedate; // the current time and the due date time
	int item_id, patron_id; // a item id and a patrons id
	int time_calculation, FineStatus; // the time calculation as an integer and if the patron has been fined
	double timediff; // the difference between the current time and the due date
	double fine; // the amount of money added to the balance of a patron

	time(&temp); // gather the current time

	map<int, Loan*>::iterator iter; // declare iterator to loop through all of the objects

	// loop through the map
	for(iter = Loan_ListB.begin(); iter != Loan_ListB.end(); iter++)
	{
		fine = 0; // reset the balance

		// retrieve the book's due date
		duedate = iter->second->show_Due_Date();

		// calculate the difference between the current time and the due date
		timediff = difftime(temp, duedate);

		// if the time is greater than zero the book is overdue
		if(timediff > 0)
		{
			time_calculation = timediff; // treat the time difference as an int

			time_calculation = (time_calculation / 86400) + 1; // calculate the number of days that a book has been due

			// retrive the ids
			item_id = iter->second->get_ItemID();
			patron_id = iter->second->get_PatronID();
		
			// change the availability of the book
			Itemlist.Change_Availability(item_id, 2);

			// check if the patron has been fined	
			FineStatus = iter->second->show_Fined_Status();
		
			// Add to the balance the correct amount of times
			if(FineStatus < time_calculation)
			{
				// loop and add to the fee
				for(int i = FineStatus; i < time_calculation; i++) 
				{
					fine += Loan_ListB[item_id]->get_Fee();
				}

				Patronlist.Change_Balance(patron_id, fine); 
				iter->second->set_Fined_Status(time_calculation);
			}
		}
	}

	return;
}
/*
Name:		Print_OverdueItems
Parameters:	a Library_Items object that represents the list of all objects and the Patrons object that
		represents the list of all patron's
Return:
Description:	This function is used to loop throught the loans map to check if an item is currently overdue.
		If the item is overdue the itme id and title will be printed along with the patron's id and
		their name as well as the due date
*/
void Loans::Print_OverdueItems(Library_Items Itemlist, Patrons Patronlist)
{
	map<int, Loan*>::iterator i; // iterator to loop through map
	
	time_t current, due_date; // the current time and the due date
	int id, counter = 0; // the item and patron id and a counter for the number of overdue items
	double time_diff; // the time difference 

	time(&current); // get the current time

	if(Loan_ListB.empty())
	{
		cout << "\t*There are no items currently loaned out.\n\n";
	}

	// loop through map
	for(i = Loan_ListB.begin(); i != Loan_ListB.end(); i++)
	{
		due_date = i->second->show_Due_Date(); // get the due date

		time_diff = difftime(current, due_date); // calculate the difference

		// if the item is overdue print names and ids and due date
		if(time_diff > 0)
		{
			counter++; // increase counter

			id = i->second->get_ItemID();
			cout << "Item ID: " << setw(24) << right << id << endl;
			cout << "Item Title: " << setw(21) << right << Itemlist.Get_Title(id) << endl;
			id = i->second->get_PatronID();
			cout << "Patron ID: " << setw(22) << right << id << endl;
			cout << "Patron Name: " << setw(20) << right << Patronlist.Get_Name(id) << endl;
			cout << "Due Date: " << setw(23) << right << ctime(&due_date) << endl << endl;
		}
	}

	if(counter == 0)
	{
		cout << "\t*There are no overdue items.\n\n";
	}

	return;
}
/*
Name:		Check_Loan
Parameters:	an int representing the loan key
Return:		a boolean representing whether the key exists in the loan map
Description:	This function is used to check whether the parameter is a valid key in the loan map
*/
bool Loans::Check_Loan(int id)
{
	bool status;

	// check if the loan key is valid
	if(Loan_ListB[id] == NULL)
	{
		// the key was not found so erase the empty map location
		status = false;
		Loan_ListB.erase(id);
	}
	else
	{
		// the id is valid so return true
		status = true;
	}

	return status;
}
/*
Name:		PatronID
Parameters:	an int representing the key in the loan map
Return:		an int representing the id of the patron that has the book loned
Description:	This function is used to retrieve the patron id from the loan map
*/
int Loans::PatronID(int id)
{
	int patron_id;

	// retrieve the patron id
	patron_id = Loan_ListB[id]->get_PatronID();

	// return the patron
	return patron_id;
}
/*
Name:		Remove_Loan
Parameters:	an int representing the key in the loan map
Return:
Description:	This function is used to remove a map location
*/
void Loans::Remove_Loan(int id)
{
	// erase the map location
	Loan_ListB.erase(id);

	return;
}
/*
Name:		set_Fined_Status
Parameters:	an int representing whether the patron has been charged 
Return:
Description:	this function is used to change the loans fined status
*/
void Loan::set_Fined_Status(int num)
{
	// set the Fined_Status to the parameter
	Fined_Status = num;
	return;
}
/*
Name:		show_Fined_Status
Parameters:
Return:		an int representing if a patron has been fined or not
Description:	this function is used to return the Fined_Status attribute
*/
int Loan::show_Fined_Status()
{
	return Fined_Status;
}
/*
Parameters:	an ostream reference and a Loan object
Return:		an ostream reference
Description:	This function overloads the insertion operator for the Loan class to display all attributes
*/
ostream& operator <<(ostream& out, Loan& loan)
{
	out << loan.Item_ID << endl;
	out << loan.Patron_ID << endl;
	out << loan.Fined_Status << endl;
	out << loan.Fee << endl;
	out << loan.Due_Date << endl;

	return out;
}
/*
Parameters:	an ifstream reference and a Loan object
Return:		an ifstream reference 
Description:	this function overloads the extraction operator for the Loan class
*/
istream& operator >>(istream& in, Loan& loan)
{
	in >> loan.Item_ID;
	in >> loan.Patron_ID;
	in >> loan.Fined_Status;
	in >> loan.Fee;
	in >> loan.Due_Date;

	return in;
}

/*
Name:		Print_LoanInfo
Parameters:	the Library_Items object that represents the list of all items and the Patrons object that
		represents the list of all patrons
Return:
Description:	this function is used to display the information from the loan map
*/
void Loans::Print_LoanInfo(Library_Items Itemlist, Patrons Patronlist)
{
	map<int, Loan*>::iterator iter; // declare iterator for map
	
	int id, patron_id; // the item's id and the patron's id
	time_t due_date; // the due date for an object

	if(Loan_ListB.empty())
	{
		cout << "\t*There are no items currently loaned out.\n\n";
	}

	// loop through map
	for(iter = Loan_ListB.begin(); iter != Loan_ListB.end(); iter++)
	{
		id = iter->second->get_ItemID(); // get the item's id
		patron_id = iter->second->get_PatronID(); // get the patron's id
		due_date = Loan_ListB[id]->show_Due_Date(); // get the due date
	
		// display the values
		cout << "Item ID: " << setw(35) << right << id << endl;
		cout << "Item Title: " << setw(32) << right << Itemlist.Get_Title(id) << endl;
		cout << "Patron ID: " << setw(33) << right << patron_id << endl;
		cout << "Patron Name: " << setw(31) << right << Patronlist.Get_Name(patron_id) << endl;
		cout << "Item Due Date: " << setw(30) << right << ctime(&due_date) << endl;
		cout << endl;
	}

	return;
}
/*
Name:		Save_Loans
Parameters:
Return:		
Description:	This function is used to save the Loan_ListB map objects into the file Loans.txt
*/
void Loans::Save_Loans()
{
	ofstream out_file; // ofstream object

	out_file.open("Loans.txt"); // open the file

	// check if the file opened correctly
	if(out_file.fail())
	{
		cout << "Failed to open the loans file.\n";
		exit(EXIT_FAILURE);
	}
	else
	{
		int id; // the item's id

		// an iterator to loop through Loan map
		map<int, Loan*>::iterator iter;

		out_file << Loan_ListB.size() << endl; // write the size to the file

		// loop through the file and write all objects to it
		for(iter = Loan_ListB.begin(); iter != Loan_ListB.end(); iter++)
		{
			id = iter->second->get_ItemID();
			out_file << *Loan_ListB[id];
		}
	}
	
	// close the file
	out_file.close();

	return;
}
/*
Name:		Loan_Loans
Parameters:
Return:		
Description:	This function is used to Load the information from the file Loans.txt
*/
void Loans::Load_Loans()
{
	ifstream in_file; // the ifstream object
	
	in_file.open("Loans.txt"); // open the file

	// check if the file opened correctly
	if(in_file.fail())
	{
		cout << "Failed to open the loans file.\n";
		exit(EXIT_FAILURE);
	}
	else
	{
		int id, size; // the item's id and the size of the former map

		in_file >> size; // read in the size

		// loop through the file
		for(int i = 0; i < size; i++)
		{
			// declare temporary object and allocate memory
			Loan *tempLoan;
			tempLoan = new Loan;
			
			// read in object
			in_file >> *tempLoan;

			// get id
			id = tempLoan->get_ItemID();
		
			// insert temp value into the map
			Loan_ListB.insert(pair<int, Loan*>(id, tempLoan)); 
		}
	}

	in_file.close(); // close the file

	return;
}
