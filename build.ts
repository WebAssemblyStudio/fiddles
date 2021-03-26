import * as gulp from "gulp";
import { Service, project } from "@wasm/studio-utils";

gulp.task("build", async () => {
  const data = await Service.compileFiles([
    project.getFile("src/main.cpp")
    ], "cpp", "wasm", "-std=c++17 -Wall -O2 -include-pch /include/DxLib/DxLib.O2.pch -I/include/DxLib -s SIDE_MODULE=1 -s ALLOW_MEMORY_GROWTH=1 -s FULL_ES2=1");
  const outWasm = project.newFile("src/main.wasm", "wasm", true);
  outWasm.setData(data["a.wasm"]);
});

gulp.task("default", ["build"], async () => {});
