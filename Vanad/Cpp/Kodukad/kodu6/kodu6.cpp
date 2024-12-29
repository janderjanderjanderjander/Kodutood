#include "andmed.h"

#if !defined(VPL_TEST)
int main() {
    //Loeb
    vector<Auto*>* autode_vektor = loeAutod("autod.txt");
    //Kuvab ekraanile
    for (size_t i{}; i < (*autode_vektor).size(); i++) {
        cout << (*(*autode_vektor)[i]);
    }
    //Vähim kk
    Auto* vähim = vähima_kuluga(autode_vektor);
    cout << "V2hima k6tusekulu auto:\n" << (*vähim);
    //kustutamine
    kustutaAutod(autode_vektor);
    delete autode_vektor;
    return 1;

}
#endif