#include "UserRegister.h"

UserRegister::UserRegister(vector<Serializable*>& serializableVector, string fileName)
{
	_fileName = fileName;
	ifstream in(_fileName, std::ios::binary);

	for (size_t i = 0; i < serializableVector.size(); ++i) {
		User temp;
		User::readUser(in, temp);
		_userList.push_back(temp);
	}

	in.close();
}

bool UserRegister::loginCheck(string& user, string& pass, User& currentUser)
{
	for (size_t i = 0; i < _userList.size(); ++i)
	{
		if (_userList[i].getName() == user) {
			if (_userList[i].getPassword() == pass) {
				std::cout << "Successfully logged in!";
				currentUser = _userList[i];
				return true;
			}
			else {
				std::cout << "Wrong password!";
			}
			return false;
		}
	}
	std::cout << "Invalid credentials!";
	return false;
}

void UserRegister::removeUser(string userToRemove)
{
	for (size_t i = 0; i < _userList.size(); ++i) {
		if (_userList[i].getName() == userToRemove) {
			_userList.erase(_userList.begin() + i);
			std::cout << "User deleted successfully.";
			serializeUserList();
			return;
		}
	}
	std::cout << "No user with name " << userToRemove << " found.";
}

void UserRegister::serializeUserList()
{
	ofstream out(USERS_FILE, std::ios::binary);

	for (User user : _userList) {
		user.serialize(out);
	}
}
