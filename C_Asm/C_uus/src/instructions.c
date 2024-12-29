#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "instructions.h"
#include "stack.h"
#include "mem.h"

//SIIN KOHE ON TRANSLAATOR!!!
void BF_increment_printAsm(struct BF_instruction_st *instruction, int *index) {
    printf("    ;;;; Instruktsioon + / -\n");
    if (instruction->increment == 1) {
        printf( "    mov al, [esi + edi]\n");
        printf( "    inc al\n");
        printf( "    mov [esi + edi], al\n");
    } else if (instruction->increment == -1) {
        printf( "    mov al, [esi + edi]\n");
        printf( "    dec al\n");
        printf( "    mov [esi + edi], al\n");
    }
}

void BF_move_printAsm(struct BF_instruction_st *instruction, int *index) {
    printf("    ;;;; Instruktsioon < / >\n");
    if (instruction->numberOfPositions == 1) {
        printf( "   inc esi\n");
    } else if (instruction->numberOfPositions == -1) {
        printf( "dec esi\n");
    }
}

void BF_beginLoop_printAsm(struct BF_instruction_st *instruction, int *index) {
    printf("    ;;;; Instruktsioon [\n");
    printf("silt_%d:\n", *index);
    printf( "   cmp byte [esi], 0\n");
    printf( "je silt_%d\n", instruction->loopForwardIndex);
}

void BF_endLoop_printAsm(struct BF_instruction_st *instruction, int *index) {
    printf("    ;;;; Instruktsioon ]\n");
    printf("    jmp silt_%d\n", instruction->loopBackIndex);
    printf("silt_%d:\n", *index);
}

void BF_Read_printAsm(struct BF_instruction_st *instruction, int *index) {
    printf("    ;;;; Instruktsioon ,\n");
    //buffrisse lugemine
    printf("    mov eax, 3\n");
    printf("    mov ebx, 0\n");
    printf("    lea ecx, [buffer]\n");
    printf("    mov edx, 1\n");
    printf("    int 0x80\n");

    //cell määramine
    printf("    mov al, [buffer]\n");
    printf("    mov [esi + edi], al\n");
}

void BF_Write_printAsm(struct BF_instruction_st *instruction, int *index) {
    printf("    ;;;; Instruktsioon .\n");
    //kirjutamine
    printf("    mov al, [esi + edi]\n");
    printf("    mov byte [msg], al\n");
    printf("    mov eax, 4\n");
    printf("    mov ebx, 1\n");
    printf("    lea ecx, [msg]\n");
    printf("    mov edx, 1\n");
    printf("    int 0x80\n");
}


/* Konstruktor funktsioon BF_increment_new loob uue struktuuri, mis suurendab
   aktiivse mäluala väärtust vastavalt parameetrina antud väärtusele, mis võib olla ka
   negatiivne. 
*/

/* Funkctioon BF_increment_new on kood, mida käivitatakse konkreetse
   instruktsiooni käivitamisel. 
*/
void BF_increment_run(struct BF_instruction_st *instruction, int *index) {
    /* Suurendame mälu väärtust vastavalt konstruktoris seatud väärtusele! */
    mem_add(instruction->increment);

    /* Suurendame instruktsiooniloendurit ühe võrra. */
    ++*index;
}

struct BF_instruction_st *BF_increment_new(int increment) {
    struct BF_instruction_st *new = NULL;

    /* Kontrollime väärtust, et vältida hilisemaid vigu. */
    if (increment == 0) {
        printf("Liitmisinstruktsiooni parameeter ei saa olla 0!");

        /* Sisuliselt tagastab nüüd funktsioon NULL'i. */
        goto cleanup;
    }

    new = malloc(sizeof(struct BF_instruction_st));
    if (new == NULL) {
        printf("Mälu küsimine ebaõnnestus.");
        goto cleanup;
    }

    /* Väärtustame inkremendi. */
    new->increment = increment;
    new->run = BF_increment_run;
    new->printAsm = BF_increment_printAsm;
cleanup:
    return new;
}

void BF_move_run(struct BF_instruction_st *instruction, int *index) {
    mem_move(instruction->numberOfPositions);
    ++*index;
}

struct BF_instruction_st *BF_move_new(int numberOfPositions) {
    struct BF_instruction_st *new = NULL;

    /* Kontrollime väärtust, et vältida hilisemaid vigu. */
    if (numberOfPositions == 0) {
        printf("liigutamisinstruktsiooni parameeter ei saa olla 0!");

        /* Sisuliselt tagastab nüüd funktsioon NULL'i. */
        goto cleanup;
    }

    new = malloc(sizeof(struct BF_instruction_st));
    if (new == NULL) {
        printf("Mälu küsimine ebaõnnestus.");
        goto cleanup;
    }

    /* Väärtustame inkremendi. */
    new->numberOfPositions = numberOfPositions;
    new->run = BF_move_run;
    new->printAsm = BF_move_printAsm;
cleanup:
    return new;
}

void BF_Read_run(struct BF_instruction_st *instruction, int *index) {
    //Kui on siis võtame ta mällu
    mem_set(instruction->sisend);
    ++*index;
}

struct BF_instruction_st *BF_Read_new() {
    struct BF_instruction_st *new = NULL;

    int c = getc(stdin);

    if (EOF == c) {
        printf("Pole sisendit!\n");
        goto cleanup;
    }

    new = malloc(sizeof(struct BF_instruction_st));
    if (new == NULL) {
        printf("Mälu küsimine ebaõnnestus.");
        goto cleanup;
    }

    /* Väärtustame inkremendi. */
    new->sisend = c;
    new->run = BF_Read_run;
    new->printAsm = BF_Read_printAsm;
cleanup:
    return new;
}

