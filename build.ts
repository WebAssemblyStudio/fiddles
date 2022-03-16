import * as gulp from "gulp";
import { Service, project } from "@wasm/studio-utils";

gulp.task("build", async () => {
  const data = await Service.compileFiles([
    project.getFile("src/main.cpp"),
    ], "cpp", "wasm", "-Wall -std=c++2a -O2 -include-pch /include/OpenSiv3Dv0.6/Siv3D.O2.pch -I/include/OpenSiv3Dv0.6/ -I/include/OpenSiv3Dv0.6/ThirdParty/ -s SIDE_MODULE=1 -D_XM_NO_INTRINSICS_");
  const outWasm = project.newFile("src/main.wasm", "wasm", true);
  outWasm.setData(data["a.wasm"]);
});

gulp.task("default", ["build"], async () => {});

gulp.task("project:load", async () => {
  logLn("Downloading OpenSiv3D for Web Files...");

  await Promise.all([ 
    (async () => {
      const siv3DWasmFile = project.newFile("src/Siv3D.wasm", "wasm", true);
      const siv3DWasm = await (await fetch("https://siv3d-assets.kamenokosoft.com/lib/v6/Siv3D.wasm")).arrayBuffer();
      siv3DWasmFile.setData(siv3DWasm);
    })(),
    (async () => {
      const siv3DDataFile = project.newFile("src/Siv3D.data", "data", true);
      const siv3DData = await (await fetch("https://siv3d-assets.kamenokosoft.com/lib/v6/Siv3D.data")).arrayBuffer();
      siv3DDataFile.setData(siv3DData);
    })(),
    (async () => {
      const siv3DJSFile = project.newFile("src/Siv3D.js", "javascript", true);
      const siv3DJS = await (await fetch("https://siv3d-assets.kamenokosoft.com/lib/v6/Siv3D.js")).text();
      siv3DJSFile.setData(siv3DJS);
    })()

  ]);

  logLn("Successfully Downloaded OpenSiv3D for Web Files");
});
