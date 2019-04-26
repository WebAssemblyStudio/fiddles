const hello = require("./hello.js")
const helloJson = require("./hello.json")

@contract
class SimpleStore {
  @state value;

  @transaction setValue(value) {
    this.value = value;
  }

  getValue() {
    return this.value;
  }

  @pure hello() {
    return hello();
  }
}