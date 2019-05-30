# WebAssembly 102


## Communication avec le code JS

Le code WASM peut partager deux types d'objets avec le code JS :

* des fonctions,
* des segmets de mémoire.

Ces objets sont partagés vides des *imports* ou des *exports*.


## Fonctions exportées

Les fonctions exportées sont définies dans le code C, avec le préfixe `WASM_EXPORT` (qui est en fait un alias pour une annotation plus compliquée, cf `src/main.c`, ligne 1).

Elles sont accessibles le code JS, via l'attribut `exports` de l'instance.

Les paramètres et les valeurs de retour de ces fonctions peuvent **uniquement** être des entiers ou des flottants (sur 32 ou 64 bits). Tous les autres types de données doivent transiter *via* les segments de mémoire partagés.


## Segments de mémoire exportées

En théorie, il est possible pour un module WASM d'exporter plusieurs segments de mémoire, mais nous n'en n'utiliseront qu'un seul. Le compilateur C exporte automatiquement un segment de mémoire, nommé `memory`, qui contient toutes les variables globales du module.


## Fonctions importées

Les fonctions importées sont simplement *déclarées* dans le code C (sans corps), avec le préfixe `extern`.

Au moment de la création de l'instanciation du module WASM par `WebAssembly.instantiateStreaming`, on peut passer en paramètre un objet qui contient toutes les fonctions requises (importées) par le module WASM. 
