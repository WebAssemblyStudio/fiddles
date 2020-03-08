// WebAssembly Studio only
require.config({
  paths: {
    "binaryen": "https://cdn.jsdelivr.net/npm/binaryen@nightly/index",
    "assemblyscript": "https://cdn.jsdelivr.net/npm/assemblyscript@nightly/dist/assemblyscript",
    "assemblyscript/bin/asc": "https://cdn.jsdelivr.net/npm/assemblyscript@nightly/dist/asc",
  }
});
logLn("Loading AssemblyScript compiler ...");
require(["assemblyscript/bin/asc"], asc => {
  monaco.languages.typescript.typescriptDefaults.addExtraLib(asc.definitionFiles.assembly);
  asc.main = (main => (args, options, fn) => {
    if (typeof options === "function") {
      fn = options;
      options = undefined;
    }
    return main(args, options || {
      stdout: asc.createMemoryStream(),
      stderr: asc.createMemoryStream(logLn),
      readFile: (filename) => {
        const file = project.getFile(filename.replace(/^\//, ""));
        return file ? file.data : null;
      },
      writeFile: (filename, contents) => {
        const name = filename.startsWith("/") ? filename.substring(1) : filename;
        const type = fileTypeForExtension(name.substring(name.lastIndexOf(".") + 1));
        project.newFile(name, type, true).setData(contents);
      },
      listFiles: (dirname) => []
    }, fn);
  })(asc.main);
  logLn("AssemblyScript compiler is ready!");
});
