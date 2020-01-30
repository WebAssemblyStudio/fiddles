function hsvToRgbJS(h, s = 1, v = 1) {
  h /= 60;
  var i = Math.floor(h);
  var f = h - i;
  var p = v * (1 - s);
  var q = v * (1 - f * s);
  var t = v * (1 - (1 - f) * s);
  var r, g, b;
  switch (i % 6) {
    case 0: r = v, g = t, b = p; break;
    case 1: r = q, g = v, b = p; break;
    case 2: r = p, g = v, b = t; break;
    case 3: r = p, g = q, b = v; break;
    case 4: r = t, g = p, b = v; break;
    case 5: r = v, g = p, b = q; break;
  }
  return [r * 255, g * 255, b * 255].map(Math.floor);
}


function unpack(rgb) {
  return [
    rgb >>> 16 & 0xFF,
    rgb >>> 8 & 0xFF,
    rgb >>> 0 & 0xFF,
  ];
}

WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    sayHello() {
      console.log("Hello from WebAssembly!");
    }
  },
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const { hue2Rgb } = result.instance.exports;

  console.log('hue2Rgb:   ', unpack(hue2Rgb(0)));
  console.log('hsvToRgbJS:', hsvToRgbJS(0));

  console.log('hue2Rgb:   ', unpack(hue2Rgb(Math.floor(2 * 256 / 360))));
  console.log('hsvToRgbJS:', hsvToRgbJS(2));

  console.log('hue2Rgb:   ', unpack(hue2Rgb(Math.floor(10 * 256 / 360))));
  console.log('hsvToRgbJS:', hsvToRgbJS(10));

  console.log('hue2Rgb:   ', unpack(hue2Rgb(Math.floor(45 * 256 / 360))));
  console.log('hsvToRgbJS:', hsvToRgbJS(45));

  console.log('hue2Rgb:   ', unpack(hue2Rgb(Math.floor(60 * 256 / 360))));
  console.log('hsvToRgbJS:', hsvToRgbJS(60));

  console.log('hue2Rgb:   ', unpack(hue2Rgb(Math.floor(180 * 256 / 360))));
  console.log('hsvToRgbJS:', hsvToRgbJS(180));

  console.log('hue2Rgb:   ', unpack(hue2Rgb(Math.floor(192 * 256 / 360))));
  console.log('hsvToRgbJS:', hsvToRgbJS(192));

  console.log('hue2Rgb:   ', unpack(hue2Rgb(Math.floor(360 * 256 / 360))));
  console.log('hsvToRgbJS:', hsvToRgbJS(360));
  
}).catch(console.error);
