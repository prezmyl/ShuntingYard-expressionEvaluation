#include "Stack.hpp"

using namespace std;

Stack::Stack()
{
    this->top = nullptr;
    this->count = 0;
}

bool Stack::isEmpty()
{
    if (this->top)
    {
        return false;
    }

    return true;
}

size_t Stack::GetCount()
{
    return this->count;
}

string Stack::GetTop()
{
    if (this->top)
    {
        return this->top->GetData();
    }
    return string();
    
}

void Stack::Display()
{
    cout <<__func__<< endl;
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
    Node *toAdd = new Node(data);
    toAdd->SetNext(this->top);
    
    this->top = toAdd;
    this->count++;
}

string Stack::Pop()
{
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

void Stack::PopAll()
{
    while (!(this->isEmpty()))
    {
        this->Pop();
    }
    
}

