#pragma once

/*
	Application class handling the front end of the application,
	loading the files onto the memory and interacting with the lower level
	via FileControllers

*/


#include <sstream>
#include <cstdlib>

#include "FileController.h"
#include "Constants.h"
#include "SerializableFactory.h"
#include "UserRegister.h"
#include "Library.h"


	
class Application
{
private:
	vector<string> _command;
	FileController _booksController;
	FileController _usersController;

	User _currentUser;
	bool _isUserLoggedIn;
public:
	Application() : _booksController(BOOKS_FILE), _usersController(USERS_FILE), _isUserLoggedIn(false) {};

	void run();

	void executeCommand();

	void loginCommand();
	void logoutCommand();
	void booksCommand(vector<string>& command);
	void helpCommand(vector<string>& command);
	void findCommand(vector<string>& command);
	void openCommand(vector<string>& command);
	void closeCommand();
	void saveAsCommand(vector<string>& command);
	void userCommand(vector<string>& command);
	

	void showBooksInfo(string bookId);

	void showUnknownCommandPrompt();

	string getPass();
};
