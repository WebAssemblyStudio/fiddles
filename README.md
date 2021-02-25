### BUILD
Using the details in config.json, the Build function compiles your source code into a WASM binary ready for the next step (Deploy)
- `fileName` should be set to your source code file name.
- `exportFunctions` should be set to the comma-separated list of the functions you want to expose in your contract

### DEPLOY
The Deploy function creates a smart contract using the WASM binary in the previous step. In config.json:
- `fileName` should be set to your WASM file name.
- `caller` is automatically set to a random Liquid Chain address which you can change. This address will be identified as the contract owner in subsequent contract calls.

### RUN
The Run function executes your contract and shows the result in the Output console. In config.json:
- `fileName` should be set to your WASM file name.
- `runCommand` includes 2 parts separated by an empty space. The first is the function name. The second is the function args. These args are also space-separated, e.g `append 3 [1,2]`
- `caller` should be set the address you want to be identified as caller the contract execution


