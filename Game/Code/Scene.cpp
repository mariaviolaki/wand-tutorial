#include "Scene.h"

Scene::Scene(std::shared_ptr<wand::App> app, std::shared_ptr<AssetManager> assetManager)
	: mApp(app), mAssetManager(assetManager), mPart(0)
{}

void Scene::ProceedToScenePart(unsigned int scenePart)
{
	if (mApp->GetInput()->MouseButtonReleased(MOUSE_BUTTON_LEFT) || mApp->GetInput()->KeyReleased(KEY_SPACE))
		mPart = scenePart;
}
