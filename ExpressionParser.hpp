#ifndef EXPRESSIONPARSER_H
#define eXPRESSIONPARSER_H
#include<iostream>
#include "Queue.hpp"

using namespace std;

class ExpressionParser
{
    public:
        static Queue* Split(string input, string del);
};


#endif