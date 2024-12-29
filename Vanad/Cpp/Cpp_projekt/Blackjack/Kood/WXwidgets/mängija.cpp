#include "m�ngija.h"
#include "master.h"

string M�ngija::get_kaart(int i) const {
    int kaart{};
    if (i == -1) {
        kaart = kaardid.back();
    }
    else {
        kaart = kaardid[i];
    }
    if (kaart > 10) {
        return pildid.at(kaart);
    }
    else {
        return to_string(kaart);
    }
}
void M�ngija::kuva() {
    if (kaardid.empty()) {
        cout << "M�ngijal pole kaarte" << endl;
    }
    else {
        cout << "M�ngijal on: " << kaardid[0] << " ja " << kaardid[1] << endl;
        cout << "Summa on: " << summa << endl;
    }
}
void M�ngija::lisa_kaart(int kaartA) {
    kaardid.push_back(kaartA);
    if (kaartA < 11) {
        summa += kaartA;
    }
    else {
        summa += 10;
    }
}
void M�ngija::fold() {
    kaardid.clear();
    summa = 0;
}

ostream& operator<<(ostream& os, const M�ngija& m�ngija) {
    for (size_t i{}; i < m�ngija.kaardid.size(); i++) {
        if (m�ngija.get_diiler() && i == 0) {
            os << "X" << " ";
        }
        else {
            os << m�ngija.get_kaart(i) << " ";
        }
    }
    return os;
}