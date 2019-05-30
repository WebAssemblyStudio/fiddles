# WebAssembly 101

## Ce qui se passe au build

* `src/main.c` est compilé en `out/main.wasm`;
* les fonctions préfixées par `WASM_EXPORT` seront "importable" par le code JS.

## Ce qui se passe à l'"exécution"

* on ouvre `src/main.html` dans un navigateur (*via* HTTP);
* le navigateur charge `src/main.js` (ligne 4 du HTML);
* le module `src/main.js` charge `out/main.wasm` avec `fetch`,
  qui retourne une promesse;
* cette promesse est passée à `WebAssembly.instantiateStreaming`,
  qui retourne (*via* une promesse) un objet `result`,
  qui donne accès aux fonctions définies dans `src/main.c`
  (en l'occurence `my_func`).
  
L'objet `result` contient deux attributs, `module` et `instance`,
mais c'est surtout `instance` qui nous intéresse ici.
Il possède un attribut `exports` qui donne accès aux fonctions exportées dans le fichier C avec `WASM_EXPORT`.

## Les autres fichiers

* `build.ts` décrit comment compiler le C en WASWM,
   en utilisant la chaîne de production du package `@wasm/studi-utils`.

* `package.json` permet, lorsqu'on télécharge le projet,
  d'installer en local toute la chaîne de production avec `npm install`,
  et de lancer la chaîne de production avec `npm run build`.