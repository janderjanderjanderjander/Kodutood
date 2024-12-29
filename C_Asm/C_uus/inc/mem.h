#ifndef __MEM_H__
#define __MEM_H__

int mem_inc();
int mem_dec();
int mem_left();
int mem_right();
int mem_set(int a);
int mem_rem(int i);
int mem_return(int i);
char mem_get();
void mem_printDebug();
int mem_add(int amount);
int mem_move(int numberOfPositions);
void mem_init();
void mem_free();

#endif