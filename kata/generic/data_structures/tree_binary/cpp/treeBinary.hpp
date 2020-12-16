#ifndef TREE_BINARY
#define TREE_BINARY

#include <iostream>

struct Node {
  int value;
  Node *left;
  Node *right;
};

class TreeBinary {
  public:
    TreeBinary();
    ~TreeBinary();
    void insert(int key);
    Node *search(int key);
    void destroyTree();
    void printInfix();
    void printPostfix();
    void printPrefix();
private:
    void destroyTree(Node *leaf);
    void insert(int key, Node *leaf);
    Node *search(int key, Node *leaf);
    void printInfix(Node *leaf);
    void printPostfix(Node *leaf);
    void printPrefix(Node *leaf);
    Node *root;
};

#endif
