#include "Scene4.h"

Scene4::Scene4(std::shared_ptr<wand::App> app,
	std::shared_ptr<AssetManager> assetManager, std::shared_ptr<SceneData> sceneData)
	: Scene(app, assetManager, sceneData)
{}

bool Scene4::Play()
{
	bool isPlaying = true;

	if (mPart == 0)
	{
		mVoid->SetSprite("void confident");
		mTextBox->SetText("Music!");
		ProceedToScenePart(1);
	}

	return isPlaying;
}
