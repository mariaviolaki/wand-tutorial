#include "Scene.h"

Scene::Scene(std::shared_ptr<wand::App> app,
	std::shared_ptr<AssetManager> assetManager, std::shared_ptr<SceneData> sceneData)
	: mApp(app), mAssetManager(assetManager), mSceneData(sceneData), mPart(0)
{
	// Initialize all assets
	mChoiceButtonRect = mAssetManager->Get<wand::Rectangle*>("choice button rect");
	mNameBox = mAssetManager->Get<wand::TextBox*>("namebox");
	mTextBox = mAssetManager->Get<wand::TextBox*>("textbox");
	mBackground = mAssetManager->Get<wand::Background*>("main background");
	mVoid = mAssetManager->Get<wand::Character*>("Void");
	mChoiceButton1 = mAssetManager->Get<wand::Button*>("choice button 1");
	mChoiceButton2 = mAssetManager->Get<wand::Button*>("choice button 2");
	float scale = mBackground->GetTransform()->GetScale().x;

	// Customize the entities
	mNameBox->SetText(wand::Utils::ToUpper(mVoid->GetName()));
	mBackground->SetSprite(mSceneData->backgroundSprite);
	mVoid->SetParentLayout(mBackground->GetTransform());
	mVoid->SetLayoutPosition(wand::LayoutPosition::MIDDLEX, wand::LayoutPosition::BOTTOM);
	mChoiceButton1->SetParentLayout(mChoiceButtonRect->GetTransform());
	mChoiceButton1->GetTextTransform()->SetWidth(mChoiceButton1->GetTransform()->GetWidth() - 20 * scale);
	mChoiceButton1->GetTextTransform()->SetHeight(mChoiceButton1->GetTransform()->GetHeight() - 20 * scale);
	mChoiceButton2->SetParentLayout(mChoiceButtonRect->GetTransform());
	mChoiceButton2->GetTextTransform()->SetWidth(mChoiceButton2->GetTransform()->GetWidth() - 20 * scale);
	mChoiceButton2->GetTextTransform()->SetHeight(mChoiceButton2->GetTransform()->GetHeight() - 20 * scale);
}

void Scene::ProceedToScenePart(unsigned int scenePart)
{
	if (mApp->GetInput()->MouseButtonReleased(MOUSE_BUTTON_LEFT) || mApp->GetInput()->KeyReleased(KEY_SPACE))
		mPart = scenePart;
}
