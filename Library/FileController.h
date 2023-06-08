#pragma once

//Handles the file loading of any Serializable inherited class

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
	
	void showAll() const;
	bool showBookDetails(const unsigned id);

	bool openFile(string fileToOpen);
	bool save() const;
	bool saveAs(string targetFileName) const;
	bool close();

	bool isOpen() const;

	void freeItemList();
	void reopen();

	bool add(Serializable* newItem);

	vector<Serializable*>& getItemList() { return _fileItemList; };
	size_t getFileSize(ifstream& in) const;
	size_t size()const ;
};

