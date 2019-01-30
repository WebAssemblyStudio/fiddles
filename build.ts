import * as gulp from "gulp";
import { Service, project } from "@wasm/studio-utils";

gulp.task("build", async () => {
  const data = await Service.assembleWat(project.getFile("src/main.wat").getData());
  const outWasm = project.newFile("out/main.wasm", "wasm", true);
  outWasm.setData(data);

  const data1 = await Service.assembleWat(project.getFile("src/main1.wat").getData());
  const outWasm1 = project.newFile("out/main1.wasm", "wasm", true);
  outWasm1.setData(data1);
});

gulp.task("default", ["build"], async () => {});
