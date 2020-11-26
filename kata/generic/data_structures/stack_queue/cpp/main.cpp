#include <iostream>

#include "stack.cpp"

int main() {
  // Stack tests
  Stack test(3);
  std::cout << "Empty?      " << test.isEmpty() << std::endl;
  std::cout << "Peeking... " << test.peek() << std::endl;
  test.push(0);
  std::cout << "Empty?      " << test.isEmpty() << std::endl;
  test.push(1);
  test.push(2);
  std::cout << "Full?       " << test.isFull() << std::endl;
  std::cout << "Peeking...  " << test.peek() << std::endl;
  test.push(3);
  test.show();
  test.pop();
  test.push(3);
  test.show();
  std::cout << "Peeking...  " << test.peek() << std::endl;
}
