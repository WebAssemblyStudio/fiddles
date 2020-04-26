# Twiggy Analysis

Twiggy is a code size profiler, learn more about it [here](https://github.com/rustwasm/twiggy).

## Top

| Shallow Bytes | Shallow % | Item |
| ------------: | --------: | :--- |
| 13888 | 33.20 | `custom section '.debug_info'` |
| 9580 | 22.90 | `custom section '.debug_str'` |
| 7755 | 18.54 | `custom section '.debug_line'` |
| 4080 | 9.75 | `custom section '.debug_abbrev'` |
| 1658 | 3.96 | `memcpy` |
| 1039 | 2.48 | `data[2]` |
| 500 | 1.20 | `custom section '.debug_loc'` |
| 496 | 1.19 | `custom section '.debug_ranges'` |
| 341 | 0.82 | `fwrite` |
| 327 | 0.78 | `__stdio_write` |
| 267 | 0.64 | `"function names" subsection` |
| 175 | 0.42 | `strlen` |
| 174 | 0.42 | `__overflow` |
| 164 | 0.39 | `__lockfile` |
| 151 | 0.36 | `data[1]` |
| 146 | 0.35 | `puts` |
| 117 | 0.28 | `writev_c` |
| 92 | 0.22 | `__towrite` |
| 83 | 0.20 | `__stdout_write` |
| 83 | 0.20 | `__stdio_seek` |
| 82 | 0.20 | `__unlockfile` |

### Note:
52 items had a shallow size percent less than 0.1 and were not listed above.


## Dominators

| Retained Bytes | Retained % | Dominator Tree |
| ------------: | --------: | :--- |
| 39883 | 95.33 | `<meta root>` |
| 13888 | 33.20 | `⤷ custom section '.debug_info'` |
| 9580 | 22.90 | `⤷ custom section '.debug_str'` |
| 7755 | 18.54 | `⤷ custom section '.debug_line'` |
| 4080 | 9.75 | `⤷ custom section '.debug_abbrev'` |
| 3094 | 7.40 | `⤷ export "main"` |
| 3087 | 7.38 | `   ⤷ func[1]` |
| 3082 | 7.37 | `      ⤷ main` |
| 3071 | 7.34 | `         ⤷ func[9]` |
| 3065 | 7.33 | `            ⤷ puts` |
| 2213 | 5.29 | `               ⤷ func[7]` |
| 2212 | 5.29 | `                  ⤷ fputs` |
| 2009 | 4.80 | `                     ⤷ func[6]` |
| 2000 | 4.78 | `                        ⤷ fwrite` |
| 1659 | 3.97 | `                           ⤷ func[17]` |
| 1658 | 3.96 | `                              ⤷ memcpy` |
| 176 | 0.42 | `                     ⤷ func[18]` |
| 175 | 0.42 | `                        ⤷ strlen` |
| 187 | 0.45 | `               ⤷ func[3]` |
| 186 | 0.44 | `                  ⤷ __lockfile` |
| 182 | 0.44 | `               ⤷ func[8]` |
| 181 | 0.43 | `                  ⤷ __overflow` |
| 151 | 0.36 | `               ⤷ data[1]` |
| 93 | 0.22 | `               ⤷ func[5]` |
| 92 | 0.22 | `                  ⤷ __towrite` |
| 87 | 0.21 | `               ⤷ func[4]` |
| 82 | 0.20 | `                  ⤷ __unlockfile` |
| 500 | 1.20 | `⤷ custom section '.debug_loc'` |
| 496 | 1.19 | `⤷ custom section '.debug_ranges'` |
| 267 | 0.64 | `⤷ "function names" subsection` |
| 129 | 0.31 | `⤷ export "writev_c"` |
| 118 | 0.28 | `   ⤷ func[2]` |
| 117 | 0.28 | `      ⤷ writev_c` |

### Note:
12 items had a retained size percent less than 0.1 and were not listed above.
