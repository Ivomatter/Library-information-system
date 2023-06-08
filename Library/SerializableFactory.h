#pragma once

//Factory helping to create FileControllers for any serializabe class

#include <vector>
#include <string>

#include "Serializable.h"	

using std::vector;



class SerializableFactory
{
public:
	static Serializable* generate(const string signature);
	
	static Serializable* generateWithParameters(const string signature, vector<string>& argv);
};

