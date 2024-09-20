#ifndef LUGEMINE_H
#define LUGEMINE_H

#include <iostream>
#include <string>
#include <set>
#include <fstream>
#include <map>
using namespace std;


//Ülesanne 1
class Hoia
{
private:
    string hoian{};
public:
    Hoia(string);
    friend ostream& operator<<(ostream& os, const Hoia& obj) {
        os << obj.hoian;
        return os;
    }
    bool operator<(const Hoia& other) const {
        return hoian < other.hoian;
    }
};

Hoia::Hoia(string arg) {
hoian = arg;
}


set<Hoia>& loe_hoia(string failinimi, set<Hoia>& st) {
    ifstream fail;
    fail.open(failinimi);

    string sona;
    while (fail >> sona) {
        Hoia objekt(sona);
        st.insert(objekt);
    }
    return st;
}


//Ülesanne 2
template<typename T1, typename T2>
map<T1, T2>& loe_failist(string failinimi, map<T1, T2>& m) {
    ifstream fail;
    fail.open(failinimi);

    string sona;
    while (fail >> sona) {
        for (size_t i{}; i < sona.length(); ++i) {
            if (ispunct(sona[i])) {
                sona.erase(i, 1);
                i--;
            } else if (isupper(sona[i])) {
                sona[i] = static_cast<char>(tolower(sona[i]));
            }
        }
        ++m[sona];
    }
    return m;
}

#endif

