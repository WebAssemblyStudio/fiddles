let x = '../out/main.wasm';

let instance = null;
const memoryStates = new WeakMap;

function syscall(instance, n, args) {
	switch (n) {
		default: {
			console.warn("Syscall %i NYI.", n);
			break;
		}
		case /* brk */ 45: {
			return 0;
		}
		case /* writev */ 146: {
			return instance.exports.writev_c(args[0], args[1], args[2]);
		}
		case /* mmap2 */ 192: {
			debugger;
			const memory = instance.exports.memory;
			const memoryState = memoryStates.get(instance);
			const requested = args[1];
			if (!memoryState) {
				memoryState = {
					object: memory,
					currentPosition: memory.buffer.byteLength,
				};
				memoryStates.set(instance, memoryState);
			}
			const cur = memoryState.currentPosition;
			if (cur + requested > memory.buffer.byteLength) {
				const need = Math.ceil((cur + requested - memory.buffer.byteLength) / 65536);
				memory.grow(need);
			}
			memoryState.currentPosition += requested;
			return cur;
		}
	}
}

let s = "";
fetch(x).then(response =>
	response.arrayBuffer()
).then(bytes =>
	WebAssembly.instantiate(bytes, {
		env: {
			/* __syscall(n, ...extra) {
				return syscall(instance, n, extra);
			},*/
			__syscall(n) { return syscall(instance, n, []); },
			__syscall1(n, a) { return syscall(instance, n, [a]); },
			__syscall2(n, a, b) { return syscall(instance, n, [a, b]); },
			__syscall3(n, a, b, c) { return syscall(instance, n, [a, b, c]); },
			__syscall4(n, a, b, c, d) { return syscall(instance, n, [a, b, c, d]); },
			__syscall5(n, a, b, c, d, e) { return syscall(instance, n, [a, b, c, d, e]); },
			__syscall6(n, a, b, c, d, e, f) { return syscall(instance, n, [a, b, c, d, e, f]); },
			putc_js(c) {
				c = String.fromCharCode(c);
				if (c == "\n") {
					console.log(s);
					s = "";
				} else {
					s += c;
				}
			}
		}
	})
).then(results => {
	({ instance } = results);
	document.querySelector("#container").textContent = instance.exports.main();
}).catch(console.error);