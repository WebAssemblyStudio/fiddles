# Twiggy Analysis

Twiggy is a code size profiler, learn more about it [here](https://github.com/rustwasm/twiggy).

## Top

| Shallow Bytes | Shallow % | Item |
| ------------: | --------: | :--- |
| 13883 | 31.24 | `custom section '.debug_info'` |
| 9599 | 21.60 | `custom section '.debug_str'` |
| 7785 | 17.52 | `custom section '.debug_line'` |
| 4243 | 9.55 | `custom section '.debug_abbrev'` |
| 3176 | 7.15 | `custom section '.debug_pubtypes'` |
| 1653 | 3.72 | `code[13]` |
| 1075 | 2.42 | `custom section '.debug_pubnames'` |
| 352 | 0.79 | `custom section '.debug_ranges'` |
| 325 | 0.73 | `code[10]` |
| 315 | 0.71 | `code[6]` |
| 275 | 0.62 | `custom section '.debug_loc'` |
| 256 | 0.58 | `code[15]` |
| 173 | 0.39 | `code[7]` |
| 170 | 0.38 | `code[14]` |
| 154 | 0.35 | `code[8]` |
| 108 | 0.24 | `code[1]` |
| 91 | 0.20 | `code[5]` |
| 83 | 0.19 | `code[11]` |
| 81 | 0.18 | `code[12]` |
| 80 | 0.18 | `code[3]` |
| 72 | 0.16 | `code[4]` |

### Note:
54 items had a shallow size percent less than 0.1 and were not listed above.


## Dominators

| Retained Bytes | Retained % | Dominator Tree |
| ------------: | --------: | :--- |
| 43690 | 98.32 | `<meta root>` |
| 13883 | 31.24 | `⤷ custom section '.debug_info'` |
| 9599 | 21.60 | `⤷ custom section '.debug_str'` |
| 7785 | 17.52 | `⤷ custom section '.debug_line'` |
| 4243 | 9.55 | `⤷ custom section '.debug_abbrev'` |
| 3176 | 7.15 | `⤷ custom section '.debug_pubtypes'` |
| 3087 | 6.95 | `⤷ export "main"` |
| 3080 | 6.93 | `   ⤷ func[0]` |
| 3075 | 6.92 | `      ⤷ code[0]` |
| 3064 | 6.90 | `         ⤷ func[8]` |
| 3058 | 6.88 | `            ⤷ code[8]` |
| 1978 | 4.45 | `               ⤷ func[6]` |
| 1969 | 4.43 | `                  ⤷ code[6]` |
| 1654 | 3.72 | `                     ⤷ func[13]` |
| 1653 | 3.72 | `                        ⤷ code[13]` |
| 362 | 0.81 | `               ⤷ func[3]` |
| 361 | 0.81 | `                  ⤷ code[3]` |
| 264 | 0.59 | `                     ⤷ func[15]` |
| 256 | 0.58 | `                        ⤷ code[15]` |
| 187 | 0.42 | `               ⤷ func[7]` |
| 180 | 0.41 | `                  ⤷ code[7]` |
| 171 | 0.38 | `               ⤷ func[14]` |
| 170 | 0.38 | `                  ⤷ code[14]` |
| 92 | 0.21 | `               ⤷ func[5]` |
| 91 | 0.20 | `                  ⤷ code[5]` |
| 77 | 0.17 | `               ⤷ func[4]` |
| 72 | 0.16 | `                  ⤷ code[4]` |
| 1075 | 2.42 | `⤷ custom section '.debug_pubnames'` |
| 352 | 0.79 | `⤷ custom section '.debug_ranges'` |
| 275 | 0.62 | `⤷ custom section '.debug_loc'` |
| 120 | 0.27 | `⤷ export "writev_c"` |
| 109 | 0.25 | `   ⤷ func[1]` |
| 108 | 0.24 | `      ⤷ code[1]` |

### Note:
15 items had a retained size percent less than 0.1 and were not listed above.
