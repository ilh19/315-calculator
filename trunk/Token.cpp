<TOKEN.CPP>
#include "Token.h"
TokenParen::
TokenParen(char c): par(c){
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
