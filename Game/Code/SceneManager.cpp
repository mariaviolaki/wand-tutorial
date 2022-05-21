#include "SceneManager.h"
#include "Scenes/Scene0.h"
#include "Scenes/Scene1.h"
#include "Scenes/Scene2.h"
#include "Scenes/Scene3.h"
#include "Scenes/Scene4.h"
#include "Scenes/Scene5.h"
#include "Scenes/Scene6.h"
#include "Scenes/Scene7.h"

SceneManager::SceneManager(std::shared_ptr<wand::App> app, std::shared_ptr<AssetManager> assetManager)
	: mApp(app), mAssetManager(assetManager), mSceneDataManager(nullptr), mSceneIndex(0)
{
	mSceneDataManager = std::make_shared<SceneDataManager>(app);
	mSceneDataManager->LoadData();
	// Load all the game scenes
	mScenes.emplace(std::make_pair(0, std::make_unique<Scene0>(mApp, mAssetManager, mSceneDataManager)));
	mScenes.emplace(std::make_pair(1, std::make_unique<Scene1>(mApp, mAssetManager, mSceneDataManager)));
	mScenes.emplace(std::make_pair(2, std::make_unique<Scene2>(mApp, mAssetManager, mSceneDataManager)));
	mScenes.emplace(std::make_pair(3, std::make_unique<Scene3>(mApp, mAssetManager, mSceneDataManager)));
	mScenes.emplace(std::make_pair(4, std::make_unique<Scene4>(mApp, mAssetManager, mSceneDataManager)));
	mScenes.emplace(std::make_pair(5, std::make_unique<Scene5>(mApp, mAssetManager, mSceneDataManager)));
	mScenes.emplace(std::make_pair(6, std::make_unique<Scene6>(mApp, mAssetManager, mSceneDataManager)));
	mScenes.emplace(std::make_pair(7, std::make_unique<Scene7>(mApp, mAssetManager, mSceneDataManager)));
	// Start game from the last saved scene
	mSceneIndex = mSceneDataManager->GetData()->lastSceneIndex + 1;
}

void SceneManager::PlayScenes()
{
	// Start over when all the scenes are finished
	if (mSceneIndex == mScenes.size())
		mSceneIndex = 0;

	// Once the scene is over, play the next one
	if (!mScenes[mSceneIndex]->Play())
		mSceneIndex++;
}
