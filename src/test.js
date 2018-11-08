const children = [];
const rootNode = {
  value: 1000000,
  children,
};

const min = 1;
const max = 1000;
for (let i = 0; i < 200000; i++) {
  children.push({
    value: (Math.floor(Math.random() * (max - min + (i * Math.random()) + min))),
  });
}

  const width = 958;
  const height = 958;

  const padding = 0.5;

  const children2 = [...rootNode.children.slice(0)];
  
  console.time('D3');
  root = d3.hierarchy({
    children: children2,
  })
    .sum(node => node.value);

  const layout = d3.pack()
    .size([width, height])
    .padding(padding);

  const nodes = layout(root).leaves();
  nodes.forEach(node => delete node.parent);
  console.timeEnd('D3');

  console.log(`Js packed nodes`);
  console.log(nodes);

Module.onRuntimeInitialized = async (_) => {
    console.time('Perf');
    const root = new Module.Hierarchy({
      size: [width, height],
      padding: padding,
    }, rootNode);

    const packedChildren = root.pack().leaves();
    console.timeEnd('Perf');

  const nodes = [];
  for(let x=0; x< packedChildren.size(); x++){
    const packedNode = packedChildren.get(x);
    nodes.push({x: packedNode.x, y: packedNode.y, r: packedNode.r, value: packedNode.value});
  }

    console.log(`Wasm packed nodes`);
    console.log(nodes);
};

  
