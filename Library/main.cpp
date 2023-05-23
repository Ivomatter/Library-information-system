#include <fstream>

#include "Application.h"
#include "Book.h"
#include "User.h"
#include "Helpers.h"
#include "Serializable.h"



int main() {

	/*Application app;
	app.run();*/

	Book b1("John Michaels", "COOL BOOK", "COMEDY", "The greatest book ever", 2010, { "super", "cool reading", "book" }, 4.5, 27);
	Book b2;

	b1.serialize();
	b2.deserialize();
	
	b2.printDetails();

}