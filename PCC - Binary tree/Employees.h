#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;

class Employees {
  private:
    struct Node {
      int id;
      string name;
      Node* left, *right;
    } *root;

    void print( Node* ) const;
    void destroyTree( Node* );
    void insert( Node*&, Node*&);
    void deleteNode(int, Node*&);
    void makeDeletion(Node*, Node*&);
    int count(Node*);

  public:
    Employees() {
      root = NULL;
    }

    ~Employees() {
      destroyTree(root);
    }
    void print() const {
      print(root);
    };
    void insert(int, string);
    void remove(int);
    bool search(int);
    int count() {
      int i = count(root);
      cout<< "There is(are) "<< i << " Employee(s)" << endl;
      return i;
    }
};

void Employees::destroyTree(Node* nodePtr) {
  if (nodePtr) {
    if(nodePtr->left)
      destroyTree(nodePtr->left);
    if(nodePtr->right)
      destroyTree(nodePtr->right);
    delete nodePtr;
  }
}

void Employees::print(Node *nodePtr) const {
  if(nodePtr) {
    print(nodePtr->left);
    print(nodePtr->right);
    cout << nodePtr->id << " " << nodePtr->name << endl;
  }
}

void Employees::insert(Node*& nodePtr, Node*& newNode)
{
  if(nodePtr == NULL)
    nodePtr = newNode; /// insert node
  else if(newNode->id < nodePtr->id)
    insert(nodePtr->left, newNode); /// left
  else
    insert(nodePtr->right, newNode); /// right
}

void Employees::insert(int num, string value) {
  Node* newNode; /// pointer for a new node

  newNode = new Node;
  newNode->id = num;
  newNode->name = value;
  newNode->left = newNode->right = NULL;

  insert(root, newNode);
}

void Employees::remove(int num) {
  deleteNode(num, root);
}

void Employees::deleteNode( int num, Node*& nodePtr) {
  Node *p, *t, *r;
  if ( nodePtr == NULL) {
    return;
  }
  p=nodePtr;
  t=nodePtr;
  while(t!=NULL) {
    if(num == t->id) {
      break;
    }
    p=t;
    if (num < t->id) {
      t=t->left;
    } else { /// if (num > nodePtr->id)
      t=t->right;
    }
  }
  /// In case not found
  if(t==NULL) {
    return;
  }
  /// in case found
  if(t->left==NULL) {
      /// deleting node having no left child
    makeDeletion(p, t);
  } else if(t->right==NULL) {
    /// having left child but no right child
    makeDeletion(p, t);
  } else {
    /// having both left and right children
    /// finding another node that's bigger than this but also in the closest
    p=t;
    r=t->right;
    /// finding the smallest value node among bigger nodes
    while(r->left) {
      p=r;
      r=r->left;
    }
    /// After copying substitute node to nodePtr
    t->id=r->id;
    t->name=r->name;
    /// deleting substitute node
    makeDeletion(p, r);
  }
}

void Employees::makeDeletion(Node *parent, Node*& nodePtr) {
  if(nodePtr == NULL) {
    cout << "Can't delete empty node\n";
  } else if (nodePtr->id<parent->id) {
    Node* tempNodePtr=nodePtr;
    if(nodePtr->right==NULL) {
      parent->left = nodePtr->left;
    } else {
      parent->left = nodePtr->right;
    }
    delete tempNodePtr;
  } else {
    Node* tempNodePtr=nodePtr;
    if(nodePtr->right==NULL) {
      parent->right = nodePtr->left;
    } else {
      parent->right = nodePtr->right;
    }
    delete tempNodePtr;
  }
}
bool Employees::search(int num) {
  Node* nodePtr = root;

  while (nodePtr) {
    if (nodePtr->id == num) {
      cout << "Found\n";
      return true;
    } else if (num < nodePtr->id)
      nodePtr = nodePtr->left;
    else
      nodePtr = nodePtr->right;
  }
  cout << "Not found\n";
  return false;
}

int Employees::count(Node* nodePtr) {
  if(nodePtr == NULL) {
    return 0;
  } else {
    return count(nodePtr->left) +1 + count(nodePtr->right);
  }
}
#endif
