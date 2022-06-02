# include <Siv3D.hpp>

// 羽根が回転する風車用の描画関数
void DrawMillModel(const Model& model, const Mat4x4& mat)
{
	const auto& materials = model.materials();

	for (const auto& object : model.objects())
	{
		Mat4x4 m = Mat4x4::Identity();

		// 風車の羽根の回転
		if (object.name == U"Mill_Blades_Cube.007")
		{
			m *= Mat4x4::Rotate(Vec3{ 0,0,-1 }, (Scene::Time() * -120_deg), Vec3{ 0, 9.37401, 0 });
		}

		const Transformer3D t{ (m * mat) };

		object.draw(materials);
	}
}

void Main()
{
	Window::Resize(1280, 720);

	const Mesh groundPlane{ MeshData::OneSidedPlane(2000, { 400, 400 }) };
	const Texture groundTexture{ U"example/texture/ground.jpg", TextureDesc::MippedSRGB };
	const Model blacksmithModel{ U"example/obj/blacksmith.obj" };
	const Model millModel{ U"example/obj/mill.obj" };
	const Model treeModel{ U"example/obj/tree.obj" };
	const Model pineModel{ U"example/obj/pine.obj" };
	Model::RegisterDiffuseTextures(treeModel, TextureDesc::MippedSRGB);
	Model::RegisterDiffuseTextures(pineModel, TextureDesc::MippedSRGB);

	const MSRenderTexture renderTexture{ Scene::Size(), TextureFormat::R8G8B8A8_Unorm_SRGB, HasDepth::Yes };
	DebugCamera3D camera{ Graphics3D::GetRenderTargetSize(), 40_deg, Vec3{ 0, 3, -16 } };

	Sky sky;
	double skyTime = 0.5;
	bool showUI = true;

	Platform::Web::System::SetMainLoop([&]
  {
    System::Update();
		// [3D シーンの描画]
		{
			const ScopedRenderTarget3D target{ renderTexture.clear(ColorF{ 0.0 }) };
			camera.update(4.0);
			Graphics3D::SetCameraTransform(camera);

			// [モデルの描画]
			{
				// 地面の描画
				groundPlane.draw(groundTexture);

				// 球の描画
				Sphere{ { 0, 1, 0 }, 1 }.draw(ColorF{ 0.75 }.removeSRGBCurve());

				// 鍛冶屋の描画
				blacksmithModel.draw(Vec3{ 8, 0, 4 });

				// 風車の描画
				DrawMillModel(millModel, Mat4x4::Translate(-8, 0, 4));

				// 木の描画
				{
					const ScopedRenderStates3D renderState{ BlendState::OpaqueAlphaToCoverage, RasterizerState::SolidCullNone };
					treeModel.draw(Vec3{ 16, 0, 4 });
					pineModel.draw(Vec3{ 16, 0, 0 });
				}
			}

			// [天空レンダリング]
			{
				const double time0_2 = Math::Fraction(skyTime * 0.5) * 2.0;
				const double halfDay0_1 = Math::Fraction(skyTime);
				const double distanceFromNoon0_1 = Math::Saturate(1.0 - (Abs(0.5 - halfDay0_1) * 2.0));
				const bool night = (1.0 < time0_2);
				const double tf = EaseOutCubic(distanceFromNoon0_1);
				const double tc = EaseInOutCubic(distanceFromNoon0_1);
				const double starCenteredTime = Math::Fmod(time0_2 + 1.5, 2.0);

				// set sun
				{
					const Quaternion q = (Quaternion::RotateY(halfDay0_1 * 180_deg) * Quaternion::RotateX(50_deg));
					const Vec3 sunDirection = q * Vec3::Right();
					const ColorF sunColor{ 0.1 + Math::Pow(tf, 1.0 / 2.0) * (night ? 0.1 : 0.9) };

					Graphics3D::SetSunDirection(sunDirection);
					Graphics3D::SetSunColor(sunColor);
					Graphics3D::SetGlobalAmbientColor(ColorF{ sky.zenithColor });
				}

				// set sky color
				{
					if (night)
					{
						sky.zenithColor = ColorF{ 0.3, 0.05, 0.1 }.lerp(ColorF{ 0.1, 0.1, 0.15 }, tf);
						sky.horizonColor = ColorF{ 0.1, 0.1, 0.15 }.lerp(ColorF{ 0.1, 0.1, 0.2 }, tf);
					}
					else
					{
						sky.zenithColor = ColorF{ 0.4, 0.05, 0.1 }.lerp(ColorF{ 0.15, 0.24, 0.56 }, tf);
						sky.horizonColor = ColorF{ 0.2, 0.05, 0.15 }.lerp(ColorF{ 0.3, 0.4, 0.5 }, tf);
					}
				}

				// set parameters
				{
					sky.starBrightness = Math::Saturate(1.0 - Pow(Abs(1.0 - starCenteredTime) * 1.8, 4));
					sky.fogHeightSky = (1.0 - tf);
					sky.cloudColor = ColorF{ 0.02 + (night ? 0.0 : (0.98 * tc)) };
					sky.sunEnabled = (not night);
					sky.cloudTime = skyTime * sky.cloudScale * 40.0;
					sky.starTime = skyTime;
				}

				sky.draw();
			}
		}

		// [RenderTexture を 2D シーンに描画]
		{
			Graphics3D::Flush();
			renderTexture.resolve();
			Shader::LinearToScreen(renderTexture);
		}

		// 天空レンダリングのパラメータ設定
		if (showUI)
		{
			Rect{ 20, 20, 480, 76 }.draw();
			SimpleGUI::GetFont()(U"zenith:").draw(28, 24, ColorF{ 0.11 });
			Rect{ 100, 26, 28 }.draw(sky.zenithColor.gamma(2.2)).drawFrame(1, 0, ColorF{ 0.5 });
			SimpleGUI::GetFont()(U"horizon:").draw(148, 24, ColorF{ 0.11 });
			Rect{ 230, 26, 28 }.draw(sky.horizonColor.gamma(2.2)).drawFrame(1, 0, ColorF{ 0.5 });
			SimpleGUI::GetFont()(U"cloud:").draw(276, 24, ColorF{ 0.11 });
			Rect{ 340, 26, 28 }.draw(sky.cloudColor.gamma(2.2)).drawFrame(1, 0, ColorF{ 0.5 });
			SimpleGUI::GetFont()(U"sun:").draw(386, 24, ColorF{ 0.11 });
			Rect{ 430, 26, 28 }.draw(Graphics3D::GetSunColor().gamma(2.2)).drawFrame(1, 0, ColorF{ 0.5 });
			SimpleGUI::GetFont()(U"sunDir: {:.2f}   cloudTime: {:.1f}"_fmt(Graphics3D::GetSunDirection(), sky.cloudTime)).draw(28, 60, ColorF{ 0.11 });

			SimpleGUI::Slider(U"cloudiness: {:.3f}"_fmt(sky.cloudiness), sky.cloudiness, Vec2{ 20, 100 }, 180, 300);
			SimpleGUI::Slider(U"cloudScale: {:.2f}"_fmt(sky.cloudScale), sky.cloudScale, 0.0, 2.0, Vec2{ 20, 140 }, 180, 300);
			SimpleGUI::Slider(U"cloudHeight: {:.0f}"_fmt(sky.cloudPlaneHeight), sky.cloudPlaneHeight, 20.0, 6000.0, Vec2{ 20, 180 }, 180, 300);
			SimpleGUI::Slider(U"orientation: {:.0f}"_fmt(Math::ToDegrees(sky.cloudOrientation)), sky.cloudOrientation, 0.0, Math::TwoPi, Vec2{ 20, 220 }, 180, 300);
			SimpleGUI::Slider(U"fogHeightSky: {:.2f}"_fmt(sky.fogHeightSky), sky.fogHeightSky, Vec2{ 20, 260 }, 180, 300, false);
			SimpleGUI::Slider(U"star: {:.2f}"_fmt(sky.starBrightness), sky.starBrightness, Vec2{ 20, 300 }, 180, 300, false);
			SimpleGUI::Slider(U"starF: {:.2f}"_fmt(sky.starBrightnessFactor), sky.starBrightnessFactor, Vec2{ 20, 340 }, 180, 300);
			SimpleGUI::Slider(U"starSat: {:.2f}"_fmt(sky.starSaturation), sky.starSaturation, 0.0, 1.0, Vec2{ 20, 380 }, 180, 300);
			SimpleGUI::CheckBox(sky.sunEnabled, U"sun", Vec2{ 20, 420 }, 120, false);
			SimpleGUI::CheckBox(sky.cloudsEnabled, U"clouds", Vec2{ 150, 420 }, 120);
			SimpleGUI::CheckBox(sky.cloudsLightingEnabled, U"cloudsLighting", Vec2{ 280, 420 }, 220);
		}

		SimpleGUI::CheckBox(showUI, U"UI", Vec2{ 20, Scene::Height() - 100 });
		SimpleGUI::Slider(U"time: {:.2f}"_fmt(skyTime), skyTime, -2.0, 4.0, Vec2{ 20, Scene::Height() - 60 }, 120, Scene::Width() - 160);
  });
}

