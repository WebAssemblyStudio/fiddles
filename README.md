# WebAssembly 102

## Communication avec le code JS

Le code WASM peut partager deux types d'objets avec le code JS :

* des fonctions,
* des segmets de mémoire.

Ces objets sont partagés vides des *imports* ou des *exports*.

Les objets **exportés** sont définis dans le code C,
et préfixés par `WASM_EXPORT`
(qui est en fait un alias pour une annotation plus compliquée,
 cf `src/main.c`, ligne 1).
