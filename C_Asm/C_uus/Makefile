# MAKEFILE KÄSUD:

## See jooksutab c koodi
# make run RUN_ARG="(bf kood)"

## See jooksutab asm koodi
# make arun

## See puhastab kõik
# make clean

CFLAGS := -std=c99 -g -Og -Werror -Wall

EXE := lib/bfi

SRC_FILES := $(wildcard src/*.c)
OBJ_FILES := $(patsubst src/%.c, obj/%.o, $(SRC_FILES))

ASM := nasm
ASM_FLAGS = -felf -g
ASM_SRC := $(wildcard lib/*.asm)
ASM_OBJ := $(ASM_SRC:.asm=.o)
ASM_EXE := lib/abfi

CC := gcc
CC_FLAGS = -m32 -g

$(EXE): $(OBJ_FILES) | lib
	$(CC) $(CFLAGS) -Iinc/ -o $(EXE) $(OBJ_FILES)

obj/%.o: src/%.c | obj
	$(CC) $(CFLAGS) -c -Iinc/ -o $@ $<

obj:
	mkdir -p obj

lib:
	mkdir -p lib

asm: $(ASM_EXE)

lib/%.o: lib/%.asm | lib
	$(ASM) $< $(ASM_FLAGS) -o $@

$(ASM_EXE): $(ASM_OBJ) | lib
	$(CC) $(CC_FLAGS) $(ASM_OBJ) -o $(ASM_EXE)

.PHONY: run
run: $(EXE)
	@if [ -z "$(RUN_ARG)" ]; then \
		echo "Usage: make run RUN_ARG=\"<argument>\""; \
		exit 1; \
	fi; \
	RUN_ARG_ESCAPED="$(RUN_ARG)"; \
	./$(EXE) "$$RUN_ARG_ESCAPED"

.PHONY: arun
arun: $(ASM_EXE)
	./$(ASM_EXE)

.PHONY: clean
clean:
	rm -rf obj/ lib/
