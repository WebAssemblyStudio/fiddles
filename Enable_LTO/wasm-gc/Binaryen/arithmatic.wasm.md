# Twiggy Analysis

Twiggy is a code size profiler, learn more about it [here](https://github.com/rustwasm/twiggy).

## Top

| Shallow Bytes | Shallow % | Item |
| ------------: | --------: | :--- |
| 183 | 19.20 | `data[1]` |
| 103 | 10.81 | `code[4]` |
| 99 | 10.39 | `data[2]` |
| 98 | 10.28 | `code[8]` |
| 81 | 8.50 | `code[7]` |
| 62 | 6.51 | `code[9]` |
| 48 | 5.04 | `code[3]` |
| 48 | 5.04 | `code[6]` |
| 39 | 4.09 | `data[0]` |
| 13 | 1.36 | `type[2]` |
| 13 | 1.36 | `custom section 'linking'` |
| 12 | 1.26 | `export "substract"` |
| 12 | 1.26 | `export "remainder"` |
| 11 | 1.15 | `export "multiply"` |
| 9 | 0.94 | `export "memory"` |
| 9 | 0.94 | `export "divide"` |
| 8 | 0.84 | `global[0]` |
| 8 | 0.84 | `export "power"` |
| 8 | 0.84 | `code[0]` |
| 8 | 0.84 | `code[1]` |
| 8 | 0.84 | `code[2]` |
| 8 | 0.84 | `code[5]` |
| 6 | 0.63 | `type[0]` |
| 6 | 0.63 | `export "add"` |
| 5 | 0.52 | `type[3]` |
| 4 | 0.42 | `type[1]` |
| 2 | 0.21 | `memory[0]` |
| 1 | 0.10 | `func[0]` |
| 1 | 0.10 | `func[1]` |
| 1 | 0.10 | `func[2]` |
| 1 | 0.10 | `func[3]` |
| 1 | 0.10 | `func[4]` |
| 1 | 0.10 | `func[5]` |
| 1 | 0.10 | `func[6]` |
| 1 | 0.10 | `func[7]` |
| 1 | 0.10 | `func[8]` |
| 1 | 0.10 | `func[9]` |


## Dominators

| Retained Bytes | Retained % | Dominator Tree |
| ------------: | --------: | :--- |
| 600 | 62.96 | `<meta root>` |
| 378 | 39.66 | `⤷ func[4]` |
| 373 | 39.14 | `   ⤷ code[4]` |
| 262 | 27.49 | `      ⤷ func[9]` |
| 256 | 26.86 | `         ⤷ code[9]` |
| 194 | 20.36 | `            ⤷ func[8]` |
| 180 | 18.89 | `               ⤷ code[8]` |
| 82 | 8.60 | `                  ⤷ func[7]` |
| 81 | 8.50 | `                     ⤷ code[7]` |
| 13 | 1.36 | `               ⤷ type[2]` |
| 5 | 0.52 | `         ⤷ type[3]` |
| 8 | 0.84 | `      ⤷ global[0]` |
| 4 | 0.42 | `   ⤷ type[1]` |
| 61 | 6.40 | `⤷ export "remainder"` |
| 49 | 5.14 | `   ⤷ func[6]` |
| 48 | 5.04 | `      ⤷ code[6]` |
| 58 | 6.09 | `⤷ export "divide"` |
| 49 | 5.14 | `   ⤷ func[3]` |
| 48 | 5.04 | `      ⤷ code[3]` |
| 21 | 2.20 | `⤷ export "substract"` |
| 9 | 0.94 | `   ⤷ func[1]` |
| 8 | 0.84 | `      ⤷ code[1]` |
| 20 | 2.10 | `⤷ export "multiply"` |
| 9 | 0.94 | `   ⤷ func[2]` |
| 8 | 0.84 | `      ⤷ code[2]` |
| 17 | 1.78 | `⤷ export "power"` |
| 9 | 0.94 | `   ⤷ func[5]` |
| 8 | 0.84 | `      ⤷ code[5]` |
| 15 | 1.57 | `⤷ export "add"` |
| 9 | 0.94 | `   ⤷ func[0]` |
| 8 | 0.84 | `      ⤷ code[0]` |
| 13 | 1.36 | `⤷ custom section 'linking'` |
| 11 | 1.15 | `⤷ export "memory"` |
| 2 | 0.21 | `   ⤷ memory[0]` |
| 6 | 0.63 | `⤷ type[0]` |
