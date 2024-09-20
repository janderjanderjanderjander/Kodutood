#include <iostream>
using namespace std;

/* Funktioonid - . - . - .

KUJU:
tagasustüüp nimi(params) {
    keha
} */

double aste(double x, int n); //deklaratsioon

//main()

double aste(double x, int n) {
    double tulemus(1);
    for (int i{}; i < abs(n); ++i) {
        tulemus *= x;
    }
    if (n < 0) {
        tulemus = 1.0 / tulemus;
    }
    return tulemus;
}

/* Kui funktioon ei vaja tagastust, siis on void
void funk(params) {

}
Teksti kuvamiseks näiteks
int main() algusesse
funktioone peab deklareerima alguses, sest pärast maini programm ei vaata, seega peab näitama, deklareerimine võib ka ilma variable'ita teha, ainult tüüp
main saab ka argumente võtta, näiteks mitu arguenti on käsureal ehk mitu sõna just sisestasid

Overloading (üledefineerimine) - sama nimega funktioonid ehk saab erineva argumentitega sama nimega funktioone teha ning programm saab aru milline funktoon argumentide koguse
järgi

Inline functions (pistikfunktioonid) - Väiksed funktioonid tehakse nii sest on kiirem kuidagi ???
*/
inline int suurim(int a, int b) {
    return a > b ? a : b; //kumb on suurem, selle returnib
};
// - . - . - . - . - . - .


/* Muutuja skoop (scope) - . - . - . - . -
Programmi osa, kus muutuja on nähtav
Näiteks lokaalne muutuja scope on kuni tema lokaalse funktiooni lõpuni

Nimeruum (namespace) - klass? saab ligi topeltkooloniga, std on nimeruum  -> std:: <-

Eluiga (lifetime) - muutuja eluiga algab defineerimisest ja lõpeb kõige hiljem programmi lõppemisga

Tekstfaili lugemine ja kirjutamine:

1. Päis - ofstream (kirjutamine) :: ifstream (lugemine)
2. Deklareerida muutuja tüüp - ios::(mis teha tahad) --> out(kirj) v in(lug) v app(kirj lõppu) v trunc(kirj üle)
3. Avada fail
4. Kontrollida faili olemasolu
5. Teha mis tahad
6. Sulgeda
*/
#include <fstream>
void kirjutamine() {
    ofstream os; // deklaratioon
    os.open("tooted.txt", ios::out); //avamine
    if (os) { //kas on olemas
        os << "pliiats " << 0.25 << "\n"; //kirjutamine
        os.close(); //sulgemine
    }
    else { //kui ei saanud hakkama
        cout << "Ei saa avada\n";
    }
    return;
}
// Kus fail on? - Seal kus kompliteeritakse, peab täpsustama ka kohta
void lugemine() {
    ifstream is;
    is.open("tooted.txt", ios::in);
    if (!is) { //kas tekkis viga
        cout << "Ei saa lugeda\n";
        return;
    }
    string toode{};
    float hind{};
    float summa{}; //kogusumma jaoks
    is >> toode >> hind; // loeme toote ja hinna muutujatesse
    cout << toode << " " << hind << "\n"; //ekraanile
    summa += hind;
    is >> toode >> hind; //teine rida
    cout << toode << " " << hind << "\n";
    summa += hind;
    is.close();
    cout << "Kokku: " << summa << "\n"; //ekraanile
    return;
}
// Getline, et saada niipalju ridu kui neid on selle loopiga:

void miturida() {
    ifstream is;
    float toode{};
    float hind{};
    float summa{};
    is.open("tooted.txt", ios::in);
    if (is) {
        string rida{};
        while (getline(is, rida)) { //niikaua kuni õnnestub lugeda
            int i = rida.find(" ");
            toode = rida.substr(0, i);
            hind = stof(rida.substr( i + 1 ));
            summa += hind;
            cout << toode << " " << hind << "\n";

        }
    }
    cout << "Kokku: " << summa << "\n";
    is.close();
    return;
}

/* kui semikoolonitega eraldatud --> getline(is, nimi, ";");
getline(is, s_arv, ";") --> järgmise semikooloneni
SLAIDIDEL TÄPSELT KUIDAS TÖÖDELDA (SLAID 25)


*/




//





//
