#pragma once
#include "Wand.h"
#include "AssetManager.h"

class Scene
{
public:
	// Returns true when the scene is finished
	virtual bool Play() = 0;
	void ContinueAfterClick(unsigned int scenePart);

protected:
	std::shared_ptr<wand::App> mApp;
	std::shared_ptr<AssetManager> mAssetManager;
	unsigned int mPart; // the specific part of the scene

	Scene(std::shared_ptr<wand::App> app, std::shared_ptr<AssetManager> assetManager);
};
