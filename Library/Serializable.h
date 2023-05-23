#pragma once

#include <fstream>
#include <string>

using std::string;
using std::ofstream;
using std::ifstream;

//const string FILE_NAME = "example.txt";



class Serializable
{
public:
	bool writeStringToBinary(string& str, ofstream& out);
	bool readStringFromBinary(string& str, ifstream& in);


	virtual bool serialize() = 0;
	virtual bool deserialize() = 0;
};

