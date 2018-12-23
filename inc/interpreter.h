#include "tape.h"

#include <stdint.h>

#IFNDEF INTERPRETER_H
#DEFINE INTERPRETER_H
class Interpreter{
private:
	Tape *t;
	int8_t process(char *source, std::vector<char> *target);
	bool execute(std::vector<char> *code, uint32_t *instructionPointer, std::stack<uint32_t> *loops);
public:
	Interpreter();
	void run(char* source);
};
#ENDIF
