#pragma once
#include "Scene.h"

class Scene3 : public Scene
{
public:
	Scene3(std::shared_ptr<wand::App> app, std::shared_ptr<AssetManager> assetManager,
		std::shared_ptr<SceneDataManager> sceneDataManager);
	bool Play() override;
};
