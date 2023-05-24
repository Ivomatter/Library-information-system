#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "Serializable.h"
#include "Constants.h"

using std::string;
using std::vector;

//default empty tag list
//vector<string> tags = {};

class Book : Serializable
{
private:
	string _author;
	string _title;
	string _genre;
	string _description;
	unsigned _year;
	vector<string> _tags;
	double _rating;
	unsigned _id;

	void copy(const Book& other);
public:
	Book();
	Book(const string& author,const string& title, const string& genre, const string& desc, const unsigned year,const vector<string>& tags, const double rating, unsigned id);
	Book& operator=(const Book& other);
	
	static bool generateBooksFile();

	bool serialize(ofstream& out) override final;
	bool deserialize(ifstream& in) override final;

	void printDetails() const;
	void printForAll() const;
	

	//friend std::ostream& operator<<(std::ostream& out, const Book& obj);
	//friend std::istream& operator>>(std::istream& in, Book& obj);	
};


