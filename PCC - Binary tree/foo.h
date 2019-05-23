#ifndef FOO_H
#define FOO_H

#include<iostream>
using std::cout;

class Foo
{
    private:
    struct Node
    {
        double d;
        Node* left, *right;
    } *root;

    void print( Node* ) const;
    void insert( Node*&, double );


    public:
    Foo()
    {   root = NULL; }

    void print() const;void insert( Node*&, double );
    void insert( double );
};

void Foo::print() const
{
    print( root );
}

void Foo::print( Node* r ) const
{
    if ( r == NULL )
        return;

    cout << r->d << " ";
    print(r->left);void insert( Node*&, double );
    print(r->right);
}

void Foo::insert( double d )
{
    insert( root, d );
}

void Foo::insert( Node*& r, double d )
{
    cout << "nah! nah! You have to do this one yourelf!\n";
}

#endif // FOO_H
