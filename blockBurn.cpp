#include<iostream>
#include<DxLib.h>
using namespace std;
#define A 4; //	ボールx速度

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE); //非全画面表示
	SetGraphMode(640, 480, 32); //画面サイズ指定
	SetOutApplicationLogValidFlag(FALSE); //log.txtの非表示
	if (DxLib_Init() == 1) {
		return -1;
	}     //初期化失敗時にエラーを出力し終了
	int i, j[4], mx, my, cx, cy;
	i = 1;
	j[1] = 0;//ボールx座標速さ 左右切り替え変数
	j[2] = 0;//ボールy座標速さ 上下切り替え変数
	mx = 0; //マウスx座標取得用
	my = 0; //マウスy座標取得用
	cx = 320; //ボールx座標
	cy = 240; //ボールy座標
	struct Block { //ブロックの情報
		int k;  //存在するか否か
		int bx; //ブロック座標右
		int by; //ブロック座標上
	};
	Block block[26] = { 0 };
	while (i <= 24) {
		block[i].k = 1;
		block[i].bx = 620;
		block[i].by = 20 * (i - 1);
		i = i + 1;
	}



	while (ProcessMessage() == 0) //ゲーム内容
	{
		ClearDrawScreen(); //裏画面消す
		SetDrawScreen(DX_SCREEN_BACK);//描画先を裏画面に持っていく
		DrawFormatString(0, 0, GetColor(255, 221, 181), "ブロック崩しver1.0.1");
		DrawCircle(cx, cy, 6, GetColor(0, 0, 205), 1);
		GetMousePoint(&mx, &my);
		for (i = 1; i <= 24; i++) { //ブロックの表示(判別付き)
			if (block[i].k == 1) {
				DrawBox(620, 20 * (i - 1), 630, 20 * i, GetColor(255, 0, 255), 0);
			}
		}
		if (cx + 6 >= 640) { //右端当たり判定
			j[1] = 0;
		}
		if (cy - 6 <= 0 || cy + 6 >= 480) { //上下当たり判定
			if (j[2] == 0) j[2] = 1;
			else if (j[2] == 1) j[2] = 0;
		}
		if (cx + 6 >= 610 && cx - 6 <= 610) {
			for (i = 1; i <= 24; i++) {
				if (block[i].k == 1) { //もしブロックが存在したら
					if (cy + 2 >= block[i].by && cy - 2 <= block[i].by + 20) {
						if (j[1] == 0) j[1] = 1;
						if (j[1] == 1) j[1] = 0;
						block[i].k = 0;
					}
				}
			}
		}
		if (cx - 6 <= 620 && cx + 6 >= 620) {
			for (i = 1; i <= 24; i++) {
				if (block[i].k == 1) {
					if (cy + 2 >= block[i].by && cy - 2 <= block[i].by + 20) {
						if (j[1] == 0) j[1] = 1;
						if (j[1] == 1) j[1] = 0;
						block[i].k = 0;
					}
				}
			}
		}
		if (cx - 6 <= 110 && cx + 6 >= 110 && cy - 6 <= my + 30 && cy + 6 >= my) { //打ち返しバー当たり判定
			j[1] = 1;
			if (my >= cy - 1 && my <= cy + 1) { //右上エッジの処理
				j[2] = 0;
			}
			if (my + 30 >= cy - 1 && my + 30 <= cy + 1) {  //右下エッジの処理
				j[2] = 1;
			}
		}
		DrawBox(100, my, 110, my + 30, GetColor(0, 255, 0), 1);
		if (j[1] == 1) {
			cx = cx + A;
			if (j[2] == 1) {
				cy = cy + 2;
			}
			else if (j[2] == 0) cy = cy - 2;
		}
		else if (j[1] == 0) {
			cx = cx - A;
			if (j[2] == 1) {
				cy = cy + 2;
			}
			else if (j[2] == 0) cy = cy - 2;
		}
		if (cx <= 0) break; //左端で終了
		i = 0;
		ScreenFlip();
	}
	WaitKey();
	DxLib_End();
	return 0;

}