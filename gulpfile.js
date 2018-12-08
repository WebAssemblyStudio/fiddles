const gulp = require("gulp");

gulp.task("build", callback => {
  const asc = require("assemblyscript/bin/asc");
  asc.main([
    "assembly/main.ts",
    "--baseDir", "assembly",
    "--binaryFile", "../out/main.wasm",
    "-O3",
    "--importMemory",
    "--use", "Math=JSMath",
    "--sourceMap",
    "--measure"
  ], callback);
});

gulp.task("default", ["build"]);

gulp.task("project:load", () => { // WebAssembly Studio only
  const utils = require("@wasm/studio-utils");
  eval(utils.project.getFile("setup.js").getData());
});
