#include<iostream>
#include<string>

#include "Queue.hpp"
#include "Stack.hpp"
#include "ExpressionParser.hpp"

void shunting_yard()
{
    ;
}

void postfic_notion()
{
    ;
}


int main()
{   
    const string setOperators = "+-*/^()";
    const string input = "3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3"; //1.zp inicializace
    const string input2("3 + 4 * 2 / ( 1 - 5 )"); // 2.zp inicializace
    //cin << input;


    Queue* inputQueue = ExpressionParser::Split(input2, setOperators);
    inputQueue->Display();

    /*
    //Test Stack
    Stack myStack;
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
    
    //myStack.Display();

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