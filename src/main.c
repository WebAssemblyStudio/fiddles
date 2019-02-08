#define WASM_EXPORT __attribute__((visibility("default")))

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>

#define STACK_BUFFER 16384

// Checks whether the stack is overflowing
static bool stack_check(void);

// The address of the top of the stack when we first saw it
// This approximates a pointer to the bottom of the stack, but
// may not necessarily _be_ the exact bottom. This is set by
// the entry point of the application
static void *stack_initial = NULL;
// Pointer to the end of the stack
static uintptr_t stack_max = (uintptr_t)NULL;
// The current stack pointer
static uintptr_t stack_ptr_val = (uintptr_t)NULL;
// The amount of stack remaining
static ptrdiff_t stack_left = 0;

// Maximum stack size of 248k
// This limit is arbitrary, but is what works for me under Node.js when compiled with emscripten
static size_t stack_limit = 1024 * 248 * 1;

static bool stack_check(void) {
  // Get the address of the top of the stack
  stack_ptr_val = (uintptr_t)__builtin_frame_address(0); // could also use alloca(0)
  
  // The check fails if we have no stack remaining
  // Subtraction is used because the stack grows downwards
  return (stack_ptr_val - stack_max - STACK_BUFFER) <= 0;
}

#define MAX_DEPTH 50000

static int depth;
static int trampoline;

int a(int val);
int b(int val);

int a(int val) {
    // Perform stack check and only recurse if we have stack
    if (stack_check()) {
        trampoline = 1;
        return val;
    } else {
        depth += 1;
        return b(val); 
    }
}

int b(int val) {
    int val2;
    if (depth < MAX_DEPTH) {
        // Keeping recursing, but again only if we have stack
        val2 = val + 1;
        if (stack_check()) {
            trampoline = 1;
            return val2;
        }
        return a(val2);
    } else {
        return val;
    }
}

WASM_EXPORT
int main() {
    stack_initial = __builtin_frame_address(0); // could also use alloca(0)
    stack_max = (uintptr_t)stack_initial - stack_limit;

    depth = 0;
    trampoline = 0;

    int val = 0;

    while (true) {
        val = a(val);
        // This flag helps us distinguish between a return to reset the stack vs
        // a return because we're done. Not how you'd probably do this generally,
        // but this is just to demonstrate the basic mechanism
        if (trampoline == 1) {
            trampoline = 0;
            continue;
        }
        break;
    }

    return 0;
}