let s="";
fetch('../out/main.wasm')
 .then(response => response.arrayBuffer())
 .then(bytes => WebAssembly.instantiate(bytes,
      { env: {
              putc_js: function (c) {
                    c = String.fromCharCode(c);     
                    if (c == "\n") {
                     console.log(s);
                     s = "";    
                    } else {
                     s += c;
                    }
                   }
             }
       }))

  .then(results => {
           instance = results.instance;
           document.getElementById("container")
               .innerText = instance.exports.main();
       })