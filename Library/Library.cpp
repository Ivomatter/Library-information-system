#include "Library.h"
#include <algorithm>


Library::Library(vector<Serializable*>& serializableVector, string fileName)
{
	_fileName = fileName;
	ifstream in(_fileName, std::ios::binary);

	for (size_t i = 0; i < serializableVector.size(); ++i) {
		Book temp;
		Book::readBook(in, temp);
		_bookList.push_back(temp);
	}

	in.close();
}

void Library::findBook(vector<string> command)
{
	string toFind = "";
	for (size_t i = 3; i < command.size(); i++)
	{
		toFind += command[i];
		if (i + 1 != command.size())
			toFind += ' ';
	}
	transform(toFind.begin(), toFind.end(), toFind.begin(), ::tolower);

	if (command[2] == "title") {
		for (Book book : _bookList) {
			string title = book.getTitle();
			transform(title.begin(), title.end(), title.begin(), ::tolower);
			if (title == toFind)
				book.printDetails();
		}
	}
	else if (command[2] == "author") {
		for (Book book : _bookList) {
			string author = book.getAuthor();
			transform(author.begin(), author.end(), author.begin(), ::tolower);
			if (author == toFind)
				book.printDetails();
		}
	}
	else if (command[2] == "tag") {
		for (Book book : _bookList) {
			for (string tag : book.getTags()) {
				transform(tag.begin(), tag.end(), tag.begin(), ::tolower);
				if (tag == toFind) {
					book.printDetails();
					break;
				}
			}
		}
	}
	else
		std::cout << "Invalid option for find.";
}
