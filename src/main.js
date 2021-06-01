/*fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  //document.getElementById("result").textContent = instance.exports.welcome();
    //document.getElementById("container").textContent = instance.exports.main();
  //var n=  document.getElementById("result").value;
  
  document.getElementById("result").textContent = instance.exports.helloWorld();

}).catch(console.error);
*/

(async()=>{
  const codePromise=fetch('../out/main.wasm')
  const { instance }=await WebAssembly.instantiateStreaming(codePromise)
  const buffer=new Uint8Array(instance.exports.memory.buffer)
  const pointer=instance.exports.helloWorld()
  let string =""
  for(let i=pointer;buffer[i];i++){
    string+=String.fromCharCode(buffer[i])

  }
    var u=  document.getElementById("uname").value;
    var p=  document.getElementById("pass").value;

    const userName=instance.exports.checkUserName(u)
    const pass=instance.exports.checkPassword(p)
    if(userName==1 && pass==1)
    {
      let string="success";
      document.getElementById("result").textContent =string


    }
    else{
      let string="fail"
        document.getElementById("result").textContent =string

    }
     


  //document.getElementById("result").textContent =string




})()
