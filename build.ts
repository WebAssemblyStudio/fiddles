import * as gulp from "gulp";
import { Service, project } from "@wasm/studio-utils";

gulp.task("build", async () => {
  const options = { lto: true, opt_level: 's', debug: true };
  const fileNames = ["emscripten.rs", "matrix.rs", "main.rs"];
  const files = fileNames.map(fileName => project.getFile("src/webgl/" + fileName));
  const data = await Service.compileFiles(files, "rust", "wasm", options);
  const outWasm = project.newFile("out/main.wasm", "wasm", true);
  outWasm.setData(data["a.wasm"]);
});

gulp.task("default", ["build"], async () => {});
