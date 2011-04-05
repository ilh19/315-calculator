#include "Evaluator.h"
#include <cmath>


int Evaluator::evalExp() {
	if (p.postFix.empty()) throw RuntimeException("No operands");

	int v1, v2;
	Token* cur; 

	while (!p.postFix.empty()) {
		cur = p.postFix.front();
		p.postFix.pop_front();
		try {
			if (cur->getId()!='d') {
				if (cur->getId() == '~') {
					if (evalStack.size()<1) throw RuntimeException("Invalid expression");  //checks for number of operands in stack (must be at least 1) 
					v1 = evalStack.back();
					evalStack.pop_back();
					evalStack.push_back(eval(v1,'~'));
				}
				else {
					if (evalStack.size()<2) throw RuntimeException("Invalid expression");  //checks for number of operands in stack (must be at least 2) 
					v2 = evalStack.back();
					evalStack.pop_back();
					v1 = evalStack.back();
					evalStack.pop_back();
					evalStack.push_back(eval(v1,v2,cur->getId()));
				}
			}
			else {
				evalStack.push_back(cur->getValue());
			}
		}
		catch (...) {
			throw RuntimeException("Invalid expression");
		}
	}
	if (evalStack.size() > 1 ) throw RuntimeException("Invalid expression");

	return evalStack.front();
}


int Evaluator::eval(int v1, char id) { 
	return -v1;
}

int Evaluator::eval(int v1, int v2, char id) {
  switch (id) {
    case '+':
      return (v1+v2);
      break;
	  
	case '-':
      return (v1-v2);
      break;
	
	case '/':
	  if (v2 == 0) throw RuntimeException("Division by zero is invalid!");	// check for division by zero
	  return (v1/v2); 
	  break;
	
	case '*':
	  return (v1*v2);
	  break;

	case '%':
	  if (v2 == 0) throw RuntimeException("Division by zero is invalid!");	// check for division by zero
	  return (v1%v2);
	  break;	

	case '^':
	  return static_cast<int>(pow(static_cast<double>(v1), v2));
	  break;

	default:
	return 0;
  }
}