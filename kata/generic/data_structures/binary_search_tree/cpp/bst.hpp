#ifndef BST
#define BST

#include <iostream>
#include <math.h>
#include <vector>

struct Node {
  int value;
  Node *left;
  Node *right;
};

class bst {
public:
  bst();
  ~bst();

  bool isBalanced();
  bool isValid();
  bool searchBFS(int query);
  bool searchBinary(int query);
  bool searchDFS(int query);
  std::vector<int> formatPrettyPrint();
  void destroyTree();
  void insert(int key);
  void printInfix();
  void printPostfix();
  void printPrefix();
private:
  Node *root;

  bool isBalanced(Node* leaf);
  bool searchBinary(int query, Node* leaf);
  bool searchDFS(int query, Node* leaf);
  bool validateBST(Node* leaf, int min, int max);
  int calcHeight(Node* leaf);
  int sizePerfectBST();
  void destroyTree(Node *leaf);
  void insert(int key, Node *leaf);
  void printInfix(Node *leaf);
  void printPostfix(Node *leaf);
  void printPrefix(Node *leaf);
};

#endif
