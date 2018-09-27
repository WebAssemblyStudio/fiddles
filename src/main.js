const { greet, isFullWidth } = wasm_bindgen;

function isFullWidthCharacter(charCode) {
	// Do a cheap trick to better support wrapping of wide characters, treat them as 2 columns
	// http://jrgraphix.net/research/unicode_blocks.php
	//          2E80 — 2EFF   CJK Radicals Supplement
	//          2F00 — 2FDF   Kangxi Radicals
	//          2FF0 — 2FFF   Ideographic Description Characters
	//          3000 — 303F   CJK Symbols and Punctuation
	//          3040 — 309F   Hiragana
	//          30A0 — 30FF   Katakana
	//          3100 — 312F   Bopomofo
	//          3130 — 318F   Hangul Compatibility Jamo
	//          3190 — 319F   Kanbun
	//          31A0 — 31BF   Bopomofo Extended
	//          31F0 — 31FF   Katakana Phonetic Extensions
	//          3200 — 32FF   Enclosed CJK Letters and Months
	//          3300 — 33FF   CJK Compatibility
	//          3400 — 4DBF   CJK Unified Ideographs Extension A
	//          4DC0 — 4DFF   Yijing Hexagram Symbols
	//          4E00 — 9FFF   CJK Unified Ideographs
	//          A000 — A48F   Yi Syllables
	//          A490 — A4CF   Yi Radicals
	//          AC00 — D7AF   Hangul Syllables
	// [IGNORE] D800 — DB7F   High Surrogates
	// [IGNORE] DB80 — DBFF   High Private Use Surrogates
	// [IGNORE] DC00 — DFFF   Low Surrogates
	// [IGNORE] E000 — F8FF   Private Use Area
	//          F900 — FAFF   CJK Compatibility Ideographs
	// [IGNORE] FB00 — FB4F   Alphabetic Presentation Forms
	// [IGNORE] FB50 — FDFF   Arabic Presentation Forms-A
	// [IGNORE] FE00 — FE0F   Variation Selectors
	// [IGNORE] FE20 — FE2F   Combining Half Marks
	// [IGNORE] FE30 — FE4F   CJK Compatibility Forms
	// [IGNORE] FE50 — FE6F   Small Form Variants
	// [IGNORE] FE70 — FEFF   Arabic Presentation Forms-B
	//          FF00 — FFEF   Halfwidth and Fullwidth Forms
	//               [https://en.wikipedia.org/wiki/Halfwidth_and_fullwidth_forms]
	//               of which FF01 - FF5E fullwidth ASCII of 21 to 7E
	// [IGNORE]    and FF65 - FFDC halfwidth of Katakana and Hangul
	// [IGNORE] FFF0 — FFFF   Specials
	charCode = +charCode; // @perf
	return (
		(charCode >= 0x2E80 && charCode <= 0xD7AF)
		|| (charCode >= 0xF900 && charCode <= 0xFAFF)
		|| (charCode >= 0xFF01 && charCode <= 0xFF5E)
	);
}
function runApp() {
  let str = "当时比赛进行到第85分钟，阿扎尔在中场得球。只见比利时球星先后摆脱了亨德森、法比尼奥和菲尔米诺3名利物浦球员的防守，还穿了菲尔米诺的裆。而在得到阿斯皮利奎塔的做球之后，阿扎尔开启了第二波个人表演，他高速带球的同时在凯塔和莫雷诺之间通过变向完成了“两进两出”，两位红军大将一时间被晃得找不到北——阿扎尔甩开凯塔，走内线再走外线连续趟球摆脱莫雷诺，干净利落地劲射远角得手！这次一条龙一气呵成，蓝军10号犹如开挂一般， 精彩且流畅的过人以及精湛的射术在这粒进球中展现得淋漓尽致。当时比赛进行到第85分钟，阿扎尔在中场得球。只见比利时球星先后摆脱了亨德森、法比尼奥和菲尔米诺3名利物浦球员的防守，还穿了菲尔米诺的裆。而在得到阿斯皮利奎塔的做球之后，阿扎尔开启了第二波个人表演，他高速带球的同时在凯塔和莫雷诺之间通过变向完成了“两进两出”，两位红军大将一时间被晃得找不到北——阿扎尔甩开凯塔，走内线再走外线连续趟球摆脱莫雷诺，干净利落地劲射远角得手！这次一条龙一气呵成，蓝军10号犹如开挂一般， 精彩且流畅的过人以及精湛的射术在这粒进球中展现得淋漓尽致。当时比赛进行到第85分钟，阿扎尔在中场得球。只见比利时球星先后摆脱了亨德森、法比尼奥和菲尔米诺3名利物浦球员的防守，还穿了菲尔米诺的裆。而在得到阿斯皮利奎塔的做球之后，阿扎尔开启了第二波个人表演，他高速带球的同时在凯塔和莫雷诺之间通过变向完成了“两进两出”，两位红军大将一时间被晃得找不到北——阿扎尔甩开凯塔，走内线再走外线连续趟球摆脱莫雷诺，干净利落地劲射远角得手！这次一条龙一气呵成，蓝军10号犹如开挂一般， 精彩且流畅的过人以及精湛的射术在这粒进球中展现得淋漓尽致。当时比赛进行到第85分钟，阿扎尔在中场得球。只见比利时球星先后摆脱了亨德森、法比尼奥和菲尔米诺3名利物浦球员的防守，还穿了菲尔米诺的裆。而在得到阿斯皮利奎塔的做球之后，阿扎尔开启了第二波个人表演，他高速带球的同时在凯塔和莫雷诺之间通过变向完成了“两进两出”，两位红军大将一时间被晃得找不到北——阿扎尔甩开凯塔，走内线再走外线连续趟球摆脱莫雷诺，干净利落地劲射远角得手！这次一条龙一气呵成，蓝军10号犹如开挂一般， 精彩且流畅的过人以及精湛的射术在这粒进球中展现得淋漓尽致。当时比赛进行到第85分钟，阿扎尔在中场得球。只见比利时球星先后摆脱了亨德森、法比尼奥和菲尔米诺3名利物浦球员的防守，还穿了菲尔米诺的裆。而在得到阿斯皮利奎塔的做球之后，阿扎尔开启了第二波个人表演，他高速带球的同时在凯塔和莫雷诺之间通过变向完成了“两进两出”，两位红军大将一时间被晃得找不到北——阿扎尔甩开凯塔，走内线再走外线连续趟球摆脱莫雷诺，干净利落地劲射远角得手！这次一条龙一气呵成，蓝军10号犹如开挂一般， 精彩且流畅的过人以及精湛的射术在这粒进球中展现得淋漓尽致。当时比赛进行到第85分钟，阿扎尔在中场得球。只见比利时球星先后摆脱了亨德森、法比尼奥和菲尔米诺3名利物浦球员的防守，还穿了菲尔米诺的裆。而在得到阿斯皮利奎塔的做球之后，阿扎尔开启了第二波个人表演，他高速带球的同时在凯塔和莫雷诺之间通过变向完成了“两进两出”，两位红军大将一时间被晃得找不到北——阿扎尔甩开凯塔，走内线再走外线连续趟球摆脱莫雷诺，干净利落地劲射远角得手！这次一条龙一气呵成，蓝军10号犹如开挂一般， 精彩且流畅的过人以及精湛的射术在这粒进球中展现得淋漓尽致。当时比赛进行到第85分钟，阿扎尔在中场得球。只见比利时球星先后摆脱了亨德森、法比尼奥和菲尔米诺3名利物浦球员的防守，还穿了菲尔米诺的裆。而在得到阿斯皮利奎塔的做球之后，阿扎尔开启了第二波个人表演，他高速带球的同时在凯塔和莫雷诺之间通过变向完成了“两进两出”，两位红军大将一时间被晃得找不到北——阿扎尔甩开凯塔，走内线再走外线连续趟球摆脱莫雷诺，干净利落地劲射远角得手！这次一条龙一气呵成，蓝军10号犹如开挂一般， 精彩且流畅的过人以及精湛的射术在这粒进球中展现得淋漓尽致。当时比赛进行到第85分钟，阿扎尔在中场得球。只见比利时球星先后摆脱了亨德森、法比尼奥和菲尔米诺3名利物浦球员的防守，还穿了菲尔米诺的裆。而在得到阿斯皮利奎塔的做球之后，阿扎尔开启了第二波个人表演，他高速带球的同时在凯塔和莫雷诺之间通过变向完成了“两进两出”，两位红军大将一时间被晃得找不到北——阿扎尔甩开凯塔，走内线再走外线连续趟球摆脱莫雷诺，干净利落地劲射远角得手！这次一条龙一气呵成，蓝军10号犹如开挂一般， 精彩且流畅的过人以及精湛的射术在这粒进球中展现得淋漓尽致。当时比赛进行到第85分钟，阿扎尔在中场得球。只见比利时球星先后摆脱了亨德森、法比尼奥和菲尔米诺3名利物浦球员的防守，还穿了菲尔米诺的裆。而在得到阿斯皮利奎塔的做球之后，阿扎尔开启了第二波个人表演，他高速带球的同时在凯塔和莫雷诺之间通过变向完成了“两进两出”，两位红军大将一时间被晃得找不到北——阿扎尔甩开凯塔，走内线再走外线连续趟球摆脱莫雷诺，干净利落地劲射远角得手！这次一条龙一气呵成，蓝军10号犹如开挂一般， 精彩且流畅的过人以及精湛的射术在这粒进球中展现得淋漓尽致。";
  for (let i = 0; i < 6; i++) {
    str += str;
  }
  let cnt = 0;
  let t0 = performance.now();
  for(let i = 0; i < str.length; i++) {
      cnt += isFullWidthCharacter(str.charCodeAt(i)) ? 1 : 0;
  }
  let t1 = performance.now();
  console.log("JS # Fullwidth char checking took " + (t1 - t0) + " milliseconds.");
  cnt = 0;
  let t2 = performance.now();
  for(let i = 0; i < str.length; i++) {
      cnt += isFullWidth(str.charCodeAt(i)) ? 1 : 0;
  }
  let t3 = performance.now();
  console.log("WASM # Fullwidth char checking took " + (t3 - t2) + " milliseconds.");
}

// Load and instantiate the wasm file, and we specify the source of the wasm
// file here. Once the returned promise is resolved we're ready to go and
// use our imports.
wasm_bindgen('../out/main_bg.wasm').then(runApp).catch(console.error);
