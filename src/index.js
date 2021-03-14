
//__webpack_require__.r(__webpack_exports__);
/* harmony import */ //var wasm_flag_check__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! wasm-flag-check */ "../pkg/flag_check.js");

window.onload = () => {
    document.getElementById("flag_form").onsubmit = () => {
        const guess = document.getElementById("flag").value;
        /*
        if(wasm_flag_check__WEBPACK_IMPORTED_MODULE_0__["check_flag"](guess.split('').map(a => a.charCodeAt(0)))) {
            alert("You got the flag!");
        }else{
            alert("try again!");
        }
        */
            alert("try again!");

        return false;
    };
}

//# sourceURL=webpack:///./index.js?