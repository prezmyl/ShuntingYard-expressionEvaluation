#include "Node.hpp"

Node::Node(string data)
{
    cout <<__func__<< endl;
    this->data = data;
    this->next = nullptr;
}

Node::~Node()
{
    cout <<__func__<< endl;
}

string Node::GetData()
{
    return this->data;
}

Node* Node::GetNext()
{
    return this->next;
}

void Node::SetNext(Node* ptr)
{
    this->next = ptr;
}