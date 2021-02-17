// Prompt: Given an array of integers, find the unique, i.e. non-duplicate,
// elements.

//
// Solution
//

interface Elem {
  elem: number;
  count: number;
}

function isEqual(a: Elem, b: Elem): boolean {
  return a.elem === b.elem
    && a.count === b.count;
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
      if (result !== undefined ) {
        counts.push({elem: result, count: 1});
      }
    }
    dup = false;
  }
  return counts.filter((elem: Elem) => elem.count === 1);
}

//
// Test(s)
//

function test(control: Array<Elem>, test: Array<Elem>, message: string): void {
  let result = false;
  for (let i in control) {
    let tmpControl = control[i];
    let tmpTest    = test[i];
    if (tmpControl !== undefined && tmpTest !== undefined) {
      if (isEqual(tmpControl, tmpTest)) {
        result = true;
      } else {
        result = false;
      }
    } else {
      result = false;
    }
  }
  console.log(message + " -> " + result);
}

// Test 00
let control00 = [{elem: 2, count: 1}];
let test00    = findUniqueElem([0,0,1,1,2,3,3,3]);
test(control00, test00, "test 00");
