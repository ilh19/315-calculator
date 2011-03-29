﻿/*
<LEXER.CPP>
*/
#include "Lexer.h"
#include "Token.h"
#include <iostream>

using namespace std;

Lexer::Lexer(string str):s(str){
}

vector<Token*> Lexer::get_v()const{
  	return v;
}

string Lexer::get_s()const{
  	return s;
}

 void Lexer::break_into_tokens()throw (EmptyStringException,NotValidExpressionException){
	if(s.empty()) throw (EmptyStringException());
	bool unary = false;                      // boolean flag
	const char *string = s.c_str();
	while(*string != '\0'){
		char c = *string;     //THINK ABOUT OPTIMIZATION
		switch (c){
		case '+':
			{
			TokenPlusMinus* tokPlus = new TokenPlusMinus(c);
			v.push_back(tokPlus);
			string++;
			break;
		}
		case '-':   //check for unary minus  
			{
			string++;
			// = string;
			//char* digit = new char[size];
			c = *string; //new char[2];
			string--;
			//dig[0] = ;
			//dig[1] = '\0';
			//bool b = isdigit(c);
			if(isdigit(c)){  // assuming there are no spaces after it //FIX!!
				unary = true;
			}
			else{
				TokenPlusMinus* tokMinus = new TokenPlusMinus(c);
				v.push_back(tokMinus);
				string++;
				break;
			}
			}
		case '*':
			{
			TokenDivMult* tokMult = new TokenDivMult(c);
			v.push_back(tokMult);
			string++;
			break;
			}
		case '/':
			{
			TokenDivMult* tokDiv = new TokenDivMult(c);
			v.push_back(tokDiv);
			string++;
			break;
			}
		case '^':
			{
			TokenExp* tokExp = new TokenExp();
			v.push_back(tokExp);
			string++;
			break;
			}
		case '(':
			{
			TokenOpenParen* tokOpen = new TokenOpenParen();
			v.push_back(tokOpen);
			string++;
			break;
			}
		case ')':
			{
			TokenCloseParen* tokClose = new TokenCloseParen();
			v.push_back(tokClose);
			string++;
			break;
			}
		case ' ':
			string++;
			break;
		case 'q':
			exit(0);	
		default:
			{
			const int size = s.size()+1;
			char* digit = new char[size];	//	max size is the size of the input str
			char* digitIterator = digit;   //	used to iterate through the c_str
			if(unary){
				digitIterator[0] = '-';
				digitIterator++;
				unary = false;
			}
			while(isdigit(c)){
				*digitIterator = c;
				digitIterator++;
				string++;
				c = *string;
			}
			int number = atoi(digit);			
			TokenDigit* tokDig = new TokenDigit(number);
			v.push_back(tokDig);
			break;
		}
		throw NotValidExpressionException();  // it does not satisfy any of the above cases
		}
	}
}
 //!!! change to operator overloading
 void Lexer::printfunc()const{
	for(int i = 0; i < v.size(); i++){
		char c = v[i]->getId();
		if (c == 'd'){
			cout << v[i]->getValue() << " ";
		}
		else{
			cout << c << " ";
		}
	}
	cout << endl;
 }


  	//destructor
//Lexer::
//~Lexer(){
//  	delete v;
//}