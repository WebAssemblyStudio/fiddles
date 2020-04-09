/* 
 * File:   Main
 * Author: nokotan
 *
 * Created on 2020/01/30, 0:57
 * 
 * DxLibToHTML5雛形ファイル
 */

#include <emscripten/html5.h>
#include <emscripten.h>

#include "DxLib.h"

EM_JS(int, canvas_width, (), {
    return Module.canvas.width;
});

EM_JS(int, canvas_height, (), {
    return Module.canvas.height;
});

static bool shouldExit = false;

int x, add ;

void mainLoop(void*) {
	if( ProcessMessage() != 0 ) {
		shouldExit = true;
	}

	// 移動
	x += add ;
	if( x < 0 || x > 640 ) add = -add ;

	// 画面のクリア
	ClearDrawScreen() ;

	// 四角形の描画
	DrawBox( x, 240 - 32, x + 64, 240 + 32, GetColor( 255,255,255 ), TRUE ) ;

	// 裏画面の内容を表画面に反映
	ScreenFlip() ;
}

int main()
{
	// ＤＸライブラリの初期化
	if( DxLib_Init() < 0 ) return -1 ;

	// 描画先を裏画面にする
	SetDrawScreen( DX_SCREEN_BACK ) ;

	x = 0 ;
	add = 8 ;

	// emscripten_set_canvas_element_size("canvas", 1024, 600);
	emscripten_set_main_loop_arg(mainLoop, NULL, 0, 1);

	// ソフトの終了
	return 0 ;
}
