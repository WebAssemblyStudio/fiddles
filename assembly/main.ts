declare function print(str: string): void;

type testFunc = ((size: usize) => usize) | null;

@external("env", "testCallback")
declare function testCallback(f: testFunc): void;


function cbk(size: usize): usize {
  print("!CBK!");
  return 123;
}

testCallback(cbk);