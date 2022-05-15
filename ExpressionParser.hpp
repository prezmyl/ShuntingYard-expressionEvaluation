#ifndef EXPRESSIONPARSER_H
#define EXPRESSIONPARSER_H
#include<iostream>
#include "Queue.hpp"

using namespace std;

/*!
 Class with static method that serve as a parser of the input string expression
*/
class ExpressionParser
{
    public:
        static bool IsThisDelimiter(char ch, string delimitrList);
        static Queue* Split(string input, string del);
};


#endif