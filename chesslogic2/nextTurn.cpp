#include <iostream>
#include "Source.h"
#include "nextTurn.h"

int nextTurn() {

	makeMove();
	return 0;
}

int failTurn() {
	std::cout << "\n\nYou're move failed. You must've done something against the rules\nOtherwise my program is broken\n\n";
	makeMove();
	return 0;
}