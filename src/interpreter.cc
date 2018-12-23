#include "interpreter.h"

#include <iostream>
#include <vector>
#include <stack>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

Interpreter::Interpreter(){
	t();
	instructionPointer = 0;
}

void Interpreter::run(char* source){
	std::vector<char> code(0);
	int8_t err = process(source, &code);
	if(err < 0) {
		std::cerr << "Error " << err << " while processing file " << source << std::endl;
		return;
	}

	std::stack<uint32_t> loopStack();
	uint32_t instructionPointer = 0;

	while(execute(&code, &instructionPointer, &loopStack));	
}

int8_t Interpreter::process(char *source, std::vector<char> *target){
	int8_t file = open(source, O_RDONLY);
	if(file < 0) return -1;		//error while opening

	int16_t readB;
	char buf[512];
	do{
		readB = read(file, buf, 512);
		if(readB < 0) return -2;	//error while reading

		for(uint16_t i = 0; i < readB; i++){
			if(strchr("<>+-,.[]", buf[i]) != NULL) target->push_back(buf[i]);
		}
	} while(readB == 512);

	file = close(file);
	if(file < 0) return -3;		//error while closing
	return 0;
}

bool Interpreter.execute(std::vector<char> *code, uint32_t *instructionPointer, std::stack<uint32_t> *loops){
	switch(code->at(instructionPointer)){
	case '<':
		t->moveLeft();
		break;
	case '>':
		t->moveRight();
		break;
	case '+':
		t->increment();
		break;
	case '-':
		t->decrement();
		break;
	case '.':
		t->print();
		break;
	case ',':
		t->read();
		break;
	case '[':
		loops->push(*instructionPointer);
		break;
	case ']':
		if(t->value() > 0) *instructionPointer = loops->top();
		else loops->pop();
		break;
	}
	
	(*instructionPointer)++;
	return *instructionPointer < code->size();
}
