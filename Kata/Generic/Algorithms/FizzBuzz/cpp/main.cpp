#include <iostream>
#include <vector>

// Prompt: Implement a method that takes an integer and returns the string
//         "Fizz," "Buzz," or "FizzBuzz" depending on whether the number is
//         divisible by 3, 5, or both sans remainder.

//
// Solution
//

std::string fizzBuzz(int num) {
  if (num % 15 == 0) {
    return "FizzBuzz";
  } else if (num % 3 == 0) {
    return "Fizz";
  } else if (num % 5 == 0) {
    return "Buzz";
  } else {
    return std::to_string(num);
  }
}

//
// Util
//

std::vector<std::string> apply(std::vector<int> testCase) {
  std::vector<std::string> result;
  for (int i=0; i<testCase.size(); i++) {
    result.push_back(fizzBuzz(testCase[i]));
  }
  return result;
}

bool test(std::vector<std::string> control, std::vector<std::string> wild) {
  bool result = true;
  for (int i=0; i<control.size(); i++) {
    if (control[i] != wild[i]) {
      result = false;
    }
  }
  return result;
}

void testPrint(bool result, std::string testCase) {
  std::string resultAsString = result ? "pass" : "fail";
  std::cout << testCase << " -> " << resultAsString << std::endl;
}

//
// Test(s)
//

int main() {
  // Test 00
  std::vector<std::string> control;
  control.push_back("FizzBuzz");
  control.push_back("1");
  control.push_back("2");
  control.push_back("Fizz");
  control.push_back("4");
  control.push_back("Buzz");
  control.push_back("Fizz");
  control.push_back("7");
  control.push_back("8");
  control.push_back("Fizz");
  std::vector<int> wild;
  wild.push_back(0);
  wild.push_back(1);
  wild.push_back(2);
  wild.push_back(3);
  wild.push_back(4);
  wild.push_back(5);
  wild.push_back(6);
  wild.push_back(7);
  wild.push_back(8);
  wild.push_back(9);
  bool result = test(control, apply(wild));
  testPrint(result, "test00");
}
