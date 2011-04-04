#ifndef EVALUATOR_H
#define EVALUATOR_H
#include "Parser.h"
#include "RuntimeException.h"
#include <iostream>

class Evaluator {
	private:
		Parser p;
		int eval(int v1, int v2, char id);
		list<int> evalStack;
		
	public:
		Evaluator(Parser parser) : p(parser), evalStack() {}
		int evalExp();
};

#endif