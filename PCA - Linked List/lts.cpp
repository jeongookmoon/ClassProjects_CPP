#include <iostream>

using namespace std;

struct Node
{
    int x;
    Node* next;
};

Node* append(Node*, int);
Node* insert(Node*, int);
Node* traversal(Node* );
Node* deleteNode(Node*, int);
Node* destroy(Node*);


int main()
{
    Node* Head = NULL; /// empty

    /// append a new node with value 5

    Head = append (Head, 15);
    Head = append (Head, 10);
    Head = append (Head, 5);

    Head = traversal (Head);

    Head = insert (Head, 3);
    Head = traversal (Head);

    Head = insert (Head, 7);
    Head = traversal (Head);

    Head = insert (Head, 20);
    Head = traversal (Head);

    Head = deleteNode(Head, 7);
    Head = traversal (Head);

    Head = deleteNode(Head, 3);
    Head = traversal (Head);

    Head = deleteNode(Head, 20);
    Head = traversal (Head);

    Head = destroy (Head);

    cout << "Head=" << Head <<endl;



    return 0;
}

Node* append (Node* head, int i)
{
    /// Create a new node

    Node* newNode = new Node;
    newNode->x = i;
    newNode->next = NULL;

    /// check if linked list is empty. if so attach new node

    if( head == NULL)
    {
         head = newNode;
         return head;
    }

    /// if the list isn't empty
    Node* p = head; /// use temp pointer
    while( p->next )
        p = p->next;

    p->next = newNode;
    return head;


}

Node* insert (Node* head, int i)
{
    Node* newNode = new Node;
    newNode->x = i;

    if(head == NULL)
    {
        newNode->next = NULL;
        head = newNode;
        return head;
    }

    Node* prev=NULL, *p = head;

    if (newNode->x < head->x)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }

    while( p!= NULL && p->x > newNode->x)
    {
        prev = p;
        p = p->next;
    }
    /// insert node
    if( p == NULL)
    {
        prev->next = newNode;
        newNode->next = NULL;
        return head;
    }
    /// if p != NULL
    else
    {
        newNode -> next = p;
        prev->next = newNode;
        return head;
    }
}

Node* traversal(Node* head)
{
    Node* p = head;

    while(p)
    {
        cout << p->x << " ";
        p = p->next;
    }
    cout << endl;
    return head;
}

Node* deleteNode(Node* head, int i)
{
    if(head == NULL)
        return head;
    if(head->x == i)
    {
        Node* p = head;
        head =  head->next;
        delete p;
        return head;
    }
    Node* p = head, *prev;

    while(p!= NULL && p->x != i)
    {
        prev=p;
        p = p->next;
    }

    if(p == NULL)
    {
        return head;
    }
    if( p!= NULL)
    {
        prev->next = p->next;
        delete p;
        return head;
    }
}
Node* destroy(Node* head)
{
    Node* p = head;
    while (head)
    {
        p = head;
        head = head->next;
        delete p;
    }
    return NULL;
}
