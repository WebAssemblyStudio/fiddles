// The entry file of your WebAssembly module.
declare function updatePacketCnt(rtpTimestamp: i32): void;
declare function consolelog(line: i32): void;
declare function consolelogs(num1: i32, num2: i32): void;
declare function consolelog4(num1: i32, num2: i32, num3: i32, num4: i32): void;

// sayHello();
memory.grow(240);// 64KB x 60 * 2  3840KB/s packet, Frame

consolelog(9);

const readPacketOffset: i32 = 0;
const writeFrameOffset: i32 = 3840*1024;

const CAMERA: u8 = 1;
const RECODER: u8 = 2;
const LIVE: u8 = 1;
const PLAYBACK: u8 = 2;
const IFRAME: u8 = 1;
const PFRAME: u8 = 2;
const rtspInterleavedOffset: i32 = readPacketOffset + 0;
const rtpHeaderOffset: i32 = readPacketOffset + 1024;
const rtpPayloadOffset: i32 = readPacketOffset + 2048;
const spsOffset: i32 = writeFrameOffset + 0;
const ppsOffset: i32 = writeFrameOffset + 1024;
const frameBufferOffset: i32 = writeFrameOffset + 2048;

let rtspInterleaved: Uint8Array;
let rtpHeader: Uint8Array;
let rtpPayload: Uint8Array;

let ts_deviceType: u8 = CAMERA;

let playMode: u8 = LIVE;
let frameData: Uint8Array;

let ts_frameType = IFRAME;
let ts_framerate: i32 = 0;
let ts_packetSeq = 0;
let ts_rtpTimestamp = 0;
let ts_timestamp = null;
let ts_timestamp_usec = null;
let ts_timezone: u8 = 0;
let ts_startTimestamp = 0;
let ts_SPSLength: i32 = 0;
let ts_PPSLength: i32 = 0;
let ts_FrameBufferLength: i32 = 0;

export function getPlayMode(): u8 {
  return playMode;
}

export function getFrameType(): u8 {
    return ts_frameType;
}

export function getFramerate(): i32 {
    return ts_framerate;
}

export function getPacketSeq(): i32 {
    return ts_packetSeq;
}

export function getRtpTimestamp(): i32 {
    return ts_rtpTimestamp;
}

export function getTimestamp(): i32 {
    return ts_timestamp;
}

export function getTimestamp_usec(): i32 {
    return ts_timestamp_usec;
}

export function getTimezone(): u8 {
    return ts_timezone;
}

export function getStartTimestamp(): i32 {
    return ts_startTimestamp;
}

export function setDeviceType(deviceType: u8): void {
    ts_deviceType = deviceType;
}

export function setReceivedPacketCount(count: i32): void {
    ts_packetSeq = count;
}

export function setRtspInterleavedData(length: u16): void {
    // consolelogs(94, length);
    rtspInterleaved = new Uint8Array(length);
    rtspInterleaved.forEach( function (a, i) {
        rtspInterleaved[i] = load<u8>(rtspInterleavedOffset + i);
    });
    // consolelog(99);
}

export function setRtpHeaderData(length: u16): void {
    // consolelogs(103, length);
    rtpHeader = new Uint8Array(length);
    rtpHeader.forEach( function (a, i) {
        rtpHeader[i] = load<u8>(rtpHeaderOffset + i);
    });
    // consolelog(108);
}

export function setRtpPayloadData(length: u16): void {
    // consolelogs(112, memory.size());
    rtpPayload = new Uint8Array(length);
    rtpPayload.forEach( function (a, i) {
        rtpPayload[i] = load<u8>(rtpPayloadOffset + i);
    });
    // consolelog(117);
}

export function getSPSLength(): i32 {
  return ts_SPSLength;
}

export function getPPSLength(): i32 {
  return ts_PPSLength;
}

export function getFrameLength(): i32 {
  return ts_FrameBufferLength;
}

