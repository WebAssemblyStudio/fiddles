# include <Siv3D.hpp>

void Main()
{
	const ManagedScript script{ U"example/script/hello.as" };

	Platform::Web::System::SetMainLoop([&]
  {
    System::Update();
		script.run();
  });
}