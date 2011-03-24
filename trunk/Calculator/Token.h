/*
<TOKEN.H>
*/
#ifndef TOKEN_H
#define TOKEN_H

class Token{
public:
	// character has an integer value
  	Token(int i);
	getInPrior();
	getStackPrior();
	getId();

private:
	/*Priorities*/
	int inPrior;
	int stackPrior;
	int id;
};
	
class TokenOpenParen:Token{
public:
  	TokenOpenParen(int i);
};

class TokenCloseParen:Token{
public:
  	TokenCloseParen(int i);
};

class TokenDigit:Token{
public:
  	TokenDigit(int i);
};

class TokenPlusMinus:Token{
public:
  	TokenPlusMinus(int i);
};

class TokenDivMult:Token{
public:
  	TokenDivMult(int i);
};

class TokenExp:Token{
public:
  	TokenExp(int i);
};

class TokenEnd:Token{
public:
  	TokenEnd();
};

#endif;