#pragma once
#include "Wand.h"
#include "AssetManager.h"
#include "Scene.h"

class SceneManager
{
public:
	SceneManager(std::shared_ptr<wand::App> app, std::shared_ptr<AssetManager> assetManager);

	void PlayScenes();

private:
	std::shared_ptr<wand::App> mApp;
	std::shared_ptr<AssetManager> mAssetManager;
	std::unordered_map<unsigned int, std::unique_ptr<Scene>> mScenes;
	unsigned int mSceneIndex;
};