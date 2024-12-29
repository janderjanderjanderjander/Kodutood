#include "kodu13.h"

void ruutvõrrand(string sisestus) {
    istringstream stream(sisestus);
    int a, b, c;
    stream >> a >> b >> c;

    //cout << "a: " << a << " b: " << b << " c: " << c << endl;

    if (determinant(a, b, c) != -1) {
        cout << "Ruutvõrrandi lahendid on: ";
        cout << (-b + sqrt(b * b - 4 * a *c)) / 2 * a << " ja " << (-b - sqrt(b * b - 4 * a *c)) / 2 << endl;
    }
}

void ÜL1() {
    string x{};
    cout << "Sisesta täisarve, iga arv eraldi real:\n";
    while (true) {
        cin >> x;
        if (cin.eof()) {
            break;
        }
        try {
            int ix = stoi(x);
            hoidla[ix]++;
        } catch (const invalid_argument& e) {
            cerr << "Vigane sisend stoi\n";
        } catch (const out_of_range& e) {
            cerr << "Ei jää int piiridesse\n";
        } catch (...) {
            cerr << "Viga\n";
        }
    }
    cout << "Sisestatud täisarvude sagedused:\n";
    for (const auto& pair : hoidla) {
        cout << pair.first << " " << pair.second << endl;
    }
    return;


}

void ÜL2() {
    cout << "Sisesta failinimi, kui andmed on failis.\n";
    cout << "Kordajad on: ";
    string sisestus;
    getline(cin, sisestus);

    if (std::filesystem::exists(sisestus)) {
        int count{1};
        ifstream fail(sisestus);
        string rida;
        while (getline(fail, rida)) {
            cout << count << ". ruutvõrrand:\n";
            ruutvõrrand(rida);
            cout << endl;
            count++;
        }
    } else {
    ruutvõrrand(sisestus);
}}

int main() {
    //ÜL1();
    ÜL2();

    return 0;
}