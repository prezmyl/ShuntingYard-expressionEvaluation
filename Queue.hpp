#ifndef QUEUE_H
#define QUEUE_H
#include<iostream>
#include<string>

#include "Node.hpp"

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
        ~Queue();
        bool isEmpty();
        void Display();
        void DequeAll();

};


#endif
