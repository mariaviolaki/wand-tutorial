#include "Scene.h"

Scene::Scene(std::shared_ptr<wand::App> app, std::shared_ptr<AssetManager> assetManager)
	: mApp(app), mAssetManager(assetManager), mPart(0)
{}

void Scene::ContinueAfterClick(unsigned int scenePart)
{
	if (mApp->GetInput()->MouseButtonDown(MOUSE_BUTTON_LEFT) || mApp->GetInput()->KeyDown(KEY_SPACE))
		mPart = scenePart;
}
