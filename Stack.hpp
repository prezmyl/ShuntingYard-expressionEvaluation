#ifndef STACK_H
#define STACK_H

#include "Node.hpp"

/*!
    Class Stack with basic functionality. 
    Implemeted for practise class purposes. Has no robustness nor funcionality anywhere near the containers version
*/
class Stack
{
    private:
        Node* top;
        size_t count; 
    public:
        Stack();
        void Push(string data);
        string Pop();
        void PopAll();
        bool isEmpty();
        size_t GetCount();
        string GetTop();
        void Display();
};
#endif