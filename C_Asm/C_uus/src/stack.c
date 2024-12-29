#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

//fstacki init ja leni muutmine 0-iks
struct stack_st fstack = { .len = 0, .size = 0, .arr = NULL, .index = 0, .nullosa = 0, .lopeta = 0}; 
struct stack_st loopstack = { .len = 0, .size = 0, .arr = NULL, .index = 0, .nullosa = 0, .lopeta = 0}; 

//FUNKTSIOONID

    //Lisab fstacki ühe elemendi juurde
    void stack_push(int element, struct stack_st *s) {
        //kontroll kas mälu on piisavalt
        if (s->size == 0 || s->arr == NULL) {
            //teeme ühe elemndi jaoks ruumi
            s->size = 1;
            //calloc teeb nulliks
            s->arr = calloc(s->size, sizeof(int));

            //vaatame kas tegi
            if (s->arr == NULL) {
                printf("Mälu on otsas!\n");
                return;
            }
        //kuna see juhtub ainult alguses siis kinnitame length
        s->len = 0;
        } else if (s->len == s->size) {
            //ehk siis, kui stack saab niisama täis
            //ajutiste muutujatega suurendan mälu 2x
            int tmp_size = s->size * 2;
            int *tmp_arr = NULL;

            //teen mälu suuremaks
            tmp_arr = realloc(s->arr, tmp_size * sizeof(int));
            //kas juhtus?
            if (tmp_arr == NULL) {
                printf("Mälu suurendamine ebaõnnestus!\n");
                return;
            }

            //kõik uus memory nullideks
            memset(tmp_arr + s->size, 0, (tmp_size - s->size) * sizeof(int));

            //Siin teame et on korras
            s->arr = tmp_arr;
            s->size = tmp_size;
        }

        //PUSH FUNKTSIOONI REAALNE ALGUS
        s->arr[s->len] = element;
        s->len++;
        return;
    }

    //liigutab indeksi taha poole ehk nagu eemaldaks aga me ei muuda seda tagasi nulliks
    int stack_pop(struct stack_st *s) {
        //kontroll
        if (s->len == 0) {
            printf("fStack on tühi\n");
            return 0;
        }

        //eemaldamine niiöelda
        int element = s->arr[s->len - 1];
        s->arr[s->len-1] = 0;
        s->len--;

        //kontroll kas mälu on vaja

        if (s->len == 0 && s->arr != NULL) {
            //mälu pole kasutusel üldse
            free(s->arr);
            s->arr = NULL;
            s->size = 0;
            return element;
        }

        //kontroll kas peab mälu vähendama
        if (s->len < 0.25 * s->size) {
            //uus suurus, int teeb kindlaks et ei oleks komakohta
            int new_size = (int)(s->size * 0.25);


            //kindlustan, et ei kaota elemente
            if (new_size < s->len) {
                new_size = s->len;
            }

            //kontroll, et ei oleks null
            if (new_size == 0) {
                printf("Viga, mälu on 0\n");
                return 1;
            }

            //mälu allokeerimine
            int *tmp_arr = realloc(s->arr, new_size * sizeof(int));

            //Kas tegi?
            if (tmp_arr == NULL) {
                printf("Ei saanud mälu väiksemaks\n");
                return 1;
            }

            //päriselt määramine
            s->arr = tmp_arr;
            s->size = new_size;
        }
        return element;
    }

    //tagastab viimase elemendi, aga ei _eemalda nagu pop
    int stack_peek(struct stack_st *s) {
        if (s->len == 0) {
            printf("fStack on tühi\n");
            return 0;
        }
        int element = s->arr[s->len - 1];
        return element;
    }

    //kontrollib kas fstack on tühi
    int stack_isEmpty(struct stack_st *s) {
        if (s->len == 0) {
            return 1;
        }
        return 0;
    }

    //kõik fstacki elemendid, alustab pealmisest
    void stack_print(struct stack_st *s) {
        //kontroll
        if (s->len == 0) {
            printf("stack tühi\n");
            return;
        }
        //printimine
        for (int i = s->len - 1; i >= 0; i-- ) {
            printf("%d\n", s->arr[i]);
        }
    }

void free_stack(struct stack_st *s) {
    if (s->arr != NULL) {
        free(s->arr);
        s->arr = NULL;  // Avoid dangling pointer
        s->size = 0;
        s->len = 0;
    }
}