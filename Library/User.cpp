#include "User.h"

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