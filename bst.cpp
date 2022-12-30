#include "bst.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <stdexcept>
#include <array>
#include <cstring>
#include <fstream>
#include <sstream>
using namespace std;

//lets construct the tree shall we
BST :: BST() {root = NULL;}

void BST :: insert(string val){
  Node* insert_me = new Node(val);
  if(root == NULL) root = insert_me;
  else {
    insert(root, insert_me);
  }
}

void BST::insert(Node*start, Node*insert_me){
  if(start == NULL) return;
  if(insert_me->key.compare(start->key)==0) return; //it exist on tree
  else if(insert_me->key.compare(start->key)<0) { // we go lefty
    if(start->left == NULL){ //we basically want to put it at the end as a leaf
      start->left = insert_me;
      insert_me->parent = start;
      return;
    } else{ //we keep going
      insert(start->left, insert_me);
      return;
    }

  } else if(insert_me->key.compare(start->key)>0){ //we go righty
    if(start->right==NULL){//do the same as above but with right side
      start->right = insert_me;
      insert_me->parent = start;
      return;
    }else{
      insert(start->right, insert_me);
      return;
    }
  } 
  return;//should not go here but just in case
}

int BST::search(string a, string b){
  int counter = 0;
  return search(counter, a, b, root);
}

int BST::search(int &counter, string a, string b, Node*start){
  if (start==NULL) {return 0;}
  if (a == start->key || b == start->key){
    counter++;
    // cout<<counter<<endl;
  }
  else if((start->key.compare(a)>0)&&(start->key.compare(b)<0)){
    counter++;
    // cout<<counter<<endl;
  }
  search(counter, a, b, start->left);
  search(counter, a, b, start->right);
  return counter;

}


void BST::Preorder(){
  Preorder(root);
  return;
}

void BST::Preorder(Node*start){
  if(start==NULL) return;
  cout<<start->key<<endl;
  Preorder(start->left);
  Preorder(start->right); 
}

