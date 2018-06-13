# Twiggy Analysis

Twiggy is a code size profiler, learn more about it [here](https://github.com/rustwasm/twiggy).

## Top

| Shallow Bytes | Shallow % | Item |
| ------------: | --------: | :--- |
| 6439 | 39.69 | `code[3]` |
| 1851 | 11.41 | `code[7]` |
| 1592 | 9.81 | `code[6]` |
| 1556 | 9.59 | `code[12]` |
| 1079 | 6.65 | `code[2]` |
| 705 | 4.35 | `code[16]` |
| 600 | 3.70 | `code[14]` |
| 431 | 2.66 | `code[11]` |
| 431 | 2.66 | `code[13]` |
| 384 | 2.37 | `code[15]` |
| 381 | 2.35 | `code[8]` |
| 186 | 1.15 | `code[1]` |
| 103 | 0.63 | `code[9]` |
| 98 | 0.60 | `code[5]` |
| 81 | 0.50 | `code[4]` |
| 62 | 0.38 | `code[10]` |
| 52 | 0.32 | `code[17]` |

### Note:
38 items had a shallow size percent less than 0.1 and were not listed above.


## Dominators

| Retained Bytes | Retained % | Dominator Tree |
| ------------: | --------: | :--- |
| 16196 | 99.83 | `<meta root>` |
| 6445 | 39.73 | `⤷ func[3]` |
| 6439 | 39.69 | `   ⤷ code[3]` |
| 3256 | 20.07 | `⤷ func[1]` |
| 3247 | 20.01 | `   ⤷ code[1]` |
| 3061 | 18.87 | `      ⤷ func[2]` |
| 3060 | 18.86 | `         ⤷ code[2]` |
| 1593 | 9.82 | `            ⤷ func[6]` |
| 1592 | 9.81 | `               ⤷ code[6]` |
| 388 | 2.39 | `            ⤷ func[8]` |
| 381 | 2.35 | `               ⤷ code[8]` |
| 1852 | 11.42 | `⤷ func[7]` |
| 1851 | 11.41 | `   ⤷ code[7]` |
| 1562 | 9.63 | `⤷ func[12]` |
| 1556 | 9.59 | `  ���⤷ code[12]` |
| 715 | 4.41 | `⤷ export "tensor"` |
| 706 | 4.35 | `   ⤷ func[16]` |
| 705 | 4.35 | `      ⤷ code[16]` |
| 612 | 3.77 | `⤷ export "multiply"` |
| 601 | 3.70 | `   ⤷ func[14]` |
| 600 | 3.70 | `      ⤷ code[14]` |
| 444 | 2.74 | `⤷ export "substract"` |
| 432 | 2.66 | `   ⤷ func[13]` |
| 431 | 2.66 | `      ⤷ code[13]` |
| 438 | 2.70 | `⤷ export "add"` |
| 432 | 2.66 | `   ⤷ func[11]` |
| 431 | 2.66 | `      ⤷ code[11]` |
| 391 | 2.41 | `⤷ export "dot"` |
| 385 | 2.37 | `   ⤷ func[15]` |
| 384 | 2.37 | `      ⤷ code[15]` |
| 361 | 2.23 | `⤷ func[9]` |
| 360 | 2.22 | `   ⤷ code[9]` |
| 257 | 1.58 | `      ⤷ func[10]` |
| 256 | 1.58 | `         ⤷ code[10]` |
| 194 | 1.20 | `            ⤷ func[5]` |
| 180 | 1.11 | `               ⤷ code[5]` |
| 82 | 0.51 | `                  ⤷ func[4]` |
| 81 | 0.50 | `                     ⤷ code[4]` |
| 60 | 0.37 | `⤷ func[17]` |
| 52 | 0.32 | `   ⤷ code[17]` |

### Note:
13 items had a retained size percent less than 0.1 and were not listed above.
