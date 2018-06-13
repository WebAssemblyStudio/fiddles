# Twiggy Analysis

Twiggy is a code size profiler, learn more about it [here](https://github.com/rustwasm/twiggy).

## Top

| Shallow Bytes | Shallow % | Item |
| ------------: | --------: | :--- |
| 103 | 16.40 | `code[4]` |
| 98 | 15.61 | `code[8]` |
| 81 | 12.90 | `code[7]` |
| 62 | 9.87 | `code[9]` |
| 48 | 7.64 | `code[3]` |
| 48 | 7.64 | `code[6]` |
| 13 | 2.07 | `type[2]` |
| 13 | 2.07 | `custom section 'linking'` |
| 12 | 1.91 | `export "substract"` |
| 12 | 1.91 | `export "remainder"` |
| 11 | 1.75 | `export "multiply"` |
| 9 | 1.43 | `export "memory"` |
| 9 | 1.43 | `export "divide"` |
| 8 | 1.27 | `global[0]` |
| 8 | 1.27 | `export "power"` |
| 8 | 1.27 | `code[0]` |
| 8 | 1.27 | `code[1]` |
| 8 | 1.27 | `code[2]` |
| 8 | 1.27 | `code[5]` |
| 6 | 0.96 | `type[0]` |
| 6 | 0.96 | `export "add"` |
| 5 | 0.80 | `type[3]` |
| 4 | 0.64 | `type[1]` |
| 2 | 0.32 | `memory[0]` |
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
| 600 | 95.54 | `<meta root>` |
| 378 | 60.19 | `⤷ func[4]` |
| 373 | 59.39 | `   ⤷ code[4]` |
| 262 | 41.72 | `      ⤷ func[9]` |
| 256 | 40.76 | `         ⤷ code[9]` |
| 194 | 30.89 | `            ⤷ func[8]` |
| 180 | 28.66 | `               ⤷ code[8]` |
| 82 | 13.06 | `                  ⤷ func[7]` |
| 81 | 12.90 | `                     ⤷ code[7]` |
| 13 | 2.07 | `               ⤷ type[2]` |
| 5 | 0.80 | `         ⤷ type[3]` |
| 8 | 1.27 | `      ⤷ global[0]` |
| 4 | 0.64 | `   ⤷ type[1]` |
| 61 | 9.71 | `⤷ export "remainder"` |
| 49 | 7.80 | `   ⤷ func[6]` |
| 48 | 7.64 | `      ⤷ code[6]` |
| 58 | 9.24 | `⤷ export "divide"` |
| 49 | 7.80 | `   ⤷ func[3]` |
| 48 | 7.64 | `      ⤷ code[3]` |
| 21 | 3.34 | `⤷ export "substract"` |
| 9 | 1.43 | `   ⤷ func[1]` |
| 8 | 1.27 | `      ⤷ code[1]` |
| 20 | 3.18 | `⤷ export "multiply"` |
| 9 | 1.43 | `   ⤷ func[2]` |
| 8 | 1.27 | `      ⤷ code[2]` |
| 17 | 2.71 | `⤷ export "power"` |
| 9 | 1.43 | `   ⤷ func[5]` |
| 8 | 1.27 | `      ⤷ code[5]` |
| 15 | 2.39 | `⤷ export "add"` |
| 9 | 1.43 | `   ⤷ func[0]` |
| 8 | 1.27 | `      ⤷ code[0]` |
| 13 | 2.07 | `⤷ custom section 'linking'` |
| 11 | 1.75 | `⤷ export "memory"` |
| 2 | 0.32 | `   ⤷ memory[0]` |
| 6 | 0.96 | `⤷ type[0]` |
