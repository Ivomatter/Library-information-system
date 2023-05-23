#pragma once
class Serializable
{
public:
	virtual bool serialize() = 0;
	virtual bool deserialize() = 0;
};

