#ifndef CELL_H
#define CELL_H
#include <stdint.h>

class Cell{
public:
	uint8_t value;
	Cell *left;
	Cell *right;
	Cell();
	~Cell();
};

#endif
