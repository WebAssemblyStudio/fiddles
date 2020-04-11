import * as gulp from "gulp";
import { Service, project } from "@wasm/studio-utils";

gulp.task("build", async () => {
  // Optimize for small builds for now
  const options = { lto: true, opt_level: 's', debug: true, cargo: true };

    const data = await Service.compileFiles([
        project.getFile("src/lib.rs"),
        project.getFile("src/ext.rs"),
        project.getFile("Cargo.toml")            
    ], "rust", "wasm", options);
    const outWasm = project.newFile("out/main_bg.wasm", "wasm", true);
    outWasm.setData(data["a.wasm"]);


  // const libSrc = project.getFile("src/lib.rs");
  // const data = await Service.compileFileWithBindings(libSrc, "rust", "wasm", options);

  // const outWasm = project.newFile("out/main_bg.wasm", "wasm", true);
  // outWasm.setData(data.wasm);
  const outJs = project.newFile("out/main.js", "javascript", true);
  outJs.setData(data.wasmBindgenJs);
});

gulp.task("default", ["build"], async () => {});
