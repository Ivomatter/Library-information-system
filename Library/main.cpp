#include <fstream>
#include <cstdlib>

#include "Application.h"
#include "Book.h"
#include "User.h"
#include "Helpers.h"
#include "Serializable.h"
#include "FileController.h"
#include "./OOP-sha512/SHA512.h"



int main() {
	//User::generateUsersFile();
	Application app;
	app.run();
	
	return 0;
}



/*
	The books loaded by default:

	"John Michaels", "COOL BOOK", "COMEDY", "The greatest book ever", 2010, { "super", "cool reading", "book" }, 4.5, 27
	"Andy Rillins", "Book about Magic", "Adventure", "Magic", 2002, { "magic", "friendship" }, 9.5, 24
	"Oliver Dann", "The Depth", "Action", "Action", 2017, { "action" }, 1.7, 23
	"Mark Irivine", "Hell and Heaven", "Drama", "Book about the lifecycle", 2007, { "drama", "hell", "heaven" }, 2.7, 13
	"Tamara Neil", "Fancy book", "Comedy", "Comedy books", 2011, { "fancy tag" }, 5.6, 14
	
	*/