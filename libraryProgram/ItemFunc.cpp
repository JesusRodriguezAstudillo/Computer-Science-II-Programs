#include "libraries.h"
#include "functions.h"

/*
Name:		Add_LibraryItem
Parameters:	the Library_Values object representing the loans and fees for library items
Return:		
Description:	This function is used to display a menu and call funtions that add new 
		items to the LibraryItems map
*/
void Library_Items::Add_LibraryItem(struct Library_Values values)
{
	int choice = -1; // the user choice

	// display menu
	do
	{
		cout << "Enter the type of item that you would like to enter\n";
		cout << "or enter 0 to go back to the main menu.\n";
		cout << "\t(1) Book\n";
		cout << "\t(2) DVD\n";
		cout << "\t(3) Videogame\n";
		cout << "\t(0) Return to Main Menu\n";
		cout << "Choice: ";
		cin  >> choice;
		
		// use switch to call functions
		switch(choice)
		{
			case 0:
				break;
			case 1:
				Add_Book(values);
				break;
			case 2:
				Add_DVD(values);
				break;
			case 3:
				Add_Videogame(values);
				break;
			default:
				cout << "The choice that you entered was in valid.\n";
		}	

	}while(choice != 0);

	return;
}
/*
Name:		Add_Videogame
Parameters:	a Library_Values object representing loan times and fees
Return:
Description:	This function is used to create a new Videogames object and assign values 
		from user input
*/
void Library_Items::Add_Videogame(struct Library_Values values)
{
	int id; // the Videogames id
	string temp; // string values
	double price; // the videogame's replacement cost

	Videogames *newGame; // a videogame object

	newGame = new Videogames; // allocate memory

	do
	{
		// prompt for and set ID
		cout << "Enter the videogame's ID number: ";
		cin  >> id;

		if(id < 0)
		{
			cout << "The value is not valid.\n";
		}
	}while(id < 0);
	
	newGame->set_ID(id);

	// check if the ID is being used by another object
	if(LibraryItems[id] == NULL)
	{
		// the ID is available so prompt for and assign values
		cout << "Enter the videogame's title: ";
		cin.ignore();
		getline(cin, temp);
		newGame->set_Title(temp);

		cout << "Enter the videogame's platform: ";
		getline(cin, temp);
		newGame->set_Platform(temp);

		cout << "Enter the videogame's developers: ";
		getline(cin, temp);
		newGame->set_Developer(temp);

		cout << "Enter the videogame's rating: ";
		cin  >> temp;
		newGame->set_Rating(temp);

		do
		{
			cout << "Enter the videogame's replacement cost: $";
			cin  >> price;
			if(price < 0)
			{
				cout << "The value is not valid.\n";
			}
		}while(price < 0);
		newGame->set_Price(price);

		newGame->set_Avail(0);
		newGame->set_Loan_Period(values.VideogameLoanPeriod);
		newGame->set_Media_Type("Videogame");

		LibraryItems[id] = newGame; // save object into map
	}
	else
	{
		// the ID is not available
		cout << "The ID number that you entered is already in use by another item.\n";
	}

	return;
}
/*
Name:		Add_DVD
Parameters:	a Library_Values object that represents the fees and loan times of items
Return:
Description:	This function is used to create a new DVD object and assign values based on user input
*/
void Library_Items::Add_DVD(struct Library_Values values)
{
	int id;	// the DVD's ID
	string temp; // string values
	double price; // the DVD's replacement cost

	DVD *newDVD; // a new DVD object

	newDVD = new DVD; // allocate memory

	do
	{
		// prompt for the ID and set the value to the object
		cout << "Enter the DVD's ID number: ";
		cin  >> id;
		if(id < 0)
		{
			cout << "The value is not valid.\n";
		}
	}while(id < 0);

	newDVD->set_ID(id);

	// check if the ID is used by another object
	if(LibraryItems[id] == NULL)
	{
		// the ID is available so prompt and assign remaining values
		cout << "Enter the DVD's title: ";
		cin.ignore();
		getline(cin, temp);
		newDVD->set_Title(temp);

		cout << "Enter the DVD's Director: ";
		getline(cin, temp);
		newDVD->set_Director(temp);

		cout << "Enter the DVD's actors: ";
		getline(cin, temp);
		newDVD->set_Actors(temp);

		cout << "Enter the DVD's rating: ";
		cin  >> temp;
		newDVD->set_Rating(temp);

		do
		{
			cout << "Enter the DVD's replacement cost: $";
			cin  >> price;
			if(price < 0)
			{
				cout << "The value is not valid.\n";
			}
		}while(price < 0);
		newDVD->set_Price(price);

		newDVD->set_Avail(0);
		newDVD->set_Loan_Period(values.DVDLoanPeriod);
		newDVD->set_Media_Type("DVD");

		LibraryItems[id] = newDVD; // assign object to the map
	}
	else
	{
		// the ID is not available  so output message
		cout << "The ID number that you entered is already in use by another item.\n";
	}

	return;
}
/*
Name:		Add_Book
Parameters:	a Library_Values object representing fees and loan times
Return:
Description:	This function is used to create a new book object and assign values to it
		and saving it to the LibraryItems map
*/
void Library_Items::Add_Book(struct Library_Values values)
{
	int id; // the book's id
	string temp; // string values
	double price; // the book's price

	Book *newBook; // a new book object

	newBook = new Book; // allocate memory
	
	do
	{
		// prompt for id and assign the value
		cout << "Enter the book's ID number: ";
		cin  >> id;
	
		if(id < 0)
		{
			cout << "The value is not valid.\n";
		}
	}while(id < 0);

	newBook->set_ID(id);

	// check if the ID is available
	if(LibraryItems[id] == NULL)
	{
		// the ID is not used so prompt for values and assign them to the object
		cout << "Enter the book's title: ";
		cin.ignore();
		getline(cin, temp);
		newBook->set_Title(temp);

		cout << "Enter the book's author: ";
		getline(cin, temp);
		newBook->set_Author(temp);

		cout << "Enter the book's publisher: ";
		getline(cin, temp);
		newBook->set_Publisher(temp);
		
		cout << "Enter the book's publishing date: ";
		getline(cin, temp);
		newBook->set_Publish_Date(temp);

		do
		{
			cout << "Enter the book's replacement cost: $";
			cin  >> price;
			if(price < 0)
			{
				cout << "The value is not valid.\n";
			}
		}while(price < 0);
		newBook->set_Price(price);
	
		newBook->set_Avail(0);
		newBook->set_Loan_Period(values.BookLoanPeriod);
		newBook->set_Media_Type("Book");

		LibraryItems[id] = newBook; // save the object to the map
	}
	else
	{
		// the ID is not available so display message 
		cout << "The ID number that was entered is already used by another item.\n";
	}

	return;
}
/*
Name:		Edit_Information
Parameters:	a loans object that represents the list of all loans
Return:
Description:	This function is used to prompt for new values for a specific object
*/
void Library_Items::Edit_Information(class Loans Loanlist)
{
	int id; // the objects id
	double price; // the objects price
	string temp; // string values

	// display message to let user know that object type cannot be changed
	cout << "\t*Editing information won't change the item's media type.\n";
	cout << "\t To do so, remove the item's information instead.\n\n";

	// prompt for ID
	cout << "Enter the item's ID to edit its information: ";
	cin  >> id;

	// check if the ID is valid
	if(LibraryItems[id] != NULL)
	{
		// check if the item is currently loaned out
		if(Loanlist.Check_Loan(id))
		{
			cout << "The items information cannot be changed since it is currently loaned out.\n";
		}
		else
		{
			// the ID belongs to a Videogames object
			if(LibraryItems[id]->get_Media_Type() == "Videogame")
			{
				// prompt for new values
				cout << "Enter the videogame's title: ";
				cin.ignore();
				getline(cin, temp);
				LibraryItems[id]->set_Title(temp);
	
				cout << "Enter the videogame's platform: ";
				getline(cin, temp);
				static_cast<Videogames*>(LibraryItems[id])->set_Platform(temp);

				cout << "Enter the videogame's developers: ";
				getline(cin, temp);
				static_cast<Videogames*>(LibraryItems[id])->set_Developer(temp);

				cout << "Enter the videogame's rating: ";
				cin  >> temp;
				static_cast<Videogames*>(LibraryItems[id])->set_Rating(temp);
		
				do
				{
					cout << "Enter the videogame's replacement cost: ";
					cin  >> price;
					if(price < 0)
					{
						cout << "The value is not valid.\n";
					}
				}while(price < 0);
				LibraryItems[id]->set_Price(price);
			}
			// the ID belongs to a DVD object
			else if(LibraryItems[id]->get_Media_Type() == "DVD")
			{
				// prompt for new values
				cout << "Enter the DVD's title: ";
				cin.ignore();
				getline(cin, temp);
				LibraryItems[id]->set_Title(temp);

				cout << "Enter the DVD's Director: ";
				getline(cin, temp);
				static_cast<DVD*>(LibraryItems[id])->set_Director(temp);

				cout << "Enter the DVD's actors: ";
				getline(cin, temp);
				static_cast<DVD*>(LibraryItems[id])->set_Actors(temp);

				cout << "Enter the DVD's rating: ";
				cin  >> temp;
				static_cast<DVD*>(LibraryItems[id])->set_Rating(temp);

				do
				{
					cout << "Enter the DVD's replacement cost: ";
					cin  >> price;
					if(price < 0)
					{
						cout << "The value is not valid.\n";
					}
				}while(price < 0);
				LibraryItems[id]->set_Price(price);
			}
			// the ID belongs to a Book object
			else if(LibraryItems[id]->get_Media_Type() == "Book")
			{
				// prompt for new values
				cout << "Enter the book's title: ";
				cin.ignore();
				getline(cin, temp);
				LibraryItems[id]->set_Title(temp);

				cout << "Enter the book's author: ";
				getline(cin, temp);
				static_cast<Book*>(LibraryItems[id])->set_Author(temp);

				cout << "Enter the book's publisher: ";
				getline(cin, temp);
				static_cast<Book*>(LibraryItems[id])->set_Publisher(temp);

				cout << "Enter the book's publishing date: ";
				getline(cin, temp);
				static_cast<Book*>(LibraryItems[id])->set_Publish_Date(temp);
				
				do
				{
					cout << "Enter the book's replacement cost: ";
					cin  >> price;
					if(price < 0)
					{
						cout << "The value is not valid.\n";
					}
				}while(price < 0);
				LibraryItems[id]->set_Price(price);
			}
		}
	}
	else
	{	
		// the ID is not valid so output message and erase empty map location
		cout << "The ID that you entered was not found.\n";
		LibraryItems.erase(id);
	}

	return;
}
/*
Name:		Remove_Item
Parameters:	
Return:
Description:	This function is used to remove an item from the LibraryItems map
*/
void Library_Items::Remove_Item()
{
	int item_id; // the items ID

	// prompt for ID
	cout << "Enter the id of the item that you wish to remove: ";
	cin  >> item_id;

	// check if the ID exists
	if(LibraryItems[item_id] == NULL)
	{
		// the ID does not exist so output message and erase empty location
		cout << "The ID entered was not found.\n";
		LibraryItems.erase(item_id);
	}
	else
	{
		// the ID is valid so check if it is currently loaned out
		if(LibraryItems[item_id]->get_Avail() > 0)
		{
			// the book is loaned so output message that it cannot be removed
			cout << "The item cannot be removed since it is currently loaned out.\n";
		}
		else
		{
			// the book can be erased
			LibraryItems.erase(item_id);
			cout << "The item has been removed from the catalog.\n";
		}
	}

}
/*
Name:		Mark_Lost_Item
Parameters:	A Loans class object representing the list of all loan objects and the Patrons
		object representing the list of all patrons
Return:
Description:	This function is used to mark an item from the ItemList map as lost.
*/
void Library_Items::Mark_Lost_Item(class Loans &Loanlist, class Patrons Patronlist)
{
	int id, patron_id; // the item's id and the patron's id

	// prompt for the item's id
	cout << "Enter the item's ID to mark it as lost: ";
	cin  >> id;

	// check if the ID is valid
	if(LibraryItems[id] == NULL)
	{
		// the ID is not valid so erase the empty map location and output a message
		cout << "The ID that you entered was not found.\n";
		LibraryItems.erase(id);
	}
	else
	{
		cout.precision(2);
		
		// the ID is valid so check if the Item is currently loaned out
		if(Loanlist.Check_Loan(id))
		{
			// the Item is loaned so add the replacement cost to the patron's balance
			cout << "The item was loaned out before marking it as lost.\n";
			cout << "The replacement cost of $" << fixed <<LibraryItems[id]->get_Price() <<" will be added to the patron's balance.\n";
			
			patron_id = Loanlist.PatronID(id); // get patron ID

			Patronlist.Change_Balance(patron_id, LibraryItems[id]->get_Price()); // charge patron
	
			// remove one loan from the patron
			Patronlist.Add_Loaned(patron_id, -1);

			// remove the loan from the map and remove the item from the map
			Loanlist.Remove_Loan(id);
			LibraryItems.erase(id);
		}
		else
		{
			// the book is not loaned out so remove from map
			LibraryItems.erase(id);
			cout << "The item's information has been removed from the system.\n";
		}
	}

	return;
}
/*
Name:		Check_ID
Parameters:	an int representing the ID of an item
Return:		a bool representing whether the ID is valid or not
Description:	This function is used to chek the LibraryItems map to check the validity of
		a particular object
*/
bool Library_Items::Check_ID(int id)
{
	// check if the ID exitst
	if(LibraryItems[id] == NULL)
	{
		// the ID does not exist so return false and erase empty location
		LibraryItems.erase(id);
		return false;
	}
	else
	{
		// the ID exists so return true
		return true;
	}

}
/*
Name:		Change_Availability
Parameters:	an int representing an items id and an int representing the new availability of the book
Return:		
Description:	This function is used to change the availability of a particular book
*/
void Library_Items::Change_Availability(int id, int status)
{
	LibraryItems[id]->set_Avail(status); // pass the availability status to the particular object

	return;
}
/*
Name:		Get_Availability
Parameters:	and int representing an item's id
Return:		an int representing the availability of an object
Description:	This function is used to return the availability of a particular object
*/
int Library_Items::Get_Availability(int id)
{
	return LibraryItems[id]->get_Avail(); // return the availability
}
/*	
Name:		Get_Loan_Period
Parameters:	an int representing an item's id
Return:		an int representing the amount of time that an item is allowed to be loaned
Description:	This fucntion is used to return the amount of time that an object is allowed
		to be loaned
*/
int Library_Items::Get_Loan_Period(int id)
{
	return LibraryItems[id]->get_Loan_Period(); // return the loan period for the item
}
/*
Name:		Get_MediaType
Parameters:	an int representing an item's id
Return:		a string representing the type of object for the id
Description:	This function is used to return the type of object for the id
*/
string Library_Items::Get_MediaType(int id)
{
	return LibraryItems[id]->get_Media_Type(); // return the media type
}
/*
Name:		Get_Title
Parameters:	an int representing the id of an item
Return:		a string representing the title of the object
Description:	this function is used to return the objects title
*/
string Library_Items::Get_Title(int id)
{		
	return LibraryItems[id]->get_Title(); // return the object's Title
}
/*
Name:		PrintItems
Parameters:	
Return:
Description:	This function is used to loop through LibraryItems map and print the values
		of the objects in the map
*/
void Library_Items::PrintItems()
{
	map<int, Library_Item*>::iterator iter; // declare iterator for map
	
	string Availability; // the availbility of the book as a string

	cout.precision(2); // format output stream

	// display message if the map is empty
	if(LibraryItems.empty())
	{
		cout << "\t*There are no items in the catalog.\n\n";
	}

	// loop through map
	for(iter = LibraryItems.begin(); iter != LibraryItems.end(); iter++)
	{
		// print values from the base class
		cout << "Item ID: " << setw(38) << right << iter->second->get_ID() << endl;
		cout << "Item Title: " << setw(35) << right << iter->second->get_Title() << endl;
		if(iter->second->get_Avail() == 0)
		{
			Availability = "Available";
		}
		else
		{
			Availability = "Not Available";
		}
	
		cout << "Item Availability: " << setw(28) << right << Availability << endl;
		cout << "Item Loan Period: " << setw(29) << right << iter->second->get_Loan_Period() << endl;
		cout << "Item Media Type: " << setw(30) << right << iter->second->get_Media_Type() << endl;
		cout << "Item replacement cost: " << setw(24) << right << fixed << iter->second->get_Price() << endl; 

		// print values specific to the Videogames class	
		if(iter->second->get_Media_Type() == "Videogame")
		{
			cout << "Videogame's Platform: " << setw(25) << right << static_cast<Videogames*>(iter->second)->get_Platform() << endl;
			cout << "Videogame's Rating: " << setw(27) << right << static_cast<Videogames*>(iter->second)->get_Rating() << endl;
			cout << "Videogame's Developer: "<< setw(24) << right << static_cast<Videogames*>(iter->second)->get_Developer() << endl;
		}
		// print values specific to the DVD class
		else if(iter->second->get_Media_Type() == "DVD")
		{
			cout << "DVD's Director: " << setw(31) << right << static_cast<DVD*>(iter->second)->get_Director() << endl;
			cout << "DVD's Rating: " << setw(33) << static_cast<DVD*>(iter->second)->get_Rating() << endl;
			cout << "DVD's Actors: " << endl;
			cout << static_cast<DVD*>(iter->second)->get_Actors() << endl;
		}
		// print values specific to the Book class
		else if(iter->second->get_Media_Type() == "Book")
		{
			cout << "Book's Author: " << setw(32) << right << static_cast<Book*>(iter->second)->get_Author() << endl;
			cout << "Book's Publisher: " << setw(29) << right << static_cast<Book*>(iter->second)->get_Publisher() << endl;
			cout << "Book's Publish Date: " << setw(26) << right << static_cast<Book*>(iter->second)->get_Publish_Date() << endl;
		}
		cout << endl;
	}

	return;
}
/*
Name:		Save_Items
Parameters:	
Return:
Description:	This function is used to save all of the objects in the LibraryItems map
*/
void Library_Items::Save_Items()
{
	ofstream out; // output stream object

	out.open("Items.txt"); // open the file

	// check if the file opened correctlye
	if(out.fail())
	{
		// display message if the file failed to open and exit
		cout << "Failed to open the file.\n";
		exit(EXIT_FAILURE);
	}
	else
	{
		// the file opened correctly
		map<int, Library_Item*>::iterator iter; // iterator for map
		
		out << LibraryItems.size() << endl; // print the size to the file
	
		// loop through the map and print out the base class values
		for(iter = LibraryItems.begin(); iter != LibraryItems.end(); iter++)
		{
			out << iter->second->get_Media_Type() << endl;
			out << iter->second->get_ID() << endl;
			out << iter->second->get_Avail() << endl;
			out << iter->second->get_Loan_Period() << endl;
			out << iter->second->get_Price() << endl;
			out << iter->second->get_Title() << endl;

			// print values specific to the videogame class
			if(iter->second->get_Media_Type() == "Videogame")
			{
				out << static_cast<Videogames*>(iter->second)->get_Rating() << endl;
				out << static_cast<Videogames*>(iter->second)->get_Platform() << endl;
				out << static_cast<Videogames*>(iter->second)->get_Developer() << endl;
			}
			// print values specific to the DVD class
			else if(iter->second->get_Media_Type() == "DVD")
			{
				out << static_cast<DVD*>(iter->second)->get_Rating() << endl;
				out << static_cast<DVD*>(iter->second)->get_Director() << endl;
				out << static_cast<DVD*>(iter->second)->get_Actors() << endl;
			}
			// print values specific to the Book class
			else if(iter->second->get_Media_Type() == "Book")
			{
				out << static_cast<Book*>(iter->second)->get_Author() << endl;
				out << static_cast<Book*>(iter->second)->get_Publisher() << endl;
				out << static_cast<Book*>(iter->second)->get_Publish_Date() << endl;
			}
		}
	}

	return;
}
/*
Name:		Load_Items
Parameters:
Return:
Description:	This function is used to read and save objects from an input file
*/
void Library_Items::Load_Items()
{
	int size, id; // the size of the saved map and the ID of the Item
	string temp; // string values

	ifstream in; // input stream object

	in.open("Items.txt"); // open the file

	// check if the file opened correctly
	if(in.fail())
	{
		// the file could not be loaded so display message and exit
		cout << "Failed to open the file.\n";
		exit(EXIT_FAILURE);
	}
	else
	{
		// the file opened correctly so read in the size for the for loop
		in >> size;

		// run for loop
		for(int i = 0; i < size; i++)
		{
			// read in a string to determine what type of object to read
			in >> temp;
		
			// read a Videogame
			if(temp == "Videogame")
			{
				Videogames *newGame; // declare pointer
			
				newGame = read_Game(in, temp); // call read function

				// read in the ID and save the object to the LibraryItems map
				id = newGame->get_ID(); 
				LibraryItems[id] = newGame;
			}
			// read a DVD
			else if(temp == "DVD")
			{
				DVD *newDVD; // declare pointer

				newDVD = read_DVD(in, temp); // call function to read in a DVD

				id = newDVD->get_ID(); // Get the ID and save the object to the map
				LibraryItems[id] = newDVD;
			}
			// read in a book
			else if(temp == "Book")
			{
				Book *newBook; // declare a pointer

				newBook = read_Book(in, temp); // call function to read a Book

				// get the new ID and save the object to the map
				id = newBook->get_ID();
				LibraryItems[id] = newBook;
			}
		}	
	}

	return;
}
/*
Name:		Delete
Parameters:
Return:
Description:	This function is used to delete the objects in the LibraryItems map
*/
void Library_Items::Delete()
{
	// call function to clear map
	LibraryItems.clear();
	return;
}
/*
Name:		set_ID
Parameters:	an int representing the objects new ID
Return:
Description:	This function is used to set the ID of a Library_Item object
*/
void Library_Item::set_ID(int id)
{
	// assign the ID
	ID = id;
	return;
}
/*
Name:		get_ID
Parameters:
Return:		an int representing the ID of an object
Description:	This function is used to return the ID of an object
*/
int Library_Item::get_ID()
{
	return ID;
}
/*
Name:		set_Avail
Parameters:	an int representing the availability of the object
Return:
Description:	This function is used to assing the Avail attribute to the parameter
*/
void Library_Item::set_Avail(int state)
{
	Avail = state;

	return;
}
/*
Name:		get_Avail
Parameters:
Return:		an int representing the objects availability
Description:	this function is used to return an objects Avail attribute
*/
int Library_Item::get_Avail()
{
	return Avail;
}
/*
Name:		set_Title
Parameters:	a string representing the objects title
Return:
Description:	this function is used assign the Title attribute to the paramete
*/
void Library_Item::set_Title(string title)
{
	Title = title;

	return;
}
/*
Name:		get_Title
Parameters:
Return:		a string representing an objects title
Description:	this function is used to return the title of an object
*/
string Library_Item::get_Title()
{
	return Title;
}
/*
Name:		set_Loan_Period
Parameters:	an int representing the amount of time that an object is allows to be
		loaned
Return:	
Description:	this function is used to assign the Loan_Period to the parameter
*/
void Library_Item::set_Loan_Period(int amount)
{
	Loan_Period = amount;

	return;
}
/*
Name:		get_Loan_Period
Parameters:	
Return:		an int representing the amount of time that an object is alloweed to be
		loaned
Description:	this function is used to return the Loan_period attribute
*/
int Library_Item::get_Loan_Period()
{
	return Loan_Period;
}
/*
Name:		set_Media_Type
Parameters:	a string representing the type of object
Return:
Description:	this function is used to assign the Media_Type attribute to the parameter
*/
void Library_Item::set_Media_Type(string type)
{
	Media_Type = type;

	return;
}
/*
Name:		get_Media_Type
Parameters:	
Return:		a string representing the type of object
Description:	this function is used to return an object's Media_Type
*/
string Library_Item::get_Media_Type()
{
	return Media_Type;
}
/*
Name:		set_Price
Parameters:	a double representing the replacement cost for an object
Return:		
Description:	this function is used to assign the Item_Price attribute	
*/
void Library_Item::set_Price(double price)
{
	Item_Price = price;

	return;
}
/*
Name:		get_Price
Parameters:
Return:		a double that represents an objects replacement cost
Description:	this function is used to return an objects Item_Price
*/
double Library_Item::get_Price()
{
	return Item_Price;
}
/*
Name:		set_Director
Parameters:	a string representing a DVD's director
Return:
Description:	this function is used to assign the Director attribute
*/
void DVD::set_Director(string director)
{
	Director = director;

	return;
}
/*
Name:		get_Director
Parameters:	
Return:		a string representing a DVD's director
Description:	this function is used to return a DVD's director
*/
string DVD::get_Director()
{
	return Director;
}
/*
Name:		set_Actors
Parameters:	a string representing the actors for a DVD
Return:	
Description:	this function is used to assign the Actors attribute of a DVD
*/
void DVD::set_Actors(string actors)
{
	Actors = actors;

	return;
}
/*
Name:		get_Actors
Parameters:
Return:		a string representing a DVD's actors
Description:	this function is used to return the Actors attribute
*/
string DVD::get_Actors()
{
	return Actors;
}
/*
Name:		set_Rating
Parameters:	a string representing a DVD's rating
Return:
Description:	this function is used to assign the Ratings attribute
*/
void DVD::set_Rating(string rating)
{
	Rating = rating;

	return;
}
/*
Name:		get_Rating
Parameters:
Return:		a string representing a DVD objects rating
Description:	this function is used to return the Rating attribute
*/
string DVD::get_Rating()
{
	return Rating;
}
/*
Name:		set_Platform
Parameters:	a string representing a Videogame's platform
Return:
Description:	this function is used to assign the Platform attribute for an object
*/
void Videogames::set_Platform(string platform)
{
	Platform = platform;
	return;
}
/*
Name:		get_Platform
Parameters:
Return:		a string representing the Platform of a Videogame object
Description:	this function is used to return the Platform of an object
*/
string Videogames::get_Platform()
{
	return Platform;
}
/*
Name:		set_rating
Parameters:	a string representing the rating of a Videogame object
Return:	
Description:	this function is used to assign the Rating attribute
*/
void Videogames::set_Rating(string rating)
{
	Rating = rating;
	return;
}
/*
Name:		get_Rating
Parameters:	
Return:		a string representing a Videogame object's rating
Description:	this function is used to return the Rating of a Videogame object
*/
string Videogames::get_Rating()
{
	return Rating;
}
/*
Name:		set_Developer
Parameters:	a string representing a Videogame's developer
Return:
Description:	this function is used to assign the Developer attribute to the parameter
*/
void Videogames::set_Developer(string dev)
{
	Developer = dev;

	return;
}
/*
Name:		get_Developer
Parameters:
Return:		a string representing a Videogame's Developer attribute
Description:	this function is used to return the Developer attribute
*/
string Videogames::get_Developer()
{
	return Developer;
}
/*
Name:		set_Author
Parameters:	a string representing the name of an author
Return:	
Description:	This function is used to set the author a book object
*/
void Book::set_Author(string author)
{
	// set author to the parameter
	Author = author;
	return;
}
/*
Name:		get_Author
Parameters:
Return:		a string representing a Book's author
Description:	this function is used to return the Author attribute of a Book object
*/
string Book::get_Author()
{
	return Author;
}
/*
Name:		set_Publisher
Parameters:	a string representing the publisher of a book
Return:
Description:	this function is used to assign the Publisher attribute
*/
void Book::set_Publisher(string publisher)
{
	Publisher = publisher;

	return;
}
/*
Name:		get_Publisher
Parameters:	
Return:		a string representing the publiser of a book
Description:	this function is used to return the Publisher attribute
*/
string Book::get_Publisher()
{
	return Publisher;
}
/*
Name:		set_Publish_Date
Parameters:	a string representing the publishing date
Return:	
Description:	this function is used to assign the Publish_Date attribute
*/
void Book::set_Publish_Date(string date)
{
	Publish_Date = date;
	
	return;
}
/*
Name:		get_Publish_Date
Parameters:
Return:		a string representing a book's publishing date
Description:	this function is used to return a book's publish date
*/
string Book::get_Publish_Date()
{
	return Publish_Date;
}
