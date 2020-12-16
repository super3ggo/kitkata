#include "treeBinary.hpp"

TreeBinary::TreeBinary() {
  root = NULL;
}

TreeBinary::~TreeBinary() {
  destroyTree();
}

//
// public
//

void TreeBinary::insert(int key){
  if (root != NULL) {
    insert(key, root);
  } else {
    root        = new Node;
    root->value = key;
    root->left  = NULL;
    root->right = NULL;
  }
}

Node *TreeBinary::search(int key) {
  return search(key, root);
}

void TreeBinary::destroyTree() {
  destroyTree(root);
}

void TreeBinary::printInfix() {
  printInfix(root);
  std::cout << "\n";
}

void TreeBinary::printPostfix() {
  printPostfix(root);
  std::cout << "\n";
}

void TreeBinary::printPrefix() {
  printPrefix(root);
  std::cout << "\n";
}

//
// private
//

void TreeBinary::destroyTree(Node *leaf) {
  if (leaf != NULL) {
    destroyTree(leaf->left);
    destroyTree(leaf->right);
    delete leaf;
  }
}

void TreeBinary::insert(int key, Node *leaf) {
  if (key < leaf->value) {           // go left
    if (leaf->left != NULL) {
      insert(key, leaf->left);
    } else {                         // terminal
      leaf->left        = new Node;
      leaf->left->value = key;
      leaf->left->left  = NULL;
      leaf->left->right = NULL;
    }
  }
  if (key >= leaf->value) {          // go right
    if (leaf->right != NULL) {
      insert(key, leaf->right);
    } else {                         // terminal
      leaf->right        = new Node;
      leaf->right->value = key;
      leaf->right->right = NULL;
      leaf->right->left  = NULL;
    }
  }
}

Node *TreeBinary::search(int key, Node *leaf) {
  if (leaf != NULL) {
    if (key == leaf->value) {
      return leaf;
    } else if (key < leaf->value) {
      return search(key, leaf->left);
    } else {
      return search(key, leaf->right);
    }
  } else {
    return NULL;
  }
}

void TreeBinary::printInfix(Node *leaf) {
  if (leaf != NULL) {
    printInfix(leaf->left);
    std::cout << leaf->value << ",";
    printInfix(leaf->right);
  }
}

void TreeBinary::printPrefix(Node *leaf) {
  if (leaf != NULL) {
    std::cout << leaf->value << ",";
    printInfix(leaf->left);
    printInfix(leaf->right);
  }
}

void TreeBinary::printPostfix(Node *leaf) {
  if (leaf != NULL) {
    printInfix(leaf->left);
    printInfix(leaf->right);
    std::cout << leaf->value << ",";
  }
}
