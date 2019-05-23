#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class MyStack
{
    private:
        int top;
        int length;
        char stack[200];

    public:

    MyStack()
    {
        top = -1;
        length = 200;
    }

    bool isEmpty() const
    {
        return( top == -1 );
    }

    bool isFull() const
    {
        return ( top == (length - 1));

    }

    void push (char c)
    {
        if ( isFull() )
            return;
        top++;
        stack[top] = c;
    }

    void pop (char& c)
    {
        if ( isEmpty() )
            return;
        c = stack[top];
        top--;
    }
};

int main()
{
    MyStack s;

    char text[200];

    cout << "Gimme a string: ";
    cin.getline(text, 200);
    for (int i =0; text[i] != '\0'; i++)
        s.push(text[i]);

    char t;

    while (!s.isEmpty())
    {
        s.pop(t);
        cout << t;
    }
    cout << endl;

    return 0;
}
