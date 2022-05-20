#pragma once
#include "Scene.h"

class Scene5 : public Scene
{
public:
	Scene5(std::shared_ptr<wand::App> app, std::shared_ptr<AssetManager> assetManager,
		std::shared_ptr<SceneDataManager> sceneDataManager);
	bool Play() override;
};
