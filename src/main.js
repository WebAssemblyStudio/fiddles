fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;

  const { add_one: addOne, minus_one: minusOne } = instance.exports;
  const buttonPlus = document.querySelector('#plus');
  const buttonMinus = document.querySelector('#minus');
  const root = document.querySelector('#result');
  const updateDOM = () => (root.innerText = state.number);
  const state = {
    number: 0,
    setState(value) {
      Object.entries(value).forEach(([key, value]) => {
        this[key] = value;
      });
      updateDOM();
    }
  };

  buttonPlus.addEventListener('click', () => { 
    const result = addOne(state.number);

    state.setState({ number: result });
  });

  buttonMinus.addEventListener('click', () => { 
    const result = minusOne(state.number); 

    state.setState({ number: result });
  });
}).catch(console.error);
