#include "mängija.h"
#include "master.h"

string Mängija::get_kaart(int i) const {
    if (kaardid[i] > 10) {
        return pildid.at(kaardid[i]);
    } else {
        return to_string(kaardid[i]);
    }
}
void Mängija::kuva() {
    if (kaardid.empty()) {
        cout << "Mängijal pole kaarte" << endl;
    } else {
        cout << "Mängijal on: " << kaardid[0] << " ja " << kaardid[1] << endl;
        cout << "Summa on: " << summa << endl;
    }
}
void Mängija::lisa_kaart(int kaartA) {
    kaardid.push_back(kaartA);
    if (kaartA < 11) {
        summa += kaartA;
    } else {
        summa += 10;
    }
}
void Mängija::fold() {
    kaardid.clear();
    summa = 0;
}

ostream& operator<<(ostream& os, const Mängija& mängija) {
    for (size_t i{}; i < mängija.kaardid.size(); i++) {
        if (mängija.get_diiler() && i == 0) {
            os << "X" << " ";
        } else {
        os << mängija.get_kaart(i) << " ";
        }
    }
    return os;
}