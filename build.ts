import * as gulp from "gulp";
import { Service, project } from "@wasm/studio-utils";

gulp.task("build", async () => {
  const data = await Service.compileFiles([project.getFile("src/main.cpp")], "cpp", "wasm", "-g -O3 -std=c++2a -fcoroutines-ts");
  const outWasm = project.newFile("src/main.wasm", "wasm", true);
  outWasm.setData(data["a.wasm"]);
  const outJS = project.newFile("src/main.js", "javascript", true);
  outJS.setData(data["wasm_bindgen.js"]);
});

gulp.task("default", ["build"], async () => {});
