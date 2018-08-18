import * as gulp from "gulp";
import { Service, project } from "@wasm/studio-utils";

gulp.task("build", async () => {
  const data = await Service.assembleWat(project.getFile("src/main.wat").getData());
  const outWasm = project.newFile("out/main.wasm", "wasm", true);
  outWasm.setData(data);
  project.newFile('out/browserfs.js', 'js', true).setData(
    project.getFile('node_modules/browserfs/dist/browserfs.js')
  )
});

gulp.task("default", ["build"], async () => {});
