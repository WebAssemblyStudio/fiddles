const canvas = document.body.appendChild(document.createElement('canvas'))
const ctx = canvas.getContext('2d')

function runApp() {
	const { init, get_img_addr, get_img_len, gen_img, tick, add_ant, wasm } =
		wasm_bindgen

	const WIDTH = 256
	const HEIGHT = 256
	const TICKS_PER_INTERVAL = 10
	const INTERVAL = 1

	init(WIDTH, HEIGHT)

	add_ant(Math.floor(WIDTH / 2), Math.floor(HEIGHT / 2), 0, 0)
	add_ant(Math.floor(WIDTH / 3), Math.floor(HEIGHT / 2), 1, 1)
	add_ant(Math.floor(WIDTH / 2), Math.floor(HEIGHT / 3), 2, 2)

	function draw() {
		gen_img()
		const arr = new Uint8ClampedArray(
			wasm.memory.buffer,
			get_img_addr(),
			get_img_len()
		)
		const img = new ImageData(arr, WIDTH, HEIGHT)
		canvas.width = WIDTH
		canvas.height = HEIGHT
		ctx.putImageData(img, 0, 0)

		requestAnimationFrame(draw)
	}
	draw()

	setInterval(() => {
		for (let i = 0; i < TICKS_PER_INTERVAL; i++) tick()
	}, INTERVAL)
}

wasm_bindgen('../out/main_bg.wasm').then(runApp).catch(console.error)
