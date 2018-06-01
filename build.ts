import * as gulp from "gulp";
import { Service, project } from "@wasm/studio-utils";

gulp.task("build", async () => {
  const options = { cargo: true, debug: true };
  const data = await Service.compileFiles([
    project.getFile("src/main.rs"),
    project.getFile("Cargo.toml")
  ], "rust", "wasm", options);
  const outWasm = project.newFile("out/main.wasm", "wasm", true);
  outWasm.setData(data["a.wasm"]);
});

gulp.task("default", ["build"], async () => {});
