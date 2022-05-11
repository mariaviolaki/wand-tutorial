#include "Wand.h"
#include "Code/AssetManager.h"

// Entry point for windows applications
int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
	// Create a new app
	auto app = std::make_shared<wand::App>();
	auto assetManager = std::make_unique<AssetManager>(app.get());

	auto textBox = assetManager->Get<wand::TextBox*>("textbox");
	textBox->SetText("Why, hello there, fellow dev.");

	auto nameBox = assetManager->Get<wand::TextBox*>("namebox");
	nameBox->SetText("???");

	auto background = assetManager->Get<wand::Background*>("main background");
	background->SetSprite("weird forest");

	auto cVoid = assetManager->Get<wand::Character*>("Void");
	cVoid->SetSprite("void smile");
	cVoid->SetParentLayout(background->GetTransform());
	cVoid->SetLayoutPosition(wand::LayoutPosition::MIDDLEX, wand::LayoutPosition::BOTTOM);
	
	while (app->IsRunning())
	{
		app->Clear();

		/* Code that runs each frame goes here */

		app->Update();
	}
	return 0;
}
