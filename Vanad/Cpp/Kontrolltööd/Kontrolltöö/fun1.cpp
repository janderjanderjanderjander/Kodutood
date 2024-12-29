#include "fun1.h"

double punkte(string nimede_mass[], int punktide_mass[], int el_mass, string nimi) {
    double count{};
    for (int i{}; i < el_mass; i++) {
        if (nimede_mass[i] == nimi) {
            count += punktide_mass[i];
        }
    }
return count;
}

string parim(string nimede_mass[], int punktide_mass[], int el_mass) {
    vector<string> temp;
    int suurim{};
    string kes{};
    for (int i{}; i < el_mass; i++) {
        if (count(temp.begin(), temp.end(), nimede_mass[i]) == 0) {
            if (punkte(nimede_mass, punktide_mass, el_mass, nimede_mass[i]) > suurim) {
                suurim = punkte(nimede_mass, punktide_mass, el_mass, nimede_mass[i]);
                kes = nimede_mass[i];
            }
            temp.push_back(nimede_mass[i]);
        }
    }
    return kes;
}

