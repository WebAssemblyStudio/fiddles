import * as gulp from "gulp";
import { Service, project } from "@wasm/studio-utils";

gulp.task("build", async () => {
  const data = await Service.assembleWat(project.getFile("src/main.wat").getData());
  const outWasm = project.newFile("out/main.wasm", "wasm", true);
  outWasm.setData(data);
  const data = await Service.assembleWat(project.getFile("src/i64.wat").getData());
  const outWasm = project.newFile("out/i64.wasm", "wasm", true);
  outWasm.setData(data);
});

gulp.task("default", ["build"], async () => {});
