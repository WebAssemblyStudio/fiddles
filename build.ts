import * as gulp from "gulp";
import { Service, project } from "@wasm/studio-utils";

gulp.task("build", async () => {
  const data = await Service.compileFile(project.getFile("src/main.c"), "c", "wasm", "-g -O3");
  const outWasm = project.newFile("out/main.wasm", "wasm", true);
  outWasm.setData(data);

  const outCompactHTML = project.newFile("out/compact.html", "html", true);

  const mainHTML = project.getFile("src/main.html").data;
  const mainJS = project.getFile("src/main.js").data;

  const outputHTML = outCompactHTML.setData(mainHTML.replaceAll("<script src=\"./main.js\">", "<script>" + mainJS));

  outCompactHTML.setData(outputHTML);

});

gulp.task("default", ["build"], async () => {});
