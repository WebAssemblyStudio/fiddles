const HEIGHT = 16;
const WIDTH = 16;
const PIXEL = 4;
const FRAME_RATE = 10;

var get_ctx = () => document.getElementById('canvas').getContext('2d');
var g_key;

function get_random (min, max) {	
	var num = Math.floor(Math.random()*(max - min)) + min;	
	return num;	
}

function draw_body(x, y)
{
  var ctx = get_ctx();
  ctx.fillStyle = '#246417';
  ctx.fillRect(x, y, HEIGHT, WIDTH);
}

function remove_body(x, y)
{
  var ctx = get_ctx();
  ctx.fillStyle = '#9dff00';
  ctx.fillRect(x, y, HEIGHT, WIDTH);
}

function draw_fruit_1(x, y)
{
  /**  *  *
        **
        **
       *  *   */

  var ctx = get_ctx();
  ctx.fillStyle = '#246417';
  ctx.fillRect(x, y, PIXEL, PIXEL);
  ctx.fillRect(x + (3 * PIXEL) , y, PIXEL, PIXEL);
  ctx.fillRect(x + (1 * PIXEL), y + (1 * PIXEL), (2 * PIXEL), (2 * PIXEL));
  ctx.fillRect(x, y + (3 * PIXEL), PIXEL, PIXEL);
  ctx.fillRect(x + (3 * PIXEL), y + (3 * PIXEL), PIXEL, PIXEL);
}

function draw_fruit_2(x, y)
{
  /**    **
         **
        *  *
        *  *   */

  var ctx = get_ctx();
  ctx.fillStyle = '#246417';
  ctx.fillRect(x + PIXEL, y, (2 *PIXEL), (2 *PIXEL));
  ctx.fillRect(x, y + (2 * PIXEL), PIXEL, (2 *PIXEL));
  ctx.fillRect(x + (3 * PIXEL), y + (2 * PIXEL), PIXEL, (2 *PIXEL));
}

function draw_at(x, y, type)
{
  switch (type){
    case 0:
      draw_body(x, y)
      break
    case 1:
      remove_body(x,y)
      break
    case 2:
      draw_fruit_1(x, y)
      break
    case 3:
      draw_fruit_2(x, y)
      break
  }
}

function input_store(key, state) 
{
    g_key = key;
}

function get_input() 
{
    switch (g_key) 
    {
      case "ArrowUp":
        return 10;
      case "ArrowDown":
        return 5;
      case "ArrowRight":
        return 3;
      case "ArrowLeft":
        return 12;
      case " ":
        return 15;
      case "r":
      case "R":
        g_key = ""
        return 1;

      default:
        return 0
    }
  }

function draw_clear_board(){
  var ctx = get_ctx();
  ctx.fillStyle = '#9dff00';
  ctx.fillRect(0 , 0 , canvas.width , canvas.height)
}

function draw_game_lost(){
    var ctx = get_ctx();
    ctx.fillStyle = '#9dff00';
    ctx.fillRect(0 , 0 , canvas.width , canvas.height)

    ctx.font = "bold 30px Courier New";
    ctx.fillStyle = '#246417';
    ctx.textAlign = "center";
    ctx.fillText("Game Over!", canvas.width/2, canvas.height/2);

    ctx.font = "bold 20px Courier New";
    ctx.fillText("(R)eplay", canvas.width/2 - 2, canvas.height/2 + 40);

    ctx.lineWidth = 2;
    ctx.strokeStyle = "#246417";
    ctx.strokeRect(canvas.width/2 -104 , canvas.height/2 -30,204,40)
}

imports = {
    draw_at: draw_at,
    get_input: get_input,
    console_log: arg => console.log(arg),
    stackSave: () => 0,
    stackRestore: () => 0,
    get_random: get_random,
    draw_game_lost: draw_game_lost,
    draw_clear_board: draw_clear_board
    

}

if (typeof mergeInto !== 'undefined') mergeInto(LibraryManager.library, imports);

function game_start(game_iter)
{  
    interval = setInterval(game_iter, 1000 / FRAME_RATE);
}

function game_stop()
{
    clearInterval(interval);
}