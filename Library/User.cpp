#include "User.h"
#include "./OOP-sha512/SHA512.h"


void User::copy(const User& other)
{
    _userName = other._userName;
    _password = other._password;
    _isAdmin = other._isAdmin;
}

User& User::operator=(const User& other)
{
    if (this != &other) {
        copy(other);
    }
    return *this;
}

void User::generateUsersFile()
{
    User u1("admin", "admin", true);
    User u2("guest", "guest");

    ofstream out(USERS_FILE, std::ios::out | std::ios::binary);
    u1.serialize(out);
    u2.serialize(out);

    out.close();
}

bool User::serialize(ofstream& out)
{
    if (!(writeStringToBinary(USER_OBJECT_SIGNATURE, out)
        && writeStringToBinary(_userName, out)
        && writeStringToBinary(_password, out))) {
        throw "Error writing to file!";
    }

    out.write((char*)&_isAdmin, sizeof(bool));

    return out.good();
}

bool User::deserialize(ifstream& in)
{
    if (!(readStringFromBinary(_userName, in)
        && readStringFromBinary(_password, in))) {
        throw "Error reading from file!";
    }

    in.read((char*)&_isAdmin, sizeof(bool));

    return in.good();
}

bool User::readUser(ifstream& in, User& user)
{
    string serializable;
    Serializable::readStringFromBinary(serializable, in);
    if (serializable != USER_OBJECT_SIGNATURE) {
        throw "Invalid file contents";
        return false;
    }
    user.deserialize(in);
    return in.good();
}

void User::printDetails() const 
{
    this->printForAll();
    if (_isAdmin) std::cout << "Admin" << '\n';
    else std::cout << "User" << '\n';
    printNewline();
}

void User::printForAll() const
{
    std::cout << _userName << '\n';
    std::cout << _password << '\n';
}

void User::clear()
{
    _userName.clear();
    _password.clear();
    _isAdmin = false;
}
