import * as gulp from "gulp";
import { Service, project } from "@wasm/studio-utils";

/*
gulp.task("build", async () => {
  const options = { lto: true, opt_level: 's', debug: true };
  const data = await Service.compileFile(project.getFile("src/main.rs"), "rust", "wasm", options);
  const outWasm = project.newFile("out/main.wasm", "wasm", true);
  outWasm.setData(data);
});
*/

gulp.task("build", async () => {
  const options = { lto: true, opt_level: 's', debug: true };
  const data = await Service.compileFiles([
    project.getFile("src/main.rs"),
    project.getFile("src/ekt.rs"),
    project.getFile("src/ekt/pos.rs"),
    ], "rust", "wasm", options);
//  const outWasm = project.newFile("out/main.wasm", "wasm", true);
//  outWasm.setData(data["a.wasm"]);

  const outWasm = project.newFile("out/main.wasm", "wasm", true);
  outWasm.setData(data["a.wasm"]);
  const outJS = project.newFile("out/main.js", "javascript", true);
  outJS.setData(data["a.js"]);

});

gulp.task("default", ["build"], async () => {});
