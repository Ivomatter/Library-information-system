#pragma once

#include <fstream>
#include <string>
#include <vector>

#include "Serializable.h"

using std::string;


class User : public Serializable
{
private:
	string _userName;
	string _password;
	bool _isAdmin;
public:
	User() : _isAdmin(false) { _userName.reserve(16); _password.reserve(16); };
	User(string name, string password) :			   _userName(name), _password(password), _isAdmin(false) {};
	User(string name, string password, bool isAdmin) : _userName(name), _password(password), _isAdmin(isAdmin) {};
	
	//TODO: Define the following override functions for class User
	bool serialize(ofstream& out) override final;
	bool deserialize(ifstream& in) override final;

	void printDetails() const override final {};
	void printForAll() const override final {};

	bool checkForDetails(const unsigned id) const override final { return true; };
};

