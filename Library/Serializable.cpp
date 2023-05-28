#include "Serializable.h"
#include "SerializableFactory.h"

bool Serializable::writeStringToBinary(const string& str, ofstream& out)
{
    size_t size = str.size();
    int pos = out.tellp();
    out.write((char*)&size, sizeof(size));
    out.write((char*) & str[0], size);
    return (out.good());
}

bool Serializable::readStringFromBinary(string& str, ifstream& in)
{
    size_t size;
    in.read((char*) & size, sizeof(size_t));
    int pos = in.tellg();
    str.resize(size);
    in.read((char*) & str[0], size);
    return (in.good());
}

Serializable* Serializable::readSerializable(ifstream& in)
{
    string signature;
    if (!readStringFromBinary(signature, in)) {
        return nullptr;
    }

    Serializable* serializable = SerializableFactory::generate(signature);
    serializable->deserialize(in);

    return serializable;
};
