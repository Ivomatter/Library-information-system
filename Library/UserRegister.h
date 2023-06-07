#pragma once

#include "User.h"


class UserRegister
{
private:
	vector<User> _userList;
	string _fileName;
public:
	UserRegister() {};
	UserRegister(vector<Serializable*>& serializableVector, string fileName);

	bool loginCheck(string& user, string& pass, User& currentUser);

	void removeUser(string userToRemove);

	void serializeUserList();
};

