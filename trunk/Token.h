/*
<TOKEN.H>
*/
#ifndef TOKEN_H
#define TOKEN_H
class Token{
public:
  	Token(char);
  	Token(int);
/*
Token:          +   −   /   *   ^    (            )            operand       END
input priority:	1   1   3   3   6    100          0                 0         0
stack priority: 2   2   4	4    5   0           99                0 	     −1
*/  
	enum inPriors { factor = 6, mult = 3, div = 3, add = 1, sub=1,  oParen=100, cParen = 0, end = 0};
	enum stackPriors {factor = 5, mult = 4, div = 4, add = 2, sub=2,  oParen=0, cParen = 99, end = -1};


};
class TokenOpenParen{
public:
  	TokenOpenParen(char);
private:
  	char par;
};

class TokenCloseParen{
public:
  	TokenCloseParen(char);
private:
  	char par;
};

class TokenDigit{
public:
  	TokenDigit(int);
private:
  	int digit;
};
class TokenOperator{
public:
  	TokenOperator(char,int);
private:
  	int prior;
  	char oper;
};
////////FIX
class TokenEnd{
public:
  	TokenEnd();
private:
  	int prior;
  	char oper;
};

#endif;