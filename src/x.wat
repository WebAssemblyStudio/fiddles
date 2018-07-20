(function{char.ml:49,14-153} camlStdlib__char__lowercase_1015 (c/1016: val)
 (catch
   (catch
     (if (>= c/1016 131) (if (<= c/1016 181) (exit 9) (exit 12)) (exit 12))
   with(12)
     (catch
       (if (>= c/1016 385) (if (<= c/1016 429) (exit 9) (exit 11)) (exit 11))
     with(11)
       (catch
         (if (>= c/1016 433) (if (<= c/1016 445) (exit 9) (exit 10))
           (exit 10))
       with(10) c/1016)))
 with(9) (+ c/1016 64)))