#include "AssetManager.h"

AssetManager::AssetManager(wand::App* app)
	: mApp(app)
{
	// Load all assets into the engine
	LoadFonts();
	LoadSprites();
	LoadRectangles();
	LoadTextBoxes();
	LoadButtons();
	LoadBackgrounds();
	LoadCharacters();
}

template<>
wand::Sprite* AssetManager::Get(std::string label)
{
	// Get the iterator of the sprite with the target name
	auto spriteIt = std::find_if(mSprites.begin(), mSprites.end(),
		[&label](wand::Sprite* s) { return s->GetLabel() == label; });
	// Return the sprite after using the iterator to find its index in the vector
	return mSprites[std::distance(mSprites.begin(), spriteIt)];
}
template<>
wand::Rectangle* AssetManager::Get(std::string label)
{
	// Get the iterator of the rectangle with the target name
	auto rectangleIt = std::find_if(mRectangles.begin(), mRectangles.end(),
		[&label](wand::Rectangle* r) { return r->GetLabel() == label; });
	// Return the rectangle after using the iterator to find its index in the vector
	return mRectangles[std::distance(mRectangles.begin(), rectangleIt)];
}
template<>
wand::TextBox* AssetManager::Get(std::string label)
{
	// Get the iterator of the textbox with the target name
	auto textBoxIt = std::find_if(mTextBoxes.begin(), mTextBoxes.end(),
		[&label](wand::TextBox* t) { return t->GetLabel() == label; });
	// Return the textbox after using the iterator to find its index in the vector
	return mTextBoxes[std::distance(mTextBoxes.begin(), textBoxIt)];
}
template<>
wand::Button* AssetManager::Get(std::string label)
{
	// Get the iterator of the button with the target name
	auto buttonIt = std::find_if(mButtons.begin(), mButtons.end(),
		[&label](wand::Button* b) { return b->GetLabel() == label; });
	// Return the button after using the iterator to find its index in the vector
	return mButtons[std::distance(mButtons.begin(), buttonIt)];
}
template<>
wand::Background* AssetManager::Get(std::string label)
{
	// Get the iterator of the background with the target name
	auto backgroundIt = std::find_if(mBackgrounds.begin(), mBackgrounds.end(),
		[&label](std::shared_ptr<wand::Background>& b) { return b->GetName() == label; });
	// Return the background after using the iterator to find its index in the vector
	return mBackgrounds[std::distance(mBackgrounds.begin(), backgroundIt)].get();
}
template<>
wand::Character* AssetManager::Get(std::string label)
{
	// Get the iterator of the character with the target name
	auto characterIt = std::find_if(mCharacters.begin(), mCharacters.end(),
		[&label](std::shared_ptr<wand::Character>& c) { return c->GetName() == label; });
	// Return the character after using the iterator to find its index in the vector
	return mCharacters[std::distance(mCharacters.begin(), characterIt)].get();
}

void AssetManager::LoadFonts()
{
	std::string fontDir = mApp->GetFileManager()->GetRootFolder() + "Game\\Fonts\\";

	mApp->GetFontManager()->Add(fontDir + "Sundae-Ice.ttf", "Sundae-Ice", 30);
	mFonts.emplace_back(mApp->GetFontManager()->Get("Sundae-Ice", 30));
}

void AssetManager::LoadSprites()
{
	std::string imageDir = mApp->GetFileManager()->GetRootFolder() + "Game\\Images\\";

	// Load a blob sprite
	auto blob = mApp->GetEntityManager()->AddSprite(imageDir + "blob.png");
	mSprites.emplace_back(blob);
	blob->SetLabel("blob");
	blob->GetTransform()->SetLayer(1);
	blob->GetTransform()->SetWidth(200);
	blob->GetTransform()->SetHeight(160);
	blob->Hide();
}

void AssetManager::LoadRectangles()
{
	// Background rectangle for text
	auto textRect = mApp->GetEntityManager()->AddRectangle(wand::Color(102, 106, 134, 210));
	mRectangles.emplace_back(textRect);
	textRect->SetLabel("text rect");
	textRect->GetTransform()->SetPos(0, 0);
	textRect->GetTransform()->SetWidth(mApp->GetWindow()->GetStartWidth());
	textRect->GetTransform()->SetHeight(140);
	textRect->GetTransform()->SetLayer(2);
	
	// Background rectangle for character names
	auto nameRect = mApp->GetEntityManager()->AddRectangle(wand::Color(51, 51, 51, 240));
	mRectangles.emplace_back(nameRect);
	nameRect->SetLabel("name rect");
	nameRect->GetTransform()->SetPos(0, 140);
	nameRect->GetTransform()->SetWidth(mApp->GetWindow()->GetStartWidth());
	nameRect->GetTransform()->SetHeight(50);
	nameRect->GetTransform()->SetLayer(2);

	// Transparent layout for choice buttons
	auto choiceButtonRect = mApp->GetEntityManager()->AddRectangle(wand::Color(0, 0, 0, 0));
	mRectangles.emplace_back(choiceButtonRect);
	choiceButtonRect->SetLabel("choice button rect");
	choiceButtonRect->GetTransform()->SetPos(0, 0);
	choiceButtonRect->GetTransform()->SetWidth(mApp->GetWindow()->GetStartWidth());
	choiceButtonRect->GetTransform()->SetHeight(mApp->GetWindow()->GetStartHeight());
	choiceButtonRect->GetTransform()->SetLayer(4);
	choiceButtonRect->Hide();
}

