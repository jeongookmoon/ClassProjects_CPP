#include <iostream>
using namespace std;

/*
    Notes:
    left child value < parent value < right child value
    leaf node: node with no children
    root node: the first node in the list
    parent nodes: have 1 or 2 children.
    child node:  node attached to a parent
*/

/*******************************
     NODE DEFINITION
*******************************/

struct Node
{
    char value;
    Node* left, *right;
};


/*******************************
     FUNCTION PROTOTYPES
*******************************/


Node* createLeaf( char );   // creates an new leaf
void pre_print( Node* );    // print tree - pre-order
void in_print( Node* );     // print tree - in-order
void post_print( Node* );   // print tree - post-order
void destroy( Node* );      // destroys the tree
void addLeaf( Node*&, Node*& ); // add a leaf to the tree
bool search( Node*, char ); // search the tree
void remove( Node*&, char );// removes a node from the tree
void _remove( Node*& );     // helps remove
Node* goleft( Node* );      // moves down the left side of a subtree

int main()
{
    // tree is empty
    Node* tree = NULL;

    // add some leaves
    Node* leaf = NULL;
    leaf = createLeaf( 'G' );
    addLeaf( tree, leaf );
    leaf = createLeaf( 'O' );
    addLeaf( tree, leaf );
    leaf = createLeaf( 'B' );
    addLeaf( tree, leaf );
    leaf = createLeaf( 'D' );
    addLeaf( tree, leaf );
    leaf = createLeaf( 'J' );
    addLeaf( tree, leaf );
    leaf = createLeaf( 'A' );
    addLeaf( tree, leaf );
    leaf = createLeaf( 'S' );
    addLeaf( tree, leaf );
    remove( tree, 'G' );


    in_print( tree );


    // search the tree for 'B'
    bool found;
    found = search( tree, 'B' );
    cout << endl;
    if ( found )
        cout << "value found!\n";
    else
        cout << "Value not found!\n";

    // print the tree - preorder
    pre_print( tree );
    cout << endl;

    // print the tree - inorder
    in_print( tree );
    cout << endl;

    // print the tree - postorder
    post_print( tree );
    cout << endl;

    //destroy the tree
    destroy( tree );
    tree = NULL;

    return 0;
}

/*******************************
     FUNCTION DEFINITIONS
*******************************/

// creates an new leaf
Node* createLeaf( char c )
{
    Node* leaf = new Node;
    leaf->value = c;
    leaf->left = leaf->right = NULL;
    return leaf;
}

// print tree - pre-order
void pre_print( Node* p )
{
    // base case
    if ( p == NULL )
        return;
    // recursive case
    else
    {
        cout << p->value << " ";
        pre_print( p->left );
        pre_print( p->right );
    }
}

// print tree - in-order
void in_print( Node* p )
{
    // base case
    if ( p == NULL )
        return;
    // recursive case
    else
    {
        in_print( p->left );
        cout << p->value << " ";
        in_print( p->right );
    }
}

// print tree - post-order
void post_print( Node* p )
{
    // base case
    if ( p == NULL )
        return;
    // recursive case
    else
    {
        post_print( p->left );
        post_print( p->right );
        cout << p->value << " ";
    }
}

// add a leaf to the tree
void addLeaf( Node*& p, Node*& leaf )
{
    // if tree is empty
    if ( !p)
        p = leaf;
    // go left
    else if ( leaf->value < p->value )
        addLeaf(p->left, leaf );
    // go right
    else
        addLeaf( p->right, leaf );
}

// destroys the tree
void destroy( Node* p )
{
    // base case
    if ( p == NULL )
        return;
    // recursive calls
    else
    {
        destroy( p->left );
        destroy( p->right );
        delete p;
    }
}

// tree for target
bool search( Node* p, char target )
{
    // check current node:

    // arriving at NULL means we've searched the
    //   tree and haven't found the target
    if ( p == NULL )
        return false;

    // found it
    else if ( p->value == target )
        return true;

    // haven't found it - search one of the children

    // search left
    else if ( target < p->value )
        return search( p->left, target );

    // search right
    else
        return search( p->right, target );
}

// removes a node from the tree
void remove( Node*& p, char target )
{
    // list empty, nothing to do
    if ( p == NULL )
        return;
    // check root
    if ( p->value == target )
        _remove( p );
    // move to one of the children
    // go left
    if ( target < p->value )
        remove( p->left, target );
    // go right
    else
        remove( p->right, target );
}

// helps remove
void _remove( Node*& p )
{
    // helper pointer
    Node* r;

    // node has just left child
    if ( p->right == NULL )
    {
        r = p;
        p = p->left;
        delete r;
    }

    // node has just right child
    else if ( p->left == NULL )
    {
        r = p;
        p = p->right;
        delete r;
    }

    // node has two children
    else
    {
        // move r one node to the right
        r = p->right;

        // move r to the end left node
        r = goleft( r );

        // reattach left subtree
        r->left = p->left;
        r = p;

        // reattach right subtree
        p = p->right;

        // delete target node
        delete r;
    }
}

// moves down the left side of a subtree
Node* goleft( Node* p )
{
    if ( p->left == NULL )
        return p;
    else
        return goleft( p->left );
}
