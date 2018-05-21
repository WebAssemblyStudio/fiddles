import "allocator/tlsf";
import { HEADER_SIZE } from "internal/arraybuffer";

const QUESTION_MARK: u8 = 63;

/**
 * Entrypoint for the eos contract
 *
 */
export function apply(account: u64, action: u64, code: u64): void {
        print("Hello, World!");
}


function print(msg: string): void{
  env.prints(UTF16LEtoLatin1Ptr(msg));
}

export namespace env {
        /**
         * Eos environment function to print a utf-8 encoded string, identified by its pointer, to the console.
         * AssemblyScript strings are encoded in utf-16le so we first convert these to latin.
         *
         */
        declare function prints(pointer: usize): void;
}

/**
 * Converts an UTF16 string to latin1.
 * All unicode characters up to code U+00FF (end of latin1 extension) are allowed, if the string contains a character out of this range, it is replaced with a question mark.
 *
 */
export function UTF16LEtoLatin1Ptr(str: string): usize {
        var output = new Array<u8>(str.length + 1);
        for (let i : i32 = 0, len: i32 = str.length; i < len; i++) {
                let code = str.codePointAt(i);
                output[i] = code >= 0xFF ? QUESTION_MARK : <u8>code;

        }
        return changetype<usize>(output.buffer_) + HEADER_SIZE;
}