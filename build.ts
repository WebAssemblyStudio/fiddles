import * as gulp from "gulp";
import { Service, project } from "@wasm/studio-utils";

gulp.task("build", async () => {
  const data = await Service.assembleWat(project.getFile("src/thinning.wat").getData());
  const outWasm = project.newFile("out/thinning.wasm", "wasm", true);
  outWasm.setData(data);
});

gulp.task("default", ["build"], async () => {});
