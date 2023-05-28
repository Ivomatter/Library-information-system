#include "SerializableFactory.h"
#include "User.h"
#include "Book.h"

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
