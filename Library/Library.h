#pragma once

#include "Book.h"

class Library
{
private:
	vector<Book> _bookList;
	string _fileName;
public:
	Library() {};
	Library(vector<Serializable*>& serializableVector, string fileName);

	void findBook(vector<string> command);
};

