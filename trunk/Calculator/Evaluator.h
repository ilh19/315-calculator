#ifndef EVALUATOR_H
#define EVALUATOR_H
#include "Parser.h"
#include "RuntimeException.h"
#include <iostream>

class Evaluator {
	private:
		Parser p;
		int eval(int v1, int v2, char id);	// function that evaluates sub-expressions
		int eval(int v1, char id); // handling unary minus
		list<int> evalStack;	// evaluator stack

		
	public:
		Evaluator(Parser parser) : p(parser), evalStack() {}
		int evalExp();			// function that goes through the postfix list and calls eval function
};

#endif