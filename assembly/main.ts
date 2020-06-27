declare function log(v: i32): void;

type Family = i32;

abstract class Component {
  static family<C extends Component>(): Family {
    return idof<C>() as Family;
  }
}

class AbcComponent extends Component {}
class CdeComponent extends Component {}

export function test(): void {
  log(AbcComponent.family<AbcComponent>());
  log(CdeComponent.family<CdeComponent>());
}
