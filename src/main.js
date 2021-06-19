/*
fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  const instance = results.instance;
  document.getElementById("output").textContent = instance.exports.add(1, 1);
}).catch(console.error);
*/

fetch("../src/input.wat").then(response =>
  response.text()
).then(input => {
  const map = (object, transform) => transform(object);

  const ParseError = SyntaxError;

  const ParserResult = {
    success: (matched, remaining) => { matched, remaining },
    failure: msg => new ParseError(msg),
    isFailure: result => result instanceof ParseError,
    
    map: (result, transform) => 
      isFailure(result) ? result : success(transform(result.matched), result.remaining) 
  }, { success, failure, isFailure } = ParserResult;

  const Parser = {
    map: (parser, transform) => 
      input => map(parser(input), result => success(transform(result.matched), result.remaining))
  };

  const sequence = (...parsers) => 
    (input) => parsers.reduce((result, parser) =>
      !isFailure(input = result) && !isFailure(result = parser(input)) ? result : parser(result[1]), ["", input]);

  const character = specimen => ([next, ...rest]) => 
    next === undefined ? new ParseError("No more input") :
    next !== specimen ? new ParseError(`Expected '${specimen}', received '${next}'`) :
    [next, rest];

  console.log(sequence(character("A"), character("B"))("ABC"))
});