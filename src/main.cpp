# include <Siv3D.hpp>

void Main()
{
  const Font fontA{ 36, Typeface::Regular };
	const Font fontB{ 36, Typeface::Regular };
	const Font fontC{ 36, Typeface::Regular };

	const Font fontJP{ 36, Typeface::CJK_Regular_JP };
	const Font fontEmoji{ 36, Typeface::ColorEmoji };

	// fontB にフォールバックフォントを 1 つ追加
	fontB.addFallback(fontJP);

	// fontC にフォールバックフォントを 2 つ追加
	fontC.addFallback(fontJP);
	fontC.addFallback(fontEmoji);

	const String s = U"Hello! こんにちは 你好 안녕하세요 🐈🐕🚀";

	Platform::Web::System::SetMainLoop([&]
  {
    System::Update();

		fontA(s).draw(20, 20);
		fontB(s).draw(20, 60);
		fontC(s).draw(20, 100);
  });
}