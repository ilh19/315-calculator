/*
<PARSER.CPP>
*/

#include "Parser.h"

Parser::Parser(vector<Token*> _input): input(_input) {
        TokenEnd end = TokenEnd(); ////fix
        opStack.push_back(end);
}

Parser::~Parser(){}

/*Member Functions*/

list<Token*> Parser::getPostFix() const{
        return postFix;
}

list<Token*> Parser::getOpStack() const{
        return opStack;
}

void Parser::infixToPostfix(){
        for (int i = 0; i < input.size(); i++){
                Token* inp = input[i];
                if (inp->getId()=='d'){ 
                        postFix.push_back(inp);
                }
                if(inp->getId()=='#'){
					while (!opStack.empty() && ((opStack.back())->getId())!='#') {
						postFix.push_back(opStack.back());
						opStack.pop_back();
                       // pop everything up to the END token and enqueue
					}
					//pop #?
                }
                if(inp is a TokenOpenParen){
                        opStack.push_back(inp);
                }
                if(inp is a TokenCloseParen){
					while (!opStack.empty() && ((opStack.back())->getId())!='(') {
						postFix.push_back(opStack.back());
						opStack.pop_back();
						//pop everything up to left paren (ignore paren)  and enqueue
					}
					if (!opStack.empty() && ((opStack.back())->getId())=='(') {
						opStack.pop_back();
					}
                }
                *Token temp = opStack.front();
                if(inp->getInPrior() >= temp->getStackPrior()) {
                        opStack.push(inp);
                }
                else{
                        postFix.enqueue(inp);
                
                }
        }

}

