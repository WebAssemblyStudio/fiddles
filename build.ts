import * as gulp from "gulp";
import { Service, project } from "@wasm/studio-utils";

gulp.task("build", async () => {
  const data = await Service.assembleWat(project.getFile("src/binarySearch.wat").getData());
  const outWasm = project.newFile("out/binarySearch.wasm", "wasm", true);
  outWasm.setData(data);
});

gulp.task("default", ["build"], async () => {});
