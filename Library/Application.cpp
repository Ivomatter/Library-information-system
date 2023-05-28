#include "Application.h"



void Application::run()
{
	string input;
	_booksController.openFile();
	//control.loadUsers();


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
}

void Application::executeCommand()
{
	if (_command[0] == "exit")
		exit(0);
	else if (_command[0] == "books") {
		booksCommand(_command);
	}
	else if (_command[0] == "help") {
		helpCommand(_command);
	}
	else {
		showUnknownCommandPrompt();
	}

	printNewline();
	return;
}

void Application::booksCommand(vector<string> _command)
{
	//If the command is only "Books", print help message.
	if (_command.size() == 1) {
		showUnknownCommandPrompt();
		return;
	}
	if (_command[1] == "all") {
		_booksController.showAllBooks();
		return;
	}

	/*if (_command.size() < 3) {
		showUnknownCommandPrompt();
	}*/
	if (_command[1] == "info") {
		if (_command.size() == 2) {
			std::cout << "Please specify book id.";
			return;
		}
		showBooksInfo(_command[2]);	
	}
	else {
		showUnknownCommandPrompt();
	}
	
}

void Application::helpCommand(vector<string> command)
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

