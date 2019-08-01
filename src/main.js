fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;

  let form = document.getElementById("temp-form");
  let input = document.getElementById("temp-input");

  form.addEventListener('submit', (event) => {
    event.preventDefault();
  })

  input.oninput = useInput;

  function useInput() {
    const inputValue = input.value;
    const radioValue = getRadioVal(form, 'temp');

    if (radioValue === 'fahrenheit' && inputValue !== '') {
      document.getElementById("container").textContent = instance.exports.fahrToCels(inputValue);
    } else if (radioValue === 'celsius' && inputValue !== '') {
      document.getElementById("container").textContent = instance.exports.celsToFahr(inputValue);
    } else {
      document.getElementById("container").textContent = '';
    }
  }

}).catch(console.error);

function getRadioVal(form, name) {
  var val;
  var radios = form.elements[name];
  for (var i=0, len=radios.length; i<len; i++) {
    if ( radios[i].checked ) { 
      val = radios[i].value;
      break;
    }
  }
  return val;
}
