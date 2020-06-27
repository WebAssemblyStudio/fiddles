declare function log(v: i32): void;

type Family = i32;
let global_id: i32 = 0;

class Component {
  static count: Family = -1;

  static family(): Family {
    if (this.count < 0) {
      this.count = global_id++;
    }
    return this.count;
  }
}

class AbcComponent extends Component {}
class CdeComponent extends Component {}

export function test(): void {
  log(AbcComponent.family());
  log(CdeComponent.family());

  log(AbcComponent.family());
  log(CdeComponent.family());
}
