// A helper function
function byId(id) {
  return document.getElementById(id);
}

// Instantiate a new IceteaWeb3 instance
const tweb3 = new icetea.IceteaWeb3("wss://rpc.icetea.io/websocket");

// create a new account, the account is needed to call setValue
tweb3.wallet.createAccount();

// Note: replace the contract address with your actual address or alias
const contract = tweb3.contract("teat1eyhvz5f92sdmz47zvkzsuq3xw7nfn5l84g6cms");

// called at page load to display current value
contract.methods
  .value()
  .call()
  .then(function(value) {
    byId("value").textContent = value;
  })
  .catch(function(error) {
    console.error(error);
    alert(error);
  });

// setValue button handler
byId("setValue").addEventListener("click", function() {
  const newValue = byId("newValue").value;
  contract.methods
    .setValue(+newValue)
    .sendCommit()
    .catch(function(error) {
      console.error(error);
      alert(error);
    });
});

// watch for ValueSet event and update current value
contract.events.ValueSet({}, function(error, data) {
  if (error) {
    console.error(error);
    byId("value").textContent = String(error);
  } else {
    byId("value").textContent = data.newValue;
  }
});