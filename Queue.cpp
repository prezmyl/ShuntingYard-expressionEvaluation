#include "Queue.hpp"

using namespace std;

Queue::Queue()
{
    //cout <<__func__<< endl;
    this->front = nullptr;
    this->rear = nullptr;
    this->count = 0;
}

Queue::~Queue()
{
    //cout <<__func__<< endl;
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
        //pridavam do fronty, kde uz neco(ukazuje na to Stack.Rear) je, tak to co uz tam je musi ukazovat na novy vkladany   
        this->rear->SetNext(toAdd);
        //(Stack.Rear) ted prepojime na novy posledni(ten vkladany)
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
        this->front = this->front->GetNext(); //pokud posledni prvek tak ten ukazuje na null a to nam udela prazdnou frontu(o co this->rear?)
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
    //size_t total = this->count;
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