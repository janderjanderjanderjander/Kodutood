#include "stack.h"
#include "mem.h"
#include <stdio.h>

#include <stdlib.h>
//BF mälu tööriistad

//suurendab indeksiga viidatud massiivi elemendi väärtust ühe võrra. Tagastab uue väärtuse. 
int mem_inc() {
    return mem_add(1);
}

//vähendab indeksiga viidatud massiivi elemendi väärtust ühe võrra. Tagastab uue väärtuse.
int mem_dec() {
    return mem_add(-1);
}

//liigutab indeksit vasakuke (vähendab selle väärtust ühe võrra). Kui indeks muutub negatiivseks, siis liiguta see massiivi lõppu. Tagastab indeksi uue väärtuse.
int mem_left() {
    return mem_move(-1);
}

//liigutab indeksit paremale (suurendab selle väärtust ühe võrra). Kui indeks läheb üle massiivi piiri, siis liiguta indeks massiivi algusesse. Tagastab indeksi uue väärtuse.
int mem_right() {
    return mem_move(1);
}

// trükib välja indeksi väärtuse, mälu väärtuse sellel indeksil ja sellele järgnevad 9 väärtust (kui massiivi piir tuleb ette, siis liigu tagasi algusesse)
void mem_printDebug() {
    printf("\n\n");
    printf("Väärtus sellel aadressil: %d\nJärgmised 9 väärtust: ", fstack.arr[fstack.index]);
    for (int i = 0; i <= 67; i++) {
        printf("%d ", fstack.arr[i]);
    }
    printf("\nIndex: %d", fstack.index);
    printf("\nKasutusel stack: %d", fstack.len);
    printf("\nSaadaval stack: %d", fstack.size);
    printf("\nNullosa: %d", fstack.nullosa);
    printf("\n\n");
}

//Panen argumendi võrduma indexiga näidatud mälurakku
int mem_set(int a) {
    if (fstack.index >= fstack.size) {
        stack_push(0, &fstack);
    }
    fstack.arr[fstack.index] = a;
    return a;
}

char mem_get() {
    char c = fstack.arr[fstack.index];
    return c;
}

//Remember, loopi alguseks jätab meelde alguskoha.
int mem_rem(int i) {
    stack_push(i, &loopstack);
    return i;
}

//LOOPI LÕPP, kui indexi all on 0, siis tagastab sama ja kustutab viimase meeldejätmise, kui mitte, siis tagastab viimase loopi alguskoha.
int mem_return(int i) {
    if (fstack.arr[fstack.index] == 0) { 
        stack_pop(&loopstack);
        return i;
    } else {
        return stack_peek(&loopstack);
    }
}

//funktsioon, mis liidab aktiivsele mäluväljale parameetrina antud väärtuse, mis võib olla ka negatiivne. Funktsioon tagastab aktiivse mäluvälja väärtuse.
int mem_add(int amount) {
    fstack.arr[fstack.index] += amount;
    if (fstack.arr[fstack.index] >= 255) { //Ülemine piir
        fstack.arr[fstack.index] = 0;
    } else if (fstack.arr[fstack.index] < 0) { //alumine piir
        fstack.arr[fstack.index] = 255;
    }
    //kui muutsin elementi aga nullosa oli maas
    if (fstack.arr[fstack.index] != 0 && fstack.nullosa < fstack.index) {
        fstack.nullosa = fstack.index;
    } else if (fstack.arr[fstack.index] == 0 && fstack.index != 0 && fstack.nullosa == fstack.index) { //kui muutsin nulliks siis pean nullosa parandama
        int i = 0; //true or false
        int j = 0; //hakkan lugema alla
        while (i == 0) {
            if (fstack.arr[fstack.index - j] != 0) {
                fstack.nullosa = fstack.index - j;
                i = 1;
            }
            j++;
        }
    }

    while (fstack.len > fstack.nullosa + 1 && fstack.len > fstack.index + 1) { //Kui on liiga palju nulle
        stack_pop(&fstack);
    }

    return fstack.arr[fstack.index];
}

//liigutab aktiivset mäluvälja vasakule ja paremale ning tagastab uue positsiooni.
int mem_move(int numberOfPositions) {
    fstack.index += numberOfPositions;
    if (fstack.index < 0) { //Piirid
        fstack.index = 29999;
    } else if (fstack.index > 29999) {
        fstack.index = 0;
    }
    while (fstack.index >= fstack.len) { //Kui index liigub uuele alale
        stack_push(0, &fstack);
    }
    return fstack.arr[fstack.index];

}

void mem_init() {
    fstack.arr = (int*)malloc(30000 * sizeof(int));

    if (fstack.arr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1); 
    }
    for (int i = 0; i < 30000; i++) {
        fstack.arr[i] = 0;
    }
    fstack.index = 0;
}

void mem_free() {
    if (fstack.arr != NULL) {
        free(fstack.arr);
        fstack.arr = NULL;
    }
}