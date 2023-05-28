#pragma once

#include "Book.h"
#include "User.h"
#include "Helpers.h"

class FileController
{
private:
	string _fileName;
	bool _isFileOpen;
	vector<Serializable*> _fileItemList;

public:
	FileController() : _isFileOpen(false) {};
	FileController(string fileName) : _isFileOpen(false), _fileName(fileName) {};
	
	void showAllBooks() const;
	bool showBookDetails(const unsigned id);

	bool openFile();
	bool save() const;
	bool saveAs(string targetFileName) const;
	bool close();

	void freeItemList();

	size_t getFileSize(ifstream& in);
};

