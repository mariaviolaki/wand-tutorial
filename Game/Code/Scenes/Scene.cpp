#include "Scene.h"

Scene::Scene(std::shared_ptr<wand::App> app, std::shared_ptr<AssetManager> assetManager,
	std::shared_ptr<SceneDataManager> sceneDataManager)
	: mApp(app), mAssetManager(assetManager), mSceneDataManager(sceneDataManager), 
	mSceneData(std::make_unique<SceneData>()), mPart(0), mIsDataSaved(false)
{
	// Initialize all assets
	mChoiceButtonRect = mAssetManager->Get<wand::Rectangle*>("choice button rect");
	mNameBox = mAssetManager->Get<wand::TextBox*>("namebox");
	mTextBox = mAssetManager->Get<wand::TextBox*>("textbox");
	mBackground = mAssetManager->Get<wand::Background*>("main background");
	mVoid = mAssetManager->Get<wand::Character*>("Void");
	mChoiceButton1 = mAssetManager->Get<wand::Button*>("choice button 1");
	mChoiceButton2 = mAssetManager->Get<wand::Button*>("choice button 2");
	mBlob = mAssetManager->Get<wand::Sprite*>("blob");
	float scale = mBackground->GetTransform()->GetScale().x;

	// Customize the entities
	mNameBox->SetText(wand::Utils::ToUpper(mVoid->GetName()));
	mBackground->SetSprite(mSceneDataManager->GetData()->backgroundSprite);
	mVoid->SetParentLayout(mBackground->GetTransform());
	mVoid->SetLayoutPosition(wand::LayoutPosition::MIDDLEX, wand::LayoutPosition::BOTTOM);
	mChoiceButton1->SetParentLayout(mChoiceButtonRect->GetTransform());
	mChoiceButton1->GetTextTransform()->SetWidth(mChoiceButton1->GetTransform()->GetWidth() - 20 * scale);
	mChoiceButton1->GetTextTransform()->SetHeight(mChoiceButton1->GetTransform()->GetHeight() - 20 * scale);
	mChoiceButton1->SetLayoutPosition(wand::LayoutPosition::MIDDLEX, wand::LayoutPosition::MIDTOP);
	mChoiceButton2->SetParentLayout(mChoiceButtonRect->GetTransform());
	mChoiceButton2->GetTextTransform()->SetWidth(mChoiceButton2->GetTransform()->GetWidth() - 20 * scale);
	mChoiceButton2->GetTextTransform()->SetHeight(mChoiceButton2->GetTransform()->GetHeight() - 20 * scale);
	mChoiceButton2->SetLayoutPosition(wand::LayoutPosition::MIDDLEX, wand::LayoutPosition::MIDDLEY);
	mBlob->SetParentLayout(mBackground->GetTransform());
}

void Scene::LoadData()
{
	// Initialize scene data
	SceneData* savedSceneData = mSceneDataManager->GetData();
	mSceneData->likability = savedSceneData->likability;
	mSceneData->backgroundSprite = savedSceneData->backgroundSprite;
	mSceneData->lastSceneIndex = savedSceneData->lastSceneIndex;
	mSceneData->musicOn = savedSceneData->musicOn;
}

void Scene::SaveData()
{
	if (mIsDataSaved)
		return;
	mSceneDataManager->SaveData(mSceneData.get());
	mIsDataSaved = true;
}

void Scene::ProceedToScenePart(unsigned int scenePart, bool playSound)
{
	if (mApp->GetInput()->MouseButtonReleased(MOUSE_BUTTON_LEFT) || mApp->GetInput()->KeyReleased(KEY_SPACE))
	{
		if (playSound)
			mApp->GetAudioManager()->Play("spell", 1.5f);
		mPart = scenePart;
	}
}

void Scene::ProceedAndPlaySound(unsigned int scenePart)
{
	ProceedToScenePart(scenePart, true);
}
