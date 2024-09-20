#include "master.h"
#include "counter.h"

void sega_kaardid(vector<int>* kaardid) {
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	default_random_engine e(seed);
	shuffle(begin(*kaardid), end(*kaardid), e);
	cout << "Kaardid segati." << endl;
}
void kuva(vector<int>* kaardid) {
	for (size_t i{}; i < (*kaardid).size(); i++) {
		cout << (*kaardid)[i] << ", ";
	}
	cout << endl;
}
int main_menu() {
	int sisestus{};
	while (true) {
		cout << "- - - - - Blackjack - - - - -";
		vahed(10);
		cout << "Start(1)";
		vahed(10);
		cin >> sisestus;
		if (sisestus == 1) {
			return 1;
		}
		else {
			cout << ":";
			cin >> sisestus;
		}
	}
}
vector<Mängija> setup() {
	Mängija diiler(true);
	Mängija player(false);
	vector<Mängija> t;
	t.push_back(diiler);
	t.push_back(player);
	return t;
}
void anna_kaart(vector<int>* kaardipakk, Mängija* kellele, Counter* counter) {
	int kaart = (*kaardipakk).back();
	(*kaardipakk).pop_back();
	(*kellele).lisa_kaart(kaart);
	//counter
	if (kellele->get_summa() == 0 && kellele->get_diiler() == true) {
		counter->lisa_peidetud(kaart);
	}
	else {
		counter->laual_kaart(kaart);
	}
}
void jaga_kaardid(vector<Mängija>* s, vector<int>* pakk, Counter* counter) {
	(*s)[0].fold();
	(*s)[0].peida();
	(*s)[1].fold();

	for (int i{}; i < 2; i++) {
		anna_kaart(pakk, (&(*s)[1]), counter);
		anna_kaart(pakk, (&(*s)[0]), counter);
	}
}
int otsus(vector<Mängija>* s, Counter* counter) {
	int sisestus{};
	vahed(20);
	cout << "Diileri kaardid:\n"
		<< (*s)[0];
	vahed(10);
	cout << "Sinu kaardid:\n"
		<< (*s)[1];
	vahed(1);
	counter->kuva_võimalused();
	cout << "Hit(1) - - Stay(2)\n:";
	cin >> sisestus;
	while (true) {
		if (sisestus == 1)
		{
			return 3;
		}
		else if (sisestus == 2)
		{
			return 4;
		}
		else {
			cout << ":";
			cin >> sisestus;
		}
	}
}
int hit(Mängija* m, vector<int>* pakk, Counter* counter) {
	anna_kaart(pakk, m, counter);
	if ((*m).get_summa() > 21) {
		return 5;
	}
	else {
		return 2;
	}
}
void diileri_kord(Mängija* diiler, vector<int>* pakk, Counter* counter) {
	(*diiler).näita();
	counter->peidetud_näita();
	while ((*diiler).get_summa() < 17) {
		anna_kaart(pakk, diiler, counter);
	}
}
int lõpp(vector<Mängija>* m, vector<int>* pakk, Counter* counter) {
	int sisestus;
	(*m)[0].näita();
	vahed(20);
	cout << "Diileri kaardid:\n" << (*m)[0];
	vahed(10);
	cout << "Sinu kaardid:\n" << (*m)[1];
	vahed(6);
	if ((*m)[1].get_summa() < 22 && ((*m)[1].get_summa() > (*m)[0].get_summa() || (*m)[0].get_summa() > 21)) {
		cout << "- - Võit! - -" << endl;
	}
	else {
		cout << "KAOTUS!" << endl;
	}
	vahed(2);
	cout << "Kaardipakis on veel " << (*pakk).size() << " kaarti.\n";
	if ((*pakk).size() < 10) {
		(*pakk) = kaardipakk_template;
		sega_kaardid(pakk);
		counter->unusta_kõik();
	}
	vahed(1);
	cout << "Edasi(1)    Ei viitsi(2)\n:";
	cin >> sisestus;
	if (sisestus == 1) {
		return 1;
	}
	else {
		return 0;
	}
}

void puhasta() {
	for (int i{}; i < 100; i++) {
		cout << "\n";
	}
}
void maga(int millisekundid) {
	{ this_thread::sleep_for(chrono::milliseconds(millisekundid)); }
}
void vahed(int vahed) {
	for (int i{}; i < vahed; i++) {
		cout << "\n";
	}
}
void h_vahed(int vahed) {
	for (int i{}; i < vahed; i++) {
		cout << " ";
	}
}
const map<int, string> pildid = {
	{11, "J"},
	{12, "Q"},
	{13, "K"},
	{14, "A"}
};