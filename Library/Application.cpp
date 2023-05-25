#include "Application.h"

Application::Application()
{
	control.loadBooks();
	//control.loadUsers();


	while (true) {


		getline(std::cin, _input);
		std::stringstream ss(_input);

		while (getline(ss, _input, ' ')) {
			command.push_back(_input);
		}

		/*for (string word : command) {
			std::cout << word << ' ';
		}*/

		if (!command.empty())
			executeCommand();
		
		command.clear();
	}
}

void Application::executeCommand()
{
	if (command[0] == "exit")
		exit(0);
	else if (command[0] == "books") {
		booksCommand(command);
	}
	else{
		std::cout << "Unknown command. For a list of commands, use \"help\".";
	}
	
	printNewline();
	return;
}

void Application::booksCommand(vector<string> command)
{
	if (command.size() == 1) {
		showHelpMessage(command[0]);
		return;
	}
	if (command[1] == "all") {
		control.showAllBooks();
		return;
	}
	if (command.size() < 3) {
		showHelpMessage(command[0]);
	}
	else if (command[1] == "info") {

		string strId = command[2];
		char* endTest;
		unsigned id = strtol(command[2].c_str(), &endTest, 10);

		if (*endTest != '\0') {
			noIdMessage();
			return;
		}

		if (!control.showBookDetails(id)) {
			noIdMessage();
			return;
		}
	}
	else {
		showHelpMessage(command[0]);
	}
	
}

void Application::noIdMessage() {
	std::cout << "No book found with such id.";
	printNewline();
}

void Application::showHelpMessage(string commandError)
{
	std::cout << "Incorrect syntax. For help, use \"help " << commandError << "\".";
	printNewline();
}
