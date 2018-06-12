enum Hex {

    ZERO       = 0x00; // 0
    //             0x01; // -1
    //             0x02; // 1
    //             ...   // zig-zag encoded varints
    MAX        = 0xEF; // -120, max. zig-zag encoded varint
  
    NULL       = 0xF0; // null
    TRUE       = 0xF1; // true
    FALSE      = 0xF2; // false
    EOBJECT    = 0xF3; // {}
    EARRAY     = 0xF4; // []
    ESTRING    = 0xF5; // ""
    OBJECT     = 0xF6; // {...}
    ARRAY      = 0xF7; // [...]
    INTEGER    = 0xF8; // number (zig-zag encoded varint32)
    LONG       = 0xF9; // Long   (zig-zag encoded varint64)
    FLOAT      = 0xFA; // number (float32)
    DOUBLE     = 0xFB; // number (float64)
    STRING     = 0xFC; // string (varint length + data)
    STRING_ADD = 0xFD; // string (varint length + data, add to dictionary)
    STRING_GET = 0xFE; // string (varint index to get from dictionary)
    BINARY     = 0xFF; // bytes (varint length + data)
}