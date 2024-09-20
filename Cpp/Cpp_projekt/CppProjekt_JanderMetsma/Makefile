
CXX := g++

CXXFLAGS := -g -Wall -std=c++20 -Wpedantic -Werror

CPPFLAGS := -Iinc

SRCPATH := src/

INCPATH := inc/

OBJPATH := obj/

EXE := bin/main.exe

SRC_FILES := $(wildcard $(SRCPATH)*.cpp)

OBJ_FILES := $(patsubst $(SRCPATH)%.cpp,$(OBJPATH)%.o, $(SRC_FILES))

INC_FILES = $(wildcard $(INCPATH)*.h)

hello:
	echo $(INC_FILES)

all: $(EXE)

$(OBJPATH)%.o: $(SRCPATH)%.cpp $(INC_FILES)
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $< -o $@

$(EXE): obj $(OBJ_FILES) bin
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(OBJ_FILES) -o $@

.PHONY: run
run: $(EXE)
	./$(EXE)

.PHONY: check
check: src check_d
	@cppcheck src -Iinc --cppcheck-build-dir=check_d --platform=win64 --quiet

check_d:
	mkdir check_d

obj:
	mkdir obj

bin:
	mkdir bin

clean:
	rm -r bin
	rm -r obj
	rm -r check_d

init: src inc
	echo "#include <iostream>" >> $(SRCPATH)main.cpp
	echo >> $(SRCPATH)main.cpp
	echo "int main(int argc, char *argv[]){" >> $(SRCPATH)main.cpp
	echo "	std::cout << 100;" >> $(SRCPATH)main.cpp
	echo "	return 0; }" >> $(SRCPATH)main.cpp

src:
	mkdir src

inc:
	mkdir inc


