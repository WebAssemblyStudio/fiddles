function ab2str(buf) {
  return String.fromCharCode.apply(null, new Uint8Array(buf));
}

fetch("../out/main.wasm")
  .then((response) => response.arrayBuffer())
  .then((arrayBuffer) => {
    const dragDrop = document.getElementById("drag-wasm");
    dragDrop.setAttribute("draggable", "true");
    dragDrop.addEventListener("dragstart", (event) => {
      //console.log(event.dataTransfer.items.add(file));
      event.dataTransfer.setData("application/wasm", ab2str(arrayBuffer));
    });
  })
  .catch(console.error);
