import * as console from 'bindings/console';

declare const null_ref: anyref;
declare const ref_table: anyref;
declare let ref_table_size: i32;

declare function table_get(table: anyref, offset: i32): anyref;
declare function table_set(table: anyref, offset: i32, value: anyref): void;
declare function table_grow(table: anyref, size: i32): i32;

/**
 * Note about this demo:
 * 
 * This demo show one way someone could use and keep anyref's inside AssemblyScript
 * by using a Wasm Table to store them and keeping the table index as a class field.
 * 
 * Because of Wasm <-> JS bridge costs, it might not actually be worth
 * having these ref_table functions in AssemblyScript. It's probably faster to
 * have them in JS and just import them, at least until AssemblyScript supports
 * the table manipulation instructions natively. I'm not sure though, haven't
 * done any scientific benchmarking.
 */


// I haven't really looked into how AssemblyScript implements Arrays, so I don't know
// whether this is the most performant data structure for the table slot GC or not.
// It probably isn't, because we could specialize things like allocation bucket size.
const freed_indices = new Array<i32>(0);
let ref_table_count: i32 = 0;

// If you use a Wasm table like this, when a index slot is "freed" by removing
// the anyref, you now have a table with holes in it: unused indices aka fragmentation.
// One way to solve is kind of like a simple form of garbage collection, where you keep
// track of indices that have been freed and reuse them when a request to store another
// value is made. That's what we do here.
function ref_table_alloc(): i32 {
    // Reclaim any older, unused slots
  if (freed_indices.length > 0) {
    return freed_indices.pop();
  } else {
    // How much we want to grow this depends on use cases but doubling is one way.
    if (ref_table_count >= ref_table_size) {
      table_grow(ref_table, ref_table_size);
      ref_table_size += ref_table_size;
    }

    const index = ref_table_count;
    ref_table_count++;
    return index;
  }
}

function ref_table_add(ref: anyref): i32 {
  const index = ref_table_alloc();
  table_set(ref_table, index, ref);

  return index;
}

function ref_table_remove(index: i32): void {
  table_set(ref_table, index, null_ref);
  freed_indices.push(index);
}

function ref_table_get(index: i32): anyref {
  return table_get(ref_table, index);
}

/**
 * A simple contrived example to show a class which stores a value in a Wasm table
 * and keeps the index of where to find it.
 */
class Example {
  valueIndex: i32;

  get_value(): anyref {
    return ref_table_get(this.valueIndex);
  }

  get value(): anyref {
    return this.get_value();
  }

  set_value(value: anyref): void {
    this.valueIndex = ref_table_add(value);
  }

  remove_value(): void {
    ref_table_remove(this.valueIndex);
  }
}

export function test(value: anyref): anyref {
  const example = new Example();

  // Adds anyref value to Wasm table.
  example.set_value(value);
  // Removes anyref from table, but now we have an unused slot.
  example.remove_value();
  // Reuses the previous slot since it's unused.
  example.set_value(value);

  // Get it locally before we remove it.
  const result = example.value;

  // There are no destructors in AS, so we need to manually make sure we cleanup
  // any storing into tables. This isn't ideal, of course.
  example.remove_value();

  return result;
}

