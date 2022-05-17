#include "Scene2.h"

Scene2::Scene2(std::shared_ptr<wand::App> app, 
	std::shared_ptr<AssetManager> assetManager, std::shared_ptr<SceneData> sceneData)
	: Scene(app, assetManager, sceneData)
{}

bool Scene2::Play()
{
	bool isPlaying = true;

	if (mPart == 0)
	{
		mVoid->SetSprite("void confident");
		mTextBox->SetText("Welcome back. Let's see...");
		ProceedToScenePart(1);
	}
	else if (mPart == 1)
	{
		if (mSceneData->likability < 0)
		{
			mVoid->SetSprite("void evil");
			mTextBox->SetText("You don't like me much, do you human?");
			ProceedToScenePart(2);
		}
		else if (mSceneData->likability > 0)
		{
			mVoid->SetSprite("void shy smile");
			mTextBox->SetText("I quite like you, human. "
				+ std::string("You've been nice so far, and I appreciate it."));
			ProceedToScenePart(4);
		}
		else
		{
			mVoid->SetSprite("void smile");
			mTextBox->SetText("I don't hate you, human, but I don't like you either.");
			ProceedToScenePart(3);
		}
	}
	else if (mPart == 2)
	{
		mVoid->SetSprite("void confident");
		mTextBox->SetText("Don't worry~ The feeling's mutual.");
		ProceedToScenePart(4);
	}
	else if (mPart == 3)
	{
		mVoid->SetSprite("void smile");
		mTextBox->SetText("Let's see if we can get along better from now on~");
		ProceedToScenePart(4);
	}
	else if (mPart == 4)
	{
		mVoid->SetSprite("void smile");
		mTextBox->SetText("In any case, let me move on to my actual point.");
		ProceedToScenePart(5);
	}
	else if (mPart == 5)
	{
		mTextBox->SetText("To repeat what I just did, you need to keep track of your game's States. "
			+ std::string("That is, all the things you want to remember even after the game exits."));
		ProceedToScenePart(6);
	}
	else if (mPart == 6)
	{
		mTextBox->SetText("You also need to set an OnClose method to the window. "
			+ std::string("This way, you'll do everything you need to do ")
			+ std::string("right before the player closes the window."));
		ProceedToScenePart(7);
	}
	else if (mPart == 7)
	{
		mVoid->SetSprite("void calm");
		mTextBox->SetText("Now, you might be wondering where you can find all these things.");
		ProceedToScenePart(8);
	}
	else if (mPart == 8)
	{
		mVoid->SetSprite("void smile");
		mTextBox->SetText("It's simple, really.");
		ProceedToScenePart(9);
	}
	else if (mPart == 9)
	{
		mTextBox->SetText("All the major subsystems belong to the App. This includes things like "
			+ std::string("input, entities, states, fonts, audio, cursors, files, ")
			+ std::string("as well as the window itself."));
		ProceedToScenePart(10);
	}
	else if (mPart == 10)
	{
		mTextBox->SetText("Whenever you need to access any of those, just request it from the app.");
		ProceedToScenePart(11);
	}
	else if (mPart == 11)
	{
		mTextBox->SetText("The engine also provides easy ways to generate random numbers, "
			+ std::string("log things for debugging purposes, and several other utility functions."));
		ProceedToScenePart(12);
	}
	else if (mPart == 12)
	{
		mTextBox->SetText("You can use these even more easily though "
			+ std::string("since they're simple, static functions that belong ")
			+ std::string("to their respective category within the wand namespace."));
		ProceedToScenePart(13);
	}
	else if (mPart == 13)
	{
		mVoid->SetSprite("void calm");
		mTextBox->SetText("For example, to get a random integer between 1 and 10, "
			+ std::string("all you have to do is type: 'wand::Random::GetInt(1, 10);'"));
		ProceedToScenePart(14);
	}
	else if (mPart == 14)
	{
		mVoid->SetSprite("void confident");
		mTextBox->SetText("Alright. All this monotonous talking is boring me to death.");
		ProceedToScenePart(15);
	}
	else if (mPart == 15)
	{
		mVoid->SetSprite("void smile");
		mTextBox->SetText("Feel free to close the window again, if you want, and go take a break. "
			+ std::string("I'll save the progress up to here and when you return, ")
			+ std::string("we'll continue with something a bit more interesting."));
		mSceneData->lastSceneIndex = 2;
		ProceedToScenePart(16);
	}
	else if (mPart == 16)
	{
		mTextBox->SetText("...");
		ProceedToScenePart(17);
	}
	else if (mPart == 17)
	{
		mTextBox->SetText(".........");
		ProceedToScenePart(18);
	}
	else if (mPart == 18)
	{
		mVoid->SetSprite("void surprised");
		mTextBox->SetText("Oh?");
		ProceedToScenePart(19);
	}
	else if (mPart == 19)
	{
		mTextBox->SetText("You're still here?");
		ProceedToScenePart(20);
	}
	else if (mPart == 20)
	{
		mVoid->SetSprite("void shy smile");
		mTextBox->SetText("Thanks for hanging around.");
		mSceneData->likability++;
		ProceedToScenePart(21);
	}
	else if (mPart == 21)
	{
		isPlaying = false;
	}

	return isPlaying;
}
