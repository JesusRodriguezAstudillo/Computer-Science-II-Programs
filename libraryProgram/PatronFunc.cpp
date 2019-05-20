#include "libraries.h"
#include "functions.h"

/*
Name:		Add_Patron
Parameters:	the Patrons object that represents the list of all patrons
Return:
Description:	This function is used to create a new patron object, prompt for values,
		and save the new patron to the patron map
*/
void Patrons::Add_Patron(Patrons &Patronlist)
{
	Patron *newPatron; // temporary patron object
	string temp; // a string that will hold the temporary values
	int id; // the patron's id number and map index

	newPatron = new Patron; // allocate memory for temporary patron

	do
	{
		// promp for id
		cout << "Enter the patron's ID: ";
		cin  >> id;
		if(id < 0)
		{
			cout << "The value is not valid.\n";
		}
	}while(id < 0);

	// set the patron's id
	newPatron->get_ID(id);

	// check that the map location is empty
	if(Patron_List[id] == NULL)
	{
		// prompt for values
		cout << "Enter the patron's last name then their first separated by a space: ";
		cin.ignore();
		getline(cin, temp);
		newPatron->get_Name(temp);

		// save the patron name to the alphabetical map 
		Patron_Names[temp] = id;
	
		cout << "Enter the patron's address: ";
		getline(cin, temp);
		newPatron->get_Address(temp);

		cout << "Enter the patron's email adress: ";
		getline(cin, temp);
		newPatron->set_Email(temp);

		cout << "Enter the patron's phone number: ";
		getline(cin, temp);
		newPatron->set_Phone(temp);

		// set values to zero
		newPatron->set_Balance(0);
		newPatron->set_Loaned(0);

		// add patron to the map
		Patron_List[id] = newPatron;


	}
	else
	{
		// the ID already exists and cannot be used again
		cout << "The ID that you entered is already in use.\n";
	}

	return;
}
/*
Name:		Edit_Information
Parameters:
Return:
Description:	This function is used change the attributes of a specific patron object inside
		the patron map
*/
void Patrons::Edit_Information()
{
	int ID; // the patron's ID
	string temp; // a string to hold the values

	// prompt for ID
	cout << "Enter the Patron's ID to edit their information: ";
	cin  >> ID;

	// check the validity of the patron's id
	if(Patron_List[ID] != NULL)
	{
		temp = Patron_List[ID]->display_Name();
		Patron_Names.erase(temp);
		
		// prompt for new values
		cout << "Enter the patron's last name then their first name separated by a space: ";
		cin.ignore();
		getline(cin, temp);
		Patron_List[ID]->get_Name(temp);
		Patron_Names[temp] = ID;

		cout << "Enter the patron's address: ";
		getline(cin, temp);
		Patron_List[ID]->get_Address(temp);

		cout << "Enter the patron's email address: ";
		getline(cin, temp);
		Patron_List[ID]->set_Email(temp);

		cout << "Enter the patron's phone number: ";
		getline(cin, temp);
		Patron_List[ID]->set_Phone(temp);
	}
	else
	{
		// the id is not valid so erase the empty map location
		cout << "The ID that you entered is not registered.\n";
		Patron_List.erase(ID);
	}

	return;
}
/*
Name:		Remove_Patron
Parameters:
Return:
Description:	This function is used to remove a patron from the patron map but only
		after checking that their balance is 0 and that they have no books currently loaned out
*/
void Patrons::Remove_Patron()
{
	int ID; // the patron's id
	string name;


	// set precision for money
	cout.precision(2);

	// prompt for id
	cout << "Enter the Patron's ID to remove their information: ";
	cin  >> ID;

	// check that the id is a valid index location
	if(Patron_List[ID] != NULL)
	{
		name = Patron_List[ID]->display_Name();

		// check the patron's balance
		if(Patron_List[ID]->show_Balance() > 0)
		{
			cout << "The patron cannot be removed from the system because they have a outstanding balance of: $" << setw(4) << fixed  << right << Patron_List[ID]->show_Balance() << endl;
		}
		// check if the patron has active loans
		else if(Patron_List[ID]->show_Loaned() > 0)
		{
			cout << "The patron cannot be removed from the system beacuse they have one or more books currently loaned\n";
		}
		else
		{
			// the patron has no fines or loans so remove them from the map
			Patron_List.erase(ID);
	
			// remove the patron from the secondary map	
			Patron_Names.erase(name);
			cout << "The patron has been removed.\n";
		}
	}
	else
	{
		// the ID is invalid so erase the empty map location
		cout << "The ID that you entered is not registered.\n";
		Patron_List.erase(ID);
	}

	return;
}
/*
Name:		Print_Names
Parameters:
Return:
Description:	This function is used to copy the Patron_List map into a vector so 
		that the names of the patrons are arranged and displayed in alphabetical order
*/
void Patrons::Print_Names()
{
	int id; // the patron's id

	// declare an iterator to loop through the map
	map<string, int>::iterator iter;

	// loop through the map and output the patron's name in alphabetical order with their attributes
	for(iter = Patron_Names.begin(); iter != Patron_Names.end(); iter++)
	{
		cout << "Name: " << setw(33) << right << iter->first << endl;
		id = iter->second;
		cout << "ID: " << setw(35) << right << Patron_List[id]->check_ID() << endl;
		cout << "Address: " << setw(30) << right << Patron_List[id]->print_Address() << endl;
		cout << "Email: " << setw(32) << right << Patron_List[id]->get_Email() << endl;
		cout << "Phone: " << setw(32) << right << Patron_List[id]->get_Phone() << endl;
		cout.precision(2);
		cout << "Balance: " << setw(26) << right << fixed << '$' << Patron_List[id]->show_Balance() << endl;
		cout << "Number of Loans: " << setw(22) << right << Patron_List[id]->show_Loaned() << endl << endl;
	}

	// display message for an empty map
	if(Patron_List.empty())
	{
		cout << "\t*There are no registered Patrons.\n\n";
	}

	return;
}
/*
Name:		Print_Addresses
Parameters:
Return:
Description:	This function is used to print the names of all patrons and then print their
		addresses
*/
void Patrons::Print_Addresses()
{
	map<int, Patron*>::iterator iter; // iterator used to loop through the map

	// loop through the map
	for(iter = Patron_List.begin(); iter != Patron_List.end(); iter++)
	{
		// print the names and addresses
		cout << "Name: " << setw(33) << right << iter->second->display_Name() << endl; 
		cout << "Address: " << setw(30) << right << iter->second->print_Address() << endl << endl;
	}

	// display message for an empty map
	if(Patron_List.empty())
	{
		cout << "\t*There are no registered Patrons.\n\n";
	}
	
	return;
}
/*
Name:		Get_Name
Parameters:	an int representing a patron's id number
Return:		a string representing the patron's name
Description:	this function is used to retrive the name of a particular patron from the 
		patron map
*/
string Patrons::Get_Name(int id)
{
	string name; // the name of the patron
	
	// retrieve name and initialize the string to the name
	name = Patron_List[id]->display_Name();
	
	// return the name of the patron
	return name;
}
/*
Name:		Change_Balance
Parameters:	an int representin a patron's ID and a double representing an amount of money
Return:
Description:	this function is used to change a particular patron's balance
*/
void Patrons::Change_Balance(int id, double amount)
{
	// call the Add_Balance function and pass the amount of money
	Patron_List[id]->Add_Balance(amount);

	return;
}
/*
Name:		Print_Fines
Parameters:
Return:
Description:	This function is used to loop through the map and print out all of the patrons
		that have a balance greater than zero
*/
void Patrons::Print_Fines()
{
	map<int, Patron*>::iterator iter; // iteratro used to loop through map

	int counter = 0; // the amount of patron's with fines

	// loop through map
	for(iter = Patron_List.begin(); iter != Patron_List.end(); iter++)
	{
		// check if the balance is greater than zero
		if(iter->second->show_Balance() > 0)
		{
			counter++; // increment the counter

			// adjust cout
			cout.precision(2);

			// print values
			cout << "Patron ID: " << setw(10) << right << iter->second->check_ID();
			cout << "   Patron Name: " << setw(20) << right << iter->second->display_Name();
			cout << "   Balance: " << setw(4) << fixed << right << '$' << iter->second->show_Balance() << endl << endl;
		}
	}

	// output message if there are not patrons with fines
	if(counter == 0)
	{
		cout << "\t*None of the patrons have fines.\n\n";
	}

	return;
}
/*
Name:		Payment
Parameters:
Return:
Description:	This function is used to change the balance of a patron
*/
void Patrons::Payment()
{
	int id; // Patron's id
	double amount, balance, change; // values representing amounts of money

	// prompt for id
	cout << "Enter the patron's ID: ";
	cin  >> id;

	// check that the index is valid
	if(Patron_List[id] == NULL)
	{
		// the index is not valid and erase the empty map location
		cout << "The ID was not found.\n";
		Patron_List.erase(id);
	}
	else
	{
		// adjust cout
		cout.precision(2);
	
		// retrive the patron's balance
		balance = Patron_List[id]->show_Balance();

		// prompt for the amount to be paid
		cout << "Enter the amount of money: $";
		cin  >> amount;

		// check that the value is appropriate
		if(amount <= 0)
		{
			cout << "The amount entered is invalid.\n";
		}
		else
		{
			// adjust the amount if the patron pays more than enough money
			if((balance - amount) < 0)
			{
				change = (amount - balance); // calculate the change due
			
				amount = (amount - change) * -1; // adjust amount and treat it as a negative number
					
				// call the Add_Balance function and pass the negative amount
				Patron_List[id]->Add_Balance(amount);

				// print remaining balance
				cout << "New Balance: $" << Patron_List[id]->show_Balance() << endl;
			
				// print out the change due
				cout << "Change Due: $" << setw(4) << change << endl;
			}
			else
			{
				// the amount does not exceed the balance
				amount *= -1; // multiply by a negative 1
		
				// call function pass the amount of money
				Patron_List[id]->Add_Balance(amount);

				// print remaining balance
				cout << "New Balance: $" << Patron_List[id]->show_Balance() << endl;
			} 
		}
	}

	return;
}
/*
Name:		Delete
Parameters:
Return:
Description:	This function is used to clear all indices of the map when the user quits the
		program
*/
void Patrons::Delete()
{
	// call function to clear the map
	Patron_List.clear();
	return;
}
/*
Name:		get_Name
Parameters:	a string representing the patron's name
Return:		
Description:	this function is used to set the name of a patron to the value passed by the user
*/
void Patron::get_Name(string name)
{
	// set name equal to the parameter
	Name = name;
	return;
}
/*
Name:		display_Name
Parameters:
Return:		a string representing the patron's name
Description:	this function is used to return the patron's name
*/
string Patron::display_Name()
{
	return Name;
}
/*
Name:		get_ID
Parameters:	an int representing a patron's ID
Return:		
Description:	This function is used to initialize a patron object's id to 
		a value entered by the user
*/
void Patron::get_ID(int id)
{
	// set the id equal to the parameter
	ID = id;
	return;
}
/*	
Name:		check_ID
Parameters:	
Return:		an int representing a patron's id
Description:	this function is used to return the patron's ID
*/
int Patron::check_ID()
{
	return ID;
}
/*	
Name:		get_Phone
Parameters:	
Return:		a string representing a patron's phone number
Description:	this function is used to return a patron's phone number
*/
string Patron::get_Phone()
{
	return Phone_Number;
}
/*	
Name:		get_Email
Parameters:	
Return:		a string representing the patron's email address
Description:	this function is used to return the patron's email address
*/
string Patron::get_Email()
{
	return Email;
}
/*
Name:      	check_ID
Parameters:	an int representing a patron's id number
Return:		a bool representing whether the id parameter exist in the patron map
Description:
*/
bool Patrons::check_ID(int ID)
{
	// check if the index is valid
	if(Patron_List[ID] == NULL)
	{
		// since the index is not valid erase empty location and return false
		Patron_List.erase(ID);
		return false;
	}
	else
	{
		// the id is valid so return true
		return true;
	}
}
/*
Name:		get_Address
Parameters:	a string representing the address of a patron
Return:		
Description:	this function is used to set the address of a patron to the parameter
		entered by the user
*/
void Patron::get_Address(string address)
{
	// set the address to the parameter
	Address = address;
	return;
}
/*
Name:		set_Email
Parameters:	a string representing the email of a patron
Return:		
Description:	This function is used to set the Email attribute to a value entered by the user
*/
void Patron::set_Email(string email)
{
	// set the Email equal to the parameter
	Email = email;
	return;
}
/*
Name:		set_Balance
Parameters:	a double representing an amout of money
Return:
Description:	this function is used to set the balance of a patron
*/
void Patron::set_Balance(double balance)	
{
	// set the Balance equal to the parameter
	Balance = balance;
	return;
}
/*
Name:		set_Phone
Parameters:	a string representing a phone number
Return:		
Description:	this function is used to set the Phone_Number attribute to a value
		entered by the user
*/
void Patron::set_Phone(string phone)
{
	// set the Phone_Number equal to the parameter
	Phone_Number = phone;	
	return;
}
/*
Name:		print_Address
Parameters:	
Return:		a string representing a patron's address
Description:	This function is used to return the Address of a patron
*/
string Patron::print_Address()
{
	return Address;
}
/*
Name:		set_Loaned
Parameters:	an int representing a new loan under a particular patron
Return:		
Description:	This function is used to set the Loaned attribute to the parameter
*/
void Patron::set_Loaned(int num)
{
	// set the Loaned value to the parameter
	Loaned = num;
	return;
}
/*
Name:		show_Balance
Parameters:
Return:		a double representing the Balance of a patron
Description:	This function is used to return the Balance of a patron
*/
double Patron::show_Balance()
{
	return Balance;
}
/*
Name:		Add_Balance
Parameters:	a double representing an amount of money
Return:
Description:	This function is used to change the balance of a particular patron by adding an
		amount of money
*/
void Patron::Add_Balance(double amount)
{
	// add the amount to the balance
	Balance += amount;

	return;
}
/*
Name:		Add_Loaned
Parameters:	and int representing a patron's id and an int representing the amount of loans
Return:
Description:	This function is used to increase or decrease the amount of loans that a patron has
*/
void Patrons::Add_Loaned(int id, int num)
{
	// call the add_Loaned function and pass the num parameter
	Patron_List[id]->add_Loaned(num);
	return;
}
/*
Name:		add_Loaned
Parameters:	and int represing whether a book was loned or returned
Return:
Description:	This function is used to increase or decrease the amount of loans that a patron has
*/	
void Patron::add_Loaned(int num)
{
	// add the num to the Loaned attribute
	Loaned += num;
	return;
}
/*
Name:		show_Loaned
Parameters:
Return:		an int representing the amount of loans that a patron has
Description:	this function is used to return the Loaned attribute
*/
int Patron::show_Loaned()
{
	return Loaned;
}
/*
Parameters:	an ostream reference and a Patron object
Return:		an ostream reference
Description:	This function overloads the insertion operator for the Patron class to display all attributes
*/
ostream& operator <<(ostream& out, Patron& patron)
{
	out << patron.ID << endl;
	out << patron.Loaned << endl;
	out << patron.Balance << endl;
	out << patron.Name << endl;
	out << patron.Address << endl;
	out << patron.Email << endl;
	out << patron.Phone_Number << endl;

	return out;
}
/*
Parameters:	an ifstream reference and a Patron object
Return:		an ifstream reference 
Description:	this function overloads the extraction operator for the Patron class
*/
istream& operator >>(istream& in, Patron& patron)
{
	in >> patron.ID;
	in >> patron.Loaned;
	in >> patron.Balance;
	in.ignore();
	
	getline(in, patron.Name);
	getline(in, patron.Address);
	getline(in, patron.Email);
	getline(in, patron.Phone_Number);

	return in;
}
/* 
Name:		Save_Patrons
Parameters:
Return:		
Description:	This function is used to save the patron map information to a file named Patrons.txt
*/
void Patrons::Save_Patrons()
{
	ofstream out_file; // ofstream object

	out_file.open("Patrons.txt"); // open the file

	// check if the file opened correctly
	if(out_file.fail())
	{
		cout << "Failed to open the patrons file.\n";
		exit(EXIT_FAILURE);
	}
	else
	{
		int id; // the patron's id

		map<int, Patron*>::iterator iter; // iterator to loop through the map

		out_file << Patron_List.size() << endl; // write the size to the file

		// loop through the map and print the attributes of the map
		for(iter = Patron_List.begin(); iter != Patron_List.end(); iter++)
		{
			id = iter->second->check_ID();
			out_file << *Patron_List[id];
		}
	}

	// close the file
	out_file.close();

	return;
}
/*
Name:		Loan_Patrons
Parameters:	
Return:		
Description:	This function is used load the information from the Patrons.txt file
*/
void Patrons::Load_Patrons()
{
	ifstream in_file; // the ifstream object

	in_file.open("Patrons.txt"); // open the file
	
	// check if the file opened correctly
	if(in_file.fail())
	{
		cout << "Failed to open the patrons file.\n";
		exit(EXIT_FAILURE);
	}
	else
	{
		int id, size; // the id of a patron and the previous number of patrons
		string name; // the patron's name

		in_file >> size; // read in the size

		// loop through file
		for(int i = 0; i < size; i++)
		{
			// declare a temporary object and allocate memory
			Patron *tempPatron;
			tempPatron = new Patron;
		
			// read in attributes
			in_file >> *tempPatron;

			// get the key for the map
			id = tempPatron->check_ID();
		
			// insert the patron into the map
			Patron_List.insert(pair<int, Patron*>(id, tempPatron)); 
		}

		map<int, Patron*>::iterator iter; // iterator to loop through Patron map

		// copy the names into the alphabetically sorted map
		for(iter = Patron_List.begin(); iter != Patron_List.end(); iter++)
		{
			id = iter->second->check_ID();
			name = iter->second->display_Name();
			Patron_Names[name] = id;
		}

	}
	
	// close the file
	in_file.close();

	return;
}
