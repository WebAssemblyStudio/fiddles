(module
  (global $BEGIN   i32 (i32.const 0))
  (global $END     i32 (i32.const 1))
  (global $SEMI    i32 (i32.const 2))
  (global $PLUS    i32 (i32.const 3))
  (global $MINUS   i32 (i32.const 4))
  (global $LESS    i32 (i32.const 5))
  (global $GREATER i32 (i32.const 6))
  (global $EQUAL i32 (i32.const 6))
  (global $IDENT   i32 (i32.const 7))
  (func $match (param i32) (result i32) (i32.const 0))
  (func $consume (param i32))
  (func $statement
    (if (call $match (get_global $BEGIN)) (then
      (loop $loop
        (call $statement)
        (br_if $loop
          (i32.eqz (call $match (get_global $SEMI)))))
      (call $consume (get_global $END)))
    (else (if (call $match (get_global $IF)) (then
      (call $condition)
      (call $consume (get_global $THEN))
      (call $statement))
    (else (if (call $match (get_global $IF)) (then
      (call $condition
      (call $consume (get_global $THEN))
      (call $statement)))
    (else (if (call $match (get_global $WRITE)) (then
      (call $expression))
    (else (if (call $match (get_global $READ)) (then
      (call $consume (get_global $IDENT)))
    (else (if (call $match (get_global $IDENT)) (then
      (call $consume (get_global $ASSIGN)))
    (else (if (call $match (get_global $CALL)) (then
      (call $consume (get_global $IDENT)))))))))))))))))
  (func $block
    (if (call $match (get_global $VAR)) (then
      (loop $loop
        (call $consume (get_global $IDENT))
        (br_if $loop
          (i32.eqz (call $match (get_global $COMMA)))))
      (call $consume (get_global $SEMI))))
    (call $statement))
  (func $condition
    (if (call $match (get_global $ODD)) (then
      (call $expression))
    (else
      (call $expression)
      (if (call $match (get_global $LESS)) (then)
      (else (if (call $match (get_global $GREATER)) (then)
      (else (call $consume (get_global $EQUAL)))))))))
  (func $expression
    (call $term)
    (loop
      (if (call $match (get_global $PLUS)) (then
        (call $term)
        (br 1))
      (else (if (call $match (get_global $MINUS)) (then
        (call $term)
        (br 1))
      (else return))))))
  (func $term)
)