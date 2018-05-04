import * as gulp from "gulp";
import { Service, project } from "@wasm/studio-utils";

const console = window.console || {
  log:()=>{}
};

gulp.task("build", async () => {
  console.log("WERK");
  const data = await Service.compileFile(project.getFile("src/main.cpp"), "cpp", "wasm", "-g -O3");
  console.log("Data Recieved");
  const outWasm = project.newFile("out/main.wasm", "wasm", true);
  outWasm.setData(data);
});

gulp.task("default", ["build"], async () => {});
