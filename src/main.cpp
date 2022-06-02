# include <Siv3D.hpp>

void Main()
{
	Window::Resize(1280, 720);

	const VertexShader vsTerrain = HLSL{ U"example/shader/hlsl/terrain_forward.hlsl", U"VS" }
		| GLSL{ U"example/shader/glsl/terrain_forward.vert", {{ U"VSPerView", 1 }, { U"VSPerObject", 2 }, { U"VSPerMaterial", 3 }} };

	const PixelShader psTerrain = HLSL{ U"example/shader/hlsl/terrain_forward.hlsl", U"PS" }
		| GLSL{ U"example/shader/glsl/terrain_forward.frag", {{ U"PSPerFrame", 0 }, { U"PSPerView", 1 }, { U"PSPerMaterial", 3 }} };

	const PixelShader psNormal = HLSL{ U"example/shader/hlsl/terrain_normal.hlsl", U"PS" }
		| GLSL{ U"example/shader/glsl/terrain_normal.frag", {{U"PSConstants2D", 0}} };

	if ((not vsTerrain) || (not psTerrain) || (not psNormal))
	{
		return;
	}

	const ColorF backgroundColor = ColorF{ 0.4, 0.6, 0.8 }.removeSRGBCurve();
	const Texture terrainTexture{ U"example/texture/grass.jpg", TextureDesc::MippedSRGB };
	const Texture rockTexture{ U"example/texture/rock.jpg", TextureDesc::MippedSRGB };
	const Texture brushTexture{ U"example/particle.png" };
	const MSRenderTexture renderTexture{ Scene::Size(), TextureFormat::R8G8B8A8_Unorm_SRGB, HasDepth::Yes };
	const Mesh gridMesh{ MeshData::Grid({128, 128}, 128, 128) };
	DebugCamera3D camera{ renderTexture.size(), 30_deg, Vec3{ 10, 16, -32 } };
	RenderTexture heightmap{ Size{ 256, 256 }, ColorF{0.0}, TextureFormat::R32_Float };
	RenderTexture normalmap{ Size{ 256, 256 }, ColorF{0.0, 0.0, 0.0}, TextureFormat::R16G16_Float };

	Platform::Web::System::SetMainLoop([&]
  {
    System::Update();
		camera.update(2.0);

		// 3D
		{
			Graphics3D::SetCameraTransform(camera);

			const ScopedCustomShader3D shader{ vsTerrain, psTerrain };
			const ScopedRenderTarget3D target{ renderTexture.clear(backgroundColor) };
			const ScopedRenderStates3D ss{ { ShaderStage::Vertex, 0, SamplerState::ClampLinear} };
			Graphics3D::SetVSTexture(0, heightmap);
			Graphics3D::SetPSTexture(1, normalmap);
			Graphics3D::SetPSTexture(2, rockTexture);

			gridMesh.draw(terrainTexture);
		}

		// RenderTexture を 2D シーンに描画
		{
			Graphics3D::Flush();
			renderTexture.resolve();
			Shader::LinearToScreen(renderTexture);
		}

		if (const bool gen = SimpleGUI::Button(U"Random", Vec2{270, 10});
			(gen || (MouseL | MouseR).pressed())) // 地形を編集
		{
			// heightmap を編集
			if (gen)
			{
				const PerlinNoiseF perlin{ RandomUint64() };
				Grid<float> grid(256, 256);
				for (auto p : step(grid.size()))
				{
					grid[p] = perlin.octave2D0_1(p / 256.0f, 5) * 16.0f;
				}
				const RenderTexture noise{ grid };
				const ScopedRenderTarget2D target{ heightmap };
				noise.draw();
			}
			else
			{
				const ScopedRenderTarget2D target{ heightmap };
				const ScopedRenderStates2D blend{ BlendState::Additive };
				brushTexture.scaled(1.0 + MouseL.pressed()).drawAt(Cursor::PosF(), ColorF{ Scene::DeltaTime() * 15.0 });
			}

			// normal map を更新
			{
				const ScopedRenderTarget2D target{ normalmap };
				const ScopedCustomShader2D shader{ psNormal };
				const ScopedRenderStates2D blend{ BlendState::Opaque, SamplerState::ClampLinear };
				heightmap.draw();
			}
		}

		heightmap.draw(ColorF{ 0.1 });
		normalmap.draw(0, 260);
  });
}