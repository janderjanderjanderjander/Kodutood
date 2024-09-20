#include "counter.h"

Counter::Counter() {
    double odds;
    for (int i{ 2 }; i <= 11; i++) {
        if (i == 10) {
            odds = (16 / 52) * 100;
            võimalus[i] = round(odds * 10.0) / 10.0;
        }
        else {
            odds = (4 / 52) * 100;
        }
        võimalus[i] = round(odds * 10.0) / 10.0;
    }
}
void Counter::laual_kaart(int kaart) {
    if (kaart < 7) {
        running++;
    }
    else if (kaart > 9) {
        running--;
    }
    maas.push_back(kaart);
}
void Counter::uuenda_võimalusi() {
    int count_kogu = maas.size();
    for (int i{ 2 }; i <= 11; i++) {
        double odds{};
        int count{};

        if (i < 10 || i == 11) {
            for (int value : maas) {
                if (value == i) {
                    count++;
                }
            }
            odds = (4.0 - count) / (52.0 - count_kogu) * 100.0;
        }
        else {
            for (int value : maas) {
                if (value >= 10 && value < 14) {
                    count++;
                }
            }
            odds = (16.0 - count) / (52.0 - count_kogu) * 100.0;
        }
        võimalus[i] = round(odds * 10.0) / 10.0;
    }
}
void Counter::kuva_võimalused() {
    uuenda_võimalusi();
    cout << " --------------------\n";
    cout << "| Vaartus | Voimalus |\n";
    cout << "|--------------------|\n";
    double sum{};
    for (const auto& pair : võimalus) {
        cout << "| " << setw(3) << pair.first << " | " << setw(11) << setprecision(7) << pair.second << " %|\n";
        sum += pair.second / 100.0;
    }
    cout << " --------------------\n";
    //sum = round(sum * 10.0) / 10.0;
    //sum *= 100;
    //cout << "Kokku: " << sum << endl;
}
void Counter::unusta_kõik() {
    maas.clear();
    peidetud_kaart = 0;
    running = 0;
}
