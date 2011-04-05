/*
<PARSER.H>
*/
#ifndef PARSER_H
#define PARSER_H
#include "Token.h" 
#include <list>
#include <vector>
#include <queue> 

using namespace std;
class Parser{
public: 
        Parser(vector<Token*> inputVect);
        
		void infixToPostfix();
		list<Token*> postFix;
        list<Token*> getPostFix() const;
        list<Token*> getOpStack() const;
		void printfunc();
        
private: 
        list<Token*> opStack;
        vector<Token*> input;
};

#endif
