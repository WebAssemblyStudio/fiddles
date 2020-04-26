import * as gulp from "gulp";
import { Service, project } from "@wasm/studio-utils";

gulp.task("build", async () => {
  const data = await Service.compileFiles([
    project.getFile("src/main.cpp"),
    project.getFile("include/DxCompileConfig.h"),
    project.getFile("include/DxDataType.h"),
    project.getFile("include/DxDataTypeHTML5.h"),
    project.getFile("include/DxFunctionWin.h"),
    project.getFile("include/DxLib.h"),
    ], "cpp", "wasm", "-Wall -O1 -s MAIN_MODULE=1 -s ALLOW_MEMORY_GROWTH=1 -s FULL_ES2=1");
  const outWasm = project.newFile("src/main.wasm", "wasm", true);
  outWasm.setData(data["a.wasm"]);
  const outJS = project.newFile("src/main.js", "javascript", true);
  outJS.setData(data["a.js"]);
});

gulp.task("default", ["build"], async () => {});
