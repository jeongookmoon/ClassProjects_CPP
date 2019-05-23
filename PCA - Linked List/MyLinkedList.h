#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H

#include <iostream>
using std::cout;

class MyLinkedList
{
    private:
    struct Node
    {
        int i;
        Node* next;
    }*head;

    public:
    MyLinkedList();

    void insert(int);
    void remove(int);
    double isEmpty();
    double search(int);
    double print();
    ~MyLinkedList(); /// for loop destruct until head == null


};

MyLinkedList::MyLinkedList()
{
    head = NULL;
}
MyLinkedList::~MyLinkedList()
{
    Node* p;

    while (head)
    {
        p = head;
        head = head-> next;
        delete p;
    }
}


void MyLinkedList::insert( int a )
{
    Node* p, *q;

    Node* n = new Node;
    n->i = a;

    if(head == NULL)
    {
        n->next = NULL;
        head = n;
        return;
    }

    if( a < head->i)
    {
        n->next = head;
        head = n;
        return;
    }
    for ( q = head, p=head->next; p!= NULL && a > p->i; q = q -> next, p= p -> next);
    if ( p = NULL)
    {
        p->next = NULL;
        q->next = n;
        return;
    }

    n->next = p;
    q->next = n;

}

void MyLinkedList::remove( int t )
{

    if (head == NULL)
    return;

    if (head->i == t)
    {
        Node* p = new Node;
        p = head;
        head = head->next;
        delete p;
        return;
    }
    Node* q = new Node;
    q = head;
    Node* p = new Node;
    p = head->next;


    for (; p!=NULL && p-> i !=t; q = q->next, p= p->next);
    if( p == NULL)
        return;

    q->next = q->next->next;

    delete p;
}

double MyLinkedList::print()
{

    Node* p = head;         // helper pointer

    cout << "Head->";

    while( p )              // while p is pointing to a node
    {
        cout << p->i << "->";   // print the contents of it
        p = p->next;            // move to the next one
    }

    cout << "NULL\n";
}

double MyLinkedList::search(int z)
{
    Node* p = new Node;
    p = head;

    while (p != NULL)
    {
        if(p->i == z)
        {
            return true;
        }
        p = p->next;
    }
    return false;
}

double MyLinkedList::isEmpty()
{
   if( head == NULL )
      return 1;
   return 0;
}



#endif
