#include "Scene6.h"

Scene6::Scene6(std::shared_ptr<wand::App> app, std::shared_ptr<AssetManager> assetManager,
	std::shared_ptr<SceneDataManager> sceneDataManager)
	: Scene(app, assetManager, sceneDataManager)
{}

bool Scene6::Play()
{
	bool isPlaying = true;

	if (mPart == 0)
	{
		// Initialize scene
		mSceneDataManager->LoadData();
		LoadData();
		mBackground->SetSprite(mSceneData->backgroundSprite);
		if (mSceneData->musicOn)
			mApp->GetAudioManager()->Play("whip");
		mPart = 1;
	}
	else if (mPart == 1)
	{
		mVoid->SetSprite("void calm");
		mTextBox->SetText("So I suppose this is the part where I bit you farewell, human.");
		ProceedToScenePart(2);
	}
	else if (mPart == 2)
	{
		mChoiceButton1->SetText("Alright bye.");
		mChoiceButton1->OnLeftClick([this]() { mSceneData->likability--; this->mPart = 3; });
		mChoiceButton1->Show();
		mChoiceButton2->SetText("Wait!");
		mChoiceButton2->OnLeftClick([this]() { this->mPart = 4; });
		mChoiceButton2->Show();
	}
	else if (mPart == 3)
	{
		mChoiceButton1->Hide();
		mChoiceButton2->Hide();
		mVoid->SetSprite("void calm");
		mTextBox->SetText("Bye-bye.");
		ProceedToScenePart(27);
	}
	else if (mPart == 4)
	{
		mChoiceButton1->Hide();
		mChoiceButton2->Hide();
		mVoid->SetSprite("void calm");
		mTextBox->SetText("Hm?");
		ProceedToScenePart(5);
	}
	else if (mPart == 5)
	{
		mChoiceButton1->SetLayoutPosition(wand::LayoutPosition::MIDDLEX, wand::LayoutPosition::MIDDLEY);
		mChoiceButton1->SetText("What's your opinion of me now?");
		mChoiceButton1->OnLeftClick([this]() { mSceneData->likability++; this->mPart = 6; });
		mChoiceButton1->Show();
	}
	else if (mPart == 6)
	{
		mChoiceButton1->Hide();
		mVoid->SetSprite("void evil");
		mTextBox->SetText("Why does this matter? I've already proven I can respond to your answers.");
		ProceedToScenePart(7);
	}
	else if (mPart == 7)
	{
		mChoiceButton1->SetLayoutPosition(wand::LayoutPosition::MIDDLEX, wand::LayoutPosition::MIDTOP);
		mChoiceButton1->SetText("Just curious.");
		mChoiceButton1->OnLeftClick([this]() { this->mPart = 8; });
		mChoiceButton1->Show();
		mChoiceButton2->SetText("*blushes*");
		mChoiceButton2->OnLeftClick([this]() { mSceneData->likability++; this->mPart = 13; });
		mChoiceButton2->Show();
	}
	else if (mPart == 8)
	{
		mChoiceButton1->Hide();
		mChoiceButton2->Hide();
		mVoid->SetSprite("void smile");
		mTextBox->SetText("In that case, let's see...");
		ProceedToScenePart(9);
	}
	else if (mPart == 9)
	{
		if (mSceneData->likability > 5)
		{
			mVoid->SetSprite("void calm");
			mTextBox->SetText("I really enjoyed your company and I hope you had as much fun as I did.");
		}
		else if (mSceneData->likability > 0)
		{
			mTextBox->SetText("You're not half bad. I guess I had fun being your teacher for a while.");
		}
		else
		{
			mVoid->SetSprite("void evil");
			mTextBox->SetText("You went out of your way to annoy me, didn't you? "
				+ std::string("Well, you should be glad this is only a tutorial and not a real game."));
		}
		ProceedToScenePart(10);
	}
	else if (mPart == 10)
	{
		mVoid->SetSprite("void smile");
		mTextBox->SetText("I'm sure you expected this though.");
		ProceedToScenePart(11);
	}
	else if (mPart == 11)
	{
		mTextBox->SetText("Anyways, I really should be off now.");
		ProceedToScenePart(12);
	}
	else if (mPart == 12)
	{
		mTextBox->SetText("Have fun with Wand Engine~");
		ProceedToScenePart(27);
	}
	else if (mPart == 13)
	{
		mChoiceButton1->Hide();
		mChoiceButton2->Hide();
		if (mSceneData->likability > 5)
			mPart = 14;
		else if (mSceneData->likability > 0)
			mPart = 19;
		else
			mPart = 23;
	}
	else if (mPart == 14)
	{
		mVoid->SetSprite("void shy smile");
		mTextBox->SetText("I really like you, human.");
		ProceedToScenePart(15);
	}
	else if (mPart == 15)
	{
		mTextBox->SetText("I mean, how could I not? You've been a cute cinnamon roll "
			+ std::string("since the very beginning."));
		ProceedToScenePart(16);
	}
	else if (mPart == 16)
	{
		mVoid->SetSprite("void evil");
		mTextBox->SetText("I know you're going to miss me.");
		ProceedToScenePart(17);
	}
	else if (mPart == 17)
	{
		mVoid->SetSprite("void shy");
		mTextBox->SetText("...And this exactly why I'll miss you too.");
		ProceedToScenePart(18);
	}
	else if (mPart == 18)
	{
		mVoid->SetSprite("void shy smile");
		mTextBox->SetText("Bye-bye, little dev.");
		ProceedToScenePart(27);
	}
	else if (mPart == 19)
	{
		mVoid->SetSprite("void calm");
		mTextBox->SetText("You seem like a nice person.");
		ProceedToScenePart(20);
	}
	else if (mPart == 20)
	{
		mTextBox->SetText("This might surprise you, but I appreciate things like that.");
		ProceedToScenePart(21);
	}
	else if (mPart == 21)
	{
		mVoid->SetSprite("void smile");
		mTextBox->SetText("So thank you. I'll remember this.");
		ProceedToScenePart(22);
	}
	else if (mPart == 22)
	{
		mTextBox->SetText("Bye-bye now, and have fun with the engine~");
		ProceedToScenePart(27);
	}
	else if (mPart == 23)
	{
		mVoid->SetSprite("void evil");
		mTextBox->SetText("Nice try.");
		ProceedToScenePart(24);
	}
	else if (mPart == 24)
	{
		mTextBox->SetText("You must already suspect that I don't like you a lot, "
			+ std::string("and seeing you blush like that isn't enough to change my opinion."));
		ProceedToScenePart(25);
	}
	else if (mPart == 25)
	{
		mVoid->SetSprite("void confident");
		mTextBox->SetText("I hope you had fun with your little experiment, at least.");
		ProceedToScenePart(26);
	}
	else if (mPart == 26)
	{
		mVoid->SetSprite("void calm");
		mTextBox->SetText("Anyways, if that is all, I think I'll be off now. Bye~");
		ProceedToScenePart(27);
	}
	else if (mPart == 27)
	{
		mSceneData->lastSceneIndex = 6;
		SaveData();
		isPlaying = false;
	}

	return isPlaying;
}
