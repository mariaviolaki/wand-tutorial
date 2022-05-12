#include "Wand.h"
#include "Code/AssetManager.h"
#include "Code/SceneManager.h"

// Entry point for windows applications
int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
	// Create a new app
	auto app = std::make_shared<wand::App>();
	auto assetManager = std::make_shared<AssetManager>(app.get());
	auto sceneManager = std::make_unique<SceneManager>(app, assetManager);
	
	while (app->IsRunning())
	{
		app->Clear();

		sceneManager->PlayScenes();

		app->Update();
	}
	return 0;
}
