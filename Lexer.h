/*
<LEXER.H>
*/
#ifndef LEXER_H
#define LEXER_H
#include "Token.h"
#include <string>
#include <vector>

using namespace std;
class Lexer{
public:
  	//constructor
  	Lexer(string);
  	//accessors
  	vector<Token> get_v()const ;
  	string get_s()const ;
  	//mutator
  	//void break_into_tokens();
  	//destructor
private:
  	vector<Token> v;
  	string s;
};
#endif
