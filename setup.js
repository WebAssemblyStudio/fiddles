// This file is not required when running the project locally. Its purpose is to set up the
// AssemblyScript compiler when a new project has been loaded in WebAssembly Studio.

/***
 * As of 2019-07-13, the dist build on assemblyscript.github.io is out of date.
 * The PR for DataView.wrap() and TypedArray.wrap() was merged a couple weeks ago,
 * and we use that feature (I pushed an updated dist to cdetrio.github.io/assemblscript).
 * 
 */

require.config({
  paths: {
    "binaryen": "https://assemblyscript.github.io/binaryen.js/index",
    "assemblyscript": "https://cdetrio.github.io/assemblyscript/dist/assemblyscript",
    "assemblyscript/bin/asc": "https://cdetrio.github.io/assemblyscript/dist/asc",
    "wabt": "https://cdn.jsdelivr.net/gh/AssemblyScript/wabt.js/index",
  }
});

logLn("Loading AssemblyScript compiler ...");

require(["assemblyscript/bin/asc"], asc => {
  logLn("loading asc...");
  monaco.languages.typescript.typescriptDefaults.addExtraLib(asc.definitionFiles.assembly);
  asc.main = (main => (args, options, fn) => {
    if (typeof options === "function") {
      fn = options;
      options = undefined;
    }
    return main(args, options || {
      stdout: asc.createMemoryStream(),
      stderr: asc.createMemoryStream(logLn),
      readFile: (filename, baseDir) => {
        const file = project.getFile(baseDir + "/" + filename.replace(/^\//, ""));
        return file ? file.data : null;
      },
      writeFile: (filename, contents) => {
        const name = filename.startsWith("../") ? filename.substring(3) : filename;
        const type = fileTypeForExtension(name.substring(name.lastIndexOf(".") + 1));
        project.newFile(name, type, true).setData(contents);
      },
      listFiles: () => []
    }, fn);
  })(asc.main);
  logLn("AssemblyScript compiler is ready!");
});
