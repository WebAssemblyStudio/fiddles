# Twiggy Analysis

Twiggy is a code size profiler, learn more about it [here](https://github.com/rustwasm/twiggy).

## Top

| Shallow Bytes | Shallow % | Item |
| ------------: | --------: | :--- |
| 12 | 31.58 | `custom section 'linking'` |
| 9 | 23.68 | `export "memory"` |
| 2 | 5.26 | `memory[0]` |


## Dominators

| Retained Bytes | Retained % | Dominator Tree |
| ------------: | --------: | :--- |
| 23 | 60.53 | `<meta root>` |
| 12 | 31.58 | `⤷ custom section 'linking'` |
| 11 | 28.95 | `⤷ export "memory"` |
| 2 | 5.26 | `   ⤷ memory[0]` |
