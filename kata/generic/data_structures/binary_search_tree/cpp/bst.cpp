#include "bst.hpp"

//
// public
//

bst::bst() {
  root = NULL;
}

bst::~bst() {
  destroyTree();
}

bool bst::isBalanced() {
  // Determine whether the BST is balanced, i.e. the heights of its SubTrees
  // differ by no more than one Node.
  //
  // Call the private method of the same name to determine the boolean value.
  return isBalanced(this->root);
};

bool bst::isValid() {
  // Determine whether the BST instance is, in fact, a valid BST.
  return validateBST(this->root, 0, 0);
};

bool bst::searchBFS(int query) {
  // Perform a BFS search for a Node based on its value.
  std::vector<Node*> nodes;
  bool found = false;
  nodes.push_back(this->root);
  while(!nodes.empty()) {
    Node* current = nodes[0];
    if (current->value == query) {
      found = true;
    } else {
      if (current->left != NULL) {
        nodes.push_back(current->left);
      }
      if (current->right != NULL) {
        nodes.push_back(current->right);
      }
    }
    nodes.erase(nodes.begin());
  }
  return found;
}

bool bst::searchBinary(int query) {
  // Perform a binary search, i.e. this is a BST, for a Node based on its value.
  return searchBinary(query, root);
}

bool bst::searchDFS(int query) {
  // Perform a DFS search for a Node based on its value.
  return searchDFS(query, root);
}

std::vector<int> bst::formatPrettyPrint() {
  // Return the Nodes of the BST instance in order from top-down and left-right
  // for easy pretty printing. A -1 Integer value represents Null and fills out
  // the BST as a Perfect BST.
  int perfectBSTSize = sizePerfectBST();
  std::vector<int> printableBST;
  std::vector<Node*> nodes;
  nodes.push_back(root);
  while(perfectBSTSize > 0) {
    Node* current = nodes[0];
    if (current != NULL) {
      printableBST.push_back(current->value);
      if (current->left != NULL) {
        nodes.push_back(current->left);
      } else {                                  // Set Left Null Node value to -1.
        Node* fillLeft  = new Node;
        fillLeft->value = -1;
        fillLeft->left  = NULL;
        fillLeft->right = NULL;
        nodes.push_back(fillLeft);
      }
      if (current->right != NULL) {
        nodes.push_back(current->right);
      } else {                                  // Set Right Null Node value to -1.
        Node* fillRight  = new Node;
        fillRight->value = -1;
        fillRight->left  = NULL;
        fillRight->right = NULL;
        nodes.push_back(fillRight);
      }
    }
    nodes.erase(nodes.begin());
    --perfectBSTSize;
  }
  return printableBST;
}

void bst::destroyTree() {
  // De-allocate a BST instance.
  destroyTree(root);
}

void bst::insert(int key) {
  // Helper method for Node insertion.
  if (root != NULL) {
    insert(key, root);
  } else {
    root        = new Node;
    root->value = key;
    root->left  = NULL;
    root->right = NULL;
  }
}

void bst::printInfix() {
  // Print BST instance via infix traversal.
  printInfix(root);
  std::cout << std::endl;
}

void bst::printPostfix() {
  // Print BST instance via postfix traversal.
  printPostfix(root);
  std::cout << std::endl;
}

void bst::printPrefix() {
  // Print BST instance via prefix traversal.
  printPrefix(root);
  std::cout << std::endl;
}

//
// private
//

bool bst::isBalanced(Node* leaf) {
  // Determine whether the BST is balanced, i.e. the heights of its SubTrees
  // differ by no more than one Node.
  if (leaf == NULL) {
    return 0;
  } else {
    int lDepth = calcHeight(leaf->left);
    int rDepth = calcHeight(leaf->right);
    return (abs(lDepth - rDepth) <= 1);
  }
};

bool bst::searchBinary(int query, Node* leaf) {
  // Perform a BFS search for a Node based on its value.
  if (leaf != NULL) {
    if (query == leaf->value) {
      return true;
    } else if (query < leaf->value) {
      return searchBinary(query, leaf->left);
    } else {
      return searchBinary(query, leaf->right);
    }
  } else {
    return false;
  }
}

bool bst::searchDFS(int query, Node* leaf) {
  // Perform a DFS search for a Node based on its value.
  if (query == leaf->value) {
    return true;
  } else {
    if (leaf->left != NULL) {
      return searchDFS(query, leaf->left);
    } else {
      return false;
    }
    if (leaf->right != NULL) {
      return searchDFS(query, leaf->right);
    } else {
      return false;
    }
  }
}

int bst::calcHeight(Node* leaf) {
  // Calculate the height of a BST instance, i.e. the number of levels from the
  // root to the lowest Node.
  if (leaf == NULL) {
    return 0;
  } else {
    int lDepth = calcHeight(leaf->left);
    int rDepth = calcHeight(leaf->right);
    if (lDepth > rDepth) {
      return(lDepth + 1);
    } else {
      return(rDepth + 1);
    }
  }
}

int bst::sizePerfectBST() {
  // Calculate the Perfect BST size in number of Nodes needed to draw all the
  // Nodes in a BST instance.
  return pow(2,calcHeight(root)) - 1;
}

void bst::destroyTree(Node *leaf) {
  // Helper method to de-allocate a BST instance.
  if (leaf != NULL) {
    destroyTree(leaf->left);
    destroyTree(leaf->right);
    delete leaf;
  }
}

void bst::insert(int key, Node *leaf) {
  // Helper method for Node insertion.
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

bool bst::validateBST(Node* leaf, int min, int max) {
  // Helper method for BST validation.
  if (leaf == NULL) {
    return true;
  }
  if ((min != 0 && leaf->value <= min) || (max != 0 && leaf->value > max)) {
    return false;
  }
  if (!validateBST(leaf->left, min, leaf->value) || !validateBST(leaf->right, leaf->value, max)) {
    return true;
  }
  return true;
}

void bst::printInfix(Node *leaf) {
  // Helper method for printing a BST instance via infix traversal.
  if (leaf != NULL) {
    printInfix(leaf->left);
    std::cout << leaf->value << ",";
    printInfix(leaf->right);
  }
}

void bst::printPrefix(Node *leaf) {
  // Helper method for printing a BST instance via prefix traversal.
  if (leaf != NULL) {
    std::cout << leaf->value << ",";
    printPrefix(leaf->left);
    printPrefix(leaf->right);
  }
}

void bst::printPostfix(Node *leaf) {
  // Helper method for printing a BST instance via postfix traversal.
  if (leaf != NULL) {
    printPostfix(leaf->left);
    printPostfix(leaf->right);
    std::cout << leaf->value << ",";
  }
}
