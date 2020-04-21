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

#define VERT_X	80
#define VERT_Y	45

static bool shouldExit = false;

VERTEX2D vertex[VERT_Y][VERT_X];
unsigned short indices[(VERT_Y - 1)*(VERT_X - 1)*6];
int indices_setup;

// Online Sample: nokotan.github.io/WebAssemblyStudio/?f=fdm81i856i9
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
	
//	if (AutoColorChange)
//	{
// 	 	for (int i = 0; i < 4; i++)
//	 	{
//	 		int h, l, s;
//	 		RGBtoHLS(red[i], green[i], blue[i], &h, &l, &s);
//	 		int color_h = GetColorHLS(h + GetKey(KEY_COUNT), l, s);		// 少しづつ色を変化させる
//	 		GetColor2(color_h, &red[i], &green[i], &blue[i]);
//	 	}
//	}

	// 各頂点の情報をセット
	for (int i = 0; i < VERT_Y; i++)
	{
		for (int j = 0; j < VERT_X; j++)
		{
			vertex[i][j].pos.x = static_cast<float>(x2 - x1) * j / (VERT_X - 1) + static_cast<float>(x1);
			vertex[i][j].pos.y = static_cast<float>(y2 - y1) * i / (VERT_Y - 1) + static_cast<float>(y1);

			vertex[i][j].dif.r = static_cast<BYTE>((((red[0]  *((VERT_X - 1) - j) + red[1]  *j) / (VERT_X - 1) * ((VERT_Y - 1) - i) + (red[2]  *((VERT_X - 1) - j) + red[3]  *j) / (VERT_X - 1) * i)) / (VERT_Y - 1));
			vertex[i][j].dif.g = static_cast<BYTE>((((green[0]*((VERT_X - 1) - j) + green[1]*j) / (VERT_X - 1) * ((VERT_Y - 1) - i) + (green[2]*((VERT_X - 1) - j) + green[3]*j) / (VERT_X - 1) * i)) / (VERT_Y - 1));
			vertex[i][j].dif.b = static_cast<BYTE>((((blue[0] *((VERT_X - 1) - j) + blue[1] *j) / (VERT_X - 1) * ((VERT_Y - 1) - i) + (blue[2] *((VERT_X - 1) - j) + blue[3] *j) / (VERT_X - 1) * i)) / (VERT_Y - 1));

			vertex[i][j].pos.z = 0.0f;
			vertex[i][j].rhw = 1.0f;
			vertex[i][j].dif.a = 0xff;
			vertex[i][j].u = 0.0f;
			vertex[i][j].v = 0.0f;
		}
	}

	// 頂点インデックスを作成
	if( indices_setup == 0 )
	{
		indices_setup = 1;
		int k = 0;
		for (int i = 0; i < VERT_Y - 1; i++)
		{
			for (int j = 0; j < VERT_X - 1; j++)
			{
				indices[k] = static_cast<unsigned short>(i * VERT_X + j);
				indices[k + 1] = static_cast<unsigned short>(i * VERT_X + j + 1);
				indices[k + 2] = static_cast<unsigned short>(( i + 1 ) * VERT_X + j);
				indices[k + 3] = static_cast<unsigned short>(( i + 1 ) * VERT_X + j + 1);
				indices[k + 4] = static_cast<unsigned short>(( i + 1 ) * VERT_X + j);
				indices[k + 5] = static_cast<unsigned short>(i * VERT_X + j + 1);
				k += 6;
			}
		}
	}

	return DrawPolygonIndexed2D(&vertex[0][0], VERT_X * VERT_Y, indices, (VERT_Y - 1)*(VERT_X - 1)*6, DX_NONE_GRAPH, FALSE);
}

void mainLoop(void*) {
    if (ProcessMessage() == -1) {
        shouldExit = true;
    }

    ClearDrawScreen();

    {
      DrawBoxGrad(32, 32, 640 - 32, 480 - 32, GetColor(255, 0, 0), GetColor(0, 255, 255), GetColor(255, 0, 255), GetColor(255, 255, 0), false);
    }

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