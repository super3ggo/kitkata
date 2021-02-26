// Prompt: Implement a method that takes an integer and returns the string
//         "Fizz," "Buzz," or "FizzBuzz" depending on whether the number is
//         divisible by 3, 5, or both sans remainder.

//
// Solution
//

function fizzBuzz(n: number): string {
  if (n % 15 == 0) {
    return "FizzBuzz";
  } else if (n % 5 == 0) {
    return "Buzz";
  } else if (n % 3 == 0) {
    return "Fizz";
  } else {
    return n.toString();
  }
}

//
// Util
//

function equals(a: Array<string>, b: Array<string>): boolean {
  let result = false;
  for (let i in a) {
    let tmpA = a[i];
    let tmpB = b[i];
    if (tmpA !== undefined && tmpB !== undefined) {
      if (tmpA == tmpB) {
        result = true;
      } else {
        result = false;
      }
    } else {
      result = false;
    }
  }
  return result;
}

function test(control: Array<string>, wild: Array<number>): boolean {
  let test = wild.map(fizzBuzz);
  return equals(control, test);
}

function testPrint(result: boolean, testCase: string): void {
  let message = testCase + ' -> ';
  if (result) {
    console.log(message + 'success');
  } else {
    console.log(message + 'failure');
  }
}

//
// Test(s)
//

// Test 00
let control00 = ['FizzBuzz','1','2','Fizz','4','Buzz','Fizz','7','8','Fizz'];
let wild00    = [0,1,2,3,4,5,6,7,8,9];
let result00  = test(control00, wild00);
testPrint(result00, 'test 00');
