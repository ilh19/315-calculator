/*
<LEXER.CPP>
*/
#include "Lexer.h"
#include "Token.h"
Lexer::
Lexer(string str):s(str){
}
  	//accessors
vector<Token>
Lexer::
get_v()const{
  	return v;
}
string
Lexer::
get_s()const{
  	return s;
}

  	//mutators
//void
//Lexer::
//break_into_tokens(){
//need to finish!
//}
  	//destructor
//Lexer::
//~Lexer(){
//  	delete v;
//}
