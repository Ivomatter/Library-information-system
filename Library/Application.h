#pragma once
#include <sstream>
#include <cstdlib>

#include "FileController.h"
#include "Constants.h"


	
class Application
{
private:
	string _input;
	vector<string> command;
	FileController control;
	//User currentUser;
public:
	Application();

	void executeCommand();
	void booksCommand(vector<string> command);

	void showHelpMessage(string commandError);
	void noIdMessage();
};
