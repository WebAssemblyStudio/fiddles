# include <Siv3D.hpp>

void Main()
{
	Window::Resize(1280, 720);

	Audio audio;
	double posSec = 0.0;
	double volume = 1.0;
	double pan = 0.0;
	double speed = 1.0;
	bool loop = false;

	Array<float> busSamples;
	Array<float> globalSamples;
	FFTResult busFFT;
	FFTResult globalFFT;
	LineString lines(256, Vec2{ 0, 0 });

	bool pitch = false;
	double pitchShift = 0.0;

	bool lpf = false;
	double lpfCutoffFrequency = 800.0;
	double lpfResonance = 0.5;
	double lpfWet = 1.0;

	bool hpf = false;
	double hpfCutoffFrequency = 800.0;
	double hpfResonance = 0.5;
	double hpfWet = 1.0;

	bool echo = false;
	double delay = 0.1;
	double decay = 0.5;
	double echoWet = 0.5;

	bool reverb = false;
	bool freeze = false;
	double roomSize = 0.5;
	double damp = 0.0;
	double width = 0.5;
	double reverbWet = 0.5;

	Platform::Web::System::SetMainLoop([&]
  {
    System::Update();
		ClearPrint();
		Print << U"GlobalAudio::GetActiveVoiceCount(): " << GlobalAudio::GetActiveVoiceCount();
		Print << U"isEmpty : " << audio.isEmpty();
		Print << U"isStreaming : " << audio.isStreaming();
		Print << U"sampleRate : " << audio.sampleRate();
		Print << U"samples : " << audio.samples();
		Print << U"lengthSec : " << audio.lengthSec();
		Print << U"posSample : " << audio.posSample();
		Print << U"posSec : " << (posSec = audio.posSec());
		Print << U"isActive : " << audio.isActive();
		Print << U"isPlaying : " << audio.isPlaying();
		Print << U"isPaused : " << audio.isPaused();
		Print << U"samplesPlayed : " << audio.samplesPlayed();
		Print << U"isLoop : " << (loop = audio.isLoop());
		Print << U"getLoopTimingtLoop : " << audio.getLoopTiming().beginPos << U", " << audio.getLoopTiming().endPos;
		Print << U"loopCount : " << audio.loopCount();
		Print << U"getVolume : " << (volume = audio.getVolume());
		Print << U"getPan : " << (pan = audio.getPan());
		Print << U"getSpeed : " << (speed = audio.getSpeed());

		if (SimpleGUI::Button(U"Open audio file", Vec2{ 60, 560 }))
		{
			audio.stop(0.5s);
			audio = Dialog::OpenAudio(Audio::Stream);
		}

		{
			GlobalAudio::BusGetSamples(MixBus0, busSamples);
			GlobalAudio::BusGetFFT(MixBus0, busFFT);

			for (auto [i, s] : Indexed(busSamples))
			{
				lines[i].set((300.0 + i), (200.0 - s * 100.0));
			}

			if (busSamples)
			{
				lines.draw(2, Palette::Orange);
			}

			for (auto [i, s] : Indexed(busFFT.buffer))
			{
				RectF{ Arg::bottomLeft(300 + i, 300), 1, (s * 4) }.draw();
			}
		}

		{
			GlobalAudio::GetSamples(globalSamples);
			GlobalAudio::GetFFT(globalFFT);

			for (auto [i, s] : Indexed(globalSamples))
			{
				lines[i].set((300.0 + i), (550.0 - s * 100.0));
			}

			if (globalSamples)
			{
				lines.draw(2, Palette::Orange);
			}

			for (auto [i, s] : Indexed(globalFFT.buffer))
			{
				RectF{ Arg::bottomLeft(300 + i, 650), 1, (s * 4) }.draw();
			}
		}

		if (SimpleGUI::Button(U"Play", Vec2{ 600, 20 }, 80, !audio.isPlaying()))
		{
			audio.play();
		}

		if (SimpleGUI::Button(U"Pause", Vec2{ 690, 20 }, 80, (audio.isPlaying() && !audio.isPaused())))
		{
			audio.pause();
		}

		if (SimpleGUI::Button(U"Stop", Vec2{ 780, 20 }, 80, (audio.isPlaying() || audio.isPaused())))
		{
			audio.stop();
		}

		if (SimpleGUI::Button(U"Play in 2s", Vec2{ 870, 20 }, 120, !audio.isPlaying()))
		{
			audio.play(2s);
		}

		if (SimpleGUI::Button(U"Pause in 2s", Vec2{ 1000, 20 }, 120, (audio.isPlaying() && !audio.isPaused())))
		{
			audio.pause(2s);
		}

		if (SimpleGUI::Button(U"Stop in 2s", Vec2{ 1130, 20 }, 120, (audio.isPlaying() || audio.isPaused())))
		{
			audio.stop(2s);
		}

		if (SimpleGUI::Slider(U"{:.1f} / {:.1f}"_fmt(posSec, audio.lengthSec()), posSec, 0.0, audio.lengthSec(), Vec2{ 600, 60 }, 160, 360))
		{
			if (MouseL.down() || !Cursor::DeltaF().isZero()) // シークの連続（ノイズの原因）を防ぐ
			{
				audio.seekTime(posSec);
			}
		}

		if (SimpleGUI::CheckBox(loop, U"Loop", Vec2{ 1130, 60 }))
		{
			audio.setLoop(loop);
		}

		if (SimpleGUI::Slider(U"volume: {:.2f}"_fmt(volume), volume, Vec2{ 600, 110 }, 140, 130))
		{
			audio.setVolume(volume);
		}

		if (SimpleGUI::Button(U"0.0 in 2s", Vec2{ 880, 110 }, 110, audio.isActive()))
		{
			audio.fadeVolume(0.0, 2s);
		}

		if (SimpleGUI::Button(U"0.5 in 2s", Vec2{ 1000, 110 }, 110, audio.isActive()))
		{
			audio.fadeVolume(0.5, 2s);
		}

		if (SimpleGUI::Button(U"1.0 in 2s", Vec2{ 1120, 110 }, 110, audio.isActive()))
		{
			audio.fadeVolume(1.0, 2s);
		}

		if (SimpleGUI::Slider(U"pan: {:.2f}"_fmt(pan), pan, -1.0, 1.0, Vec2{ 600, 150 }, 140, 130))
		{
			audio.setPan(pan);
		}

		if (SimpleGUI::Button(U"-1.0 in 2s", Vec2{ 880, 150 }, 110, audio.isActive()))
		{
			audio.fadePan(-1.0, 2s);
		}

		if (SimpleGUI::Button(U"0.0 in 2s", Vec2{ 1000, 150 }, 110, audio.isActive()))
		{
			audio.fadePan(0.0, 2s);
		}

		if (SimpleGUI::Button(U"1.0 in 2s", Vec2{ 1120, 150 }, 110, audio.isActive()))
		{
			audio.fadePan(1.0, 2s);
		}

		if (SimpleGUI::Slider(U"speed: {:.3f}"_fmt(speed), speed, 0.0, 4.0, Vec2{ 600, 190 }, 140, 130))
		{
			audio.setSpeed(speed);
		}

		if (SimpleGUI::Button(U"0.8 in 2s", Vec2{ 880, 190 }, 110, audio.isActive()))
		{
			audio.fadeSpeed(0.8, 2s);
		}

		if (SimpleGUI::Button(U"1.0 in 2s", Vec2{ 1000, 190 }, 110, audio.isActive()))
		{
			audio.fadeSpeed(1.0, 2s);
		}

		if (SimpleGUI::Button(U"1.2 in 2s", Vec2{ 1120, 190 }, 110, audio.isActive()))
		{
			audio.fadeSpeed(1.2, 2s);
		}

		bool updatePitch = false;
		bool updateLPF = false;
		bool updateHPF = false;
		bool updateEcho = false;
		bool updateReverb = false;

		if (SimpleGUI::CheckBox(pitch, U"Pitch", Vec2{ 600, 240 }, 120, GlobalAudio::SupportsPitchShift()))
		{
			if (pitch)
			{
				updatePitch = true;
			}
			else
			{
				GlobalAudio::BusClearFilter(MixBus0, 0);
			}
		}
		updatePitch |= SimpleGUI::Slider(U"pitchShift: {:.2f}"_fmt(pitchShift), pitchShift, -12.0, 12.0, Vec2{ 720, 240 }, 160, 300);

		if (SimpleGUI::CheckBox(lpf, U"LPF", Vec2{ 600, 280 }, 120))
		{
			if (lpf)
			{
				updateLPF = true;
			}
			else
			{
				GlobalAudio::BusClearFilter(MixBus0, 1);
			}
		}
		updateLPF |= SimpleGUI::Slider(U"cutoffFrequency: {:.0f}"_fmt(lpfCutoffFrequency), lpfCutoffFrequency, 10, 4000, Vec2{ 720, 280 }, 220, 240);
		updateLPF |= SimpleGUI::Slider(U"resonance: {:.2f}"_fmt(lpfResonance), lpfResonance, 0.1, 8.0, Vec2{ 720, 310 }, 220, 240);
		updateLPF |= SimpleGUI::Slider(U"wet: {:.2f}"_fmt(lpfWet), lpfWet, Vec2{ 720, 340 }, 220, 240);

		if (SimpleGUI::CheckBox(hpf, U"HPF", Vec2{ 600, 380 }, 120))
		{
			if (hpf)
			{
				updateHPF = true;
			}
			else
			{
				GlobalAudio::BusClearFilter(MixBus0, 2);
			}
		}
		updateHPF |= SimpleGUI::Slider(U"cutoffFrequency: {:.0f}"_fmt(hpfCutoffFrequency), hpfCutoffFrequency, 10, 4000, Vec2{ 720, 380 }, 220, 240);
		updateHPF |= SimpleGUI::Slider(U"resonance: {:.2f}"_fmt(hpfResonance), hpfResonance, 0.1, 8.0, Vec2{ 720, 410 }, 220, 240);
		updateHPF |= SimpleGUI::Slider(U"wet: {:.2f}"_fmt(hpfWet), hpfWet, Vec2{ 720, 440 }, 220, 240);

		if (SimpleGUI::CheckBox(echo, U"Echo", Vec2{ 600, 480 }, 120))
		{
			if (echo)
			{
				updateEcho = true;
			}
			else
			{
				GlobalAudio::BusClearFilter(MixBus0, 3);
			}
		}
		updateEcho |= SimpleGUI::Slider(U"delay: {:.2f}"_fmt(delay), delay, Vec2{ 720, 480 }, 220, 240);
		updateEcho |= SimpleGUI::Slider(U"decay: {:.2f}"_fmt(decay), decay, Vec2{ 720, 510 }, 220, 240);
		updateEcho |= SimpleGUI::Slider(U"wet: {:.2f}"_fmt(echoWet), echoWet, Vec2{ 720, 540 }, 220, 240);

		if (SimpleGUI::CheckBox(reverb, U"Reverb", Vec2{ 600, 580 }, 120))
		{
			if (reverb)
			{
				updateReverb = true;
			}
			else
			{
				GlobalAudio::BusClearFilter(MixBus0, 4);
			}
		}
		updateReverb |= SimpleGUI::CheckBox(freeze, U"freeze", Vec2{ 720, 580 }, 110);
		updateReverb |= SimpleGUI::Slider(U"roomSize: {:.2f}"_fmt(roomSize), roomSize, 0.001, 1.0, { 830, 580 }, 150, 200);
		updateReverb |= SimpleGUI::Slider(U"damp: {:.2f}"_fmt(damp), damp, Vec2{ 720, 610 }, 220, 240);
		updateReverb |= SimpleGUI::Slider(U"width: {:.2f}"_fmt(width), width, Vec2{ 720, 640 }, 220, 240);
		updateReverb |= SimpleGUI::Slider(U"wet: {:.2f}"_fmt(reverbWet), reverbWet, Vec2{ 720, 670 }, 220, 240);

		if (pitch && updatePitch)
		{
			GlobalAudio::BusSetPitchShiftFilter(MixBus0, 0, pitchShift);
		}

		if (lpf && updateLPF)
		{
			GlobalAudio::BusSetLowPassFilter(MixBus0, 1, lpfCutoffFrequency, lpfResonance, lpfWet);
		}

		if (hpf && updateHPF)
		{
			GlobalAudio::BusSetHighPassFilter(MixBus0, 2, hpfCutoffFrequency, hpfResonance, hpfWet);
		}

		if (echo && updateEcho)
		{
			GlobalAudio::BusSetEchoFilter(MixBus0, 3, delay, decay, echoWet);
		}

		if (reverb && updateReverb)
		{
			GlobalAudio::BusSetReverbFilter(MixBus0, 4, freeze, roomSize, damp, width, reverbWet);
		}
  });

	if (GlobalAudio::GetActiveVoiceCount())
	{
		GlobalAudio::FadeVolume(0.0, 0.5s);
		System::Sleep(0.5s);
	}
}