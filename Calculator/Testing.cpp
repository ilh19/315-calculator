#include "Token.h"
#include <iostream>
#include <vector>


using namespace std;

int main(){
	TokenOpenParen* tokOpen = new TokenOpenParen();
	TokenCloseParen* tokClose = new TokenCloseParen();
	TokenDigit* tokDigit = new TokenDigit(33);
	TokenPlusMinus* tokPlus = new TokenPlusMinus('+');
	TokenPlusMinus* tokMinus = new TokenPlusMinus('-');
	TokenDivMult* tokMult = new TokenDivMult('*');
	TokenDivMult* tokDiv = new TokenDivMult('/');
	TokenExp* tokExp = new TokenExp();
	TokenEnd* tokEnd = new TokenEnd();
	
	vector<Token*> tokenVect = vector<Token*>();
	tokenVect.push_back(tokOpen);
	tokenVect.push_back(tokClose);
	tokenVect.push_back(tokDigit);
	tokenVect.push_back(tokPlus);
	tokenVect.push_back(tokMinus);
	tokenVect.push_back(tokMult);
	tokenVect.push_back(tokDiv);
	tokenVect.push_back(tokExp);
	tokenVect.push_back(tokEnd);
	Token* tok;

	for(int i=0; i < tokenVect.size(); i++){
		tok = tokenVect[i];
		cout << "ID: "<< tok->getId() << ": ";
		cout << "Stack Priority: "<< tokenVect[i]->getStackPrior() << " ";
		cout << "Input Priority: "<< tokenVect[i]->getInPrior() << endl;
		if(tok->getId() == 'd'){
			cout << "Value: " << tok->getValue() << endl;
		}
	}
	cin.get();
	return 1;
}