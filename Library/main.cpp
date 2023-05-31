#include <fstream>
#include <cstdlib>

#include "Application.h"
#include "Book.h"
#include "User.h"
#include "Helpers.h"
#include "Serializable.h"
#include "FileController.h"
#include "SHA512.h"

int main() {

	/*Application app;
	app.run();*/

	string hi = "Hello!";

	string output = sha512(hi);
	string output2 = sha512("abc" + hi + "def");
	std::cout << output << '\n';
	std::cout << output2;
	
	return 0;
	
	

}