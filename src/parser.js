const or = (...regexes) => regexes.map(regex => regex.source).join("|");

const unicode = /\\u[0-9a-fA-F]{4}/;
const escapes = /\\["\\\/bfnrt]/;
const character = /[^\s"\\\0-\x1F\x7F]/;
const whitespace = /\s/;

const identifier = /^/;
const string = new RegExp(`^"((?:${or(escapes, unicode, character, whitespace)})*)"`);

console.log(string);
console.log(`"test"`.match(string));

const lparen = /^\(/;
const rparen = /^\)/;