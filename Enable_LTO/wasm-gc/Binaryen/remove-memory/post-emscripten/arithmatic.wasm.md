# Twiggy Analysis

Twiggy is a code size profiler, learn more about it [here](https://github.com/rustwasm/twiggy).

## Top

| Shallow Bytes | Shallow % | Item |
| ------------: | --------: | :--- |
| 100 | 16.31 | `code[4]` |
| 92 | 15.01 | `code[8]` |
| 81 | 13.21 | `code[7]` |
| 56 | 9.14 | `code[9]` |
| 48 | 7.83 | `code[3]` |
| 48 | 7.83 | `code[6]` |
| 13 | 2.12 | `type[2]` |
| 13 | 2.12 | `custom section 'linking'` |
| 12 | 1.96 | `export "substract"` |
| 12 | 1.96 | `export "remainder"` |
| 11 | 1.79 | `export "multiply"` |
| 9 | 1.47 | `export "memory"` |
| 9 | 1.47 | `export "divide"` |
| 8 | 1.31 | `global[0]` |
| 8 | 1.31 | `export "power"` |
| 8 | 1.31 | `code[0]` |
| 8 | 1.31 | `code[1]` |
| 8 | 1.31 | `code[2]` |
| 8 | 1.31 | `code[5]` |
| 6 | 0.98 | `type[0]` |
| 6 | 0.98 | `export "add"` |
| 5 | 0.82 | `type[3]` |
| 4 | 0.65 | `type[1]` |
| 2 | 0.33 | `memory[0]` |
| 1 | 0.16 | `func[0]` |
| 1 | 0.16 | `func[1]` |
| 1 | 0.16 | `func[2]` |
| 1 | 0.16 | `func[3]` |
| 1 | 0.16 | `func[4]` |
| 1 | 0.16 | `func[5]` |
| 1 | 0.16 | `func[6]` |
| 1 | 0.16 | `func[7]` |
| 1 | 0.16 | `func[8]` |
| 1 | 0.16 | `func[9]` |


## Dominators

| Retained Bytes | Retained % | Dominator Tree |
| ------------: | --------: | :--- |
| 585 | 95.43 | `<meta root>` |
| 363 | 59.22 | `⤷ func[4]` |
| 358 | 58.40 | `   ⤷ code[4]` |
| 250 | 40.78 | `      ⤷ func[9]` |
| 244 | 39.80 | `         ⤷ code[9]` |
| 188 | 30.67 | `            ⤷ func[8]` |
| 174 | 28.38 | `               ⤷ code[8]` |
| 82 | 13.38 | `                  ⤷ func[7]` |
| 81 | 13.21 | `                     ⤷ code[7]` |
| 13 | 2.12 | `               ⤷ type[2]` |
| 5 | 0.82 | `         ⤷ type[3]` |
| 8 | 1.31 | `      ⤷ global[0]` |
| 4 | 0.65 | `   ⤷ type[1]` |
| 61 | 9.95 | `⤷ export "remainder"` |
| 49 | 7.99 | `   ⤷ func[6]` |
| 48 | 7.83 | `      ⤷ code[6]` |
| 58 | 9.46 | `⤷ export "divide"` |
| 49 | 7.99 | `   ⤷ func[3]` |
| 48 | 7.83 | `      ⤷ code[3]` |
| 21 | 3.43 | `⤷ export "substract"` |
| 9 | 1.47 | `   ⤷ func[1]` |
| 8 | 1.31 | `      ⤷ code[1]` |
| 20 | 3.26 | `⤷ export "multiply"` |
| 9 | 1.47 | `   ⤷ func[2]` |
| 8 | 1.31 | `      ⤷ code[2]` |
| 17 | 2.77 | `⤷ export "power"` |
| 9 | 1.47 | `   ⤷ func[5]` |
| 8 | 1.31 | `      ⤷ code[5]` |
| 15 | 2.45 | `⤷ export "add"` |
| 9 | 1.47 | `   ⤷ func[0]` |
| 8 | 1.31 | `      ⤷ code[0]` |
| 13 | 2.12 | `⤷ custom section 'linking'` |
| 11 | 1.79 | `⤷ export "memory"` |
| 2 | 0.33 | `   ⤷ memory[0]` |
| 6 | 0.98 | `⤷ type[0]` |
