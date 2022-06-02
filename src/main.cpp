# include <Siv3D.hpp>

struct Unit
{
	Circle circle;

	ColorF color;

	void draw() const
	{
		circle.draw(color);
	}
};

// Unit を KDTree で扱えるようにするためのアダプタ
struct UnitAdapter : KDTreeAdapter<Array<Unit>, Vec2>
{
	static const element_type* GetPointer(const point_type& point)
	{
		return point.getPointer();
	}

	static element_type GetElement(const dataset_type& dataset, size_t index, size_t dim)
	{
		return dataset[index].circle.center.elem(dim);
	}
};

void Main()
{
	// 200 個の Unit を生成
	Array<Unit> units;
	{
		for (size_t i = 0; i < 200; ++i)
		{
			Unit unit
			{
				.circle = Circle{ RandomVec2(Scene::Rect()), 4 },
				.color = RandomColorF()
			};
			units << unit;
		}
	}

	// kd-tree を構築
	KDTree<UnitAdapter> kdTree{ units };

	// radius search する際の探索距離
	constexpr double searchDistance = 80.0;

	Platform::Web::System::SetMainLoop([&]
  {
    System::Update();
		const Vec2 cursorPos = Cursor::PosF();

		Circle{ cursorPos, searchDistance }.draw(ColorF{ 1.0, 0.2 });

		// searchDistance 以内の距離にある Unit のインデックスを取得
		for (auto index : kdTree.radiusSearch(cursorPos, searchDistance))
		{
			Line{ cursorPos, units[index].circle.center }.draw(4);
		}

		// ユニットを描画
		for (const auto& unit : units)
		{
			unit.draw();
		}
  });
}