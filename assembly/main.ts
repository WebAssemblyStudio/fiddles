declare function log(value: i32): void;

export enum Type {
  Unknown = -1,

  Null,
  Reference,
  String,
  Array,

  I8,
  I16,
  I32,
  I64,

  U8,
  U16,
  U32,
  U64,

  F32,
  F64,
}

@inline
function kindof<T>(value: T): i32 {
  if (isReference<T>(value)) {
         if (!value)          { return Type.Null; }
    else if (isString(value)) { return Type.String; }
    else if (isArray(value))  { return Type.Array; }
    else                      { return Type.Reference; }
  } else {
    if (isInteger(value)) {
      if (sizeof<T>() == 1) {
        if (isSigned<T>()) { return Type.I8;  } else { return Type.U8;  }
      } else if (sizeof<T>() == 2) {
        if (isSigned<T>()) { return Type.I16; } else { return Type.U16; }
      } else if (sizeof<T>() == 4) {
        if (isSigned<T>()) { return Type.I32; } else { return Type.U32; }
      } else if (sizeof<T>() == 8) {
        if (isSigned<T>()) { return Type.I64; } else { return Type.U64; }
      }
    } else if (isFloat(value)) {
           if (sizeof<T>() == 4) { return Type.F32; }
      else if (sizeof<T>() == 8) { return Type.F64; }
    } else {
      return Type.Unknown;
    }
  }
}

@inline
function foo<T>(arg: T): i32 {
  switch (kindof(arg)) {
    case Type.I32: return -1;
    case Type.F64: return 1;
    default:       return 0;
  }
}

var t  = foo(1);
var t2 = foo(2.0);

var str0: string = null;
var str1: string = "abc";

log(kindof(str0));      // Null
log(kindof(str1));      // String
log(kindof(1));         // I32
log(kindof(1.0));       // F64
log(kindof(<f32>1.0));  // F32
log(kindof(<u64>100));  // U64
