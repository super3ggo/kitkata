#include <iostream>

#include "treeBinary.hpp"

int main() {
  TreeBinary *tree = new TreeBinary();

  tree->insert(2);
  tree->insert(1);
  tree->insert(3);

  tree->printPrefix();
  tree->printInfix();
  tree->printPostfix();

  delete tree;
}
