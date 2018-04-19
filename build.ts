import * as gulp from "gulp";
import { Service, project } from "@wasm/studio-utils";

gulp.task("build_rt", async () => {
  const data = await Service.assembleWat(project.getFile("src/main.wat").getData());
  const outWasm = project.newFile("out/main.wasm", "wasm", true);
  outWasm.setData(data);
});

gulp.task("build_main", async () => {
  const data = await Service.assembleWat(project.getFile("src/rt.wat").getData());
  const outWasm = project.newFile("out/rt.wasm", "wasm", true);
  outWasm.setData(data);
});

gulp.task("build", ["build_rt", "build_main"], async () => {});

gulp.task("default", ["build"], async () => {});
