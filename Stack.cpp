#include "Stack.hpp"

using namespace std;

Stack::Stack()
{
    cout <<__func__<< endl;
    this->top = nullptr;
    this->count = 0;
}

Stack::~Stack()
{
    cout <<__func__<< endl;
}

bool Stack::isEmpty()
{
    //cout <<__func__<< endl;
    if (this->top)
    {
        return false;
    }

    return true;
}

size_t Stack::GetCount()
{
    //cout <<__func__<< endl;
    return this->count;
}

string Stack::GetTop()
{
    //cout <<__func__<< endl;
    if (this->top)
    {
        return this->top->GetData();
    }
    return string();
    
}

void Stack::Display()
{
   // cout <<__func__<< endl;
    Node* current = this->top;
    while (current)
    {
        cout << current->GetData() << " "; 
        current = current->GetNext();
    }
    
    cout << endl;
    
    
}

void Stack::Push(string data)
{
    //cout <<__func__<< endl;
    Node *toAdd = new Node(data);
    //musim rozlisit prazdny/neprazdny?? poradi si s obojim??
    toAdd->SetNext(this->top);
    
    this->top = toAdd;
    this->count++;
}

string Stack::Pop()
{
    //cout <<__func__<< endl;
    if (this->top)
    {
        Node* toRemove = this->top;
        string data = toRemove->GetData();
        this->top = this->top->GetNext();
        this->count--;
        delete toRemove;
        return data;
    }
    
    return string();
    
}

