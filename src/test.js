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


console.log(rootNode);
for (let x = 0; x < 10; x++) {
  const children2 = [...rootNode.children.slice(0)];
  console.time('D3');
  root = d3.hierarchy({
    children: children2,
  })
    .sum(node => node.value);

  const layout = d3.pack()
    .size([958, 958])
    .padding(0.5);

  const nodes = layout(root).leaves();
  nodes.forEach(node => delete node.parent);
  console.timeEnd('D3');
}

const svg = d3.select('svg'),
  width = +svg.attr('width'),
  height = +svg.attr('height');

const format = d3.format(',d');

const color = d3.scaleSequential(d3.interpolateRainbow)
    .domain([1, 100000]);
const box = svg.select('g').selectAll('g');

Module.onRuntimeInitialized = async (_) => {
  for (let x = 0; x < 10; x++) {
    console.time('Perf');
    const root = new Module.Hierarchy({
      size: [958, 958],
      padding: 0.5,
    }, rootNode);

    const packedChildren = root.pack().leaves();
    console.timeEnd('Perf');
  }
  const result = [];
  const BatchSize = 3000;
  const partialData = [];
  const batch = (start, end) => () => {
    for (let p = start; p < end; p++) {
      const circleData = packedChildren.get(p);
      partialData.push({ x: circleData.x, y: circleData.y, r: circleData.r, value: circleData.value });
    }
    const hole = box.data(partialData).enter().append('g');

    hole.attr('transform', d => `translate(${d.x},${d.y})`)
        .append('circle')
        .attr('r', d => d.r)
        .style('fill', d => color(d.value));
    setTimeout(batch(end, (end + BatchSize >= packedChildren.size()) ? packedChildren.size() - 1 : end + BatchSize), 0);
  };

  setTimeout(batch(0, BatchSize), 0);
};
