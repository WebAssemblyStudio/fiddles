const gulp = require('gulp');

gulp.task('build', callback => {
  const asc = require('assemblyscript/bin/asc');
  asc.main(
    [
      'main.ts',
      '--baseDir',
      'assembly',
      '--binaryFile',
      '../out/main.wasm',
      '--sourceMap',
      '--importMemory',
      '--optimize',
      '--measure'
    ],
    callback
  );
});

gulp.task('default', ['build']);