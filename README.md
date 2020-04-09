# Flower-Coords finder
This program searches for positions of a certain configurations of flowers.
The program is writen in WebAssembly to speed thing up.
Each pixel on the canvas represents a `chunk` (`10000x10000` area)
There are `30 000 000 x 30 000 000` positions to check, and it takes around `1 second/chunk`, that's around 1 year of calculation time.
## How to use
1. Look in videos for flower positions.
  1. Select a block in the video to use as relative origin for your coordinate system and select X and Z axis.
  2. Write down the coordinates of the flower relative to your origin and the position on the block relative to your chosen X and Z axis. (see table below for more info)
2. Add flowers programaticaly by adding: `manager.addFlower(position_on_block,x,z)` in `main.js`.
3. Select area in wich you want to search for flowers: `manager.multipleChunkTester(x_start,x_end,z_start,z_end)`. 
  1. For example `manager.multipleChunkTester(0,2,0,2);` searches in a `20000x20000` area in the 4 possible orientations.
4. Chunks are marked in red if no such configuration is found.
5. Chunks are marked in green if no such configuration is found.
6. Coordinates of your chosen origin are displayed below the canvas if this happens.
## Remarks
Since WebGL doesn support the `XOR` opperation on integers, WebAssembly is used instead.
## Files
- `main.html`
- `main.js` add flower configuration here
- `main.wat` not in use
- `Manager.js` Manager class to manage chunk calculating
- `WorkerWrapper.js` communication with worker.js
- `worker.js` js webworker one can activate a timer in this file, time is displayed in javascript console (https://developer.mozilla.org/en-US/docs/Web/API/Console/timeEnd).
- `f-small100000.wasm` WebAssembly file, chunksize is `100000x100000`, use `size=300`, large chunks (faster)
- `f-small10000.wasm` WebAssembly file, chunksize is `10000x10000`, use `size=3000`, default
- `f-small1000.wasm` WebAssembly file, chunksize is `1000x1000`, use `size=30000`, mainly for testing
## Table
|     |     |     |
|-----|-----|-----|
|     | 2   | 3   |
| x ↑ | 0   | 1   |
|     | z → |     |