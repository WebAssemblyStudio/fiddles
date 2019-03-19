export class Method {
  name: string;
}

export function getMethod(name: string) : Method {
  var method = new Method();
  method.name = name;
  return method;
}

export class Action {
  static attach<T>(mth: Method, data: T):void  {

  }
}


export class Method1 {
  name: string;
}

export function getMethod1(name: string) : Method1 {
  var method = new Method1();
  method.name = name;
  return method;
}

export class Action1 {
  static attach<T>(mth: Method1, data: T):void  {

  }
}