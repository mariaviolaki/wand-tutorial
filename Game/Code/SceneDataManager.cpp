#include "SceneDataManager.h"

SceneDataManager::SceneDataManager(std::shared_ptr<wand::App> app)
	: mApp(app), mSceneData(std::make_unique<SceneData>())
{
	// Initialize scene data
	mSceneData->lastSceneIndex = -1;
	mSceneData->likability = 0;
	mSceneData->backgroundSprite = "weird forest";
	mSceneData->musicOn = false;
}

void SceneDataManager::SaveData(SceneData* sceneData)
{
	mSceneData->likability = sceneData->likability;
	mSceneData->backgroundSprite = sceneData->backgroundSprite;
	mSceneData->lastSceneIndex = sceneData->lastSceneIndex;
	mSceneData->musicOn = sceneData->musicOn;
	// Save the last state to a file
	SaveSceneState();
}

void SceneDataManager::LoadData()
{
	// Load any previously saved states
	mApp->GetStateManager()->LoadStates("states.txt");
	auto state = mApp->GetStateManager()->GetState("State0");
	if (!state)
		return;

	// Save the state data into the scene data
	for (auto& pair : state->GetStateData())
	{
		if (pair->GetName() == "likability")
			mSceneData->likability = pair->GetIntValue();
		else if (pair->GetName() == "lastSceneIndex")
			mSceneData->lastSceneIndex = pair->GetIntValue();
		else if (pair->GetName() == "backgroundSprite")
			mSceneData->backgroundSprite = pair->GetStringValue();
		else if (pair->GetName() == "musicOn")
			mSceneData->musicOn = pair->GetBoolValue();
	}
}

SceneData* SceneDataManager::GetData() const { return mSceneData.get(); }

void SceneDataManager::SaveSceneState()
{
	std::shared_ptr<wand::State> state = std::make_shared<wand::State>("State0");
	state->Add(new wand::Pair("lastSceneIndex", mSceneData->lastSceneIndex));
	state->Add(new wand::Pair("likability", mSceneData->likability));
	state->Add(new wand::Pair("backgroundSprite", mSceneData->backgroundSprite));
	state->Add(new wand::Pair("musicOn", mSceneData->musicOn));
	mApp->GetStateManager()->SaveState(state, "states.txt");
}
