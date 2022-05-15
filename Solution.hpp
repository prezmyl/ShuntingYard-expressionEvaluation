#ifndef SOLUTION_HPP
#define SOLUTION_HPP
#include<iostream>
#include<string>

#include "Queue.hpp"
#include "Stack.hpp"
#include "ExpressionParser.hpp"
/*!
 Class Solution it is where most of the logic is stored and its methods execute ShuntingYard and Postfix evaluation algorithms
*/
enum Associates { none, left_to_right, right_to_left };

class Solution
{
    private:
        Queue* outputQ;
        string operators;
        float result;
    public:
        Solution(string operators);
        ~Solution();
        void ShuntingYard(Queue* inputQ);
        void PostfixEval();
        int GetOperatorPrio(string op);
        bool IsNumeric(string str);
        bool IsOperator(char ch, string delimitrList);
        int GetAssociate(string str);
        float Calculation(float x, float y, string op);
        float DisplayResult();
        
};

#endif