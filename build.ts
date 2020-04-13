import * as gulp from "gulp";
import { Service, project } from "@wasm/studio-utils";

gulp.task("build", async () => {
  const options = { lto: true, opt_level: 's', debug: true, cargo: false };

  const data = await Service.compileFilesWithBindings([project.getFile("src/lib.rs")], "rust", "wasm", options);

  const outWasm = project.newFile("out/main_bg.wasm", "wasm", true);
  outWasm.setData(data.wasm);
  const outJs = project.newFile("out/main.js", "js", true);
  outJs.setData(data.wasmBindgenJs);
});

gulp.task("default", ["build"], async () => {});
