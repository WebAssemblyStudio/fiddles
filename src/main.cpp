# include <Siv3D.hpp>

void Main()
{
	// ウィンドウを 1280x720 にリサイズ
	Window::Resize(1280, 720);

	// 背景色を設定
	Scene::SetBackground(ColorF{ 0.2 });

	// 2D 物理演算のシミュレーションステップ（秒）
	constexpr double stepSec = (1.0 / 200.0);

	// 2D 物理演算のシミュレーション蓄積時間（秒）
	double accumulatorSec = 0.0;

	// 2D 物理演算のワールド
	P2World world;

	const P2Body rail = world.createLineString(P2Static, Vec2{ 0, -400 }, { Vec2{-400, -40}, Vec2{-400, 0}, Vec2{400, 0}, {Vec2{400, -40}} });
	const P2Body wheel = world.createCircle(P2Dynamic, Vec2{ 0, -420 }, 20);
	const P2Body car = world.createCircle(P2Dynamic, Vec2{ 0, -380 }, 10).setFixedRotation(true);

	// ホイールジョイント
	const P2WheelJoint wheelJoint = world.createWheelJoint(car, wheel, wheel.getPos(), Vec2{ 0, 1 })
		.setLimitsEnabled(true);

	const P2Body box = world.createPolygon(P2Dynamic, Vec2{ 0, 0 }, LineString{ Vec2{-100, 0}, Vec2{-100, 100}, Vec2{100, 100}, {Vec2{100, 0}} }.calculateBuffer(5), P2Material{ .friction = 0.0 });

	// 距離ジョイント
	const P2DistanceJoint distanceJointL = world.createDistanceJoint(car, car.getPos(), box, Vec2{ -100, 0 }, 400);
	const P2DistanceJoint distanceJointR = world.createDistanceJoint(car, car.getPos(), box, Vec2{ 100, 0 }, 400);

	Array<P2Body> balls;

	// マウスジョイント
	P2MouseJoint mouseJoint;

	// 2D カメラ
	Camera2D camera{ Vec2{ 0, -150 } };

	Print << U"[Space]: 粒子を放出";

	Platform::Web::System::SetMainLoop([&]
  {
    System::Update();
		for (accumulatorSec += Scene::DeltaTime(); stepSec <= accumulatorSec; accumulatorSec -= stepSec)
		{
			world.update(stepSec);
		}

		// こぼれたボールの削除
		balls.remove_if([](const P2Body& b) { return (600 < b.getPos().y); });

		// 2D カメラの更新
		camera.update();
		{
			// 2D カメラから Transformer2D を作成
			const auto t = camera.createTransformer();

			// マウスジョイントによる干渉
			if (MouseL.down())
			{
				mouseJoint = world.createMouseJoint(box, Cursor::PosF())
					.setMaxForce(box.getMass() * 5000.0)
					.setLinearStiffness(2.0, 0.7);
			}
			else if (MouseL.pressed())
			{
				mouseJoint.setTargetPos(Cursor::PosF());
			}
			else if (MouseL.up())
			{
				mouseJoint.release();
			}

			if (KeySpace.pressed())
			{
				// ボールの追加
				balls << world.createCircle(P2Dynamic, Cursor::PosF(), Random(2.0, 4.0), P2Material{ .density = 0.001, .restitution = 0.5, .friction = 0.0 });
			}

			rail.draw(Palette::Gray);
			wheel.draw(Palette::Gray).drawWireframe(1, Palette::Yellow);
			car.draw(ColorF{ 0.3, 0.8, 0.5 });
			box.draw(ColorF{ 0.3, 0.8, 0.5 });

			for (const auto& ball : balls)
			{
				ball.draw(Palette::Skyblue);
			}

			distanceJointL.draw();
			distanceJointR.draw();

			mouseJoint.draw();
		}

		// 2D カメラの操作を描画
		camera.draw(Palette::Orange);
  });
}