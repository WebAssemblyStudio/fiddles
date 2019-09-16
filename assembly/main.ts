export function virtual1(classId: u32, memberId: u32): u32 {
  switch (memberId) {
    case 1: {
      switch (classId) {
       case 1: return 0;
       case 2: return 1;
       case 3: return 1;
      }
    }
    case 6: {
      switch (classId) {
       case 1: return 1;
       case 2: return 0;
       case 3: return 1;
      }
    }
    case 8: {
      switch (classId) {
       case 1: return 1;
       case 2: return 0;
       case 3: return 1;
       case 4: return 2;
       case 5: return 1;
      }
    }
  }
  unreachable();
  return 0;
}

export function virtual2(classId: u32, memberId: u32): u32 {
  switch ((memberId << 16) | classId) {
    case (1 << 16) | 1: return 0;
    case (1 << 16) | 2: return 1;
    case (1 << 16) | 3: return 1;
    case (6 << 16) | 1: return 1;
    case (6 << 16) | 2: return 0;
    case (6 << 16) | 3: return 1;
    case (8 << 16) | 1: return 1;
    case (8 << 16) | 2: return 0;
    case (8 << 16) | 3: return 1;
    case (8 << 16) | 4: return 2;
    case (8 << 16) | 5: return 1;
  }
  unreachable();
  return 0;
}
