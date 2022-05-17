#include "Scene1.h"

Scene1::Scene1(std::shared_ptr<wand::App> app, 
	std::shared_ptr<AssetManager> assetManager, std::shared_ptr<SceneData> sceneData)
	: Scene(app, assetManager, sceneData)
{}

bool Scene1::Play()
{
	bool isPlaying = true;

	if (mPart == 0)
	{
		mTextBox->SetText("Everything you see on the screen is made up of 3 basic UI entities: "
			+ std::string("Rectangles, Sprites, and TextBoxes."));
		ProceedToScenePart(1);
	}
	else if (mPart == 1)
	{
		mTextBox->SetText("Buttons are a combination of 1 Rectangle and 1 Textbox, or 1 Sprite and 1 TextBox.");
		ProceedToScenePart(2);
	}
	else if (mPart == 2)
	{
		mVoid->SetSprite("void confident");
		mTextBox->SetText("Simple, right?");
		ProceedToScenePart(3);
	}
	else if (mPart == 3)
	{
		mChoiceButton1->SetText("Yep!");
		mChoiceButton1->OnLeftClick([this]() { this->mPart = 4; });
		mChoiceButton1->Show();
		mChoiceButton2->SetText("Can you give me an example?");
		mChoiceButton2->OnLeftClick([this]() { this->mPart = 5; });
		mChoiceButton2->Show();
	}
	else if (mPart == 4)
	{
		mChoiceButton1->Hide();
		mChoiceButton2->Hide();
		mVoid->SetSprite("void smile");
		mTextBox->SetText("Great.");
		ProceedToScenePart(12);
	}
	else if (mPart == 5)
	{
		mChoiceButton1->Hide();
		mChoiceButton2->Hide();
		mVoid->SetSprite("void smile");
		mTextBox->SetText("Sure.");
		ProceedToScenePart(6);
	}
	else if (mPart == 6)
	{
		mTextBox->SetText("Let's take the screen you see now as an example: "
			+ std::string("There are 2 grey Rectangles (1 for my name and 1 for what I say), ")
			+ std::string("2 TextBoxes that contain the actual letters, ")
			+ std::string("and 2 Sprites (me and the lovely background)."));
		ProceedToScenePart(7);
	}
	else if (mPart == 7)
	{
		mVoid->SetSprite("void confident");
		mTextBox->SetText("Although I like to think that I'm a lot more than just a Sprite.");
		ProceedToScenePart(8);
	}
	else if (mPart == 8)
	{
		mChoiceButton1->SetText("Yeah, right.");
		mChoiceButton1->OnLeftClick([this]() { mSceneData->likability--; this->mPart = 11; });
		mChoiceButton1->Show();
		mChoiceButton2->SetText("I believe so too.");
		mChoiceButton2->OnLeftClick([this]() { mSceneData->likability++; this->mPart = 9; });
		mChoiceButton2->Show();
	}
	else if (mPart == 9)
	{
		mChoiceButton1->Hide();
		mChoiceButton2->Hide();
		mVoid->SetSprite("void shy smile");
		mTextBox->SetText("You're a kind one, aren't you?");
		ProceedToScenePart(10);
	}
	else if (mPart == 10)
	{
		mTextBox->SetText("Still, allow me to prove it to you in a more tangible way.");
		ProceedToScenePart(13);
	}
	else if (mPart == 11)
	{
		mChoiceButton1->Hide();
		mChoiceButton2->Hide();
		mTextBox->SetText("Oh, but I am.");
		ProceedToScenePart(13);
	}
	else if (mPart == 12)
	{
		mTextBox->SetText("Let's move on to something a bit more complicated then.");
		ProceedToScenePart(13);
	}
	else if (mPart == 13)
	{
		mVoid->SetSprite("void smile");
		mTextBox->SetText("Although Sprites can exist independently, Characters such as I "
			+ std::string("as well as Backgrounds can be comprised of more than 1 Sprite."));
		ProceedToScenePart(14);
	}
	else if (mPart == 14)
	{
		mTextBox->SetText("The same Character can have more than 1 expression, for example, "
			+ std::string("and the Background can also have plenty of variations."));
		ProceedToScenePart(15);
	}
	else if (mPart == 15)
	{
		mTextBox->SetText("Both are considered VN entities as far as the engine is concerned, "
			+ std::string("and they're very similar to the 3 basic UI entites I mentioned earlier."));
		ProceedToScenePart(16);
	}
	else if (mPart == 16)
	{
		mTextBox->SetText("They just have the bonus feature of allowing the developer "
			+ std::string("to set a different Sprite easily."));
		ProceedToScenePart(17);
	}
	else if (mPart == 17)
	{
		mTextBox->SetText("If you decide to use Characters and Backgrounds, however, "
			+ std::string("remember to label all the different Sprites. ")
			+ std::string("Labels are optional for all UI entities, but can be very useful ")
			+ std::string("- especially when you need to tell things apart."));
		ProceedToScenePart(18);
	}
	else if (mPart == 18)
	{
		mVoid->SetSprite("void confident");
		mTextBox->SetText("Now, let's try something a bit more fun, shall we?");
		ProceedToScenePart(19);
	}
	else if (mPart == 19)
	{
		mChoiceButton1->SetText("Sure!");
		mChoiceButton1->OnLeftClick([this]() { mSceneData->likability++; this->mPart = 20; });
		mChoiceButton1->Show();
		mChoiceButton2->SetText("Finally! I was getting kinda bored...");
		mChoiceButton2->OnLeftClick([this]() { mSceneData->likability--; this->mPart = 20; });
		mChoiceButton2->Show();
	}
	else if (mPart == 20)
	{
		mChoiceButton1->Hide();
		mChoiceButton2->Hide();
		mTextBox->SetText("Close the game then, and when you come back, "
			+ std::string("I'll tell you what I think of you ")
			+ std::string("based on the answers you've given me so far."));
		mSceneData->lastSceneIndex = 1;
		ProceedToScenePart(21);
	}
	else if (mPart == 21)
	{
		mVoid->SetSprite("void smile");
		mTextBox->SetText("...");
		ProceedToScenePart(22);
	}
	else if (mPart == 22)
	{
		mTextBox->SetText(".........");
		ProceedToScenePart(23);
	}
	else if (mPart == 23)
	{
		mVoid->SetSprite("void evil smile");
		mTextBox->SetText("I'm waiting~");
		ProceedToScenePart(21);
	}

	return isPlaying;
}
