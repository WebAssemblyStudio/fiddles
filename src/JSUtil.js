
/*** MathUtil ***/
if (typeof (MathUtil) == 'undefined') {
    MathUtil = {};
}

(function () {
    MathUtil.decimal = {};
    //依照起始跟結尾還有scale去建立陣列
    MathUtil.decimal.createDecimalSet = function (start, end, scale) {
        var temp = new Array();
        for (var i = start; i <= end; i = MathUtil.decimal.add(i, scale)) {
            temp.push(i);
        }
        return temp;
    };
    MathUtil.decimal.add = function (v1, v2) {
        return function (arg1, arg2) {
			if(arg1==null || arg1.length==0){arg1=0;};
			if(arg2==null || arg2.length==0){arg2=0;};
            var r1, r2, m;
            try {
                r1 = arg1.toString().split(".")[1].length;
            } catch (e) {
                r1 = 0;
            }
            try {
                r2 = arg2.toString().split(".")[1].length;
            } catch (e) {
                r2 = 0;
            }
            m = Math.pow(10, Math.max(r1, r2));
            return (mul(arg1, m) + mul(arg2, m)) / m;
        }(v1, v2);
    };
    MathUtil.decimal.subtract = function (v1, v2) {
        return function (arg1, arg2) {
			if(arg1==null || arg1.length==0){arg1=0;};
			if(arg2==null || arg2.length==0){arg2=0;};
            var r1, r2, m;
            try {
                r1 = arg1.toString().split(".")[1].length;
            } catch (e) {
                r1 = 0;
            }
            try {
                r2 = arg2.toString().split(".")[1].length;
            } catch (e) {
                r2 = 0;
            }
            m = Math.pow(10, Math.max(r1, r2));
            return (mul(arg1, m) - mul(arg2, m)) / m;// .toFixed(n);
        }(v1, v2);
    };
    MathUtil.decimal.multiply = function (v1, v2) {
        return function (arg1, arg2) {
			if(arg1==null || arg1.length==0){arg1=0;};
			if(arg2==null || arg2.length==0){arg2=0;};
            return mul(arg1, arg2);
        }(v1, v2);
    };
    MathUtil.decimal.divide = function (v1, v2) {
        return function (arg1, arg2) {
            var t1 = 0, t2 = 0, r1, r2;
            try {
                t1 = arg1.toString().split(".")[1].length;
            } catch (e) {
            }
            try {
                t2 = arg2.toString().split(".")[1].length;
            } catch (e) {
            }
            r1 = Number(arg1.toString().replace(".", ""));
            r2 = Number(arg2.toString().replace(".", ""));
            return mul((r1 / r2), Math.pow(10, t2 - t1));
        }(v1, v2);
    };
    // Because MathUtil.decimal.divide(100, 200.123456) = 0.0004996915503997693
    // used arg1 = Math.round(arg1 * 10000)
    MathUtil.decimal.divide2 = function (v1, v2) {
        return function (arg1, arg2) {
            var t1 = 0, t2 = 0, r1, r2;
            try {
                arg1 = Math.round(arg1 * 10000);
                t1 = arg1.toString().split(".")[1].length;
            } catch (e) {
            }
            try {
                arg2 = Math.round(arg2 * 10000);
                t2 = arg2.toString().split(".")[1].length;
            } catch (e) {
            }

            r1 = Number(arg1.toString().replace(".", ""));
            r2 = Number(arg2.toString().replace(".", ""));
            return mul((r1 / r2), Math.pow(10, t2 - t1));
        }(v1, v2);
    };
    MathUtil.isZeroPointFive = function (value) {
        if (value.match(/^[0]+(.)+[5]+$/) == null) {
            return false;
        } else {
            return true;
        }
    };
    MathUtil.isInteger = function (value) {
        if (value.match(/^\d+$/) == null)
            return false;
        else
            return true;
    };
    MathUtil.isNumeric = function (sText, decimals, negatives) {
        var isNumber = true;
        var numDecimals = 0;
        var validChars = "0123456789";
        if (decimals) validChars += ".";
        if (negatives) validChars += "-";
        var thisChar;
        if (sText.length == 0) return false;
        for (var i = 0; i < sText.length && isNumber == true; i++) {
            thisChar = sText.charAt(i);
            if (negatives && thisChar == "-" && i > 0) isNumber = false;
            if (decimals && thisChar == ".") {
                numDecimals = numDecimals + 1;
                if (i == 0 || i == sText.length - 1) isNumber = false;
                if (numDecimals > 1) isNumber = false;
            }
            if (validChars.indexOf(thisChar) == -1) isNumber = false;
        }
        return isNumber;
    };
    MathUtil.isPositive = function (number) {
        return (number >= 0);
        /*
		var isPositive=true;
		if (number<0)  isPositive = false;
		return isPositive;
		*/
    };
    MathUtil.roundp = function (num, pos) {
        var size = Math.pow(10, pos);
        return Math.round(num * size) / size;
    };
    MathUtil.floor = function (num) {
        return Math.floor(num);
    };
    MathUtil.percentage = function (amount, totalAmount) {
        var percentage = 0;
        if (amount != 0) {
            var divide = MathUtil.decimal.divide2(amount, totalAmount);
            var multiply = MathUtil.decimal.multiply(divide, 100);
            percentage = MathUtil.roundp(multiply, 1);
        }
        return percentage;
    };
    MathUtil.currentBetAmountShow = function (bet, totalBet, unit, showAmount) {
        if (typeof (unit) == "undefined") {
            unit = "";
        }
        if (typeof (showAmount) == "undefined") {
            showAmount = false;
        }

        var val = 0;
        if (showAmount) {
            if (bet < 1000) {
                unit = "";
                val = CurrencyUtil.format(bet, 1);
            } else if (bet >= 1000 && bet < 1000000) {
                var divide = MathUtil.decimal.divide2(bet, 1000);
                if (MathUtil.roundp(divide, 1) != 1000) {
                    unit = "K";
                    val = CurrencyUtil.format(MathUtil.roundp(divide, 1), 1);
                } else {
                    unit = "M";
                    divide = MathUtil.decimal.divide2(bet, 1000000);
                    val = CurrencyUtil.format(MathUtil.roundp(divide, 1), 1);
                }
            } else {
                unit = "M";
                var divide = MathUtil.decimal.divide2(bet, 1000000);
                val = CurrencyUtil.format(MathUtil.roundp(divide, 1), 1);
            }
        } else {
            if (bet != 0) {
                var divide = MathUtil.decimal.divide2(bet, totalBet);
                var multiply = MathUtil.decimal.multiply(divide, 100);
                val = CurrencyUtil.format(MathUtil.roundp(multiply, 1));
            }
        }
        return val + "" + unit;
    };
    MathUtil.getRandomNumber = function (beginNumber, maxNumber) {
        return (Math.floor(Math.random() * maxNumber) + beginNumber);
    };
    var mul = function (arg1, arg2) {
        var t1 = 0, t2 = 0, r1, r2, s1 = arg1.toString(), s2 = arg2.toString();
        try {
            t1 = s1.split(".")[1].length;
        } catch (e) {
        }
        try {
            t2 = s2.split(".")[1].length;
        } catch (e) {
        }
        r1 = Number(s1.toString().replace(".", ""));
        r2 = Number(s2.toString().replace(".", ""));
        return r1 * r2 / Math.pow(10, t1 + t2);
    };
})();



