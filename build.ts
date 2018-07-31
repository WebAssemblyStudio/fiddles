import * as gulp from "gulp";
import { Service, project } from "@wasm/studio-utils";

gulp.task("build", async () => {
  const main = await Service.compileFile(project.getFile("src/main.cpp"), "cpp", "wasm", "-g -Os");
  const malloc = await Service.compileFile(project.getFile("src/malloc.c"), "cpp", "wasm", "-g -Os");
  project.newFile("out/main.wasm", "wasm", true).setData(main);
  project.newFile("out/malloc.wasm", "wasm", true).setData(malloc);
});

gulp.task("default", ["build"], async () => {});
