export let __lastAbortMsg: string | null = null;
export let __lastAbortLine = -1;

function assert2(cond: bool, msg: string): void {
  if (!cond) {
    __lastAbortMsg = msg;
    __lastAbortLine = 9;
    unreachable();
  }
}

export function foo(): void {
  assert2(false, "some error"); // trap
}