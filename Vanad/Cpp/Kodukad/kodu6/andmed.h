#pragma once

#include <vector>
#include <string>
#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// Ülesanne 1
int* loo_andmed(int);
vector<int>* loe_andmed(string* failinimi);
void tootle_andmeid(int*, int);
void kustuta_andmed(int*, vector<int>*);
void tootle_andmeid_vektoris(vector<int>*);

// Ülesanne 2
class Auto
{
private:
    string auto_mark;
    string energia_klass;
    double kütuse_kulu;
public:
    Auto();
    Auto(string, string, double);
    double kytusekulu();
    friend ostream& operator<<(ostream&, const Auto&);
    ~Auto();
};

Auto* looAuto(const string);
vector<Auto*>* loeAutod(const string);
Auto* vähima_kuluga(vector<Auto*>*);
void kustutaAutod(vector<Auto*>*);
