import * as gulp from "gulp";
import { Service, project } from "@wasm/studio-utils";

const buildFile = async (file: string) => {
  const data = await Service.assembleWat(project.getFile(`src/${file}.wat`).getData());
  const outWasm = project.newFile(`out/${file}.wasm`, "wasm", true);
  outWasm.setData(data);
}

gulp.task("build", async () => {
  await buildFile("main")
  await buildFile("memory")
  await buildFile("factorial_loop")
});

gulp.task("default", ["build"], async () => {});