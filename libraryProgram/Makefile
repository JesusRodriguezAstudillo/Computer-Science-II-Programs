Library: LibraryMain.o Functions.o ItemFunc.o PatronFunc.o LoanFunc.o
	g++ -o Library LibraryMain.o Functions.o ItemFunc.o PatronFunc.o LoanFunc.o

LibraryMain.o: LibraryMain.cpp libraries.h functions.h
	g++ -c LibraryMain.cpp

Functions.o: Functions.cpp libraries.h functions.h
	g++ -c Functions.cpp

ItemFunc.o: ItemFunc.cpp libraries.h functions.h
	g++ -c ItemFunc.cpp

PatronFunc.o: PatronFunc.cpp libraries.h functions.h
	g++ -c PatronFunc.cpp

LoanFunc.o: LoanFunc.cpp libraries.h functions.h
	g++ -c LoanFunc.cpp
