#include "libraries.h"

class Library_Item
{
	private:
		int ID; // The library items ID number
		int Avail; // the availability of the item
		string Title; // the item's title
		int Loan_Period; // The amount of time that the item is allowed to be loned before being overdue
		string Media_Type; // the item's media type 
		double Item_Price; // the item's price
	public:
		// function declarations
		void set_ID(int id);
		int get_ID();
		void set_Avail(int state);
		int get_Avail();
		void set_Title(string title);
		string get_Title();
		void set_Loan_Period(int amount);
		int get_Loan_Period();
		void set_Media_Type(string type);
		string get_Media_Type();
		void set_Price(double price);
		double get_Price();
};

class DVD : public Library_Item
{
	private:
		string Director; // The DVD's director
		string Actors; // The DVD's actor
		string Rating; // The DVD's rating
	public:
		// function declarations
		void set_Director(string director);
		string get_Director();
		void set_Actors(string actors);
		string get_Actors();
		void set_Rating(string rating);
		string get_Rating();
};

class Videogames : public Library_Item
{
	private:
		string Platform; // The videogame's available platforms
		string Rating; // the videogames rating
		string Developer; // the videogames developer studio
	public:
		// function declarations
		void set_Platform(string platform);
		string get_Platform();
		void set_Rating(string rating);
		string get_Rating();
		void set_Developer(string dev);
		string get_Developer();
};

class Book : public Library_Item
{
	private:
		string Author; // the book's author
		string Publisher; // the book's publisher
		string Publish_Date; // the book's publishing date
	public:
		// function declarations
		void set_Author(string author);
		string get_Author();
		void set_Publisher(string publisher);
		string get_Publisher();
		void set_Publish_Date(string date);
		string get_Publish_Date();
};

class Library_Items
{
	private:
		map<int, Library_Item*> LibraryItems; // map to hold all library items
	public:
		// function declarations
		void Add_LibraryItem(struct Library_Values values);
		void Add_Videogame(struct Library_Values values);
		void Add_DVD(struct Library_Values values);
		void Add_Book(struct Library_Values values);
		void Edit_Information(class Loans Loanlist);
		void Remove_Item();
		void Mark_Lost_Item(class Loans &Loanlist, class Patrons Patronlist);
		bool Check_ID(int id);
		void Change_Availability(int id, int status);
		int Get_Availability(int id);
		int Get_Loan_Period(int id);
		string Get_MediaType(int id);
		string Get_Title(int id);
		void Save_Items();
		void Load_Items();
		void PrintItems();
		void Delete();
};

class Patron
{
	private:
		string Name; // the patron's name
		string Address; // the patron's address
		string Email; // the patron's email
		double Balance; // the patron's balance
		string Phone_Number; // the patron's phone number
		int ID; // the patron's id
		int Loaned; // an int representing the amount of loans
	public:
		// function declarations
		void get_Name(string name);
		string display_Name();
		void get_Address(string address);
		string print_Address();
		void set_Email(string email);
		string get_Email();
		void set_Balance(double balance);
		double show_Balance();
		void set_Phone(string phone);
		string get_Phone();
		void get_ID(int id);
		int check_ID();
		void set_Loaned(int num);
		int show_Loaned();
		void add_Loaned(int num);
		void Add_Balance(double amount);
		friend ostream& operator <<(ostream& out, Patron& patron);
		friend istream& operator >>(istream& in, Patron& patron);
};

class Patrons
{
	private:
		map<int, Patron*> Patron_List; // the patron map to hold all patrons
		map<string, int> Patron_Names; // the patron map to hold all patrons in alphabetical order
	public:
		// function declarations
		void Add_Patron(Patrons &Patronlist);
		void Remove_Patron();
		void Edit_Information();
		void Delete();
		bool check_ID(int ID);
		void Print_Names();
		void Print_Addresses();
		string Get_Name(int id);
		void Add_Loaned(int id, int num);
		void Change_Balance(int id, double amount);
		void Print_Fines();
		void Payment();
		void Save_Patrons();
		void Load_Patrons();
};

class Loan
{
	private:
		int Patron_ID; // the patron's id
		int Item_ID; // the item's id
		time_t Due_Date; // the due date for the loan
		double Fee; // the fee for the item
		int Fined_Status; // an int representing whether a patron has been fined for a loan
	public:
		// function declarations
		void set_PatronID(int ID);
		void set_ItemID(int id);
		int get_ItemID();
		void set_Fee(double fee);
		double get_Fee();
		int get_PatronID();
		void set_Due_Date(int LoanPeriod);
		time_t show_Due_Date();
		void set_Fined_Status(int num);
		int show_Fined_Status();
		friend ostream& operator <<(ostream& out, Loan& loan);
		friend istream& operator >>(istream& in, Loan& loan);
};

class Loans
{
	private:
		map<int, Loan*> Loan_ListB; // the Loan map to hold all loans
	public:
		// function declarations
		void Loan_Item(Library_Items &Itemlist, Patrons &Patronlist, struct Library_Values values);
		void Return_Item(Library_Items &Itemlist, Patrons &Patronlist);
		void Print_OverdueItems(Library_Items Itemlist, Patrons Patronlist);
		void Update_Date(Library_Items &Itemlist, Patrons &Patronlist);
		bool Check_Loan(int id);
		int PatronID(int id);
		void Remove_Loan(int id);
		void Delete();
		void Save_Loans();
		void Load_Loans();
		void Print_LoanInfo(Library_Items Itemlist, Patrons Patronlist);
};

struct Library_Values
{
	int BookLoanPeriod; // loan period for a book
	double BookFee; // fee per day for an overdue book
	int DVDLoanPeriod; // loan period for a DVD
	double DVDFee; // fee per day for an overdue DVD
	int VideogameLoanPeriod; // loan period for a videogame
	double VideogameFee; // fee per day for an overdue videogame
};
