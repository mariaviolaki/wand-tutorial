#include "SceneManager.h"
#include "Scene0.h"
#include "Scene1.h"

SceneManager::SceneManager(std::shared_ptr<wand::App> app, std::shared_ptr<AssetManager> assetManager)
	: mApp(app), mAssetManager(assetManager), mSceneIndex(0)
{
	// Load all the game scenes
	mScenes.emplace(std::make_pair(0, std::make_unique<Scene0>(mApp, mAssetManager)));
	mScenes.emplace(std::make_pair(1, std::make_unique<Scene1>(mApp, mAssetManager)));
}

void SceneManager::PlayScenes()
{
	// Don't continue if all the scenes are finished
	if (mSceneIndex == mScenes.size())
		return;

	// Once the scene is over, go to the next one
	if (!mScenes[mSceneIndex]->Play())
		mSceneIndex++;
}
