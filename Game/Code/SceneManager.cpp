#include "SceneManager.h"
#include "Scene0.h"
#include "Scene1.h"
#include "Scene2.h"
#include "Scene3.h"

SceneManager::SceneManager(std::shared_ptr<wand::App> app, std::shared_ptr<AssetManager> assetManager)
	: mApp(app), mAssetManager(assetManager), mSceneData(std::make_shared<SceneData>()), mSceneIndex(0)
{
	// Initialize and backup scene data
	mSceneData->lastSceneIndex = -1;
	mSceneData->likability = 0;
	mSceneData->backgroundSprite = "weird forest";
	LoadSceneData();
	mApp->GetWindow()->OnClose([this]() { SaveSceneData(); });
	// Load all the game scenes
	mScenes.emplace(std::make_pair(0, std::make_unique<Scene0>(mApp, mAssetManager, mSceneData)));
	mScenes.emplace(std::make_pair(1, std::make_unique<Scene1>(mApp, mAssetManager, mSceneData)));
	mScenes.emplace(std::make_pair(2, std::make_unique<Scene2>(mApp, mAssetManager, mSceneData)));
	mScenes.emplace(std::make_pair(3, std::make_unique<Scene3>(mApp, mAssetManager, mSceneData)));
	// Set the starting scene
	SetStartingScene();
}

void SceneManager::PlayScenes()
{
	// Don't continue if all the scenes are finished
	if (mSceneIndex == mScenes.size())
		return;

	// Once the scene is over, save its index and go to the next one
	if (!mScenes[mSceneIndex]->Play())
		mSceneData->lastSceneIndex = mSceneIndex++;
}

void SceneManager::LoadSceneData()
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
	}
}

void SceneManager::SaveSceneData()
{
	std::shared_ptr<wand::State> state = std::make_shared<wand::State>("State0");
	state->Add(new wand::Pair("lastSceneIndex", mSceneData->lastSceneIndex));
	state->Add(new wand::Pair("likability", mSceneData->likability));
	state->Add(new wand::Pair("backgroundSprite", mSceneData->backgroundSprite));
	mApp->GetStateManager()->SaveState(state, "states.txt");
}

void SceneManager::SetStartingScene()
{
	switch (mSceneData->lastSceneIndex)
	{
	case 1:
		mSceneIndex = 2;
		break;
	case 2:
		mSceneIndex = 3;
		break;
	}
}