export function setTo(x: Uint8Array, y: Uint8Array): void {
  // consolelogs(x.length, y.length);
  for(let idx: i32 = 0; idx < y.length; idx ++) {
    x[idx] = y[idx];
    // consolelogs(x[idx], y[idx]);
  }
  // memory.copy(changetype<usize>(x.buffer) + x.byteOffset, changetype<usize>(y.buffer) + y.byteOffset, y.length);
  // return x[0];
}

export function copy(x: Uint8Array, y: Uint8Array, offset: i32): void {
  // consolelogs(x.length, y.length);
  for(let idx: i32 = 0; idx < y.length; idx ++) {
    x[offset + idx] = y[idx];
    // consolelogs(x[offset + idx], y[idx]);
  }
    // memory.copy(changetype<usize>(x.buffer) + x.byteOffset, changetype<usize>(y.buffer) + y.byteOffset, length);
    // return x[0];
}

export function storeSPSBuffer(buffer: Uint8Array): void {
  buffer.forEach( function (a, i) {
      store<u8>((spsOffset + i), a);
  })
  ts_SPSLength = buffer.length;
}

export function storePPSBuffer(buffer: Uint8Array): void {
  buffer.forEach( function (a, i) {
    store<u8>((ppsOffset + i), a);
  })
  ts_PPSLength = buffer.length;
}

export function storeFrameBuffer(buffer: Uint8Array): void {
  buffer.forEach( function (a, i) {
    store<u8>((frameBufferOffset + i), a);
  })
  ts_FrameBufferLength = buffer.length;
}

let ts_rtpVersion: number;
let ts_rtpPadding: boolean;
let ts_rtpCSRCCount: number;
let ts_rtpExtension: boolean;
let ts_rtpMarkerBit: boolean;
// let ts_rtpSquenceNumber: number;
let ts_rtpPayloadType: number;
let ts_rtpNRI: number;
let ts_rtpNALType: number;
let ts_rtpForbiddenZeroBit: number;
let ts_inputLength = 0;
let ts_playback = false;
// const size_1_4K = Math.floor(1.4 * 1024);
let ts_inputBuffer = new Uint8Array(0);
consolelog(ts_inputBuffer.length);
let ts_PREFIX = new Uint8Array(4);
let ts_NTPmsw = new Uint8Array(4);
let ts_NTPlsw = new Uint8Array(4);
let ts_gmt = new Uint8Array(2);

//initial segment test
let ts_sps_segment: Uint8Array;
let ts_pps_segment: Uint8Array;
let ts_FrameBuffer = new Uint8Array(4);

//media segment test
ts_PREFIX[0] = 0x00;
ts_PREFIX[1] = 0x00;
ts_PREFIX[2] = 0x00;
ts_PREFIX[3] = 0x01;


// 'frameData': inputBufferSub,  //store

// interface streamInfo {
//     frameType: u8;
//     framerate: u8;
//     packetSeq: i32;
//     timeStamp: {
//         rtpTimestamp: i32,
//         timestamp: i32,
//         timestamp_usec: i32,
//         timezone: u8
//     },
// };

// interface TimeData {
//     timestamp: number;
//     timestamp_usec: number;
//     timezone: number;
// }

// class StreamData {
//     channelId: number;
//     interleavedId: number;
//     deviceType: string;
//     timezone: number;
//     rtpTimestamp: number;
//     frameRate: number;
//     timeStamp: TimeData;
//     startTimeStamp: number;
//     receivedPacketCount: number;

//     timeData: TimeData;
//     rtcpSession: any;

//     constructor(channelId: number, interleavedId: number, deviceType: string, timezone: number, rtpTimestamp: number, frameRate: number, timeStamp: TimeData) {
//         this.channelId = channelId;
//         this.interleavedId = interleavedId;
//         this.deviceType = deviceType;
//         this.timezone = timezone;
//         this.rtpTimestamp = rtpTimestamp;
//         this.frameRate = frameRate;
//         this.timeStamp = timeStamp;
//         this.receivedPacketCount = 0;
//     }
//     getFramerate(): number { return this.frameRate; }
//     setFramerate(fps: number) { this.frameRate = fps; }
//     GetTimeStamp(): TimeData { return this.timeStamp; }
//     SetTimeStamp(timeStamp: TimeData) { this.timeStamp = timeStamp; }
//     setStartTimeStamp(timeStamp: number) { this.startTimeStamp = timeStamp; }
//     isInitializeReceivedPacketCount(): boolean { return (this.receivedPacketCount === 0); }
//     increaseNumberOfReceivedPacketCount(): void { this.receivedPacketCount++; }
//     getNumberOfReceivedPacketCount(): number { return this.receivedPacketCount; }
// }

