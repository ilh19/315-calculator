#include "Token.h"
#include "Parser.h"
#include "RuntimeException.h"
#include "Lexer.h"
#include <iostream>
#include <vector>
#include "Evaluator.h"


using namespace std;

int main(){
try{	
	char * exp = new char[200];
	cout << "--Enter an expression to be evaluated: ";
	cin.getline(exp,200);
	while (exp != "q"){
		Lexer lex(exp);
		lex.break_into_tokens();
		lex.printfunc();
		Parser par(lex.v);
		par.infixToPostfix();
		Evaluator v(par);
		cout << "Value: " << v.evalExp() << endl;
		cout << "--Enter an expression to be evaluated: ";
		cin.getline(exp,200);
	}
	cin.get();
	return 1;
}
catch(RuntimeException &e){
	cerr << e<<endl;
	cin.get();
}
}