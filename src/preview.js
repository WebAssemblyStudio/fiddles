async function showPreview(frames, fps, loop) {
  const gridContainer = document.querySelector("#lights-grid");
  const rows = createGrid(gridContainer, frames[0].length, frames[0][0].length);

  const generator = showFrame(rows, frames, loop);
  setInterval(generator.next.bind(generator), 1000 / fps);
}

function createGrid(container, rowCount, colCount) {
  const rows = [];

  for (let y = 0; y < rowCount; y++) {
    const row = rows[y] = [];
    for (let x = 0; x < colCount; x++) {
      const light = row[x] = document.createElement('div');
      light.classList.add('light');
      container.appendChild(light);
    }
  }

  container.style.gridTemplateColumns = `repeat(${colCount}, min-content)`;

  return rows;
}

function* showFrame(rows, frames, loop) {
  let i = -1;
  while (true) {
    i++;
    if (i === frames.length) {
      if (!loop) {
        return;
      }
      i = 0;
    }
    console.log(i);
    let frame = frames[i];

    for (let y = 0; y < rows.length; y++) {
      const row = rows[y];
      for (let x = 0; x < row.length; x++) {
        const light = row[x];
        const color = frame[y][x];
        light.style.background = `rgb(${color[0]},${color[1]},${color[2]})`;
      }
    }

    yield;
  }
}