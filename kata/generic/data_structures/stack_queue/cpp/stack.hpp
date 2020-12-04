#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <vector>

class Stack {
  public:
    Stack();
    Stack(int limit);
    bool isEmpty();
    bool isFull();
    int  peek();
    void init(int limit);
    void pop();
    void push(int entry);
    void show();
  protected:
    int limit;
    int currentSize;
    std::vector<int> stack;
};

#endif
