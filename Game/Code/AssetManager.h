#pragma once
#include "Wand.h"

class AssetManager
{
public:
	AssetManager(wand::App* app);

	template<typename T>
	T Get(std::string label) {};
	template<>
	wand::Sprite* Get(std::string label);
	template<>
	wand::Rectangle* Get(std::string label);
	template<>
	wand::TextBox* Get(std::string label);
	template<>
	wand::Button* Get(std::string label);
	template<>
	wand::Background* Get(std::string label);
	template<>
	wand::Character* Get(std::string label);

private:
	wand::App* mApp;
	std::vector<wand::Font*> mFonts;
	std::vector<wand::Sprite*> mSprites;
	std::vector<wand::Rectangle*> mRectangles;
	std::vector<wand::TextBox*> mTextBoxes;
	std::vector<wand::Button*> mButtons;
	std::vector<std::shared_ptr<wand::Background>> mBackgrounds;
	std::vector<std::shared_ptr<wand::Character>> mCharacters;

	// Load fonts
	void LoadFonts();
	// Load UI entities
	void LoadSprites();
	void LoadRectangles();
	void LoadTextBoxes();
	void LoadButtons();
	// Load visual novel entities
	void LoadBackgrounds();
	void LoadCharacters();
};
