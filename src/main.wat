(module
  (func $program
    (call $block)
    (call $consume (get_global $period)))
  (func $block
    (if (call $match ())
      (then
        (loop
          (call $ident)
          (call $consume (get_global $equals))
          (br_if 0
            (call $match (get_global $comma))))))
    (if (call $match (get_global $var))
      (then
        (loop
          (call $ident)
          (br_if 0 (call $match (get_global $comma))))))
    (loop
      (if (call $match (get_global $procedure))
        (then
          (call $ident)
          (call $consume (get_global $semicolon))
          (call $block)
          (call $consume (get_global $semicolon))
          (br 1))))
    (call $statement))
  (func $statement
    (if (call $match (get_global $if))
      (then
        (call $condition)
        (call $consume (get_global $then))
        (call $statement)
        (return)))
    (if (call $match (get_global $while))
      (then
        (call $condition)
        (call $consume (get_global $do))
        (call $statement)
        (return)))
    (if (call $match (get_global $write))
      (then
        (call $expression)
        (return)))
    (if (call $match (get_global $read))
      (then
        (call $ident)
        (return))))
  (func $condition
    (call $expression)
    (if (call $match (get_global $less))
      (then
        (call $expression)
        (return)))
    (if (call $match (get_global $greater))
      (then
        (call $expression)
        (return)))
    (if (call $match (get_global $equal))
      (then
        (call $expression)
        (return))))
  (func $expression)

  (func $match (param i32))
  (func $consume (param i32))
)
