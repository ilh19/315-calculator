/*
<TOKEN.H>
*/
#ifndef TOKEN_H
#define TOKEN_H

class Token{
public:
	// character has an integer value
  	Token(int i);
	int getInPrior();
	int getStackPrior();
	int getId();

protected:
	/*Priorities*/
	int inPrior;
	int stackPrior;
	int id;
};
	
class TokenOpenParen: public Token{
public:
  	TokenOpenParen(int i): inPrior(100), stackPrior(0);
};

class TokenCloseParen:Token{
public:
  	TokenCloseParen(int i):inPrior(0), stackPrior(99);
};

class TokenDigit:Token{
public:
  	TokenDigit(int i) : inPrior(0), stackPrior(0);
};

class TokenPlusMinus:Token{
public:
  	TokenPlusMinus(int i) : inPrior(1), stackPrior(2);
};

class TokenDivMult:Token{
public:
  	TokenDivMult(int i) : inPrior(3), stackPrior(4);
};

class TokenExp:Token{
public:
  	TokenExp(int i) : inPrior(6), stackPrior(5);
};

class TokenEnd:Token{
public:
  	TokenEnd() : inPrior(0), stackPrior(-1);
};

#endif;