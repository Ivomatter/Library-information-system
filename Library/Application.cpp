#include "Application.h"

Application::Application()
{
	control.loadBooks();
	//control.loadUsers();


	while (true) {

		//Displays prompt and reads user input
		_input = readline("> ");

		////Checks for EOF
		if (!_input) {
			break;
		}

		printf("%s", _input);


		free(_input);
	}
}
