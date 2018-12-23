#include <iostream>
#include "interpreter.h"

int main(int argc, char **argv){
	if(argc != 2){
		std::cout << "Usage: brainfuck FILE" << std::endl;
		return 0;
	}

	Interpreter *i();
	i->run(argv[1]);
	
	return 0;
}
