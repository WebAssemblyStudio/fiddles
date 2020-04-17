#include "DxLib.h"

#ifdef EMSCRIPTEN
#  include <emscripten.h>

EM_JS(int, canvas_width, (), {
    return Module.canvas.width;
});

EM_JS(int, canvas_height, (), {
    return Module.canvas.height;
});
#endif

static bool shouldExit = false;

// グラデーションカラーの四角形を描画する
int DrawBoxGrad(int x1, int y1, int x2, int y2, int Colorlt, int Colorrt, int Colorlb, int Colorrb, bool AutoColorChange)
{
	int red[4], green[4], blue[4];
	if (Colorlb == 0) Colorlb = Colorlt;		// 四角形の左下の色が指定されていなければ上の色をコピーする
	if (Colorrb == 0) Colorrb = Colorrt;		// 四角形の右下の色が指定されていなければ上の色をコピーする
	GetColor2(Colorlt, &red[0], &green[0], &blue[0]);
	GetColor2(Colorrt, &red[1], &green[1], &blue[1]);
	GetColor2(Colorlb, &red[2], &green[2], &blue[2]);
	GetColor2(Colorrb, &red[3], &green[3], &blue[3]);
	
	// if (AutoColorChange)
	// {
	// 	for (int i = 0; i < 4; i++)
	// 	{
	// 		int h, l, s;
	// 		RGBtoHLS(red[i], green[i], blue[i], &h, &l, &s);
	// 		int color_h = GetColorHLS(h + GetKey(KEY_COUNT), l, s);		// 少しづつ色を変化させる
	// 		GetColor2(color_h, &red[i], &green[i], &blue[i]);
	// 	}
	// }

	VERTEX2D vertex[5];
	for (int i = 0; i < 5; i++)
	{
		vertex[i].pos.z = 0.0f;
		vertex[i].rhw = 1.0f;
		vertex[i].dif.a = 0xff;
		vertex[i].u = 0.0f;
		vertex[i].v = 0.0f;
	}

	// 左上の頂点の情報をセット
	vertex[0].pos.x = static_cast<float>(x1);
	vertex[0].pos.y = static_cast<float>(y1);
	vertex[0].dif.r = static_cast<BYTE>(red[0]);
	vertex[0].dif.g = static_cast<BYTE>(green[0]);
	vertex[0].dif.b = static_cast<BYTE>(blue[0]);

	// 右上の頂点の情報をセット
	vertex[1].pos.x = static_cast<float>(x2);
	vertex[1].pos.y = static_cast<float>(y1);
	vertex[1].dif.r = static_cast<BYTE>(red[1]);
	vertex[1].dif.g = static_cast<BYTE>(green[1]);
	vertex[1].dif.b = static_cast<BYTE>(blue[1]);

	// 右下の頂点の情報をセット
	vertex[2].pos.x = static_cast<float>(x2);
	vertex[2].pos.y = static_cast<float>(y2);
	vertex[2].dif.r = static_cast<BYTE>(red[2]);
	vertex[2].dif.g = static_cast<BYTE>(green[2]);
	vertex[2].dif.b = static_cast<BYTE>(blue[2]);

	// 左下の頂点の情報をセット
	vertex[3].pos.x = static_cast<float>(x1);
	vertex[3].pos.y = static_cast<float>(y2);
	vertex[3].dif.r = static_cast<BYTE>(red[3]);
	vertex[3].dif.g = static_cast<BYTE>(green[3]);
	vertex[3].dif.b = static_cast<BYTE>(blue[3]);

	// 右下の頂点の情報をセッ���
	vertex[4].pos.x = static_cast<float>(x1 + x2) / 2;
	vertex[4].pos.y = static_cast<float>(y1 + y2) / 2;
	vertex[4].dif.r = static_cast<BYTE>((red[0] + red[1] + red[2] + red[3]) / 4);
	vertex[4].dif.g = static_cast<BYTE>((green[0] + green[1] + green[2] + green[3]) / 4);
	vertex[4].dif.b = static_cast<BYTE>((blue[0] + blue[1] + blue[2] + blue[3]) / 4);	

  unsigned short indices[] = { 0, 1, 4, 1, 2, 4, 2, 3, 4, 3, 0, 4};

	return DrawPolygonIndexed2D(vertex, 5, indices, 4, DX_NONE_GRAPH, FALSE);		// ポリゴンを2個描画する
}

void mainLoop(void*) {
    if (ProcessMessage() == -1) {
        shouldExit = true;
    }

    ClearDrawScreen();
    DrawBoxGrad(30, 30, 640 - 30, 480 - 30, GetColor(255, 0, 0), GetColor(0, 255, 0), GetColor(255, 255, 0), GetColor(0, 255, 255), false);

    ScreenFlip();
}

#ifdef _WIN32
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
#else
int main () {
#endif
    SetGraphMode(640, 480, 32);

    if (DxLib_Init() == -1) {
        return -1;
    }

    // ChangeFont("assets/07LogoTypeGothic7.ttf");
    SetDrawScreen(DX_SCREEN_BACK);

#ifdef EMSCRIPTEN
    emscripten_set_main_loop_arg(mainLoop, NULL, 0, 1);	
#else
    while (!shouldExit) {
        mainLoop(NULL);
    }
    
    DxLib_End();
#endif

    return 0;
}