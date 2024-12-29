#pragma once

#include <vector>
#include <iostream>
#include <map>
using namespace std;

class M�ngija
{
private:
	vector<int> kaardid{};
	int summa{};
	bool peida_kaart{};
public:
	M�ngija(bool a) : peida_kaart(a) {}
	string get_kaart(int) const;
	int get_summa() const { return summa; }
	bool get_diiler() const { return peida_kaart; }
	void n�ita() { peida_kaart = false; }
	void peida() { peida_kaart = true; }
	void kuva();
	void lisa_kaart(int);
	void fold();
	friend ostream& operator<<(ostream&, const M�ngija&);
};
