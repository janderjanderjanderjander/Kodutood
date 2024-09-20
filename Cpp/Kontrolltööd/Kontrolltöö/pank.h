#ifndef PANK_H
#define PANK_H
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

class Ylekanne
{
private:
    uint64_t p_allikas;
    uint64_t p_siht;
    double p_summa;
public:
    Ylekanne(uint64_t, uint64_t, double);
    ~Ylekanne();
    bool kinnitus();
    friend ostream& operator<<(ostream& os, const Ylekanne& ylekanne);
};
Ylekanne::Ylekanne(uint64_t allikas, uint64_t siht, double summa) {
    p_allikas = allikas;
    p_siht = siht;
    p_summa = summa;
}
Ylekanne::~Ylekanne()
{
}

class Pank
{
private:
    string nimi;
    vector<Ylekanne*>* ülekande_ptr;
public:
    Pank(string);
    ~Pank();
    Ylekanne* looYlekanne(uint64_t, uint64_t, double);
    void salvestaLog(Ylekanne*);
    void saabuvYlekanne(Ylekanne*);
    void lopeta();
    void kuva();

};

Pank::Pank(string panga_nimi) {
    nimi = panga_nimi;
}

Pank::~Pank()
{
}

#endif