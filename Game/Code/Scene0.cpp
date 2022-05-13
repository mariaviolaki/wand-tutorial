#include "Scene0.h"

Scene0::Scene0(std::shared_ptr<wand::App> app,
	std::shared_ptr<AssetManager> assetManager, std::shared_ptr<SceneData> sceneData)
	: Scene(app, assetManager, sceneData)
{}

bool Scene0::Play()
{
	bool isPlaying = true;

	if (mPart == 0)
	{
		mBackground->SetSprite("weird forest");
		mVoid->SetSprite("void smile");
		mNameBox->SetText("???");
		mTextBox->SetText("Why, hello there, fellow dev.");
		ProceedToScenePart(1);
	}
	else if (mPart == 1)
	{
		mNameBox->SetText(wand::Utils::ToUpper(mVoid->GetName()));
		mTextBox->SetText("You may call me Void.");
		ProceedToScenePart(2);
	}
	else if (mPart == 2)
	{
		mTextBox->SetText("I was tasked with explaining to you how Wand Engine works. "
			+ std::string("So I hope you're as impatient as I am, yes?"));
		ProceedToScenePart(3);
	}
	else if (mPart == 3)
	{
		mChoiceButton1->SetLayoutPosition(wand::LayoutPosition::MIDDLEX, wand::LayoutPosition::MIDTOP);
		mChoiceButton1->SetText("YAS!");
		mChoiceButton1->OnLeftClick([this]() { mSceneData->likability++; this->mPart = 4; });
		mChoiceButton1->Show();
		mChoiceButton2->SetLayoutPosition(wand::LayoutPosition::MIDDLEX, wand::LayoutPosition::MIDDLEY);
		mChoiceButton2->SetText("...Why is the background so creepy?");
		mChoiceButton2->OnLeftClick([this]() { mSceneData->likability--; this->mPart = 5; });
		mChoiceButton2->Show();
	}
	else if (mPart == 4)
	{
		mChoiceButton1->Hide();
		mChoiceButton2->Hide();
		mVoid->SetSprite("void shy smile");
		mTextBox->SetText("I'm glad.");
		ProceedToScenePart(13);
	}
	else if (mPart == 5)
	{
		mChoiceButton1->Hide();
		mChoiceButton2->Hide();
		mVoid->SetSprite("void surprised");
		mTextBox->SetText("Oh? Let's change it, then.");
		ProceedToScenePart(6);
	}
	else if (mPart == 6)
	{
		mBackground->SetSprite("creepy forest");
		mVoid->SetSprite("void evil");
		mTextBox->SetText("How about now? Is this more to your liking?");
		ProceedToScenePart(7);
	}
	else if (mPart == 7)
	{
		mChoiceButton1->SetText("No! Change it back!");
		mChoiceButton1->OnLeftClick([this]() { mSceneData->likability--; this->mPart = 8; });
		mChoiceButton1->Show();
		mChoiceButton2->SetText("Yes, actually.");
		mChoiceButton2->OnLeftClick([this]() { this->mPart = 11; });
		mChoiceButton2->Show();
	}
	else if (mPart == 8)
	{
		mChoiceButton1->Hide();
		mChoiceButton2->Hide();
		mVoid->SetSprite("void smile");
		mTextBox->SetText("Well, if you insist...");
		ProceedToScenePart(9);
	}
	else if (mPart == 9)
	{
		mBackground->SetSprite("weird forest");
		mTextBox->SetText("...Here.");
		ProceedToScenePart(10);
	}
	else if (mPart == 10)
	{
		mVoid->SetSprite("void evil");
		mTextBox->SetText("This is only a tutorial, after all, so I'll indulge you.");
		ProceedToScenePart(13);
	}
	else if (mPart == 11)
	{
		mChoiceButton1->Hide();
		mChoiceButton2->Hide();
		mVoid->SetSprite("void surprised");
		mTextBox->SetText("It is?");
		ProceedToScenePart(12);
	}
	else if (mPart == 12)
	{
		mVoid->SetSprite("void smile");
		mTextBox->SetText("Let's keep it this way then. I quite like this forest myself.");
		mSceneData->backgroundSprite = "creepy forest";
		ProceedToScenePart(13);
	}
	else if (mPart == 13)
	{
		mVoid->SetSprite("void smile");
		mTextBox->SetText("So let's move on with the main part then, shall we?");
		ProceedToScenePart(14);
	}
	else if (mPart == 14)
	{
		isPlaying = false;
	}

	return isPlaying;
}
