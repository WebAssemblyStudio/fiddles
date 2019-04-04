import * as gulp from "gulp";
import { Service, project } from "@wasm/studio-utils";

gulp.task("build", async () => {
  const data = await Service.compileFile(project.getFile("src/main.c"), "c", "wasm", "-g -O3");
  const outWasm = project.newFile("out/main.wasm", "wasm", true);
  outWasm.setData(data);

  const dataChange = await Service.compileFile(project.getFile("src/change.c"), "c", "wasm", "-lm -O3");
  const outWasmchange = project.newFile("out/change.wasm", "wasm", true);
  outWasmchange.setData(dataChange);

});

gulp.task("default", ["build"], async () => {});
