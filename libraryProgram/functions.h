#include "classes.h"

// function declarations
void header();
void SetLibraryValues(Library_Values &ValueList);
void SaveLibraryValues(Library_Values ValueList);
void LoadLibraryValues(Library_Values &ValueList);
Videogames* read_Game(ifstream& in, string type);
DVD* read_DVD(ifstream& in, string type);
Book* read_Book(ifstream& in, string type);
