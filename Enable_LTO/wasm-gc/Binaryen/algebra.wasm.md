# Twiggy Analysis

Twiggy is a code size profiler, learn more about it [here](https://github.com/rustwasm/twiggy).

## Top

| Shallow Bytes | Shallow % | Item |
| ------------: | --------: | :--- |
| 6439 | 36.58 | `code[3]` |
| 1851 | 10.51 | `code[7]` |
| 1592 | 9.04 | `code[6]` |
| 1556 | 8.84 | `code[12]` |
| 1108 | 6.29 | `data[1]` |
| 1079 | 6.13 | `code[2]` |
| 705 | 4.00 | `code[16]` |
| 600 | 3.41 | `code[14]` |
| 431 | 2.45 | `code[11]` |
| 431 | 2.45 | `code[13]` |
| 384 | 2.18 | `code[15]` |
| 381 | 2.16 | `code[8]` |
| 268 | 1.52 | `data[0]` |
| 186 | 1.06 | `code[1]` |
| 103 | 0.59 | `code[9]` |
| 98 | 0.56 | `code[5]` |
| 81 | 0.46 | `code[4]` |
| 62 | 0.35 | `code[10]` |
| 52 | 0.30 | `code[17]` |

### Note:
38 items had a shallow size percent less than 0.1 and were not listed above.


## Dominators

| Retained Bytes | Retained % | Dominator Tree |
| ------------: | --------: | :--- |
| 17304 | 98.30 | `<meta root>` |
| 6445 | 36.61 | `⤷ func[3]` |
| 6439 | 36.58 | `   ⤷ code[3]` |
| 3256 | 18.50 | `⤷ func[1]` |
| 3247 | 18.44 | `   ⤷ code[1]` |
| 3061 | 17.39 | `      ⤷ func[2]` |
| 3060 | 17.38 | `         ⤷ code[2]` |
| 1593 | 9.05 | `            ⤷ func[6]` |
| 1592 | 9.04 | `               ⤷ code[6]` |
| 388 | 2.20 | `            ⤷ func[8]` |
| 381 | 2.16 | `               ⤷ code[8]` |
| 1852 | 10.52 | `⤷ func[7]` |
| 1851 | 10.51 | `   ⤷ code[7]` |
| 1562 | 8.87 | `⤷ func[12]` |
| 1556 | 8.84 | `   ⤷ code[12]` |
| 1108 | 6.29 | `⤷ data[1]` |
| 715 | 4.06 | `⤷ export "tensor"` |
| 706 | 4.01 | `   ⤷ func[16]` |
| 705 | 4.00 | `      ⤷ code[16]` |
| 612 | 3.48 | `⤷ export "multiply"` |
| 601 | 3.41 | `   ⤷ func[14]` |
| 600 | 3.41 | `      ⤷ code[14]` |
| 444 | 2.52 | `⤷ export "substract"` |
| 432 | 2.45 | `   ⤷ func[13]` |
| 431 | 2.45 | `      ⤷ code[13]` |
| 438 | 2.49 | `⤷ export "add"` |
| 432 | 2.45 | `   ⤷ func[11]` |
| 431 | 2.45 | `      ⤷ code[11]` |
| 391 | 2.22 | `⤷ export "dot"` |
| 385 | 2.19 | `   ⤷ func[15]` |
| 384 | 2.18 | `      ⤷ code[15]` |
| 361 | 2.05 | `⤷ func[9]` |
| 360 | 2.04 | `   ⤷ code[9]` |
| 257 | 1.46 | `      ⤷ func[10]` |
| 256 | 1.45 | `         ⤷ code[10]` |
| 194 | 1.10 | `            ⤷ func[5]` |
| 180 | 1.02 | `               ⤷ code[5]` |
| 82 | 0.47 | `                  ⤷ func[4]` |
| 81 | 0.46 | `                     ⤷ code[4]` |
| 60 | 0.34 | `⤷ func[17]` |
| 52 | 0.30 | `   ⤷ code[17]` |

### Note:
13 items had a retained size percent less than 0.1 and were not listed above.
