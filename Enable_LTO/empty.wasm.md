# Twiggy Analysis

Twiggy is a code size profiler, learn more about it [here](https://github.com/rustwasm/twiggy).

## Top

| Shallow Bytes | Shallow % | Item |
| ------------: | --------: | :--- |
| 22 | 17.60 | `export "rust_eh_personality"` |
| 22 | 17.60 | `"function names" subsection` |
| 12 | 9.60 | `custom section 'linking'` |
| 9 | 7.20 | `export "memory"` |
| 8 | 6.40 | `global[0]` |
| 4 | 3.20 | `table[0]` |
| 3 | 2.40 | `type[0]` |
| 3 | 2.40 | `rust_eh_personality` |
| 2 | 1.60 | `memory[0]` |
| 1 | 0.80 | `func[0]` |


## Dominators

| Retained Bytes | Retained % | Dominator Tree |
| ------------: | --------: | :--- |
| 74 | 59.20 | `<meta root>` |
| 29 | 23.20 | `⤷ export "rust_eh_personality"` |
| 7 | 5.60 | `   ⤷ func[0]` |
| 3 | 2.40 | `      ⤷ type[0]` |
| 3 | 2.40 | `      ⤷ rust_eh_personality` |
| 22 | 17.60 | `⤷ "function names" subsection` |
| 12 | 9.60 | `⤷ custom section 'linking'` |
| 11 | 8.80 | `⤷ export "memory"` |
| 2 | 1.60 | `   ⤷ memory[0]` |
