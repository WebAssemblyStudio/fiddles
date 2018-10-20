

@inline
function test(skipGC: bool): bool {
  if (isManaged<String>() && !skipGC) {
    return true;
  } else {
    return false;
  }
}

export function test1(): bool {
  return test(false);
}

export function test2(): bool {
  return test(true);
}
