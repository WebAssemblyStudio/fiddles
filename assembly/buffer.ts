let _freeId = new Array<f32>(512);
let _id: f32 = 1;

enum Command{
  callback,
  end
}

enum CommandCb {

}

enum CommandArgs{
  
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

export class CommandBuffer { 
  /**
   * 唯一ID
   * Unique ID
   *
   * @type {f64}
   * @memberof CommandBuffer
   */
    public id: f32 = CommandBuffer.gID();

    /**
     * 写入池
     * buffer 
     * 
     * ---command---args---id----command---args---id~~~
     *
     * @private
     * @type {Float32Array}
     * @memberof CommandBuffer
     */
    private _buffer: Float32Array;

    /**
     * 指针偏移
     * pointer offset
     *
     * @private
     * @type {f32}
     * @memberof CommandBuffer
     */
    private _offset: f32;

    /**
     * 
     *
     * @private
     * @static
     * @type {CommandBuffer}
     * @memberof CommandBuffer
     */
    private _assemblebuffer: CommandBuffer;

    /**
     * 命令缓冲
     * command buffer
     * 
     * @author 
     * @memberof CommandBuffer
     */
    public constructor() {
        this._buffer = new Float32Array(64);
        this._offset = 0;
    }

    /**
     * 写入一个值
     *
     * @author 
     * @param {CommandArgs} arg0
     * @memberof CommandBuffer
     */
    public write(arg0: f32): void {
        unchecked(this._buffer[<i32>this._offset] = <f32>arg0);
        ++this._offset;
    }

    /**
     * 写入不需要参数的命令
     * Write commands that do not require parameters
     * 
     * @author 
     * @param {Command} command
     * @memberof CommandBuffer
     */
    @inline
    public writeZeroArgsCommand(command: Command): void {
        this.write(<f32>command * <f32>10 + <f32>0);
        this.write(this.id);
    }

    /**
     * 写入需要一个参数的命令
     * write a command that requires one argument
     *
     * @author 
     * @template T
     * @param {Command} command
     * @param {T} arg0
     * @memberof CommandBuffer
     */
    @inline
    public writeOneArgsCommand(command: Command, arg0: CommandArgs): void {
        this.write(<f32>command * <f32>10 + <f32>1);
        this.write(<f32>arg0);
        this.write(this.id);
    }

    /**
     * 写入需要二个参数的命令
     * write a command that requires two argument
     * 
     * @author 
     * @param {Command} command
     * @param {CommandArgs} arg0
     * @param {CommandArgs} arg1
     * @memberof CommandBuffer
     */
    @inline
    public writeTwoArgsCommand(command: Command, arg0: CommandArgs, arg1: CommandArgs): void {
        this.write(<f32>command * <f32>10 + <f32>2);
        this.write(<f32>arg0);
        this.write(<f32>arg1);
        this.write(<f32>this.id);
    }

    /**
     * 写入需要三个参数的命令
     * write a command that requires three argument
     *
     * @author 
     * @param {Command} command
     * @param {CommandArgs} arg0
     * @param {CommandArgs} arg1
     * @param {CommandArgs} arg2
     * @memberof CommandBuffer
     */
    @inline
    public writeThreeArgsCommand(command: Command, arg0: CommandArgs, arg1: CommandArgs, arg2: CommandArgs): void {
        this.write(<f32>command * <f32>10 + <f32>3);
        this.write(<f32>arg0);
        this.write(<f32>arg1);
        this.write(<f32>arg2);
        this.write(<f32>this.id);
    }

    /**
     * 写入需要四个参数的命令
     * write a command that requires four argument
     *
     * @author 
     * @param {Command} command
     * @param {f32} arg0
     * @param {f32} arg1
     * @param {f32} arg2
     * @param {f32} arg3
     * @memberof CommandBuffer
     */
    @inline
    public writeFourArgsCommand(command: Command, arg0: f32, arg1: f32, arg2: f32, arg3: f32): void {
        this.write(<f32>command * <f32>10 + <f32>4);
        this.write(<f32>arg0);
        this.write(<f32>arg1);
        this.write(<f32>arg2);
        this.write(<f32>arg3);
        this.write(<f32>this.id);
    }

    /**
     * 写入一个不需要参数的回调
     * write a callback do not require parameters
     *
     * @author 
     * @param {CallbackZeroArgs} callback
     * @memberof CommandBuffer
     */
    @inline
    public writeZeroCallback(cb: Callback): void {
        this.write(<f32>Command.callback);
        this.write(<f32>cb.type);
        this.write(<f32>changetype<usize>(cb));
        this.write(<f32>0);
        this.write(<f32>this.id);
    }

    /**
     * 提交缓冲区的命令
     * commit buffer command
     *
     * @author 
     * @memberof CommandBuffer
     */
    @inline
    public commit(): void {
        this.write(<f32>Command.end);
        this.write(<f32>this._offset);
        commit(this._buffer);
        this.reset();
    }

    /**
     * 
     * 将已经提交的命令缓冲区重置
     * reset the already committed command buffer
     * 
     * @author 
     * @private
     * @memberof CommandBuffer
     */
    @inline
    private reset(): void {
        this._offset = 0;
    }

    /**
     * 销毁
     *
     * @author 
     * @memberof CommandBuffer
     */
    @inline
    public destory(): void {
        CommandBuffer.sID(this.id);
    }

    /**
     * 获得一个唯一的命令缓冲组装器
     * get a unique command buffer assembler
     * 
     * @author 
     * @static
     * @returns {CommandBuffer}
     * @memberof CommandBuffer
     */
    @inline
    public assembleBuffer(): CommandBuffer {
        if (!this._assemblebuffer) {
            this._assemblebuffer = new CommandBuffer();
        }

        return this._assemblebuffer;
    }

    /**
     * 获取一个唯一个ID
     * get a unique ID
     *
     * @author 
     * @static
     * @returns {f32}
     * @memberof CommandBuffer
     */
    @inline
    public static gID(): f32 {
        return _freeId.pop() || _id++;
    }

    /**
     * 回收一个唯一ID
     * recycle a unique ID
     *
     * @author 
     * @static
     * @returns {f32}
     * @memberof CommandBuffer
     */
    @inline
    public static sID(id: f32): void {
        _freeId.push(id);
    }
};