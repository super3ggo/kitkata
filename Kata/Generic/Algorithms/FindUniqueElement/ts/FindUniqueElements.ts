// Prompt: Given an array of integers, find the unique, i.e. non-duplicate,
//         elements.

//
// Solution
//

interface Elem {
  elem: number;
  count: number;
}

function findUniqueElem(list: Array<number>): Array<Elem> {
  let dup: boolean        = false;
  let counts: Array<Elem> = [];
  for (let i in list) {
    for (let j in counts) {
      let tmp = counts[j]
      if (tmp !== undefined && list[i] === tmp.elem) {
        tmp.count += 1;
        dup = true;
      }
    }
    if (!dup) {
      let result = list[i];
      if (result !== undefined) {
        counts.push({elem: result, count: 1});
      }
    }
    dup = false;
  }
  return counts.filter((elem: Elem) => elem.count === 1);
}

//
// Util
//

function isEqual(a: Elem, b: Elem): boolean {
  return a.elem === b.elem
    && a.count === b.count;
}

function equals(a: Array<Elem>, b: Array<Elem>): boolean {
  let result = false;
  for (let i in a) {
    let tmpA = a[i];
    let tmpB = b[i];
    if (tmpA !== undefined && tmpB !== undefined) {
      if (isEqual(tmpA, tmpB)) {
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

function test(control: Array<Elem>, wild: Array<Elem>): boolean {
  return equals(control, wild);
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
let control00 = [{elem: 2, count: 1}];
let wild00    = findUniqueElem([0,0,1,1,2,3,3,3]);
let result00  = test(control00, wild00);
testPrint(result00, 'test 00');
