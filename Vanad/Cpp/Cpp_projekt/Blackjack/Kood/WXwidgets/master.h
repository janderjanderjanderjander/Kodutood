#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <string>

#include "m�ngija.h"
#include "counter.h"

using namespace std;

vector<int> const kaardipakk_template{
					2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
					2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
					2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
					2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };


void sega_kaardid(vector<int>*);
void kuva(vector<int>*);

int main_menu();
vector<M�ngija> setup();
void anna_kaart(vector<int>*, M�ngija*, Counter*);
void jaga_kaardid(vector<M�ngija>*, vector<int>*, Counter*);
int otsus(vector<M�ngija>*, Counter*);
int hit(M�ngija*, vector<int>*, Counter*);
void diileri_kord(M�ngija*, vector<int>*, Counter*);
int l�pp(vector<M�ngija>*, vector<int>*, Counter*);
extern const map<int, string> pildid;


//Lihtsalt et terminalis kuvada
#include <thread>
void puhasta();
void vahed(int);
void h_vahed(int);
void maga(int);


