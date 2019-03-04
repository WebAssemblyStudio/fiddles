// The code in the main global scope.

let audioworkletnode;

window.startaudio = async () => { 
           
    const bytes = await fetch('../out/main.wasm').then(response =>
        response.arrayBuffer()
    );
      
    const song = JSON.parse(await fetch('../out/song.json').then(response =>
        response.text()
    ));

    
    let context = new AudioContext(); 
           
    const processorbytes = await fetch('processor.js').then(response =>
        response.blob()
    );
    
    await context.audioWorklet.addModule(URL.createObjectURL(processorbytes));
    
    audioworkletnode = new AudioWorkletNode(context, 'my-worklet-processor',
        {outputChannelCount: [2]});
    
    // testprocessor.port.onmessage = (d) => console.log(d.data);
    audioworkletnode.port.start();
    audioworkletnode.port.postMessage({ topic: "wasm", samplerate: context.sampleRate, wasm: bytes, song: song});
    audioworkletnode.connect(context.destination);
};

window.stopaudio = async () => {
    audioworkletnode.disconnect();
}

window.restartaudio = async () => {
    await stopaudio();
    await startaudio();
};