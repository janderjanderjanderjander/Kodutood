#include "fun1.h"

void fun1() {
    int punktid[]{3, 2, 3, 2};
    string nimed[]{"Post", "Dijkstra", "Post", "Valge"};
    cout << punkte(nimed, punktid, 4, "Post") << endl;
    cout << parim(nimed, punktid, 4) << endl;
}



int main() {
    //fun1();

    return 0;
}