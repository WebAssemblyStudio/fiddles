(module $Quick

  (global $return (mut i32)(i32.const 1))

  (func $add 
    (param i32 i32) 
    (result i32)
    (local $i i32)

    i32.const 10
    set_local $i

    ;;suma los parametros, guarda resultado en param0
    get_local 0
    get_local 1
    i32.add
    set_local 0

    ;;comienzo del bucle
    loop $l1

      ;;Incrementa en 1 el resultado de la suma de los parametros
      get_local 0
      i32.const 1
      i32.add
      set_local 0

      ;;incrementa i en 1 unidad por paso del bucle
      ;;si i es menor a 10 continua con el bucle
      get_local $i
      i32.const 1
      i32.sub

      tee_local $i
      i32.const 0
      i32.ne
      br_if $l1  
    end
    get_local 0
  )

  (export "add" (func $add))
)