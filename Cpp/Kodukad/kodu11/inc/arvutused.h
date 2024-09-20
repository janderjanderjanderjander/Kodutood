#ifndef ARVUTUSED_H
#define ARVUTUSED_H

int suurim(int*, int*, int*);
int suurim(int&, int&, int&);
int suurim(int&, int*, int*);
void suurim(int*, int*, int*, int*); //neljas parameeter on suurima jaoks
void suurim(int&, int&, int&, int&); //neljas parameeter on suurima jaoks

template <typename T>
T tSuurimP(T* a, T* b, T* c) {
    T max{};
    max = *a;
    if (max < *b) {
        max = *b;
    };
    if (max < *c) {
        max = *c;
    };
    return max;
}

template <typename T>
T tSuurimR(T& a, T& b, T& c) {
    T max{};
    max = a;
    if (max < b) {
        max = b;
    };
    if (max < c) {
        max = c;
    };
    return max;
}
#endif