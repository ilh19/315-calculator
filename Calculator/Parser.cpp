/*
<PARSER.CPP>
*/

#include "Parser.h"

Parser::Parser(vector<Token*> inputVect): input(inputVect) {
		TokenEnd* end = new TokenEnd(); 
        opStack.push_back(end);
}

//Parser::~Parser(){}

list<Token*> Parser::getPostFix() const{
        return postFix;
}

list<Token*> Parser::getOpStack() const{
        return opStack;
}

void Parser::infixToPostfix(){
        for (int i = 0; i < input.size(); i++){
                Token* inp = input[i];
				char id = inp->getId();
                if (id =='d'){ 
                        postFix.push_back(inp);
                }
                if(id =='#'){ // pop everything up to the END token and enqueue
					while (!opStack.empty() && ((opStack.back())->getId())!='#') {
						postFix.push_back(opStack.back());
						opStack.pop_back();
					}
					opStack.pop_back();
					return;
					//pop #?
                }
                if(id == '('){
                        opStack.push_back(inp);
                }
                if(id == ')'){
					while (!opStack.empty() && ((opStack.back())->getId())!='(') {
						postFix.push_back(opStack.back());
						opStack.pop_back();
						//pop everything up to left paren (ignore paren)  and enqueue
					}
					if (!opStack.empty() && ((opStack.back())->getId())=='(') {
						opStack.pop_back();
					}
                }
                Token* temp = opStack.back(); 
				while (temp->getStackPrior() >= inp->getInPrior()) { //pop from stack into queue those operators with stack priority > input priority
					postFix.push_back(temp);
					opStack.pop_back();
					if (!opStack.empty()) temp = opStack.back();
					else break;
				}
				
				opStack.push_back(inp); //push current operator into stack
				
               /* if(inp->getInPrior() >= temp->getStackPrior()) {
                        opStack.push_back(inp);
                }
                else{
                        postFix.push_back(inp);
                
                }*/
        }

}

