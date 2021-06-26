const $container = document.getElementById("container");
const print = msg => $container.textContent = msg.toString();

const bind = (environment, bindings) => Object.assign(Object.create(environment), bindings);

const global = Object.assign({
  isSymbol: value => value && value.constructor === Symbol,
  isAtom: value => !Array.isArray(value) && !(value instanceof Map)
}, {
  quote: expression => expression,
  atom: expression => (expression = global.evaluate(expression), isAtom
});
