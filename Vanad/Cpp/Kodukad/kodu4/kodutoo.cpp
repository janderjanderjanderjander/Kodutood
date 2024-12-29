/*

*/
#include <iostream>
#include <string>
#include <concepts>
using namespace std;

template<typename T>
requires integral<T> || floating_point<T>
class Massiiv {
    T m_massiiv[100]{};
public:
    T getElement(int i){
        return m_massiiv[i];
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
        for (int i{99}; i > -1; i--) {
            if (m_massiiv[i] == 0) {
                m_massiiv[i] = el;
                break;
            }
        }
    }
    void kustutaElement(){
        for (int i{99}; i > -1; i--) {
            if (m_massiiv[i] != 0) {
                m_massiiv[i] = 0;
                break;
            }
        }
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
}



int main() {




    return 0; 
}