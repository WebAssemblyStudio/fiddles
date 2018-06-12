# Twiggy Analysis

Twiggy is a code size profiler, learn more about it [here](https://github.com/rustwasm/twiggy).

## Top

| Shallow Bytes | Shallow % | Item |
| ------------: | --------: | :--- |
| 12 | 21.82 | `custom section 'linking'` |
| 9 | 16.36 | `export "memory"` |
| 4 | 7.27 | `table[0]` |
| 2 | 3.64 | `memory[0]` |
| 1 | 1.82 | `"function names" subsection` |


## Dominators

| Retained Bytes | Retained % | Dominator Tree |
| ------------: | --------: | :--- |
| 24 | 43.64 | `<meta root>` |
| 12 | 21.82 | `⤷ custom section 'linking'` |
| 11 | 20.00 | `⤷ export "memory"` |
| 2 | 3.64 | `   ⤷ memory[0]` |
| 1 | 1.82 | `⤷ "function names" subsection` |
