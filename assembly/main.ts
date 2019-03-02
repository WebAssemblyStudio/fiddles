export class Game {

  constructor() {
    this.prepare();
  }

  prepare = () : void => {
    this.prepareContainer();
  }

  private container;

  prepareContainer() {
    this.container = "123";
  }

}