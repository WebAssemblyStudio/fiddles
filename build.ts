import * as gulp from "gulp";
import { Service, project } from "@wasm/studio-utils";
const byteToHex = [];

for (let n = 0; n <= 0xff; ++n)
{
    const hexOctet = n.toString(16).padStart(2, "0");
    byteToHex.push(hexOctet);
}

function hex(arrayBuffer)
{
    const buff = new Uint8Array(arrayBuffer);
    const hexOctets = []; // new Array(buff.length) is even faster (preallocates necessary array size), then use hexOctets[i] instead of .push()

    for (let i = 0; i < buff.length; ++i)
        hexOctets.push(byteToHex[buff[i]]);

    return hexOctets.join("");
}
function ab2str(buf) {
  return String.fromCharCode.apply(null, new Uint16Array(buf));
}
function str2ab(str) {
  var buf = new ArrayBuffer(str.length*2); // 2 bytes for each char
  var bufView = new Uint16Array(buf);
  for (var i=0, strLen=str.length; i < strLen; i++) {
    bufView[i] = str.charCodeAt(i);
  }
  return buf;
}
gulp.task("build", async () => {
  const data = await Service.compileFile(project.getFile("src/main.cpp"), "cpp", "wasm", "-g -O3");
  const outWasm = project.newFile("out/main.wasm", "wasm", true);
  
  
  outWasm.setData(data);
  const str = hex(data)
  
  const outWasmHex = project.newFile("out/main.wasm.txt", "txt", true);
  outWasmHex.setData(str);
});

gulp.task("default", ["build"], async () => {});
