type Comparator<T> = (a: T, b: T) => i32;

export function quickselectFast<T>(arr: T[], compare: Comparator<T>, k: i32, left: i32 = 0, right: i32 = arr.length - 1): void {
    quickselectStep(arr, k, left, right, compare)
}

function quickselectStep<T>(arr: T[], k: i32, left: i32, right: i32, compare: Comparator<T>): void {
    while (right > left) {
        if (right - left > 600) {
            var n = right - left + 1
            var m = k - left + 1
            var z = Math.log(n)
            var s = 0.5 * Math.exp(z * (2 / 3))
            var sd = 0.5 * Math.sqrt(z * s * (n - s) / n) * Math.sign(m - (n >>> 1))
            var newLeft = max<i32>(left, Math.floor(k - m * s / n + sd) as i32)
            var newRight = min<i32>(right, Math.floor(k + (n - m) * s / n + sd) as i32)
            quickselectStep(arr, k, newLeft, newRight, compare)
        }

        var t = unchecked(arr[k])
        var i = left
        var j = right

        swap(arr, left, k)
        if (compare(arr[right], t) > 0) {
          swap(arr, left, right)
        }

        while (i < j) {
            swap(arr, i, j)
            i++;
            j--;
            while (compare(arr[i], t) < 0) i++;
            while (compare(arr[j], t) > 0) j--;
        }

        if (compare(arr[left], t) === 0) {
          swap(arr, left, j);
       }  else {
            j++;
            swap(arr, j, right);
        }

        if (j <= k) left  = j + 1;
        if (k <= j) right = j - 1;
    }
}

@inline
function swap<T>(arr: T[], i: i32, j: i32): void {
    let tmp = unchecked(arr[i])
    unchecked(arr[i] = arr[j])
    unchecked(arr[j] = tmp)
}