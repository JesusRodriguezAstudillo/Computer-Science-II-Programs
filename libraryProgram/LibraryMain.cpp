#include "libraries.h"
#include "functions.h"

int main()
{
	// declare class objects
	Patrons Patronlist;
	Loans Loanlist;
	Library_Items Itemlist;

	// declare struct object
	Library_Values ValueList;
	
	// initialize struct values
	ValueList.BookLoanPeriod = ValueList.DVDLoanPeriod = ValueList.VideogameLoanPeriod = 0;
	ValueList.BookFee = ValueList.DVDFee = ValueList.VideogameFee = 0;
	
	int selection = -1; // the menu selection

	// display the header
	header();

	cout << "\t*Make sure to set up the loan periods and overdue fees for\n";
	cout << "\t the items first unless you have information to load.\n\n";

	// do while loop to display menu
	do
	{
		cout << "\t(0) Exit the Program\n";
		cout << "\t(1) Set or Change Loan Periods and Fees\n"; //Add a do this first
		cout << "\t(2) Add a New Item to the Library\n";
		cout << "\t(3) Edit Item Information\n";
		cout << "\t(4) Remove an Item\n";
		cout << "\t(5) Mark an Item as Lost\n";
		cout << "\t(6) Print Item Catalog\n";
		cout << "\t(7) Register a New Patron\n";
		cout << "\t(8) Edit Patron information\n";
		cout << "\t(9) Remove Patron\n";
		cout << "\t(10) Print All Patrons and Their Information\n";
		cout << "\t(11) Print Patron Address Labels\n";
		cout << "\t(12) Print All Patrons with Fines\n";
		cout << "\t(13) Pay Fine\n";
		cout << "\t(14) Loan an Item\n";
		cout << "\t(15) Return a Loaned Item\n";
		cout << "\t(16) Print All Overdue Items\n";
		cout << "\t(17) Print All Current Loans\n";
		cout << "\t(18) Save Information\n"; 
		cout << "\t(19) Load Information\n";
		cout << "Selection: ";
		cin  >> selection; // user selection

		// switch for menu input
		switch(selection)
		{
			case 0:
				break;
			case 1:
				SetLibraryValues(ValueList);
				break;
			case 2:
				Itemlist.Add_LibraryItem(ValueList);
				break;
			case 3:
				Itemlist.Edit_Information(Loanlist);
				break;
			case 4:
				Itemlist.Remove_Item();
				break;
			case 5:
				Itemlist.Mark_Lost_Item(Loanlist, Patronlist);
				break;
			case 6:
				Itemlist.PrintItems();
				break;
			case 7:
				Patronlist.Add_Patron(Patronlist);
				break;
			case 8:
				Patronlist.Edit_Information();
				break;
			case 9:
				Patronlist.Remove_Patron();
				break;
			case 10:
				Loanlist.Update_Date(Itemlist, Patronlist);
				Patronlist.Print_Names();
				break;
			case 11:
				Patronlist.Print_Addresses();
				break;
			case 12:
				Loanlist.Update_Date(Itemlist, Patronlist);
				Patronlist.Print_Fines();
				break;
			case 13:
				Patronlist.Payment();
				break;
			case 14:
				Loanlist.Loan_Item(Itemlist, Patronlist, ValueList);
				break;
			case 15:
				Loanlist.Update_Date(Itemlist, Patronlist);
				Loanlist.Return_Item(Itemlist, Patronlist);
				break;
			case 16:
				Loanlist.Print_OverdueItems(Itemlist, Patronlist);
				break;
			case 17:
				Loanlist.Print_LoanInfo(Itemlist, Patronlist);
				break;
			case 18:
				SaveLibraryValues(ValueList);
				Itemlist.Save_Items();
				Patronlist.Save_Patrons();
				Loanlist.Save_Loans();
				cout << "All the information has been saved.\n";
				break;
			case 19:
				LoadLibraryValues(ValueList);
				Itemlist.Load_Items();
				Patronlist.Load_Patrons();
				Loanlist.Load_Loans();
				cout << "All the information has been loaded.\n";
				break;
			default:
				cout << "The selection that you entered is not valid.\n";
		}
	}while(selection !=0);	

	// clear the maps
	Patronlist.Delete();
	Loanlist.Delete();
	Itemlist.Delete();

	return 0;
}
