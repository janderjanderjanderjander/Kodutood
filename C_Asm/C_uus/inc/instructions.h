#ifndef __INSTRUCTIONS_H__
#define __INSTRUCTIONS_H__

/* Selles enumeratsioonis on toodud kõik Brainfuck'i keele sümbolid. */
enum instructions_e {
    /* Liiguta mälu indeksit paremale. */
    BF_RIGHT      = '>',

    /* Liiguta mälu indeksit vasakule. */
    BF_LEFT       = '<',

    /* Suurenda mälu indeksil olevat väärtust. */
    BF_INCREASE   = '+',

    /* Vähenda mälu indeksil olevat väärtust. */
    BF_DECREASE   = '-',

    /* Loe kasutajalt sisendit ja salvesta see mäluindeksile. */
    BF_READ       = ',',

    /* Trüki välja mälu indeksil olev väärtus char'ina. */
    BF_PRINT      = '.',

    /* Tsükli algus. */
    BF_START_LOOP = '[',

    /* Tsükli lõpp. */
    BF_END_LOOP   = ']',

    /* Trüki silumise informatsioon. */
    BF_DEBUG      = '#'
};

struct BF_instruction_st {

    /* Instruktsiooni väljakutse funktsioon. Esimene parameeter on viit instruktsiooni
       objektile teine on viit instruktsiooni indeksile, mida antud funktsioon
       peab kas suurendama või muutma (näiteks tsüklites). 
    */
    void (*run)(struct BF_instruction_st *instruction, int *index);
    
        /* Assembleri implementatsiooni funktsioon. Trükib välja vastava instruktsiooni
       implementatsiooni assembleris. */
    void (*printAsm)(struct BF_instruction_st *instruction, int *index);

    union {
        /* Suurenda liitmisel väärtust selle võrra (võib olla ka negatiivne). */
        int increment;

        /* Mitu kohta tuleb mälu asukohta liigutada (võib olla ka negatiivne). */
        int numberOfPositions;

        /* Indeks kuhu hüpata tsükli alguses kui getMem() == 0. */
        int loopForwardIndex;

        /* Indeks kuhu hüpata tagasi tsükli lõpus kui getMem() != 0. */
        int loopBackIndex;

        //Sisend
        int sisend;
    };
};

void BF_increment_run(struct BF_instruction_st *instruction, int *index);
void BF_move_run(struct BF_instruction_st *instruction, int *index);
void BF_Read_run(struct BF_instruction_st *instruction, int *index);
void BF_Write_run(struct BF_instruction_st *instruction, int *index);
void BF_beginLoop_run(struct BF_instruction_st *instruction, int *index);
void BF_endLoop_run(struct BF_instruction_st *instruction, int *index);

void BF_increment_printAsm(struct BF_instruction_st *instruction, int *index);
void BF_move_printAsm(struct BF_instruction_st *instruction, int *index);
void BF_beginLoop_printAsm(struct BF_instruction_st *instruction, int *index);
void BF_endLoop_printAsm(struct BF_instruction_st *instruction, int *index);
void BF_Read_printAsm(struct BF_instruction_st *instruction, int *index);
void BF_Write_printAsm(struct BF_instruction_st *instruction, int *index);

void printAsm(struct BF_instruction_st **inst_arr, int inst_arr_len);
void parse(struct BF_instruction_st **inst_arr, char *program);
void run(struct BF_instruction_st **inst_arr, int inst_arr_len);
void free_instructions(struct BF_instruction_st **inst_arr, int inst_arr_len);

struct BF_instruction_st;


#endif