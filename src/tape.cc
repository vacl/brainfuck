#include "tape.h"

#include <stdint.h>
#include <iostream>

Tape::Tape(){
	head = new Cell();
}

Tape::~Tape(){
	delete head;
}

void Tape::moveLeft(){
	Cell *next = head->left;
	if(next == NULL) next = new Cell();
	next->right = head;
	head->left = next;
	head = next;
}

void Tape::moveRight(){
	Cell *next = head->right;
	if(next == NULL) next = new Cell();
	next->left = head;
	head->right = next;
	head = next;
}

void Tape::increment(){
	head->value++;
}

void Tape::decrement(){
	if(head->value > 0) head->value--;
}

void Tape::print(){
	std::cout << char(head->value);
}

void Tape::read(){
	char in;

	std::cout << std::endl << "in: ";
	std::cin >> in;
	std::cout << std::endl;

	head->value = uint8_t(in);
}

uint8_t Tape::getValue(){
	return head->value;
}
