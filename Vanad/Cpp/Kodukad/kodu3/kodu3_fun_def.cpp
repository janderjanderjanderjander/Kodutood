#include "kodu3_fun_dekl.h"
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
int fun(int a, int b) { return {a+b}; }

int fun(double a) {
  int b{};
  b = round(a * a);
  return b;
}

string fun(unsigned int a, string b) { 
  string valjastusstring{b};
  for (unsigned int i{1}; i < a; i++) {
    valjastusstring = valjastusstring + b;
  } return valjastusstring;
}

double kehamassiindeks(double pikkus, int kaal) {
  double bmi{};
  bmi = (kaal / pow(pikkus, 2));
  return bmi;
} 

string hinnang(double bmi) { 
  if (bmi < 19) {
    return "alakaal";
  } else if (bmi < 25) {
    return "normaalkaal";
  } else if (bmi < 30) {
    return "ülekaal";
  } else {
    return "rasvumine";
  };
}

unsigned long int faktoriaal_li(int n) { return {}; }

string otsi_mustrit(int& argc, char* argv[]) { 
  string otsitav;
  int oli{};
  for (int i{1}; i < argc; ++i) {
    string arg(argv[i]);
    if (arg.find("-otsi=") == 0) {
      otsitav = arg.substr(6);
      if (!otsitav.empty()) {
      oli = 1;
    }}}

  if (oli == 1) {
    oli = 0;
  } else {
    return "Mustrit ei ole olemas.";
  }
  for (int i{1}; i < argc; ++i) {
    string arg(argv[i]);
    if (arg.find("-otsi=") == 0) {
      continue;}
    if (otsitav == arg) {
      oli = 1;
    }}
  if (oli == 1) {
    string tagastus = "Otsitav '" + otsitav + "' leiti.";
    return tagastus;
  }
  else {
    string tagastus = "Otsitavat '" + otsitav + "' ei leitud.";
    return tagastus;
  }
}

void andmed_failist(string nimi) {
    ifstream is;
    ofstream os;
    string rida, number;
    double summareas{}, summakokku{}, k_number{}; 
    int mitureas{};
    vector<double> list;

    is.open(nimi, ios::in);
    if (!is) {
        cout << "ei suuda lugeda";
        return;}
    while (getline(is, rida)) {
        stringstream reastriim(rida);
        while (getline(reastriim, number, ';')) { 
            if (!number.empty()) {
                ++mitureas;
                k_number = stod(number);
                summakokku += k_number;
                summareas += k_number;
            }
        }
        list.push_back(summareas / mitureas);
        summareas = 0; 
        mitureas = 0;
    }
    is.close();
    os.open("tulemused.txt", ios::out);
    if (!os) {
        cout << "Tekkis viga kirjutamisel\n";
        return;}
    for (double& i : list) {
        os << i << "\n";
    }
    os << summakokku;
    os.close();
    return;}


#if !defined(VPL_TEST)  // See main funktsioon kommenteeritakse välja
int main(int argc, char* argv[]) {
  // Siin saad oma koodi testida
}
#endif