#ifndef __STACK_H__
#define __STACK_H__


//INIT
    //struktuur fikseeritud stackile
    struct stack_st {
        int len;
        int size; /* Massiivi mahtuvus - mitme elemendi jaoks on ruumi. */ //TODO: KOODIS ARR ON VIGA
        int *arr;
        int index;
        int nullosa; //Kus maalt on ainult algväärtustamine
        int lopeta;
    };

//fstacki init ja leni muutmine 0-iks
extern struct stack_st fstack;
extern struct stack_st loopstack;

/* Funktsioon push saab parameetriks int tüüpi väärtuse, mille lisab globaalsesse pinusse, kui
 * selles on veel ruumi. Vastasel korral trükib ekkraanile vea. Funktsioon ei tagasta midagi.
 */
void stack_push(int element, struct stack_st *s);

/* Funktsioon pop ei saa ühtegi parameetrit ja tagastab globaalse pinu pealmise elemendi, mille ta
 * pinust eemaldab. Kui pinu on juba tühi, siis funktsioon tagastab väärtuse 0.
 */
int stack_pop(struct stack_st *s);

/* Funktsioon isEmpty tagastab tõeväärtuse (0-vale ja mitte 0 tõene) vastavalt sellele kas
 * pinu on tühi või mitte.
 */
int stack_isEmpty(struct stack_st *s);

/* Funktsioon peek tagastab pinu pealmise elemendi ilma seda eemaldamata.
 * Kui pinu on tühi, siis see tagastab 0 väärtuse.
 */
int stack_peek(struct stack_st *s);


/* Funktsioon print_stack trükib ekraanile kõik pinu elemendid eraldi reale alustades ülemisest.
 */
void stack_print(struct stack_st *s);

void free_stack(struct stack_st *s);

#endif