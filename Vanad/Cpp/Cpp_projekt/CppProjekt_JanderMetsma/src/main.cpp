#include "mängija.h"
#include "master.h"
#include "counter.h"

int main(int argc, char *argv[]){
	int state{1};

	puhasta();
	
	main_menu();

	Counter counter{};

	vector<Mängija> players = setup();

	vector<int> kaardipakk = kaardipakk_template;
	sega_kaardid(&kaardipakk);

	while (true) {
	if (state == 1) { //mängu algus
		jaga_kaardid(&players, &kaardipakk, &counter);
		state = 2;
	}
	else if (state == 2) { //Valik
		state = otsus(&players, &counter);
	}
	else if (state == 3) { //hit
		state = hit(&(players[1]), &kaardipakk, &counter);
	}
	else if (state == 4) {
		diileri_kord(&(players[0]), &kaardipakk, &counter);
		state = 5;
	}
	else if (state == 5) {
		state = lõpp(&players, &kaardipakk, &counter);
	}
	else if (state == 0) {
		return 1;
	}
	}
}
