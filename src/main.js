var readPacketOffset = 0;
var writeFrameOffset = 3840*1024;

var rtspInterleavedOffset = readPacketOffset + 0;
var rtpHeaderOffset = readPacketOffset + 1024;
var rtpPayloadOffset = readPacketOffset + 2048;
var spsOffset = writeFrameOffset + 0;
var ppsOffset = writeFrameOffset + 1024;
var frameBufferOffset = writeFrameOffset + 2048;

var rtspInterleavedBuffer;
var rtpHeaderBuffer;
var rtpPayloadBuffer;
var sps_segment;
var pps_segment;
var frameBuffer;
var exports;

var rtspInterleaved = new Uint8Array([1, 2, 3, 4]);
var rtpHeader = new Uint8Array([1, 2, 3, 4]);
var rtpPayload = new Uint8Array([1, 2, 3, 4]);

WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    updatePacketCnt(rtpTimestamp) {
      console.log("updatePacketCnt rtpTimestamp :" + updatePacketCnt);
        // if (this.isInitializeReceivedPacketCount()) {
        //     this.setStartTimeStamp(rtpTimestamp);
        // }
        // this.increaseNumberOfReceivedPacketCount();
    },
    consolelog(line) {
      console.log("consolelog line = " + line);
    },
    consolelogs(num1, num2) {
      console.log("consolelog num1 ", num1, " num2 ", num2);
    },
    consolelog4(num1, num2, num3, num4) {
      console.log("consolelog num1 ", num1, " num2 ", num2, " num3 ", num3, " num4 ", num4);
    }
  },
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  exports = result.instance.exports;
  document.getElementById("container").textContent = "Result: " + exports.add(14, 23);

    // Get our memory object from the exports
  var memory = exports.memory;
  // Create a Uint8Array to give us access to Wasm Memory
  rtspInterleavedBuffer = new Uint8Array(memory.buffer, rtspInterleavedOffset, 1024);
  rtpHeaderBuffer = new Uint8Array(memory.buffer, rtpHeaderOffset, 1024);
  rtpPayloadBuffer = new Uint8Array(memory.buffer, rtpPayloadOffset, 3838*1024);
  sps_segment = new Uint8Array(memory.buffer, spsOffset, 1024);
  pps_segment = new Uint8Array(memory.buffer, ppsOffset, 1024);
  frameBuffer = new Uint8Array(memory.buffer, frameBufferOffset, 3838*1024);

  console.log("all right : ", "test is OK");

  rtspInterleavedBuffer.set(rtspInterleaved);
  rtpHeaderBuffer.set(rtpHeader);
  rtpPayloadBuffer.set(rtpPayload);

  console.log('rtspInterleavedBuffer ', rtspInterleavedBuffer);
  console.log('rtpHeaderBuffer ', rtpHeaderBuffer);
  console.log('rtpPayloadBuffer ', rtpPayloadBuffer);

  exports.setRtspInterleavedData(rtspInterleaved.length);
  exports.setRtpHeaderData(rtpHeader.length);
  exports.setRtpPayloadData(rtpPayload.length);

  rtspInterleaved = new Uint8Array([2, 2, 4, 4]);
  rtpHeader = new Uint8Array([2, 2, 4, 4]);
  rtpPayload = new Uint8Array([2, 2, 4, 4]);

  rtspInterleavedBuffer.set(rtspInterleaved);
  rtpHeaderBuffer.set(rtpHeader);
  rtpPayloadBuffer.set(rtpPayload);

  console.log('rtspInterleavedBuffer ', rtspInterleavedBuffer);
  console.log('rtpHeaderBuffer ', rtpHeaderBuffer);
  console.log('rtpPayloadBuffer ', rtpPayloadBuffer);

  exports.setRtspInterleavedData(rtspInterleaved.length);
  exports.setRtpHeaderData(rtpHeader.length);
  exports.setRtpPayloadData(rtpPayload.length);

  rtspInterleaved = new Uint8Array([3, 2, 4, 5]);
  rtpHeader = new Uint8Array([3, 2, 4, 5]);
  rtpPayload = new Uint8Array([3, 2, 4, 5]);

  rtspInterleavedBuffer.set(rtspInterleaved);
  rtpHeaderBuffer.set(rtpHeader);
  rtpPayloadBuffer.set(rtpPayload);

  console.log('rtspInterleavedBuffer ', rtspInterleavedBuffer);
  console.log('rtpHeaderBuffer ', rtpHeaderBuffer);
  console.log('rtpPayloadBuffer ', rtpPayloadBuffer);

  exports.setRtspInterleavedData(rtspInterleaved.length);
  exports.setRtpHeaderData(rtpHeader.length);
  exports.setRtpPayloadData(1536);

  rtspInterleaved = new Uint8Array([4, 2, 4, 5]);
  rtpHeader = new Uint8Array([3, 5, 4, 5]);
  rtpPayload = new Uint8Array([3, 1, 4, 5]);

  rtspInterleavedBuffer.set(rtspInterleaved);
  rtpHeaderBuffer.set(rtpHeader);
  rtpPayloadBuffer.set(rtpPayload);

  console.log('rtspInterleavedBuffer ', rtspInterleavedBuffer);
  console.log('rtpHeaderBuffer ', rtpHeaderBuffer);
  console.log('rtpPayloadBuffer ', rtpPayloadBuffer);

  exports.setRtspInterleavedData(rtspInterleaved.length);
  exports.setRtpHeaderData(rtpHeader.length);
  exports.setRtpPayloadData(1536);

}).catch(console.error);

var test = function () {
  rtspInterleaved = new Uint8Array([4, 2, 4, 5]);
  rtpHeader = new Uint8Array([3, 5, 4, 5]);
  rtpPayload = new Uint8Array([3, 1, 4, 5]);

  rtspInterleavedBuffer.set(rtspInterleaved);
  rtpHeaderBuffer.set(rtpHeader);
  rtpPayloadBuffer.set(rtpPayload);

  console.log('rtspInterleavedBuffer ', rtspInterleavedBuffer);
  console.log('rtpHeaderBuffer ', rtpHeaderBuffer);
  console.log('rtpPayloadBuffer ', rtpPayloadBuffer);

  exports.setRtspInterleavedData(rtspInterleaved.length);
  exports.setRtpHeaderData(rtpHeader.length);
  exports.setRtpPayloadData(1536);
}

test();
test();
test();