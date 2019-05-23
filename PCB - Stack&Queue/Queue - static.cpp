class MyQueue
{
    private:
    int front, rear, inLine;
    int q[10];

    public:
    MyQueue();
    bool isFull() const;
    bool isEmpty() const;
    void enqueue( int );
    void dequeue( int&);

};
MyQueue::MyQueue()
{
    front = rear = inLine = 0;
}
bool MyQueue::isEmpty()const
{
    return inLine == 0;

}

bool MyQueue::isFull() const
{
    return inLine == 10;
}

void MyQueue::enqueue ( int value )
{
    if (isFull())
        return;
    q[rear] = value;
    rear++
    inLine++

    if(rear == 10)
        rear = 0;
}

void MyQueue::dequeue (int& value)
{
    if(isEmpty())
        return;
    value = q[front];
    front++;
    inLine--;

    if(front == 10)
        front = 0;
}
