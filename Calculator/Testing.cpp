#include "Token.h"
#include <iostream>
#include <vector>
#include "Parser.h"

using namespace std;

int main(){
	TokenOpenParen* tokOpen = new TokenOpenParen();
	TokenCloseParen* tokClose = new TokenCloseParen();
	TokenDigit* tokDigit1 = new TokenDigit(2);
	TokenDigit* tokDigit2 = new TokenDigit(4);
	TokenDigit* tokDigit3 = new TokenDigit(6);
	TokenDigit* tokDigit4 = new TokenDigit(11);
	TokenPlusMinus* tokPlus = new TokenPlusMinus('+');
	TokenPlusMinus* tokMinus = new TokenPlusMinus('-');
	TokenDivMult* tokMult = new TokenDivMult('*');
	TokenDivMult* tokDiv = new TokenDivMult('/');
	TokenExp* tokExp = new TokenExp();
	TokenEnd* tokEnd = new TokenEnd();
	
	// 2+(4*6)^2-(11*(4/2)) = 556
	vector<Token*> tokenVect = vector<Token*>();
	tokenVect.push_back(tokDigit1);	
	tokenVect.push_back(tokPlus);
	tokenVect.push_back(tokOpen);
	tokenVect.push_back(tokDigit2);
	tokenVect.push_back(tokMult);
	tokenVect.push_back(tokDigit3);
	tokenVect.push_back(tokClose);
	tokenVect.push_back(tokExp);
	tokenVect.push_back(tokDigit1);
	tokenVect.push_back(tokMinus);
	tokenVect.push_back(tokOpen);
	tokenVect.push_back(tokDigit4);	
	tokenVect.push_back(tokMult);
	tokenVect.push_back(tokOpen);
	tokenVect.push_back(tokDigit2);	
	tokenVect.push_back(tokDiv);
	tokenVect.push_back(tokDigit1);
	tokenVect.push_back(tokClose);
	tokenVect.push_back(tokClose);
	tokenVect.push_back(tokEnd);
	Token* tok;

	/*for(int i=0; i < tokenVect.size(); i++){
		tok = tokenVect[i];
		cout << "ID: "<< tok->getId() << ": ";
		cout << "Stack Priority: "<< tokenVect[i]->getStackPrior() << " ";
		cout << "Input Priority: "<< tokenVect[i]->getInPrior() << endl;
		if(tok->getId() == 'd'){
			cout << "Value: " << tok->getValue() << endl;
		}
	}*/
	
	Parser p(tokenVect);
	p.infixToPostfix();
	
	p.printfunc();

	cin.get();
	return 1;
}