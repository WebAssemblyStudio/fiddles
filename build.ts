import * as gulp from "gulp";
import { Service, project } from "@wasm/studio-utils";

gulp.task("build", async () => {
  const data = await Service.compileFile(project.getFile("src/subscription/subscription.cpp"), "cpp", "wasm", "-g -O3 -I src/subscription/");
  const outWasm = project.newFile("out/subscription/subscription.wasm", "wasm", true);
  outWasm.setData(data);
});

gulp.task("default", ["build"], async () => {});
