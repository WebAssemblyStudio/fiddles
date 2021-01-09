import * as gulp from "gulp";
import { Service, project } from "@wasm/studio-utils";

gulp.task("build", async () => {
  // Optimize for small builds for now
  const options = { debug: true, cargo: true };
  const srcs = [project.getFile("Cargo.toml"), project.getFile("src/lib.rs")];
  const data = await Service.compileFiles(srcs, "rust", "wasm", options);

  const outWasm = project.newFile("out/lib.wasm", "wasm", false);
  outWasm.setData(data.wasm);
});

gulp.task("default", ["build"], async () => {});
