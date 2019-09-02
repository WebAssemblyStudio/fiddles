WebAssembly.instantiateStreaming(fetch("../out/main.wasm"),
{
	main: {},
	env:
	{
		abort(_msg, _file, line, column)
		{
			console.error("abort called at main.ts:" + line + ":" + column);
		}
	},
}).then(result =>
{
	const exports = result.instance.exports;

	console.time("u32");
	exports.computeMandelbrotU32();
	console.timeEnd("u32");

	console.time("f32");
	exports.computeMandelbrotF32();
	console.timeEnd("f32");

  return;
}).catch(console.error);