#include<iostream>
#include<string>

#include "Queue.hpp"
#include "Stack.hpp"
#include "ExpressionParser.hpp"
#include "Solution.hpp"


int main()
{   
    //inputs
    const string input = "3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3"; //1.zp inicializace
    //const string input("((2-4)^2)^3/4");

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