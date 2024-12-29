#include "arvutused.h"
#include <cmath>
#include <iostream>
using namespace std;

int suurim(int* a, int* b, int* c) {
    int max{};
    max = *a;
    if (max < *b) {
        max = *b;
    };
    if (max < *c) {
        max = *c;
    };
    return max;
}
int suurim(int& a, int& b, int& c) {
    int max{};
    max = a;
    if (max < b) {
        max = b;
    };
    if (max < c) {
        max = c;
    };
    return max;
}
int suurim(int& a, int* b, int* c) {
    int max{};
    max = a;
    if (max < *b) {
        max = *b;
    };
    if (max < *c) {
        max = *c;
    };
    return max;
}
void suurim(int* a, int* b, int* c, int* suurim) {
    (*suurim) = *a;
        (*suurim) = *a;
    if ((*suurim) < *b) {
        (*suurim) = *b;
    };
    if ((*suurim) < *c) {
        (*suurim) = *c;
    };
}
void suurim(int& a, int& b, int& c, int& suurim_arv) {
    (suurim_arv) = a;
        (suurim_arv) = a;
    if ((suurim_arv) < b) {
        (suurim_arv) = b;
    };
    if ((suurim_arv) < c) {
        (suurim_arv) = c;
    };
}
