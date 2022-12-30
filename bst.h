#ifndef BST_H
#define BST_H

#include <string>

using namespace std;

class Node{
  public:
    string key;
    Node *left, *right, *parent;
    Node(){
      left = right = parent = NULL;
    }
    Node (string val){
      key = val;
      left = right = parent = NULL;
    }
};

class BST{
  private:
    Node*root;
  public:
    BST(); //default constructor set root to null
    void insert(string);
    void insert (Node *, Node*);
    int search(string, string);
    int search(int&, string, string, Node*);
    void Preorder();
    void Preorder(Node*);
};
#endif
