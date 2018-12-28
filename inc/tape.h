#ifndef TAPE_H
#define TAPE_H
#include "cell.h"

class Tape{
private:
	Cell *head;
public:
	Tape();
	~Tape();
	void moveLeft();
	void moveRight();
	void increment();
	void decrement();
	void print();
	void read();
	uint8_t getValue();
};
#endif
