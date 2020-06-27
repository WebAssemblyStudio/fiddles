declare function log(v: i32): void;

type Family = i32;

abstract class Component {
  static counter: Family = 0;

  static family(): Family {
    return this.counter++;
  }
}

class AbcComponent extends Component {}
class CdeComponent extends Component {}

export function test(): void {
  log(AbcComponent.family());
  log(CdeComponent.family());
}
