__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "check_flag", function() { return check_flag; });
/* harmony import */ var _flag_check_bg_wasm__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! ./flag_check_bg.wasm */ "../pkg/flag_check_bg.wasm");


let cachegetUint8Memory0 = null;
function getUint8Memory0() {
    if (cachegetUint8Memory0 === null || cachegetUint8Memory0.buffer !== _flag_check_bg_wasm__WEBPACK_IMPORTED_MODULE_0__["memory"].buffer) {
        cachegetUint8Memory0 = new Uint8Array(_flag_check_bg_wasm__WEBPACK_IMPORTED_MODULE_0__["memory"].buffer);
    }
    return cachegetUint8Memory0;
}

let WASM_VECTOR_LEN = 0;

function passArray8ToWasm0(arg, malloc) {
    const ptr = malloc(arg.length * 1);
    getUint8Memory0().set(arg, ptr / 1);
    WASM_VECTOR_LEN = arg.length;
    return ptr;
}
/**
* @param {Uint8Array} flag
* @returns {boolean}
*/
function check_flag(flag) {
    var ptr0 = passArray8ToWasm0(flag, _flag_check_bg_wasm__WEBPACK_IMPORTED_MODULE_0__["__wbindgen_malloc"]);
    var len0 = WASM_VECTOR_LEN;
    var ret = _flag_check_bg_wasm__WEBPACK_IMPORTED_MODULE_0__["check_flag"](ptr0, len0);
    return ret !== 0;
}



//# sourceURL=webpack:///../pkg/flag_check_bg.js?