enum H264NalUnit {
    H264_NAL_UNSPECIFIED = 0,		// 0
    H264_NAL_SLICE,			// 1
    H264_NAL_DPA,				// 2
    H264_NAL_DPB,				// 3
    H264_NAL_DPC,				// 4
    H264_NAL_IDR_SLICE,		// 5
    H264_NAL_SEI,				// 6
    H264_NAL_SPS,				// 7
    H264_NAL_PPS,				// 8
    H264_NAL_AUD,				// 9
    H264_NAL_END_SEQUENCE,	// 10
    H264_NAL_END_STREAM,		// 11
    H264_NAL_FILLER_DATA,		// 12
    H264_NAL_SPS_EXT,			// 13
    H264_NAL_PREFIX,			// 14
    H264_NAL_SUB_SPS,			// 15
    H264_NAL_DPS,				// 16
    H264_NAL_RESERVED17,		// 17
    H264_NAL_RESERVED18,		// 18
    H264_NAL_AUXILIARY_SLICE,	// 19
    H264_NAL_EXTEN_SLICE,		// 20
    H264_NAL_DEPTH_EXTEN_SLICE,//21
    H264_NAL_RESERVED22,		// 22
    H264_NAL_RESERVED23,		// 23
    H264_NAL_UNSPECIFIED24,	// 24
    H264_NAL_UNSPECIFIED25,	// 25
    H264_NAL_UNSPECIFIED26,	// 26
    H264_NAL_UNSPECIFIED27,	// 27
    H264_NAL_UNSPECIFIED28,	// 28
    H264_NAL_UNSPECIFIED29,	// 29
    H264_NAL_UNSPECIFIED30,	// 30
    H264_NAL_UNSPECIFIED31	// 31
};

/**
 *  fromHex().  Convert a hex string to ascii text.
 */
export function fromHex(hex: string): i32 {
    return <i32>parseInt(hex, 16);
}

/**
 *  toHex().  Convert an ASCII string to hexadecimal.
 */
// function toHex(decimal: number): string {
//     return "0x" + (decimal + 0x10000).toString(16).substr(-4).toUpperCase();
// }

export function ntohl(buffer: Uint8Array): i32 {
  consolelog4(buffer[0], buffer[1], buffer[2], buffer[3]);
    return (((buffer[0] << 24) + (buffer[1] << 16) +
      (buffer[2] << 8) + buffer[3]) >>> 0);
};

export function ts_setBuffer(baseBuffer: Uint8Array, dataBuffer: Uint8Array): Uint8Array {
    // consolelogs(ts_inputLength, dataBuffer.length);
    // consolelogs(ts_inputLength + dataBuffer.length, baseBuffer.length);
    if ((ts_inputLength + dataBuffer.length) > baseBuffer.length) {
      // consolelog(317);
        let tmp = baseBuffer; // baseBuffer = null;
        baseBuffer = new Uint8Array(tmp.length + dataBuffer.length);  // consolelog( "baseBuffer = new Uint8Array ( tmp.length ", tmp.length, ', dataBuffer.length ', dataBuffer.length, ')');
        // consolelog(320);
        setTo(baseBuffer, tmp);
        // tmp = null;
    }
    // consolelog(324);
    // consolelog( "ts_setBuffer ( baseBuffer ", baseBuffer.length, ', dataBuffer ', dataBuffer.length, ', ts_inputLength ', ts_inputLength, ')');
    copy(baseBuffer, dataBuffer, ts_inputLength);
    ts_inputLength += dataBuffer.length;
    return baseBuffer;
};

