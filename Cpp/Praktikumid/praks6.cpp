#include <iostream>
#include <memory>
using namespace std;

void uniq_test() {
    auto ptr = make_unique<int>(6);
    cout << *ptr << "\n";
}

int main() {
    uniq_test();
    return 0;
}