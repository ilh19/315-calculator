<TOKEN.CPP>
#include "Token.h"

	/*
Token:          +   −   /   *   ^    (            )            operand       END
input priority:	1   1   3   3   6    100          0                 0         0
stack priority: 2   2   4	4    5   0           99                0 	     −1
*/  
	//enum inPriors { factor = 6, mult = 3, div = 3, add = 1, sub=1,  oParen=100, cParen = 0, end = 0};
	//enum stackPriors {factor = 5, mult = 4, div = 4, add = 2, sub=2,  oParen=0, cParen = 99, end = -1};


Token::Token (int i):id(i){}

int Token::getInPrior() {
	return inPrior;
}

int Token::getStackPrior() {
	return stackPrior;
}

int	Token::getId() {
	return id;
}


	
TokenParen::
TokenParen(char c): par(c) {

}

TokenDigit::
TokenDigit(int i): digit(i){
}
TokenOperator::
TokenOperator(char c, int priority): oper(c),prior(priority){
}
Token::
Token(char c){
  	if(c == '(' || c == ')'){
          	TokenParen * t = new TokenParen(c);
  	}
  	else{
          	priors p;
          	switch(c){
          	case '^':   	p = factor;
                                  	break;
          	case '*':   	p = mult;
                                  	break;
          	case '/':   	p = div;
                                  	break;
          	case '+':   	p = add;
                                  	break;
          	case '-':   	p = sub;
                                  	break;
          	}
          	TokenOperator * t = new TokenOperator(c,p);
  	}
}
Token::
Token(int i){
  	//need to finish
}