var test = function test(): void {
  var dv1 = new Uint8Array(12);
  var dv2 = new Uint8Array(5);
  dv2[0] = 1;
  dv2[1] = 2;
  dv2[2] = 3;
  dv2[3] = 4;
  dv2[4] = 5;

  setTo(dv1, dv2);
}

test();

export function depacketize_H264(rtspInterleavedLength: u16, rtpHeaderLength: u16, rtpPayloadLength: u16): i32 {//, streamdata: StreamData): i32 {
    let PAYLOAD: Uint8Array;
    let extensionHeaderLen = 0;
    let PaddingSize = 0;
    let ret = 0;
    let rtpTimeStamp = 0;
    // consolelog(ts_FrameBuffer.length);
    // let info = { frameType: IFRAME, framerate: 0, packetSeq: 0, 
    //     timeStamp: { rtpTimestamp: 0, timestamp: 0, timestamp_usec: 0, timezone: 0 },
    // };

    // if(streamdata.interleavedId !== rtspInterleaved[1]) {
    //     // TODO: check interleaved id
    // }

    // Reference: https://tools.ietf.org/html/rfc3550
    // Reference: https://tools.ietf.org/html/rfc3984
    ts_rtpVersion = (rtpHeader[0] & 0xC0) >> 6;
    ts_rtpPadding = (((rtpHeader[0] & 0x20) >> 5) === 1);
    ts_rtpExtension = (((rtpHeader[0] & 0x10) >> 4) === 1);
    ts_rtpCSRCCount = (rtpHeader[0] & 0x0F);
    ts_rtpMarkerBit = (((rtpHeader[1] & 0x80) >> 7) === 1);
    ts_rtpPayloadType = rtpHeader[1] & 0x7F;

    if (rtspInterleaved[0] !== 0x24) {
        // consolelog( "it is not valid interleave header (RTSP over TCP). Interleaved[0] = " + rtspInterleaved[0].toString(16));
        // throw new umpError({
        //     channelId: streamdata.channelId,
        //     errorCode: fromHex('0x0102'),
        //     place: 'h264Session.js:87',
        //     message: "it is not valid interleave header (RTSP over TCP). Interleaved[0] = " + rtspInterleaved[0].toString(16)
        // });
        ret = 11;
    } else if (ts_rtpCSRCCount !== 0) {
        // consolelog("There is additional CSRC which is not handled in this version. CSRC count = " + ts_rtpCSRCCount);
        // throw new umpError({
        //     channelId: streamdata.channelId,
        //     errorCode: fromHex('0x0103'),
        //     place: 'h264Session.js:94',
        //     message: "There is additional CSRC which is not handled in this version. CSRC count = " + rtpCSRCCount
        // });
        ret = 22;
    } else if (ts_rtpPadding) {
        PaddingSize = rtpPayload[rtpPayload.length - 1];
        // consolelog("H.264 PaddingSize - " + PaddingSize);
    }

    //Extension bit check in RTPHeader
    if (ts_rtpExtension) {
        extensionHeaderLen = ((rtpPayload[2] << 8 | rtpPayload[3]) * 4) + 4;
        if (rtpPayload[0] === 0xAB && (rtpPayload[1] === 0xAD || rtpPayload[1] === 0xAC)) {
            let startHeader = 4;
            setTo(ts_NTPmsw, rtpPayload.subarray(startHeader, startHeader + 4));
            startHeader += 4;
            setTo(ts_NTPlsw, rtpPayload.subarray(startHeader, startHeader + 4));
            if (ts_deviceType === CAMERA) {
                startHeader += 6;
                setTo(ts_gmt, rtpPayload.subarray(startHeader, startHeader + 2));
            }
            // consolelog(404);

            let tempTimestamp = ((ntohl(ts_NTPmsw) - 0x83AA7E80) >>> 0);
            consolelogs(408, tempTimestamp);
            let tempTimestamp_usec = (ntohl(ts_NTPlsw) / 0xffffffff) * 1000;
            consolelogs(410, tempTimestamp_usec);
            let tempTimezone = (((ts_gmt[0] << 8) | ts_gmt[1]) << 16) >> 16;
            consolelogs(412, tempTimezone);
            
            // tempdata.timestamp = ((ntohl(ts_NTPmsw) - 0x83AA7E80) >>> 0);
            // tempdata.timestamp_usec = (ntohl(ts_NTPlsw) / 0xffffffff) * 1000;
            // if (streamdata.deviceType === 'camera') {
            //     tempdata.timezone = (((ts_gmt[0] << 8) | ts_gmt[1]) << 16) >> 16;
            // }

            if (ts_timestamp != null && ts_timestamp_usec !== null) {
                // consolelog("", tempdata.timestamp, tempdata.timestamp_usec, streamdata.GetTimeStamp().timestamp,  streamdata.GetTimeStamp().timestamp_usec);
                var timeGap = Math.abs(tempTimestamp - ts_timestamp);
                if(timeGap <= 1) {
                    var distance = Math.abs( (tempTimestamp*1000 + tempTimestamp_usec)-
                                                            (ts_timestamp*1000 + ts_timestamp_usec));
                    consolelogs(426, <i32>distance);
                    if(distance != 0) {
                        ts_framerate = <i32>Math.round(1000 / distance);
                        consolelogs(429, ts_framerate);
                        // consolelog("playback framerate = ", streamdata.getFramerate());
                    }
                }
            }
            ts_timestamp = tempTimestamp;
            ts_timestamp_usec = tempTimestamp_usec;
            ts_timezone = tempTimezone;
            ts_playback = true;
        }
    }

    PAYLOAD = rtpPayload.subarray(extensionHeaderLen, rtpPayload.length - PaddingSize);

    // consolelog(439);
    rtpTimeStamp = ntohl(rtpHeader.subarray(4, 8));
    consolelogs(443, rtpTimeStamp);
    // ts_rtpSquenceNumber = ntohl(rtpHeader.subarray(2, 3));

    // consolelog("interleaved id = ", streamdata.interleavedId,
    //     ", H.264 RTP Version: ", ("00" + ts_rtpVersion).slice(-2),
    //     ", Padding: ", ts_rtpPadding,
    //     ", ExtensionBit: ", ts_rtpExtension,
    //     ", CSRC Count: ", ts_rtpCSRCCount,
    //     ", Marker Bit: ", ts_rtpMarkerBit,
    //     ", RTP Payload Type: ", ts_rtpPayloadType,
    //     ", RTP Sequence Number: ", ts_rtpSquenceNumber,
    //     ", RTP Timestamp: ", ts_rtpTimeStamp,
    //     ", RTCP Timestamp: " + streamdata.rtcpSession.rtpTimestamp);

    // Reference: https://tools.ietf.org/html/rfc3984
    ts_rtpForbiddenZeroBit = (PAYLOAD[0] & 0x80) >> 7;
    ts_rtpNRI = (PAYLOAD[0] & 0x60) >> 5;
    ts_rtpNALType = (PAYLOAD[0] & 0x1f);
    if (ts_rtpNALType == 0) {
        // consolelog("This NAL type does not support on this application. nal_type = " + toHex(ts_rtpNALType));
        // throw new umpError({
        //     channelId: this.channelId,
        //     errorCode: fromHex('0x0101'),
        //     place: 'h264Session.js:155',
        //     message: "This NAL type does not support on this application. nal_type = " + toHex(rtpNALType)
        // });
        ret = 33; // nal type error
    } else {
        // consolelog("H.264 Forbidden Zero Bit: " + ts_rtpForbiddenZeroBit +
        //                                  ", NRI: " + ts_rtpNRI.toString(2) +
        //                                  ", Nal Unit Type: " + toHex(ts_rtpNALType) +
        //                                  ", Payload length: " + PAYLOAD.length);
    }

    switch (true) {
        case ts_rtpNALType == H264NalUnit.H264_NAL_SPS: //SPS
            // consolelog(477);
            ts_FrameBuffer = ts_setBuffer(ts_FrameBuffer, ts_PREFIX);
            // consolelog(479);
            ts_FrameBuffer = ts_setBuffer(ts_FrameBuffer, PAYLOAD);
            // consolelog(481);
            // ts_sps_segment = PAYLOAD;
            storeSPSBuffer(PAYLOAD);
            // consolelog(484);
            ret = 7;
            break;
        case ts_rtpNALType == H264NalUnit.H264_NAL_PPS: //PPS
            // consolelog(488);
            ts_FrameBuffer = ts_setBuffer(ts_FrameBuffer, ts_PREFIX);
            // consolelog(491);
            ts_FrameBuffer = ts_setBuffer(ts_FrameBuffer, PAYLOAD);
            // consolelog(493);
            // ts_pps_segment = PAYLOAD;
            storePPSBuffer(PAYLOAD);
            // consolelog(496);
            ret = 8;
            break;
        case ts_rtpNALType == H264NalUnit.H264_NAL_SPS_EXT: // SPS (Sequence Parameter Set) extension
            // consolelog("H.264 SPS (Sequence Parameter Set) extension" + "\r\n" + "Reference: https://tools.ietf.org/html/rfc3984#section-5.7");
            // throw new umpError({
            //     channelId: this.channelId,
            //     errorCode: fromHex('0x0101'),
            //     place: 'h264Session.js:195',
            //     message: "SPS (Sequence Parameter Set) extension is additional which is not handled in this version. NALType  = " + rtpNALType
            // });
            ret = 44;
            break;
        case ts_rtpNALType == H264NalUnit.H264_NAL_SUB_SPS: // SSPS (Subset Sequence Parameter Set)
            // consolelog("H.264 SSPS (Subset Sequence parameter Set) " + "\r\n" + "Reference: https://tools.ietf.org/html/rfc3984#section-5.7");
            // throw new umpError({
            //     channelId: this.channelId,
            //     errorCode: fromHex('0x0101'),
            //     place: 'h264Session.js:204',
            //     message: "SSPS (Subset Sequence parameter Set) is additional which is not handled in this version. NALType  = " + rtpNALType
            // });
            ret = 55;
            break;
        case ts_rtpNALType == H264NalUnit.H264_NAL_UNSPECIFIED28: // Fragmentation unit(FU)
            // reference Figure 15 from  https://tools.ietf.org/html/rfc3984#section-5.8
            // following FU header format
            let start_bit = ((PAYLOAD[1] & 0x80) === 0x80),
                end_bit = ((PAYLOAD[1] & 0x40) === 0x40),
                reserved_bit = ((PAYLOAD[1] & 0x20) === 0x20),
                fu_type = PAYLOAD[1] & 0x1f,
                payload_start_index = 2;

                // consolelog("start bit: " + start_bit +
                // ", end bit: " + end_bit +
                // ", reserved bit: " + reserved_bit  +
                // ", Fu Type: " + fu_type);

            if (start_bit == true && end_bit == false) {
                var new_nal_header = new Uint8Array(1);
                new_nal_header[0] = (PAYLOAD[0] & 0x60 | fu_type);
                ts_FrameBuffer = ts_setBuffer(ts_FrameBuffer, ts_PREFIX);
                ts_FrameBuffer = ts_setBuffer(ts_FrameBuffer, new_nal_header);
                ts_FrameBuffer = ts_setBuffer(ts_FrameBuffer, PAYLOAD.subarray(payload_start_index, PAYLOAD.length));
            } else {
                ts_FrameBuffer = ts_setBuffer(ts_FrameBuffer, PAYLOAD.subarray(payload_start_index, PAYLOAD.length));
            }
            // consolelog("H.264 Raw Length: " + PAYLOAD.length);
            // consolelog("H.264 Buff Length: " + ts_FrameBuffer.length);
            // console.log("H.264 Raw Length: " + PAYLOAD.length + "\r\nData: ", PAYLOAD);
            // console.log("H.264 Buff Length: " + inputBuffer.length + "\r\nData: ", inputBuffer);
            break;
        case ts_rtpNALType == H264NalUnit.H264_NAL_AUD: // Fragmentation unit(FU)\
            // consolelog("H.264 Coded slice of an (" + ts_rtpNALType  + ").\r\n" + "Reference: https://tools.ietf.org/html/rfc3984#section-5.7");
        // 	break;
        default:
            // consolelog("H.264 Coded slice of an (" + ts_rtpNALType  + ").\r\n" + "Reference: https://tools.ietf.org/html/rfc3984#section-5.7");
            ts_FrameBuffer = ts_setBuffer(ts_FrameBuffer, ts_PREFIX);
            ts_FrameBuffer = ts_setBuffer(ts_FrameBuffer, PAYLOAD);
            break;
    }
    consolelog(551);

    //check marker bit
    if (ts_rtpMarkerBit) {
        // consolelog("H.264 Length: " + ts_inputBuffer.length);
        var inputBufferSub = ts_FrameBuffer.subarray(0, ts_inputLength);
        var frameType = '';

        ts_rtpTimestamp = <i32>Math.round(rtpTimeStamp / 90);
        consolelogs(566, ts_rtpTimestamp);

        // reset input length
        ts_inputLength = 0;

        updatePacketCnt(ts_rtpTimestamp);
        // if (ts_packetSeq === 0) {
        //     ts_startTimestamp = ts_rtpTimestamp;
        // }
        // ts_packetSeq++;

        if ((inputBufferSub[3] & 0x1f) === 0x07) {
            // consolelog("This h.264 parser does not support 3 byte start code.")
            // throw new umpError({
            //     channelId: this.channelId,
            //     errorCode: fromHex('0x0101'),
            //     place: 'h264Session.js:264',
            //     message: "3 byte start code is additional which is not handled in this version. inputBufferSub[3].toString(16): " + inputBufferSub[3].toString(16)
            // });
            ret = 66;
        }

        if ((inputBufferSub[4] & 0x1f) === 0x07 || (inputBufferSub[4] & 0x1f) === 0x09) {
            ts_frameType = 1;// frameType = 'I';
        } else {
            ts_frameType = 2;// frameType = 'P';
        }
        // let playMode = (ts_playback === true) ? 'Playback' : "Live";  //store
        // let streamData = {
        //     'interleaved': streamdata.interleavedId,
        //     'codecType': 'H264',
        //     'frameData': inputBufferSub,  //store
        //     'channelId': streamdata.channelId,
        //     'packetSeq': streamdata.getNumberOfReceivedPacketCount(),  //store
        //     'receiveClock': performance.now(),
        //     'timeStamp': {
        //         'rtpTimestamp': streamdata.rtpTimestamp,  //store
        //         'timestamp': streamdata.timeData.timestamp,  //store
        //         'timestamp_usec': streamdata.timeData.timestamp_usec,  //store
        //         'timezone': streamdata.timeData.timezone  //store
        //     },
        //     'rtcp_interleavedId': streamdata.rtcpSession.interleavedId
        // };
        // let videoInfo = {
        //     'frameType': frameType,        // store
        //     'spsPayload': ts_sps_segment,  // store
        //     'ppsPayload': ts_pps_segment,  // store
        //     'framerate': streamdata.getFramerate()  //store
        // };

        consolelog(606);
        storeFrameBuffer(inputBufferSub);

        // streamdata.eventVideoCallback(playMode, streamData, videoInfo);

        //inputBuffer = new Uint8Array(size_1_4K);
        // var data = {
        // 	index: this.getNumberOfReceivedPacketCount(),
        // 	mode: playMode,
        // 	packet: streamData,
        // 	info: videoInfo
        // }
        // this.addPacket(data);
        ret = 1;

        // return {
        //     playMode,
        //     streamData,
        //     videoInfo
        // };
    } else { // return nothing
        ret = 88;
    }
    consolelog(ret);
    return ret;
}

export function add(a: i32, b: i32): i32 {
  return a + b;
}
