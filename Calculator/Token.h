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
	virtual char getId() const = 0; // needs to be defined by derived classes

protected:
	/*Priorities*/
	int inPrior;
	int stackPrior;
};
	
class TokenOpenParen : public Token{
public:
  	TokenOpenParen();
	char getId() const;
};

class TokenCloseParen: public Token{
public:
  	TokenCloseParen();
	char getId() const;
};

class TokenDigit: public Token{
public:
  	TokenDigit(int i);
	char getId() const;
	int getValue() const;

private:
	int value;
};

class TokenPlusMinus : public Token{
public:
  	TokenPlusMinus();
	char getId() const;
};

class TokenDivMult : public Token{
public:
  	TokenDivMult();
	char getId() const;
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