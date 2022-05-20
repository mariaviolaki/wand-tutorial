#include "Scene5.h"

Scene5::Scene5(std::shared_ptr<wand::App> app, std::shared_ptr<AssetManager> assetManager,
	std::shared_ptr<SceneDataManager> sceneDataManager)
	: Scene(app, assetManager, sceneDataManager)
{}

bool Scene5::Play()
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
		mVoid->SetSprite("void confident");
		mTextBox->SetText("Oh, by the way, have you noticed "
			+ std::string("that you can also press the spacebar to continue?"));
		ProceedToScenePart(2);
	}

	return isPlaying;
}
