#include "Scene3.h"

Scene3::Scene3(std::shared_ptr<wand::App> app,
	std::shared_ptr<AssetManager> assetManager, std::shared_ptr<SceneData> sceneData)
	: Scene(app, assetManager, sceneData)
{}

bool Scene3::Play()
{
	bool isPlaying = true;

	if (mPart == 0)
	{
		mVoid->SetSprite("void smile");
		mTextBox->SetText("Let's continue then.");
		ProceedToScenePart(1);
	}

	return isPlaying;
}
