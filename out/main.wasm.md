# Twiggy Analysis

Twiggy is a code size profiler, learn more about it [here](https://github.com/rustwasm/twiggy).

## Top

| Shallow Bytes | Shallow % | Item |
| ------------: | --------: | :--- |
| 12 | 12.37 | `custom section 'linking'` |
| 10 | 10.31 | `export "add_one"` |
| 10 | 10.31 | `"function names" subsection` |
| 9 | 9.28 | `export "memory"` |
| 8 | 8.25 | `add_one` |
| 5 | 5.15 | `type[0]` |
| 4 | 4.12 | `table[0]` |
| 2 | 2.06 | `memory[0]` |
| 1 | 1.03 | `func[0]` |


## Dominators

| Retained Bytes | Retained % | Dominator Tree |
| ------------: | --------: | :--- |
| 57 | 58.76 | `<meta root>` |
| 24 | 24.74 | `⤷ export "add_one"` |
| 14 | 14.43 | `   ⤷ func[0]` |
| 8 | 8.25 | `      ⤷ add_one` |
| 5 | 5.15 | `      ⤷ type[0]` |
| 12 | 12.37 | `⤷ custom section 'linking'` |
| 11 | 11.34 | `⤷ export "memory"` |
| 2 | 2.06 | `   ⤷ memory[0]` |
| 10 | 10.31 | `⤷ "function names" subsection` |
