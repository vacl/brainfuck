#include "interpreter.h"

#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

Interpreter::Interpreter(){
	t = new Tape();
}

Interpreter::~Interpreter(){
	delete t;
}

void Interpreter::run(char* source){
	std::vector<char> code(0);
	int8_t err = process(source, &code);
	if(err < 0) {
		std::cerr << "Error " << err << " while processing file " << source << std::endl;
		return;
	}

	std::stack<uint32_t> loopStack;
	uint32_t instructionPointer = 0;

	while(execute(&code, &instructionPointer, &loopStack));
	std::cout << std::endl;
}

int8_t Interpreter::process(char *source, std::vector<char> *target){
	int8_t file = open(source, O_RDONLY);
	if(file < 0) return -1;		//error while opening

	int16_t readB;
	char buf[513];
	int16_t loopCounter = 0;
	do{
		readB = read(file, buf, 512);
		if(readB < 0) return -2;	//error while reading
		buf[readB] = '\0';

		for(uint16_t i = 0; i < readB; i++){
			if(strchr("<>+-,.[]", buf[i]) != NULL) target->push_back(buf[i]);
			if(buf[i] == '[') loopCounter++;
			else if(buf[i] == ']') loopCounter--;
		}
	} while(readB == 512);

	file = close(file);
	if(loopCounter != 0) return -3;	//mismatched loop(s)
	if(file < 0) return -4;		//error while closing
	return 0;
}

bool Interpreter::execute(std::vector<char> *code, uint32_t *instructionPointer, std::stack<uint32_t> *loops){
	switch(code->at(*instructionPointer)){
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
		if(t->getValue() > 0) loops->push(*instructionPointer);
		else skipLoop(code, instructionPointer);
		break;
	case ']':
		if(t->getValue() > 0) *instructionPointer = loops->top();
		else loops->pop();
		break;
	}
	
	(*instructionPointer)++;
	return *instructionPointer < code->size();
}

void Interpreter::skipLoop(std::vector<char> *code, uint32_t *instructionPointer){
	if((*code)[*instructionPointer] != '[') return;
	while((*code)[*instructionPointer] != ']') (*instructionPointer)++;
}
