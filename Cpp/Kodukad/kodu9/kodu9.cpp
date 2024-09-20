#include "kodu9.h"

void lisaJaKustuta(vector<string>& v) {
    auto algus = v.begin();
    auto lõpp = v.end();
    lõpp--;
    algus--;
    while (algus != lõpp) {
        //cout << "Hetkel olen sõna " << (*lõpp) << " juures" << endl;
        if ((*lõpp).find("tt") != string::npos || (*lõpp).find("at") != string::npos) {   
            v.erase(lõpp);
            lõpp--;
        }else if ((*lõpp).find("aa") != string::npos || (*lõpp).find("oo") != string::npos || (*lõpp).find("uu") != string::npos) {
            v.insert(lõpp, (*lõpp));
            lõpp--;
        } else {
            lõpp--;
        }
    }
}


#if !defined(VPL_TEST)
int main() {
    vector<string> v{"Juuli", "lõpus", "ilmunud", "loost", "Water", "sai",
                "võrdlemisi", "salaja", "aasta",  "oluliseim", "hitt"};
    for (auto it{v.begin()}, lopp{v.end()}; it != lopp ; ++it) {
        cout << *it << " ";
    }
    cout << "\n";
    lisaJaKustuta(v);
    for (auto it{v.begin()}, lopp{v.end()}; it != lopp ; ++it) {
    cout << *it << " ";
    }

}
#endif