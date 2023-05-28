#include "FileController.h"



bool FileController::openFile()
{
	ifstream in(_fileName, std::ios::out | std::ios::binary);
	if (!in) {
		throw "Unable to open file!";
	}

	size_t fileSize = getFileSize(in);	

	
	while (in.tellg() < fileSize)
	{
		Serializable* temp = Serializable::readSerializable(in);
		_fileItemList.push_back(temp);
	}
	in.close();
	return in.good();
}

bool FileController::save() const
{
	return saveAs(_fileName);
}

bool FileController::saveAs(string targetFileName) const
{
	ofstream out(_fileName, std::ios::binary);
	if (!out) {
		throw "Failed to load file!";
		return false;
	}
	for (Serializable* serializable : _fileItemList) {
		serializable->serialize(out);
	}
	out.close();
	return out.good();
}

bool FileController::close()
{
	if (!_isFileOpen) {
		std::cout << "No file open!";
		return false;
	}
	_isFileOpen = false;
	freeItemList();
}

void FileController::freeItemList()
{
	_fileItemList.clear();
}

void FileController::showAllBooks() const
{
	for (Serializable* book : _fileItemList) {
		book->printForAll();
		printNewline();
	}
}

bool FileController::showBookDetails(const unsigned id)
{
	for (size_t i = 0; i < _fileItemList.size(); i++)
	{
		if (_fileItemList[i]->checkForDetails(id))
			return true;
	}
	return false;
	

}

size_t FileController::getFileSize(ifstream& in)
{
	in.seekg(0, SEEK_END);
	size_t fileSize = in.tellg();
	in.seekg(0, SEEK_SET);
	return fileSize;
}

