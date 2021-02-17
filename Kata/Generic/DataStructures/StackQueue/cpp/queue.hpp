#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
#include <vector>

class Queue {
  public:
    Queue(int limit);
    bool isEmpty();
    bool isFull();
    int  peek();
    void add(int entry);
    void remove();
    void show();
  private:
    int currentSize;
    int limit;
    std::vector<int> queue;
};

#endif
