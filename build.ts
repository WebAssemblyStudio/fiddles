import * as gulp from "gulp";
import { Service, project, logLn } from "@wasm/studio-utils";

gulp.task("build", async () => {
  const config = await Service.getBuildConfig(project.getFile("config.json"));
  const data = await Service.compileFile(project.getFile(`src/${config.fileName}.c`), "c", "wasm", `--export-function ${config.exportFunctions}`);
  const outWasm = project.newFile(`out/${config.fileName}.wasm`, "wasm", true);
  const outAbi = project.newFile(`out/${config.fileName}.abi.json`, "json", true);
  outWasm.setData(data.wasm);
  outAbi.setData(data.abi);
});

gulp.task("interpret", async () => {
  const config = await Service.getBuildConfig(project.getFile("config.json"));
  const contractAddress = await Service.getContractAddress(project.getFile("deployMap.json"), config.fileName);
  const data = await Service.interpretFile(
    project.getFile(`out/${config.fileName}.wasm`), 
    project.getFile(`out/${config.fileName}.abi.json`),
    config.runCommand,
    config.caller,
    contractAddress
  );
  logLn(data);

  // const outWasm = project.newFile("out/main.wasm", "wasm", true);
  // outWasm.setData(data);
});
gulp.task("deploy", async () => {
  const config = await Service.getBuildConfig(project.getFile("config.json"));
  const data = await Service.deployFile(
    project.getFile(`out/${config.fileName}.wasm`), 
    project.getFile(`out/${config.fileName}.abi.json`),
    config.caller
  );
  await Service.setContractAddress(project.getFile("deployMap.json"), config.fileName, data.result)
  logLn(data.result);
});

gulp.task("default", ["build"], async () => {});
