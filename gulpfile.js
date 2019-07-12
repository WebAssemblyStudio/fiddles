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


  asc.main([
    "main.ts",
    "--baseDir", "assembly",
    "--binaryFile", "../out/main.wasm",
    "--textFile", "../out/main.wat",
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

  function ascDone(res) {
    logLn("ascDone res:", res)
    
    mergeWats();
  }

  function mergeWats() {

    require(["wabt"], wabtdep => {
      console.log('setup.js loaded wabt:', wabtdep);
      logLn('wabts:', wabt)
      var wabt = wabtdep();
      logLn("wabt activated:", wabt);

      const utils = require("@wasm/studio-utils");
      logLn("loading src/keccak-funcs.wat...");
      const keccakWat = utils.project.getFile("src/keccak-funcs.wat").getData();
      //logLn("loaded keccak wat:", keccakWat);
      const keccakLines = keccakWat.split("\n")

      logLn("loading out/main.wat...");
      const mainWat = utils.project.getFile("out/main.wat").getData();
      //logLn("loaded main wat:", mainWat);
      var mainLines = mainWat.split("\n");
      logLn("main wat line count:", mainLines.length);
      // mainLines.length is 915
      // mainLines[0] is `(module`
      // mainLines[913] is is the closing paren `)`
      // mainLines[914] is an empty line ``
      // closing paren is second to last line

      var closing_paren_ix = mainLines.length - 2;

      mainLines.splice(closing_paren_ix, 0, ...keccakLines);

      logLn('mainLines with keccak inserted:', mainLines.length);

      // now delete the import statement
      //  (import "watimports" "$keccak" (func $main/keccak (type $t1)))
      // currently on line 12 (mainLines[11])
      // TODO: find line instead of using hardcoded

      logLn("searching for import statement to delete...");

      var foundImport = false;
      for (var i=0; i<20; i++) {
        logLn(mainLines[i]);
        if (mainLines[i] === '(import "watimports" "$keccak" (func $main/keccak (type $t1)))') {
          logLn("found import statement!! deleting it...");
          mainLines.splice(i, 1);
          foundImport = true;
          break;
        }
      }

      if (!foundImport) {
        logLn("ERROR!! Couldn't find keccak import statement! wat parsing will probably fail.");
      }

      logLn('mainLines after deleting 11:', mainLines.length);

      var features = {'mutable_globals':false};
      var myModule = wabt.parseWat("main_with_keccak.wat", mainLines.join("\n"), features);
      logLn('parsed merged wat..');
      myModule.resolveNames();
      logLn('names resolved...');
      myModule.validate();
      logLn('myModule validated!!');
      var binary_result = myModule.toBinary({ write_debug_names: true });

      var wasm_output = utils.project.newFile("out/main_with_keccak.wasm", "wasm");
      wasm_output.setData(binary_result.buffer);

      logLn('done merging wat codes.');
    });
  
  }


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
