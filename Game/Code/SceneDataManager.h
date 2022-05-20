#pragma once
#include "Wand.h"

struct SceneData
{
	int lastSceneIndex;
	int likability;
	std::string backgroundSprite;
	bool musicOn;
};

class SceneDataManager
{
public:
	SceneDataManager(std::shared_ptr<wand::App> app);

	void SaveData(SceneData* sceneData);
	void LoadData();
	SceneData* GetData() const;

private:
	std::shared_ptr<wand::App> mApp;
	std::unique_ptr<SceneData> mSceneData;

	void SaveSceneState();
};
