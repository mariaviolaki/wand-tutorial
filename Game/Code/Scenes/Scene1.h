#pragma once
#include "Scene.h"

class Scene1 : public Scene
{
public:
	Scene1(std::shared_ptr<wand::App> app, 
		std::shared_ptr<AssetManager> assetManager, std::shared_ptr<SceneData> sceneData);
	bool Play() override;
};
