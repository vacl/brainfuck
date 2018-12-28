#include "cell.h"

#include <cstddef>

Cell::Cell(){
	value = 0;
	left = NULL;
	right = NULL;
}

Cell::~Cell(){
	if(left != NULL){
		left->right = NULL;
		delete left;
	}
	if(right != NULL){
		right->left = NULL;
		delete right;
	}
}
