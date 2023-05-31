#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>


#include "Serializable.h"
#include "Constants.h"
#include "Helpers.h"
#include "./OOP-sha512/SHA512.h"

using std::string;


class User : public Serializable
{
private:
	string _userName;
	string _password;
	bool _isAdmin;

	void copy(const User& other);
public:
	User() : _isAdmin(false) { _userName.reserve(16); _password.reserve(16); };
	User(string name, string password) :			   _userName(name), _password(sha512(SALT_PREFIX + password + SALT_SUFFIX)), _isAdmin(false) {};
	User(string name, string password, bool isAdmin) : _userName(name), _password(sha512(SALT_PREFIX + password + SALT_SUFFIX)), _isAdmin(isAdmin) {};
	
	User& operator=(const User& other);

	static void generateUsersFile();
	//TODO: Define the following override functions for class User
	bool serialize(ofstream& out) override final;
	bool deserialize(ifstream& in) override final;

	static bool readUser(ifstream& in, User& user);

	void printDetails() const override final;
	void printForAll() const override final;

	bool checkForDetails(const unsigned id) const override final { return true; };

	string getName() override final { return _userName; };
	string getPassword() { return _password; };
	bool isAdmin() { return _isAdmin; };

	void clear();
	
};

