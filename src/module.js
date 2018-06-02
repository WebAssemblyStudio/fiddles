(async () => {
    const rows = 44
    const cols = 36
    const seconds = 2
    const fps = 35

    document.body.innerHTML = ''
    document.body.style = 'margin: 0; background: palegoldenrod; display: flex; flex-direction: column; justify-content: center; align-items: center;'

    const canvas = document.createElement('canvas')
    canvas.style = 'width: 360px; height: 440px; image-rendering: pixelated; transform: scaleY(-1);'
    canvas.width = cols
    canvas.height = rows
    const ctx = canvas.getContext('2d')
    
    window.ctx = ctx
    document.body.appendChild(canvas)  

    const textarea = document.createElement('textarea')
    textarea.addEventListener('click', textarea.select)
    textarea.style = 'height: 100px; width: 360px;'

    const button = document.createElement('button')
    button.type = button
    button.disabled = true
    button.addEventListener('click', () => {
      textarea.value = 'Rendering string...\n(This can take a while)\n(Your browser will lock up)\n(#sorrynotsorry)'

      document.body.appendChild(textarea)
      button.style.display = 'none'

      setTimeout(done, 100)
    })
    document.body.appendChild(button)

    button.innerHTML = "Animating..."
    const frames = []
    let frameNr = 0

    if (window.lastTimeout) clearTimeout(window.lastTimeout)
    const draw = () => {
        ctx.fillStyle = 'black'
        ctx.fillRect(0,0, canvas.width, canvas.height)

        // RENDER SOMETHING TO CANVAS

        ctx.fillStyle = 'red'
        ctx.fillRect(0, 0, Math.max(10, frameNr - 30), (1 + frameNr) * 1)

        // OK STOP NOW THANKS

        const imageData = ctx.getImageData(0, 0, canvas.width, canvas.height)
        const rgbData = []
        imageData.data.forEach((x,i) => {
          if (i % 4 !== 3) rgbData.push(x)
        })
        frames.push(rgbData)

        if (frameNr < seconds * fps - 1) {
          window.lastTimeout = setTimeout(draw, Math.round(1000 / fps))
        } else {
          button.innerHTML = 'Render string'
          button.disabled = false
          window.frames = frames
        }
        frameNr++
    }
    draw()

    function done() {
      const str =
`const frames_str = [
${frames.map(frame => `"${btoa(frame.map(x => String.fromCharCode(x)).join(''))}"`).join(',\n')}
]
const frames = frames_str.map(str => {
  const binstr = atob(str)
  return [...binstr].map(char => char.charCodeAt(0))
})

export function transform(buffer, rows, cols, frameCount, fps, isFirst) {
  const frameSize = 3 * rows * cols
  const lineSize = cols * 3

  for (let i = 0; i < frameCount; i++) {
    const frame = new Uint8Array(buffer, frameSize * i, frameSize)
    const texture = frames[i % frames.length]
    for (let j = 0; j < rows; j++) {
        const line = frame.subarray(lineSize * j, lineSize* (j + 1));   
        for (let k = 0; k < cols; k++) {
            line[k * 3 + 0] = texture[j * cols * 3 + k * 3 + 0]
            line[k * 3 + 1] = texture[j * cols * 3 + k * 3 + 1]
            line[k * 3 + 2] = texture[j * cols * 3 + k * 3 + 2]
        }
    }
  }
}
    
export default function () {
  return Promise.resolve({
    transform,
  })
}
`

      textarea.value = str
    }
})()