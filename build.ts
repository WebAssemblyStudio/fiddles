import * as gulp from "gulp";
import { Service, project } from "@wasm/studio-utils";

gulp.task("build", async () => {
  // Optimize for small builds for now
  const options = { lto: true, opt_level: "z", debug: false, debug_assertions: false, overflow_checks : false, panic: 'unwind', incremental :false, codegen_units : 1, rpath : false };
  const libSrc = project.getFile("src/lib.rs");
  const data = await Service.compileFileWithBindings(libSrc, "rust", "wasm", options);

  const outWasm = project.newFile("out/main_bg.wasm", "wasm", true);
  outWasm.setData(data.wasm);
  const outJs = project.newFile("out/main.js", "javascript", true);
  outJs.setData(data.wasmBindgenJs);
});

gulp.task("default", ["build"], async () => {});
