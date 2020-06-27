declare function log(v: i32): void;

type Family = i32;

abstract class Component {
  static counter: Family = 0;

  family(): Family {
    return Component.counter++;
  }
}

class AbcComponent extends Component {}
class CdeComponent extends Component {}

export function test(): void {
  log(new AbcComponent().family());
  log(new CdeComponent().family());
}
