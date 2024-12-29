#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "mem.h"
#include "instructions.h"
#include <string.h>

//votab pika sõna ja hakkab igat tähte vaatama, iga tähega teeb mäluga midagi
void interpret(char *program) {
    int i = 0;
    //stack_push(0, &fstack); //Array init
    int skip = 0; //Kas jätta vahele järgmised käsud? (Loopiga seoses)
    while (program[i] != 0) {
        if (skip > 0) {
            if (program[i] == '[') { //Kui vahepeal tuleb uus loop
                skip++;
            }
            if (program[i] == ']') {
                skip--;
                i++;
                continue;
            } else {
                i++;
                continue;
            }
        } else {
              switch (program[i]) {
                case BF_INCREASE:
                    mem_inc();
                    break;
                case BF_DECREASE:
                    mem_dec();
                    break;
                case BF_RIGHT:
                    mem_right();
                    break;
                case BF_LEFT:
                    mem_left();
                    break;
                case BF_START_LOOP:
                    if (fstack.arr[fstack.index] == 0) { //Kontrollib kas loopi käivitada
                        skip = 1;
                    } else {
                        mem_rem(i);
                    }
                    break;
                case BF_END_LOOP:
                    i = mem_return(i); 
                    break;
                case BF_DEBUG:
                    mem_printDebug();
                    break;
                case BF_READ: {
                    //Loeme ühe märgi ASCII koodis
                    int c = getc(stdin);
                    //Kui pole midagi siis katkestame
                    if (EOF == c) {
                        printf("Pole sisendit!\n");
                        return;
                    }
                    //Kui on siis võtame ta mällu
                    mem_set(c);
                    break;
                }
                case BF_PRINT: {
                    //võtan indexi kohal numbri
                    char c = mem_get();
                    printf("%c", c);
                    break;
                }
                default:
                    /* Ignoreerime sümboleid, mida me ei tunne. */
                    break;
            }
        i++;
        }
    }
}

void interpret2(char *program) {
    /* Leiame programmi lähtekoodi pikkuse. */
    int program_len = strlen(program);
    
    /* Teeme massiivi, mis hoiab viitasid, mida on kokku program_len tükku. Viitade
       algväärtustamine toimub parse() funktsioonis. Massiivi pikkus on võetud varuga */
    struct BF_instruction_st **inst_arr = malloc(sizeof(struct BF_instruction_st *) * program_len);

    /* Parsime sisendprogrammi, mille tulemus salvestatakse inst_arr massiivi. */
    parse(inst_arr, program);

    /* Käivitame programmi. */

    //run(inst_arr, program_len);
    printAsm(inst_arr, program_len); //AINULT INTERPRET2

    free_instructions(inst_arr, program_len);

}

int main(int argc, char *argv[]) {

    char *kood = argv[1];

    stack_push(0, &fstack);
    interpret2(kood);
    //interpret(kood);
    free_stack(&fstack);
    free_stack(&loopstack);
    mem_free();
    printf("\n");
    return 0;
}

