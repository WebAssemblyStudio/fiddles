(module $Quick

  (global $return (mut i32)(i32.const 1))

  (func $add 
    (param i32 i32) 
    (result i32)
    (local $i i32)

    ;;suma los parametros, guarda resultado en param0
    get_local 0
    get_local 1
    i32.add
    tee_local 0

    ;;comienzo del bucle
    (loop $l1



      ;;incrementa i en 1 unidad por paso del bucle
      get_local $i
      i32.const 1
      i32.add
      tee_local $i

      ;;si i es menor a 10 continua con el bucle
      get_local $i
      i32.const 10
      i32.eq
      br_if $l1  
      get_local 0
      return
    )
  )

  (export "add" (func $add))
)