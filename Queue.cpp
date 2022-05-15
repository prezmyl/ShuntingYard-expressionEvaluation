#include "Queue.hpp"

using namespace std;

Queue::Queue()
{
    //cout <<__func__<< endl;
    this->front = nullptr;
    this->rear = nullptr;
    this->count = 0;
}


size_t Queue::GetCount()
{
    //cout <<__func__<< endl;
    return this->count;
}

Node* Queue::GetFront()
{
    return this->front;
}

Node* Queue::GetRear()
{
    return this->rear;
}

bool Queue::isEmpty()
{
    if (this->front)
    {
        return false;
    }
    return true;
}

void Queue::Enque(string data)
{
    //cout <<__func__<< endl;
    Node* toAdd = new Node(data);
    if (this->rear)
    {   
        this->rear->SetNext(toAdd);
        this->rear = toAdd;
    }
    else
    {   
        this->rear = toAdd;
        this->front = toAdd;
    }
    this->count++;
    
    
}

string Queue::Deque()
{
    //cout <<__func__<< endl;
    if (this->front)
    {
        Node* toRemove = this->front;
        this->front = this->front->GetNext(); 
        if (!this->front)
        {
            this->rear = nullptr;
        }
        
        string data = toRemove->GetData();
        delete toRemove;
        return data;
    }

    return string();
}


void Queue::Display()
{
    Node *current = this->front;
    size_t i = 0;

    while (current)
    {
        cout << i << ".node\"" << current->GetData() << "\" | ";
        current = current->GetNext();
        i++;
    }

    cout << endl;
    
}

void Queue::DequeAll()
{
    while (!this->isEmpty())
    {
        this->Deque();
    }
}