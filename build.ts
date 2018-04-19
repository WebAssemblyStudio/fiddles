import * as gulp from "gulp";
import { Service, project } from "@wasm/studio-utils";

gulp.task("build_rt", async () => {
  const wat = project.getFile("src/rt.wat").getData();
  await Service.lazyLoad("lib/libwabt.js");
  console.log(Module);
  const module = wabt.parseWat("test.wat", wat);
  module.TOTAL_MEMORY = 52428800000;
  console.log(module);
  module.resolveNames();
  module.validate();
  const binary = module.toBinary({ log: true, write_debug_names: true });
  const data = binary.buffer;
  const outWasm = project.newFile("out/main.wasm", "wasm", true);
  outWasm.setData(data);
});

gulp.task("build_main", async () => {
  const data = await Service.assembleWat(
    project.getFile("src/main.wat").getData()
  );
  const outWasm = project.newFile("out/rt.wasm", "wasm", true);
  outWasm.setData(data);
});

gulp.task("build", ["build_rt", "build_main"], async () => {});

gulp.task("default", ["build"], async () => {});
