#include <iostream>
#include <string>
#include <map>
#include <exception>
#include <sstream>
#include <fstream>
#include <cmath>
#include <filesystem>

using namespace std;

map<int, size_t> hoidla;
void ruutvõrrand(string);
void ÜL1();
void ÜL2();

template <typename T>
class NegatiivneDeterminant : public exception {
private:
    string m_s;
    T m_arv;
public:
    NegatiivneDeterminant(string s, T arv) : m_s{s}, m_arv{arv} {};
    string getSõnum() const {return m_s;}
    T getArv() const {return m_arv;}
};

template <typename T>
T determinant(T a, T b, T c) {
    //cout << "a: " << a << " b: " << b << " c: " << c << endl;
    try {
    T väljund = b * b - 4 * a * c;
    if (väljund < 0) {
        throw NegatiivneDeterminant<T>("Negatiivne determinant", väljund);
    }
    return väljund;
    } catch (const NegatiivneDeterminant<T>& e) {
        cout << e.getSõnum() << ": " << e.getArv() << endl;
        cout << "Reaalarvulist lahendit ei leidu!" << endl;
        return -1;
    }
}