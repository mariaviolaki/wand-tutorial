#pragma once
#include "Scene.h"

class Scene0 : public Scene
{
public:
	Scene0(std::shared_ptr<wand::App> app, std::shared_ptr<AssetManager> assetManager);
	bool Play() override;

private:
	wand::Rectangle* mChoiceButtonRect;
	wand::TextBox* mNameBox;
	wand::TextBox* mTextBox;
	wand::Background* mBackground;
	wand::Character* mVoid;
	wand::Button* mChoiceButton1;
	wand::Button* mChoiceButton2;
	float mScale;
};
