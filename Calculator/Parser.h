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
        Parser(vector<Token*> inputVect);
       // ~Parser();
        
		void infixToPostfix();
        list<Token*> getPostFix() const;
        list<Token*> getOpStack() const;
        
private: 
        list<Token*> opStack;
        list<Token*> postFix;
        vector<Token*> input;

        //friend class Evaluator;
        
};

#endif
