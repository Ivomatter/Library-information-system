#pragma once

#include <string>

using std::string;


const string BOOK_OBJECT_SIGNATURE = "Book";
const string USER_OBJECT_SIGNATURE = "User";

const int MIN_USER_ARGS = 2;
const int MIN_BOOK_ARGS = 4;

const string SALT_PREFIX = "o()$jf";
const string SALT_SUFFIX = "@*V*,.[b{";

const string BOOKS_FILE = "books.dat";
const string USERS_FILE = "users.dat";
const string EXIT_STRING = "exit";