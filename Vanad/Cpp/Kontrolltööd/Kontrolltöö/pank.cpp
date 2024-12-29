#include "pank.h"

ostream& operator<<(ostream& os, const Ylekanne& ylekanne) {
    os << ylekanne.p_allikas << ";" << ylekanne.p_siht << ";" << ylekanne.p_summa << ";" << ylekanne.kinnitus << endl;
    return os;
}

Ylekanne* Pank::looYlekanne(uint64_t allikas, uint64_t siht, double summa) {
    Ylekanne* ül_ptr = new Ylekanne(allikas, siht, summa);
    (*ülekande_ptr).push_back(ül_ptr);
    return ül_ptr;
}

void Pank::salvestaLog(Ylekanne* ülekande_ptr) {
    cout << "Salvestamine logisse: " << 
}