# Twiggy Analysis

Twiggy is a code size profiler, learn more about it [here](https://github.com/rustwasm/twiggy).

## Top

| Shallow Bytes | Shallow % | Item |
| ------------: | --------: | :--- |
| 8 | 13.79 | `run` |
| 6 | 10.34 | `export "run"` |
| 6 | 10.34 | `"function names" subsection` |
| 3 | 5.17 | `type[0]` |
| 1 | 1.72 | `func[0]` |


## Dominators

| Retained Bytes | Retained % | Dominator Tree |
| ------------: | --------: | :--- |
| 24 | 41.38 | `<meta root>` |
| 18 | 31.03 | `⤷ export "run"` |
| 12 | 20.69 | `   ⤷ func[0]` |
| 8 | 13.79 | `      ⤷ run` |
| 3 | 5.17 | `      ⤷ type[0]` |
| 6 | 10.34 | `⤷ "function names" subsection` |
