import * as gulp from "gulp";
import { Service, project } from "@wasm/studio-utils";

gulp.task("build", async () => {
  const data = await Service.assembleWat(project.getFile("src/success.wat").getData());
  const outWasm = project.newFile("out/success.wasm", "wasm", true);
  outWasm.setData(data);

  const data2 = await Service.assembleWat(project.getFile("src/failure.wat").getData());
  const outWasm2 = project.newFile("out/failure.wasm", "wasm", true);
  outWasm.setData(data);
});

gulp.task("default", ["build"], async () => {});
