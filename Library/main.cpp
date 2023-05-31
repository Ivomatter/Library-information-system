#include <fstream>
#include <cstdlib>

#include "Application.h"
#include "Book.h"
#include "User.h"
#include "Helpers.h"
#include "Serializable.h"
#include "FileController.h"
#include "./OOP-sha512/SHA512.h"



int main() {
	//User::generateUsersFile();
	Application app;
	app.run();
	/*ifstream in(USERS_FILE, std::ios::binary);
	Serializable* user = Serializable::readSerializable(in);
	user->printDetails();*/
	
	return 0;
}