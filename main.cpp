/*!
*   Algoritmy I. zadani.2
*   Program returns a value of the given infix Math expression by transforming it into postfix and its evaluation
*   @author Premysl Polas POL0511
*/

#include<iostream>
#include<string>

#include "Queue.hpp"
#include "Stack.hpp"
#include "ExpressionParser.hpp"
#include "Solution.hpp"


int main()
{   
    //inputs
    const string input = "3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3";
    //const string input("((2-40)^2)^10/4");

    //set of operators and parenthesis
    const string operators = "+-*/^";
    const string parenthesis = "()";

    Queue* inputQ = ExpressionParser::Split(input, operators + parenthesis);

    Solution* solution = new Solution(operators);
    solution->ShuntingYard(inputQ);
    solution->PostfixEval();
    cout << solution->DisplayResult()<< endl;

    delete solution;
    inputQ->DequeAll();
    delete inputQ;

    return 0;
}