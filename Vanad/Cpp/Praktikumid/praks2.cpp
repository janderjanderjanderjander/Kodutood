#include <iostream>
using namespace std;

void ruutjuur() {
    float sisestus{};
    float r{};
    cin >> sisestus;
    auto alg = sisestus / 2;
    for (int i{}; i < 20; ++i) {
        if (i > 0) {
            alg = (alg + r) / 2;
        }
        r = sisestus / alg;
        cout << "Ruutjuure väärtus: " << alg << "\n";
    }

}

int main() {
    ruutjuur();
}