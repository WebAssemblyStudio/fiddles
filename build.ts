import * as gulp from "gulp";
import { Service, project } from "@wasm/studio-utils";

gulp.task("build", async () => {
  const options = { debug: true, cargo: true };
  const project_files = [
    project.getFile("src/lib.rs"),
    project.getFile("Cargo.toml"),
  ];
  const data = await Service.compileFiles(project_files, "rust", "wasm", options);
  const outWasm = project.newFile("out/main_bg.wasm", "wasm", true);
  outWasm.setData(data.wasm);
  const outJs = project.newFile("out/main.js", "javascript", true);
  outJs.setData(data.wasmBindgenJs);
});

gulp.task("default", ["build"], async () => {});
