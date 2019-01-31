

function memcmp(vl: usize, vr: usize, n: isize): i32 {
  const word_size  = 8;
  const word_align = 8;

  const align_mask = word_align - 1;

  let buf1 = vl;
  let buf2 = vr;

  let addr1 = vl;
  let addr2 = vr;

  if ((addr1 & align_mask) == (addr2 & align_mask)) {
    const skip = word_align - (addr1 & align_mask);

    for (let i = 0; i < skip; ++i) {
      // load<u8>
      if (*buf1++ != *buf2++)
        break end;
      --n;
    }

    let wbuf1 = buf1;
    let wbuf2 = buf2;

    while (n >= word_size) {
      // load<u64>
      if (*wbuf1++ != *wbuf2++)
        break end;

      n -= word_size;
    }

    buf1 = wbuf1;
    buf2 = wbuf2;
  }

  while (n--) {
    // load<u8>
    if (*buf1++ != *buf2++)
      break end;
  }

end:
  return n ? *buf1 - *buf2 : 0;
}
