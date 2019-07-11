const gulp = require("gulp");
/*
  Runtime variants:

  "--runtime", "full" (default)
    A proper memory manager and reference-counting based garbage collector, with runtime interfaces
    being exported to the host for being able to create managed objects externally.

  "--runtime", "half"
    The same as full but without any exports, i.e. where creating objects externally is not required.
    This allows the optimizer to eliminate parts of the runtime that are not needed.

  "--runtime", "stub"
    A minimalist arena memory manager without any means of freeing up memory again, but the same external
    interface as full. Useful for very short-lived programs or programs with hardly any memory footprint,
    while keeping the option to switch to full without any further changes. No garbage collection.

  "--runtime", "none"
    The same as stub but without any exports, for the same reasons as explained in half. Essentially
    evaporates entirely after optimizations.

    For more information see: https://docs.assemblyscript.org/details/runtime
*/
gulp.task("build", callback => {
  const asc = require("assemblyscript/bin/asc");
  logLn("guild build callback:", callback)

  function ascDone(res) {
    logLn("ascDone res:", res)
    //callback(null)
  }
  asc.main([
    "main.ts",
    "--baseDir", "assembly",
    "--binaryFile", "../out/main.wasm",
    "--sourceMap",
    "--measure",
    "--runtime", "none",
    "--optimize"
  ], ascDone);

  console.log('gulp.js build task..');
  /*
  const wabt = require("wabt")();
  console.log('gulp required wabt:', wabt);
  */

  require(["wabt"], wabtdep => {
    console.log('setup.js loaded wabt:', wabtdep);
    logLn('wabts:', wabt)
    var wabt = wabtdep();
    logLn("wabt activated:", wabt);

    const utils = require("@wasm/studio-utils");
    const keccakWat = utils.project.getFile("src/keccak.wat").getData();
    //logLn("loaded keccak src:", keccakWat);

    var features = {'mutable_globals':false};
    var myModule = wabt.parseWat("keccak.wat", keccakWat, features);
    logLn('parsed wat..')
    myModule.resolveNames();
    myModule.validate();
    logLn('myModule validated!!');


    logLn('wabts');
  });
  
  /*
  console.log('gulp calling fetch..')
  fetch("../src/keccak.wat").then(response => {
    console.log('fetch got response:', response);
    return response.text();
  }).then(watfile => {
    console.log('got watfile:', watfile);
    var features = {'mutable_globals':false};
    var myModule = wabt.parseWat(FILENAME, watfile, features);
    myModule.resolveNames();

    console.log('parsed wat..')
    myModule.validate();
    console.log('myModule validated!!')
  }).catch( err => {
    console.log('caught error:', err);
  });
  */



});


gulp.task("default", ["build"]);


// This task is not required when running the project locally. Its purpose is to set up the
// AssemblyScript compiler when a new project has been loaded in WebAssembly Studio.
gulp.task("project:load", () => {
  const utils = require("@wasm/studio-utils");
  logLn('gulp project:load...')
  utils.eval(utils.project.getFile("setup.js").getData(), {
    logLn,
    project,
    monaco,
    fileTypeForExtension,
  });
});
