#pragma once
#include "Scene.h"

class Scene7 : public Scene
{
public:
	Scene7(std::shared_ptr<wand::App> app, std::shared_ptr<AssetManager> assetManager,
		std::shared_ptr<SceneDataManager> sceneDataManager);
	bool Play() override;

private:
	wand::Rectangle* mNameRect;
	wand::Rectangle* mTextRect;
	wand::Rectangle* mCreditsRect;
	wand::TextBox* mCreditsBox;
};
