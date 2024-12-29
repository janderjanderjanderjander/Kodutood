#ifndef KODU9_H
#define KODU9_H

#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

template <typename T1, typename T2, typename T3>
void yhenda(T1& alg1, T2& alg2, T3& tulem) {
    for (auto el : alg1) {
        tulem.push_back(el);
    }
    for (auto el : alg2) {
        tulem.push_back(el);
    }
}

template <typename T>
ostream& tryki(T& alg, ostream & os) {
    for (auto el : alg) {
        os << el << " ";
    }
    os << endl;
return os;
}

template <typename T>
bool operator<(T& esimene, T& teine) {
    double essa_summa;
    double teise_summa;
    for (auto el : esimene) {
        essa_summa += el;
    }
    for (auto el : teine) {
        teise_summa += el;
    }
    return (essa_summa < teise_summa);
}

void lisaJaKustuta(vector<string>&);







#endif