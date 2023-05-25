#pragma once

#include "FileController.h"
#include "Constants.h"
#include "readline/readline.h"
#include "readline/history.h"

class Application
{
private:
	string _input;
	FileController control;
	//User currentUser;
public:
	Application();
};

