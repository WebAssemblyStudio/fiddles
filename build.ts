import * as gulp from "gulp";
import { Service, project } from "@wasm/studio-utils";

gulp.task("build", async () => {
  const data = await Service.compileFile(project.getFile("src/main.rs"), "rust", "wasm");

  const outWasm = project.newFile("out/main_bg.wasm", "wasm", true);
  outWasm.setData(data.wasm);
  const outJs = project.newFile("out/main.js", "js", true);
  outJs.setData(data.wasmBindgenJs);
});

gulp.task("default", ["build"], async () => {});
