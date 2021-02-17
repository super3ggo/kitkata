#include "queue.hpp"

Queue::Queue(int limit) {
  this->limit = limit;
  this->currentSize = 0;
  this->queue.reserve(this->limit);
}

bool Queue::isEmpty() {
  return this->currentSize == 0;
}

bool Queue::isFull() {
  return this->currentSize == this->limit;
}

int Queue::peek() {
  if (!isEmpty()) {
    return this->queue.front();
  } else {
    return -1;
  }
}

void Queue::add(int entry) {
  if (!isFull()) {
    this->queue.push_back(entry);
    this->currentSize += 1;
  } else {
    std::cout << "Error: queue overflow!" << std::endl;
  }
}

void Queue::remove() {
  if (!isEmpty()) {
    std::vector<int> tmp;
    for (int i=1; i < this->queue.size(); i++) {
      tmp.push_back(this->queue[i]);
    }
    this->queue = tmp;
    this->currentSize -= 1;
  } else {
    std::cout << "Error: empty queue!" << std::endl;
  }
}

void Queue::show() {
  std::cout << "--------------------" << std::endl;
  for (int i=0; i < this->queue.size(); i++) {
    std::cout << "item: " << i << " elem: " << this->queue[i] << std::endl;
  }
  std::cout << "--------------------" << std::endl;
}
