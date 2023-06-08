#include "Application.h"
#include <conio.h>
#include <algorithm>

const char ENTER = 13;
const char BACK_SPACE = 8;
const char TAB = '\t';
const string INSUFFICIENT_PARAMTETERS_MESSAGE = "Insufficient parameters.";

void Application::run()
{
	_usersController.openFile(USERS_FILE);

	string input;

	while (true) {
		getline(std::cin, input);
		std::stringstream ss(input);

		while (getline(ss, input, ' ')) {
			_command.push_back(input);
		}

		if (!_command.empty())
			executeCommand();

		_command.clear();
	}
	_usersController.close();
}

void Application::executeCommand()
{
	// Let the initial command be case insensitive by making it lowercase
	transform(_command[0].begin(), _command[0].end(), _command[0].begin(), ::tolower);
	// 
	if (_command[0] == "exit")
		exit(0);
	else if (_command[0] == "login") {
		loginCommand();
	}
	else if (_command[0] == "logout") {
		logoutCommand();
	}
	else if (_command[0] == "books") {
		booksCommand(_command);
	}
	else if (_command[0] == "help") {
		helpCommand(_command);
	}
	else if (_command[0] == "open") {
		openCommand(_command);
	}
	else if (_command[0] == "close") {
		_booksController.close();
	}
	else if (_command[0] == "save") {
		_booksController.save();
	}
	else if (_command[0] == "saveas") {
		saveAsCommand(_command);
	}
	else if (_command[0] == "users") {
		userCommand(_command);
	}
	else {
		showUnknownCommandPrompt();
	}
	printNewline();
	return;
}

void Application::loginCommand()
{
	if (_isUserLoggedIn) {
		std::cout << "Already logged in!";
		return;
	}
	string user;
	string password;

	std::cout << "Enter username: ";
	std::cin >> user;
	std::cout << "Enter password: ";
	password = getPass();

	password = sha512(SALT_PREFIX + password + SALT_SUFFIX);

	UserRegister userRegister(_usersController.getItemList(), USERS_FILE);

	_isUserLoggedIn = userRegister.loginCheck(user, password, _currentUser);
}

void Application::logoutCommand()
{
	if (!_isUserLoggedIn) {
		std::cout << "No active user.";
		return;
	}
	_currentUser.clear();
	_isUserLoggedIn = false;
	std::cout << "Logged out successfully.";
}

void Application::booksCommand(vector<string>& _command) {

	if (_command.size() == 1) {
		showUnknownCommandPrompt();
		return;
	}
	if (!_isUserLoggedIn) {
		std::cout << "Access denied.";
		return;
	}
	if (!_booksController.isOpen()) {
		std::cout << "No book file loaded.";
		return;
	}
	if (_command[1] == "all") {
		_booksController.showAll();
		return;
	}
	else if (_command[1] == "info") {
		if (_command.size() == 2) {
			std::cout << "Please specify book id.";
			return;
		}
		showBooksInfo(_command[2]);	
	}
	else if (_command[1] == "add") {
		if (!_currentUser.isAdmin()) {
			std::cout << "Access denied.";
			return;
		}
		Serializable* temp = SerializableFactory::generate(BOOK_OBJECT_SIGNATURE);
		temp->setAll();
		_booksController.add(temp);
		return;
	}
	else if (_command[1] == "find") {
		if (_command.size() < 4) {
			std::cout << INSUFFICIENT_PARAMTETERS_MESSAGE;
		}
		findCommand(_command);
	}
	else
	showUnknownCommandPrompt();
}

void Application::helpCommand(vector<string>& command)
{
	if (command.size() == 1) {
		std::cout << "List of avaliable commands:" << '\n';
		std::cout << ">login" << '\n';
		std::cout << ">logout" << '\n';
		std::cout << '\n';
		std::cout << ">open\n- opens a file for editing or creates a file for editing" << '\n';
		std::cout << ">save\n- saves contents to opened file" << '\n';
		std::cout << ">saveas\n- save contents to specified file" << '\n';
		std::cout << ">close\n- closes file" << '\n';
		std::cout << '\n';
		std::cout << ">books all\n- displays information about all loaded books" << '\n';
		std::cout << ">books info <id>\n- displays information about book with id" << '\n';
		std::cout << ">books find <option> <option_string>\n- displays book info by criteria" << '\n';
		std::cout << ">books sort <option> <option_string>\n- sorts by option and order respectively"<< '\n';
		std::cout << '\n';
		std::cout << ">users add <user> <password>\n- creates new user" << '\n';
		std::cout << ">users remove <user>\n- deletes user" << '\n';
		std::cout << "exit\n- exits the program" << '\n';
		return;
	}
}

void Application::findCommand(vector<string>& command) {
	if (command.size() < 3) {
		std::cout << INSUFFICIENT_PARAMTETERS_MESSAGE;
		return;
	}

	Library bookLibrary(_booksController.getItemList(), BOOKS_FILE);
	bookLibrary.findBook(command);
}

void Application::openCommand(vector<string>& command)
{
	if (command.size() == 1) {
		std::cout << "Please specify file." << std::endl;
		return;
	}
	_booksController.openFile(command[1]);
	if (!_booksController.isOpen()) {
		std::cout << "Failed to open file." << std::endl;
		return;
	}
	std::cout << "Successfully opened " << command[1] << std::endl;
}

void Application::closeCommand()
{
	_booksController.close();
}

void Application::saveAsCommand(vector<string>& command)
{
	if (command.size() == 1) {
		std::cout << "Please specify file.";
		return;
	}
	_booksController.saveAs(command[1]);
}

void Application::userCommand(vector<string>& command)
{
	if (!_currentUser.isAdmin()) {
		std::cout << "Access denied.";
		return;
	}
	if (command.size() == 1) {
		showUnknownCommandPrompt();
		return;
	}
	if (command[1] == "all") {
		_usersController.showAll();
		return;
	}
	else if (command[1] == "add") {
		if (command.size() < 4) {
			std::cout << INSUFFICIENT_PARAMTETERS_MESSAGE;
			return;
		}

		vector<string> argv = { command[2], command[3] };
		Serializable* temp = SerializableFactory::generateWithParameters(USER_OBJECT_SIGNATURE, argv);
		_usersController.add(temp);
		ofstream out(USERS_FILE, std::ios::binary | std::ios::app);
		temp->serialize(out);
		std::cout << "Successfully added user!";
	}
	else if (command[1] == "remove" && command.size() > 2) {
		UserRegister userRegister(_usersController.getItemList(), USERS_FILE);
		userRegister.removeUser(command[2]);
		_usersController.reopen();
	}
	else
		showUnknownCommandPrompt();
	
	return;
}


void Application::showBooksInfo(string bookId)
{
	char* endTest;
	unsigned id = strtol(bookId.c_str(), &endTest, 10);

	if (*endTest != '\0') {
		std::cout << "No book found with such id.";
		printNewline();
		return;
	}

	if (!_booksController.showBookDetails(id)) {
		std::cout << "No book found with such id.";
		printNewline();
		return;
	}
}

void Application::showUnknownCommandPrompt()
{
	std::cout << "Unknown command. For a list of commands, use \"help\".";
}


string Application::getPass() {
	int ch;
	string password;
	ch = _getch();
	while (ch != ENTER) {
		if (ch == BACK_SPACE) {
			if (password.size() > 0) {
				password.pop_back();
				std::cout << "\b \b";
			}
		}
		else if (ch == TAB) {}
		else {
			password.push_back(ch);
			std::cout << '*';
		}
		ch = _getch();
	}
	std::cout << std::endl;
	return password;
}