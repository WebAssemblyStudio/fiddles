import * as gulp from "gulp";
import { Service, project } from "@wasm/studio-utils";

gulp.task("build", async () => {
  const data0 = await Service.assembleWat(project.getFile("src/shared0.wat").getData());
  const outWasm0 = project.newFile("out/shared0.wasm", "wasm", true);
  outWasm0.setData(data0);
  const data1 = await Service.assembleWat(project.getFile("src/shared1.wat").getData());
  const outWasm1 = project.newFile("out/shared1.wasm", "wasm", true);
  outWasm0.setData(data1);  
});

gulp.task("default", ["build"], async () => {});
