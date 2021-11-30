# Twiggy Analysis

Twiggy is a code size profiler, learn more about it [here](https://github.com/rustwasm/twiggy).

## Top

| Shallow Bytes | Shallow % | Item |
| ------------: | --------: | :--- |
| 1806 | 25.74 | `custom section '.debug_line'` |
| 1484 | 21.15 | `custom section '.debug_info'` |
| 1393 | 19.85 | `custom section '.debug_str'` |
| 899 | 12.81 | `custom section '.debug_abbrev'` |
| 382 | 5.44 | `memset` |
| 316 | 4.50 | `__stpncpy` |
| 307 | 4.38 | `main` |
| 71 | 1.01 | `custom section '.debug_ranges'` |
| 63 | 0.90 | `"function names" subsection` |
| 41 | 0.58 | `data[0]` |
| 23 | 0.33 | `custom section '.debug_macinfo'` |
| 14 | 0.20 | `import env::putc_js` |
| 14 | 0.20 | `export "__heap_base"` |
| 14 | 0.20 | `strncpy` |
| 13 | 0.19 | `export "__data_end"` |
| 9 | 0.13 | `export "memory"` |

### Note:
16 items had a shallow size percent less than 0.1 and were not listed above.


## Dominators

| Retained Bytes | Retained % | Dominator Tree |
| ------------: | --------: | :--- |
| 6879 | 98.03 | `<meta root>` |
| 1806 | 25.74 | `⤷ custom section '.debug_line'` |
| 1484 | 21.15 | `⤷ custom section '.debug_info'` |
| 1393 | 19.85 | `⤷ custom section '.debug_str'` |
| 1089 | 15.52 | `⤷ export "main"` |
| 1082 | 15.42 | `   ⤷ func[1]` |
| 1077 | 15.35 | `      ⤷ main` |
| 722 | 10.29 | `         ⤷ func[4]` |
| 714 | 10.18 | `            ⤷ strncpy` |
| 700 | 9.98 | `               ⤷ func[3]` |
| 699 | 9.96 | `                  ⤷ __stpncpy` |
| 383 | 5.46 | `                     ⤷ func[2]` |
| 382 | 5.44 | `                        ⤷ memset` |
| 41 | 0.58 | `         ⤷ data[0]` |
| 899 | 12.81 | `⤷ custom section '.debug_abbrev'` |
| 71 | 1.01 | `⤷ custom section '.debug_ranges'` |
| 63 | 0.90 | `⤷ "function names" subsection` |
| 23 | 0.33 | `⤷ custom section '.debug_macinfo'` |
| 21 | 0.30 | `⤷ export "__heap_base"` |
| 19 | 0.27 | `⤷ export "__data_end"` |
| 11 | 0.16 | `⤷ export "memory"` |

### Note:
6 items had a retained size percent less than 0.1 and were not listed above.
