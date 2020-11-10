import * as gulp from "gulp";
import { Service, project } from "@wasm/studio-utils";

gulp.task("build", async () => {
  const options = { lto: true, opt_level: 3, debug: false, panic: 'abort', debug_assert: false, codegen_units: 1 };
  const data = await Service.compileFile(project.getFile("src/main.rs"), "rust", "wasm", options);
  const outWasm = project.newFile("out/main.wasm", "wasm", true);
  outWasm.setData(data);
});

gulp.task("default", ["build"], async () => {});
