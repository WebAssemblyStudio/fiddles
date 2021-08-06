function _args_get(argv, argv_buf) {
  try {

    var bufSize = 0;
    mainArgs.forEach(function (arg, i) {
      var ptr = argv_buf + bufSize;
      HEAP32[(((argv) + (i * 4)) >> 2)] = ptr;
      writeAsciiToMemory(arg, ptr);
      bufSize += arg.length + 1;
    });
    return 0;
  } catch (e) {
    if (typeof FS === 'undefined' || !(e instanceof FS.ErrnoError)) abort(e);
    return e.errno;
  }
}

function _args_sizes_get(pargc, pargv_buf_size) {
  try {

    HEAP32[((pargc) >> 2)] = mainArgs.length;
    var bufSize = 0;
    mainArgs.forEach(function (arg) {
      bufSize += arg.length + 1;
    });
    HEAP32[((pargv_buf_size) >> 2)] = bufSize;
    return 0;
  } catch (e) {
    if (typeof FS === 'undefined' || !(e instanceof FS.ErrnoError)) abort(e);
    return e.errno;
  }
}

function _fd_close(fd) {
  try {

    var stream = SYSCALLS.getStreamFromFD(fd);
    FS.close(stream);
    return 0;
  } catch (e) {
    if (typeof FS === 'undefined' || !(e instanceof FS.ErrnoError)) abort(e);
    return e.errno;
  }
}

function _fd_read(fd, iov, iovcnt, pnum) {
  try {

    var stream = SYSCALLS.getStreamFromFD(fd);
    var num = SYSCALLS.doReadv(stream, iov, iovcnt);
    HEAP32[((pnum) >> 2)] = num
    return 0;
  } catch (e) {
    if (typeof FS === 'undefined' || !(e instanceof FS.ErrnoError)) abort(e);
    return e.errno;
  }
}

function _fd_seek(fd, offset_low, offset_high, whence, newOffset) {
  try {


    var stream = SYSCALLS.getStreamFromFD(fd);
    var HIGH_OFFSET = 0x100000000; // 2^32
    // use an unsigned operator on low and shift high by 32-bits
    var offset = offset_high * HIGH_OFFSET + (offset_low >>> 0);

    var DOUBLE_LIMIT = 0x20000000000000; // 2^53
    // we also check for equality since DOUBLE_LIMIT + 1 == DOUBLE_LIMIT
    if (offset <= -DOUBLE_LIMIT || offset >= DOUBLE_LIMIT) {
      return -61;
    }

    FS.llseek(stream, offset, whence);
    (tempI64 = [stream.position >>> 0, (tempDouble = stream.position, (+(Math.abs(tempDouble))) >= 1.0 ? (tempDouble > 0.0 ? ((Math.min((+(Math.floor((tempDouble) / 4294967296.0))), 4294967295.0)) | 0) >>> 0 : (~~((+(Math.ceil((tempDouble - +(((~~(tempDouble))) >>> 0)) / 4294967296.0))))) >>> 0) : 0)], HEAP32[((newOffset) >> 2)] = tempI64[0], HEAP32[(((newOffset) + (4)) >> 2)] = tempI64[1]);
    if (stream.getdents && offset === 0 && whence === 0) stream.getdents = null; // reset readdir state
    return 0;
  } catch (e) {
    if (typeof FS === 'undefined' || !(e instanceof FS.ErrnoError)) abort(e);
    return e.errno;
  }
}

function _fd_write(fd, iov, iovcnt, pnum) {
  try {

    var stream = SYSCALLS.getStreamFromFD(fd);
    var num = SYSCALLS.doWritev(stream, iov, iovcnt);
    HEAP32[((pnum) >> 2)] = num
    return 0;
  } catch (e) {
    if (typeof FS === 'undefined' || !(e instanceof FS.ErrnoError)) abort(e);
    return e.errno;
  }
}
function _exit(status) {
  // void _exit(int status);
  // http://pubs.opengroup.org/onlinepubs/000095399/functions/exit.html
  exit(status);
}
function _proc_exit(code) {
  try {

    _exit(code);
  } catch (e) {
    if (typeof FS === 'undefined' || !(e instanceof FS.ErrnoError)) abort(e);
    return e.errno;
  }
}

function abort(what) {

  what += '';

  ABORT = true;
  EXITSTATUS = 1;

  var output = 'abort(' + what ;
  what = output;

  // Use a wasm runtime error, because a JS error might be seen as a foreign
  // exception, which means we'd run destructors on it. We need the error to
  // simply make the program stop.
  var e = new WebAssembly.RuntimeError(what);

  // Throw the error whether or not MODULARIZE is set because abort is used
  // in code paths apart from instantiation where an exception is expected
  // to be thrown when abort is called.
  throw e;
}

var asmLibraryArg = {
  "args_get": _args_get,
  "args_sizes_get": _args_sizes_get,
  "fd_close": _fd_close,
  "fd_read": _fd_read,
  "fd_seek": _fd_seek,
  "fd_write": _fd_write,
  "proc_exit": _proc_exit
};
var info = {
  'env': asmLibraryArg,
  'wasi_snapshot_preview1': asmLibraryArg,
};

fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes, info)).then(results => {
  instance = results.instance;
  console.log(instance.exports.test(12));
  console.log(instance.exports.APIInitKBWrapper());
}).catch(console.error);
