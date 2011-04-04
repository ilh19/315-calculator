#include "Evaluator.h"
#include <cmath>


int Evaluator::evalExp() { //not working
	int v1, v2;
	
	list<Token*>::iterator it;
	for (it = p.postFix.begin(); it!=p.postFix.end(); it++) {
		char cur = (*it)->getId();
		if(cur == 'd') {
			evalStack.push_back((*it)->getValue());
		}
		else {
			v2 = evalStack.back();
			evalStack.pop_back();
			v1 = evalStack.back();
			evalStack.pop_back();
			evalStack.push_back(eval(v1,v2,cur));
		}
	}
	//try {
		return evalStack.front();
	//}
	//catch (...) {
	//	cerr<<"Wrong expression" << endl; 
	//}
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
	  if (v2 == 0) throw RuntimeException("Division by zero is invalid!");
	  return (v1/v2); //check for div by zero later
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