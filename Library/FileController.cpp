#include "FileController.h"

FileController::FileController()
{
	_bookList.reserve(8);
	//_userList.reserve(5);
}

bool FileController::loadBooks()
{
	ifstream in(BOOKS_FILE, std::ios::out | std::ios::binary | std::ios::ate);
	if (!in) {
		throw "Unable to open file!";
	}

	size_t fileSize = in.tellg();
	in.seekg(0, SEEK_SET);

	int i = 0;
	while (in.tellg() < fileSize)
	{
		Book temp;
		temp.deserialize(in);
		_bookList.push_back(temp);
	}
	in.close();
	return in.good();
}

void FileController::showAllBooks() const
{
	for (Book book : _bookList) {
		book.printForAll();
		printNewline();
	}
}

bool FileController::showBookDetails(const unsigned id)
{
	for (size_t i = 0; i < _bookList.size(); i++)
	{
		if (_bookList[i].checkForDetails(id))
			return true;
	}
	return false;

}

