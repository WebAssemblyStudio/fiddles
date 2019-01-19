
declare function logStr(str: string): void;
declare function logF64(val: f64): void;

/**
 * Extend from this class to handle events from parser.
 * Default implementation traverses whole object tree and does nothing.
 */
export abstract class JSONHandler {
    setString(name: string, value: string): void {
    }

    setBoolean(name: string, value: bool): void {
    }

    setNull(name: string): void {
    }

    setInteger(name: string, value: i32): void {
    }

    pushArray(name: string): bool {
        return true;
    }

    popArray(): void {
    }

    pushObject(name: string): bool {
        return true;
    }

    popObject(): void {
    }
}

/**
 * Extend from this class to handle events from parser.
 * This implementation crashes on every unimplemented set/push method
 * to allow easier validation of input.
 */
export class ThrowingJSONHandler extends JSONHandler {
    setString(name: string, value: string): void {
       assert(false, 'Unexpected string field ' + name + ' : "' + value + '"');
    }

    setBoolean(name: string, value: bool): void {
       assert(false, 'Unexpected bool field ' + name + ' : ' + (value ? 'true' : 'false'));
    }

    setNull(name: string): void {
       assert(false, 'Unexpected null field ' + name);
    }

    setInteger(name: string, value: i32): void {
       let arr: Array<i32> = [value];
       assert(false, 'Unexpected integer field ' + name + ' : ' + arr.toString());
    }

    pushArray(name: string): bool {
        assert(false, 'Unexpected array field ' + name);
        return true;
    }

    pushObject(name: string): bool {
        assert(false, 'Unexpected object field ' + name);
        return true;
    }
}

export class DecoderState {
    readIndex: i32 = 0;
    buffer: Uint8Array = null;
    lastKey: string = null;
}

export class JSONDecoder<JSONHandlerT extends JSONHandler> {

    handler: JSONHandlerT;
    state: DecoderState;

    constructor(handler: JSONHandlerT) {
        this.handler = handler;
    }
}

export class __near_JSONHandler_Todo extends ThrowingJSONHandler {
      buffer: Uint8Array;
      decoder: JSONDecoder<__near_JSONHandler_Todo>;
}

export function __near_decode_Todo(buffer: Uint8Array, state: DecoderState): JSONDecoder<__near_JSONHandler_Todo> {
  let handler = new __near_JSONHandler_Todo();
  return new JSONDecoder<__near_JSONHandler_Todo>(handler);
}
