#ifndef LEXER_H
#define LEXER_H

#include "Token.h"
#include "RuntimeException.h"
#include <string>
#include <vector>

using namespace std;
class Lexer{
public:
   	Lexer(string str);	

  	vector<Token*> v;
  	vector<Token*> get_v()const ;
  	string get_s()const ;
   	void break_into_tokens();
	void printfunc()const; 	

private:
  	string s;
};
#endif
