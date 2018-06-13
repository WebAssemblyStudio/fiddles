# Twiggy Analysis

Twiggy is a code size profiler, learn more about it [here](https://github.com/rustwasm/twiggy).

## Top

| Shallow Bytes | Shallow % | Item |
| ------------: | --------: | :--- |
| 271 | 20.58 | `"function names" subsection` |
| 232 | 17.62 | `data[0]` |
| 103 | 7.82 | `core::panicking::panic::haf7d7779169c0743` |
| 103 | 7.82 | `rust_begin_unwind` |
| 102 | 7.74 | `data[1]` |
| 96 | 7.29 | `std::panicking::rust_panic_with_hook::h9b1c029d1ceaded2` |
| 62 | 4.71 | `core::panicking::panic_fmt::h29e5105b4d53bc05` |
| 53 | 4.02 | `divide` |
| 53 | 4.02 | `remainder` |
| 23 | 1.75 | `data[2]` |
| 13 | 0.99 | `type[2]` |
| 13 | 0.99 | `custom section 'linking'` |
| 12 | 0.91 | `export "substract"` |
| 12 | 0.91 | `export "remainder"` |
| 11 | 0.84 | `export "multiply"` |
| 9 | 0.68 | `export "memory"` |
| 9 | 0.68 | `export "divide"` |
| 8 | 0.61 | `global[0]` |
| 8 | 0.61 | `export "power"` |
| 8 | 0.61 | `add` |
| 8 | 0.61 | `substract` |
| 8 | 0.61 | `multiply` |
| 8 | 0.61 | `power` |
| 8 | 0.61 | `std::panicking::begin_panic_fmt::h29d4906ca23d78a0` |
| 6 | 0.46 | `type[0]` |
| 6 | 0.46 | `export "add"` |
| 5 | 0.38 | `type[3]` |
| 4 | 0.30 | `type[1]` |
| 4 | 0.30 | `table[0]` |
| 2 | 0.15 | `memory[0]` |

### Note:
11 items had a shallow size percent less than 0.1 and were not listed above.


## Dominators

| Retained Bytes | Retained % | Dominator Tree |
| ------------: | --------: | :--- |
| 933 | 70.84 | `<meta root>` |
| 430 | 32.65 | `⤷ func[4]` |
| 425 | 32.27 | `   ⤷ core::panicking::panic::haf7d7779169c0743` |
| 314 | 23.84 | `      ⤷ func[10]` |
| 308 | 23.39 | `         ⤷ core::panicking::panic_fmt::h29e5105b4d53bc05` |
| 246 | 18.68 | `            ⤷ func[8]` |
| 232 | 17.62 | `               ⤷ rust_begin_unwind` |
| 129 | 9.79 | `                  ⤷ func[9]` |
| 128 | 9.72 | `                     ⤷ std::panicking::begin_panic_fmt::h29d4906ca23d78a0` |
| 120 | 9.11 | `                        ⤷ func[7]` |
| 119 | 9.04 | `                           ⤷ std::panicking::rust_panic_with_hook::h9b1c029d1ceaded2` |
| 23 | 1.75 | `                              ⤷ data[2]` |
| 13 | 0.99 | `               ⤷ type[2]` |
| 5 | 0.38 | `         ⤷ type[3]` |
| 8 | 0.61 | `      ⤷ global[0]` |
| 4 | 0.30 | `   ⤷ type[1]` |
| 271 | 20.58 | `⤷ "function names" subsection` |
| 66 | 5.01 | `⤷ export "remainder"` |
| 54 | 4.10 | `   ⤷ func[6]` |
| 53 | 4.02 | `      ⤷ remainder` |
| 63 | 4.78 | `⤷ export "divide"` |
| 54 | 4.10 | `   ⤷ func[3]` |
| 53 | 4.02 | `      ⤷ divide` |
| 21 | 1.59 | `⤷ export "substract"` |
| 9 | 0.68 | `   ⤷ func[1]` |
| 8 | 0.61 | `      ⤷ substract` |
| 20 | 1.52 | `⤷ export "multiply"` |
| 9 | 0.68 | `   ⤷ func[2]` |
| 8 | 0.61 | `      ⤷ multiply` |
| 17 | 1.29 | `⤷ export "power"` |
| 9 | 0.68 | `   ⤷ func[5]` |
| 8 | 0.61 | `      ⤷ power` |
| 15 | 1.14 | `⤷ export "add"` |
| 9 | 0.68 | `   ⤷ func[0]` |
| 8 | 0.61 | `      ⤷ add` |
| 13 | 0.99 | `⤷ custom section 'linking'` |
| 11 | 0.84 | `⤷ export "memory"` |
| 2 | 0.15 | `   ⤷ memory[0]` |
| 6 | 0.46 | `⤷ type[0]` |
