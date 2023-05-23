#include "Book.h"
Book::Book()
{
	_author.reserve(16);
	_title.reserve(16);
	_genre.reserve(16);
	_description.reserve(16);
	_year = 2023;
	_tags.reserve(4);
	_rating = 0;
	_id = 0;
}
//
Book::Book(const string& author, const string& title, const string& genre, const string& desc, const unsigned year, const vector<string>& tags, const double rating, unsigned id)
{
	_author = author;
	_title = title;
	_genre = genre;
	_description = desc;
	_year = year;
	_tags = tags;
	_rating = rating;
	_id = id;
}

bool Book::serialize()
{
	std::ofstream out("jeff.dat", std::ios::out | std::ios::binary);
	if (!out) {
		std::cout << "Error in loading file!";
		return 0;
	}
	out.write((char*)this, sizeof(this));
	out.close();
}


