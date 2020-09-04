local internalPackets = [];

function getPacket() {
  if (internalPackets.len() == 0) {
    return {id = -1};
  }
  return internalPackets.pop();
}

function gotPacketInternal(packetId, ...) {
  print("PacketID: " + packetId);
 
  for(local i = 0; i< vargv.len(); i++)
  {
    print("varparam "+i+" = "+vargv[i]);
  }
  internalPackets.insert(0, {id = packetId, args = vargv});
}

local mac = [0xdc, 0x4f, 0x22, 0x5f, 0x22, 0x50]

function clear_screen() {
  for (local y = 0; y < 20; y++) {
    load_background_line(y, ' ');
  }

    load_background_line(0, ' ');

}

function setup() {
  print("Setup");
  clear_screen();
  
  //a low
  send_tile(0, 0);
  send_tile(1, 1);
  send_tile(2, 16);
  send_tile(3, 17);
  
  //b low
  send_tile(4, 2);
  send_tile(5, 3);
  send_tile(6, 18);
  send_tile(7, 19);
  
  //a high
  send_tile(8, 32);
  send_tile(9, 33);
  send_tile(10, 48);
  send_tile(11, 49);
  
  //b high
  send_tile(12, 34);
  send_tile(13, 35);
  send_tile(14, 50);
  send_tile(15, 51);
  
  //start and select
  send_tile(16, 5);
  send_tile(17, 6);
  
  //start and select selected 
  send_tile(18, 21);
  send_tile(19, 22);
  
  //directionals
  send_tile(20, 7); 
  send_tile(21, 8);
  
  
  //mac address
  //start_esp_now(mac);
}
function CHECK_BIT(var,pos) {
  return ((((var)>>(pos)) & 1) == 1)
}
local lastKeyCode = 300;
function update(keyCode) {
  //send_esp_now_message("controller", keyCode);
  if (keyCode != lastKeyCode) {
    //a
    if (CHECK_BIT(keyCode,0)) {
      set_tile(8,16,6);
      set_tile(9,17,6);
      set_tile(10,16,7);
      set_tile(11,17,7);
    } else {
      set_tile(0,16,6);
      set_tile(1,17,6);
      set_tile(2,16,7);
      set_tile(3,17,7);
    }
    //b
    if (CHECK_BIT(keyCode,1)) {
      set_tile(12,13,8);
      set_tile(13,14,8);
      set_tile(14,13,9);
      set_tile(15,14,9);
    } else {
      set_tile(4,13,8);
      set_tile(5,14,8);
      set_tile(6,13,9);
      set_tile(7,14,9);
    }
    //select
    if (CHECK_BIT(keyCode,2)) {
      set_tile(18,7,13);
      set_tile(19,8,13);
      //start_vibrating();
    } else {
      set_tile(16,7,13);
      set_tile(17,8,13);
      //stop_vibrating();
    }
    //start
    if (CHECK_BIT(keyCode,3)) {
      set_tile(18,11,13);
      set_tile(19,12,13);
    } else {
      set_tile(16,11,13);
      set_tile(17,12,13);
    }
   
    //right
    if (CHECK_BIT(keyCode,4)) {
      set_tile(21,6,7);
    } else {
      set_tile(20,6,7);
    }
    //left
    if (CHECK_BIT(keyCode,5)) {
      set_tile(21,2,7);
    } else {
      set_tile(20,2,7);
    }
    //up
    if (CHECK_BIT(keyCode,6)) {
      set_tile(21,4,5);
    } else {
      set_tile(20,4,5);
    }
    //down
    if (CHECK_BIT(keyCode,7)) {
      set_tile(21,4,9);
    } else {
      set_tile(20,4,9);
    }
    
    lastKeyCode = keyCode;
  }
}