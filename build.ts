import * as gulp from "gulp";
import { Service, project } from "@wasm/studio-utils";

gulp.task("build", async () => {
  project.newFile("out/main.wasm", "wasm", true).setData(
    await Service.assembleWat(project.getFile("src/main.wat").getData())
  );

  project.newFile("out/basis_ffi.wasm", "wasm", true).setData(
    await Service.compileFile(project.getFile("src/basis_ffi.c"), "c", "wasm", "-s LINKABLE=1")
  );
});

gulp.task("default", ["build"], async () => {});
