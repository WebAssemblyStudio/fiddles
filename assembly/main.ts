import 'allocator/tlsf';

declare function log(msg: string): void

export function createCow(): Cow {
  return new Cow();
}

export function makeSound(cow: Cow): void {
  cow.makeSound();
}

class Cow {
  public makeSound(): void {
    log('moo');
  }
}
