import * as gulp from "gulp";
import { Service, project } from "@wasm/studio-utils";

gulp.task("build", async () => {
  const options = { lto: true, opt_level: 's', debug: true };
  const data = await Service.compileFileWithBindings(project.getFile("src/main.rs"), "rust", "wasm", options);
  
  const outWasm = project.newFile("out/main.wasm", "wasm", true);
  outWasm.setData(data.wasm);
  
  const outJs = project.newFile("out/main_bindings.js", "javascript", true);
  outJs.setData(data.wasmBindgenJs);
});

gulp.task("default", ["build"], async () => {});
