#include "Scene5.h"

Scene5::Scene5(std::shared_ptr<wand::App> app, std::shared_ptr<AssetManager> assetManager,
	std::shared_ptr<SceneDataManager> sceneDataManager)
	: Scene(app, assetManager, sceneDataManager)
{}

bool Scene5::Play()
{
	bool isPlaying = true;

	if (mPart == 0)
	{
		// Initialize scene
		mSceneDataManager->LoadData();
		LoadData();
		mBackground->SetSprite(mSceneData->backgroundSprite);
		if (mSceneData->musicOn)
			mApp->GetAudioManager()->Play("whip");
		mPart = 1;
	}
	else if (mPart == 1)
	{
		mVoid->SetSprite("void confident");
		mTextBox->SetText("Oh, by the way, have you noticed "
			+ std::string("that you can also press the spacebar to continue?"));
		ProceedToScenePart(2);
	}
	else if (mPart == 2)
	{
		mChoiceButton1->SetText("Yes!");
		mChoiceButton1->OnLeftClick([this]() { this->mPart = 3; });
		mChoiceButton1->Show();
		mChoiceButton2->SetText("No?");
		mChoiceButton2->OnLeftClick([this]() { this->mPart = 3; });
		mChoiceButton2->Show();
	}
	else if (mPart == 3)
	{
		mChoiceButton1->Hide();
		mChoiceButton2->Hide();
		mVoid->SetSprite("void calm");
		mTextBox->SetText("Either way, I have no way of knowing if you did or not.");
		ProceedToScenePart(4);
	}
	else if (mPart == 4)
	{
		mVoid->SetSprite("void smile");
		mTextBox->SetText("Here's the code that checks your input and tells me when to keep talking: "
			+ std::string("\"if (app->GetInput()->MouseButtonReleased(MOUSE_BUTTON_LEFT) ")
			+ std::string("|| app->GetInput()->KeyReleased(KEY_SPACE))\""));
		ProceedToScenePart(5);
	}
	else if (mPart == 5)
	{
		mTextBox->SetText("So as you can see, if you get the Input from the App, "
			+ std::string("you can check how the player interacts with the UI."));
		ProceedToScenePart(6);
	}
	else if (mPart == 6)
	{
		mTextBox->SetText("This includes keyboard and mouse button presses, mouse movement, and "
			+ std::string("mouse scrolling."));
		ProceedToScenePart(7);
	}
	else if (mPart == 7)
	{
		mTextBox->SetText("You can also set functions to individual UI and VN entities "
			+ std::string("that run when the user clicks the left or right button, ")
			+ std::string("or hovers over this particular entity."));
		ProceedToScenePart(8);
	}
	else if (mPart == 8)
	{
		mTextBox->SetText("That's how I see which button you pressed when you want to react to something.");
		ProceedToScenePart(9);
	}
	else if (mPart == 9)
	{
		mVoid->SetSprite("void evil");
		mTextBox->SetText("Some of your answers matter more than others, of course, "
			+ std::string("and rest assured that I make my own conclusions about you."));
		ProceedToScenePart(10);
	}
	else if (mPart == 10)
	{
		mVoid->SetSprite("void calm");
		mTextBox->SetText("In any case, there's one more thing I'd like to explain, and that's the cursor.");
		ProceedToScenePart(11);
	}
	else if (mPart == 11)
	{
		mVoid->SetSprite("void smile");
		mTextBox->SetText("If you want the player to be able to interact with an entity, "
			+ std::string("you must first enable it. I imagine you've already noticed ")
			+ std::string("how the cursor changes when you hover over buttons, yes?"));
		ProceedToScenePart(12);
	}
	else if (mPart == 12)
	{
		mTextBox->SetText("You can also set or even create custom cursors if you want. "
			+ std::string("Just remember to give the engine an image ")
			+ std::string("if you don't like the standard cursors provided by your system."));
		ProceedToScenePart(13);
	}
	else if (mPart == 13)
	{
		mTextBox->SetText("...");
		ProceedToScenePart(14);
	}
	else if (mPart == 14)
	{
		mVoid->SetSprite("void calm");
		mTextBox->SetText("I believe this is everything.");
		ProceedToScenePart(15);
	}
	else if (mPart == 15)
	{
		mSceneData->lastSceneIndex = 5;
		SaveData();
		isPlaying = false;
	}

	return isPlaying;
}
