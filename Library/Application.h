#pragma once
#include <sstream>
#include <cstdlib>

#include "FileController.h"
#include "Constants.h"


	
class Application
{
private:
	vector<string> _command;
	FileController _booksController;
	FileController _usersController;	
	//User currentUser;
public:
	Application() : _booksController(BOOKS_FILE), _usersController(USERS_FILE) {};

	void run();

	void executeCommand();

	void booksCommand(vector<string>& command);
	void helpCommand(vector<string>& command);
	void openCommand(vector<string>& command);
	void closeCommand();
	void saveAsCommand(vector<string>& command);

	void showBooksInfo(string bookId);

	void showUnknownCommandPrompt();
};
