/*
<PARSER.H>
*/
#ifndef PARSER_H
#define PARSER_H
#include "Token.h" 
#include <list>
#include <vector>

using namespace std;
class Parser{
public: 
	/*Constructor*/
	Parser(vector<Token> _input);
	/*Destructor*/
	~Parser();
	//getToken(); don't think we need a get token
	/*Member Functions*/
	void infixToPostfix();
	/*Accessors*/
	list<Token> getPostFix() const;
	list<Token> getOpStack() const;
	
private: 
	list<Token> opStack;
	list<Token> postFix;
	vector<Token> input;

	//friend class Evaluator;
	
};

#endif