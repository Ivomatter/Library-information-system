#include "SerializableFactory.h"
#include "User.h"
#include "Book.h"

const int MIN_USER_ARGS = 2;
const int MIN_BOOK_ARGS = 4;


Serializable* SerializableFactory::generate(const string signature)
{
    Serializable* serializable = nullptr;

    if (signature == BOOK_OBJECT_SIGNATURE)
        serializable = new Book();
    else if (signature == USER_OBJECT_SIGNATURE)
        serializable = new User();
    else
        throw "Invalid object signature \"" + signature + "\" !";

    return serializable;
}

Serializable* SerializableFactory::generateWithParameters(const string signature, vector<string>& argv)
{
    Serializable* serializable = nullptr;

    if (signature == USER_OBJECT_SIGNATURE && argv.size() >= MIN_USER_ARGS)
        serializable = new User(argv[0], argv[1]);
    else if (signature == BOOK_OBJECT_SIGNATURE && argv.size() >= MIN_BOOK_ARGS)
        serializable = new Book(argv[0], argv[1], argv[2], argv[3]);
    else
        throw "Invalid object signature \"" + signature + "\" !";

    return serializable;

}
