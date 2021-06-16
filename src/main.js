// This is a unique integer which is used for the id of the JS objects
var jsRefId = 0;

// This is a dictionary which maps from id to JS object
var jsRefs = {};

// This creates a new id, puts the object into the dictionary, then returns the new id
function mallocJsRef(obj) {
    var id = jsRefId;
    // Because we always increment the id, it's guaranteed to be unique
    // (until it reaches 4294967295)
    ++jsRefId;
    jsRefs[id] = obj;
    return id;
}

// This looks up the JS object based upon its id
function lookupJsRef(id) {
    return jsRefs[id];
}

// This cleans up the memory for the JS object (by allowing it to be garbage collected)
function freeJsRef(id) {
    delete jsRefs[id];
}

var imports = {
    env: {
        makeNewArray: function () {
            return mallocJsRef([]);
        },
        push: function (id, value) {
            lookupJsRef(id).push(value);
        },
        length: function (id) {
            return lookupJsRef(id).length;
        },
        logInt: function (value) {
            console.log(value);
        },
        logRef: function (id) {
            console.log(lookupJsRef(id));
        },
        free: function (id) {
            freeJsRef(id);
        }
    }
};

WebAssembly.instantiateStreaming(fetch('../out/main.wasm'), imports).then(function (result) {
    result.instance.exports.main();
}).catch(function (e) {
    console.error(e);
});

