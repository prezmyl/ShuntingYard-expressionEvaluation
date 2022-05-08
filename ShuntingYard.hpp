#ifndef SHUNTINGYARD_HPP
#define SHUNTINGYARD_HPP
#include<iostream>
#include<string>

#include "Queue.hpp"
#include "Stack.hpp"
#include "ExpressionParser.hpp"
class ShuntingYard
{
    private:
        string input;
        string operators;
    public:
        ShuntingYard(string input, string operators, string parenthesis);
        int GetOperatorPrio(string op);
        bool IsNumeric(string str);
        bool IsOperator(char ch, string delimitrList);
};

#endif