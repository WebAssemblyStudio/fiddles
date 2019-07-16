const gulp = require("gulp");
/**
 * A bunch of magic happens below to merge functions from a wat file
 * into the assemblyscript output wasm.
 *
 * The `ImportStatementToDelete` is a config setting that you might
 * have to update if the `export declare function keccak(...)`
 * is moved between different files.
 * 
 * If you change something and AS uses a different imported name,
 * don't forget to edit the entry function in keccak-funcs.wat
 * so that it matches. see the line near the bottom:
 *   (func $keccak/keccak ;; this name needs to match what assemblyscript generates

 * 
 */

const ImportStatementToDelete = '(import "watimports" "$ethash_keccak256" (func $keccak/ethash_keccak256 (param i32 i32 i32)))';



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
  logLn('gulp.js build task..');
  const asc = require("assemblyscript/bin/asc");


  asc.main([
    "main.ts",
    "--baseDir", "assembly",
    "--binaryFile", "../out/main.wasm",
    "--textFile", "../out/main.wat",
    "--sourceMap",
    "--measure",
    "--runtime", "none",
    "--use", "abort=",
    "--memoryBase", "10000",
    "--optimize"
  ], ascDone);


  function ascDone(res) {
    logLn("ascDone res:", res)
    if (res) {
      throw new Error("AssemblyScript error!!");
    }
    
    mergeWats();
  }

  function mergeWats() {

    require(["wabt"], wabtdep => {
      logLn('gulpfile.js loaded wabt:');
      var wabt = wabtdep();

      const utils = require("@wasm/studio-utils");
      logLn("loading src/ethash_keccak_funcs.wat...");
      const keccakWat = utils.project.getFile("src/ethash_keccak_funcs.wat").getData();
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

      // insert keccak functions wat code just before the last closing paren
      mainLines.splice(closing_paren_ix, 0, ...keccakLines);

      logLn('mainLines with keccak inserted:', mainLines.length);

      // now delete the import statement
      logLn("searching for import statement to delete...");

      var foundImport = false;
      for (var i=0; i<20; i++) {
        logLn(mainLines[i]);
        if (mainLines[i].trim() === ImportStatementToDelete) {
          logLn("found import statement!! deleting it...");
          mainLines.splice(i, 1);
          foundImport = true;
          break;
        }
      }

      if (!foundImport) {
        logLn("ERROR!! Couldn't find keccak import statement! wat parsing will probably fail.");
      }

      logLn('mainLines after deleting import statement:', mainLines.length);

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
