import * as gulp from "gulp";
import { Service, project } from "@wasm/studio-utils";

gulp.task("build", async () => {
  const data = await Service.assembleWat(project.getFile("src/main.wat").getData());
  const outWasm = project.newFile("out/main.wasm", "wasm", true);
  outWasm.setData(data);
  const data2 = await Service.assembleWat(project.getFile("src/lazy.wat").getData());
  const outWasm2 = project.newFile("out/lazy.wasm", "wasm", true);
  outWasm2.setData(data2);
});

gulp.task("default", ["build"], async () => {});
