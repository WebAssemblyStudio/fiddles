# Twiggy Analysis

Twiggy is a code size profiler, learn more about it [here](https://github.com/rustwasm/twiggy).

## Top

| Shallow Bytes | Shallow % | Item |
| ------------: | --------: | :--- |
| 6591 | 30.76 | `dlmalloc::dlmalloc::Dlmalloc::malloc::hce1b00d5aca5677c` |
| 1905 | 8.89 | `dlmalloc::dlmalloc::Dlmalloc::free::h4c32f8306a59a4b8` |
| 1622 | 7.57 | `dlmalloc::dlmalloc::Dlmalloc::dispose_chunk::hb606175ffa022755` |
| 1619 | 7.55 | `nalgebra::linalg::determinant::<impl nalgebra::base::matrix::Matrix<N, D, D, S>>::determinant::h87358dffc20cc251` |
| 1108 | 5.17 | `data[2]` |
| 1103 | 5.15 | `__rust_realloc` |
| 1021 | 4.76 | `"function names" subsection` |
| 722 | 3.37 | `tensor` |
| 617 | 2.88 | `multiply` |
| 480 | 2.24 | `data[1]` |
| 445 | 2.08 | `add` |
| 445 | 2.08 | `substract` |
| 392 | 1.83 | `dot` |
| 388 | 1.81 | `dlmalloc::dlmalloc::Dlmalloc::memalign::h35a38b3134a61c27` |
| 271 | 1.26 | `data[0]` |
| 199 | 0.93 | `<alloc::raw_vec::RawVec<T, A>>::reserve_internal::hda88ecc4dab37321` |
| 106 | 0.49 | `memmove` |
| 103 | 0.48 | `rust_begin_unwind` |
| 103 | 0.48 | `core::panicking::panic::haf7d7779169c0743` |
| 96 | 0.45 | `std::panicking::rust_panic_with_hook::h9b1c029d1ceaded2` |
| 69 | 0.32 | `memcmp` |
| 62 | 0.29 | `core::panicking::panic_fmt::h29e5105b4d53bc05` |
| 55 | 0.26 | `memcpy` |
| 45 | 0.21 | `memset` |
| 22 | 0.10 | `export "rust_eh_personality"` |

### Note:
50 items had a shallow size percent less than 0.1 and were not listed above.


## Dominators

| Retained Bytes | Retained % | Dominator Tree |
| ------------: | --------: | :--- |
| 19289 | 90.01 | `<meta root>` |
| 6597 | 30.78 | `⤷ func[4]` |
| 6591 | 30.76 | `   ⤷ dlmalloc::dlmalloc::Dlmalloc::malloc::hce1b00d5aca5677c` |
| 3330 | 15.54 | `⤷ func[2]` |
| 3321 | 15.50 | `   ⤷ <alloc::raw_vec::RawVec<T, A>>::reserve_internal::hda88ecc4dab37321` |
| 3122 | 14.57 | `      ⤷ func[3]` |
| 3121 | 14.56 | `         ⤷ __rust_realloc` |
| 1623 | 7.57 | `            ⤷ func[10]` |
| 1622 | 7.57 | `               ⤷ dlmalloc::dlmalloc::Dlmalloc::dispose_chunk::hb606175ffa022755` |
| 395 | 1.84 | `            ⤷ func[12]` |
| 388 | 1.81 | `               ⤷ dlmalloc::dlmalloc::Dlmalloc::memalign::h35a38b3134a61c27` |
| 1906 | 8.89 | `⤷ func[11]` |
| 1905 | 8.89 | `   ⤷ dlmalloc::dlmalloc::Dlmalloc::free::h4c32f8306a59a4b8` |
| 1632 | 7.62 | `⤷ func[16]` |
| 1626 | 7.59 | `   ⤷ nalgebra::linalg::determinant::<impl nalgebra::base::matrix::Matrix<N, D, D, S>>::determinant::h87358dffc20cc251` |
| 1108 | 5.17 | `⤷ data[2]` |
| 1021 | 4.76 | `⤷ "function names" subsection` |
| 870 | 4.06 | `⤷ func[13]` |
| 869 | 4.06 | `   ⤷ core::panicking::panic::haf7d7779169c0743` |
| 766 | 3.57 | `      ⤷ func[14]` |
| 765 | 3.57 | `         ⤷ core::panicking::panic_fmt::h29e5105b4d53bc05` |
| 703 | 3.28 | `            ⤷ func[7]` |
| 689 | 3.22 | `               ⤷ rust_begin_unwind` |
| 586 | 2.73 | `                  ⤷ func[8]` |
| 585 | 2.73 | `                     ⤷ std::panicking::begin_panic_fmt::h29d4906ca23d78a0` |
| 577 | 2.69 | `                        ⤷ func[6]` |
| 576 | 2.69 | `                           ⤷ std::panicking::rust_panic_with_hook::h9b1c029d1ceaded2` |
| 480 | 2.24 | `                              ⤷ data[1]` |
| 732 | 3.42 | `⤷ export "tensor"` |
| 723 | 3.37 | `   ⤷ func[20]` |
| 722 | 3.37 | `      ⤷ tensor` |
| 629 | 2.94 | `⤷ export "multiply"` |
| 618 | 2.88 | `   ⤷ func[18]` |
| 617 | 2.88 | `      ⤷ multiply` |
| 458 | 2.14 | `⤷ export "substract"` |
| 446 | 2.08 | `   ⤷ func[17]` |
| 445 | 2.08 | `      ⤷ substract` |
| 452 | 2.11 | `⤷ export "add"` |
| 446 | 2.08 | `   ⤷ func[15]` |
| 445 | 2.08 | `      ⤷ add` |
| 399 | 1.86 | `⤷ export "dot"` |
| 393 | 1.83 | `   ⤷ func[19]` |
| 392 | 1.83 | `      ⤷ dot` |
| 63 | 0.29 | `⤷ func[21]` |
| 55 | 0.26 | `   ⤷ memcpy` |
| 26 | 0.12 | `⤷ export "rust_eh_personality"` |

### Note:
17 items had a retained size percent less than 0.1 and were not listed above.
