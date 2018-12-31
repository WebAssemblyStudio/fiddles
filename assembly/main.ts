declare function _logi(x: i32): void;
declare function _logf(x: f64): void;
declare function _log_str(x: string): void;

export function log<T>(item: T): void {
  if (isReference<T>()) {
    if (isString<T>()) {
      _log_str(changetype<string>(item));
    } else {
      _logi(changetype<i32>(item));
    }
  } else {
    if (isInteger<T>()) {
      _logi(<i32>item);
    } else {
      _logf(<f64>item);
    }
  }
}

log("abc");
log(123);
log(123.0);

