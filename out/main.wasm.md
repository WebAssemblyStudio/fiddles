# Twiggy Analysis

Twiggy is a code size profiler, learn more about it [here](https://github.com/rustwasm/twiggy).

## Top

| Shallow Bytes | Shallow % | Item |
| ------------: | --------: | :--- |
| 13888 | 34.62 | `custom section '.debug_info'` |
| 9580 | 23.88 | `custom section '.debug_str'` |
| 7755 | 19.33 | `custom section '.debug_line'` |
| 4078 | 10.17 | `custom section '.debug_abbrev'` |
| 1653 | 4.12 | `code[13]` |
| 500 | 1.25 | `custom section '.debug_loc'` |
| 496 | 1.24 | `custom section '.debug_ranges'` |
| 325 | 0.81 | `code[10]` |
| 315 | 0.79 | `code[5]` |
| 173 | 0.43 | `code[6]` |
| 170 | 0.42 | `code[14]` |
| 154 | 0.38 | `code[7]` |
| 153 | 0.38 | `code[2]` |
| 109 | 0.27 | `code[1]` |
| 91 | 0.23 | `code[4]` |
| 83 | 0.21 | `code[11]` |
| 82 | 0.20 | `code[3]` |
| 81 | 0.20 | `code[12]` |

### Note:
48 items had a shallow size percent less than 0.1 and were not listed above.


## Dominators

| Retained Bytes | Retained % | Dominator Tree |
| ------------: | --------: | :--- |
| 39391 | 98.20 | `<meta root>` |
| 13888 | 34.62 | `⤷ custom section '.debug_info'` |
| 9580 | 23.88 | `⤷ custom section '.debug_str'` |
| 7755 | 19.33 | `⤷ custom section '.debug_line'` |
| 4078 | 10.17 | `⤷ custom section '.debug_abbrev'` |
| 2879 | 7.18 | `⤷ export "main"` |
| 2872 | 7.16 | `   ⤷ func[0]` |
| 2867 | 7.15 | `      ⤷ code[0]` |
| 2856 | 7.12 | `         ⤷ func[7]` |
| 2850 | 7.10 | `            ⤷ code[7]` |
| 1978 | 4.93 | `               ⤷ func[5]` |
| 1969 | 4.91 | `                  ⤷ code[5]` |
| 1654 | 4.12 | `                     ⤷ func[13]` |
| 1653 | 4.12 | `                        ⤷ code[13]` |
| 187 | 0.47 | `               ⤷ func[6]` |
| 180 | 0.45 | `                  ⤷ code[6]` |
| 174 | 0.43 | `               ⤷ func[2]` |
| 173 | 0.43 | `                  ⤷ code[2]` |
| 171 | 0.43 | `               ⤷ func[14]` |
| 170 | 0.42 | `                  ⤷ code[14]` |
| 92 | 0.23 | `               ⤷ func[4]` |
| 91 | 0.23 | `                  ⤷ code[4]` |
| 87 | 0.22 | `               ⤷ func[3]` |
| 82 | 0.20 | `                  ⤷ code[3]` |
| 500 | 1.25 | `⤷ custom section '.debug_loc'` |
| 496 | 1.24 | `⤷ custom section '.debug_ranges'` |
| 121 | 0.30 | `⤷ export "writev_c"` |
| 110 | 0.27 | `   ⤷ func[1]` |
| 109 | 0.27 | `      ⤷ code[1]` |

### Note:
13 items had a retained size percent less than 0.1 and were not listed above.
