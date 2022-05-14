#include<iostream>
#include<string>

#include "Queue.hpp"
#include "Stack.hpp"
#include "ExpressionParser.hpp"
#include "Solution.hpp"



//smas ty nepotrebne konstruktoru ve tridach!!

int main()
{   
    //input
    const string input = "3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3"; //1.zp inicializace
    const string input1("((3 + 4 * 2 / ( 1 - 5 )+"); // 2.zp inicializace
    const string input2("3 + 4 * 2 / ( 1 - 5 )");
    const string input3("4^2");
    //cin << input;

    //set of operators and parenthesis
    const string operators = "+-*/^";  //nebo neco jako enum??? vyctovym typem
    const string parenthesis = "()";

    Queue* inputQ = ExpressionParser::Split(input, operators + parenthesis);

    Solution* solution = new Solution(operators);
    solution->ShuntingYard(inputQ);
    solution->PostfixEval();
    cout << solution->DisplayResult()<< endl;


    delete solution;
    inputQ->DequeAll();
    inputQ->Display();
    delete inputQ;

    /*Queue* inputQueue = ExpressionParser::Split(input2, operators + parenthesis);
    inputQueue->Display();*/



    //EMPTY QUES STACKS to delete all objebcts MEMORY LEAKS!!!
    
    //Test Stack
   /* Stack myStack;
    for (size_t i = 0; i < 5; i++)
    {
        myStack.Push("sNODE" + to_string(i));
    }

    myStack.Display();

    cout << "poping: " << myStack.Pop() << endl;

    myStack.Display();

    //poping out the rest
    cout << "\npopping the rest" << endl;
    while (!(myStack.isEmpty()))
    {
        cout << "poping: " << myStack.Pop() << endl;
        cout << myStack.GetCount() << endl;
        myStack.Display();
        
    }
    
    myStack.Display();*/
    /*
    //test Queue
    Queue *myQueue = new Queue();

    for (size_t i = 0; i < 5; i++)
    {
        myQueue->Enque("qNODE" + to_string(i));
        myQueue->Display();
    }
    
    cout << "dequing: " << myQueue->Deque() << endl;
    myQueue->Display();

    cout << "\nDequing the rest:" << endl;
    while (myQueue->GetFront())
    {
        cout << "dequing: " << myQueue->Deque() << endl;
        myQueue->Display();
    }
    
    delete myQueue;
    */

 


    return 0;
}