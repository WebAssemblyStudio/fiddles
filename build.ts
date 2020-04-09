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
    ], "cpp", "wasm", "-g -O3 -lc++abi-noexcept");
  const outWasm = project.newFile("src/main.wasm", "wasm", true);
  outWasm.setData(data["a.wasm"]);
  const outJS = project.newFile("src/main.js", "javascript", true);
  outJS.setData(data["a.js"]);
});

gulp.task("default", ["build"], async () => {});
