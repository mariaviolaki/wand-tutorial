#include "Scene7.h"

Scene7::Scene7(std::shared_ptr<wand::App> app, std::shared_ptr<AssetManager> assetManager,
	std::shared_ptr<SceneDataManager> sceneDataManager)
	: Scene(app, assetManager, sceneDataManager)
{}

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
		mChoiceButton1->SetLayoutPosition(wand::LayoutPosition::MIDDLEX, wand::LayoutPosition::MIDDLEY);
		mChoiceButton1->SetText("START OVER");
		mChoiceButton1->OnLeftClick([this]() { this->mPart = 2; });
		mChoiceButton1->Show();
	}
	else if (mPart == 2)
	{
		// Reset scene data
		mSceneData->backgroundSprite = "weird forest";
		mSceneData->lastSceneIndex = -1;
		mSceneData->likability = 0;
		mSceneData->musicOn = false;
		// Reset scene
		mChoiceButton1->Hide();
		mChoiceButton1->SetLayoutPosition(wand::LayoutPosition::MIDDLEX, wand::LayoutPosition::MIDTOP);
		mApp->GetAudioManager()->Stop("whip");
		mBackground->SetSprite(mSceneData->backgroundSprite);
		SaveData();
		isPlaying = false;
	}

	return isPlaying;
}
