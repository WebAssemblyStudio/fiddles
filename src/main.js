

function quickselectJS(arr, compare, k, left = 0, right = arr.length - 1) {
    quickselectStep(arr, k, left, right, compare)
}

function quickselectStep(arr, k, left, right, compare) {
    while (right > left) {
        if (right - left > 600) {
            var n = right - left + 1
            var m = k - left + 1
            var z = Math.log(n)
            var s = 0.5 * Math.exp(2 * z / 3)
            var sd = 0.5 * Math.sqrt(z * s * (n - s) / n) * (m - n / 2 < 0 ? -1 : 1)
            var newLeft  = Math.max(left, Math.floor(k - m * s / n + sd)) | 0
            var newRight = Math.min(right, Math.floor(k + (n - m) * s / n + sd)) | 0
            quickselectStep(arr, k, newLeft, newRight, compare)
        }

        var t = arr[k]
        var i = left
        var j = right

        swap(arr, left, k)
        if (compare(arr[right], t) > 0) swap(arr, left, right)

        while (i < j) {
            swap(arr, i, j)
            i++;
            j--;
            while (compare(arr[i], t) < 0) i++;
            while (compare(arr[j], t) > 0) j--;
        }

        if (compare(arr[left], t) === 0) swap(arr, left, j);
        else {
            j++;
            swap(arr, j, right);
        }

        if (j <= k) left = j + 1;
        if (k <= j) right = j - 1;
    }
}

function swap(arr, i, j) {
    let tmp = arr[i]
    arr[i] = arr[j]
    arr[j] = tmp
}


const arr = new Array(100000);

for (let i = 0; i < arr.length; i++) {
  arr[i] = (arr.length - i) % 1000;
}

function benchJS() {
  quickselectJS(arr, (a, b) => a - b, 500);
}

WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const { benchSlow, benchFast } = result.instance.exports;
  
  // warmup
  for (let i = 0; i < 100; i++) benchSlow();
  console.time('quickselectSlow');
  for (let i = 0; i < 100; i++) benchSlow();
  console.timeEnd('quickselectSlow');

  // warmup
  for (let i = 0; i < 100; i++) benchFast();
  console.time('quickselectFast');
  for (let i = 0; i < 100; i++) benchFast();
  console.timeEnd('quickselectFast');

  for (let i = 0; i < 100; i++) benchJS();
  console.time('quickselectJavaScript');
  for (let i = 0; i < 100; i++) benchJS();
  console.timeEnd('quickselectJavaScript');

}).catch(console.error);
