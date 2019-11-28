let wasmModule;
let referenceTimestamp = Date.now();
WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at" + line + ":" + column);
    }
  },
  Date: {
    now: () => Date.now() - referenceTimestamp
  },
  main: {
    ConsoleLog(item1, item2, item3) {
      console.log("[Logged from WASM] -- ", item1, item2, item3);
    },
    CompareCharCode(charCode, index) {
      let wasmByteMemoryArray = new Int32Array(wasmModule.instance.exports.memory.buffer);
      console.log("[Logged from WASM] -- ", charCode, index, charCode == wasmByteMemoryArray[index], wasmByteMemoryArray[index], String.fromCharCode(wasmByteMemoryArray[index]));
    }
  },
}).then(_wasmModule => {
  wasmModule = _wasmModule;
  function fa(e) {
    console.log("Entered fa() in JS -- ", Date.now() - referenceTimestamp);
    e += "\x3d";
    let wasmByteMemoryArray = new Int32Array(wasmModule.instance.exports.memory.buffer);
    let i = 0;
    let indexToE = i;
    wasmByteMemoryArray[i++] = e.length;
    for (let j = 0; j < e.length; j++) {
      wasmByteMemoryArray[i++] = e.charCodeAt(j);
    }
    wasmByteMemoryArray[i++] = "\0".charCodeAt(0);
    let indexToDocumentCookie = i;
    let documentCookie = "br_user=eyJiaW8iOm51bGwsImNvdW50cnkiOiJVUyIsImRlZmF1bHRfdGFncyI6WzIyLDIzLDE4LDE5LDE2LDIwXSwiZmlyc3RfbmFtZSI6bnVsbCwiaWQiOm51bGwsImlzX2JyX3ZlcmlmaWVkIjpmYWxzZSwibGFzdF9uYW1lIjpudWxsLCJwaG90b19wYXRoIjpudWxsLCJwcm9maWxlX2lkIjpudWxsLCJ0YWdzIjpbXSwidGl0bGUiOm51bGwsInR5cGUiOiJBbm9ueW1vdXMiLCJ1cGRhdGVkX2F0IjpudWxsLCJ1c2VybmFtZSI6bnVsbH0=; country_code=USA; portmeirion_id=e7c10790-5d95-44cf-933c-56e3d07e09b1; br_user_type=Anonymous; _cb_ls=1; _cb=B16PjdftoJ4CjNBRY; _cb_svref=null; utag_main=v_id:016ea5a1866c0067e0589776e39403069001f06100868$_sn:1$_se:6$_ss:0$_st:1574738667659$ses_id:1574736856685%3Bexp-session$_pn:2%3Bexp-session; _chartbeat2=.1574736858501.1574736867867.1.1C456BPcSb7CQukV6S01u1CwvuQ0.2";
    console.log("documentCookie.length -- ", documentCookie.length)
    wasmByteMemoryArray[i++] = documentCookie.length;
    for (let j = 0; j < documentCookie.length; j++) {
      wasmByteMemoryArray[i++] = documentCookie.charCodeAt(j);
    }
    wasmByteMemoryArray[i++] = "\0".charCodeAt(0);
    console.log("Handing over to fa() in WASM -- ", Date.now() - referenceTimestamp, indexToE, indexToDocumentCookie);
    let indexToReturnString = wasmModule.instance.exports.fa(indexToE, indexToDocumentCookie, Date.now() - referenceTimestamp);
    console.log("Taking back control from fa() in WASM -- ", Date.now() - referenceTimestamp, indexToReturnString);
    // for (let j = 0, k = indexToDocumentCookie; j < documentCookie.length; j++) {
    //   // console.log("Comparing", wasmByteMemoryArray[k++] || 0, "and", documentCookie.charCodeAt(j));
    // }
    let returnString = "";
    let returnStringLength = wasmByteMemoryArray[indexToReturnString++];
    console.log("Length of return string -- ", 0);
    // for (let j = 0; j < returnStringLength; j++) {
    //   returnString += String.fromCharCode(wasmByteMemoryArray[indexToReturnString++]);
    // }
    console.log("Returning from fa() in JS -- ", Date.now() - referenceTimestamp);
    return returnString || null;
  }
  fa("OptanonConsent");
  // fa("OptanonConsent");
}).catch(console.error);
