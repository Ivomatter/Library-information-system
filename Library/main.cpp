#include <fstream>

#include "Application.h"
#include "Book.h"
#include "User.h"
#include "Helpers.h"
#include "Serializable.h"
#include "FileController.h"


int main() {
	Book::generateBooksFile();

	FileController control;
	control.loadBooks();
	control.showAllBooks();

	

	/*Book b1;
	Book b2;

	ifstream in(BOOKS_FILE, std::ios::binary);
	b1.deserialize(in);
	b2.deserialize(in);
	in.close();
	
	b1.printForAll();
	b2.printForAll();

	Book b3;
	b3 = b1;

	b3.printForAll();*/
}