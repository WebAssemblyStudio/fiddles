const normalize = (pattern, quantifier = "") => 
  new RegExp(`(?${pattern instanceof RegExp ? pattern.source : pattern})${quantifier}`); 

const either = (...regexes) => normalize(regexes.map(regex => normalize(regex)).join("|"));
const concat = (...regexes) => normalize(regexes.map(regex => normalize(regex)).join(""));
const some = (regex) => normalize(regex, "+");
const optional = (regex) => normalize(regex, "?");
const any = (regex) => normalize(regex, "*");
const delimit = (regex, limit) => concat(limit, regex, limit);
const group = (regex) => normalize(`(${regex.source})`);

const unicode = /\\u[0-9a-zA-Z]{4}/;
const escapes = /\\["\\\/bfnrt]/;
const character = /[^"\\\0-\x1F\x7F]/;

export const string = delimit(group(any(either(character, unicode, escapes))), `"`);

console.log(`"test"`.match(string));