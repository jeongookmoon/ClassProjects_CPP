#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <iostream>

class MyQueue
{
    private:
        int front, back, line;
        int a[20];

    public:
    MyQueue();
    bool isFull() const;
    bool isEmpty() const;
    void enqueue( char );
    void dequeue( char&);

};

MyQueue::MyQueue()
{
    front = back = line = 0;
}

bool MyQueue::isFull() const
{
    return(line == 20);
}
bool MyQueue::isEmpty() const
{
    return(line == 0);
}
void MyQueue::enqueue( char c )
{
    if(isFull())
        return;
    a[back] = c;
    back++;
    line++;
    if(back == 20)
        back = 0;
}

void MyQueue::dequeue( char& c )
{
    if(isEmpty())
        return;
    c = a[front];
    front++;
    line--;
    if(front == 20)
        front = 0;
}


#endif // MYQUEUE_H
