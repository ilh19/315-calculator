#include "Evaluator.h"
#include <cmath>


int Evaluator::evalExp() {
	int v1, v2;
	
	list<Token*>::iterator it;		// iterator to iterate through the list containing the postfix expression
	for (it = p.postFix.begin(); it!=p.postFix.end(); it++) {
		char cur = (*it)->getId();	// get id of current element in postfix list
		if(cur == 'd') {			// current element is a digit, push into evaluator stack
			evalStack.push_back((*it)->getValue());
		}
		else {						// current element is an operator
			v2 = evalStack.back();	// pop digit
			evalStack.pop_back();
			v1 = evalStack.back();	// pop digit
			evalStack.pop_back();
			evalStack.push_back(eval(v1,v2,cur));	// evaluate expression and push into evaluator stack
		}
	}
	return evalStack.front();
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
	
	case '^':
	  return static_cast<int>(pow(static_cast<double>(v1), v2));
	  break;

	default:
	return 0;
  }
}