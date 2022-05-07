#ifndef STACK_H
#define STACK_H

//#include<iostream>
//#include<string>
#include "Node.hpp"

class Stack
{
    private:
        Node* top;
        size_t count; 
    public:
        Stack();
        ~Stack();
        void Push(string data);
        string Pop();
        bool isEmpty();
        size_t GetCount();
        string GetTop();
        void Display();
};
#endif