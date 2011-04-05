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

 void Lexer::break_into_tokens(){
	int count_right_parenthesis = 0;
	int count_left_parenthesis = 0;
	if(s.empty()) throw (RuntimeException("Empty String"));
	const char *string = s.c_str();
	while(*string != '\0'){
		char c = *string;     
		switch (c){
		case '+':
			{
			TokenPlusMinus* tokPlus = new TokenPlusMinus(c);
			v.push_back(tokPlus);
			string++;
			break;
		}
		case '-':   
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
		case '%':
			{
			TokenDivMult* tokMod = new TokenDivMult(c);
			v.push_back(tokMod);
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
			count_left_parenthesis++;
			TokenOpenParen* tokOpen = new TokenOpenParen();
			v.push_back(tokOpen);
			string++;
			break;
			}
		case ')':
			{
			count_right_parenthesis++;
			if (count_right_parenthesis > count_left_parenthesis) throw RuntimeException("Invalid Parenthesis");
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
				cout << "Bye!" << endl;
				exit(0);	
			}
			throw RuntimeException("Not a valid expression"); 
		default:
			{
				if(isdigit(c)){
					const int size = s.size()+1;
					char* digit = new char[size];			//	max size is the size of the input str
					char* digitIterator = digit;			//	used to iterate through the c_str
					char char_unary;
					int vSize;
					if(!v.empty()){							// there are tokens in the vector of tokens
						char_unary = v.back()->getId();		// gets the last token that was parsed
						vSize = v.size();
						
						if(char_unary == '-' && (vSize == 1 || v[vSize - 2]->getId() == '+' || v[vSize - 2]->getId() == '-' ||		
								v[vSize - 2]->getId() == '*' ||  v[vSize - 2]->getId() == '/' || v[vSize - 2]->getId() == '^'|| 
								v[vSize - 2]->getId() == '(')){
								
								digitIterator[0] = '-';		//checks for unary minus before the digit
								digitIterator++;
								v.pop_back();
						}
					}
					//gets more digits and skips spaces
					while(isdigit(c) || c == ' '){  
						while(c == ' '){ 
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
			else{  // not a digit or space or operator
				cout << "ERROR" << endl;
				throw RuntimeException("Not valid expression");  // it does not satisfy any of the above cases
				}
			}
		}	
	}
	if (count_left_parenthesis != count_right_parenthesis) throw RuntimeException("Unbalanced number of parentheses");
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


