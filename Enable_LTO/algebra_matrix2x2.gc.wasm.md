# Twiggy Analysis

Twiggy is a code size profiler, learn more about it [here](https://github.com/rustwasm/twiggy).

## Top

| Shallow Bytes | Shallow % | Item |
| ------------: | --------: | :--- |
| 6591 | 33.97 | `dlmalloc::dlmalloc::Dlmalloc::malloc::hce1b00d5aca5677c` |
| 1905 | 9.82 | `dlmalloc::dlmalloc::Dlmalloc::free::h4c32f8306a59a4b8` |
| 1622 | 8.36 | `dlmalloc::dlmalloc::Dlmalloc::dispose_chunk::hb606175ffa022755` |
| 1619 | 8.34 | `nalgebra::linalg::determinant::<impl nalgebra::base::matrix::Matrix<N, D, D, S>>::determinant::h87358dffc20cc251` |
| 1108 | 5.71 | `data[2]` |
| 1103 | 5.68 | `__rust_realloc` |
| 841 | 4.33 | `"function names" subsection` |
| 722 | 3.72 | `tensor` |
| 617 | 3.18 | `multiply` |
| 480 | 2.47 | `data[1]` |
| 445 | 2.29 | `add` |
| 445 | 2.29 | `substract` |
| 392 | 2.02 | `dot` |
| 388 | 2.00 | `dlmalloc::dlmalloc::Dlmalloc::memalign::h35a38b3134a61c27` |
| 271 | 1.40 | `data[0]` |
| 199 | 1.03 | `<alloc::raw_vec::RawVec<T, A>>::reserve_internal::hda88ecc4dab37321` |
| 103 | 0.53 | `rust_begin_unwind` |
| 103 | 0.53 | `core::panicking::panic::haf7d7779169c0743` |
| 96 | 0.49 | `std::panicking::rust_panic_with_hook::h9b1c029d1ceaded2` |
| 62 | 0.32 | `core::panicking::panic_fmt::h29e5105b4d53bc05` |
| 55 | 0.28 | `memcpy` |

### Note:
45 items had a shallow size percent less than 0.1 and were not listed above.


## Dominators

| Retained Bytes | Retained % | Dominator Tree |
| ------------: | --------: | :--- |
| 19083 | 98.34 | `<meta root>` |
| 6597 | 34.00 | `⤷ func[4]` |
| 6591 | 33.97 | `   ⤷ dlmalloc::dlmalloc::Dlmalloc::malloc::hce1b00d5aca5677c` |
| 3330 | 17.16 | `⤷ func[2]` |
| 3321 | 17.11 | `   ⤷ <alloc::raw_vec::RawVec<T, A>>::reserve_internal::hda88ecc4dab37321` |
| 3122 | 16.09 | `      ⤷ func[3]` |
| 3121 | 16.08 | `         ⤷ __rust_realloc` |
| 1623 | 8.36 | `            ⤷ func[9]` |
| 1622 | 8.36 | `               ⤷ dlmalloc::dlmalloc::Dlmalloc::dispose_chunk::hb606175ffa022755` |
| 395 | 2.04 | `            ⤷ func[11]` |
| 388 | 2.00 | `               ⤷ dlmalloc::dlmalloc::Dlmalloc::memalign::h35a38b3134a61c27` |
| 1906 | 9.82 | `⤷ func[10]` |
| 1905 | 9.82 | `   ⤷ dlmalloc::dlmalloc::Dlmalloc::free::h4c32f8306a59a4b8` |
| 1632 | 8.41 | `⤷ func[15]` |
| 1626 | 8.38 | `   ⤷ nalgebra::linalg::determinant::<impl nalgebra::base::matrix::Matrix<N, D, D, S>>::determinant::h87358dffc20cc251` |
| 1108 | 5.71 | `⤷ data[2]` |
| 870 | 4.48 | `⤷ func[12]` |
| 869 | 4.48 | `   ⤷ core::panicking::panic::haf7d7779169c0743` |
| 766 | 3.95 | `      ⤷ func[13]` |
| 765 | 3.94 | `         ⤷ core::panicking::panic_fmt::h29e5105b4d53bc05` |
| 703 | 3.62 | `            ⤷ func[7]` |
| 689 | 3.55 | `               ⤷ rust_begin_unwind` |
| 586 | 3.02 | `                  ⤷ func[8]` |
| 585 | 3.01 | `                     ⤷ std::panicking::begin_panic_fmt::h29d4906ca23d78a0` |
| 577 | 2.97 | `                        ⤷ func[6]` |
| 576 | 2.97 | `                           ⤷ std::panicking::rust_panic_with_hook::h9b1c029d1ceaded2` |
| 480 | 2.47 | `                              ⤷ data[1]` |
| 841 | 4.33 | `⤷ "function names" subsection` |
| 732 | 3.77 | `⤷ export "tensor"` |
| 723 | 3.73 | `   ⤷ func[19]` |
| 722 | 3.72 | `      ⤷ tensor` |
| 629 | 3.24 | `⤷ export "multiply"` |
| 618 | 3.18 | `   ⤷ func[17]` |
| 617 | 3.18 | `      ⤷ multiply` |
| 458 | 2.36 | `⤷ export "substract"` |
| 446 | 2.30 | `   ⤷ func[16]` |
| 445 | 2.29 | `      ⤷ substract` |
| 452 | 2.33 | `⤷ export "add"` |
| 446 | 2.30 | `   ⤷ func[14]` |
| 445 | 2.29 | `      ⤷ add` |
| 399 | 2.06 | `⤷ export "dot"` |
| 393 | 2.03 | `   ⤷ func[18]` |
| 392 | 2.02 | `      ⤷ dot` |
| 63 | 0.32 | `⤷ func[20]` |
| 55 | 0.28 | `   ⤷ memcpy` |

### Note:
16 items had a retained size percent less than 0.1 and were not listed above.
