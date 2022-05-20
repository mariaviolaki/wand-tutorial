#pragma once
#include "Wand.h"
#include "AssetManager.h"
#include "SceneDataManager.h"
#include "Scenes/Scene.h"

class SceneManager
{
public:
	SceneManager(std::shared_ptr<wand::App> app, std::shared_ptr<AssetManager> assetManager);

	void PlayScenes();

private:
	std::shared_ptr<wand::App> mApp;
	std::shared_ptr<AssetManager> mAssetManager;
	std::shared_ptr<SceneDataManager> mSceneDataManager;
	std::unordered_map<unsigned int, std::unique_ptr<Scene>> mScenes;
	unsigned int mSceneIndex;

	void SetStartingScene();
};
