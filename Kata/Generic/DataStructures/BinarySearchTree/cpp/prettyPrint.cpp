#include "prettyPrint.hpp"

namespace {
  struct Indents {
    int firstIndent;
    int secondIndent;
    int maxNodes;
  };

  struct PrettyPrintInfo {
    int perfectBSTSize;
    int perfectBSTLevels;
    std::vector<int> indentsAtLevel;
  };

  PrettyPrintInfo calcPrettyPrint(int nodes);
  int calcNodeWidth(std::vector<int> nodes);
  int calcNodesPerLevel(int nodes);
  int countDigits(int number);
  std::string spaceOut(char c, int n);
  std::vector<Indents> calcIndents(int nodes, int adjustment);
}

namespace PrettyPrint {
  void prettyPrint(std::vector<int> nodes) {
    // Pretty print a BST given its Nodes arranged as a Perfect BST.
    int totalNodes               = nodes.size();
    int printCount               = 0;
    int nodeWidth                = calcNodeWidth(nodes);
    bool printFirst              = true;
    std::vector<Indents> indents = calcIndents(totalNodes, nodeWidth);
    for (int i=0; i<indents.size(); i++) {
      while(printCount < indents[i].maxNodes) {
        if (printFirst) {
          std::cout << spaceOut(' ',indents[i].firstIndent);
        } else {
          std::cout << spaceOut(' ',indents[i].secondIndent);
        }
        int nodeValue = nodes[0];
        if (nodeValue > 0) {
          int spacing = nodeWidth - countDigits(nodeValue);
          std::cout << spaceOut(' ',spacing) << nodeValue;
        } else {
          std::cout << spaceOut('_',nodeWidth);
        }
        nodes.erase(nodes.begin());
        printFirst = false;
        printCount++;
      }
      std::cout << std::endl;
      printFirst = true;
      printCount = 0;
    }
  }
}

namespace {
  PrettyPrintInfo calcPrettyPrint(int nodes) {
    // Calculate the info...
    // 0. Perfect BST size.
    // 1. Perfect BST Levels.
    // 2. Indents need per Level. I.e. n-1 Nodes per Level appended with 0: [15,7,3,1] -> [7,3,1,0]
    //
    // Needed to calculate the whitespace indents given a BST.
    PrettyPrintInfo ppInfo;
    int perfectBstSize = 0;
    std::vector<int> indents;
    while(nodes > perfectBstSize) {
      perfectBstSize = (perfectBstSize * 2) + 1;
      indents.push_back(perfectBstSize);
    }
    indents.pop_back();
    std::reverse(indents.begin(), indents.end());
    ppInfo.perfectBSTSize   = perfectBstSize;
    ppInfo.perfectBSTLevels = log2(perfectBstSize + 1); // You can just take the size of indentsAtLevel, but this is faster?
    ppInfo.indentsAtLevel   = indents;
    return ppInfo;
  }

  int calcNodeWidth(std::vector<int> nodes) {
    // Calculate the character width needed to print the largest BST Node, and
    // therefore the rest of its Nodes.
    std::vector<int> widths;
    for (int i=0; i<nodes.size(); i++) {
      int current = nodes[i];
      if (current > 0) {
        widths.push_back(countDigits(current));
      }
    }
    sort(widths.begin(), widths.end(), std::greater<int>());
    return widths[0];
  }

  int calcNodesPerLevel(int nodes) {
    // Calculate the number of Nodes per Level of a Perfect BST. I.e. just
    // return the power of 2 at Integer n such that Level 1 equals n of 0.
    if (nodes < 0) {
      nodes = 0;
    }
    return pow(2, nodes);
  }

  int countDigits(int number) {
    // Count the digits of a number.
    int count = 0;
    while(number != 0) {
      number = number/10;
      count++;
    }
    return count;
  }

  std::string spaceOut(char c, int n) {
    // Return a whitespace string with a length of n.
    std::string spaces = "";
    for (int i=0; i<n; i++) {
      spaces += c;
    }
    return spaces;
  };

  std::vector<Indents> calcIndents(int nodes, int adjustment) {
    // Calculate the indents needed to pretty print a BST given its Nodes
    // arranged as a Perfect BST.
    PrettyPrintInfo ppInfo          = calcPrettyPrint(nodes);
    std::vector<int> indentsAtLevel = ppInfo.indentsAtLevel;
    int perfectNodes                = ppInfo.perfectBSTSize;
    int levels                      = ppInfo.perfectBSTLevels;
    int previous                    = adjustment;
    std::vector<Indents> indents;
    Indents tmp;
    for (int i=0; i<levels; i++) {
      if (i == 0) {
        tmp.firstIndent  = indentsAtLevel[i] * adjustment;
        tmp.secondIndent = tmp.firstIndent;
      } else if (i == levels-1) {
        tmp.firstIndent  = 0;
        tmp.secondIndent = previous;
      } else {
        tmp.firstIndent  = indentsAtLevel[i] * adjustment;
        tmp.secondIndent = indentsAtLevel[i-1] * adjustment;
        previous         = tmp.firstIndent;
      }
      tmp.maxNodes = calcNodesPerLevel(i);
      indents.push_back(tmp);
    }
    return indents;
  }
}
