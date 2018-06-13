# Twiggy Analysis

Twiggy is a code size profiler, learn more about it [here](https://github.com/rustwasm/twiggy).

## Top

| Shallow Bytes | Shallow % | Item |
| ------------: | --------: | :--- |
| 6373 | 39.74 | `code[3]` |
| 1827 | 11.39 | `code[7]` |
| 1565 | 9.76 | `code[6]` |
| 1550 | 9.66 | `code[12]` |
| 1076 | 6.71 | `code[2]` |
| 696 | 4.34 | `code[16]` |
| 591 | 3.68 | `code[14]` |
| 425 | 2.65 | `code[11]` |
| 425 | 2.65 | `code[13]` |
| 378 | 2.36 | `code[8]` |
| 378 | 2.36 | `code[15]` |
| 180 | 1.12 | `code[1]` |
| 100 | 0.62 | `code[9]` |
| 92 | 0.57 | `code[5]` |
| 81 | 0.51 | `code[4]` |
| 56 | 0.35 | `code[10]` |
| 52 | 0.32 | `code[17]` |

### Note:
38 items had a shallow size percent less than 0.1 and were not listed above.


## Dominators

| Retained Bytes | Retained % | Dominator Tree |
| ------------: | --------: | :--- |
| 16010 | 99.83 | `<meta root>` |
| 6379 | 39.77 | `⤷ func[3]` |
| 6373 | 39.74 | `   ⤷ code[3]` |
| 3217 | 20.06 | `⤷ func[1]` |
| 3208 | 20.00 | `   ⤷ code[1]` |
| 3028 | 18.88 | `      ⤷ func[2]` |
| 3027 | 18.87 | `         ⤷ code[2]` |
| 1566 | 9.76 | `            ⤷ func[6]` |
| 1565 | 9.76 | `               ⤷ code[6]` |
| 385 | 2.40 | `            ⤷ func[8]` |
| 378 | 2.36 | `               ⤷ code[8]` |
| 1828 | 11.40 | `⤷ func[7]` |
| 1827 | 11.39 | `   ⤷ code[7]` |
| 1556 | 9.70 | `⤷ func[12]` |
| 1550 | 9.66 | `   ⤷ code[12]` |
| 706 | 4.40 | `⤷ export "tensor"` |
| 697 | 4.35 | `   ⤷ func[16]` |
| 696 | 4.34 | `      ⤷ code[16]` |
| 603 | 3.76 | `⤷ export "multiply"` |
| 592 | 3.69 | `   ⤷ func[14]` |
| 591 | 3.68 | `      ⤷ code[14]` |
| 438 | 2.73 | `⤷ export "substract"` |
| 426 | 2.66 | `   ⤷ func[13]` |
| 425 | 2.65 | `      ⤷ code[13]` |
| 432 | 2.69 | `⤷ export "add"` |
| 426 | 2.66 | `   ⤷ func[11]` |
| 425 | 2.65 | `      ⤷ code[11]` |
| 385 | 2.40 | `⤷ export "dot"` |
| 379 | 2.36 | `   ⤷ func[15]` |
| 378 | 2.36 | `      ⤷ code[15]` |
| 346 | 2.16 | `⤷ func[9]` |
| 345 | 2.15 | `   ⤷ code[9]` |
| 245 | 1.53 | `      ⤷ func[10]` |
| 244 | 1.52 | `         ⤷ code[10]` |
| 188 | 1.17 | `            ⤷ func[5]` |
| 174 | 1.08 | `               ⤷ code[5]` |
| 82 | 0.51 | `                  ⤷ func[4]` |
| 81 | 0.51 | `                     ⤷ code[4]` |
| 60 | 0.37 | `⤷ func[17]` |
| 52 | 0.32 | `   ⤷ code[17]` |

### Note:
13 items had a retained size percent less than 0.1 and were not listed above.
