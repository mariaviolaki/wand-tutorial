#pragma once
#include "Wand.h"
#include "../AssetManager.h"

struct SceneData
{
	int lastSceneIndex;
	int likability;
	std::string backgroundSprite;
};

class Scene
{
public:
	// Returns true when the scene is finished
	virtual bool Play() = 0;
	void ProceedToScenePart(unsigned int scenePart);

protected:
	std::shared_ptr<wand::App> mApp;
	std::shared_ptr<AssetManager> mAssetManager;
	std::shared_ptr<SceneData> mSceneData;
	unsigned int mPart; // the specific part of the scene

	// Assets that all scenes should have access to
	wand::Rectangle* mChoiceButtonRect;
	wand::TextBox* mNameBox;
	wand::TextBox* mTextBox;
	wand::Background* mBackground;
	wand::Character* mVoid;
	wand::Button* mChoiceButton1;
	wand::Button* mChoiceButton2;
	wand::Sprite* mBlob;

	Scene(std::shared_ptr<wand::App> app, 
		std::shared_ptr<AssetManager> assetManager, std::shared_ptr<SceneData> sceneData);
};
