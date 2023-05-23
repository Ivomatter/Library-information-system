#pragma once
#include <iostream> 
#include <vector>

using std::ostream;
using std::vector;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
    for (int i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i != v.size() - 1)
            os << " ";
    }
    os << "\n";
    return os;
}



