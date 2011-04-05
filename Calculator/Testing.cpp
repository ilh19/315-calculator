#include "Token.h"
#include "Parser.h"
#include "RuntimeException.h"
#include "Lexer.h"
#include <iostream>
#include <vector>
#include "Evaluator.h"


using namespace std;

int main(){
	for( ; ; ){
		try{	
			char * exp = new char[200];
			cout << "--Enter an expression to be evaluated: ";
			cin.getline(exp,200);

			Lexer lex(exp);   // FIX: when letters and symbols are entered!; fix the q to show "Bye!", makefile
			lex.break_into_tokens();
			lex.printfunc();
			Parser par(lex.v);
			par.infixToPostfix();
			Evaluator v(par);
			cout << "Value: " << v.evalExp() << endl;
		}
		catch(RuntimeException &e){
			cout<<"printing some exception" << endl;
			cerr << e << endl;
		}
	}
}