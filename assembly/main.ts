import "allocator/tlsf";
import {WebGLRenderingContext} from "./gl";
//@ts-ignore
export { memory };

//@ts-ignore
@external("log", "logi")
declare function logi(x: i32): void;

type GLsizei = u32;
type GLenum = u32;


enum CommandCb {

}

class Callback<T = CommandCb> {
  public pointer: usize;
  public type: T;

  public constructor(pointer: usize, type: T) {
    this.pointer = pointer;
    this.type = type;
  }

  public destory(): void {

  }

  public invoke(buffer: Float32Array): void {

  }
}

let gl = new WebGLRenderingContext();
logi(gl.COLOR_BUFFER_BIT);