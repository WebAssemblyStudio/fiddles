import "allocator/arena";

declare function log(val: u32): void;

type GLenum = u32;

class CommandBuffer {}

export class WebGLRenderingContext extends CommandBuffer {
   public readonly ACTIVE_ATTRIBUTES: GLenum = 0x8B89;
   public readonly ACTIVE_TEXTURE: GLenum = 0x84E0;
}

// test ordinal instantiation
var gl1 = new WebGLRenderingContext();

log(gl1.ACTIVE_ATTRIBUTES);
log(gl1.ACTIVE_TEXTURE);

// test generic instantiation
var gl2 = instantiate<WebGLRenderingContext>();

log(gl2.ACTIVE_ATTRIBUTES);
log(gl2.ACTIVE_TEXTURE);

