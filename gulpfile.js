const gulp = require("gulp");
/*
  Варианты исполнения:

  "--runtime", "full" (default)
    Надлежащий менеджер памяти и сборщик мусора, основанный на подсчете ссылок, 
    с экспортируемыми в хост интерфейсами времени выполнения для возможности создания управляемых объектов извне.

  "--runtime", "half"
    То же, что и полный, но без экспорта, т.е. где создание объектов извне не требуется.
    Это позволяет оптимизатору исключить ненужные части времени выполнения.

  "--runtime", "stub"
    Минималистичный менеджер памяти arena без каких-либо средств повторного освобождения памяти, но с тем же внешним интерфейсом, что и full. 
    Полезен для очень недолговечных программ или программ, почти не занимающих память, сохраняя возможность перехода на полный режим без дальнейших изменений. 
    Отсутствие сборки мусора.

  "--runtime", "none"
    То же, что и stub, но без экспорта, по тем же причинам, что и в половине случаев. 
    По сути, полностью испаряется после оптимизации.

    Более подробную информацию см: https://docs.assemblyscript.org/details/runtime
*/
gulp.task("build", callback => {
  const asc = require("assemblyscript/bin/asc");
  asc.main([
    "main.ts",
    "--baseDir", "assembly",
    "--binaryFile", "../out/main.wasm",
    "--sourceMap",
    "--measure",
    "--runtime", "stub", // Please use "incremental" if you need GC
    "-O3"                // Please use "-O3z" if you need optimize for size
  ], callback);
});

gulp.task("default", ["build"]);

// Эта задача не требуется при локальном запуске проекта. 
// Его цель - настроить компилятор AssemblyScript, когда новый проект был загружен в WebAssembly Studio.
gulp.task("project:load", () => {
  const utils = require("@wasm/studio-utils");
  utils.eval(utils.project.getFile("setup.js").getData(), {
    logLn,
    project,
    monaco,
    fileTypeForExtension,
  });
});
