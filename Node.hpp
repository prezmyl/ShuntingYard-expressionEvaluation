#ifndef NODE_H
#define NODE_H
#include<iostream>
#include<string>

using namespace std;

class Node
{
    private:
        string data;
        Node* next;
    public:
        Node(string data);
        string GetData();
        Node* GetNext();
        void SetNext(Node* ptr);
};

#endif