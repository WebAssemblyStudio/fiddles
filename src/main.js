fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;

  console.log(instance);

  var dice = document.querySelector('.dice');

  dice.addEventListener('click', function(){
        
        document.querySelector('.dice').className = "dice dice-" + instance.exports.main();                  

  });


  
}).catch(console.error);
