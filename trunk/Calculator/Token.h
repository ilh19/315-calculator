/*
<TOKEN.H>
*/
#ifndef TOKEN_H
#define TOKEN_H

class Token{
public:
	// character has an integer value
  	Token(int i);
    int getInPrior() const ;
	int getStackPrior() const ;
	char getId() const; 
	int getValue() const;

protected:
	/*Priorities*/
	int inPrior;
	int stackPrior;
	char id;
	int value;
};
	
class TokenOpenParen : public Token{
public:
  	TokenOpenParen();
};

class TokenCloseParen: public Token{
public:
  	TokenCloseParen();
};

class TokenDigit: public Token{
public:
  	TokenDigit(int i);
	//int getValue() const;

//private:
//	int value;
};

class TokenPlusMinus : public Token{
public:
  	TokenPlusMinus(char c);
};

class TokenDivMult : public Token{
public:
  	TokenDivMult(char c);
};

class TokenExp: public Token{
public:
  	TokenExp();
};

class TokenEnd: public Token{
public:
  	TokenEnd();
};

#endif;