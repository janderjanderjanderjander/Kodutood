#include "andmed.h"
using namespace std;

//Ül 1
int* loo_andmed(int a) {
    if (a < 1) {
        return nullptr;
    } else {
        int* massiiv = new int[a];
        srand((unsigned)time(0));
        for (int i{}; i < a; i++) {
            int rand_arv = rand();
            massiiv[i] = rand_arv;
        }
        return massiiv;
    }
}

vector<int>* loe_andmed(string* failinimi) {
    vector<int>* vektor_ptr = new vector<int>{};
    ifstream file(*failinimi);
    string line;
    while(getline(file, line)) {
        size_t algus = 0;
        size_t lõpp = 0;
        char lahutaja = ' ';
        for (size_t i{}; i <= line.size(); i++) {
            if (line[i] == lahutaja or i == line.size()) {
                lõpp = i;
                string snumber{};
                snumber.append(line, algus, lõpp - algus);
                int number = stoi(snumber);
                (*vektor_ptr).push_back(number);
                algus = i + 1;
            }
        }
    }
    file.close();
    return vektor_ptr;
    }
// - - - - -
void tootle_andmeid(int* massiivi_ptr, int suurus) {
    double summa{};
    for (int i{}; i < suurus; i++) {
        summa += massiivi_ptr[i];
    }
    cout << "Summa: " << summa << endl;
    cout << "Keskmine: " << summa/suurus << endl;
    for (int i{}; i < suurus; i++) {
    massiivi_ptr[i] *= -1;
    }
}
// - - - - -
void tootle_andmeid_vektoris(vector<int>* vektor) {
    double summa{};
    int count{};
    for (size_t i{}; i < (*vektor).size(); i++) {
        double converted = static_cast<double>(i);
        summa += converted;
        count += 1;
    }
    cout << "Summa: " << summa << endl;
    cout << "Keskmine: " << summa / count << endl;
}

void kustuta_andmed(int* massiivi_ptr, vector<int>* vektori_ptr) {
    delete (massiivi_ptr);
    delete (vektori_ptr);
}

//Ül2

Auto::Auto() {}
Auto::Auto(string mark, string klass, double kulu) {
    auto_mark = mark;
    energia_klass = klass;
    kütuse_kulu = kulu;
}
double Auto::kytusekulu() {
    return kütuse_kulu;
}

Auto* looAuto(const string rida) {
    stringstream ss(rida);
    string sõna;
    vector<string> sõnad;
    while (getline(ss, sõna, ';')) {
        sõnad.push_back(sõna);
    }
    double kütusekulu = stod(sõnad[2]);
    Auto* masina_ptr = new Auto(sõnad[0], sõnad[1], kütusekulu);
    return masina_ptr;
}

vector<Auto*>* loeAutod(const string fail) {
    vector<Auto*>* vektori_ptr = new vector<Auto*>;
    ifstream fail_obj(fail);
    string rida;
    while (getline(fail_obj, rida)) {
        (*vektori_ptr).push_back(looAuto(rida));
    }
    fail_obj.close();
    return vektori_ptr;
}

Auto* vähima_kuluga(vector<Auto*>* autod) { // {auto_ptr1, auto_ptr2}
    double hetkel_vähim_kütusekulu{10000000};
    Auto* auto_obj_ptr;
    for (size_t i{}; i < (*autod).size(); i++ ) {
        if ((*autod)[i]->kytusekulu() < hetkel_vähim_kütusekulu) {
            hetkel_vähim_kütusekulu = (*autod)[i]->kytusekulu();
            auto_obj_ptr = (*autod)[i];
        }
    }
    return auto_obj_ptr;
}

void kustutaAutod(vector<Auto*>* autod) {
    for (size_t i{}; i < (*autod).size(); i++ ) {
        delete (*autod)[i];
    }
}

ostream& operator<<(ostream& os, const Auto& masin) {
    os << "Mark: " << masin.auto_mark << "\nEnergia klass: " << masin.energia_klass << "\nK6tusekulu: " << masin.kütuse_kulu << "\n- - - - - - -" << endl;
    return os;
}

Auto::~Auto() {
    cout << Auto::auto_mark << " destruktoris" << endl;
}
