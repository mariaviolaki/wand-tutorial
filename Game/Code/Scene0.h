#pragma once
#include "Scene.h"

class Scene0 : public Scene
{
public:
	Scene0(std::shared_ptr<wand::App> app,
		std::shared_ptr<AssetManager> assetManager, std::shared_ptr<SceneData> sceneData);
	bool Play() override;
};
