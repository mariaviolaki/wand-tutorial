#pragma once
#include "Scene.h"

class Scene1 : public Scene
{
public:
	Scene1(std::shared_ptr<wand::App> app, std::shared_ptr<AssetManager> assetManager);
	bool Play() override;

private:
	wand::TextBox* mTextBox;
	wand::Character* mVoid;
	wand::Button* mChoiceButton1;
	wand::Button* mChoiceButton2;
};
