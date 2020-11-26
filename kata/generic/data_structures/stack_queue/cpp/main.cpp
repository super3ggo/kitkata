#include <iostream>

#include "stack.cpp"
#include "queue.cpp"

int main() {
  // Stack tests
  Stack testStack(3);
  std::cout << "Empty?      " << testStack.isEmpty() << std::endl;
  std::cout << "Peeking... "  << testStack.peek()    << std::endl;
  testStack.push(0);
  std::cout << "Empty?      " << testStack.isEmpty() << std::endl;
  testStack.push(1);
  testStack.push(2);
  std::cout << "Full?       " << testStack.isFull()  << std::endl;
  std::cout << "Peeking...  " << testStack.peek()    << std::endl;
  testStack.push(3);
  testStack.show();
  testStack.pop();
  testStack.push(3);
  testStack.show();
  std::cout << "Peeking...  " << testStack.peek()    << std::endl;

  // Queue tests
  Queue testQueue(3);
  std::cout << "Empty?      " << testQueue.isEmpty() << std::endl;
  std::cout << "Peeking... "  << testQueue.peek()    << std::endl;
  testQueue.add(0);
  std::cout << "Empty?      " << testQueue.isEmpty() << std::endl;
  std::cout << "Peeking...  " << testQueue.peek()    << std::endl;
  testQueue.add(1);
  testQueue.add(2);
  std::cout << "Full?       " << testQueue.isFull()  << std::endl;
  std::cout << "Peeking...  " << testQueue.peek()    << std::endl;
  testQueue.show();
  testQueue.remove();
  testQueue.show();
  testQueue.remove();
  testQueue.show();
  testQueue.remove();
  testQueue.show();
  testQueue.remove();
}
