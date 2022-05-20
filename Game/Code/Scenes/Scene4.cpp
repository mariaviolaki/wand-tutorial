#include "Scene4.h"

Scene4::Scene4(std::shared_ptr<wand::App> app, std::shared_ptr<AssetManager> assetManager,
	std::shared_ptr<SceneDataManager> sceneDataManager)
	: Scene(app, assetManager, sceneDataManager)
{}

bool Scene4::Play()
{
	bool isPlaying = true;

	if (mPart == 0)
	{
		// Initialize scene
		mSceneDataManager->LoadData();
		LoadData();
		mBackground->SetSprite(mSceneData->backgroundSprite);
		mPart = 1;
	}
	if (mPart == 1)
	{
		mVoid->SetSprite("void confident");
		mTextBox->SetText("Music!");
		mApp->GetAudioManager()->Play("whip");
		ProceedToScenePart(2);
	}
	else if (mPart == 2)
	{
		mVoid->SetSprite("void smile");
		mTextBox->SetText("To play any music tracks or sound effects, "
			+ std::string("you'll first need to load them into the App's AudioManager. ")
			+ std::string("You'll have to specify their path, name, ")
			+ std::string("and whether you want them to be looping or not."));
		ProceedToScenePart(3);
	}
	else if (mPart == 3)
	{
		mTextBox->SetText("To start or stop playing an audio file, "
			+ std::string("you must only specify the name of the track. Optionally, ")
			+ std::string("you can also set the volume, panning, and speed of the playback."));
		ProceedToScenePart(4);
	}
	else if (mPart == 4)
	{
		mVoid->SetSprite("void confident");
		mTextBox->SetText("Let us try a little experiment. I'll stop the music now, "
			+ std::string("and restart it with different options."));
		ProceedToScenePart(5);
	}
	else if (mPart == 5)
	{
		mApp->GetAudioManager()->Stop("whip");
		mTextBox->SetText("...");
		ProceedToScenePart(6);
	}
	else if (mPart == 6)
	{
		mApp->GetAudioManager()->Play("whip", 0.5f, 1.0f, 1.5f);
		mVoid->SetSprite("void smile");
		mTextBox->SetText("What you hear right now is the same music track, but with lower volume, "
			+ std::string("right panning, and higher speed. The code looks like this: ")
			+ std::string("app->GetAudioManager()->Play(\"whip\", 0.5f, 1.0f, 1.5f);"));
		ProceedToScenePart(7);
	}
	else if (mPart == 7)
	{
		mTextBox->SetText("Of course, you can play multiple audio files at the same time. "
			+ std::string("Notice what happens when you click to coninue on."));
		ProceedAndPlaySound(8);
	}
	else if (mPart == 8)
	{
		mTextBox->SetText("...");
		ProceedAndPlaySound(9);
	}
	else if (mPart == 9)
	{
		mTextBox->SetText("By the way, I've disabled looping for this sound effect and, unlike the music, "
			+ std::string("you can play it again and again without stopping it so that it overlaps."));
		ProceedToScenePart(10);
	}
	else if (mPart == 10)
	{
		mChoiceButton1->SetText("Can you play the normal version of the music again?");
		mChoiceButton1->OnLeftClick([this]() { mSceneData->likability++; this->mPart = 11; });
		mChoiceButton1->Show();
		mChoiceButton2->SetText("Can you stop the music now? I miss the silence.");
		mChoiceButton2->OnLeftClick([this]() { this->mPart = 13; });
		mChoiceButton2->Show();
	}
	else if (mPart == 11)
	{
		mChoiceButton1->Hide();
		mChoiceButton2->Hide();
		mApp->GetAudioManager()->Stop("whip");
		mPart = 12;
	}
	else if (mPart == 12)
	{
		mTextBox->SetText("Sure. I'm not sure why, but I kinda like this music too.");
		mApp->GetAudioManager()->Play("whip");
		mSceneData->musicOn = true;
		ProceedToScenePart(15);
	}
	else if (mPart == 13)
	{
		mChoiceButton1->Hide();
		mChoiceButton2->Hide();
		mApp->GetAudioManager()->Stop("whip");
		mPart = 14;
	}
	else if (mPart == 14)
	{
		mTextBox->SetText("Sure.");
		mSceneData->musicOn = false;
		ProceedToScenePart(15);
	}
	else if (mPart == 15)
	{
		mVoid->SetSprite("void calm");
		mTextBox->SetText("Let's keep it this way then, from now on - "
			+ std::string("not that there's much left to cover."));
		ProceedToScenePart(16);
	}
	else if (mPart == 16)
	{
		mChoiceButton1->SetText("Aww. Is the tutorial over already?");
		mChoiceButton1->OnLeftClick([this]() { mSceneData->likability++; this->mPart = 17; });
		mChoiceButton1->Show();
		mChoiceButton2->SetText("Good. This is getting too long.");
		mChoiceButton2->OnLeftClick([this]() { mSceneData->likability--; this->mPart = 22; });
		mChoiceButton2->Show();
	}
	else if (mPart == 17)
	{
		mChoiceButton1->Hide();
		mChoiceButton2->Hide();
		mVoid->SetSprite("void evil");
		mTextBox->SetText("Are you going to miss me, little dev?");
		ProceedToScenePart(18);
	}
	else if (mPart == 18)
	{
		mChoiceButton1->SetText("No, I just thought the tutorial should be longer.");
		mChoiceButton1->OnLeftClick([this]() { mSceneData->likability--; this->mPart = 19; });
		mChoiceButton1->Show();
		mChoiceButton2->SetText("Yes!");
		mChoiceButton2->OnLeftClick([this]() { mSceneData->likability++; this->mPart = 20; });
		mChoiceButton2->Show();
	}
	else if (mPart == 19)
	{
		mChoiceButton1->Hide();
		mChoiceButton2->Hide();
		mVoid->SetSprite("void smile");
		mTextBox->SetText("Well then, I'm glad you find it interesting enough.");
		ProceedToScenePart(23);
	}
	else if (mPart == 20)
	{
		mChoiceButton1->Hide();
		mChoiceButton2->Hide();
		mVoid->SetSprite("void shy");
		mTextBox->SetText("...");
		ProceedToScenePart(21);
	}
	else if (mPart == 21)
	{
		mVoid->SetSprite("void smile");
		mTextBox->SetText("I'll respond to that at the end.");
		ProceedToScenePart(23);
	}
	else if (mPart == 22)
	{
		mChoiceButton1->Hide();
		mChoiceButton2->Hide();
		mVoid->SetSprite("void evil smile");
		mTextBox->SetText("Well, aren't you ecstatic.");
		ProceedToScenePart(23);
	}
	else if (mPart == 23)
	{
		mVoid->SetSprite("void calm");
		mTextBox->SetText("Moving on~");
		ProceedToScenePart(24);
	}
	else if (mPart == 24)
	{
		mVoid->SetSprite("void smile");
		mTextBox->SetText("Much like audio files, you can load many other assets in a similar way. "
			+ std::string("Just add each of them into its respective manager."));
		ProceedToScenePart(25);
	}
	else if (mPart == 25)
	{
		mTextBox->SetText("Fonts, for example, should be added to the FontManager "
			+ std::string("by providing a path and a name, and UI Entities belong to the EntityManager."));
		ProceedToScenePart(26);
	}
	else if (mPart == 26)
	{
		mTextBox->SetText("VN Entities are an exception, as you might have expected. "
			+ std::string("To create those, you should get the sprites you need from the EntityManager ")
			+ std::string("and add them to their respective containers."));
		ProceedToScenePart(27);
	}
	else if (mPart == 27)
	{
		mVoid->SetSprite("void calm");
		mTextBox->SetText("I think that's pretty much everything I can say at this point "
			+ std::string("about loading things to the App."));
		ProceedToScenePart(28);
	}
	else if (mPart == 28)
	{
		mSceneData->lastSceneIndex = 4;
		SaveData();
		isPlaying = false;
	}

	return isPlaying;
}
