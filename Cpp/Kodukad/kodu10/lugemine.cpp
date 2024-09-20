#include "lugemine.h"


int main() {
    /*Ül 1
    set<Hoia> s1{};
    s1 = loe_hoia("andmed.txt", s1);
    for (auto el : s1) {
        cout << el << ' ';
    }
    */

   map<string, int> m{};
   loe_failist("andmed.txt", m);
   for (const auto& pair : m) {
    cout << pair.first << " : " << pair.second << endl;
   }


    return 1;
}