void BF_Write_run(struct BF_instruction_st *instruction, int *index) {
    char c = mem_get();
    printf("%c", c);
    ++*index;
}

struct BF_instruction_st *BF_Write_new() {
    struct BF_instruction_st *new = NULL;

    new = malloc(sizeof(struct BF_instruction_st));
    if (new == NULL) {
        printf("Mälu küsimine ebaõnnestus.");
        goto cleanup;
    }

    new->run = BF_Write_run;
    new->printAsm = BF_Write_printAsm;
cleanup:
    return new;
}

void BF_beginLoop_run(struct BF_instruction_st *instruction, int *index) {
    int val = mem_get();

    if (instruction->loopForwardIndex < 0) {
        printf("Tsükli algus algväärtustamata!\n");
        return;
    }

    if (val == 0) {
        *index = instruction->loopForwardIndex + 1;
    } else {
        ++*index;
    }
}

struct BF_instruction_st *BF_beginLoop_new(void) {
    struct BF_instruction_st *new = NULL;

    new = malloc(sizeof(struct BF_instruction_st));
    if (new == NULL) {
        printf("Mälu küsimine ebaõnnestus.");
        goto cleanup;
    }

    /* Hetkel pole teada kus asub tsükli lõpp, seega kasutame väärtust, mis
       ei saa korrektne olla.*/
    new->loopForwardIndex = -1;
    new->run = BF_beginLoop_run;
    new->printAsm = BF_beginLoop_printAsm;
cleanup:
    return new;
}

void BF_endLoop_run(struct BF_instruction_st *instruction, int *index) {
    int val = mem_get();

    if (instruction->loopBackIndex < 0) {
        printf("Tsükli lõpp algväärtustamata!\n");
        return;
    }

    if (val == 0) {
        /* Pole mõtet tsükli algusesse tagasi hüpata, sest tsüklit enam ei täideta. */
        ++*index;
    } else {
        /* Mine tagasi tsükli algusesse. */
        *index = instruction->loopBackIndex;
    }
}

struct BF_instruction_st *BF_endLoop_new(int loopBackIndex) {
    struct BF_instruction_st *new = NULL;

    new = malloc(sizeof(struct BF_instruction_st));
    if (new == NULL) {
        printf("Mälu küsimine ebaõnnestus.");
        goto cleanup;
    }

    new->loopBackIndex = loopBackIndex;
    new->run = BF_endLoop_run;
    new->printAsm = BF_endLoop_printAsm;
cleanup:
    return new;
}

void parse(struct BF_instruction_st **inst_arr, char *program) {
    int i = 0;

    struct stack_st loopStack = { .len = 0, .size = 0, .arr = NULL, .index = 0, .nullosa = 0, .lopeta = 0}; //TEINE LOOPSTAck; MITTE MINU!!!!

    while (program[i] != 0 ) {
        /* Algväärtustame kõik instruktsioonid eelnevalt NULL'iga. */
        inst_arr[i] = NULL;
        switch (program[i]) {
            case BF_INCREASE:
                inst_arr[i] = BF_increment_new(1);
                break;

            case BF_DECREASE:
                inst_arr[i] = BF_increment_new(-1);
                break;

            case BF_RIGHT:
                inst_arr[i] = BF_move_new(1);
                break;
            
            case BF_LEFT:
                inst_arr[i] = BF_move_new(-1);
                break;

            case BF_READ:
                inst_arr[i] = BF_Read_new();
                break;

            case BF_PRINT:
                inst_arr[i] = BF_Write_new();
                break;

            case BF_START_LOOP:
                inst_arr[i] = BF_beginLoop_new();
                stack_push(i, &loopStack);
                break;
            case BF_DEBUG:
                mem_printDebug();
                break;
            case BF_END_LOOP: {
                int beginIndex = stack_pop(&loopStack);
                inst_arr[i] = BF_endLoop_new(beginIndex);

                /* Uuendame ka tsükli algust, et seal oleks olemas 
                   info kus asub tsükli lõpp! */
                inst_arr[beginIndex]->loopForwardIndex = i;

                break;

            }

            default:
                /* Ignoreerime sümboleid, mida me ei tunne. */
                break;
        }
        i++;
    }
}

void run(struct BF_instruction_st **inst_arr, int inst_arr_len) {
    int i = 0;
    while (1) {
        if (i < 0 || i >= inst_arr_len) break;
        if (inst_arr[i] != NULL) {
            inst_arr[i]->run(inst_arr[i], &i);
        } else {
            /* Suurendame indeksit iseseisvalt. */
            i++;
        }
    }
}

void printAsm(struct BF_instruction_st **inst_arr, int inst_arr_len) {
    //algus
    printf(
        "global main\n"
        "section .data\n"
        "   msg db \"%%c\", 0\n"
        "   prompt db '', 0\n"
        "section .bss\n"
        "   tape resb 30000\n"
        "   buffer resb 1\n"
        "section .text\n"
        "main:\n"
        "   push esi\n"
        "   push edi\n"
        "   mov esi, tape\n"
        "   xor edi, edi\n"
        ";;;;kood\n"
    );
    // Käime läbi kõik instruktsioonid ja käivitame neil funktsiooni printAsm. 
    for (int i = 0; i < inst_arr_len; i++) {
       if (inst_arr[i] != NULL) {
           inst_arr[i]->printAsm(inst_arr[i], &i);
       }
    }
    // Funktsiooni main lõpp.
    printf(
        "   mov eax, 1\n"
        "   xor ebx, ebx\n"
        "   int 0x80\n"
    );
}

void free_instructions(struct BF_instruction_st **inst_arr, int inst_arr_len) {
    for (int i = 0; i < inst_arr_len; i++) {
        if (inst_arr[i] != NULL) {
            free(inst_arr[i]);
        }
    }
    free(inst_arr);
}

