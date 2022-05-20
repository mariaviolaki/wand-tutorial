#include "Scene3.h"

Scene3::Scene3(std::shared_ptr<wand::App> app, std::shared_ptr<AssetManager> assetManager,
	std::shared_ptr<SceneDataManager> sceneDataManager)
	: Scene(app, assetManager, sceneDataManager)
{}

bool Scene3::Play()
{
	bool isPlaying = true;

	if (mPart == 0)
	{
		// Initialize scene
		mSceneDataManager->LoadData();
		LoadData();
		mBackground->SetSprite(mSceneData->backgroundSprite);
		mPart = 1;
	}
	if (mPart == 1)
	{
		mVoid->SetSprite("void smile");
		mTextBox->SetText("Let's continue then.");
		ProceedToScenePart(2);
	}
	else if (mPart == 2)
	{
		mVoid->SetLayoutPosition(wand::LayoutPosition::MIDLEFT, wand::LayoutPosition::BOTTOM);
		mBlob->SetLayoutPosition(wand::LayoutPosition::MIDRIGHT, wand::LayoutPosition::MIDDLEY);
		mBlob->Show();
		mTextBox->SetText("First of all, let me introduce you to Blob, "
			+ std::string("my little helper for this lesson."));
		ProceedToScenePart(3);
	}
	else if (mPart == 3)
	{
		mVoid->SetSprite("void evil");
		mTextBox->SetText("I'm going to position him in different parts of the window, "
			+ std::string("flip him, and rotate him in different angles."));
		ProceedToScenePart(4);
	}
	else if (mPart == 4)
	{
		mChoiceButton1->SetText("Why don't you change your own position?");
		mChoiceButton1->OnLeftClick([this]() { mSceneData->likability--; this->mPart = 5; });
		mChoiceButton1->Show();
		mChoiceButton2->SetText("Ooh, fun!");
		mChoiceButton2->OnLeftClick([this]() { mSceneData->likability++; this->mPart = 7; });
		mChoiceButton2->Show();
	}
	else if (mPart == 5)
	{
		mChoiceButton1->Hide();
		mChoiceButton2->Hide();
		mTextBox->SetText("...");
		ProceedToScenePart(6);
	}
	else if (mPart == 6)
	{
		mVoid->SetSprite("void evil smile");
		mTextBox->SetText("How about no?");
		ProceedToScenePart(8);
	}
	else if (mPart == 7)
	{
		mChoiceButton1->Hide();
		mChoiceButton2->Hide();
		mVoid->SetSprite("void super evil");
		mTextBox->SetText("I know right?");
		ProceedToScenePart(8);
	}
	else if (mPart == 8)
	{
		mVoid->SetLayoutPosition(wand::LayoutPosition::MIDDLEX, wand::LayoutPosition::BOTTOM);
		mVoid->SetSprite("void evil");
		mTextBox->SetText("Anyways, watch~");
		ProceedToScenePart(9);
	}
	else if (mPart == 9)
	{
		mVoid->SetSprite("void calm");
		mTextBox->SetText("...");
		mBlob->GetTransform()->SetFlip(wand::FlipAxis::FLIP_Y);
		ProceedToScenePart(10);
	}
	else if (mPart == 10)
	{
		mBlob->GetTransform()->SetFlip(wand::FlipAxis::FLIP_XY);
		ProceedToScenePart(11);
	}
	else if (mPart == 11)
	{
		mBlob->GetTransform()->SetFlip(wand::FlipAxis::FLIP_X);
		ProceedToScenePart(12);
	}
	else if (mPart == 12)
	{
		mBlob->GetTransform()->SetFlip(wand::FlipAxis::FLIP_NONE);
		mBlob->GetTransform()->SetRotation(45.0f);
		ProceedToScenePart(13);
	}
	else if (mPart == 13)
	{
		mBlob->GetTransform()->SetRotation(90.0f);
		ProceedToScenePart(14);
	}
	else if (mPart == 14)
	{
		mBlob->GetTransform()->SetRotation(225.0f);
		ProceedToScenePart(15);
	}
	else if (mPart == 15)
	{
		mBlob->GetTransform()->SetRotation(0.0f);
		mBlob->SetLayoutPosition(wand::LayoutPosition::LEFT, wand::LayoutPosition::TOP);
		ProceedToScenePart(16);
	}
	else if (mPart == 16)
	{
		mBlob->SetLayoutPosition(wand::LayoutPosition::MIDLEFT, wand::LayoutPosition::TOP);
		ProceedToScenePart(17);
	}
	else if (mPart == 17)
	{
		mBlob->SetLayoutPosition(wand::LayoutPosition::MIDDLEX, wand::LayoutPosition::TOP);
		ProceedToScenePart(18);
	}
	else if (mPart == 18)
	{
		mBlob->SetLayoutPosition(wand::LayoutPosition::MIDRIGHT, wand::LayoutPosition::TOP);
		ProceedToScenePart(19);
	}
	else if (mPart == 19)
	{
		mBlob->SetLayoutPosition(wand::LayoutPosition::RIGHT, wand::LayoutPosition::TOP);
		ProceedToScenePart(20);
	}
	else if (mPart == 20)
	{
		mBlob->SetLayoutPosition(wand::LayoutPosition::RIGHT, wand::LayoutPosition::MIDTOP);
		ProceedToScenePart(21);
	}
	else if (mPart == 21)
	{
		mBlob->SetLayoutPosition(wand::LayoutPosition::RIGHT, wand::LayoutPosition::MIDDLEY);
		ProceedToScenePart(22);
	}
	else if (mPart == 22)
	{
		mBlob->SetLayoutPosition(wand::LayoutPosition::RIGHT, wand::LayoutPosition::MIDBOTTOM);
		ProceedToScenePart(23);
	}
	else if (mPart == 23)
	{
		mBlob->SetLayoutPosition(wand::LayoutPosition::RIGHT, wand::LayoutPosition::BOTTOM);
		ProceedToScenePart(24);
	}
	else if (mPart == 24)
	{
		mBlob->Hide();
		mTextBox->SetText("Hehe~");
		ProceedToScenePart(25);
	}
	else if (mPart == 25)
	{
		mVoid->SetSprite("void smile");
		mTextBox->SetText("If you were too excited to notice just now, "
			+ std::string("there are 5 different positions for each axis. For example, ")
			+ std::string("for the X-axis, you can place things in one of the following positions: ")
			+ std::string("left, midleft, middlex, midright, and right."));
		ProceedToScenePart(26);
	}
	else if (mPart == 26)
	{
		mTextBox->SetText("Of course you can also set your own coordinates if you want. "
			+ std::string("If you decide to use one of the default positions, though, ")
			+ std::string("remember to set a container (or layout) ")
			+ std::string("because you want to position the entity relative to another one."));
		ProceedToScenePart(27);
	}
	else if (mPart == 27)
	{
		mTextBox->SetText("As for moving things in place, you can set the flip axis as FLIP_X, FLIP_Y, "
			+ std::string("or FLIP_XY, if you want to flip vertically, horizontally, or both. ")
			+ std::string("To rotate the entity around itself, ")
			+ std::string("just set the number of degrees for the rotation."));
		ProceedToScenePart(28);
	}
	else if (mPart == 28)
	{
		mTextBox->SetText("To specify any exact coordinates, dimensions, rotation degrees, or flip axes "
			+ std::string("you'll need to get the entity's Transform ")
			+ std::string("since it contains most of the positioning data."));
		ProceedToScenePart(29);
	}
	else if (mPart == 29)
	{
		mTextBox->SetText("But if you want to set a parent layout or specify any default positions, "
			+ std::string("you'll find all the functions you need by simply accessing the entity."));
		ProceedToScenePart(30);
	}
	else if (mPart == 30)
	{
		mTextBox->SetText("Lastly, I should also mention that you can also set an entity's depth layer "
			+ std::string("through its Transform. A high layer number means that this specific object ")
			+ std::string("will appear in front of many others on the screen."));
		ProceedToScenePart(31);
	}
	else if (mPart == 31)
	{
		mTextBox->SetText("Keep in mind, though, that this doesn't apply to children entities "
			+ std::string("as they adopt the layer of their parent layout."));
		ProceedToScenePart(32);
	}
	else if (mPart == 32)
	{
		mBlob->SetLayoutPosition(wand::LayoutPosition::MIDRIGHT, wand::LayoutPosition::MIDDLEY);
		mBlob->Show();
		mTextBox->SetText("Blob, for example, has the background as his container. "
			+ std::string("That's why he never appeared in front of other things."));
		ProceedToScenePart(33);
	}
	else if (mPart == 33)
	{
		mBlob->Hide();
		mVoid->SetSprite("void calm");
		mTextBox->SetText("And with all that out of the way, let's address the elephant in the room. "
			+ std::string("What's that thing that's present in every game ")
			+ std::string("and yet I still haven't covered?"));
		ProceedToScenePart(34);
	 }
	else if (mPart == 34)
	{
		mSceneData->lastSceneIndex = 3;
		SaveData();
		isPlaying = false;
	}

	return isPlaying;
}
