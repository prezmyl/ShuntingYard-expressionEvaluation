#ifndef EXPRESSIONPARSER_H
#define EXPRESSIONPARSER_H
#include<iostream>
#include "Queue.hpp"

using namespace std;

class ExpressionParser
{
    public:
        static bool IsThisDelimiter(char ch, string delimitrList);
        static Queue* Split(string input, string del);
};


#endif