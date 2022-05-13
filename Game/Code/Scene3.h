#pragma once
#include "Scene.h"

class Scene3 : public Scene
{
public:
	Scene3(std::shared_ptr<wand::App> app,
		std::shared_ptr<AssetManager> assetManager, std::shared_ptr<SceneData> sceneData);
	bool Play() override;
};
