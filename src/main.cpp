# include <Siv3D.hpp>

void Main()
{
  // 画像ファイルから Image を作成
	const Image image{ U"./l_ky_Illusion-05.jpg" };

	// Image から　Texture を作成
	const Texture texture{ image };
	Platform::Web::System::SetMainLoop([&]
  {
    System::Update();

		const Point pos = Cursor::Pos();

		if (InRange(pos.x, 0, image.width() - 1)
			&& InRange(pos.y, 0, image.height() - 1))
		{
			// マウスカーソルの位置にあるピクセルの色を取得
			const Color pixelColor = image[pos];

			Rect{ 500, 20, 40 }.draw(pixelColor);

			PutText(U"{}"_fmt(pixelColor), Arg::topLeft(560, 20));
		}

		texture.draw();
  });
}