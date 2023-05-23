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
	ofstream out("books.dat", std::ios::out | std::ios::binary);
	if (!out) {
		throw "File open error!";
		return -1;
	}

	if (!(writeStringToBinary(_author, out)
		&& writeStringToBinary(_title, out)
		&& writeStringToBinary(_genre, out)
		&& writeStringToBinary(_description, out))) {
			throw "Failed to write to file!";
			return -1;
		}
	
	out.write((char*)&_year, sizeof(_year));

	size_t size = _tags.size();
	out.write((char*)&size, sizeof(size_t));
	for (string tag : _tags) {
		if (!writeStringToBinary(tag, out)) {
			throw "Failed to write to file!";
		}
	}

	out.write((char*)&_rating, sizeof(_rating));
	out.write((char*)&_id, sizeof(_id));

}

bool Book::deserialize()
{
	ifstream in("books.dat", std::ios::in | std::ios::binary);
	if (!in) {
		throw "Failed to open file!";
		return -1;
	}
	if (!(readStringFromBinary(_author, in)
		&& readStringFromBinary(_title, in)
		&& readStringFromBinary(_genre, in)
		&& readStringFromBinary(_description, in))) {
			throw "Failed to read from file!";
			return -1;
	}

	in.read((char*)&_year, sizeof(_year));
	
	size_t size;
	in.read((char*)&size, sizeof(size));
	_tags.resize(size);
	for (size_t i = 0; i < size; ++i)
	{
		if (!readStringFromBinary(_tags[i], in)) {
			throw "Failed to read from file!";
			return -1;
		}
	}

	in.read((char*)&_rating, sizeof(_rating));
	in.read((char*)&_id, sizeof(_id));


}

void Book::printDetails() const
{
		this->printForAll();
		std::cout 
			<< "Year: " << _year << '\n' 
			<< "Tags: ";
		for (string tag : _tags)
		{
			std::cout << tag << ' ';
		}

		std::cout << '\n' 
				  << "Rating: " << _rating << '\n' 
				  << "Id: " << _id << '\n';
}

void Book::printForAll() const
{
		std::cout 
			<< "Author: " << _author << '\n' 
			<< "Title: " << _title << '\n' 
			<< "Genre: " << _genre << '\n' 
			<< "Description: " << _description << '\n';
}


