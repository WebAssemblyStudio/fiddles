# include <Siv3D.hpp>

void Main()
{
	Window::Resize(1280, 720);

	// Web カメラを非同期で起動
	AsyncTask<Webcam> task{ []() { return Webcam{ 0, Size{ 1280, 720 }, StartImmediately::Yes }; } };
	Webcam webcam;

	// Web カメラ画像の表示用テクスチャ
	DynamicTexture texture;
	Image image;

	// 顔検出用の分類器をロード
	const CascadeClassifier cascade{ U"example/objdetect/haarcascade/frontal_face_alt2.xml" };
	Array<Rect> faces;

	Platform::Web::System::SetMainLoop([&]
  {
    System::Update();
		if ((not webcam) && (not task.isValid()))
		{
			if (SimpleGUI::Button(U"Retry", Vec2{ 20, 20 }))
			{
				// Web カメラを非同期で再起動
				task = AsyncTask{ []() { return Webcam{ 0, Size{ 1280, 720 }, StartImmediately::Yes }; } };
			}
		}

		if (task.isReady())
		{
			webcam = task.get();
		}

		if (webcam.hasNewFrame())
		{
			webcam.getFrame(image);

			// 顔を検出
			faces = cascade.detectObjects(image);

			texture.fill(image);
		}

		// Web カメラ起動待機中は円を表示
		if (not webcam)
		{
			Circle{ Scene::Center(), 40 }.drawArc(Scene::Time() * 180_deg, 300_deg, 5, 5);
		}

		if (texture)
		{
			texture.draw();
		}

		for (const auto& face : faces)
		{
			face.drawFrame(4, Palette::Red);
		}
  });
}