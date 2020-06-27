declare function log(v: i32): void;

type Family = u32;

let global_id: u32 = 0;

class Component<U> {
  static count: Family = 0;
  static init: bool = false;

  static family(): Family {
    if (!this.init) {
      this.count = global_id++;
      this.init = true;
    }
    return this.count;
  }
}

class AbcComponent extends Component<AbcComponent> {}
class CdeComponent extends Component<CdeComponent> {}

export function test(): void {
  log(AbcComponent.family());
  log(CdeComponent.family());

  log(AbcComponent.family());
  log(CdeComponent.family());
}
