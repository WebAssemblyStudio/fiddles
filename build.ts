import * as gulp from "gulp";
import { Service, project } from "@wasm/studio-utils";

gulp.task("build", async () => {
  // Optimize for small builds for now
  const options = { lto: true, opt_level: 's', debug: true };
  const data = await Service.compileFile(project.getFile("src/lib.rs"), "rust", "wasm", options);

  // We don't really care about JS ouptut, we just want to look at the compile WAT...
  const outWasm = project.newFile("out/main_bg.wasm", "wasm", true);
  outWasm.setData(data.wasm);
});

gulp.task("default", ["build"], async () => {});
