let x = '../out/main.wasm';

let instance = null;
let memoryStates = new WeakMap();
function BytePacker(arrbuff) {
  var buffer = arrbuff;
  var currentindex = 0;
  Object.defineProperty(this, 'Index', {
    get: function () {
      return currentindex;
    },
    set: function (pos) {
      currentindex = pos
    }
  });
  this.ReadUInt = () => {
    var arr = new Uint32Array(buffer, currentindex);
    var val = arr[0];
    currentindex += arr.BYTES_PER_ELEMENT
    return val;
  }
  this.ReadInt = () => {
    var arr = new Int32Array(buffer, currentindex);
    var val = arr[0];
    currentindex += arr.BYTES_PER_ELEMENT
    return val;
  }
  this.ReadByte = () => {
    var arr = new Uint8Array(buffer, currentindex);
    var val = arr[0];
    currentindex += arr.BYTES_PER_ELEMENT
    return val;
  }
  this.ReadSByte = () => {
    var arr = new Int8Array(buffer, currentindex);
    var val = arr[0];
    currentindex += arr.BYTES_PER_ELEMENT
    return val;
  }
  this.ReadShort = () => {
    var arr = new Int16Array(buffer, currentindex);
    var val = arr[0];
    currentindex += arr.BYTES_PER_ELEMENT
    return val;
  }
  this.ReadUShort = () => {
    var arr = new Uint16Array(buffer, currentindex);
    var val = arr[0];
    currentindex += arr.BYTES_PER_ELEMENT
    return val;
  }
  this.ReadFloat = () => {
    var arr = new Float32Array(buffer, currentindex);
    var val = arr[0];
    currentindex += arr.BYTES_PER_ELEMENT
    return val;
  }
  this.ReadDouble = () => {
    var arr = new Float64Array(buffer, currentindex);
    var val = arr[0];
    currentindex += arr.BYTES_PER_ELEMENT
    return val;
  }
  this.ReadLong = () => {
    var arr = new BigInt64Array(buffer, currentindex);
    var val = arr[0];
    currentindex += arr.BYTES_PER_ELEMENT
    return val;
  }
  this.ReadULong = () => {
    var arr = new BigUint64Array(buffer, currentindex);
    var val = arr[0];
    currentindex += arr.BYTES_PER_ELEMENT
    return val;
  }
  this.ReadString = () => {
    var arrlen = this.ReadInt();
    var buff = new Uint8Array(buffer, currentindex);
    var txtdec = new TextDecoder();
    var val = txtdec.decode(buffer);
    currentindex += 4 + arrlen;
    return val;
  }
  this.WriteUInt = (val) => {
    var arr = new Uint32Array(buffer, currentindex);
    arr[0] = val;
    currentindex += arr.BYTES_PER_ELEMENT
  }
  this.WriteInt = (val) => {
    var arr = new Int32Array(buffer, currentindex);
    arr[0] = val;
    currentindex += arr.BYTES_PER_ELEMENT
  }
  this.WriteByte = (val) => {
    var arr = new Uint8Array(buffer, currentindex);
    arr[0] = val;
    currentindex += arr.BYTES_PER_ELEMENT
  }
  this.WriteSByte = (val) => {
    var arr = new Int8Array(buffer, currentindex);
    arr[0] = val;
    currentindex += arr.BYTES_PER_ELEMENT
  }
  this.WriteShort = (val) => {
    var arr = new Int16Array(buffer, currentindex);
    arr[0] = val;
    currentindex += arr.BYTES_PER_ELEMENT
  }
  this.WriteUShort = (val) => {
    var arr = new Uint16Array(buffer, currentindex);
    arr[0] = val;
    currentindex += arr.BYTES_PER_ELEMENT
  }
  this.WriteFloat = (val) => {
    var arr = new Float32Array(buffer, currentindex);
    arr[0] = val;
    currentindex += arr.BYTES_PER_ELEMENT
  }
  this.WriteDouble = (val) => {
    var arr = new Float64Array(buffer, currentindex);
    arr[0] = val;
    currentindex += arr.BYTES_PER_ELEMENT
  }
  this.WriteLong = (val) => {
    var arr = new BigInt64Array(buffer, currentindex);
    arr[0] = val;
    currentindex += arr.BYTES_PER_ELEMENT
  }
  this.WriteULong = (val) => {
    var arr = new BigUint64Array(buffer, currentindex);
    arr[0] = val;
    currentindex += arr.BYTES_PER_ELEMENT
  }
  this.WriteString = (val) => {
    var textenc = new TextEncoder();
    var buff = textenc.encode(value);
    this.WriteInt(buff.byteLength);
    buffer.set(buff, currentindex)
    currentindex += buff.byteLength;
  }
}
function syscall(instance, n, args) {
  switch (n) {
    default:
      // console.log("Syscall " + n + " NYI.");
      break;
    case /* brk */ 45: return 0;
    case /* writev */ 146:
      return instance.exports.writev_c(args[0], args[1], args[2]);
    case /* mmap2 */ 192:
      debugger;
      const memory = instance.exports.memory;
      let memoryState = memoryStates.get(instance);
      const requested = args[1];
      if (!memoryState) {
        memoryState = {
          object: memory,
          currentPosition: memory.buffer.byteLength,
        };
        memoryStates.set(instance, memoryState);
      }
      let cur = memoryState.currentPosition;
      if (cur + requested > memory.buffer.byteLength) {
        const need = Math.ceil((cur + requested - memory.buffer.byteLength) / 65536);
        memory.grow(need);
      }
      memoryState.currentPosition += requested;
      return cur;
  }
}
function Vector2() {
  var { memory, Vector2_new, GetArea,Vector2_get_magnitude } = instance.exports;
  var m_PTR = 0;
  var get_bp = () => new BytePacker(memory.buffer);
  Object.defineProperty(this, 'pointer', {
    get: function () {
      return m_PTR
    },
    set: function (ptr) {
      m_PTR = ptr
    }
  });
  Object.defineProperty(this, 'x', {
    get: function () {
      var bp = get_bp();
      bp.Index = m_PTR;
      return bp.ReadFloat()
    },
    set: function (i) {
      var bp = get_bp();
      bp.Index = m_PTR;
      bp.WriteFloat(i)
    }
  });
  Object.defineProperty(this, 'y', {
    get: function () {
      var bp = get_bp();
      bp.Index = m_PTR + 4;
      return bp.ReadFloat()
    },
    set: function (i) {
      var bp = get_bp();
      bp.Index = m_PTR + 4;
      bp.WriteFloat(i)
    }
  });
  this.new = (x, y) => {
    m_PTR = Vector2_new(x, y);
    return this;
  }
  Object.defineProperty(this, 'magnitude', {
    get: function () {
      return Vector2_get_magnitude(m_PTR);
    }
  });
  this.GetArea = () => GetArea(m_PTR);
}
Vector2.Distance = (a,b) => {
  var {Vector2_Distance} = instance.exports;
  return Vector2_Distance(a.pointer,b.pointer)
}
Vector2.Sub = (a,b) => {
  var {Vector2_Sub} = instance.exports;
  var ret = Vector2_Sub(a.pointer,b.pointer)
  var vc2 = new Vector2();
  vc2.pointer = ret;
  return vc2;
}
let s = "";
fetch(x).then(response =>
  response.arrayBuffer()
).then(bytes =>
  WebAssembly.instantiate(bytes, {
    env: {
      __syscall0: function __syscall0(n) { return syscall(instance, n, []); },
      __syscall1: function __syscall1(n, a) { return syscall(instance, n, [a]); },
      __syscall2: function __syscall2(n, a, b) { return syscall(instance, n, [a, b]); },
      __syscall3: function __syscall3(n, a, b, c) { return syscall(instance, n, [a, b, c]); },
      __syscall4: function __syscall4(n, a, b, c, d) { return syscall(instance, n, [a, b, c, d]); },
      __syscall5: function __syscall5(n, a, b, c, d, e) { return syscall(instance, n, [a, b, c, d, e]); },
      __syscall6: function __syscall6(n, a, b, c, d, e, f) { return syscall(instance, n, [a, b, c, d, e, f]); },
      putc_js: function (c) {
        c = String.fromCharCode(c);
        if (c == "\n") {
          console.log(s);
          s = "";
        } else {
          s += c;
        }
      },
    }
  })
).then(results => {

  instance = results.instance;
  var { main } = instance.exports;
  var vector2 = new Vector2().new(2, 3);
  var vector2_ = new Vector2().new(1, 3);
  var result = Vector2.Sub(vector2,vector2_)
  console.log(result.x,result.y);
  document.getElementById("container").textContent = instance.exports.main();
}).catch(console.error);