// implement a stack that holds characters
// 2 functions/methods: isFull, and isEmpty
// 2 methods for the operations push and pop.
// LIFO = last in first out
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class MyStack
{
    private:

    int length;
    int top;
    char stack[20];

    public:

    MyStack()
    {
        top = -1;
        length = 20;
    }

    bool isEmpty() const
    {
        return ( top == -1 );
    }

    bool isFull() const
    {
        return ( top == ( length - 1 ) );
    }

    void push( char c )
    {
        if ( isFull() )
            return;

        top++;
        stack[top] = c;
    }

    void pop( char& c )
    {
        if ( isEmpty() )
            return;

        c = stack[top];
        top--;
    }

    void dump() const
    {
        cout << "ARRAY: ";

        for ( int i = 0; i < length; i++ )
            cout << stack[i] << " ";

        cout << endl;

        cout << "TOP: " << top << endl;

        cout << "STACK: ";

        for ( int i = 0; i <= top; i++ )
            cout << stack[i] << " ";

        cout << endl;
    }
};




int main()
{
    MyStack s;

    s.dump();
    cout << "----" << endl;
    s.push('A');
    s.dump();
    cout << "----" << endl;
    s.push('Z');
    s.push('G');
    s.dump();
    cout << "----" << endl;
    for ( char c = 'a'; c < 'e'; c++ )
        s.push(c);
    s.dump();
    cout << "----" << endl;

    char t;
    s.pop(t);
    cout << t << endl;
    s.dump();
    cout << "----" << endl;

    while ( !s.isEmpty() )
    {
        s.pop(t);
        cout << t << " ";
    }
    cout << endl;

    cout << "----" << endl;
    s.dump();

    return 0;
}
