import * as gulp from "gulp";
import { Service, project } from "@wasm/studio-utils";

gulp.task("buildMain", async () => {
  const data = await Service.compileFile(project.getFile("src/main.c"), "c", "wasm", "-g -O3");
  const outWasm = project.newFile("out/main.wasm", "wasm", true);
  outWasm.setData(data);
});


gulp.task("build", async () => {
  const data = await Service.compileFile(project.getFile("src/mandelbrot.c"), "c", "wasm", "-g -O3");
  const outWasm = project.newFile("out/mandelbrot.wasm", "wasm", true);
  outWasm.setData(data);
});

gulp.task("default", ["buildMandelbrot"], async () => {});
