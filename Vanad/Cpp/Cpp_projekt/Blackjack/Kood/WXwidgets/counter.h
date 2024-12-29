#pragma once

#include <map>
#include <vector>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class Counter
{
private:
    int running{};
    vector<int> maas{};
    int peidetud_kaart{};
    map<int, double> v�imalus;
public:
    Counter();
    int get_running() { return running; }
    void lisa_peidetud(int n) { peidetud_kaart = n; }
    void peidetud_n�ita() { maas.push_back(peidetud_kaart); }
    void laual_kaart(int);
    void uuenda_v�imalusi();
    void kuva_v�imalused();
    void unusta_k�ik();
};