// 判斷是否支援，有支援才載入wasm，並在載入完成後替換掉原本較慢的方法
if ('WebAssembly' in window) {
  WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
    main: {
      log(s) {
        // console.log(s);
        alert(s);
      }
    },
    env: {
      abort(_msg, _file, line, column) {
        console.error("abort called at main.ts:" + line + ":" + column);
      }
    },
  }).then(result => {
    const exports = result.instance.exports;
    let testWasm = confirm("執行wasm? (非wasm執行會較久，請耐心等待)");

    // for test
    if(testWasm) {
      // 有支援的瀏覽器則做替換
      MathUtil.decimal.add = exports.add;
      MathUtil.decimal.subtract = exports.subtract;
      MathUtil.decimal.multiply = exports.multiply;
      MathUtil.decimal.divide = exports.divide;
    }

    // run test case
    let report = "";
    report += testAdd(exports) + "\n";
    report += testSubtract(exports) + "\n";
    report += testMultiply(exports) + "\n";
    report += testDivide(exports) + "\n";

    alert(report);

  }).catch(console.error);
}

const count = 50000;


function testAdd(exports) {
  var start = new Date();
  for (var i = 0; i < count; i++) {
    var r = MathUtil.decimal.add(0.2, 0.1);
    // if (i % 1000 === 0) {
    //   console.log(">> " + r);
    // }
  }
  var end = new Date();
  return "testAdd : " + (end.getTime() - start.getTime()) + " ms";
  // console.log("testAdd : " + (end.getTime() - start.getTime()) + " ms");
}

function testSubtract(exports) {
  var start = new Date();
  for (var i = 0; i < count; i++) {
    var r = MathUtil.decimal.subtract(0.2, 0.1);
    // if (i % 1000 === 0) {
    //   console.log(">> " + r);
    // }
  }
  var end = new Date();
  return "testSubtract : " + (end.getTime() - start.getTime()) + " ms";
  // console.log("testSubtract : " + (end.getTime() - start.getTime()) + " ms");
}

function testMultiply(exports) {
  var start = new Date();
  for (var i = 0; i < count; i++) {
    var r = MathUtil.decimal.multiply(0.2, 0.1);
    // if (i % 1000 === 0) {
    //   console.log(r);
    // }
  }
  var end = new Date();
  return "testMultiply : " + (end.getTime() - start.getTime()) + " ms";
  // console.log("testMultiply : " + (end.getTime() - start.getTime()) + " ms");
}

function testDivide(exports) {
  var start = new Date();
  for (var i = 0; i < count; i++) {
    var r = MathUtil.decimal.divide(100, 200.123456);
    // if (i % 1000 === 0) {
    //   console.log(">> " + r);
    // }
  }
  var end = new Date();
  return "testDivide : " + (end.getTime() - start.getTime()) + " ms";
  // console.log("testDivide : " + (end.getTime() - start.getTime()) + " ms");
}

function getRandom(x) {
  return Math.random().toFixed(x);
};