void AssetManager::LoadTextBoxes()
{
	// Textbox for main text
	auto textBox = mApp->GetEntityManager()->AddTextBox("Sundae-Ice", 30, wand::Color(255, 255, 255, 255));
	mTextBoxes.emplace_back(textBox);
	textBox->GetTransform()->SetPos(20, 10);
	textBox->GetTransform()->SetLayer(3);
	textBox->GetTransform()->SetWidth(mApp->GetWindow()->GetStartWidth() - 20);
	textBox->GetTransform()->SetHeight(130);
	textBox->SetLabel("textbox");

	// Textbox for character names
	auto nameBox = mApp->GetEntityManager()->AddTextBox("Sundae-Ice", 40, wand::Color(237, 175, 184, 255));
	mTextBoxes.emplace_back(nameBox);
	nameBox->GetTransform()->SetPos(20, 140);
	nameBox->GetTransform()->SetLayer(3);
	nameBox->GetTransform()->SetWidth(mApp->GetWindow()->GetStartWidth() - 20);
	nameBox->GetTransform()->SetHeight(50);
	nameBox->SetLabel("namebox");
}

void AssetManager::LoadButtons()
{
	std::string imageDir = mApp->GetFileManager()->GetRootFolder() + "Game\\Images\\";
	// Create 3 choice buttons
	for (int i = 1; i < 4; i++)
	{
		auto choiceButton = mApp->GetEntityManager()->AddButton(
			imageDir + "choice_button.png", "Sundae-Ice", 25, wand::Color(255, 255, 255, 255));
		mButtons.emplace_back(choiceButton);
		choiceButton->SetLabel("choice button " + std::to_string(i));
		choiceButton->GetTransform()->SetWidth((2 * mApp->GetWindow()->GetStartWidth()) / 3);
		choiceButton->GetTransform()->SetHeight(100);
		choiceButton->GetTransform()->SetLayer(4);
		choiceButton->Hide();
	}
}

void AssetManager::LoadBackgrounds()
{
	std::string imageDir = mApp->GetFileManager()->GetRootFolder() + "Game\\Images\\";

	// Create and save a new background
	auto background = std::make_shared<wand::Background>("main background");
	mBackgrounds.emplace_back(background);

	// Load background images
	auto weirdForest = mApp->GetEntityManager()->AddSprite(imageDir + "weird_forest.png");
	weirdForest->SetLabel("weird forest");
	weirdForest->GetTransform()->SetPos(0, 0);
	weirdForest->GetTransform()->SetLayer(0);
	weirdForest->GetTransform()->SetWidth(mApp->GetWindow()->GetStartWidth());
	weirdForest->GetTransform()->SetHeight(mApp->GetWindow()->GetStartHeight());
	background->AddSprite(weirdForest);

	auto creepyForest = mApp->GetEntityManager()->AddSprite(imageDir + "creepy_forest.png");
	creepyForest->SetLabel("creepy forest");
	creepyForest->GetTransform()->SetPos(0, 0);
	creepyForest->GetTransform()->SetLayer(0);
	creepyForest->GetTransform()->SetWidth(mApp->GetWindow()->GetStartWidth());
	creepyForest->GetTransform()->SetHeight(mApp->GetWindow()->GetStartHeight());
	background->AddSprite(creepyForest);
}

void AssetManager::LoadCharacters()
{
	std::string imageDir = mApp->GetFileManager()->GetRootFolder() + "Game\\Images\\";

	// Create and save a new character
	auto cVoid = std::make_shared<wand::Character>("Void");
	mCharacters.emplace_back(cVoid);

	// Load character images
	auto voidSmile = mApp->GetEntityManager()->AddSprite(imageDir + "void_smile.png");
	voidSmile->SetLabel("void smile");
	cVoid->AddSprite(voidSmile);

	auto voidSurprised = mApp->GetEntityManager()->AddSprite(imageDir + "void_surprised.png");
	voidSurprised->SetLabel("void surprised");
	cVoid->AddSprite(voidSurprised);

	auto voidShySmile = mApp->GetEntityManager()->AddSprite(imageDir + "void_shy_smile.png");
	voidShySmile->SetLabel("void shy smile");
	cVoid->AddSprite(voidShySmile);

	auto voidEvil = mApp->GetEntityManager()->AddSprite(imageDir + "void_evil.png");
	voidEvil->SetLabel("void evil");
	cVoid->AddSprite(voidEvil);

	auto voidConfident = mApp->GetEntityManager()->AddSprite(imageDir + "void_confident.png");
	voidConfident->SetLabel("void confident");
	cVoid->AddSprite(voidConfident);

	auto voidEvilSmile = mApp->GetEntityManager()->AddSprite(imageDir + "void_evil_smile.png");
	voidEvilSmile->SetLabel("void evil smile");
	cVoid->AddSprite(voidEvilSmile);

	auto voidCalm = mApp->GetEntityManager()->AddSprite(imageDir + "void_calm.png");
	voidCalm->SetLabel("void calm");
	cVoid->AddSprite(voidCalm);

	auto voidSuperEvil = mApp->GetEntityManager()->AddSprite(imageDir + "void_super_evil.png");
	voidSuperEvil->SetLabel("void super evil");
	cVoid->AddSprite(voidSuperEvil);

	// Set common character data after loading all sprites
	cVoid->SetWidth(450);
	cVoid->SetHeight(mApp->GetWindow()->GetStartHeight() - 20);
	cVoid->SetLayer(1);
}
