# include <Siv3D.hpp>

// ランダムな長方形の配列を作成
Array<Rect> GenerateRandomRects()
{
	Array<Rect> rects(Random(4, 32));

	for (auto& rect : rects)
	{
		const Point pos = RandomPoint(Rect{ Scene::Size() - Size{ 150, 150 } });
		rect.set(pos, Random(20, 150), Random(20, 150));
	}

	return rects;
}

void Main()
{
	Window::Resize(1280, 720);
	Scene::SetBackground(ColorF{ 0.99 });
	Array<Rect> input;
	Array<double> rotations;
	RectanglePack output;
	Point offset{ 0, 0 };
	Stopwatch stopwatch;

	Platform::Web::System::SetMainLoop([&]
  {
    System::Update();
		if ((not stopwatch.isStarted()) || (1.8s < stopwatch))
		{
			input = GenerateRandomRects();
			rotations.resize(input.size());
			rotations.fill(0.0);
			output = RectanglePacking::Pack(input, 1024, AllowFlip::Yes);

			for (size_t i = 0; i < input.size(); ++i)
			{
				if (input[i].w != output.rects[i].w)
				{
					rotations[i] = 270_deg;
				}
			}

			// 画面中央に表示するよう位置を調整
			offset = (Scene::Size() - output.size) / 2;
			for (auto& rect : output.rects)
			{
				rect.moveBy(offset);
			}

			stopwatch.restart();
		}

		// アニメーション
		const double k = Min(stopwatch.sF() * 10, 1.0);
		const double t = Math::Saturate(stopwatch.sF() - 0.2);
		const double e = EaseInOutExpo(t);

		Rect{ offset, output.size }.draw(ColorF{ 0.7, e });

		for (auto i : step(input.size()))
		{
			const RectF in = input[i].scaledAt(input[i].center(), k);
			const RectF out = output.rects[i];
			const Vec2 center = in.center().lerp(out.center(), e);
			const RectF rect{ Arg::center = center, in.size };

			rect.rotatedAt(rect.center(), Math::Lerp(0.0, rotations[i], e))
				.draw(HSV{ i * 25.0, 0.65, 0.9 })
				.drawFrame(2, 0, ColorF{ 0.25 });
		}
  });
}


