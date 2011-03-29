/*
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
			TokenPlusMinus* tokMinus = new TokenPlusMinus(c);
			v.push_back(tokMinus);
			string++;
			break;
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
			if(s.size()==1){
				exit(0);	
			}
			throw NotValidExpressionException(); 
		default:
			{
			const int size = s.size()+1;
			char* digit = new char[size];	//	max size is the size of the input str
			char* digitIterator = digit;   //	used to iterate through the c_str
			char char_unary;
			int vSize;
			if(v.empty()){
				vSize = 0;
			}
			else{ 
				char_unary = v.back()->getId();  // gets the last token that was parsed
				vSize = v.size();
				if(char_unary == '-' && (vSize == 1 || v[vSize - 2]->getId() == '+' || v[vSize - 2]->getId() == '-' ||  v[vSize - 2]->getId() == '*' ||  v[vSize - 2]->getId() == '/' || v[vSize - 2]->getId() == '^'|| v[vSize - 2]->getId() == '(')){    //doesn't work for all the cases
					digitIterator[0] = '-'; 
					digitIterator++;
					v.pop_back();
				}
			}
			while(isdigit(c) || c == ' '){   
				while(c == ' '){ // TRY TO FIND A BETTER WAY
					string++;
					c = *string;
				}
				if(isdigit(c)){
					*digitIterator = c;
					digitIterator++;
					string++;
					c = *string;
				}
			}
			// converts c_str digit to int
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
