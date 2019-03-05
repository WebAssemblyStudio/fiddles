((function(window) {
    var arguments = [];
    var cp5 = {
        contexts: [],
        images: [],
        sockets: [],
        patterns: []
    };
    var cp5_destroyed = false;
    var FontDetect = (function() {
        function e() {
            if (!n) {
                n = !0;
                var e = document.body,
                    t = document.body.firstChild,
                    i = document.getElementById("fontdetectHelper") || document.createElement("div");
                i.id = "fontdetectHelper";
                r = document.createElement("span");
                r.innerText = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
                i.appendChild(r);
                e.insertBefore(i, t);
                i.style.position = "absolute";
                i.style.visibility = "hidden";
                i.style.top = "-200px";
                i.style.left = "-100000px";
                i.style.width = "100000px";
                i.style.height = "200px";
                i.style.fontSize = "100px"
            }
        }

        function t(e, t) {
            return e instanceof Element ? window.getComputedStyle(e).getPropertyValue(t) : window.jQuery ? $(e).css(t) : ""
        }
        var n = !1,
            i = ["serif", "sans-serif", "monospace", "cursive", "fantasy"],
            r = null;
        return {
            onFontLoaded: (function(t, i, r, o) {
                if (t) {
                    var s = o && o.msInterval ? o.msInterval : 100,
                        a = o && o.msTimeout ? o.msTimeout : 2e3;
                    if (i || r) {
                        if (n || e(), this.isFontLoaded(t)) return void(i && i(t));
                        var l = this,
                            f = (new Date).getTime(),
                            d = setInterval((function() {
                                if (l.isFontLoaded(t)) return clearInterval(d), void i(t);
                                var e = (new Date).getTime();
                                e - f > a && (clearInterval(d), r && r(t))
                            }), s)
                    }
                }
            }),
            isFontLoaded: (function(t) {
                var o = 0,
                    s = 0;
                n || e();
                for (var a = 0; a < i.length; ++a) {
                    if (r.style.fontFamily = '"' + t + '", ' + i[a], o = r.offsetWidth, a > 0 && o != s) return !1;
                    s = o
                }
                return !0
            }),
            whichFont: (function(e) {
                for (var n = t(e, "font-family"), r = n.split(","), o = r.shift(); o;) {
                    o = o.replace(/^\s*['"]?\s*([^'"]*)\s*['"]?\s*$/, "$1");
                    for (var s = 0; s < i.length; s++)
                        if (o == i[s]) return o;
                    if (this.isFontLoaded(o)) return o;
                    o = r.shift()
                }
                return null
            })
        }
    })();
    var haveFontsLoaded = false;
    var idleDeadline = null;

    function idleCallback(deadline) {
        if (cp5_destroyed) return;
        if (deadline["timeRemaining"]() < 0) return;
        idleDeadline = deadline;
        _7a61d285();
        window["requestIdleCallback"](idleCallback)
    }
    if (typeof Module == "undefined") Module = {};
    Module["postRun"] = Module["preRun"] || [];
    Module["postRun"].push((function() {
        if ("requestIdleCallback" in window) {
            window["requestIdleCallback"](idleCallback)
        }
    }));
    var curScript = window.document.currentScript;
    var textInput = document.getElementById("textInput");
    var textInputContainer = document.getElementById("textInputContainer");

    function reload(version) {
        if (window["setLoadingStatus"]) window["setLoadingStatus"]("Updating...");
        setTimeout((function() {
            window.location.reload(true)
        }), 2e3)
    }

    function allocateUTF8(str) {
        if (str == null) return 0;
        var l = str.length * 4 + 1;
        var ptr = _4528ffe0(l);
        stringToUTF8(str, ptr, l);
        return ptr
    }
    var Module = Module || {};
    Module["postRun"] = Module["postRun"] || [];
    Module["postRun"].push((function() {
        window["input"] = {
            "mouse": _6c12216c,
            "keyDown": _6ec285a3,
            "keyUp": _644e12b6,
            "blur": _bfc8fd4,
            "wheel": _4d17c882,
            "prevent_right_click": _1065663f,
            "flushInputHooks": _3e9bd0f2,
            "set_convar": (function(key, value) {
                var k = allocateUTF8(key.toString());
                var v = allocateUTF8(value.toString());
                var r = !!_70538cef(k, v);
                _2a1a33e5(k);
                _2a1a33e5(v);
                return r
            }),
            "get_convar": (function(key) {
                var k = allocateUTF8(key.toString());
                var r = _52132039(k);
                _2a1a33e5(k);
                return r ? UTF8ToString(r) : null
            }),
            "execute": (function(v) {
                var k = allocateUTF8(v.toString());
                _1bf64a7(k);
                _2a1a33e5(k)
            }),
            "print_convar_help": _10a6caac,
            "should_prevent_unload": _2f061953
        }
    }));
    Module["noExitRuntime"] = true;
    Module["print"] = (function(text, color) {
        console.log(text)
    });
    Module["printErr"] = (function(text) {
        console.error(text)
    });
    Module["setStatus"] = (function(text) {
        console.log(text)
    });
    Module["totalDependencies"] = 0;
    Module["monitorRunDependencies"] = (function(left) {
        console.log(left + " dependencies left")
    });
    Module["setStatus"]("Downloading d.js...");
    window["connect"] = (function(ip) {
        var p = allocateUTF8(ip);
        _5d28bd2a(p);
        _2a1a33e5(p)
    });

    function copyToKeyboard(text) {
        var textArea = document.createElement("textarea");
        textArea.style.position = "fixed";
        textArea.style.top = 0;
        textArea.style.left = 0;
        textArea.style.width = "2em";
        textArea.style.height = "2em";
        textArea.style.margin = 0;
        textArea.style.padding = 0;
        textArea.style.border = "none";
        textArea.style.outline = "none";
        textArea.style.boxShadow = "none";
        textArea.style.background = "transparent";
        textArea.value = text;
        document.body.appendChild(textArea);
        textArea.focus();
        textArea.select();
        var res = false;
        try {
            res = document.execCommand("copy");
            if (!res) console.log("execCommand copy failed")
        } catch (e) {}
        document.body.removeChild(textArea);
        if (!res) {
            window["prompt"]("Copy the following link to your clipboard:", text)
        }
    }
    var originalFunctionToString = Function.prototype.toString;
    var Module;
    if (!Module) Module = eval("(function() { try { return  Module || {} } catch(e) { return {} } })()");
    var moduleOverrides = {};
    for (var key in Module) {
        if (Module.hasOwnProperty(key)) {
            moduleOverrides[key] = Module[key]
        }
    }
    var ENVIRONMENT_IS_WEB = true;
    var ENVIRONMENT_IS_WORKER = false;
    var ENVIRONMENT_IS_NODE = false;
    var ENVIRONMENT_IS_SHELL = false;
    if (Module["ENVIRONMENT"]) {
        if (Module["ENVIRONMENT"] === "WEB") {
            ENVIRONMENT_IS_WEB = true
        } else if (Module["ENVIRONMENT"] === "WORKER") {
            ENVIRONMENT_IS_WORKER = true
        } else if (Module["ENVIRONMENT"] === "NODE") {
            ENVIRONMENT_IS_NODE = true
        } else if (Module["ENVIRONMENT"] === "SHELL") {
            ENVIRONMENT_IS_SHELL = true
        } else {
            throw new Error("The provided Module['ENVIRONMENT'] value is not valid. It must be one of: WEB|WORKER|NODE|SHELL.")
        }
    } else {
        ENVIRONMENT_IS_WEB = typeof window === "object";
        ENVIRONMENT_IS_WORKER = typeof importScripts === "function";
        ENVIRONMENT_IS_NODE = typeof process === "object" && typeof require === "function" && !ENVIRONMENT_IS_WEB && !ENVIRONMENT_IS_WORKER;
        ENVIRONMENT_IS_SHELL = !ENVIRONMENT_IS_WEB && !ENVIRONMENT_IS_NODE && !ENVIRONMENT_IS_WORKER
    }
    if (ENVIRONMENT_IS_NODE) {
        if (!Module["print"]) Module["print"] = console.log;
        if (!Module["printErr"]) Module["printErr"] = console.warn;
        var nodeFS;
        var nodePath;
        Module["read"] = function read(filename, binary) {
            if (!nodeFS) nodeFS = require("fs");
            if (!nodePath) nodePath = require("path");
            filename = nodePath["normalize"](filename);
            var ret = nodeFS["readFileSync"](filename);
            return binary ? ret : ret.toString()
        };
        Module["readBinary"] = function readBinary(filename) {
            var ret = Module["read"](filename, true);
            if (!ret.buffer) {
                ret = new Uint8Array(ret)
            }
            assert(ret.buffer);
            return ret
        };
        Module["load"] = function load(f) {
            globalEval(read(f))
        };
        if (!Module["thisProgram"]) {
            if (process["argv"].length > 1) {
                Module["thisProgram"] = process["argv"][1].replace(/\\/g, "/")
            } else {
                Module["thisProgram"] = "unknown-program"
            }
        }
        Module["arguments"] = process["argv"].slice(2);
        if (typeof module !== "undefined") {
            module["exports"] = Module
        }
        process["on"]("uncaughtException", (function(ex) {
            if (!(ex instanceof ExitStatus)) {
                throw ex
            }
        }));
        Module["inspect"] = (function() {
            return "[Emscripten Module object]"
        })
    } else if (ENVIRONMENT_IS_SHELL) {
        if (!Module["print"]) Module["print"] = print;
        if (typeof printErr != "undefined") Module["printErr"] = printErr;
        if (typeof read != "undefined") {
            Module["read"] = read
        } else {
            Module["read"] = function read() {
                throw "no read() available"
            }
        }
        Module["readBinary"] = function readBinary(f) {
            if (typeof readbuffer === "function") {
                return new Uint8Array(readbuffer(f))
            }
            var data = read(f, "binary");
            assert(typeof data === "object");
            return data
        };
        if (typeof scriptArgs != "undefined") {
            Module["arguments"] = scriptArgs
        } else if (typeof arguments != "undefined") {
            Module["arguments"] = arguments
        }
        if (typeof quit === "function") {
            Module["quit"] = (function(status, toThrow) {
                quit(status)
            })
        }
        eval("if (typeof gc === 'function' && gc.toString().indexOf('[native code]') > 0) var gc = undefined")
    } else if (ENVIRONMENT_IS_WEB || ENVIRONMENT_IS_WORKER) {
        Module["read"] = function read(url) {
            var xhr = new XMLHttpRequest;
            xhr.open("GET", url, false);
            xhr.send(null);
            return xhr.responseText
        };
        if (ENVIRONMENT_IS_WORKER) {
            Module["readBinary"] = function read(url) {
                var xhr = new XMLHttpRequest;
                xhr.open("GET", url, false);
                xhr.responseType = "arraybuffer";
                xhr.send(null);
                return xhr.response
            }
        }
        Module["readAsync"] = function readAsync(url, onload, onerror) {
            var xhr = new XMLHttpRequest;
            xhr.open("GET", url, true);
            xhr.responseType = "arraybuffer";
            xhr.onload = function xhr_onload() {
                if (xhr.status == 200 || xhr.status == 0 && xhr.response) {
                    onload(xhr.response)
                } else {
                    onerror()
                }
            };
            xhr.onerror = onerror;
            xhr.send(null)
        };
        if (typeof arguments != "undefined") {
            Module["arguments"] = arguments
        }
        if (typeof console !== "undefined") {
            if (!Module["print"]) Module["print"] = function print(x) {
                console.log(x)
            };
            if (!Module["printErr"]) Module["printErr"] = function printErr(x) {
                console.warn(x)
            }
        } else {
            var TRY_USE_DUMP = false;
            if (!Module["print"]) Module["print"] = TRY_USE_DUMP && typeof dump !== "undefined" ? (function(x) {
                dump(x)
            }) : (function(x) {})
        }
        if (ENVIRONMENT_IS_WORKER) {
            Module["load"] = importScripts
        }
        if (typeof Module["setWindowTitle"] === "undefined") {
            Module["setWindowTitle"] = (function(title) {
                document.title = title
            })
        }
    } else {
        throw "Unknown runtime environment. Where are we?"
    }

    function globalEval(x) {
        eval.call(null, x)
    }
    if (!Module["load"] && Module["read"]) {
        Module["load"] = function load(f) {
            globalEval(Module["read"](f))
        }
    }
    if (!Module["print"]) {
        Module["print"] = (function() {})
    }
    if (!Module["printErr"]) {
        Module["printErr"] = Module["print"]
    }
    if (!Module["arguments"]) {
        Module["arguments"] = []
    }
    if (!Module["thisProgram"]) {
        Module["thisProgram"] = "./this.program"
    }
    if (!Module["quit"]) {
        Module["quit"] = (function(status, toThrow) {
            throw toThrow
        })
    }
    Module.print = Module["print"];
    Module.printErr = Module["printErr"];
    Module["preRun"] = [];
    Module["postRun"] = [];
    for (var key in moduleOverrides) {
        if (moduleOverrides.hasOwnProperty(key)) {
            Module[key] = moduleOverrides[key]
        }
    }
    moduleOverrides = undefined;
    var Runtime = {
        setTempRet0: (function(value) {
            tempRet0 = value;
            return value
        }),
        getTempRet0: (function() {
            return tempRet0
        }),
        stackSave: (function() {
            return STACKTOP
        }),
        stackRestore: (function(stackTop) {
            STACKTOP = stackTop
        }),
        getNativeTypeSize: (function(type) {
            switch (type) {
                case "i1":
                case "i8":
                    return 1;
                case "i16":
                    return 2;
                case "i32":
                    return 4;
                case "i64":
                    return 8;
                case "float":
                    return 4;
                case "double":
                    return 8;
                default:
                    {
                        if (type[type.length - 1] === "*") {
                            return Runtime.QUANTUM_SIZE
                        } else if (type[0] === "i") {
                            var bits = parseInt(type.substr(1));
                            assert(bits % 8 === 0);
                            return bits / 8
                        } else {
                            return 0
                        }
                    }
            }
        }),
        getNativeFieldSize: (function(type) {
            return Math.max(Runtime.getNativeTypeSize(type), Runtime.QUANTUM_SIZE)
        }),
        STACK_ALIGN: 16,
        prepVararg: (function(ptr, type) {
            if (type === "double" || type === "i64") {
                if (ptr & 7) {
                    assert((ptr & 7) === 4);
                    ptr += 4
                }
            } else {
                assert((ptr & 3) === 0)
            }
            return ptr
        }),
        getAlignSize: (function(type, size, vararg) {
            if (!vararg && (type == "i64" || type == "double")) return 8;
            if (!type) return Math.min(size, 8);
            return Math.min(size || (type ? Runtime.getNativeFieldSize(type) : 0), Runtime.QUANTUM_SIZE)
        }),
        dynCall: (function(sig, ptr, args) {
            if (args && args.length) {
                return Module["dynCall_" + sig].apply(null, [ptr].concat(args))
            } else {
                return Module["dynCall_" + sig].call(null, ptr)
            }
        }),
        functionPointers: [],
        addFunction: (function(func) {
            for (var i = 0; i < Runtime.functionPointers.length; i++) {
                if (!Runtime.functionPointers[i]) {
                    Runtime.functionPointers[i] = func;
                    return 2 * (1 + i)
                }
            }
            throw "Finished up all reserved function pointers. Use a higher value for RESERVED_FUNCTION_POINTERS."
        }),
        removeFunction: (function(index) {
            Runtime.functionPointers[(index - 2) / 2] = null
        }),
        warnOnce: (function(text) {
            if (!Runtime.warnOnce.shown) Runtime.warnOnce.shown = {};
            if (!Runtime.warnOnce.shown[text]) {
                Runtime.warnOnce.shown[text] = 1;
                Module.printErr(text)
            }
        }),
        funcWrappers: {},
        getFuncWrapper: (function(func, sig) {
            assert(sig);
            if (!Runtime.funcWrappers[sig]) {
                Runtime.funcWrappers[sig] = {}
            }
            var sigCache = Runtime.funcWrappers[sig];
            if (!sigCache[func]) {
                if (sig.length === 1) {
                    sigCache[func] = function dynCall_wrapper() {
                        return Runtime.dynCall(sig, func)
                    }
                } else if (sig.length === 2) {
                    sigCache[func] = function dynCall_wrapper(arg) {
                        return Runtime.dynCall(sig, func, [arg])
                    }
                } else {
                    sigCache[func] = function dynCall_wrapper() {
                        return Runtime.dynCall(sig, func, Array.prototype.slice.call(arguments))
                    }
                }
            }
            return sigCache[func]
        }),
        getCompilerSetting: (function(name) {
            throw "You must build with -s RETAIN_COMPILER_SETTINGS=1 for Runtime.getCompilerSetting or emscripten_get_compiler_setting to work"
        }),
        stackAlloc: (function(size) {
            var ret = STACKTOP;
            STACKTOP = STACKTOP + size | 0;
            STACKTOP = STACKTOP + 15 & -16;
            return ret
        }),
        staticAlloc: (function(size) {
            var ret = STATICTOP;
            STATICTOP = STATICTOP + size | 0;
            STATICTOP = STATICTOP + 15 & -16;
            return ret
        }),
        dynamicAlloc: (function(size) {
            var ret = HEAP32[DYNAMICTOP_PTR >> 2];
            var end = (ret + size + 15 | 0) & -16;
            HEAP32[DYNAMICTOP_PTR >> 2] = end;
            if (end >= TOTAL_MEMORY) {
                var success = enlargeMemory();
                if (!success) {
                    HEAP32[DYNAMICTOP_PTR >> 2] = ret;
                    return 0
                }
            }
            return ret
        }),
        alignMemory: (function(size, quantum) {
            var ret = size = Math.ceil(size / (quantum ? quantum : 16)) * (quantum ? quantum : 16);
            return ret
        }),
        makeBigInt: (function(low, high, unsigned) {
            var ret = unsigned ? +(low >>> 0) + +(high >>> 0) * +4294967296 : +(low >>> 0) + +(high | 0) * +4294967296;
            return ret
        }),
        GLOBAL_BASE: 1024,
        QUANTUM_SIZE: 4,
        _27cc11c4: 0
    };
    Module["Runtime"] = Runtime;
    Runtime["addFunction"] = Runtime.addFunction;
    Runtime["removeFunction"] = Runtime.removeFunction;
    var ABORT = 0;
    var EXITSTATUS = 0;

    function assert(condition, text) {
        if (!condition) {
            abort("Assertion failed: " + text)
        }
    }

    function getCFunc(ident) {
        var func = Module["_" + ident];
        if (!func) {
            try {
                func = eval("_" + ident)
            } catch (e) {}
        }
        assert(func, "Cannot call unknown function " + ident + " (perhaps LLVM optimizations or closure removed it?)");
        return func
    }
    var cwrap, ccall;
    ((function() {
        var JSfuncs = {
            "stackSave": (function() {
                Runtime.stackSave()
            }),
            "stackRestore": (function() {
                Runtime.stackRestore()
            }),
            "arrayToC": (function(arr) {
                var ret = Runtime.stackAlloc(arr.length);
                writeArrayToMemory(arr, ret);
                return ret
            }),
            "stringToC": (function(str) {
                var ret = 0;
                if (str !== null && str !== undefined && str !== 0) {
                    var len = (str.length << 2) + 1;
                    ret = Runtime.stackAlloc(len);
                    stringToUTF8(str, ret, len)
                }
                return ret
            })
        };
        var toC = {
            "string": JSfuncs["stringToC"],
            "array": JSfuncs["arrayToC"]
        };
        ccall = function ccallFunc(ident, returnType, argTypes, args, opts) {
            var func = getCFunc(ident);
            var cArgs = [];
            var stack = 0;
            if (args) {
                for (var i = 0; i < args.length; i++) {
                    var converter = toC[argTypes[i]];
                    if (converter) {
                        if (stack === 0) stack = Runtime.stackSave();
                        cArgs[i] = converter(args[i])
                    } else {
                        cArgs[i] = args[i]
                    }
                }
            }
            var ret = func.apply(null, cArgs);
            if (returnType === "string") ret = Pointer_stringify(ret);
            if (stack !== 0) {
                if (opts && opts.async) {
                    EmterpreterAsync.asyncFinalizers.push((function() {
                        Runtime.stackRestore(stack)
                    }));
                    return
                }
                Runtime.stackRestore(stack)
            }
            return ret
        };
        var sourceRegex = /^function\s*[a-zA-Z$_0-9]*\s*\(([^)]*)\)\s*{\s*([^*]*?)[\s;]*(?:return\s*(.*?)[;\s]*)?}$/;

        function parseJSFunc(jsfunc) {
            var parsed = jsfunc.toString().match(sourceRegex).slice(1);
            return {
                arguments: parsed[0],
                body: parsed[1],
                returnValue: parsed[2]
            }
        }
        var JSsource = null;

        function ensureJSsource() {
            if (!JSsource) {
                JSsource = {};
                for (var fun in JSfuncs) {
                    if (JSfuncs.hasOwnProperty(fun)) {
                        JSsource[fun] = parseJSFunc(JSfuncs[fun])
                    }
                }
            }
        }
        cwrap = function cwrap(ident, returnType, argTypes) {
            argTypes = argTypes || [];
            var cfunc = getCFunc(ident);
            var numericArgs = argTypes.every((function(type) {
                return type === "number"
            }));
            var numericRet = returnType !== "string";
            if (numericRet && numericArgs) {
                return cfunc
            }
            var argNames = argTypes.map((function(x, i) {
                return "$" + i
            }));
            var funcstr = "(function(" + argNames.join(" ,") + ") {";
            var nargs = argTypes.length;
            if (!numericArgs) {
                ensureJSsource();
                funcstr += "var stack = " + JSsource["stackSave"].body + ";";
                for (var i = 0; i < nargs; i++) {
                    var arg = argNames[i],
                        type = argTypes[i];
                    if (type === "number") continue;
                    var convertCode = JSsource[type + "ToC"];
                    funcstr += "var " + convertCode.arguments + " = " + arg + ";";
                    funcstr += convertCode.body + ";";
                    funcstr += arg + "=(" + convertCode.returnValue + ");"
                }
            }
            var cfuncname = parseJSFunc((function() {
                return cfunc
            })).returnValue;
            funcstr += "var ret = " + cfuncname + "(" + argNames.join(", ") + ");";
            if (!numericRet) {
                var strgfy = parseJSFunc((function() {
                    return Pointer_stringify
                })).returnValue;
                funcstr += "ret = " + strgfy + "(ret);"
            }
            if (!numericArgs) {
                ensureJSsource();
                funcstr += JSsource["stackRestore"].body.replace("()", "(stack)") + ";"
            }
            funcstr += "return ret})";
            return eval(funcstr)
        }
    }))();
    Module["ccall"] = ccall;
    Module["cwrap"] = cwrap;

    function setValue(ptr, value, type, noSafe) {
        type = type || "i8";
        if (type.charAt(type.length - 1) === "*") type = "i32";
        switch (type) {
            case "i1":
                HEAP8[ptr >> 0] = value;
                break;
            case "i8":
                HEAP8[ptr >> 0] = value;
                break;
            case "i16":
                HEAP16[ptr >> 1] = value;
                break;
            case "i32":
                HEAP32[ptr >> 2] = value;
                break;
            case "i64":
                tempI64 = [value >>> 0, (tempDouble = value, +Math_abs(tempDouble) >= +1 ? tempDouble > +0 ? (Math_min(+Math_floor(tempDouble / +4294967296), +4294967295) | 0) >>> 0 : ~~+Math_ceil((tempDouble - +(~~tempDouble >>> 0)) / +4294967296) >>> 0 : 0)], HEAP32[ptr >> 2] = tempI64[0], HEAP32[ptr + 4 >> 2] = tempI64[1];
                break;
            case "float":
                HEAPF32[ptr >> 2] = value;
                break;
            case "double":
                HEAPF64[ptr >> 3] = value;
                break;
            default:
                abort("invalid type for setValue: " + type)
        }
    }
    Module["setValue"] = setValue;

    function getValue(ptr, type, noSafe) {
        type = type || "i8";
        if (type.charAt(type.length - 1) === "*") type = "i32";
        switch (type) {
            case "i1":
                return HEAP8[ptr >> 0];
            case "i8":
                return HEAP8[ptr >> 0];
            case "i16":
                return HEAP16[ptr >> 1];
            case "i32":
                return HEAP32[ptr >> 2];
            case "i64":
                return HEAP32[ptr >> 2];
            case "float":
                return HEAPF32[ptr >> 2];
            case "double":
                return HEAPF64[ptr >> 3];
            default:
                abort("invalid type for setValue: " + type)
        }
        return null
    }
    Module["getValue"] = getValue;
    var ALLOC_NORMAL = 0;
    var ALLOC_STACK = 1;
    var ALLOC_STATIC = 2;
    var ALLOC_DYNAMIC = 3;
    var ALLOC_NONE = 4;
    Module["ALLOC_NORMAL"] = ALLOC_NORMAL;
    Module["ALLOC_STACK"] = ALLOC_STACK;
    Module["ALLOC_STATIC"] = ALLOC_STATIC;
    Module["ALLOC_DYNAMIC"] = ALLOC_DYNAMIC;
    Module["ALLOC_NONE"] = ALLOC_NONE;

    function allocate(slab, types, allocator, ptr) {
        var zeroinit, size;
        if (typeof slab === "number") {
            zeroinit = true;
            size = slab
        } else {
            zeroinit = false;
            size = slab.length
        }
        var singleType = typeof types === "string" ? types : null;
        var ret;
        if (allocator == ALLOC_NONE) {
            ret = ptr
        } else {
            ret = [typeof _4528ffe0 === "function" ? _4528ffe0 : Runtime.staticAlloc, Runtime.stackAlloc, Runtime.staticAlloc, Runtime.dynamicAlloc][allocator === undefined ? ALLOC_STATIC : allocator](Math.max(size, singleType ? 1 : types.length))
        }
        if (zeroinit) {
            var ptr = ret,
                stop;
            assert((ret & 3) == 0);
            stop = ret + (size & ~3);
            for (; ptr < stop; ptr += 4) {
                HEAP32[ptr >> 2] = 0
            }
            stop = ret + size;
            while (ptr < stop) {
                HEAP8[ptr++ >> 0] = 0
            }
            return ret
        }
        if (singleType === "i8") {
            if (slab.subarray || slab.slice) {
                HEAPU8.set(slab, ret)
            } else {
                HEAPU8.set(new Uint8Array(slab), ret)
            }
            return ret
        }
        var i = 0,
            type, typeSize, previousType;
        while (i < size) {
            var curr = slab[i];
            if (typeof curr === "function") {
                curr = Runtime.getFunctionIndex(curr)
            }
            type = singleType || types[i];
            if (type === 0) {
                i++;
                continue
            }
            if (type == "i64") type = "i32";
            setValue(ret + i, curr, type);
            if (previousType !== type) {
                typeSize = Runtime.getNativeTypeSize(type);
                previousType = type
            }
            i += typeSize
        }
        return ret
    }
    Module["allocate"] = allocate;

    function getMemory(size) {
        if (!staticSealed) return Runtime.staticAlloc(size);
        if (!runtimeInitialized) return Runtime.dynamicAlloc(size);
        return _4528ffe0(size)
    }
    Module["getMemory"] = getMemory;

    function Pointer_stringify(ptr, length) {
        if (length === 0 || !ptr) return "";
        var hasUtf = 0;
        var t;
        var i = 0;
        while (1) {
            t = HEAPU8[ptr + i >> 0];
            hasUtf |= t;
            if (t == 0 && !length) break;
            i++;
            if (length && i == length) break
        }
        if (!length) length = i;
        var ret = "";
        if (hasUtf < 128) {
            var MAX_CHUNK = 1024;
            var curr;
            while (length > 0) {
                curr = String.fromCharCode.apply(String, HEAPU8.subarray(ptr, ptr + Math.min(length, MAX_CHUNK)));
                ret = ret ? ret + curr : curr;
                ptr += MAX_CHUNK;
                length -= MAX_CHUNK
            }
            return ret
        }
        return Module["UTF8ToString"](ptr)
    }
    Module["Pointer_stringify"] = Pointer_stringify;

    function AsciiToString(ptr) {
        var str = "";
        while (1) {
            var ch = HEAP8[ptr++ >> 0];
            if (!ch) return str;
            str += String.fromCharCode(ch)
        }
    }
    Module["AsciiToString"] = AsciiToString;

    function stringToAscii(str, outPtr) {
        return writeAsciiToMemory(str, outPtr, false)
    }
    Module["stringToAscii"] = stringToAscii;
    var UTF8Decoder = typeof TextDecoder !== "undefined" ? new TextDecoder("utf8") : undefined;

    function UTF8ArrayToString(u8Array, idx) {
        var endPtr = idx;
        while (u8Array[endPtr]) ++endPtr;
        if (endPtr - idx > 16 && u8Array.subarray && UTF8Decoder) {
            return UTF8Decoder.decode(u8Array.subarray(idx, endPtr))
        } else {
            var u0, u1, u2, u3, u4, u5;
            var str = "";
            while (1) {
                u0 = u8Array[idx++];
                if (!u0) return str;
                if (!(u0 & 128)) {
                    str += String.fromCharCode(u0);
                    continue
                }
                u1 = u8Array[idx++] & 63;
                if ((u0 & 224) == 192) {
                    str += String.fromCharCode((u0 & 31) << 6 | u1);
                    continue
                }
                u2 = u8Array[idx++] & 63;
                if ((u0 & 240) == 224) {
                    u0 = (u0 & 15) << 12 | u1 << 6 | u2
                } else {
                    u3 = u8Array[idx++] & 63;
                    if ((u0 & 248) == 240) {
                        u0 = (u0 & 7) << 18 | u1 << 12 | u2 << 6 | u3
                    } else {
                        u4 = u8Array[idx++] & 63;
                        if ((u0 & 252) == 248) {
                            u0 = (u0 & 3) << 24 | u1 << 18 | u2 << 12 | u3 << 6 | u4
                        } else {
                            u5 = u8Array[idx++] & 63;
                            u0 = (u0 & 1) << 30 | u1 << 24 | u2 << 18 | u3 << 12 | u4 << 6 | u5
                        }
                    }
                }
                if (u0 < 65536) {
                    str += String.fromCharCode(u0)
                } else {
                    var ch = u0 - 65536;
                    str += String.fromCharCode(55296 | ch >> 10, 56320 | ch & 1023)
                }
            }
        }
    }
    Module["UTF8ArrayToString"] = UTF8ArrayToString;

    function UTF8ToString(ptr) {
        return UTF8ArrayToString(HEAPU8, ptr)
    }
    Module["UTF8ToString"] = UTF8ToString;

    function stringToUTF8Array(str, outU8Array, outIdx, maxBytesToWrite) {
        if (!(maxBytesToWrite > 0)) return 0;
        var startIdx = outIdx;
        var endIdx = outIdx + maxBytesToWrite - 1;
        for (var i = 0; i < str.length; ++i) {
            var u = str.charCodeAt(i);
            if (u >= 55296 && u <= 57343) u = 65536 + ((u & 1023) << 10) | str.charCodeAt(++i) & 1023;
            if (u <= 127) {
                if (outIdx >= endIdx) break;
                outU8Array[outIdx++] = u
            } else if (u <= 2047) {
                if (outIdx + 1 >= endIdx) break;
                outU8Array[outIdx++] = 192 | u >> 6;
                outU8Array[outIdx++] = 128 | u & 63
            } else if (u <= 65535) {
                if (outIdx + 2 >= endIdx) break;
                outU8Array[outIdx++] = 224 | u >> 12;
                outU8Array[outIdx++] = 128 | u >> 6 & 63;
                outU8Array[outIdx++] = 128 | u & 63
            } else if (u <= 2097151) {
                if (outIdx + 3 >= endIdx) break;
                outU8Array[outIdx++] = 240 | u >> 18;
                outU8Array[outIdx++] = 128 | u >> 12 & 63;
                outU8Array[outIdx++] = 128 | u >> 6 & 63;
                outU8Array[outIdx++] = 128 | u & 63
            } else if (u <= 67108863) {
                if (outIdx + 4 >= endIdx) break;
                outU8Array[outIdx++] = 248 | u >> 24;
                outU8Array[outIdx++] = 128 | u >> 18 & 63;
                outU8Array[outIdx++] = 128 | u >> 12 & 63;
                outU8Array[outIdx++] = 128 | u >> 6 & 63;
                outU8Array[outIdx++] = 128 | u & 63
            } else {
                if (outIdx + 5 >= endIdx) break;
                outU8Array[outIdx++] = 252 | u >> 30;
                outU8Array[outIdx++] = 128 | u >> 24 & 63;
                outU8Array[outIdx++] = 128 | u >> 18 & 63;
                outU8Array[outIdx++] = 128 | u >> 12 & 63;
                outU8Array[outIdx++] = 128 | u >> 6 & 63;
                outU8Array[outIdx++] = 128 | u & 63
            }
        }
        outU8Array[outIdx] = 0;
        return outIdx - startIdx
    }
    Module["stringToUTF8Array"] = stringToUTF8Array;

    function stringToUTF8(str, outPtr, maxBytesToWrite) {
        return stringToUTF8Array(str, HEAPU8, outPtr, maxBytesToWrite)
    }
    Module["stringToUTF8"] = stringToUTF8;

    function lengthBytesUTF8(str) {
        var len = 0;
        for (var i = 0; i < str.length; ++i) {
            var u = str.charCodeAt(i);
            if (u >= 55296 && u <= 57343) u = 65536 + ((u & 1023) << 10) | str.charCodeAt(++i) & 1023;
            if (u <= 127) {
                ++len
            } else if (u <= 2047) {
                len += 2
            } else if (u <= 65535) {
                len += 3
            } else if (u <= 2097151) {
                len += 4
            } else if (u <= 67108863) {
                len += 5
            } else {
                len += 6
            }
        }
        return len
    }
    Module["lengthBytesUTF8"] = lengthBytesUTF8;
    var UTF16Decoder = typeof TextDecoder !== "undefined" ? new TextDecoder("utf-16le") : undefined;

    function demangle(func) {
        var _6c7ad8c5 = Module["_2695c2d2"] || Module["_13150269"];
        if (_6c7ad8c5) {
            try {
                var s = func.substr(1);
                var len = lengthBytesUTF8(s) + 1;
                var buf = _4528ffe0(len);
                stringToUTF8(s, buf, len);
                var status = _4528ffe0(4);
                var ret = _6c7ad8c5(buf, 0, 0, status);
                if (getValue(status, "i32") === 0 && ret) {
                    return Pointer_stringify(ret)
                }
            } catch (e) {} finally {
                if (buf) _2a1a33e5(buf);
                if (status) _2a1a33e5(status);
                if (ret) _2a1a33e5(ret)
            }
            return func
        }
        Runtime.warnOnce("warning: build with  -s DEMANGLE_SUPPORT=1  to link in libcxxabi demangling");
        return func
    }

    function demangleAll(text) {
        var regex = /_7ba3faf7[\w\d_]+/g;
        return text.replace(regex, (function(x) {
            var y = demangle(x);
            return x === y ? x : x + " [" + y + "]"
        }))
    }

    function jsStackTrace() {
        var err = new Error;
        if (!err.stack) {
            try {
                throw new Error(0)
            } catch (e) {
                err = e
            }
            if (!err.stack) {
                return "(no stack trace available)"
            }
        }
        return err.stack.toString()
    }

    function stackTrace() {
        var js = jsStackTrace();
        if (Module["extraStackTrace"]) js += "\n" + Module["extraStackTrace"]();
        return demangleAll(js)
    }
    Module["stackTrace"] = stackTrace;
    var WASM_PAGE_SIZE = 65536;
    var ASMJS_PAGE_SIZE = 16777216;

    function alignUp(x, multiple) {
        if (x % multiple > 0) {
            x += multiple - x % multiple
        }
        return x
    }
    var HEAP;
    var buffer;
    var HEAP8, HEAPU8, HEAP16, HEAPU16, HEAP32, HEAPU32, HEAPF32, HEAPF64;

    function updateGlobalBuffer(buf) {
        Module["buffer"] = buffer = buf
    }

    function updateGlobalBufferViews() {
        Module["HEAP8"] = HEAP8 = new Int8Array(buffer);
        Module["HEAP16"] = HEAP16 = new Int16Array(buffer);
        Module["HEAP32"] = HEAP32 = new Int32Array(buffer);
        Module["HEAPU8"] = HEAPU8 = new Uint8Array(buffer);
        Module["HEAPU16"] = HEAPU16 = new Uint16Array(buffer);
        Module["HEAPU32"] = HEAPU32 = new Uint32Array(buffer);
        Module["HEAPF32"] = HEAPF32 = new Float32Array(buffer);
        Module["HEAPF64"] = HEAPF64 = new Float64Array(buffer)
    }
    var STATIC_BASE, STATICTOP, staticSealed;
    var STACK_BASE, STACKTOP, STACK_MAX;
    var DYNAMIC_BASE, DYNAMICTOP_PTR;
    STATIC_BASE = STATICTOP = STACK_BASE = STACKTOP = STACK_MAX = DYNAMIC_BASE = DYNAMICTOP_PTR = 0;
    staticSealed = false;

    function abortOnCannotGrowMemory() {
        abort("Cannot enlarge memory arrays. Either (1) compile with  -s TOTAL_MEMORY=X  with X higher than the current value " + TOTAL_MEMORY + " , (2) compile with  -s ALLOW_MEMORY_GROWTH=1  which adjusts the size at runtime but prevents some optimizations, (3) set Module.TOTAL_MEMORY to a higher value before the program runs, or if you want malloc to return  NULL (0) instead of this abort , compile with  -s ABORTING_MALLOC=0 ")
    }

    function enlargeMemory() {
        abortOnCannotGrowMemory()
    }
    var TOTAL_STACK = Module["TOTAL_STACK"] || 5242880;
    var TOTAL_MEMORY = Module["TOTAL_MEMORY"] || 67108864;
    if (TOTAL_MEMORY < TOTAL_STACK) Module.printErr("TOTAL_MEMORY should be larger than TOTAL_STACK, was " + TOTAL_MEMORY + "! (TOTAL_STACK=" + TOTAL_STACK + ")");
    if (Module["buffer"]) {
        buffer = Module["buffer"]
    } else {
        if (typeof WebAssembly === "object" && typeof WebAssembly.Memory === "function") {
            Module["wasmMemory"] = new WebAssembly.Memory({
                "initial": TOTAL_MEMORY / WASM_PAGE_SIZE,
                "maximum": TOTAL_MEMORY / WASM_PAGE_SIZE
            });
            buffer = Module["wasmMemory"].buffer
        } else {
            buffer = new ArrayBuffer(TOTAL_MEMORY)
        }
    }
    updateGlobalBufferViews();

    function getTotalMemory() {
        return TOTAL_MEMORY
    }
    HEAP32[0] = 1668509029;
    HEAP16[1] = 25459;
    if (HEAPU8[2] !== 115 || HEAPU8[3] !== 99) throw "Runtime error: expected the system to be little-endian!";
    Module["HEAP"] = HEAP;
    Module["buffer"] = buffer;
    Module["HEAP8"] = HEAP8;
    Module["HEAP16"] = HEAP16;
    Module["HEAP32"] = HEAP32;
    Module["HEAPU8"] = HEAPU8;
    Module["HEAPU16"] = HEAPU16;
    Module["HEAPU32"] = HEAPU32;
    Module["HEAPF32"] = HEAPF32;
    Module["HEAPF64"] = HEAPF64;

    function callRuntimeCallbacks(callbacks) {
        while (callbacks.length > 0) {
            var callback = callbacks.shift();
            if (typeof callback == "function") {
                callback();
                continue
            }
            var func = callback.func;
            if (typeof func === "number") {
                if (callback.arg === undefined) {
                    Module["dynCall_v"](func)
                } else {
                    Module["dynCall_vi"](func, callback.arg)
                }
            } else {
                func(callback.arg === undefined ? null : callback.arg)
            }
        }
    }
    var _5a80a8df = [];
    var _283ac109 = [];
    var _610953bf = [];
    var _32ef363b = [];
    var _57641d71 = [];
    var runtimeInitialized = false;
    var runtimeExited = false;

    function preRun() {
        if (Module["preRun"]) {
            if (typeof Module["preRun"] == "function") Module["preRun"] = [Module["preRun"]];
            while (Module["preRun"].length) {
                addOnPreRun(Module["preRun"].shift())
            }
        }
        callRuntimeCallbacks(_5a80a8df)
    }

    function ensureInitRuntime() {
        if (runtimeInitialized) return;
        runtimeInitialized = true;
        callRuntimeCallbacks(_283ac109)
    }

    function preMain() {
        callRuntimeCallbacks(_610953bf)
    }

    function exitRuntime() {
        callRuntimeCallbacks(_32ef363b);
        runtimeExited = true
    }

    function postRun() {
        if (Module["postRun"]) {
            if (typeof Module["postRun"] == "function") Module["postRun"] = [Module["postRun"]];
            while (Module["postRun"].length) {
                addOnPostRun(Module["postRun"].shift())
            }
        }
        callRuntimeCallbacks(_57641d71)
    }

    function addOnPreRun(cb) {
        _5a80a8df.unshift(cb)
    }
    Module["addOnPreRun"] = addOnPreRun;

    function addOnInit(cb) {
        _283ac109.unshift(cb)
    }
    Module["addOnInit"] = addOnInit;

    function addOnPreMain(cb) {
        _610953bf.unshift(cb)
    }
    Module["addOnPreMain"] = addOnPreMain;

    function addOnExit(cb) {
        _32ef363b.unshift(cb)
    }
    Module["addOnExit"] = addOnExit;

    function addOnPostRun(cb) {
        _57641d71.unshift(cb)
    }
    Module["addOnPostRun"] = addOnPostRun;

    function intArrayFromString(stringy, dontAddNull, length) {
        var len = length > 0 ? length : lengthBytesUTF8(stringy) + 1;
        var u8array = new Array(len);
        var numBytesWritten = stringToUTF8Array(stringy, u8array, 0, u8array.length);
        if (dontAddNull) u8array.length = numBytesWritten;
        return u8array
    }
    Module["intArrayFromString"] = intArrayFromString;

    function intArrayToString(array) {
        var ret = [];
        for (var i = 0; i < array.length; i++) {
            var chr = array[i];
            if (chr > 255) {
                chr &= 255
            }
            ret.push(String.fromCharCode(chr))
        }
        return ret.join("")
    }
    Module["intArrayToString"] = intArrayToString;

    function writeStringToMemory(string, buffer, dontAddNull) {
        Runtime.warnOnce("writeStringToMemory is deprecated and should not be called! Use stringToUTF8() instead!");
        var lastChar, end;
        if (dontAddNull) {
            end = buffer + lengthBytesUTF8(string);
            lastChar = HEAP8[end]
        }
        stringToUTF8(string, buffer, Infinity);
        if (dontAddNull) HEAP8[end] = lastChar
    }
    Module["writeStringToMemory"] = writeStringToMemory;

    function writeArrayToMemory(array, buffer) {
        HEAP8.set(array, buffer)
    }
    Module["writeArrayToMemory"] = writeArrayToMemory;

    function writeAsciiToMemory(str, buffer, dontAddNull) {
        for (var i = 0; i < str.length; ++i) {
            HEAP8[buffer++ >> 0] = str.charCodeAt(i)
        }
        if (!dontAddNull) HEAP8[buffer >> 0] = 0
    }
    Module["writeAsciiToMemory"] = writeAsciiToMemory;
    if (!Math["imul"] || Math["imul"](4294967295, 5) !== -5) Math["imul"] = function imul(a, b) {
        var ah = a >>> 16;
        var al = a & 65535;
        var bh = b >>> 16;
        var bl = b & 65535;
        return al * bl + (ah * bl + al * bh << 16) | 0
    };
    Math.imul = Math["imul"];
    if (!Math["fround"]) {
        var froundBuffer = new Float32Array(1);
        Math["fround"] = (function(x) {
            froundBuffer[0] = x;
            return froundBuffer[0]
        })
    }
    Math.fround = Math["fround"];
    if (!Math["clz32"]) Math["clz32"] = (function(x) {
        x = x >>> 0;
        for (var i = 0; i < 32; i++) {
            if (x & 1 << 31 - i) return i
        }
        return 32
    });
    Math.clz32 = Math["clz32"];
    if (!Math["trunc"]) Math["trunc"] = (function(x) {
        return x < 0 ? Math.ceil(x) : Math.floor(x)
    });
    Math.trunc = Math["trunc"];
    var Math_abs = Math.abs;
    var Math_cos = Math.cos;
    var Math_sin = Math.sin;
    var Math_tan = Math.tan;
    var Math_acos = Math.acos;
    var Math_asin = Math.asin;
    var Math_atan = Math.atan;
    var Math_atan2 = Math.atan2;
    var Math_exp = Math.exp;
    var Math_log = Math.log;
    var Math_sqrt = Math.sqrt;
    var Math_ceil = Math.ceil;
    var Math_floor = Math.floor;
    var Math_pow = Math.pow;
    var Math_imul = Math.imul;
    var Math_fround = Math.fround;
    var Math_round = Math.round;
    var Math_min = Math.min;
    var Math_clz32 = Math.clz32;
    var Math_trunc = Math.trunc;
    var runDependencies = 0;
    var runDependencyWatcher = null;
    var dependenciesFulfilled = null;

    function getUniqueRunDependency(id) {
        return id
    }

    function addRunDependency(id) {
        runDependencies++;
        if (Module["monitorRunDependencies"]) {
            Module["monitorRunDependencies"](runDependencies)
        }
    }
    Module["addRunDependency"] = addRunDependency;

    function removeRunDependency(id) {
        runDependencies--;
        if (Module["monitorRunDependencies"]) {
            Module["monitorRunDependencies"](runDependencies)
        }
        if (runDependencies == 0) {
            if (runDependencyWatcher !== null) {
                clearInterval(runDependencyWatcher);
                runDependencyWatcher = null
            }
            if (dependenciesFulfilled) {
                var callback = dependenciesFulfilled;
                dependenciesFulfilled = null;
                callback()
            }
        }
    }
    Module["removeRunDependency"] = removeRunDependency;
    Module["preloadedImages"] = {};
    Module["preloadedAudios"] = {};
    var memoryInitializer = null;

    function integrateWasmJS(Module) {
        var method = Module["wasmJSMethod"] || "native-wasm";
        Module["wasmJSMethod"] = method;
        var wasmTextFile = Module["wasmTextFile"] || "build_9b9e4489cd499ded99cca19f4784fc929d21fc35.wasm.wast";
        var wasmBinaryFile = Module["wasmBinaryFile"] || "build_9b9e4489cd499ded99cca19f4784fc929d21fc35.wasm.wasm";
        var asmjsCodeFile = Module["asmjsCodeFile"] || "build_9b9e4489cd499ded99cca19f4784fc929d21fc35.wasm.temp.asm.js";
        var wasmPageSize = 64 * 1024;
        var asm2wasmImports = {
            "f64-rem": (function(x, y) {
                return x % y
            }),
            "f64-to-int": (function(x) {
                return x | 0
            }),
            "i32s-div": (function(x, y) {
                return (x | 0) / (y | 0) | 0
            }),
            "i32u-div": (function(x, y) {
                return (x >>> 0) / (y >>> 0) >>> 0
            }),
            "i32s-rem": (function(x, y) {
                return (x | 0) % (y | 0) | 0
            }),
            "i32u-rem": (function(x, y) {
                return (x >>> 0) % (y >>> 0) >>> 0
            }),
            "debugger": (function() {
                debugger
            })
        };
        var info = {
            "global": null,
            "env": null,
            "asm2wasm": asm2wasmImports,
            "parent": Module
        };
        var exports = null;

        function lookupImport(mod, base) {
            var lookup = info;
            if (mod.indexOf(".") < 0) {
                lookup = (lookup || {})[mod]
            } else {
                var parts = mod.split(".");
                lookup = (lookup || {})[parts[0]];
                lookup = (lookup || {})[parts[1]]
            }
            if (base) {
                lookup = (lookup || {})[base]
            }
            if (lookup === undefined) {
                abort("bad lookupImport to (" + mod + ")." + base)
            }
            return lookup
        }

        function mergeMemory(newBuffer) {
            var oldBuffer = Module["buffer"];
            if (newBuffer.byteLength < oldBuffer.byteLength) {
                Module["printErr"]("the new buffer in mergeMemory is smaller than the previous one. in native wasm,  we should grow memory here")
            }
            var oldView = new Int8Array(oldBuffer);
            var newView = new Int8Array(newBuffer);
            if (!memoryInitializer) {
                oldView.set(newView.subarray(Module["STATIC_BASE"], Module["STATIC_BASE"] + Module["STATIC_BUMP"]), Module["STATIC_BASE"])
            }
            newView.set(oldView);
            updateGlobalBuffer(newBuffer);
            updateGlobalBufferViews()
        }
        var WasmTypes = {
            none: 0,
            i32: 1,
            i64: 2,
            f32: 3,
            f64: 4
        };

        function fixImports(imports) {
            if (!0) return imports;
            var ret = {};
            for (var i in imports) {
                var fixed = i;
                if (fixed[0] == "_") fixed = fixed.substr(1);
                ret[fixed] = imports[i]
            }
            return ret
        }

        function getBinary() {
            var binary;
            if (Module["wasmBinary"]) {
                binary = Module["wasmBinary"];
                binary = new Uint8Array(binary)
            } else if (Module["readBinary"]) {
                binary = Module["readBinary"](wasmBinaryFile)
            } else {
                throw "on the web, we need the wasm binary to be preloaded and set on Module['wasmBinary']. emcc.py will do that for you when generating HTML (but not JS)"
            }
            return binary
        }

        function getBinaryPromise() {
            if (!Module["wasmBinary"] && typeof fetch === "function") {
                return fetch(wasmBinaryFile).then((function(response) {
                    return response.arrayBuffer()
                }))
            }
            return new Promise((function(resolve, reject) {
                resolve(getBinary())
            }))
        }

        function doJustAsm(global, env, providedBuffer) {
            if (typeof Module["asm"] !== "function" || Module["asm"] === methodHandler) {
                if (!Module["asmPreload"]) {
                    eval(Module["read"](asmjsCodeFile))
                } else {
                    Module["asm"] = Module["asmPreload"]
                }
            }
            if (typeof Module["asm"] !== "function") {
                Module["printErr"]("asm evalling did not set the module properly");
                return false
            }
            return Module["asm"](global, env, providedBuffer)
        }

        function doNativeWasm(global, env, providedBuffer) {
            if (typeof WebAssembly !== "object") {
                Module["printErr"]("no native wasm support detected");
                return false
            }
            if (!(Module["wasmMemory"] instanceof WebAssembly.Memory)) {
                Module["printErr"]("no native wasm Memory in use");
                return false
            }
            env["memory"] = Module["wasmMemory"];
            info["global"] = {
                "NaN": NaN,
                "Infinity": Infinity
            };
            info["global.Math"] = global.Math;
            info["env"] = env;

            function receiveInstance(instance) {
                exports = instance.exports;
                if (exports.memory) mergeMemory(exports.memory);
                Module["asm"] = exports;
                Module["usingWasm"] = true;
                removeRunDependency("wasm-instantiate")
            }
            addRunDependency("wasm-instantiate");
            if (Module["instantiateWasm"]) {
                try {
                    return Module["instantiateWasm"](info, receiveInstance)
                } catch (e) {
                    Module["printErr"]("Module.instantiateWasm callback failed with error: " + e);
                    return false
                }
            }
            Module["printErr"]("asynchronously preparing wasm");
            getBinaryPromise().then((function(binary) {
                return WebAssembly.instantiate(binary, info)
            })).then((function(output) {
                receiveInstance(output.instance)
            })).catch((function(reason) {
                Module["printErr"]("failed to asynchronously prepare wasm: " + reason);
                Module["quit"](1, reason)
            }));
            return {}
        }

        function doWasmPolyfill(global, env, providedBuffer, method) {
            if (typeof WasmJS !== "function") {
                Module["printErr"]("WasmJS not detected - polyfill not bundled?");
                return false
            }
            var wasmJS = WasmJS({});
            wasmJS["outside"] = Module;
            wasmJS["info"] = info;
            wasmJS["lookupImport"] = lookupImport;
            assert(providedBuffer === Module["buffer"]);
            info.global = global;
            info.env = env;
            assert(providedBuffer === Module["buffer"]);
            env["memory"] = providedBuffer;
            assert(env["memory"] instanceof ArrayBuffer);
            wasmJS["providedTotalMemory"] = Module["buffer"].byteLength;
            var code;
            if (method === "interpret-binary") {
                code = getBinary()
            } else {
                code = Module["read"](method == "interpret-asm2wasm" ? asmjsCodeFile : wasmTextFile)
            }
            var temp;
            if (method == "interpret-asm2wasm") {
                temp = wasmJS["_4528ffe0"](code.length + 1);
                wasmJS["writeAsciiToMemory"](code, temp);
                wasmJS["_72fb41f0"](temp)
            } else if (method === "interpret-s-expr") {
                temp = wasmJS["_4528ffe0"](code.length + 1);
                wasmJS["writeAsciiToMemory"](code, temp);
                wasmJS["_21e4e440"](temp)
            } else if (method === "interpret-binary") {
                temp = wasmJS["_4528ffe0"](code.length);
                wasmJS["HEAPU8"].set(code, temp);
                wasmJS["_2ad14372"](temp, code.length)
            } else {
                throw "what? " + method
            }
            wasmJS["_2a1a33e5"](temp);
            wasmJS["_1521024f"](temp);
            if (Module["newBuffer"]) {
                mergeMemory(Module["newBuffer"]);
                Module["newBuffer"] = null
            }
            exports = wasmJS["asmExports"];
            return exports
        }
        Module["asmPreload"] = Module["asm"];
        Module["reallocBuffer"] = (function(size) {
            var PAGE_MULTIPLE = Module["usingWasm"] ? WASM_PAGE_SIZE : ASMJS_PAGE_SIZE;
            size = alignUp(size, PAGE_MULTIPLE);
            var old = Module["buffer"];
            var oldSize = old.byteLength;
            if (Module["usingWasm"]) {
                try {
                    var result = Module["wasmMemory"].grow((size - oldSize) / wasmPageSize);
                    if (result !== (-1 | 0)) {
                        return Module["buffer"] = Module["wasmMemory"].buffer
                    } else {
                        return null
                    }
                } catch (e) {
                    return null
                }
            } else {
                exports["_25f58873"]((size - oldSize) / wasmPageSize);
                return Module["buffer"] !== old ? Module["buffer"] : null
            }
        });
        Module["asm"] = (function(global, env, providedBuffer) {
            global = fixImports(global);
            env = fixImports(env);
            if (!env["table"]) {
                var TABLE_SIZE = Module["wasmTableSize"];
                if (TABLE_SIZE === undefined) TABLE_SIZE = 1024;
                var MAX_TABLE_SIZE = Module["wasmMaxTableSize"];
                if (typeof WebAssembly === "object" && typeof WebAssembly.Table === "function") {
                    if (MAX_TABLE_SIZE !== undefined) {
                        env["table"] = new WebAssembly.Table({
                            "initial": TABLE_SIZE,
                            "maximum": MAX_TABLE_SIZE,
                            "element": "anyfunc"
                        })
                    } else {
                        env["table"] = new WebAssembly.Table({
                            "initial": TABLE_SIZE,
                            element: "anyfunc"
                        })
                    }
                } else {
                    env["table"] = new Array(TABLE_SIZE)
                }
                Module["wasmTable"] = env["table"]
            }
            if (!env["memoryBase"]) {
                env["memoryBase"] = Module["STATIC_BASE"]
            }
            if (!env["tableBase"]) {
                env["tableBase"] = 0
            }
            var exports;
            var methods = method.split(" ,");
            for (var i = 0; i < methods.length; i++) {
                var curr = methods[i];
                Module["printErr"]("trying binaryen method: " + curr);
                if (curr === "native-wasm") {
                    if (exports = doNativeWasm(global, env, providedBuffer)) break
                } else if (curr === "asmjs") {
                    if (exports = doJustAsm(global, env, providedBuffer)) break
                } else if (curr === "interpret-asm2wasm" || curr === "interpret-s-expr" || curr === "interpret-binary") {
                    if (exports = doWasmPolyfill(global, env, providedBuffer, curr)) break
                } else {
                    throw "bad method: " + curr
                }
            }
            if (!exports) throw "no binaryen method succeeded. consider enabling more options , like interpreting , if you want that: https://github.com/kripken/emscripten/wiki/WebAssembly#binaryen-methods";
            Module["printErr"]("binaryen method succeeded.");
            return exports
        });
        var methodHandler = Module["asm"]
    }
    integrateWasmJS(Module);
    var ASM_CONSTS = [(function($0) {
        {
            return !!window[UTF8ToString($0)]
        }
    }), (function() {
        {
            return document.getElementsByName("google_osd_static_frame").length > 0
        }
    }), (function($0) {
        {
            delete window["acu" + $0]
        }
    }), (function($0, $1, $2) {
        {
            var hasLoaded = false;
            var f = new Image;
            f.onload = (function() {
                if (!window["acu" + $2]) return;
                hasLoaded = true;
                window["acu" + $2][$1] = false
            });
            f.onerror = (function() {
                if (!window["acu" + $2]) return;
                if (!hasLoaded) window["acu" + $2][$1] = true
            });
            f.src = window.location.protocol + UTF8ToString($0)
        }
    }), (function($0, $1) {
        {
            return !window["acu" + $1] || !!window["acu" + $1][$0]
        }
    }), (function($0, $1) {
        {
            return typeof window["acu" + $1][$0] == "undefined"
        }
    }), (function($0) {
        {
            var s = document.querySelectorAll(UTF8ToString($0));
            for (var i = 0; i < s.length; ++i) {
                if (s[i].clientHeight != 0) {
                    var c = s[i];
                    while (c && c != document.body) {
                        c = c.parentNode
                    }
                    return c == document.body
                }
            }
            return false
        }
    }), (function() {
        {
            var v = window.location.href.split("?")[0];
            return allocateUTF8(v.slice(0, v.lastIndexOf("/")))
        }
    }), (function($0, $1) {
        {
            var s0 = UTF8ToString($0);
            var s1 = UTF8ToString($1);
            var iframe = document.createElement("iframe");
            iframe.id = s0;
            iframe.name = "1.0.4;" + s1.length + ";" + s1;
            iframe.src = window.location.protocol + "//tpc.googlesyndication.com/safeframe/1-0-4/html/container.html#xpc=sf-gdn-exp-1&p=http%3A//diep.io";
            iframe.style.display = "none";
            document.body.appendChild(iframe)
        }
    }), (function() {
        {
            setTimeout((function() {
                for (var i in window.localStorage) {
                    if (i.indexOf("acu$") == 0) {
                        delete window.localStorage[i]
                    }
                }
            }), 15e3)
        }
    }), (function($0) {
        {
            delete window.localStorage[UTF8ToString($0)]
        }
    }), (function($0) {
        {
            var f = document.getElementById(UTF8ToString($0));
            if (f && f.parentNode) f.parentNode.removeChild(f)
        }
    }), (function($0, $1, $2, $3) {
        {
            var a = document.getElementById(UTF8ToString($0));
            if (!a) return true;
            var key = UTF8ToString($1);
            if (!a[key]) return true;
            return a[key][UTF8ToString($2)] == UTF8ToString($3)
        }
    }), (function($0) {
        {
            var fs = document.querySelectorAll(UTF8ToString($0));
            if (fs.length == 0) return true;
            for (var i = 0; i < fs.length; ++i) {
                if (fs[i].src == "about:blank") return true
            }
            return false
        }
    }), (function($0) {
        {
            if (!window["ga"]) return;
            window["ga"]("send", "event", "HasAdblock", $0 ? "Yes" : "No", {
                nonInteraction: true
            })
        }
    }), (function($0, $1, $2) {
        {
            window.localStorage[UTF8ToString($0)] = String.fromCharCode.apply(null, HEAPU8.subarray($1, $1 + $2))
        }
    }), (function($0) {
        {
            window["acu" + $0] = []
        }
    }), (function($0, $1) {
        {
            var str = window.localStorage[UTF8ToString($0)];
            if (!str) str = "";
            var arr = _4528ffe0(str.length);
            HEAPU32[$1 >> 2] = str.length;
            for (var i = 0; i < str.length; ++i) {
                HEAPU8[arr + i] = str.charCodeAt(i)
            }
            return arr
        }
    }), (function($0) {
        {
            cp5.contexts[$0] = null
        }
    }), (function($0) {
        {
            cp5.contexts[$0].save()
        }
    }), (function($0) {
        {
            cp5.contexts[$0].restore()
        }
    }), (function($0, $1) {
        {
            cp5.contexts[$0].globalAlpha *= $1
        }
    }), (function($0, $1, $2, $3) {
        {
            cp5.contexts[$0].fillStyle = "rgb(" + $1 + ", " + $2 + " ," + $3 + ")"
        }
    }), (function($0, $1, $2, $3, $4, $5, $6) {
        {
            cp5.contexts[$0].setTransform($1, $2, $3, $4, $5, $6)
        }
    }), (function($0) {
        {
            cp5.contexts[$0].fillRect(0, 0, 1, 1)
        }
    }), (function() {
        {
            return "google_ad_client" in window && typeof window.google_ad_client == "undefined"
        }
    }), (function($0) {
        {
            return typeof window[UTF8ToString($0)] != "undefined"
        }
    }), (function($0) {
        {
            return typeof process != UTF8ToString($0)
        }
    }), (function($0) {
        {
            return allocateUTF8(UTF8ToString($0))
        }
    }), (function($0, $1, $2) {
        {
            var w = cp5.sockets[$0];
            if (w.readyState != 1) return 0;
            try {
                w.send(HEAP8.subarray($1, $1 + $2))
            } catch (e) {
                return 0
            }
            return 1
        }
    }), (function($0) {
        {
            window.alert(UTF8ToString($0))
        }
    }), (function() {
        {
            var ctx = document.createElement("canvas").getContext("2d");
            for (var i = 0; i < cp5.contexts.length; ++i) {
                if (cp5.contexts[i] != null) continue;
                cp5.contexts[i] = ctx;
                return i
            }
            cp5.contexts.push(ctx);
            return cp5.contexts.length - 1
        }
    }), (function($0, $1, $2) {
        {
            var canvas = cp5.contexts[$0].canvas;
            HEAP32[$1 >> 2] = canvas.width;
            HEAP32[$2 >> 2] = canvas.height
        }
    }), (function($0, $1, $2) {
        {
            var canvas = cp5.contexts[$0].canvas;
            canvas.width = $1;
            canvas.height = $2
        }
    }), (function($0) {
        {
            cp5.contexts[$0].setTransform(1, 0, 0, 1, 0, 0)
        }
    }), (function($0) {
        {
            var ctx = cp5.contexts[$0];
            var canvas = ctx.canvas;
            ctx.clearRect(0, 0, canvas.width, canvas.height)
        }
    }), (function($0) {
        {
            return document.getElementById(UTF8ToString($0)) != null
        }
    }), (function($0) {
        {
            return document.getElementsByClassName(UTF8ToString($0)).length > 0
        }
    }), (function() {
        {
            return allocateUTF8(document.body.innerHTML)
        }
    }), (function() {
        {
            return (function() {}).prototype.constructor.toString.apply(document.querySelector).indexOf("return ") != -1
        }
    }), (function() {
        {
            return document.body.parentElement != document.documentElement
        }
    }), (function() {
        {
            return allocateUTF8(window.navigator.userAgent)
        }
    }), (function($0, $1, $2) {
        {
            var s0 = UTF8ToString($0);
            return window[UTF8ToString($2)].prototype[s0][UTF8ToString($1)] != s0
        }
    }), (function() {
        {
            return allocateUTF8((function() {}).prototype.constructor.toString.apply(document.querySelector))
        }
    }), (function() {
        {
            return allocateUTF8((function() {}).prototype.constructor.toString.apply(CanvasRenderingContext2D.prototype.fillText))
        }
    }), (function() {
        {
            return allocateUTF8((function() {}).prototype.constructor.toString.apply(CanvasRenderingContext2D.prototype.strokeRect))
        }
    }), (function() {
        {
            return allocateUTF8((function() {}).prototype.constructor.toString.apply(CanvasRenderingContext2D.prototype.strokeText))
        }
    }), (function() {
        {
            return allocateUTF8((function() {}).prototype.constructor.toString.apply(CanvasRenderingContext2D.prototype.scale))
        }
    }), (function() {
        {
            return allocateUTF8((function() {}).prototype.constructor.toString.apply(CanvasRenderingContext2D.prototype.translate))
        }
    }), (function() {
        {
            return allocateUTF8((function() {}).prototype.constructor.toString.apply(CanvasRenderingContext2D.prototype.fillRect))
        }
    }), (function() {
        {
            return allocateUTF8((function() {}).prototype.constructor.toString.apply(CanvasRenderingContext2D.prototype.rotate))
        }
    }), (function() {
        {
            return allocateUTF8((function() {}).prototype.constructor.toString.apply(CanvasRenderingContext2D.prototype.getImageData))
        }
    }), (function($0) {
        {
            return document.querySelector(UTF8ToString($0)) != null
        }
    }), (function() {
        {
            return Function.prototype.toString != originalFunctionToString
        }
    }), (function($0) {
        {
            var r = UTF8ToString($0);
            return document.getElementById("canvas")[r] !== document.body[r]
        }
    }), (function($0) {
        {
            return document.body[UTF8ToString($0)] !== void 0
        }
    }), (function($0) {
        {
            return !!document.body[UTF8ToString($0)]
        }
    }), (function($0, $1) {
        {
            var f = UTF8ToString($0);
            var d = document.createElement("div");
            if (!d[f]) return false;
            return d[f]() == document.body[UTF8ToString($1)]
        }
    }), (function($0, $1) {
        {
            var s0 = UTF8ToString($0);
            var s1 = UTF8ToString($1);
            var t = window[s0][s1];
            window[s0][s1] = (function() {
                return "abcdef"
            });
            var res = window[s0][s1].toString().indexOf("abcdef") == -1;
            window[s0][s1] = t;
            return res
        }
    }), (function() {
        {
            return curScript != null ? allocateUTF8(curScript.innerHTML) : 0
        }
    }), (function() {
        {
            return curScript != null ? allocateUTF8(curScript.src) : 0
        }
    }), (function() {
        {
            if (!haveFontsLoaded) haveFontsLoaded = FontDetect.isFontLoaded("Ubuntu");
            return haveFontsLoaded
        }
    }), (function($0, $1) {
        {
            return cp5.contexts[$0].measureText(UTF8ToString($1)).width
        }
    }), (function() {
        {
            return !!CanvasRenderingContext2D.prototype.createPattern
        }
    }), (function($0, $1, $2, $3) {
        {
            cp5.contexts[$0].strokeStyle = "rgb(" + $1 + "," + $2 + "," + $3 + ")"
        }
    }), (function($0, $1) {
        {
            cp5.contexts[$0].lineWidth = $1
        }
    }), (function($0) {
        {
            cp5.contexts[$0].beginPath()
        }
    }), (function($0, $1, $2) {
        {
            cp5.contexts[$0].moveTo($1, $2)
        }
    }), (function($0, $1, $2) {
        {
            cp5.contexts[$0].lineTo($1, $2)
        }
    }), (function($0, $1, $2, $3, $4) {
        {
            cp5.contexts[$0].setTransform($1, $2, $3, $4, 0, 0)
        }
    }), (function($0) {
        {
            cp5.contexts[$0].stroke()
        }
    }), (function($0, $1) {
        {
            var pattern = cp5.contexts[$0].createPattern(cp5.contexts[$1].canvas, null);
            for (var i = 0; i < cp5.patterns.length; ++i) {
                if (cp5.patterns[i] == null) {
                    cp5.patterns[i] = pattern;
                    return i
                }
            }
            cp5.patterns.push(pattern);
            return cp5.patterns.length - 1
        }
    }), (function($0, $1) {
        {
            return $0 % $1
        }
    }), (function($0, $1, $2) {
        {
            var d = cp5.contexts[$0].getImageData($1, $2, 1, 1);
            return d.data[0] << 16 | d.data[1] << 8 | d.data[2]
        }
    }), (function() {
        {
            var a = document.getElementById("a");
            var aa = document.querySelectorAll(".aa");
            if (a) a.style.display = "none";
            for (var i = 0; i < aa.length; ++i) aa[i].style.display = "none";
            if (!window["googletag"]) return;
            if (!window["googletag"]["cmd"]) return;
            window["googletag"]["cmd"].push((function() {
                if (!window["googletag"]["pubads"]) return;
                if (!window["googletag"]["pubads"]().clear) return;
                window["googletag"]["pubads"]().clear()
            }))
        }
    }), (function($0, $1) {
        {
            var a = document.getElementById("a");
            var aa = document.getElementById(UTF8ToString($0));
            if (a) a.style.display = "block";
            if (aa) aa.style.display = "block";
            if (!window["googletag"]) return;
            if (!window["googletag"]["cmd"]) return;
            window["googletag"]["cmd"].push((function() {
                if (!window["googletag"]["pubads"]) return;
                if (!window["googletag"]["pubads"]()["refresh"]) return;
                window["googletag"]["pubads"]()["refresh"](window[UTF8ToString($1)])
            }))
        }
    }), (function() {
        {
            if (!localStorage["playwireAB"]) localStorage["playwireAB"] = Math.random();
            var player = document.getElementById("player");
            if (player && player.parentNode) player.parentNode.style.display = "none";
            var f = (function(playerName) {
                console.log("Bolt loaded " + playerName);
                if (playerName != "player") return;
                var Bolt = window["Bolt"];
                if (!Bolt) return;
                Bolt["on"](playerName, Bolt["BOLT_AD_STARTED"], (function() {
                    console.log("Ad started")
                }));
                Bolt["on"](playerName, Bolt["BOLT_AD_ERROR"], (function() {
                    console.log("Ad error");
                    _764d2878()
                }));
                Bolt["on"](playerName, Bolt["BOLT_AD_COMPLETE"], (function() {
                    console.log("Ad complete");
                    _764d2878()
                }))
            });
            window["onBoltLoaded"] = f
        }
    }), (function() {
        {
            var Bolt = window["Bolt"];
            if (!Bolt) return false;
            var player = document.getElementById("player");
            if (!player) return false;
            player.style.display = "block";
            if (player.parentNode) player.parentNode.style.display = "block";
            Bolt["renderPlayer"]("player");
            return true
        }
    }), (function() {
        {
            var a = document.getElementById("a");
            if (!a) return;
            a.style.display = "block"
        }
    }), (function() {
        {
            var a = document.getElementById("a");
            if (!a) return;
            a.style.display = "none"
        }
    }), (function($0) {
        {
            cp5.contexts[$0].clip()
        }
    }), (function($0) {
        {
            cp5.contexts[$0].fill()
        }
    }), (function($0) {
        {
            cp5.contexts[$0].lineJoin = "round"
        }
    }), (function() {
        {
            return window.navigator.getGamepads && window.navigator.getGamepads()[0] != null && window.navigator.getGamepads()[0]["mapping"] == "standard"
        }
    }), (function($0) {
        {
            cp5.contexts[$0].lineCap = "round"
        }
    }), (function($0) {
        {
            cp5.contexts[$0].lineCap = "butt"
        }
    }), (function($0) {
        {
            cp5.contexts[$0].lineCap = "square"
        }
    }), (function($0) {
        {
            cp5.contexts[$0].closePath()
        }
    }), (function($0, $1) {
        {
            cp5.contexts[$0].drawImage(cp5.contexts[$1].canvas, 0, 0)
        }
    }), (function($0, $1, $2, $3) {
        {
            var i = cp5.images[$0];
            HEAPU8[$1 >> 0] = i.isLoaded | 0;
            HEAP32[$2 >> 2] = i.width;
            HEAP32[$3 >> 2] = i.height
        }
    }), (function($0) {
        {
            var img = new Image;
            img.isLoaded = false;
            img.onload = (function() {
                img.isLoaded = true
            });
            img.src = UTF8ToString($0);
            for (var i = 0; i < cp5.images.length; ++i) {
                if (cp5.images[i] != null) continue;
                cp5.images[i] = img;
                return i
            }
            cp5.images.push(img);
            return cp5.images.length - 1
        }
    }), (function($0) {
        {
            window.location = UTF8ToString($0)
        }
    }), (function($0) {
        {
            copyToKeyboard(UTF8ToString($0))
        }
    }), (function($0) {
        {
            textInput.value = UTF8ToString($0)
        }
    }), (function($0, $1) {
        {
            cp5.contexts[$0].font = ($1 * 2048 | 0) / 2048 + "px Ubuntu"
        }
    }), (function($0) {
        {
            cp5.contexts[$0].textBaseline = "middle"
        }
    }), (function($0, $1) {
        {
            cp5.contexts[$0].globalAlpha = $1
        }
    }), (function($0, $1, $2, $3) {
        {
            cp5.contexts[$0].fillStyle = cp5.patterns[$1];
            cp5.contexts[$0].fillRect(0, 0, $2, $3)
        }
    }), (function($0, $1, $2, $3, $4, $5) {
        {
            cp5.contexts[$0].drawImage(cp5.contexts[$1].canvas, $2, $3, $4, $5, 0, 0, 1, 1)
        }
    }), (function($0, $1) {
        {
            var img = cp5.images[$1];
            if (!img.isLoaded) return;
            if (img.width == 0 || img.height == 0) return;
            cp5.contexts[$0].drawImage(img, 0, 0, img.width, img.height, 0, 0, 1, 1)
        }
    }), (function() {
        {
            return allocateUTF8(textInput.value)
        }
    }), (function($0, $1, $2, $3) {
        {
            cp5.contexts[$0].arc(0, 0, 1, $1, $2, $3)
        }
    }), (function($0) {
        {
            cp5.contexts[$0].rect(0, 0, 1, 1)
        }
    }), (function($0, $1) {
        {
            var canvas = cp5.contexts[$1].canvas;
            cp5.contexts[$0].drawImage(canvas, 0, 0, canvas.width, canvas.height, 0, 0, 1, 1)
        }
    }), (function($0) {
        {
            cp5.contexts[$0].strokeRect(0, 0, 1, 1)
        }
    }), (function() {
        {
            var player = document.getElementById("player");
            if (player) {
                player.innerHTML = "";
                player.style.display = "none";
                if (player.parentNode) player.parentNode.style.display = "none"
            }
        }
    }), (function() {
        {
            return window.location.protocol == "https:"
        }
    }), (function($0) {
        {
            var ws = new WebSocket(UTF8ToString($0));
            ws.binaryType = "arraybuffer";
            ws.events = [];
            ws.onopen = (function() {
                ws.events.push([2, 0, 0]);
                _6d876630()
            });
            ws.onerror = (function() {
                ws.events.push([3, 0, 0]);
                _6d876630()
            });
            ws.onclose = (function() {
                ws.events.push([4, 0, 0]);
                _6d876630()
            });
            ws.onmessage = (function(e) {
                var view = new Uint8Array(e.data);
                var ptr = _4528ffe0(view.length);
                writeArrayToMemory(view, ptr);
                ws.events.push([1, ptr, view.length]);
                _6d876630()
            });
            for (var i = 0; i < cp5.sockets.length; ++i) {
                if (cp5.sockets[i] != null) continue;
                cp5.sockets[i] = ws;
                return i
            }
            cp5.sockets.push(ws);
            return cp5.sockets.length - 1
        }
    }), (function($0) {
        {
            var w = cp5.sockets[$0];
            w.onopen = w.onclose = w.onmessage = w.onerror = (function() {});
            for (var i = 0; i < w.events.length; ++i) _2a1a33e5(w.events[i][1]);
            w.events = null;
            try {
                w.close()
            } catch (e) {}
            cp5.sockets[$0] = null
        }
    }), (function($0) {
        {
            var str = UTF8ToString($0);
            setTimeout(reload(str), 1)
        }
    }), (function() {
        {
            setTimeout((function() {
                window.location.reload(true)
            }), 100)
        }
    }), (function() {
        {
            alert("Invalid party ID")
        }
    }), (function() {
        {
            if (window.history && window.history.pushState) {
                window.history.pushState("", document.title, window.location.pathname + window.location.search)
            } else {
                window.location.hash = ""
            }
        }
    }), (function($0, $1, $2) {
        {
            var w = cp5.sockets[$0];
            if (w.events.length == 0) return 0;
            var e = w.events.shift();
            HEAPU32[$1 >> 2] = e[1];
            HEAP32[$2 >> 2] = e[2];
            return e[0]
        }
    }), (function() {
        {
            return allocateUTF8(window.location.hash)
        }
    }), (function($0) {
        {
            if (window["setLoadingStatus"]) window["setLoadingStatus"](UTF8ToString($0))
        }
    }), (function($0, $1) {
        {
            var requestID = $0;
            window["m28n"]["findServerPreference"](UTF8ToString($1), (function(err, servers) {
                if (err || servers.length == 0) {
                    _1a8dc8b8(requestID, 0, 0, 0)
                } else {
                    var server = servers[0];
                    var id = allocateUTF8(server["id"]);
                    var ipv4 = allocateUTF8(server["ipv4"]);
                    var ipv6 = allocateUTF8(server["ipv6"]);
                    _1a8dc8b8(requestID, id, ipv4, ipv6);
                    _2a1a33e5(id);
                    _2a1a33e5(ipv4);
                    _2a1a33e5(ipv6)
                }
            }))
        }
    }), (function($0, $1) {
        {
            var requestID = $0;
            window["m28n"]["findServerByID"](UTF8ToString($1), (function(err, server) {
                if (err || server == null) {
                    _1a8dc8b8(requestID, 0, 0, 0)
                } else {
                    var id = allocateUTF8(server["id"]);
                    var ipv4 = allocateUTF8(server["ipv4"]);
                    var ipv6 = allocateUTF8(server["ipv6"]);
                    _1a8dc8b8(requestID, id, ipv4, ipv6);
                    _2a1a33e5(id);
                    _2a1a33e5(ipv4);
                    _2a1a33e5(ipv6)
                }
            }))
        }
    }), (function() {
        {
            document.getElementById("canvas").style.cursor = "default"
        }
    }), (function() {
        {
            document.getElementById("canvas").style.cursor = "text"
        }
    }), (function() {
        {
            document.getElementById("canvas").style.cursor = "pointer"
        }
    }), (function($0, $1, $2, $3, $4) {
        {
            window["setTyping"](true);
            var padding = 5;
            textInputContainer.style.display = "block";
            textInputContainer.style.position = "absolute";
            textInputContainer.style.left = window["unscale"]($0) + "px";
            textInputContainer.style.top = window["unscale"]($1) + "px";
            textInput.style.width = window["unscale"]($2 * .96) + "px";
            textInput.style.height = window["unscale"]($3) + "px";
            textInput.style.lineHeight = window["unscale"]($3 * .9) + "px";
            textInput.style.fontSize = window["unscale"]($3 * .9) + "px";
            textInput.style.paddingLeft = padding + "px";
            textInput.style.paddingRight = padding + "px";
            textInput.disabled = !$4;
            textInput.focus()
        }
    }), (function() {
        {
            window["setTyping"](false);
            textInput.blur();
            textInput.value = "";
            textInputContainer.style.display = "none"
        }
    }), (function() {
        {
            var c = document.getElementById("canvas");
            if (document.activeElement && document.activeElement != c) document.activeElement.blur();
            c.focus()
        }
    }), (function($0) {
        {
            var axes = window.navigator.getGamepads()[0]["axes"];
            if ($0 >= axes.length) return 0;
            return axes[$0]
        }
    }), (function($0) {
        {
            var buttons = window.navigator.getGamepads()[0]["buttons"];
            if ($0 >= buttons.length) return false;
            return buttons[$0]["pressed"]
        }
    }), (function() {
        {
            setTimeout(reload, 1)
        }
    }), (function() {
        {
            return allocateUTF8(window.location.search)
        }
    }), (function() {
        {
            return allocateUTF8(window.document.referrer)
        }
    }), (function() {
        {
            return window.top.location != window.location
        }
    }), (function() {
        {
            window.top.location = "http://diep.io/"
        }
    }), (function() {
        {
            window.top.location = "https://play.google.com/store/apps/details?id=com.miniclip.diep.io"
        }
    }), (function() {
        {
            window.top.location = "https://itunes.apple.com/app/diep.io/id1114751883?mt=8&at=1l3vajp"
        }
    }), (function() {
        {
            return typeof window.navigator.orientation != "undefined"
        }
    }), (function() {
        {
            return window.navigator.standalone
        }
    }), (function() {
        {
            return "onorientationchange" in window
        }
    }), (function($0) {
        {
            cp5.contexts[$0].lineJoin = "miter"
        }
    }), (function($0, $1) {
        {
            cp5.contexts[$0].miterLimit = $1
        }
    }), (function($0) {
        {
            cp5.contexts[$0].textBaseline = "alphabetic"
        }
    }), (function($0, $1) {
        {
            cp5.contexts[$0].fillText(UTF8ToString($1), 0, 0)
        }
    }), (function($0, $1) {
        {
            cp5.contexts[$0].strokeText(UTF8ToString($1), 0, 0)
        }
    }), (function() {
        {
            if (!document.fullscreenElement && !document.webkitFullscreenElement && !document.mozFullscreenElement) {
                var e = document.body;
                if (!e) return;
                if (e.requestFullscreen) e.requestFullscreen();
                else if (e.webkitRequestFullscreen) e.webkitRequestFullscreen();
                else if (e.mozRequestFullScreen) e.mozRequestFullScreen()
            } else if (document.exitFullscreen) {
                document.exitFullscreen()
            } else if (document.mozCancelFullScreen) {
                document.mozCancelFullScreen()
            } else if (document.webkitExitFullscreen) {
                document.webkitExitFullscreen()
            }
        }
    }), (function($0) {
        {
            cp5.patterns[$0] = null
        }
    }), (function($0, $1) {
        {
            var elem = document.getElementById(UTF8ToString($0));
            if (elem == null) {
                debugger;
                return -1
            }
            var ctx = elem.getContext("2d", {
                "alpha": !!$1
            });
            for (var i = 0; i < cp5.contexts.length; ++i) {
                if (cp5.contexts[i] != null) continue;
                cp5.contexts[i] = ctx;
                return i
            }
            cp5.contexts.push(ctx);
            return cp5.contexts.length - 1
        }
    })];

    function _37ef5551(code, a0, a1, a2, a3) {

        return ASM_CONSTS[code](a0, a1, a2, a3)
    }

    function _6a007f73(code, a0, a1) {
        return ASM_CONSTS[code](a0, a1)
    }

    function _1b63264b(code, a0) {
        return ASM_CONSTS[code](a0)
    }

    function _73b3f4dc(code) {
        return ASM_CONSTS[code]()
    }

    function _53a98c0a(code, a0, a1, a2, a3) {
        return ASM_CONSTS[code](a0, a1, a2, a3)
    }

    function _6ba99a3a(code, a0) {
        return ASM_CONSTS[code](a0)
    }

    function _32d930c9(code, a0, a1) {
        return ASM_CONSTS[code](a0, a1)
    }

    function _4cdce971(code, a0, a1, a2) {
        return ASM_CONSTS[code](a0, a1, a2)
    }

    function _5fbc6ade(code, a0, a1, a2, a3, a4) {
        return ASM_CONSTS[code](a0, a1, a2, a3, a4)
    }

    function _1fed7088(code, a0, a1, a2) {
        return ASM_CONSTS[code](a0, a1, a2)
    }

    function _202cac45(code) {
        return ASM_CONSTS[code]()
    }

    function _6e7b7c8(code, a0, a1, a2, a3, a4, a5) {
        return ASM_CONSTS[code](a0, a1, a2, a3, a4, a5)
    }

    function _4d537a01(code, a0, a1, a2, a3, a4) {
        return ASM_CONSTS[code](a0, a1, a2, a3, a4)
    }

    function _6d9039e0(code, a0, a1, a2, a3, a4, a5, a6) {
        return ASM_CONSTS[code](a0, a1, a2, a3, a4, a5, a6)
    }

    function _92581b2(code, a0, a1) {
        return ASM_CONSTS[code](a0, a1)
    }

    function _4d41badc(code, a0, a1, a2, a3) {
        return ASM_CONSTS[code](a0, a1, a2, a3)
    }

    function _1da92d65(code, a0, a1) {
        return ASM_CONSTS[code](a0, a1)
    }
    STATIC_BASE = 1024;
    STATICTOP = STATIC_BASE + 183296;
    _283ac109.push({
        func: (function() {
            _9df57d5()
        })
    }, {
        func: (function() {
            _3ffb382d()
        })
    });
    memoryInitializer = Module["wasmJSMethod"].indexOf("asmjs") >= 0 || Module["wasmJSMethod"].indexOf("interpret-asm2wasm") >= 0 ? "build_9b9e4489cd499ded99cca19f4784fc929d21fc35.wasm.js.mem" : null;
    var STATIC_BUMP = 183296;
    Module["STATIC_BASE"] = STATIC_BASE;
    Module["STATIC_BUMP"] = STATIC_BUMP;
    var tempDoublePtr = STATICTOP;
    STATICTOP += 16;
    Module["_22910c01"] = _22910c01;

    function _11e81c19(condition, filename, line, func) {
        ABORT = true;
        throw "Assertion failed: " + Pointer_stringify(condition) + ",  at: " + [filename ? Pointer_stringify(filename) : "unknown filename", line, func ? Pointer_stringify(func) : "unknown function"] + " at " + stackTrace()
    }
    Module["_2b32e53b"] = _2b32e53b;
    Module["_63a0450c"] = _63a0450c;
    Module["_1aa2133b"] = _1aa2133b;

    function _5904ba26(year) {
        return year % 4 === 0 && (year % 100 !== 0 || year % 400 === 0)
    }

    function _2428ca3(array, index) {
        var sum = 0;
        for (var i = 0; i <= index; sum += array[i++]);
        return sum
    }
    var _4010c7dd = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
    var _ab650c6 = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];

    function _6fd429bf(date, days) {
        var newDate = new Date(date.getTime());
        while (days > 0) {
            var leap = _5904ba26(newDate.getFullYear());
            var currentMonth = newDate.getMonth();
            var daysInCurrentMonth = (leap ? _4010c7dd : _ab650c6)[currentMonth];
            if (days > daysInCurrentMonth - newDate.getDate()) {
                days -= daysInCurrentMonth - newDate.getDate() + 1;
                newDate.setDate(1);
                if (currentMonth < 11) {
                    newDate.setMonth(currentMonth + 1)
                } else {
                    newDate.setMonth(0);
                    newDate.setFullYear(newDate.getFullYear() + 1)
                }
            } else {
                newDate.setDate(newDate.getDate() + days);
                return newDate
            }
        }
        return newDate
    }

    function _80a051c(s, maxsize, format, tm) {
        var tm_zone = HEAP32[tm + 40 >> 2];
        var date = {
            tm_sec: HEAP32[tm >> 2],
            tm_min: HEAP32[tm + 4 >> 2],
            tm_hour: HEAP32[tm + 8 >> 2],
            tm_mday: HEAP32[tm + 12 >> 2],
            tm_mon: HEAP32[tm + 16 >> 2],
            tm_year: HEAP32[tm + 20 >> 2],
            tm_wday: HEAP32[tm + 24 >> 2],
            tm_yday: HEAP32[tm + 28 >> 2],
            tm_isdst: HEAP32[tm + 32 >> 2],
            tm_gmtoff: HEAP32[tm + 36 >> 2],
            tm_zone: tm_zone ? Pointer_stringify(tm_zone) : ""
        };
        var pattern = Pointer_stringify(format);
        var EXPANSION_RULES_1 = {
            "%c": "%a %b %d %H:%M:%S %Y",
            "%D": "%m/%d/%y",
            "%F": "%Y-%m-%d",
            "%h": "%b",
            "%r": "%I:%M:%S %p",
            "%R": "%H:%M",
            "%T": "%H:%M:%S",
            "%x": "%m/%d/%y",
            "%X": "%H:%M:%S"
        };
        for (var rule in EXPANSION_RULES_1) {
            pattern = pattern.replace(new RegExp(rule, "g"), EXPANSION_RULES_1[rule])
        }
        var WEEKDAYS = ["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"];
        var MONTHS = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"];

        function leadingSomething(value, digits, character) {
            var str = typeof value === "number" ? value.toString() : value || "";
            while (str.length < digits) {
                str = character[0] + str
            }
            return str
        }

        function leadingNulls(value, digits) {
            return leadingSomething(value, digits, "0")
        }

        function compareByDay(date1, date2) {
            function sgn(value) {
                return value < 0 ? -1 : value > 0 ? 1 : 0
            }
            var compare;
            if ((compare = sgn(date1.getFullYear() - date2.getFullYear())) === 0) {
                if ((compare = sgn(date1.getMonth() - date2.getMonth())) === 0) {
                    compare = sgn(date1.getDate() - date2.getDate())
                }
            }
            return compare
        }

        function getFirstWeekStartDate(janFourth) {
            switch (janFourth.getDay()) {
                case 0:
                    return new Date(janFourth.getFullYear() - 1, 11, 29);
                case 1:
                    return janFourth;
                case 2:
                    return new Date(janFourth.getFullYear(), 0, 3);
                case 3:
                    return new Date(janFourth.getFullYear(), 0, 2);
                case 4:
                    return new Date(janFourth.getFullYear(), 0, 1);
                case 5:
                    return new Date(janFourth.getFullYear() - 1, 11, 31);
                case 6:
                    return new Date(janFourth.getFullYear() - 1, 11, 30)
            }
        }

        function getWeekBasedYear(date) {
            var thisDate = _6fd429bf(new Date(date.tm_year + 1900, 0, 1), date.tm_yday);
            var janFourthThisYear = new Date(thisDate.getFullYear(), 0, 4);
            var janFourthNextYear = new Date(thisDate.getFullYear() + 1, 0, 4);
            var firstWeekStartThisYear = getFirstWeekStartDate(janFourthThisYear);
            var firstWeekStartNextYear = getFirstWeekStartDate(janFourthNextYear);
            if (compareByDay(firstWeekStartThisYear, thisDate) <= 0) {
                if (compareByDay(firstWeekStartNextYear, thisDate) <= 0) {
                    return thisDate.getFullYear() + 1
                } else {
                    return thisDate.getFullYear()
                }
            } else {
                return thisDate.getFullYear() - 1
            }
        }
        var EXPANSION_RULES_2 = {
            "%a": (function(date) {
                return WEEKDAYS[date.tm_wday].substring(0, 3)
            }),
            "%A": (function(date) {
                return WEEKDAYS[date.tm_wday]
            }),
            "%b": (function(date) {
                return MONTHS[date.tm_mon].substring(0, 3)
            }),
            "%B": (function(date) {
                return MONTHS[date.tm_mon]
            }),
            "%C": (function(date) {
                var year = date.tm_year + 1900;
                return leadingNulls(year / 100 | 0, 2)
            }),
            "%d": (function(date) {
                return leadingNulls(date.tm_mday, 2)
            }),
            "%e": (function(date) {
                return leadingSomething(date.tm_mday, 2, " ")
            }),
            "%g": (function(date) {
                return getWeekBasedYear(date).toString().substring(2)
            }),
            "%G": (function(date) {
                return getWeekBasedYear(date)
            }),
            "%H": (function(date) {
                return leadingNulls(date.tm_hour, 2)
            }),
            "%I": (function(date) {
                var twelveHour = date.tm_hour;
                if (twelveHour == 0) twelveHour = 12;
                else if (twelveHour > 12) twelveHour -= 12;
                return leadingNulls(twelveHour, 2)
            }),
            "%j": (function(date) {
                return leadingNulls(date.tm_mday + _2428ca3(_5904ba26(date.tm_year + 1900) ? _4010c7dd : _ab650c6, date.tm_mon - 1), 3)
            }),
            "%m": (function(date) {
                return leadingNulls(date.tm_mon + 1, 2)
            }),
            "%M": (function(date) {
                return leadingNulls(date.tm_min, 2)
            }),
            "%n": (function() {
                return "\n"
            }),
            "%p": (function(date) {
                if (date.tm_hour >= 0 && date.tm_hour < 12) {
                    return "AM"
                } else {
                    return "PM"
                }
            }),
            "%S": (function(date) {
                return leadingNulls(date.tm_sec, 2)
            }),
            "%t": (function() {
                return "\t"
            }),
            "%u": (function(date) {
                var day = new Date(date.tm_year + 1900, date.tm_mon + 1, date.tm_mday, 0, 0, 0, 0);
                return day.getDay() || 7
            }),
            "%U": (function(date) {
                var janFirst = new Date(date.tm_year + 1900, 0, 1);
                var firstSunday = janFirst.getDay() === 0 ? janFirst : _6fd429bf(janFirst, 7 - janFirst.getDay());
                var endDate = new Date(date.tm_year + 1900, date.tm_mon, date.tm_mday);
                if (compareByDay(firstSunday, endDate) < 0) {
                    var februaryFirstUntilEndMonth = _2428ca3(_5904ba26(endDate.getFullYear()) ? _4010c7dd : _ab650c6, endDate.getMonth() - 1) - 31;
                    var firstSundayUntilEndJanuary = 31 - firstSunday.getDate();
                    var days = firstSundayUntilEndJanuary + februaryFirstUntilEndMonth + endDate.getDate();
                    return leadingNulls(Math.ceil(days / 7), 2)
                }
                return compareByDay(firstSunday, janFirst) === 0 ? "01" : "00"
            }),
            "%V": (function(date) {
                var janFourthThisYear = new Date(date.tm_year + 1900, 0, 4);
                var janFourthNextYear = new Date(date.tm_year + 1901, 0, 4);
                var firstWeekStartThisYear = getFirstWeekStartDate(janFourthThisYear);
                var firstWeekStartNextYear = getFirstWeekStartDate(janFourthNextYear);
                var endDate = _6fd429bf(new Date(date.tm_year + 1900, 0, 1), date.tm_yday);
                if (compareByDay(endDate, firstWeekStartThisYear) < 0) {
                    return "53"
                }
                if (compareByDay(firstWeekStartNextYear, endDate) <= 0) {
                    return "01"
                }
                var daysDifference;
                if (firstWeekStartThisYear.getFullYear() < date.tm_year + 1900) {
                    daysDifference = date.tm_yday + 32 - firstWeekStartThisYear.getDate()
                } else {
                    daysDifference = date.tm_yday + 1 - firstWeekStartThisYear.getDate()
                }
                return leadingNulls(Math.ceil(daysDifference / 7), 2)
            }),
            "%w": (function(date) {
                var day = new Date(date.tm_year + 1900, date.tm_mon + 1, date.tm_mday, 0, 0, 0, 0);
                return day.getDay()
            }),
            "%W": (function(date) {
                var janFirst = new Date(date.tm_year, 0, 1);
                var firstMonday = janFirst.getDay() === 1 ? janFirst : _6fd429bf(janFirst, janFirst.getDay() === 0 ? 1 : 7 - janFirst.getDay() + 1);
                var endDate = new Date(date.tm_year + 1900, date.tm_mon, date.tm_mday);
                if (compareByDay(firstMonday, endDate) < 0) {
                    var februaryFirstUntilEndMonth = _2428ca3(_5904ba26(endDate.getFullYear()) ? _4010c7dd : _ab650c6, endDate.getMonth() - 1) - 31;
                    var firstMondayUntilEndJanuary = 31 - firstMonday.getDate();
                    var days = firstMondayUntilEndJanuary + februaryFirstUntilEndMonth + endDate.getDate();
                    return leadingNulls(Math.ceil(days / 7), 2)
                }
                return compareByDay(firstMonday, janFirst) === 0 ? "01" : "00"
            }),
            "%y": (function(date) {
                return (date.tm_year + 1900).toString().substring(2)
            }),
            "%Y": (function(date) {
                return date.tm_year + 1900
            }),
            "%z": (function(date) {
                var off = date.tm_gmtoff;
                var ahead = off >= 0;
                off = Math.abs(off) / 60;
                off = off / 60 * 100 + off % 60;
                return (ahead ? "+" : "-") + String("0000" + off).slice(-4)
            }),
            "%Z": (function(date) {
                return date.tm_zone
            }),
            "%%": (function() {
                return "%"
            })
        };
        for (var rule in EXPANSION_RULES_2) {
            if (pattern.indexOf(rule) >= 0) {
                pattern = pattern.replace(new RegExp(rule, "g"), EXPANSION_RULES_2[rule](date))
            }
        }
        var bytes = intArrayFromString(pattern, false);
        if (bytes.length > maxsize) {
            return 0
        }
        writeArrayToMemory(bytes, s);
        return bytes.length - 1
    }

    function _4f107009(s, maxsize, format, tm) {
        return _80a051c(s, maxsize, format, tm)
    }

    function _5b160692() {
        Module["abort"]()
    }

    function _3d345949() {}

    function _1d677ada() {}

    function _5d18fdfc(mode, value) {
        Browser.mainLoop.timingMode = mode;
        Browser.mainLoop.timingValue = value;
        if (!Browser.mainLoop.func) {
            return 1
        }
        if (mode == 0) {
            Browser.mainLoop.scheduler = function Browser_mainLoop_scheduler_setTimeout() {
                var timeUntilNextTick = Math.max(0, Browser.mainLoop.tickStartTime + value - _3b9db1a9()) | 0;
                setTimeout(Browser.mainLoop.runner, timeUntilNextTick)
            };
            Browser.mainLoop.method = "timeout"
        } else if (mode == 1) {
            Browser.mainLoop.scheduler = function Browser_mainLoop_scheduler_rAF() {
                Browser.requestAnimationFrame(Browser.mainLoop.runner)
            };
            Browser.mainLoop.method = "rAF"
        } else if (mode == 2) {
            if (!window["setImmediate"]) {
                var setImmediates = [];
                var emscriptenMainLoopMessageId = "setimmediate";

                function Browser_setImmediate_messageHandler(event) {
                    if (event.source === window && event.data === emscriptenMainLoopMessageId) {
                        event.stopPropagation();
                        setImmediates.shift()()
                    }
                }
                window.addEventListener("message", Browser_setImmediate_messageHandler, true);
                window["setImmediate"] = function Browser_emulated_setImmediate(func) {
                    setImmediates.push(func);
                    if (ENVIRONMENT_IS_WORKER) {
                        if (Module["setImmediates"] === undefined) Module["setImmediates"] = [];
                        Module["setImmediates"].push(func);
                        window.postMessage({
                            target: emscriptenMainLoopMessageId
                        })
                    } else window.postMessage(emscriptenMainLoopMessageId, "*")
                }
            }
            Browser.mainLoop.scheduler = function Browser_mainLoop_scheduler_setImmediate() {
                window["setImmediate"](Browser.mainLoop.runner)
            };
            Browser.mainLoop.method = "immediate"
        }
        return 0
    }

    function _3b9db1a9() {
        abort()
    }

    function _4849b562(func, fps, simulateInfiniteLoop, arg, noSetTiming) {
        Module["noExitRuntime"] = true;
        assert(!Browser.mainLoop.func, "emscripten_set_main_loop: there can only be one main loop function at once: call emscripten_cancel_main_loop to cancel the previous one before setting a new one with different parameters.");
        Browser.mainLoop.func = func;
        Browser.mainLoop.arg = arg;
        var browserIterationFunc;
        if (typeof arg !== "undefined") {
            browserIterationFunc = (function() {
                Module["dynCall_vi"](func, arg)
            })
        } else {
            browserIterationFunc = (function() {
                Module["dynCall_v"](func)
            })
        }
        var thisMainLoopId = Browser.mainLoop.currentlyRunningMainloop;
        Browser.mainLoop.runner = function Browser_mainLoop_runner() {
            if (ABORT) return;
            if (Browser.mainLoop.queue.length > 0) {
                var start = Date.now();
                var blocker = Browser.mainLoop.queue.shift();
                blocker.func(blocker.arg);
                if (Browser.mainLoop.remainingBlockers) {
                    var remaining = Browser.mainLoop.remainingBlockers;
                    var next = remaining % 1 == 0 ? remaining - 1 : Math.floor(remaining);
                    if (blocker.counted) {
                        Browser.mainLoop.remainingBlockers = next
                    } else {
                        next = next + .5;
                        Browser.mainLoop.remainingBlockers = (8 * remaining + next) / 9
                    }
                }
                console.log('main loop blocker "' + blocker.name + '" took ' + (Date.now() - start) + " ms");
                Browser.mainLoop.updateStatus();
                if (thisMainLoopId < Browser.mainLoop.currentlyRunningMainloop) return;
                setTimeout(Browser.mainLoop.runner, 0);
                return
            }
            if (thisMainLoopId < Browser.mainLoop.currentlyRunningMainloop) return;
            Browser.mainLoop.currentFrameNumber = Browser.mainLoop.currentFrameNumber + 1 | 0;
            if (Browser.mainLoop.timingMode == 1 && Browser.mainLoop.timingValue > 1 && Browser.mainLoop.currentFrameNumber % Browser.mainLoop.timingValue != 0) {
                Browser.mainLoop.scheduler();
                return
            } else if (Browser.mainLoop.timingMode == 0) {
                Browser.mainLoop.tickStartTime = _3b9db1a9()
            }
            if (Browser.mainLoop.method === "timeout" && Module.ctx) {
                Module.printErr("Looks like you are rendering without using requestAnimationFrame for the main loop. You should use 0 for the frame rate in emscripten_set_main_loop in order to use requestAnimationFrame, as that can greatly improve your frame rates!");
                Browser.mainLoop.method = ""
            }
            Browser.mainLoop.runIter(browserIterationFunc);
            if (thisMainLoopId < Browser.mainLoop.currentlyRunningMainloop) return;
            if (typeof SDL === "object" && SDL.audio && SDL.audio.queueNewAudioData) SDL.audio.queueNewAudioData();
            Browser.mainLoop.scheduler()
        };
        if (!noSetTiming) {
            if (fps && fps > 0) _5d18fdfc(0, 1e3 / fps);
            else _5d18fdfc(1, 1);
            Browser.mainLoop.scheduler()
        }
        if (simulateInfiniteLoop) {
            throw "SimulateInfiniteLoop"
        }
    }
    var Browser = {
        mainLoop: {
            scheduler: null,
            method: "",
            currentlyRunningMainloop: 0,
            func: null,
            arg: 0,
            timingMode: 0,
            timingValue: 0,
            currentFrameNumber: 0,
            queue: [],
            pause: (function() {
                Browser.mainLoop.scheduler = null;
                Browser.mainLoop.currentlyRunningMainloop++
            }),
            resume: (function() {
                Browser.mainLoop.currentlyRunningMainloop++;
                var timingMode = Browser.mainLoop.timingMode;
                var timingValue = Browser.mainLoop.timingValue;
                var func = Browser.mainLoop.func;
                Browser.mainLoop.func = null;
                _4849b562(func, 0, false, Browser.mainLoop.arg, true);
                _5d18fdfc(timingMode, timingValue);
                Browser.mainLoop.scheduler()
            }),
            updateStatus: (function() {
                if (Module["setStatus"]) {
                    var message = Module["statusMessage"] || "Please wait...";
                    var remaining = Browser.mainLoop.remainingBlockers;
                    var expected = Browser.mainLoop.expectedBlockers;
                    if (remaining) {
                        if (remaining < expected) {
                            Module["setStatus"](message + " (" + (expected - remaining) + "/" + expected + ")")
                        } else {
                            Module["setStatus"](message)
                        }
                    } else {
                        Module["setStatus"]("")
                    }
                }
            }),
            runIter: (function(func) {
                if (ABORT) return;
                if (Module["preMainLoop"]) {
                    var preRet = Module["preMainLoop"]();
                    if (preRet === false) {
                        return
                    }
                }
                try {
                    func()
                } catch (e) {
                    if (e instanceof ExitStatus) {
                        return
                    } else {
                        if (e && typeof e === "object" && e.stack) Module.printErr("exception thrown: " + [e, e.stack]);
                        throw e
                    }
                }
                if (Module["postMainLoop"]) Module["postMainLoop"]()
            })
        },
        isFullscreen: false,
        pointerLock: false,
        moduleContextCreatedCallbacks: [],
        workers: [],
        init: (function() {
            if (!Module["preloadPlugins"]) Module["preloadPlugins"] = [];
            if (Browser.initted) return;
            Browser.initted = true;
            try {
                new Blob;
                Browser.hasBlobConstructor = true
            } catch (e) {
                Browser.hasBlobConstructor = false;
                console.log("warning: no blob constructor, cannot create blobs with mimetypes")
            }
            Browser.BlobBuilder = typeof MozBlobBuilder != "undefined" ? MozBlobBuilder : typeof WebKitBlobBuilder != "undefined" ? WebKitBlobBuilder : !Browser.hasBlobConstructor ? console.log("warning: no BlobBuilder") : null;
            Browser.URLObject = typeof window != "undefined" ? window.URL ? window.URL : window.webkitURL : undefined;
            if (!Module.noImageDecoding && typeof Browser.URLObject === "undefined") {
                console.log("warning: Browser does not support creating object URLs. Built-in browser image decoding will not be available.");
                Module.noImageDecoding = true
            }
            var imagePlugin = {};
            imagePlugin["canHandle"] = function imagePlugin_canHandle(name) {
                return !Module.noImageDecoding && /\.(jpg|jpeg|png|bmp)$/i.test(name)
            };
            imagePlugin["handle"] = function imagePlugin_handle(byteArray, name, onload, onerror) {
                var b = null;
                if (Browser.hasBlobConstructor) {
                    try {
                        b = new Blob([byteArray], {
                            type: Browser.getMimetype(name)
                        });
                        if (b.size !== byteArray.length) {
                            b = new Blob([(new Uint8Array(byteArray)).buffer], {
                                type: Browser.getMimetype(name)
                            })
                        }
                    } catch (e) {
                        Runtime.warnOnce("Blob constructor present but fails: " + e + "; falling back to blob builder")
                    }
                }
                if (!b) {
                    var bb = new Browser.BlobBuilder;
                    bb.append((new Uint8Array(byteArray)).buffer);
                    b = bb.getBlob()
                }
                var url = Browser.URLObject.createObjectURL(b);
                var img = new Image;
                img.onload = function img_onload() {
                    assert(img.complete, "Image " + name + " could not be decoded");
                    var canvas = document.createElement("canvas");
                    canvas.width = img.width;
                    canvas.height = img.height;
                    var ctx = canvas.getContext("2d");
                    ctx.drawImage(img, 0, 0);
                    Module["preloadedImages"][name] = canvas;
                    Browser.URLObject.revokeObjectURL(url);
                    if (onload) onload(byteArray)
                };
                img.onerror = function img_onerror(event) {
                    console.log("Image " + url + " could not be decoded");
                    if (onerror) onerror()
                };
                img.src = url
            };
            Module["preloadPlugins"].push(imagePlugin);
            var audioPlugin = {};
            audioPlugin["canHandle"] = function audioPlugin_canHandle(name) {
                return !Module.noAudioDecoding && name.substr(-4) in {
                    ".ogg": 1,
                    ".wav": 1,
                    ".mp3": 1
                }
            };
            audioPlugin["handle"] = function audioPlugin_handle(byteArray, name, onload, onerror) {
                var done = false;

                function finish(audio) {
                    if (done) return;
                    done = true;
                    Module["preloadedAudios"][name] = audio;
                    if (onload) onload(byteArray)
                }

                function fail() {
                    if (done) return;
                    done = true;
                    Module["preloadedAudios"][name] = new Audio;
                    if (onerror) onerror()
                }
                if (Browser.hasBlobConstructor) {
                    try {
                        var b = new Blob([byteArray], {
                            type: Browser.getMimetype(name)
                        })
                    } catch (e) {
                        return fail()
                    }
                    var url = Browser.URLObject.createObjectURL(b);
                    var audio = new Audio;
                    audio.addEventListener("canplaythrough", (function() {
                        finish(audio)
                    }), false);
                    audio.onerror = function audio_onerror(event) {
                        if (done) return;
                        console.log("warning: browser could not fully decode audio " + name + ", trying slower base64 approach");

                        function encode64(data) {
                            var BASE = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
                            var PAD = "=";
                            var ret = "";
                            var leftchar = 0;
                            var leftbits = 0;
                            for (var i = 0; i < data.length; i++) {
                                leftchar = leftchar << 8 | data[i];
                                leftbits += 8;
                                while (leftbits >= 6) {
                                    var curr = leftchar >> leftbits - 6 & 63;
                                    leftbits -= 6;
                                    ret += BASE[curr]
                                }
                            }
                            if (leftbits == 2) {
                                ret += BASE[(leftchar & 3) << 4];
                                ret += PAD + PAD
                            } else if (leftbits == 4) {
                                ret += BASE[(leftchar & 15) << 2];
                                ret += PAD
                            }
                            return ret
                        }
                        audio.src = "data:audio/x-" + name.substr(-3) + ";base64 ," + encode64(byteArray);
                        finish(audio)
                    };
                    audio.src = url;
                    Browser.safeSetTimeout((function() {
                        finish(audio)
                    }), 1e4)
                } else {
                    return fail()
                }
            };
            Module["preloadPlugins"].push(audioPlugin);

            function pointerLockChange() {
                Browser.pointerLock = document["pointerLockElement"] === Module["canvas"] || document["mozPointerLockElement"] === Module["canvas"] || document["webkitPointerLockElement"] === Module["canvas"] || document["msPointerLockElement"] === Module["canvas"]
            }
            var canvas = Module["canvas"];
            if (canvas) {
                canvas.requestPointerLock = canvas["requestPointerLock"] || canvas["mozRequestPointerLock"] || canvas["webkitRequestPointerLock"] || canvas["msRequestPointerLock"] || (function() {});
                canvas.exitPointerLock = document["exitPointerLock"] || document["mozExitPointerLock"] || document["webkitExitPointerLock"] || document["msExitPointerLock"] || (function() {});
                canvas.exitPointerLock = canvas.exitPointerLock.bind(document);
                document.addEventListener("pointerlockchange", pointerLockChange, false);
                document.addEventListener("mozpointerlockchange", pointerLockChange, false);
                document.addEventListener("webkitpointerlockchange", pointerLockChange, false);
                document.addEventListener("mspointerlockchange", pointerLockChange, false);
                if (Module["elementPointerLock"]) {
                    canvas.addEventListener("click", (function(ev) {
                        if (!Browser.pointerLock && Module["canvas"].requestPointerLock) {
                            Module["canvas"].requestPointerLock();
                            ev.preventDefault()
                        }
                    }), false)
                }
            }
        }),
        createContext: (function(canvas, useWebGL, setInModule, webGLContextAttributes) {
            if (useWebGL && Module.ctx && canvas == Module.canvas) return Module.ctx;
            var ctx;
            var contextHandle;
            if (useWebGL) {
                var contextAttributes = {
                    antialias: false,
                    alpha: false
                };
                if (webGLContextAttributes) {
                    for (var attribute in webGLContextAttributes) {
                        contextAttributes[attribute] = webGLContextAttributes[attribute]
                    }
                }
                contextHandle = GL.createContext(canvas, contextAttributes);
                if (contextHandle) {
                    ctx = GL.getContext(contextHandle).GLctx
                }
            } else {
                ctx = canvas.getContext("2d")
            }
            if (!ctx) return null;
            if (setInModule) {
                if (!useWebGL) assert(typeof GLctx === "undefined", "cannot set in module if GLctx is used, but we are a non-GL context that would replace it");
                Module.ctx = ctx;
                if (useWebGL) GL.makeContextCurrent(contextHandle);
                Module.useWebGL = useWebGL;
                Browser.moduleContextCreatedCallbacks.forEach((function(callback) {
                    callback()
                }));
                Browser.init()
            }
            return ctx
        }),
        destroyContext: (function(canvas, useWebGL, setInModule) {}),
        fullscreenHandlersInstalled: false,
        lockPointer: undefined,
        resizeCanvas: undefined,
        requestFullscreen: (function(lockPointer, resizeCanvas, vrDevice) {
            Browser.lockPointer = lockPointer;
            Browser.resizeCanvas = resizeCanvas;
            Browser.vrDevice = vrDevice;
            if (typeof Browser.lockPointer === "undefined") Browser.lockPointer = true;
            if (typeof Browser.resizeCanvas === "undefined") Browser.resizeCanvas = false;
            if (typeof Browser.vrDevice === "undefined") Browser.vrDevice = null;
            var canvas = Module["canvas"];

            function fullscreenChange() {
                Browser.isFullscreen = false;
                var canvasContainer = canvas.parentNode;
                if ((document["fullscreenElement"] || document["mozFullScreenElement"] || document["msFullscreenElement"] || document["webkitFullscreenElement"] || document["webkitCurrentFullScreenElement"]) === canvasContainer) {
                    canvas.exitFullscreen = document["exitFullscreen"] || document["cancelFullScreen"] || document["mozCancelFullScreen"] || document["msExitFullscreen"] || document["webkitCancelFullScreen"] || (function() {});
                    canvas.exitFullscreen = canvas.exitFullscreen.bind(document);
                    if (Browser.lockPointer) canvas.requestPointerLock();
                    Browser.isFullscreen = true;
                    if (Browser.resizeCanvas) Browser.setFullscreenCanvasSize()
                } else {
                    canvasContainer.parentNode.insertBefore(canvas, canvasContainer);
                    canvasContainer.parentNode.removeChild(canvasContainer);
                    if (Browser.resizeCanvas) Browser.setWindowedCanvasSize()
                }
                if (Module["onFullScreen"]) Module["onFullScreen"](Browser.isFullscreen);
                if (Module["onFullscreen"]) Module["onFullscreen"](Browser.isFullscreen);
                Browser.updateCanvasDimensions(canvas)
            }
            if (!Browser.fullscreenHandlersInstalled) {
                Browser.fullscreenHandlersInstalled = true;
                document.addEventListener("fullscreenchange", fullscreenChange, false);
                document.addEventListener("mozfullscreenchange", fullscreenChange, false);
                document.addEventListener("webkitfullscreenchange", fullscreenChange, false);
                document.addEventListener("MSFullscreenChange", fullscreenChange, false)
            }
            var canvasContainer = document.createElement("div");
            canvas.parentNode.insertBefore(canvasContainer, canvas);
            canvasContainer.appendChild(canvas);
            canvasContainer.requestFullscreen = canvasContainer["requestFullscreen"] || canvasContainer["mozRequestFullScreen"] || canvasContainer["msRequestFullscreen"] || (canvasContainer["webkitRequestFullscreen"] ? (function() {
                canvasContainer["webkitRequestFullscreen"](Element["ALLOW_KEYBOARD_INPUT"])
            }) : null) || (canvasContainer["webkitRequestFullScreen"] ? (function() {
                canvasContainer["webkitRequestFullScreen"](Element["ALLOW_KEYBOARD_INPUT"])
            }) : null);
            if (vrDevice) {
                canvasContainer.requestFullscreen({
                    vrDisplay: vrDevice
                })
            } else {
                canvasContainer.requestFullscreen()
            }
        }),
        requestFullScreen: (function(lockPointer, resizeCanvas, vrDevice) {
            Module.printErr("Browser.requestFullScreen() is deprecated. Please call Browser.requestFullscreen instead.");
            Browser.requestFullScreen = (function(lockPointer, resizeCanvas, vrDevice) {
                return Browser.requestFullscreen(lockPointer, resizeCanvas, vrDevice)
            });
            return Browser.requestFullscreen(lockPointer, resizeCanvas, vrDevice)
        }),
        nextRAF: 0,
        fakeRequestAnimationFrame: (function(func) {
            var now = Date.now();
            if (Browser.nextRAF === 0) {
                Browser.nextRAF = now + 1e3 / 60
            } else {
                while (now + 2 >= Browser.nextRAF) {
                    Browser.nextRAF += 1e3 / 60
                }
            }
            var delay = Math.max(Browser.nextRAF - now, 0);
            setTimeout(func, delay)
        }),
        requestAnimationFrame: function requestAnimationFrame(func) {
            if (typeof window === "undefined") {
                Browser.fakeRequestAnimationFrame(func)
            } else {
                if (!window.requestAnimationFrame) {
                    window.requestAnimationFrame = window["requestAnimationFrame"] || window["mozRequestAnimationFrame"] || window["webkitRequestAnimationFrame"] || window["msRequestAnimationFrame"] || window["oRequestAnimationFrame"] || Browser.fakeRequestAnimationFrame
                }
                window.requestAnimationFrame(func)
            }
        },
        safeCallback: (function(func) {
            return (function() {
                if (!ABORT) return func.apply(null, arguments)
            })
        }),
        allowAsyncCallbacks: true,
        queuedAsyncCallbacks: [],
        pauseAsyncCallbacks: (function() {
            Browser.allowAsyncCallbacks = false
        }),
        resumeAsyncCallbacks: (function() {
            Browser.allowAsyncCallbacks = true;
            if (Browser.queuedAsyncCallbacks.length > 0) {
                var callbacks = Browser.queuedAsyncCallbacks;
                Browser.queuedAsyncCallbacks = [];
                callbacks.forEach((function(func) {
                    func()
                }))
            }
        }),
        safeRequestAnimationFrame: (function(func) {
            return Browser.requestAnimationFrame((function() {
                if (ABORT) return;
                if (Browser.allowAsyncCallbacks) {
                    func()
                } else {
                    Browser.queuedAsyncCallbacks.push(func)
                }
            }))
        }),
        safeSetTimeout: (function(func, timeout) {
            Module["noExitRuntime"] = true;
            return setTimeout((function() {
                if (ABORT) return;
                if (Browser.allowAsyncCallbacks) {
                    func()
                } else {
                    Browser.queuedAsyncCallbacks.push(func)
                }
            }), timeout)
        }),
        safeSetInterval: (function(func, timeout) {
            Module["noExitRuntime"] = true;
            return setInterval((function() {
                if (ABORT) return;
                if (Browser.allowAsyncCallbacks) {
                    func()
                }
            }), timeout)
        }),
        getMimetype: (function(name) {
            return {
                "jpg": "image/jpeg",
                "jpeg": "image/jpeg",
                "png": "image/png",
                "bmp": "image/bmp",
                "ogg": "audio/ogg",
                "wav": "audio/wav",
                "mp3": "audio/mpeg"
            }[name.substr(name.lastIndexOf(".") + 1)]
        }),
        getUserMedia: (function(func) {
            if (!window.getUserMedia) {
                window.getUserMedia = navigator["getUserMedia"] || navigator["mozGetUserMedia"]
            }
            window.getUserMedia(func)
        }),
        getMovementX: (function(event) {
            return event["movementX"] || event["mozMovementX"] || event["webkitMovementX"] || 0
        }),
        getMovementY: (function(event) {
            return event["movementY"] || event["mozMovementY"] || event["webkitMovementY"] || 0
        }),
        getMouseWheelDelta: (function(event) {
            var delta = 0;
            switch (event.type) {
                case "DOMMouseScroll":
                    delta = event.detail;
                    break;
                case "mousewheel":
                    delta = event.wheelDelta;
                    break;
                case "wheel":
                    delta = event["deltaY"];
                    break;
                default:
                    throw "unrecognized mouse wheel event: " + event.type
            }
            return delta
        }),
        mouseX: 0,
        mouseY: 0,
        mouseMovementX: 0,
        mouseMovementY: 0,
        touches: {},
        lastTouches: {},
        calculateMouseEvent: (function(event) {
            if (Browser.pointerLock) {
                if (event.type != "mousemove" && "mozMovementX" in event) {
                    Browser.mouseMovementX = Browser.mouseMovementY = 0
                } else {
                    Browser.mouseMovementX = Browser.getMovementX(event);
                    Browser.mouseMovementY = Browser.getMovementY(event)
                }
                if (typeof SDL != "undefined") {
                    Browser.mouseX = SDL.mouseX + Browser.mouseMovementX;
                    Browser.mouseY = SDL.mouseY + Browser.mouseMovementY
                } else {
                    Browser.mouseX += Browser.mouseMovementX;
                    Browser.mouseY += Browser.mouseMovementY
                }
            } else {
                var rect = Module["canvas"].getBoundingClientRect();
                var cw = Module["canvas"].width;
                var ch = Module["canvas"].height;
                var scrollX = typeof window.scrollX !== "undefined" ? window.scrollX : window.pageXOffset;
                var scrollY = typeof window.scrollY !== "undefined" ? window.scrollY : window.pageYOffset;
                if (event.type === "touchstart" || event.type === "touchend" || event.type === "touchmove") {
                    var touch = event.touch;
                    if (touch === undefined) {
                        return
                    }
                    var adjustedX = touch.pageX - (scrollX + rect.left);
                    var adjustedY = touch.pageY - (scrollY + rect.top);
                    adjustedX = adjustedX * (cw / rect.width);
                    adjustedY = adjustedY * (ch / rect.height);
                    var coords = {
                        x: adjustedX,
                        y: adjustedY
                    };
                    if (event.type === "touchstart") {
                        Browser.lastTouches[touch.identifier] = coords;
                        Browser.touches[touch.identifier] = coords
                    } else if (event.type === "touchend" || event.type === "touchmove") {
                        var last = Browser.touches[touch.identifier];
                        if (!last) last = coords;
                        Browser.lastTouches[touch.identifier] = last;
                        Browser.touches[touch.identifier] = coords
                    }
                    return
                }
                var x = event.pageX - (scrollX + rect.left);
                var y = event.pageY - (scrollY + rect.top);
                x = x * (cw / rect.width);
                y = y * (ch / rect.height);
                Browser.mouseMovementX = x - Browser.mouseX;
                Browser.mouseMovementY = y - Browser.mouseY;
                Browser.mouseX = x;
                Browser.mouseY = y
            }
        }),
        asyncLoad: (function(url, onload, onerror, noRunDep) {
            var dep = !noRunDep ? getUniqueRunDependency("al " + url) : "";
            Module["readAsync"](url, (function(arrayBuffer) {
                assert(arrayBuffer, 'Loading data file "' + url + '" failed (no arrayBuffer).');
                onload(new Uint8Array(arrayBuffer));
                if (dep) removeRunDependency(dep)
            }), (function(event) {
                if (onerror) {
                    onerror()
                } else {
                    throw 'Loading data file "' + url + '" failed.'
                }
            }));
            if (dep) addRunDependency(dep)
        }),
        resizeListeners: [],
        updateResizeListeners: (function() {
            var canvas = Module["canvas"];
            Browser.resizeListeners.forEach((function(listener) {
                listener(canvas.width, canvas.height)
            }))
        }),
        setCanvasSize: (function(width, height, noUpdates) {
            var canvas = Module["canvas"];
            Browser.updateCanvasDimensions(canvas, width, height);
            if (!noUpdates) Browser.updateResizeListeners()
        }),
        windowedWidth: 0,
        windowedHeight: 0,
        setFullscreenCanvasSize: (function() {
            if (typeof SDL != "undefined") {
                var flags = HEAPU32[SDL.screen + Runtime.QUANTUM_SIZE * 0 >> 2];
                flags = flags | 8388608;
                HEAP32[SDL.screen + Runtime.QUANTUM_SIZE * 0 >> 2] = flags
            }
            Browser.updateResizeListeners()
        }),
        setWindowedCanvasSize: (function() {
            if (typeof SDL != "undefined") {
                var flags = HEAPU32[SDL.screen + Runtime.QUANTUM_SIZE * 0 >> 2];
                flags = flags & ~8388608;
                HEAP32[SDL.screen + Runtime.QUANTUM_SIZE * 0 >> 2] = flags
            }
            Browser.updateResizeListeners()
        }),
        updateCanvasDimensions: (function(canvas, wNative, hNative) {
            if (wNative && hNative) {
                canvas.widthNative = wNative;
                canvas.heightNative = hNative
            } else {
                wNative = canvas.widthNative;
                hNative = canvas.heightNative
            }
            var w = wNative;
            var h = hNative;
            if (Module["forcedAspectRatio"] && Module["forcedAspectRatio"] > 0) {
                if (w / h < Module["forcedAspectRatio"]) {
                    w = Math.round(h * Module["forcedAspectRatio"])
                } else {
                    h = Math.round(w / Module["forcedAspectRatio"])
                }
            }
            if ((document["fullscreenElement"] || document["mozFullScreenElement"] || document["msFullscreenElement"] || document["webkitFullscreenElement"] || document["webkitCurrentFullScreenElement"]) === canvas.parentNode && typeof screen != "undefined") {
                var factor = Math.min(screen.width / w, screen.height / h);
                w = Math.round(w * factor);
                h = Math.round(h * factor)
            }
            if (Browser.resizeCanvas) {
                if (canvas.width != w) canvas.width = w;
                if (canvas.height != h) canvas.height = h;
                if (typeof canvas.style != "undefined") {
                    canvas.style.removeProperty("width");
                    canvas.style.removeProperty("height")
                }
            } else {
                if (canvas.width != wNative) canvas.width = wNative;
                if (canvas.height != hNative) canvas.height = hNative;
                if (typeof canvas.style != "undefined") {
                    if (w != wNative || h != hNative) {
                        canvas.style.setProperty("width", w + "px", "important");
                        canvas.style.setProperty("height", h + "px", "important")
                    } else {
                        canvas.style.removeProperty("width");
                        canvas.style.removeProperty("height")
                    }
                }
            }
        }),
        wgetRequests: {},
        nextWgetRequestHandle: 0,
        getNextWgetRequestHandle: (function() {
            var handle = Browser.nextWgetRequestHandle;
            Browser.nextWgetRequestHandle++;
            return handle
        })
    };

    function _38fbe96a(status) {
        Module["noExitRuntime"] = false;
        Module["exit"](status)
    }
    var _54f47a97 = Math_pow;
    Module["_1e8531c8"] = _1e8531c8;

    function _f19f455() {
        Module["noExitRuntime"] = true;
        throw "SimulateInfiniteLoop"
    }
    var SYSCALLS = {
        varargs: 0,
        get: (function(varargs) {
            SYSCALLS.varargs += 4;
            var ret = HEAP32[SYSCALLS.varargs - 4 >> 2];
            return ret
        }),
        getStr: (function() {
            var ret = Pointer_stringify(SYSCALLS.get());
            return ret
        }),
        get64: (function() {
            var low = SYSCALLS.get(),
                high = SYSCALLS.get();
            if (low >= 0) assert(high === 0);
            else assert(high === -1);
            return low
        }),
        getZero: (function() {
            assert(SYSCALLS.get() === 0)
        })
    };

    function _e0a36e1(which, varargs) {
        SYSCALLS.varargs = varargs;
        try {
            var addr = SYSCALLS.get(),
                len = SYSCALLS.get();
            var info = SYSCALLS.mappings[addr];
            if (!info) return 0;
            if (len === info.len) {
                var stream = FS.getStream(info.fd);
                SYSCALLS.doMsync(addr, stream, len, info.flags);
                FS.munmap(stream);
                SYSCALLS.mappings[addr] = null;
                if (info.allocated) {
                    _2a1a33e5(info.malloc)
                }
            }
            return 0
        } catch (e) {
            if (typeof FS === "undefined" || !(e instanceof FS.ErrnoError)) abort(e);
            return -e.errno
        }
    }

    function _670f6e34(which, varargs) {
        SYSCALLS.varargs = varargs;
        try {
            return 0
        } catch (e) {
            if (typeof FS === "undefined" || !(e instanceof FS.ErrnoError)) abort(e);
            return -e.errno
        }
    }
    Module["_664e9249"] = _664e9249;

    function _9154e1b() {
        ABORT = true;
        throw "Pure virtual function called!"
    }
    Module["_6830ed67"] = _6830ed67;
    var _19c49dfd = STATICTOP;
    STATICTOP += 16;

    function _73d4934f(env) {
        var MAX_ENV_VALUES = 64;
        var TOTAL_ENV_SIZE = 1024;
        var poolPtr;
        var envPtr;
        if (!_73d4934f.called) {
            _73d4934f.called = true;
            ENV["USER"] = ENV["LOGNAME"] = "web_user";
            ENV["PATH"] = "/";
            ENV["PWD"] = "/";
            ENV["HOME"] = "/home/web_user";
            ENV["LANG"] = "C";
            ENV["_"] = Module["thisProgram"];
            poolPtr = allocate(TOTAL_ENV_SIZE, "i8", ALLOC_STATIC);
            envPtr = allocate(MAX_ENV_VALUES * 4, "i8*", ALLOC_STATIC);
            HEAP32[envPtr >> 2] = poolPtr;
            HEAP32[_19c49dfd >> 2] = envPtr
        } else {
            envPtr = HEAP32[_19c49dfd >> 2];
            poolPtr = HEAP32[envPtr >> 2]
        }
        var strings = [];
        var totalSize = 0;
        for (var key in env) {
            if (typeof env[key] === "string") {
                var line = key + "=" + env[key];
                strings.push(line);
                totalSize += line.length
            }
        }
        if (totalSize > TOTAL_ENV_SIZE) {
            throw new Error("Environment size exceeded TOTAL_ENV_SIZE!")
        }
        var ptrSize = 4;
        for (var i = 0; i < strings.length; i++) {
            var line = strings[i];
            writeAsciiToMemory(line, poolPtr);
            HEAP32[envPtr + i * ptrSize >> 2] = poolPtr;
            poolPtr += line.length + 1
        }
        HEAP32[envPtr + strings.length * ptrSize >> 2] = 0
    }
    var ENV = {};

    function _7d7f372d(name) {
        if (name === 0) return 0;
        name = Pointer_stringify(name);
        if (!ENV.hasOwnProperty(name)) return 0;
        if (_7d7f372d.ret) _2a1a33e5(_7d7f372d.ret);
        _7d7f372d.ret = allocate(intArrayFromString(ENV[name]), "i8", ALLOC_NORMAL);
        return _7d7f372d.ret
    }
    var ERRNO_CODES = {
        EPERM: 1,
        ENOENT: 2,
        ESRCH: 3,
        EINTR: 4,
        EIO: 5,
        ENXIO: 6,
        E2BIG: 7,
        ENOEXEC: 8,
        EBADF: 9,
        ECHILD: 10,
        EAGAIN: 11,
        EWOULDBLOCK: 11,
        ENOMEM: 12,
        EACCES: 13,
        EFAULT: 14,
        ENOTBLK: 15,
        EBUSY: 16,
        EEXIST: 17,
        EXDEV: 18,
        ENODEV: 19,
        ENOTDIR: 20,
        EISDIR: 21,
        EINVAL: 22,
        ENFILE: 23,
        EMFILE: 24,
        ENOTTY: 25,
        ETXTBSY: 26,
        EFBIG: 27,
        ENOSPC: 28,
        ESPIPE: 29,
        EROFS: 30,
        EMLINK: 31,
        EPIPE: 32,
        EDOM: 33,
        ERANGE: 34,
        ENOMSG: 42,
        EIDRM: 43,
        ECHRNG: 44,
        EL2NSYNC: 45,
        EL3HLT: 46,
        EL3RST: 47,
        ELNRNG: 48,
        EUNATCH: 49,
        ENOCSI: 50,
        EL2HLT: 51,
        EDEADLK: 35,
        ENOLCK: 37,
        EBADE: 52,
        EBADR: 53,
        EXFULL: 54,
        ENOANO: 55,
        EBADRQC: 56,
        EBADSLT: 57,
        EDEADLOCK: 35,
        EBFONT: 59,
        ENOSTR: 60,
        ENODATA: 61,
        ETIME: 62,
        ENOSR: 63,
        ENONET: 64,
        ENOPKG: 65,
        EREMOTE: 66,
        ENOLINK: 67,
        EADV: 68,
        ESRMNT: 69,
        ECOMM: 70,
        EPROTO: 71,
        EMULTIHOP: 72,
        EDOTDOT: 73,
        EBADMSG: 74,
        ENOTUNIQ: 76,
        EBADFD: 77,
        EREMCHG: 78,
        ELIBACC: 79,
        ELIBBAD: 80,
        ELIBSCN: 81,
        ELIBMAX: 82,
        ELIBEXEC: 83,
        ENOSYS: 38,
        ENOTEMPTY: 39,
        ENAMETOOLONG: 36,
        ELOOP: 40,
        EOPNOTSUPP: 95,
        EPFNOSUPPORT: 96,
        ECONNRESET: 104,
        ENOBUFS: 105,
        EAFNOSUPPORT: 97,
        EPROTOTYPE: 91,
        ENOTSOCK: 88,
        ENOPROTOOPT: 92,
        ESHUTDOWN: 108,
        ECONNREFUSED: 111,
        EADDRINUSE: 98,
        ECONNABORTED: 103,
        ENETUNREACH: 101,
        ENETDOWN: 100,
        ETIMEDOUT: 110,
        EHOSTDOWN: 112,
        EHOSTUNREACH: 113,
        EINPROGRESS: 115,
        EALREADY: 114,
        EDESTADDRREQ: 89,
        EMSGSIZE: 90,
        EPROTONOSUPPORT: 93,
        ESOCKTNOSUPPORT: 94,
        EADDRNOTAVAIL: 99,
        ENETRESET: 102,
        EISCONN: 106,
        ENOTCONN: 107,
        ETOOMANYREFS: 109,
        EUSERS: 87,
        EDQUOT: 122,
        ESTALE: 116,
        ENOTSUP: 95,
        ENOMEDIUM: 123,
        EILSEQ: 84,
        EOVERFLOW: 75,
        ECANCELED: 125,
        ENOTRECOVERABLE: 131,
        EOWNERDEAD: 130,
        ESTRPIPE: 86
    };

    function _466ffc59(value) {
        if (Module["_636ff7d5"]) HEAP32[Module["_636ff7d5"]() >> 2] = value;
        return value
    }

    function _4a49bc82(pathname, size) {
        _466ffc59(ERRNO_CODES.EPERM);
        return -1
    }
    Module["_6d900685"] = _6d900685;
    var cttz_i8 = allocate([8, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 6, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 7, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 6, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0], "i8", ALLOC_STATIC);

    function _7ca91a67(x) {
        x = x | 0;
        var ret = 0;
        ret = HEAP8[cttz_i8 + (x & 255) >> 0] | 0;
        if ((ret | 0) < 8) return ret | 0;
        ret = HEAP8[cttz_i8 + (x >> 8 & 255) >> 0] | 0;
        if ((ret | 0) < 8) return ret + 8 | 0;
        ret = HEAP8[cttz_i8 + (x >> 16 & 255) >> 0] | 0;
        if ((ret | 0) < 8) return ret + 16 | 0;
        return (HEAP8[cttz_i8 + (x >>> 24) >> 0] | 0) + 24 | 0
    }
    Module["_64c247ec"] = _64c247ec;
    Module["_79a796e5"] = _79a796e5;

    function _2eb15c7f(dest, src, num) {
        HEAPU8.set(HEAPU8.subarray(src, src + num), dest);
        return dest
    }
    Module["_17863535"] = _17863535;

    function _4c6c9f1f(which, varargs) {
        SYSCALLS.varargs = varargs;
        try {
            var stream = SYSCALLS.getStreamFromFD();
            FS.close(stream);
            return 0
        } catch (e) {
            if (typeof FS === "undefined" || !(e instanceof FS.ErrnoError)) abort(e);
            return -e.errno
        }
    }

    function _817d1bb() {
        return !!_817d1bb.uncaught_exception
    }
    Module["_7c1fc741"] = _7c1fc741;
    Module["_74c2f7c3"] = _74c2f7c3;
    var _7cb8bf61 = Math_pow;
    Module["_2a665258"] = _2a665258;
    Module["_3e2469d8"] = _3e2469d8;
    Module["_1722603f"] = _1722603f;
    Module["_4db4edc0"] = _4db4edc0;

    function _44ec023f() {
        return 0
    }
    Module["_3ac8e1f5"] = _3ac8e1f5;

    function _281d7ec1(which, varargs) {
        SYSCALLS.varargs = varargs;
        try {
            var stream = SYSCALLS.getStreamFromFD(),
                offset_high = SYSCALLS.get(),
                offset_low = SYSCALLS.get(),
                result = SYSCALLS.get(),
                whence = SYSCALLS.get();
            var offset = offset_low;
            assert(offset_high === 0);
            FS.llseek(stream, offset, whence);
            HEAP32[result >> 2] = stream.position;
            if (stream.getdents && offset === 0 && whence === 0) stream.getdents = null;
            return 0
        } catch (e) {
            if (typeof FS === "undefined" || !(e instanceof FS.ErrnoError)) abort(e);
            return -e.errno
        }
    }

    function _3aa20c9f() {
        return Math.random()
    }

    function _8a564b8(which, varargs) {
        SYSCALLS.varargs = varargs;
        try {
            var stream = SYSCALLS.get(),
                iov = SYSCALLS.get(),
                iovcnt = SYSCALLS.get();
            var ret = 0;
            if (!_8a564b8.buffer) {
                _8a564b8.buffers = [null, [],
                    []
                ];
                _8a564b8.printChar = (function(stream, curr) {
                    var buffer = _8a564b8.buffers[stream];
                    assert(buffer);
                    if (curr === 0 || curr === 10) {
                        (stream === 1 ? Module["print"] : Module["printErr"])(UTF8ArrayToString(buffer, 0));
                        buffer.length = 0
                    } else {
                        buffer.push(curr)
                    }
                })
            }
            for (var i = 0; i < iovcnt; i++) {
                var ptr = HEAP32[iov + i * 8 >> 2];
                var len = HEAP32[iov + (i * 8 + 4) >> 2];
                for (var j = 0; j < len; j++) {
                    _8a564b8.printChar(stream, HEAPU8[ptr + j])
                }
                ret += len
            }
            return ret
        } catch (e) {
            if (typeof FS === "undefined" || !(e instanceof FS.ErrnoError)) abort(e);
            return -e.errno
        }
    }
    Module["requestFullScreen"] = function Module_requestFullScreen(lockPointer, resizeCanvas, vrDevice) {
        Module.printErr("Module.requestFullScreen is deprecated. Please call Module.requestFullscreen instead.");
        Module["requestFullScreen"] = Module["requestFullscreen"];
        Browser.requestFullScreen(lockPointer, resizeCanvas, vrDevice)
    };
    Module["requestFullscreen"] = function Module_requestFullscreen(lockPointer, resizeCanvas, vrDevice) {
        Browser.requestFullscreen(lockPointer, resizeCanvas, vrDevice)
    };
    Module["requestAnimationFrame"] = function Module_requestAnimationFrame(func) {
        Browser.requestAnimationFrame(func)
    };
    Module["setCanvasSize"] = function Module_setCanvasSize(width, height, noUpdates) {
        Browser.setCanvasSize(width, height, noUpdates)
    };
    Module["pauseMainLoop"] = function Module_pauseMainLoop() {
        Browser.mainLoop.pause()
    };
    Module["resumeMainLoop"] = function Module_resumeMainLoop() {
        Browser.mainLoop.resume()
    };
    Module["getUserMedia"] = function Module_getUserMedia() {
        Browser.getUserMedia()
    };
    Module["createContext"] = function Module_createContext(canvas, useWebGL, setInModule, webGLContextAttributes) {
        return Browser.createContext(canvas, useWebGL, setInModule, webGLContextAttributes)
    };
    if (ENVIRONMENT_IS_NODE) {
        _3b9db1a9 = function _6507d696() {
            var t = process["hrtime"]();
            return t[0] * 1e3 + t[1] / 1e6
        }
    } else if (typeof dateNow !== "undefined") {
        _3b9db1a9 = dateNow
    } else if (typeof self === "object" && self["performance"] && typeof self["performance"]["now"] === "function") {
        _3b9db1a9 = (function() {
            return self["performance"]["now"]()
        })
    } else if (typeof performance === "object" && typeof performance["now"] === "function") {
        _3b9db1a9 = (function() {
            return performance["now"]()
        })
    } else {
        _3b9db1a9 = Date.now
    }
    _73d4934f(ENV);
    _32ef363b.push((function() {
        var fflush = Module["_7899e48b"];
        if (fflush) fflush(0);
        var printChar = _8a564b8.printChar;
        if (!printChar) return;
        var buffers = _8a564b8.buffers;
        if (buffers[1].length) printChar(1, 10);
        if (buffers[2].length) printChar(2, 10)
    }));
    DYNAMICTOP_PTR = allocate(1, "i32", ALLOC_STATIC);
    STACK_BASE = STACKTOP = Runtime.alignMemory(STATICTOP);
    STACK_MAX = STACK_BASE + TOTAL_STACK;
    DYNAMIC_BASE = Runtime.alignMemory(STACK_MAX);
    HEAP32[DYNAMICTOP_PTR >> 2] = DYNAMIC_BASE;
    staticSealed = true;
    Module["wasmTableSize"] = 768;
    Module["wasmMaxTableSize"] = 768;

    function invoke_iiiiiiii(index, a1, a2, a3, a4, a5, a6, a7) {
        try {
            return Module["dynCall_iiiiiiii"](index, a1, a2, a3, a4, a5, a6, a7)
        } catch (e) {
            if (typeof e !== "number" && e !== "longjmp") throw e;
            Module["setThrew"](1, 0)
        }
    }

    function invoke_iiii(index, a1, a2, a3) {
        try {
            return Module["dynCall_iiii"](index, a1, a2, a3)
        } catch (e) {
            if (typeof e !== "number" && e !== "longjmp") throw e;
            Module["setThrew"](1, 0)
        }
    }

    function invoke_viiiiii(index, a1, a2, a3, a4, a5, a6) {
        try {
            Module["dynCall_viiiiii"](index, a1, a2, a3, a4, a5, a6)
        } catch (e) {
            if (typeof e !== "number" && e !== "longjmp") throw e;
            Module["setThrew"](1, 0)
        }
    }

    function invoke_viiiii(index, a1, a2, a3, a4, a5) {
        try {
            Module["dynCall_viiiii"](index, a1, a2, a3, a4, a5)
        } catch (e) {
            if (typeof e !== "number" && e !== "longjmp") throw e;
            Module["setThrew"](1, 0)
        }
    }

    function invoke_dii(index, a1, a2) {
        try {
            return Module["dynCall_dii"](index, a1, a2)
        } catch (e) {
            if (typeof e !== "number" && e !== "longjmp") throw e;
            Module["setThrew"](1, 0)
        }
    }

    function invoke_iiiiiid(index, a1, a2, a3, a4, a5, a6) {
        try {
            return Module["dynCall_iiiiiid"](index, a1, a2, a3, a4, a5, a6)
        } catch (e) {
            if (typeof e !== "number" && e !== "longjmp") throw e;
            Module["setThrew"](1, 0)
        }
    }

    function invoke_vi(index, a1) {
        try {
            Module["dynCall_vi"](index, a1)
        } catch (e) {
            if (typeof e !== "number" && e !== "longjmp") throw e;
            Module["setThrew"](1, 0)
        }
    }

    function invoke_vii(index, a1, a2) {
        try {
            Module["dynCall_vii"](index, a1, a2)
        } catch (e) {
            if (typeof e !== "number" && e !== "longjmp") throw e;
            Module["setThrew"](1, 0)
        }
    }

    function invoke_iiiiiii(index, a1, a2, a3, a4, a5, a6) {
        try {
            return Module["dynCall_iiiiiii"](index, a1, a2, a3, a4, a5, a6)
        } catch (e) {
            if (typeof e !== "number" && e !== "longjmp") throw e;
            Module["setThrew"](1, 0)
        }
    }

    function invoke_ii(index, a1) {
        try {
            return Module["dynCall_ii"](index, a1)
        } catch (e) {
            if (typeof e !== "number" && e !== "longjmp") throw e;
            Module["setThrew"](1, 0)
        }
    }

    function invoke_viii(index, a1, a2, a3) {
        try {
            Module["dynCall_viii"](index, a1, a2, a3)
        } catch (e) {
            if (typeof e !== "number" && e !== "longjmp") throw e;
            Module["setThrew"](1, 0)
        }
    }

    function invoke_v(index) {
        try {
            Module["dynCall_v"](index)
        } catch (e) {
            if (typeof e !== "number" && e !== "longjmp") throw e;
            Module["setThrew"](1, 0)
        }
    }

    function invoke_iiiiiiiii(index, a1, a2, a3, a4, a5, a6, a7, a8) {
        try {
            return Module["dynCall_iiiiiiiii"](index, a1, a2, a3, a4, a5, a6, a7, a8)
        } catch (e) {
            if (typeof e !== "number" && e !== "longjmp") throw e;
            Module["setThrew"](1, 0)
        }
    }

    function invoke_iiiii(index, a1, a2, a3, a4) {
        try {
            return Module["dynCall_iiiii"](index, a1, a2, a3, a4)
        } catch (e) {
            if (typeof e !== "number" && e !== "longjmp") throw e;
            Module["setThrew"](1, 0)
        }
    }

    function invoke_idd(index, a1, a2) {
        try {
            return Module["dynCall_idd"](index, a1, a2)
        } catch (e) {
            if (typeof e !== "number" && e !== "longjmp") throw e;
            Module["setThrew"](1, 0)
        }
    }

    function invoke_viiii(index, a1, a2, a3, a4) {
        try {
            Module["dynCall_viiii"](index, a1, a2, a3, a4)
        } catch (e) {
            if (typeof e !== "number" && e !== "longjmp") throw e;
            Module["setThrew"](1, 0)
        }
    }

    function invoke_iii(index, a1, a2) {
        try {
            return Module["dynCall_iii"](index, a1, a2)
        } catch (e) {
            if (typeof e !== "number" && e !== "longjmp") throw e;
            Module["setThrew"](1, 0)
        }
    }

    function invoke_iiiiid(index, a1, a2, a3, a4, a5) {
        try {
            return Module["dynCall_iiiiid"](index, a1, a2, a3, a4, a5)
        } catch (e) {
            if (typeof e !== "number" && e !== "longjmp") throw e;
            Module["setThrew"](1, 0)
        }
    }

    function invoke_iiiiii(index, a1, a2, a3, a4, a5) {
        try {
            return Module["dynCall_iiiiii"](index, a1, a2, a3, a4, a5)
        } catch (e) {
            if (typeof e !== "number" && e !== "longjmp") throw e;
            Module["setThrew"](1, 0)
        }
    }
    Module.asmGlobalArg = {
        "Math": Math,
        "Int8Array": Int8Array,
        "Int16Array": Int16Array,
        "Int32Array": Int32Array,
        "Uint8Array": Uint8Array,
        "Uint16Array": Uint16Array,
        "Uint32Array": Uint32Array,
        "Float32Array": Float32Array,
        "Float64Array": Float64Array,
        "NaN": NaN,
        "Infinity": Infinity
    };
    Module.asmLibraryArg = {
        "abort": abort,
        "assert": assert,
        "enlargeMemory": enlargeMemory,
        "getTotalMemory": getTotalMemory,
        "abortOnCannotGrowMemory": abortOnCannotGrowMemory,
        "invoke_iiiiiiii": invoke_iiiiiiii,
        "invoke_iiii": invoke_iiii,
        "invoke_viiiiii": invoke_viiiiii,
        "invoke_viiiii": invoke_viiiii,
        "invoke_dii": invoke_dii,
        "invoke_iiiiiid": invoke_iiiiiid,
        "invoke_vi": invoke_vi,
        "invoke_vii": invoke_vii,
        "invoke_iiiiiii": invoke_iiiiiii,
        "invoke_ii": invoke_ii,
        "invoke_viii": invoke_viii,
        "invoke_v": invoke_v,
        "invoke_iiiiiiiii": invoke_iiiiiiiii,
        "invoke_iiiii": invoke_iiiii,
        "invoke_idd": invoke_idd,
        "invoke_viiii": invoke_viiii,
        "invoke_iii": invoke_iii,
        "invoke_iiiiid": invoke_iiiiid,
        "invoke_iiiiii": invoke_iiiiii,
        "_44ec023f": _44ec023f,
        "_37ef5551": _37ef5551,
        "_7cb8bf61": _7cb8bf61,
        "_1da92d65": _1da92d65,
        "_5b160692": _5b160692,
        "_5d18fdfc": _5d18fdfc,
        "_11e81c19": _11e81c19,
        "_817d1bb": _817d1bb,
        "_1fed7088": _1fed7088,
        "_73d4934f": _73d4934f,
        "_6ba99a3a": _6ba99a3a,
        "_3aa20c9f": _3aa20c9f,
        "_6d9039e0": _6d9039e0,
        "_e0a36e1": _e0a36e1,
        "_73b3f4dc": _73b3f4dc,
        "_6fd429bf": _6fd429bf,
        "_4849b562": _4849b562,
        "_4f107009": _4f107009,
        "_7ca91a67": _7ca91a67,
        "_466ffc59": _466ffc59,
        "_54f47a97": _54f47a97,
        "_3b9db1a9": _3b9db1a9,
        "_2eb15c7f": _2eb15c7f,
        "_202cac45": _202cac45,
        "_80a051c": _80a051c,
        "_2428ca3": _2428ca3,
        "_1b63264b": _1b63264b,
        "_5fbc6ade": _5fbc6ade,
        "_38fbe96a": _38fbe96a,
        "_7d7f372d": _7d7f372d,
        "_32d930c9": _32d930c9,
        "_4a49bc82": _4a49bc82,
        "_670f6e34": _670f6e34,
        "_1d677ada": _1d677ada,
        "_5904ba26": _5904ba26,
        "_4d41badc": _4d41badc,
        "_92581b2": _92581b2,
        "_4d537a01": _4d537a01,
        "_4cdce971": _4cdce971,
        "_3d345949": _3d345949,
        "_53a98c0a": _53a98c0a,
        "_4c6c9f1f": _4c6c9f1f,
        "_6a007f73": _6a007f73,
        "_281d7ec1": _281d7ec1,
        "_6e7b7c8": _6e7b7c8,
        "_9154e1b": _9154e1b,
        "_8a564b8": _8a564b8,
        "_f19f455": _f19f455,
        "DYNAMICTOP_PTR": DYNAMICTOP_PTR,
        "tempDoublePtr": tempDoublePtr,
        "ABORT": ABORT,
        "STACKTOP": STACKTOP,
        "STACK_MAX": STACK_MAX,
        "cttz_i8": cttz_i8
    };
    var asm = Module["asm"](Module.asmGlobalArg, Module.asmLibraryArg, buffer);
    Module["asm"] = asm;
    var _6c12216c = Module["_6c12216c"] = (function() {
        return Module["asm"]["_6c12216c"].apply(null, arguments)
    });
    var _9df57d5 = Module["_9df57d5"] = (function() {
        return Module["asm"]["_9df57d5"].apply(null, arguments)
    });
    var _2b32e53b = Module["_2b32e53b"] = (function() {
        return Module["asm"]["_2b32e53b"].apply(null, arguments)
    });
    var _bfc8fd4 = Module["_bfc8fd4"] = (function() {
        return Module["asm"]["_bfc8fd4"].apply(null, arguments)
    });
    var _e159e68 = Module["_e159e68"] = (function() {
        return Module["asm"]["_e159e68"].apply(null, arguments)
    });
    var stackSave = Module["stackSave"] = (function() {
        return Module["asm"]["stackSave"].apply(null, arguments)
    });
    var getTempRet0 = Module["getTempRet0"] = (function() {
        return Module["asm"]["getTempRet0"].apply(null, arguments)
    });
    var _57403805 = Module["_57403805"] = (function() {
        return Module["asm"]["_57403805"].apply(null, arguments)
    });
    var _79a796e5 = Module["_79a796e5"] = (function() {
        return Module["asm"]["_79a796e5"].apply(null, arguments)
    });
    var _16c61acd = Module["_16c61acd"] = (function() {
        return Module["asm"]["_16c61acd"].apply(null, arguments)
    });
    var setThrew = Module["setThrew"] = (function() {
        return Module["asm"]["setThrew"].apply(null, arguments)
    });
    var _1065663f = Module["_1065663f"] = (function() {
        return Module["asm"]["_1065663f"].apply(null, arguments)
    });
    var _6d876630 = Module["_6d876630"] = (function() {
        return Module["asm"]["_6d876630"].apply(null, arguments)
    });
    var _664e9249 = Module["_664e9249"] = (function() {
        return Module["asm"]["_664e9249"].apply(null, arguments)
    });
    var _3e2469d8 = Module["_3e2469d8"] = (function() {
        return Module["asm"]["_3e2469d8"].apply(null, arguments)
    });
    var _4d17c882 = Module["_4d17c882"] = (function() {
        return Module["asm"]["_4d17c882"].apply(null, arguments)
    });
    var setTempRet0 = Module["setTempRet0"] = (function() {
        return Module["asm"]["setTempRet0"].apply(null, arguments)
    });
    var _1bf64a7 = Module["_1bf64a7"] = (function() {
        return Module["asm"]["_1bf64a7"].apply(null, arguments)
    });
    var _10a6caac = Module["_10a6caac"] = (function() {
        return Module["asm"]["_10a6caac"].apply(null, arguments)
    });
    var _63a0450c = Module["_63a0450c"] = (function() {
        return Module["asm"]["_63a0450c"].apply(null, arguments)
    });
    var _2a665258 = Module["_2a665258"] = (function() {
        return Module["asm"]["_2a665258"].apply(null, arguments)
    });
    var _17863535 = Module["_17863535"] = (function() {
        return Module["asm"]["_17863535"].apply(null, arguments)
    });
    var stackAlloc = Module["stackAlloc"] = (function() {
        return Module["asm"]["stackAlloc"].apply(null, arguments)
    });
    var _74c2f7c3 = Module["_74c2f7c3"] = (function() {
        return Module["asm"]["_74c2f7c3"].apply(null, arguments)
    });
    var _4db4edc0 = Module["_4db4edc0"] = (function() {
        return Module["asm"]["_4db4edc0"].apply(null, arguments)
    });
    var _7a61d285 = Module["_7a61d285"] = (function() {
        return Module["asm"]["_7a61d285"].apply(null, arguments)
    });
    var _644e12b6 = Module["_644e12b6"] = (function() {
        return Module["asm"]["_644e12b6"].apply(null, arguments)
    });
    var _22910c01 = Module["_22910c01"] = (function() {
        return Module["asm"]["_22910c01"].apply(null, arguments)
    });
    var _64c247ec = Module["_64c247ec"] = (function() {
        return Module["asm"]["_64c247ec"].apply(null, arguments)
    });
    var _1a8dc8b8 = Module["_1a8dc8b8"] = (function() {
        return Module["asm"]["_1a8dc8b8"].apply(null, arguments)
    });
    var _1e8531c8 = Module["_1e8531c8"] = (function() {
        return Module["asm"]["_1e8531c8"].apply(null, arguments)
    });
    var _5d28bd2a = Module["_5d28bd2a"] = (function() {
        return Module["asm"]["_5d28bd2a"].apply(null, arguments)
    });
    var _6d900685 = Module["_6d900685"] = (function() {
        return Module["asm"]["_6d900685"].apply(null, arguments)
    });
    var _57391b49 = Module["_57391b49"] = (function() {
        return Module["asm"]["_57391b49"].apply(null, arguments)
    });
    var _764d2878 = Module["_764d2878"] = (function() {
        return Module["asm"]["_764d2878"].apply(null, arguments)
    });
    var _6830ed67 = Module["_6830ed67"] = (function() {
        return Module["asm"]["_6830ed67"].apply(null, arguments)
    });
    var _3ac8e1f5 = Module["_3ac8e1f5"] = (function() {
        return Module["asm"]["_3ac8e1f5"].apply(null, arguments)
    });
    var _7c1fc741 = Module["_7c1fc741"] = (function() {
        return Module["asm"]["_7c1fc741"].apply(null, arguments)
    });
    var _3e9bd0f2 = Module["_3e9bd0f2"] = (function() {
        return Module["asm"]["_3e9bd0f2"].apply(null, arguments)
    });
    var _2a1a33e5 = Module["_2a1a33e5"] = (function() {
        return Module["asm"]["_2a1a33e5"].apply(null, arguments)
    });
    var runPostSets = Module["runPostSets"] = (function() {
        return Module["asm"]["runPostSets"].apply(null, arguments)
    });
    var _3ffb382d = Module["_3ffb382d"] = (function() {
        return Module["asm"]["_3ffb382d"].apply(null, arguments)
    });
    var _70538cef = Module["_70538cef"] = (function() {
        return Module["asm"]["_70538cef"].apply(null, arguments)
    });
    var _1722603f = Module["_1722603f"] = (function() {
        return Module["asm"]["_1722603f"].apply(null, arguments)
    });
    var _52132039 = Module["_52132039"] = (function() {
        return Module["asm"]["_52132039"].apply(null, arguments)
    });
    var stackRestore = Module["stackRestore"] = (function() {
        return Module["asm"]["stackRestore"].apply(null, arguments)
    });
    var _4528ffe0 = Module["_4528ffe0"] = (function() {
        return Module["asm"]["_4528ffe0"].apply(null, arguments)
    });
    var establishStackSpace = Module["establishStackSpace"] = (function() {
        return Module["asm"]["establishStackSpace"].apply(null, arguments)
    });
    var _1aa2133b = Module["_1aa2133b"] = (function() {
        return Module["asm"]["_1aa2133b"].apply(null, arguments)
    });
    var _6ec285a3 = Module["_6ec285a3"] = (function() {
        return Module["asm"]["_6ec285a3"].apply(null, arguments)
    });
    var _2f061953 = Module["_2f061953"] = (function() {
        return Module["asm"]["_2f061953"].apply(null, arguments)
    });
    var dynCall_iiiiiiii = Module["dynCall_iiiiiiii"] = (function() {
        return Module["asm"]["dynCall_iiiiiiii"].apply(null, arguments)
    });
    var dynCall_iiii = Module["dynCall_iiii"] = (function() {
        return Module["asm"]["dynCall_iiii"].apply(null, arguments)
    });
    var dynCall_viiiiii = Module["dynCall_viiiiii"] = (function() {
        return Module["asm"]["dynCall_viiiiii"].apply(null, arguments)
    });
    var dynCall_viiiii = Module["dynCall_viiiii"] = (function() {
        return Module["asm"]["dynCall_viiiii"].apply(null, arguments)
    });
    var dynCall_dii = Module["dynCall_dii"] = (function() {
        return Module["asm"]["dynCall_dii"].apply(null, arguments)
    });
    var dynCall_iiiiiid = Module["dynCall_iiiiiid"] = (function() {
        return Module["asm"]["dynCall_iiiiiid"].apply(null, arguments)
    });
    var dynCall_vi = Module["dynCall_vi"] = (function() {
        return Module["asm"]["dynCall_vi"].apply(null, arguments)
    });
    var dynCall_vii = Module["dynCall_vii"] = (function() {
        return Module["asm"]["dynCall_vii"].apply(null, arguments)
    });
    var dynCall_iiiiiii = Module["dynCall_iiiiiii"] = (function() {
        return Module["asm"]["dynCall_iiiiiii"].apply(null, arguments)
    });
    var dynCall_ii = Module["dynCall_ii"] = (function() {
        return Module["asm"]["dynCall_ii"].apply(null, arguments)
    });
    var dynCall_viii = Module["dynCall_viii"] = (function() {
        return Module["asm"]["dynCall_viii"].apply(null, arguments)
    });
    var dynCall_v = Module["dynCall_v"] = (function() {
        return Module["asm"]["dynCall_v"].apply(null, arguments)
    });
    var dynCall_iiiiiiiii = Module["dynCall_iiiiiiiii"] = (function() {
        return Module["asm"]["dynCall_iiiiiiiii"].apply(null, arguments)
    });
    var dynCall_iiiii = Module["dynCall_iiiii"] = (function() {
        return Module["asm"]["dynCall_iiiii"].apply(null, arguments)
    });
    var dynCall_idd = Module["dynCall_idd"] = (function() {
        return Module["asm"]["dynCall_idd"].apply(null, arguments)
    });
    var dynCall_viiii = Module["dynCall_viiii"] = (function() {
        return Module["asm"]["dynCall_viiii"].apply(null, arguments)
    });
    var dynCall_iii = Module["dynCall_iii"] = (function() {
        return Module["asm"]["dynCall_iii"].apply(null, arguments)
    });
    var dynCall_iiiiid = Module["dynCall_iiiiid"] = (function() {
        return Module["asm"]["dynCall_iiiiid"].apply(null, arguments)
    });
    var dynCall_iiiiii = Module["dynCall_iiiiii"] = (function() {
        return Module["asm"]["dynCall_iiiiii"].apply(null, arguments)
    });
    Runtime.stackAlloc = Module["stackAlloc"];
    Runtime.stackSave = Module["stackSave"];
    Runtime.stackRestore = Module["stackRestore"];
    Runtime.establishStackSpace = Module["establishStackSpace"];
    Runtime.setTempRet0 = Module["setTempRet0"];
    Runtime.getTempRet0 = Module["getTempRet0"];
    Module["asm"] = asm;
    if (memoryInitializer) {
        if (typeof Module["locateFile"] === "function") {
            memoryInitializer = Module["locateFile"](memoryInitializer)
        } else if (Module["memoryInitializerPrefixURL"]) {
            memoryInitializer = Module["memoryInitializerPrefixURL"] + memoryInitializer
        }
        if (ENVIRONMENT_IS_NODE || ENVIRONMENT_IS_SHELL) {
            var data = Module["readBinary"](memoryInitializer);
            HEAPU8.set(data, Runtime.GLOBAL_BASE)
        } else {
            addRunDependency("memory initializer");
            var applyMemoryInitializer = (function(data) {
                if (data.byteLength) data = new Uint8Array(data);
                HEAPU8.set(data, Runtime.GLOBAL_BASE);
                if (Module["memoryInitializerRequest"]) delete Module["memoryInitializerRequest"].response;
                removeRunDependency("memory initializer")
            });

            function doBrowserLoad() {
                Module["readAsync"](memoryInitializer, applyMemoryInitializer, (function() {
                    throw "could not load memory initializer " + memoryInitializer
                }))
            }
            if (Module["memoryInitializerRequest"]) {
                function useRequest() {
                    var request = Module["memoryInitializerRequest"];
                    if (request.status !== 200 && request.status !== 0) {
                        console.warn("a problem seems to have happened with Module.memoryInitializerRequest,  status: " + request.status + " , retrying " + memoryInitializer);
                        doBrowserLoad();
                        return
                    }
                    applyMemoryInitializer(request.response)
                }
                if (Module["memoryInitializerRequest"].response) {
                    setTimeout(useRequest, 0)
                } else {
                    Module["memoryInitializerRequest"].addEventListener("load", useRequest)
                }
            } else {
                doBrowserLoad()
            }
        }
    }

    function ExitStatus(status) {
        this.name = "ExitStatus";
        this.message = "Program terminated with exit(" + status + ")";
        this.status = status
    }
    ExitStatus.prototype = new Error;
    ExitStatus.prototype.constructor = ExitStatus;
    var initialStackTop;
    var preloadStartTime = null;
    var calledMain = false;
    dependenciesFulfilled = function runCaller() {
        if (!Module["calledRun"]) run();
        if (!Module["calledRun"]) dependenciesFulfilled = runCaller
    };
    Module["callMain"] = Module.callMain = function callMain(args) {
        args = args || [];
        ensureInitRuntime();
        var argc = args.length + 1;

        function pad() {
            for (var i = 0; i < 4 - 1; i++) {
                argv.push(0)
            }
        }
        var argv = [allocate(intArrayFromString(Module["thisProgram"]), "i8", ALLOC_NORMAL)];
        pad();
        for (var i = 0; i < argc - 1; i = i + 1) {
            argv.push(allocate(intArrayFromString(args[i]), "i8", ALLOC_NORMAL));
            pad()
        }
        argv.push(0);
        argv = allocate(argv, "i32", ALLOC_NORMAL);
        try {
            var ret = Module["_e159e68"](argc, argv, 0);
            exit(ret, true)
        } catch (e) {
            if (e instanceof ExitStatus) {
                return
            } else if (e == "SimulateInfiniteLoop") {
                Module["noExitRuntime"] = true;
                return
            } else {
                var toLog = e;
                if (e && typeof e === "object" && e.stack) {
                    toLog = [e, e.stack]
                }
                Module.printErr("exception thrown: " + toLog);
                Module["quit"](1, e)
            }
        } finally {
            calledMain = true
        }
    };

    function run(args) {
        args = args || Module["arguments"];
        if (preloadStartTime === null) preloadStartTime = Date.now();
        if (runDependencies > 0) {
            return
        }
        preRun();
        if (runDependencies > 0) return;
        if (Module["calledRun"]) return;

        function doRun() {
            if (Module["calledRun"]) return;
            Module["calledRun"] = true;
            if (ABORT) return;
            ensureInitRuntime();
            preMain();
            if (Module["onRuntimeInitialized"]) Module["onRuntimeInitialized"]();
            if (Module["_e159e68"] && shouldRunNow) Module["callMain"](args);
            postRun()
        }
        if (Module["setStatus"]) {
            Module["setStatus"]("Running...");
            setTimeout((function() {
                setTimeout((function() {
                    Module["setStatus"]("")
                }), 1);
                doRun()
            }), 1)
        } else {
            doRun()
        }
    }
    Module["run"] = Module.run = run;

    function exit(status, implicit) {
        if (implicit && Module["noExitRuntime"]) {
            return
        }
        if (Module["noExitRuntime"]) {} else {
            ABORT = true;
            EXITSTATUS = status;
            STACKTOP = initialStackTop;
            exitRuntime();
            if (Module["onExit"]) Module["onExit"](status)
        }
        if (ENVIRONMENT_IS_NODE) {
            process["exit"](status)
        }
        Module["quit"](status, new ExitStatus(status))
    }
    Module["exit"] = Module.exit = exit;
    var abortDecorators = [];

    function abort(what) {
        if (what !== undefined) {
            Module.print(what);
            Module.printErr(what);
            what = JSON.stringify(what)
        } else {
            what = ""
        }
        ABORT = true;
        EXITSTATUS = 1;
        var extra = "\nIf this abort() is unexpected,  build with -s ASSERTIONS=1 which can give more information.";
        var output = "abort(" + what + ") at " + stackTrace() + extra;
        if (abortDecorators) {
            abortDecorators.forEach((function(decorator) {
                output = decorator(output, what)
            }))
        }
        throw output
    }
    Module["abort"] = Module.abort = abort;
    if (Module["preInit"]) {
        if (typeof Module["preInit"] == "function") Module["preInit"] = [Module["preInit"]];
        while (Module["preInit"].length > 0) {
            Module["preInit"].pop()()
        }
    }
    var shouldRunNow = true;
    if (Module["noInitialRun"]) {
        shouldRunNow = false
    }
    Module["noExitRuntime"] = true;
    run()
}))(window)