# Twiggy Analysis

Twiggy is a code size profiler, learn more about it [here](https://github.com/rustwasm/twiggy).

## Top

| Shallow Bytes | Shallow % | Item |
| ------------: | --------: | :--- |
| 306 | 20.93 | `"function names" subsection` |
| 232 | 15.87 | `data[0]` |
| 103 | 7.05 | `core::panicking::panic::haf7d7779169c0743` |
| 103 | 7.05 | `rust_begin_unwind` |
| 102 | 6.98 | `data[1]` |
| 96 | 6.57 | `std::panicking::rust_panic_with_hook::h9b1c029d1ceaded2` |
| 62 | 4.24 | `core::panicking::panic_fmt::h29e5105b4d53bc05` |
| 53 | 3.63 | `divide` |
| 53 | 3.63 | `remainder` |
| 23 | 1.57 | `data[2]` |
| 22 | 1.50 | `export "rust_eh_personality"` |
| 13 | 0.89 | `type[2]` |
| 13 | 0.89 | `custom section 'linking'` |
| 12 | 0.82 | `export "substract"` |
| 12 | 0.82 | `export "remainder"` |
| 11 | 0.75 | `export "multiply"` |
| 9 | 0.62 | `export "memory"` |
| 9 | 0.62 | `export "divide"` |
| 8 | 0.55 | `global[0]` |
| 8 | 0.55 | `export "power"` |
| 8 | 0.55 | `add` |
| 8 | 0.55 | `substract` |
| 8 | 0.55 | `multiply` |
| 8 | 0.55 | `power` |
| 8 | 0.55 | `std::panicking::begin_panic_fmt::h29d4906ca23d78a0` |
| 6 | 0.41 | `type[0]` |
| 6 | 0.41 | `export "add"` |
| 5 | 0.34 | `type[3]` |
| 4 | 0.27 | `type[1]` |
| 4 | 0.27 | `table[0]` |
| 3 | 0.21 | `type[4]` |
| 3 | 0.21 | `rust_eh_personality` |
| 2 | 0.14 | `memory[0]` |

### Note:
12 items had a shallow size percent less than 0.1 and were not listed above.


## Dominators

| Retained Bytes | Retained % | Dominator Tree |
| ------------: | --------: | :--- |
| 997 | 68.19 | `<meta root>` |
| 430 | 29.41 | `⤷ func[4]` |
| 425 | 29.07 | `   ⤷ core::panicking::panic::haf7d7779169c0743` |
| 314 | 21.48 | `      ⤷ func[11]` |
| 308 | 21.07 | `         ⤷ core::panicking::panic_fmt::h29e5105b4d53bc05` |
| 246 | 16.83 | `            ⤷ func[8]` |
| 232 | 15.87 | `               ⤷ rust_begin_unwind` |
| 129 | 8.82 | `               ��  ⤷ func[9]` |
| 128 | 8.76 | `                     ⤷ std::panicking::begin_panic_fmt::h29d4906ca23d78a0` |
| 120 | 8.21 | `                        ⤷ func[7]` |
| 119 | 8.14 | `                           ⤷ std::panicking::rust_panic_with_hook::h9b1c029d1ceaded2` |
| 23 | 1.57 | `                              ⤷ data[2]` |
| 13 | 0.89 | `               ⤷ type[2]` |
| 5 | 0.34 | `         ⤷ type[3]` |
| 8 | 0.55 | `      ⤷ global[0]` |
| 4 | 0.27 | `   ⤷ type[1]` |
| 306 | 20.93 | `⤷ "function names" subsection` |
| 66 | 4.51 | `⤷ export "remainder"` |
| 54 | 3.69 | `   ⤷ func[6]` |
| 53 | 3.63 | `      ⤷ remainder` |
| 63 | 4.31 | `⤷ export "divide"` |
| 54 | 3.69 | `   ⤷ func[3]` |
| 53 | 3.63 | `      ⤷ divide` |
| 29 | 1.98 | `⤷ export "rust_eh_personality"` |
| 7 | 0.48 | `   ⤷ func[10]` |
| 3 | 0.21 | `      ⤷ type[4]` |
| 3 | 0.21 | `      ⤷ rust_eh_personality` |
| 21 | 1.44 | `⤷ export "substract"` |
| 9 | 0.62 | `   ⤷ func[1]` |
| 8 | 0.55 | `      ⤷ substract` |
| 20 | 1.37 | `⤷ export "multiply"` |
| 9 | 0.62 | `   ⤷ func[2]` |
| 8 | 0.55 | `      ⤷ multiply` |
| 17 | 1.16 | `⤷ export "power"` |
| 9 | 0.62 | `   ⤷ func[5]` |
| 8 | 0.55 | `      ⤷ power` |
| 15 | 1.03 | `⤷ export "add"` |
| 9 | 0.62 | `   ⤷ func[0]` |
| 8 | 0.55 | `      ⤷ add` |
| 13 | 0.89 | `⤷ custom section 'linking'` |
| 11 | 0.75 | `⤷ export "memory"` |
| 2 | 0.14 | `   ⤷ memory[0]` |
| 6 | 0.41 | `⤷ type[0]` |
