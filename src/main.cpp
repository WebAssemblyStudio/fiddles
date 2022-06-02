# include <Siv3D.hpp>
#include <random>

// メルセンヌ・ツイスター法による擬似乱数生成器を、
// ハードウェア乱数をシードにして初期化
std::random_device seed_gen;
std::mt19937 engine(seed_gen());

// 一様実数分布
// [-10.0, 10.0)の値の範囲で、等確率に実数を生成する
std::uniform_real_distribution<> dist1(-10.0, 10.0);

// 正規分布
// 平均10.0、標準偏差5.0で分布させる
std::normal_distribution<> dist2(10.0, 5);
void Main()
{
  // 背景を水色にする
  Scene::SetBackground(ColorF{ 0.8, 0.9, 1.0 });

  // 通常のフォントを作成
  const Font font{ 60 };
  
  // 絵文字用フォントを作成
  const Font emojiFont{ 60, Typeface::ColorEmoji };
  
  // `font` が絵文字用フォントも使えるようにする
  font.addFallback(emojiFont);

  // 画像ファイルからテクスチャを作成
  const Texture texture{ U"example/windmill.png" };

  // 絵文字からテクスチャを作成
  const Texture emoji{ U"🐈"_emoji };

  // 絵文字を描画する座標
  Vec2 emojiPos{ 300, 150 };

  // テキストを画面にデバッグ出力
  Print << U"Push [A] key";

  Platform::Web::System::SetMainLoop([&]
  {
    System::Update();
    
    // 各分布法に基いて乱数を生成
    double r1 = dist1(engine);
    double r2 = dist2(engine);

    // テクスチャを描く
    texture.draw(100+r1, 100+r2);

    // テキストを画面の中心に描く
    font(U"Hello, Siv3D!🚀").drawAt(Scene::Center(), Palette::Black);

    // サイズをアニメーションさせて絵文字を描く
    emoji.resized(100 + Periodic::Sine0_1(1s) * 20).drawAt(emojiPos);

    // マウスカーソルに追随する半透明な円を描く
    Circle{ Cursor::Pos(), 40 }.draw(ColorF{ 1, 0, 0, 0.5 });

    // もし [A] キーが押されたら
    if (KeyA.down())
    {
      // 選択肢からランダムに選ばれたメッセージをデバッグ表示
      Print << Sample({ U"Hello!", U"こんにちは", U"你好", U"안녕하세요?" });
    }

    // もし [Button] が押されたら
    if (SimpleGUI::Button(U"Button", Vec2{ 640, 40 }))
    {
      // 画面内のランダムな場所に座標を移動
      emojiPos = RandomVec2(Scene::Rect());
    }
  });
}
