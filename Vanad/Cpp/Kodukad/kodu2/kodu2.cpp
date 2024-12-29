#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>
#include <chrono>
#include <random>
#include <vector>
#include <algorithm>
using namespace std;

void kolmnurk() {
    auto tee_vahed = [](int vahe) {
        for (int j = 0; j < vahe; ++j) {
            cout << " ";
        };
    };
    auto tee_tärnid = [](int mitu) {
        for (int j = 0; j < mitu; ++j) {
            cout << "*";
        };
    };
    int h{};
    //cout << "Sisesta kolmnurga kõrgus: ";
    cin >> h;
    int vahe{h};
    int mitu{1};

    for (int i = 0; i < h; ++i) {
        vahe--;
        tee_vahed(vahe);
        tee_tärnid(mitu);
        //tee_vahed(vahe);
        cout << "\n";
        mitu += 2;
    };
}

void tabel() {
    float algus{};
    float samm{};
    float lõpp{};
    cout << "Sisesta algus: ";
    cin >> algus;
    float pounds{algus};
    cout << "Sisesta samm: ";
    cin >> samm;
    cout << "Sisesta lõpp: ";
    cin >> lõpp;
    cout << setw(7) << "Nael" << setw(10) << "Kg\n";
    cout << "-----------------\n";
    cout << right;
    while (true) {
        if (pounds > lõpp) {
            break;
        }
        float kg_ümardamata{pounds * 0.45359237f};
        float kg{round(kg_ümardamata * 100000) / 100000};
        cout << setw(7) << pounds << setw(10) << kg << "\n";
        pounds += samm;
        if (pounds == lõpp) {
            break;
        }
    }
    
}

void krediitkaart() {
    long long knumber{};
    int checknumber{};
    int summa{};
    int oppa{};
    int payload{};

    vector<int> numbrid;
    cin >> knumber; //17893729974
    while (knumber > 0) {
        int üks_number = knumber % 10;
        numbrid.push_back(üks_number);
        knumber /= 10;
    }
    for (int i = 0; i < numbrid.size() ; ++i) {
        int vot = numbrid[i];
        if (i == 0) {
            checknumber = vot;
            continue;
        }
        if (i % 2 == 0) {
            summa += vot;
        } else {
            oppa = 2 * vot;
            if (oppa >= 10) {
                if (oppa == 10) {
                    summa += 1;
                } else if (oppa == 12) {
                    summa += 3;
                } else if (oppa == 14) {
                    summa += 5;
                } else if (oppa == 16) {
                    summa += 7;
                } else {
                    summa += 9;
                }
                
            } else {
                summa += oppa;
            }
        }
    }

    for (int i = 0; i < 10; ++i) {
        int testimine = summa + i;
        if (testimine % 10 == 0) {
            payload = i;
        }
    }
    if (checknumber == payload) {
        cout << "korrektne\n";
    } else {
        cout << "vale\n";
    }
}

void blackjack() {
    vector<int> olnud_numbrid;
    int hetkel{};
    string valik{};
    while (true) {
        unsigned seeme = chrono::system_clock::now().time_since_epoch().count();
        uniform_int_distribution<int> distribution(2, 11);
        mt19937 generator(seeme);
        int lambine_arv = distribution(generator);
        int otsing = count(olnud_numbrid.begin(), olnud_numbrid.end(), lambine_arv);
        if (otsing < 4) {
            olnud_numbrid.push_back(lambine_arv);
            hetkel += lambine_arv;
            cout << "Tuli kaart: " << lambine_arv << " hetkeseis: "<< hetkel << "\n";
            if (hetkel >= 21) {
                break;
            }
            cout << "Kas soovid kaarti j/e?" << "\n";
            cin >> valik;
            if (valik == "j") {
                continue;
            } else {
                break;
            }
        } else {
                continue;
    }
    }
    if (hetkel > 21) {
        cout << "Kahjuks kaotasid.\n";
    } else if (hetkel == 21) {
        cout << "Võitsid.\n";
    } else {
        cout << "Lõppseis: " << hetkel << "\n";
    }

    

}


#if !defined(VPL_TEST)
int main() {
    // Testi oma funktsioone siin
    // kolmnurk();
    // tabel();
    // krediitkaart();
    // blackjack();
}
#endif