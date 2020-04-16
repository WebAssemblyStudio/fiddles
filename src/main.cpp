# include "DxLib.h"
# include <emscripten.h>
# include <stdlib.h>

EM_JS(int, canvas_width, (), {
    return Module.canvas.width;
});

EM_JS(int, canvas_height, (), {
    return Module.canvas.height;
});

// 乗算済みアルファで大量にアンチエイリアス付き図形を描画する
float Xpos, Ypos, Size;
int	Color;
int Screen;

//描画座標用編集初期化
int DrawPosX = 0;

void mainLoop(void*) {
  if (ProcessMessage() == -1) {
    DxLib_End();
    emscripten_cancel_main_loop();
    return;
  }

  //この辺はグラデーション描画するための準備なんで今回のサンプルとはあんま関係ないです。
  //グラデーション描画用ポリゴン構造体配列宣言
  VERTEX2D Vert[4] = {
    {VGet(0.0f, 0.0f, 0.0f),1.0f,GetColorU8(255, 0, 0, 255),0.0f,0.0f} ,
    {VGet(640.0f, 0.0f, 0.0f),1.0f,GetColorU8(0, 255, 0, 255),0.0f,0.0f} ,
    {VGet(640.0f, 480.0f, 0.0f),1.0f,GetColorU8(0, 0, 255, 255),0.0f,0.0f} ,
    {VGet(0.0f, 480.0f, 0.0f),1.0f,GetColorU8(128, 128, 128, 255),0.0f,0.0f} };
  //グラデーション描画用頂点インデックス
  unsigned short Indices[6] = { 0,1,2,2,3,0 };

  // 背景をポリゴンでグラデーション描画
  SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
  DrawPolygonIndexed2D(Vert, 6, Indices, 3, DX_NONE_GRAPH, FALSE);

  // 乗算済みアルファ用のアルファブレンドモードを使ってグラフィックハンドルを描画
  SetDrawBlendMode(DX_BLENDMODE_PMA_ALPHA, 255);
  DrawGraph(DrawPosX, 0, Screen, TRUE);
  DrawGraph(DrawPosX - 640, 0, Screen, TRUE);

  //座標移動
  DrawPosX += 2;
  if (DrawPosX > 640)DrawPosX -= 640;

  // 裏画面の内容を表画面に反映
  ScreenFlip();
}

int main () {
 	// 画面サイズを400x200にする
	SetGraphMode(640, 480, 32);

	// ＤＸライブラリの初期化
	if (DxLib_Init() < 0) return -1;

	// グラフィックハンドルを作成
	Screen = MakeScreen(640, 480, TRUE);
	// 作成したグラフィックハンドルを描画対象にする
	SetDrawScreen(Screen);
	// 背景色を黒に変更してクリア(デフォルトで黒だしクリアされてるけど一応…)
	SetBackgroundColor(0, 0, 0, 0);
	ClearDrawScreen();

	for (int i = 0; i < 1000; i++) {
		SetDrawBlendMode(DX_BLENDMODE_PMA_ALPHA, (rand() % 192) + 64);//あんまり薄いと見えないので最低でも64
		Xpos = 0.1f * (rand() % 6200 + 100);
		Ypos = 0.1f * (rand() % 4600 + 100);
		Size = 0.1f * (rand() % 50 + 50);//あんまり小いさいと見えないので最低でも5ピクセル
		Color = GetColor(rand() % 256, rand() % 256, rand() % 256);
		switch (rand() % 5) {
		case 0://四角を描く
			DrawBoxAA(Xpos - Size, Ypos - Size, Xpos + Size, Ypos + Size, Color, TRUE);
			break;
		case 1://円を描く
			DrawCircleAA(Xpos, Ypos, Size, 32,Color, TRUE);
			break;
		case 2://楕円を描く(実はひし形)
			DrawOvalAA(Xpos, Ypos, Size, Size * 1.5f, 4, Color, TRUE);
			break;
		case 4://三角を描く
			DrawTriangleAA(Xpos, Ypos - Size, Xpos - Size, Ypos + Size, Xpos + Size, Ypos + Size, Color, TRUE);
			break;
		}
	}

	// 描画先を裏画面に変更
	SetDrawScreen(DX_SCREEN_BACK);

  emscripten_set_main_loop_arg(mainLoop, NULL, 0, 1);
  return 0;
}