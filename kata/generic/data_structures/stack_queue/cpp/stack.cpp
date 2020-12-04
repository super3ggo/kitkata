#include "stack.hpp"

Stack::Stack() {
  this->limit       = 0;
  this->currentSize = 0;
}

Stack::Stack(int limit) {
  this->limit       = limit;
  this->currentSize = 0;
  this->stack.reserve(this->limit);
}

bool Stack::isEmpty() {
  return this->currentSize == 0;
}

bool Stack::isFull() {
  return this->currentSize == this->limit;
}

int Stack::peek() {
  if (!this->isEmpty()) {
    return this->stack.back();
  } else {
    return -1;
  }
}

void Stack::init(int limit) {
  this->limit       = limit;
  this->currentSize = 0;
  this->stack.reserve(this->limit);
}

void Stack::pop() {
  if (!this->isEmpty()) {
    this->stack.pop_back();
    this->currentSize -= 1;
  } else {
    std::cout << "Error: empty stack!" << std::endl;
  }
}

void Stack::push(int entry) {
  if (!this->isFull()) {
    this->stack.push_back(entry);
    this->currentSize += 1;
  } else {
    std::cout << "Error: stack overflow!" << std::endl;
  }
}

void Stack::show() {
  std::cout << "--------------------" << std::endl;
  for(int i = 0; i < this->stack.size(); i++) {
    std::cout << "item: " << i << " elem: " << this->stack[i] << std::endl;
  }
  std::cout << "--------------------" << std::endl;
}
