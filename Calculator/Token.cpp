﻿//<TOKEN.CPP>
#include "Token.h"

	/*
Token:          +   −   /   *   ^    (            )            operand       END
input priority:	1   1   3   3   6    100          0                 0         0
stack priority: 2   2   4	4    5   0           99                 0 	     −1
*/  
	//enum inPriors { factor = 6, mult = 3, div = 3, add = 1, sub=1,  oParen=100, cParen = 0, end = 0};
	//enum stackPriors {factor = 5, mult = 4, div = 4, add = 2, sub=2,  oParen=0, cParen = 99, end = -1};


Token::Token (int i):id(i){}

int Token::getInPrior() const {
	return inPrior;
}

int Token::getStackPrior() const {
	return stackPrior;
}

char Token::getId() const {
	return id;
}

int Token::getValue() const {
	return value;
}
	
TokenOpenParen::TokenOpenParen() : Token('(') {
	inPrior = 100;
	stackPrior = 0;
}

TokenCloseParen::TokenCloseParen() : Token(')') {
	inPrior = 0;
	stackPrior = 99;
}

TokenDigit::TokenDigit(int i): Token('d'){
	inPrior = 0;
	stackPrior = 0;
	value = i;
}

TokenPlusMinus::TokenPlusMinus(char c) : Token(c) {
	inPrior = 1;
	stackPrior = 2;
}

TokenDivMult::TokenDivMult(char c) : Token(c) {
	inPrior = 3;
	stackPrior = 4;
}

TokenExp::TokenExp() : Token('^') {
	inPrior = 6;
	stackPrior = 5;
}

TokenEnd::TokenEnd() : Token('#') { 
	inPrior = 0;
	stackPrior = -1;
}