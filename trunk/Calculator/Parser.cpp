/*
<PARSER.CPP>
*/

#include "Parser.h"

Parser::Parser(vector<Token> _input): input(_input) {
	TokenEnd end = TokenEnd(); ////fix
	opStack.push_back(end);

}

Parser::~Parser(){}

/*Member Functions*/

list<Token> Parser::getPostFix() const{
	return postFix;
}

list<Token> Parser::getOpStack() const{
	return opStack;
}

void Parser::infixToPostfix(){
	for (int i = 0; i < input.size(); i++){
		Token inp = input[i];
		if (inp is a TokenOperand){ 
			postFix.enqueue(inp);
		}
		if(inp is TokenEnd){
			pop everything up to the END token and enqueue
		}
		if(inp is a TokenOpenParen){
			opStack.push(inp);
		}
		if(inp is a TokenCloseParen){
			pop everything up to left paren (ignore paren)  and enqueue
		}
		Token temp = opStack.pop();
		if(inp.inPriors >= temp.stackPriors){
			opStack.push(inp);
		}
		else{
			postFix.enqueue(inp);
		
		}
	}

}

	