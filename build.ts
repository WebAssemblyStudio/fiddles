import * as gulp from "gulp";
import { Service, project } from "@wasm/studio-utils";

gulp.task("build", async () => {
  const data1 = await Service.compileFile(project.getFile("src/core.c"), "c", "wasm", "-g -O3");
  const outWasm1 = project.newFile("out/core.wasm", "wasm", true);
  outWasm1.setData(data1);
  const data2 = await Service.compileFile(project.getFile("src/decorator.c"), "c", "wasm", "-g -O3");
  const outWasm2 = project.newFile("out/decorator.wasm", "wasm", true);
  outWasm2.setData(data2);
});

gulp.task("default", ["build"], async () => {});
