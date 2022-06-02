# include <Siv3D.hpp>

void Main()
{
	// ウィンドウを 1280x720 にリサイズ
	Window::Resize(1280, 720);

	// 2D 物理演算のシミュレーションステップ（秒）
	constexpr double stepSec = (1.0 / 200.0);

	// 2D 物理演算のシミュレーション蓄積時間（秒）
	double accumulatorSec = 0.0;

	// 2D 物理演算のワールド
	P2World world;

	// [_] 地面
	const P2Body ground = world.createLine(P2Static, Vec2{ 0, 0 }, Line{ -600, 0, 600, 0 });

	// 物体
	Array<P2Body> bodies;

	// 2D カメラ
	Camera2D camera{ Vec2{ 0, -300 } };

	LineString points;

	Platform::Web::System::SetMainLoop([&]
  {
    System::Update();
		for (accumulatorSec += Scene::DeltaTime(); stepSec <= accumulatorSec; accumulatorSec -= stepSec)
		{
			// 2D 物理演算のワールドを更新
			world.update(stepSec);
		}

		// 地面より下に落ちた物体は削除
		bodies.remove_if([](const P2Body& b) { return (200 < b.getPos().y); });

		// 2D カメラの更新
		camera.update();
		{
			// 2D カメラから Transformer2D を作成
			const auto t = camera.createTransformer();

			// 左クリックもしくはクリックしたままの移動が発生したら
			if (MouseL.down() ||
				(MouseL.pressed() && (not Cursor::DeltaF().isZero())))
			{
				points << Cursor::PosF();
			}
			else if (MouseL.up())
			{
				points = points.simplified(2.0);

				if (const Polygon polygon = Polygon::CorrectOne(points))
				{
					const Vec2 pos = polygon.centroid();

					bodies << world.createPolygon(P2Dynamic, pos, polygon.movedBy(-pos));
				}

				points.clear();
			}

			// すべてのボディを描画
			for (const auto& body : bodies)
			{
				body.draw(HSV{ body.id() * 10.0 });
			}

			// 地面を描画
			ground.draw(Palette::Skyblue);

			points.draw(3);
		}

		// 2D カメラの操作を描画
		camera.draw(Palette::Orange);
  });
}