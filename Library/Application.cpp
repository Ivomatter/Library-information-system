#include "Application.h"

Application::Application()
{
	control.loadBooks();
	//control.loadUsers();

	_input = "";
	while (_input != EXIT_STRING) {
		std::cin >> _input;

	}
}
