#ifndef INTERPRETER_H
#define INTERPRETER_H
#include "tape.h"

#include <stdint.h>
#include <vector>
#include <stack>

class Interpreter{
private:
	Tape *t;
	int8_t process(char *source, std::vector<char> *target);
	bool execute(std::vector<char> *code, uint32_t *instructionPointer, std::stack<uint32_t> *loops);
public:
	Interpreter();
	~Interpreter();
	void run(char* source);
};
#endif
