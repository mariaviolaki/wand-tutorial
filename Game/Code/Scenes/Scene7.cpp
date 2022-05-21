#include "Scene7.h"

Scene7::Scene7(std::shared_ptr<wand::App> app, std::shared_ptr<AssetManager> assetManager,
	std::shared_ptr<SceneDataManager> sceneDataManager)
	: Scene(app, assetManager, sceneDataManager)
{
	mNameRect = mAssetManager->Get<wand::Rectangle*>("name rect");
	mTextRect = mAssetManager->Get<wand::Rectangle*>("text rect");
	mCreditsRect = mAssetManager->Get<wand::Rectangle*>("credits rect");
	mCreditsBox = mAssetManager->Get<wand::TextBox*>("creditsbox");
}

bool Scene7::Play()
{
	bool isPlaying = true;

	if (mPart == 0)
	{
		mVoid->Hide();
		mNameBox->SetText("");
		mTextBox->SetText("You've reached the end of the tutorial. "
			+ std::string("We hope you'll enjoy using Wand Engine!"));
		ProceedToScenePart(1);
	}
	else if (mPart == 1)
	{
		mNameRect->Hide();
		mTextRect->Hide();
		mTextBox->Hide();
		mNameBox->Hide();
		mCreditsRect->Show();
		mCreditsBox->Show();
		mCreditsBox->SetText("CREDITS\n\n"
			+ std::string("Character sprites by Buster_Knight from itch.io\n")
			+ std::string("Background art from craftpix.net\n")
			+ std::string("Button sprite by Clker-Free-Vector-Images from pixabay.com\n")
			+ std::string("Blob sprite by OpenClipart-Vectors from pixabay.com\n")
			+ std::string("Music by prazkhanal from pixabay.com\n")
			+ std::string("Sound effect by ryusa from freesound.org\n")
			+ std::string("Font by Brian Zick from 1001fonts.com\n")
			+ std::string("Window icon by Freepik - Flaticon from flaticon.com/free-icons/magic"));
		ProceedToScenePart(2);
	}
	else if (mPart == 2)
	{
		mChoiceButton1->SetLayoutPosition(wand::LayoutPosition::MIDDLEX, wand::LayoutPosition::MIDDLEY);
		mChoiceButton1->SetText("START OVER");
		mChoiceButton1->OnLeftClick([this]() { this->mPart = 3; });
		mChoiceButton1->Show();
	}
	else if (mPart == 3)
	{
		// Reset scene data
		mSceneData->backgroundSprite = "weird forest";
		mSceneData->lastSceneIndex = -1;
		mSceneData->likability = 0;
		mSceneData->musicOn = false;
		// Reset scene
		mNameRect->Show();
		mTextRect->Show();
		mTextBox->Show();
		mNameBox->Show();
		mCreditsRect->Hide();
		mCreditsBox->Hide();
		mChoiceButton1->Hide();
		mChoiceButton1->SetLayoutPosition(wand::LayoutPosition::MIDDLEX, wand::LayoutPosition::MIDTOP);
		mApp->GetAudioManager()->Stop("whip");
		mBackground->SetSprite(mSceneData->backgroundSprite);
		SaveData();
		isPlaying = false;
	}

	return isPlaying;
}
