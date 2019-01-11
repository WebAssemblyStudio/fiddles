import "allocator/arena";

declare function log(val: u32): void;

type GLenum = u32;

class CommandBuffer {}

export class WebGLRenderingContext extends CommandBuffer {
   public readonly ACTIVE_ATTRIBUTES: GLenum = 0x8B89;
   public readonly ACTIVE_TEXTURE: GLenum = 0x84E0;
   public readonly COLOR_BUFFER_BIT: GLenum = 0x4000;

   initialize(): void {}
}

export class WebGL2RenderingContext extends WebGLRenderingContext {
  initialize(): void {}
}

// test ordinal instantiation
var gl1 = new WebGL2RenderingContext();
gl1.initialize();

log(gl1.COLOR_BUFFER_BIT);
log(gl1.ACTIVE_ATTRIBUTES);
log(gl1.ACTIVE_TEXTURE);

// test generic instantiation
var gl2 = instantiate<WebGL2RenderingContext>();
gl2.initialize();

log(gl2.COLOR_BUFFER_BIT);
log(gl2.ACTIVE_ATTRIBUTES);
log(gl2.ACTIVE_TEXTURE);

