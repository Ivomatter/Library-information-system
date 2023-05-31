#pragma once
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

