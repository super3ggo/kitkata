#include <iostream>

#include "bst.hpp"
#include "prettyPrint.hpp"

// Note: most of the tests involve actually printing the BST. Hence, this file
// excludes the usual testing helper methods.

int main() {
  bst *tree = new bst();

  //
  // PrettyPrint BST test(s)
  //

  // tree->insert(1);
  // tree->insert(2);
  // tree->insert(3);
  // tree->insert(4);

  // tree->insert(40);
  // tree->insert(20);
  // tree->insert(10);
  // tree->insert(5);
  // tree->insert(30);
  // tree->insert(50);
  // tree->insert(60);
  // tree->insert(67);

  // tree->insert(40);
  // tree->insert(20);
  // tree->insert(10);
  // tree->insert(5);
  // tree->insert(30);
  // tree->insert(50);
  // tree->insert(45);
  // tree->insert(42);
  // tree->insert(48);

  //
  // Balanced BST test(s)
  //

  tree->insert(5);
  tree->insert(3);
  tree->insert(1);
  tree->insert(4);
  tree->insert(8);
  tree->insert(6);
  tree->insert(9);
  tree->insert(10);
  // tree->insert(11); // <- comment this node out to make it balanced

  //
  // IO
  //

  std::cout << "prefix:  ";
  tree->printPrefix();
  std::cout << "infix:   ";
  tree->printInfix();
  std::cout << "postfix: ";
  tree->printPostfix();
  std::cout << "pretty:" << std::endl;
  std::vector<int> nodesPPF = tree->formatPrettyPrint();
  std::cout << std::endl;
  PrettyPrint::prettyPrint(nodesPPF);
  std::cout << std::endl;
  std::cout << "is balanced (0/1, no/yes)? -> " << tree->isBalanced() << std::endl;
  std::cout << "is valid    (0/1, no/yes)? -> " << tree->isValid() << std::endl;
  std::cout << std::endl;

  delete tree;
}
