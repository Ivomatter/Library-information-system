#pragma once

#include "Serializable.h"


class SerializableFactory
{
public:
	static Serializable* generate(const string signature);
};

