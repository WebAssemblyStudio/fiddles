WebAssembly.instantiateStreaming(fetch('../out/main.wasm'), {
    env: {
      abort: function (msg, file, line, column) {
        console.error('abort called at main.ts:' + line + ':' + column);
      },
      log: function(log) {
        console.log(log);
      }
    }
  }).then((result) => {
    const audioCtx = new AudioContext();
    const a = result.instance.exports;
  
    const SAMPLE_RATE = 44100;
  
    const detector = a['PitchDetector#constructor'](SAMPLE_RATE);
    const getPitch = (buffer) => a['PitchDetector#getPitch'](detector, buffer);
  
    const scriptNode = audioCtx.createScriptProcessor(1024, 1, 1);
    console.log('ready');
    // Give the node a function to process audio events
    scriptNode.onaudioprocess = function (audioProcessingEvent) {
      // The input buffer is the song we loaded earlier
      const inputBuffer = audioProcessingEvent.inputBuffer;
      const inputData = inputBuffer.getChannelData(0);
      // console.log(inputData);
      const pitch = getPitch(inputData);
      document.body.innerHTML = pitch;
    };
    console.log(audioCtx.sampleRate)
    navigator.mediaDevices
      .getUserMedia({ audio: true })
      .then(function (stream) {
        const source = audioCtx.createMediaStreamSource(stream);
        source.connect(scriptNode);
        scriptNode.connect(audioCtx.destination)
        console.log('connected');
      })
      .catch(function (err) {
        document.write('err');
      });
  });
  