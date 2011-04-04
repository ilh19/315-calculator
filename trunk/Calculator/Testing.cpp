#include "Token.h"
#include "Parser.h"
#include "RuntimeException.h"
#include "Lexer.h"
#include <iostream>
#include <vector>
#include "Evaluator.h"


using namespace std;

int main(){
	
	string exp;
	while (exp != "q"){
	cout << "--Enter an expression to be evaluated: ";
	cin  >> exp;
	Lexer lex(exp);
	lex.break_into_tokens();
	lex.printfunc();
	Parser par(lex.v);
	par.infixToPostfix();
	//par.printfunc();
	Evaluator v(par);
	cout << "Value: " << v.evalExp() << endl;
	}
	//TokenOpenParen* tokOpen = new TokenOpenParen();
	//TokenCloseParen* tokClose = new TokenCloseParen();
	//TokenDigit* tokDigit1 = new TokenDigit(2);
	//TokenDigit* tokDigit2 = new TokenDigit(4);
	//TokenDigit* tokDigit3 = new TokenDigit(6);
	//TokenDigit* tokDigit4 = new TokenDigit(11);
	//TokenPlusMinus* tokPlus = new TokenPlusMinus('+');
	//TokenPlusMinus* tokMinus = new TokenPlusMinus('-');
	//TokenDivMult* tokMult = new TokenDivMult('*');
	//TokenDivMult* tokDiv = new TokenDivMult('/');
	//TokenExp* tokExp = new TokenExp();
	//TokenEnd* tokEnd = new TokenEnd();
	//
	//// 2+(4*6)^2-(11*(4/2)) = 556
	//vector<Token*> tokenVect = vector<Token*>();
	//tokenVect.push_back(tokDigit1);	
	//tokenVect.push_back(tokPlus);
	//tokenVect.push_back(tokOpen);
	//tokenVect.push_back(tokDigit2);
	//tokenVect.push_back(tokMult);
	//tokenVect.push_back(tokDigit3);
	//tokenVect.push_back(tokClose);
	//tokenVect.push_back(tokExp);
	//tokenVect.push_back(tokDigit1);
	//tokenVect.push_back(tokMinus);
	//tokenVect.push_back(tokOpen);
	//tokenVect.push_back(tokDigit4);	
	//tokenVect.push_back(tokMult);
	//tokenVect.push_back(tokOpen);
	//tokenVect.push_back(tokDigit2);	
	//tokenVect.push_back(tokDiv);
	//tokenVect.push_back(tokDigit1);
	//tokenVect.push_back(tokClose);
	//tokenVect.push_back(tokClose);
	//tokenVect.push_back(tokEnd);
//	//Token* tok;
//
//	/*for(int i=0; i < tokenVect.size(); i++){
//		tok = tokenVect[i];
//		cout << "ID: "<< tok->getId() << ": ";
//		cout << "Stack Priority: "<< tokenVect[i]->getStackPrior() << " ";
//		cout << "Input Priority: "<< tokenVect[i]->getInPrior() << endl;
//		if(tok->getId() == 'd'){
//			cout << "Value: " << tok->getValue() << endl;
//		}
//	}*/
//
//	/*
//	CHECK for :
//	Unary minus: -digit ; -( = 0-( ; digit - (; ()-() (-)3
//	*/
	try{
	//cout << ">>>Lexer Testing<<<<" << endl;
	//Lexer l("-   2    8 9 0 91    + - (4* -    6    )^2-(11*(4/-2   ))");
	//l.break_into_tokens();
	//cout << "String: " << l.get_s() <<endl;
	//l.printfunc();

	//cout << ">>>Parser Testing<<<<" << endl;
	//Parser p(tokenVect);
	//p.infixToPostfix();
	//p.printfunc();

	//cout << "Testing for lexer object" << endl;
	//Parser p2(l.get_v());
	//p2.infixToPostfix();
	//p2.printfunc();

	/*testing for atoi*/
	//const char* string = "-12345";
	//int digit = atoi(string);
	//cout<<"(atoi testing) Digit: " << digit <<endl;

//<<<<<<< .mine
	//Evaluator v(p);
	//cout << v.evalExp();

//=======
	//cout << "Testing for lexer object" << endl;
	//Lexer l2("-2--34--3");
	//l2.break_into_tokens();
	//cout << "String: " << l2.get_s() <<endl;
	//l2.printfunc();

//>>>>>>> .r28
	cin.get();
	return 1;
	}
	catch(RuntimeException &e){
		cerr << e<<endl;
		cin.get();
	}
}