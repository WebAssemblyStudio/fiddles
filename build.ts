import * as gulp from "gulp";
import { Service, project } from "@wasm/studio-utils";

gulp.task("build", async () => {
  // Optimize for small builds for now
  const options = { lto: true, opt_level: 's', debug: true, cargo: false };

  const sources = [project.getFile("src/lib.rs"), project.getFile("src/ext.rs"), project.getFile("src/random.rs")];
  const data = await Service.compileFilesWithBindings(sources, "rust", "wasm", options);

  const outWasm = project.newFile("out/main_bg.wasm", "wasm", true);
  outWasm.setData(data.wasm);
  const outJs = project.newFile("out/main.js", "javascript", true);
  outJs.setData(data.wasmBindgenJs);
});

gulp.task("default", ["build"], async () => {});
