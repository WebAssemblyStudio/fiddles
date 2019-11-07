import * as gulp from "gulp";
import { Service, project } from "@wasm/studio-utils";

gulp.task("build", async () => {
  const data = await Service.compileFile(project.getFile("src/main.c"), "c", "wasm", "-g -O3 -fno-inline-small-functions");
  const outWasm = project.newFile("out/main.wasm", "wasm", true);
  outWasm.setData(data);
});

gulp.task("default", ["build"], async () => {});
