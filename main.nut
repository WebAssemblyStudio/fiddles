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
  //clear_screen();
  
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
  
  set_tile(1,1,'A');
  //mac address
  //start_esp_now(mac);
}
function CHECK_BIT(var,pos) {
  return ((((var)>>(pos)) & 1) == 1)
}
local lastKeyCode = 300;
function update(keyCode) {
  set_tile('A',1,1);
  set_tile(20,2,2);
}