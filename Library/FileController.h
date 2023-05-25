#pragma once

#include "Book.h"
#include "User.h"
#include "Helpers.h"

class FileController
{
private:
	vector<Book> _bookList;
	//vector<User> _userList;
public:
	FileController();
	
	bool loadBooks();
	void showAllBooks() const;

	void showBookDetails(const unsigned id);
};

