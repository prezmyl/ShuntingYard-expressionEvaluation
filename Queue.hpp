#ifndef QUEUE_H
#define QUEUE_H
#include<iostream>
#include<string>

#include "Node.hpp"

/*!
    Class Queue with basic functionality. 
    Implemeted for practise class purposes. Has no robustness nor funcionality anywhere near the containers version
*/
class Queue
{
    private:
        Node* front;
        Node* rear;
        size_t count;
    public:
        Queue();
        void Enque(string data);
        string Deque();
        size_t GetCount();
        Node* GetFront();
        Node* GetRear();
        bool isEmpty();
        void Display();
        void DequeAll();

};


#endif
