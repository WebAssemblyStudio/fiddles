import { func1 } from './func1';

// START RESOURCES --
class Resource {

}

class Table extends Resource {

  
}
// END RESOURCES   --



class EventABC {
  constructor(public rawEvent: string) {}
}


export function main(rawEvent: string): void {
  // START SHIM -- Need to come up with a standard way of decoding the event into a managed class 
  const event = new EventABC(rawEvent);
  // END SHIM   --

  //
}