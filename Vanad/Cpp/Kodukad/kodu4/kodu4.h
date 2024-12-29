#ifndef KODU4_H
#define KODU4_H

#include <concepts>
#include <iostream>
#include <string>
using namespace std;

// Mallifunktsioonid
//liida
template <typename T, typename U>
requires std::integral<T> || std::floating_point<T> || std::is_same<T, std::string>::value
 T liida(T a, U b) {
    return a + b;
 }

//on vahemikus
template <int T>
bool onVahemikus(int b, int c) {
    if (T >= b && T <= c) {
        return true;
    } else {
        return false;
    }
}

// Klass Massiiv
template<typename T>
requires std::integral<T> || std::floating_point<T>
class Massiiv {
    T m_massiiv[100]{};
    int kus_oleme{};
public:
    T getElement(int i){
        if(m_massiiv[i] != 0){
            return m_massiiv[i];
        } else {
            return -1111;
        }
    }
    bool kasTais(){
        for (int i{}; i < 100; i++) {
            if (m_massiiv[i] == 0) {
                return false;
            }
        }
        return true;
    }
    int getSuurus(){
        int mitu{};
        for (int i{}; i < 100; i++) {
            if (m_massiiv[i] != 0) {
                mitu++;
            }
        }
        return mitu;
    }
    void print() {
        for (int i{}; i < 100; i++) {
            if (m_massiiv[i] != 0) {
                cout << m_massiiv[i] << " ";
            }
        }
        cout << "\n";
    }
    void lisaElement(T el){
        m_massiiv[kus_oleme] = el;
        kus_oleme++;
    }
    void kustutaElement(){
        kus_oleme--;
        m_massiiv[kus_oleme] = 0;
    }
    void asendaElement(T el1, T el2){
        for (int i{}; i < 100; i++) {
            if (m_massiiv[i] != 0) {
                if (m_massiiv[i] == el1) {
                    m_massiiv[i] = el2;
                }
            }
        }
    }
    int vabuKohti(){
        int mitu{};
        for (int i{}; i < 100; i++) {
            if (m_massiiv[i] == 0) {
                mitu++;
            }
        }
        return mitu;
    }
    bool kasSisaldub(T el){
        for (int i{}; i < 100; i++) {
            if (m_massiiv[i] != 0) {
                if (m_massiiv[i] == el) {
                    return true;
                }
            }
        }
        return false;
    }
};


// NB! Oma koodi katseta ise kuskil cpp-failis

#endif