import * as gulp from "gulp";
import { Service, project } from "@wasm/studio-utils";

gulp.task("build", async () => {
  const data = await Service.compileFile(project.getFile("src/lmdif.cpp"), "cpp", "wasm", "-g -O3");
  const outWasm = project.newFile("out/lmdif.wasm", "wasm", true);
  outWasm.setData(data);
});

gulp.task("default", ["build"], async () => {});
