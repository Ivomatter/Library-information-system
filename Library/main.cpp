#include <fstream>
#include <cstdlib>

#include "Application.h"
#include "Book.h"
#include "User.h"
#include "Helpers.h"
#include "Serializable.h"
#include "FileController.h"



int main() {
	Book::generateBooksFile(BOOKS_FILE);

	//FileController control;
	//control.loadBooks();
	////control.showAllBooks();
	//control.showBookDetails(27);
	//control.showBookDetails(13);

	Application app;
	app.run();
	/*ifstream in(BOOKS_FILE, std::ios::binary);
	Serializable* book = Serializable::readSerializable(in);
	in.close();

	book->printDetails();*/


	
	

}