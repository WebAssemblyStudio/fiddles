import * as gulp from "gulp";
import { Service, Arc, project, logLn } from "@wasm/studio-utils";

gulp.task("build", async () => {
    const options = { debug: true, cargo: true };
    const data = await Service.compileFiles([
        project.getFile("src/lib.rs"),
        project.getFile("src/ext.rs"),
        project.getFile("Cargo.toml")            
    ], "rust", "wasm", options);
    const outWasm = project.newFile("out/lib.wasm", "wasm", true);
    outWasm.setData(data["a.wasm"]);
});

gulp.task("default", ["build"], async () => {});
