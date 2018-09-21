#include "FBullCowGame.h"
using int32 = int;

FBullCowGame::FBullCowGame()  // constructor
{
	Reset();
}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;
	const Fstring Hiden_Word = "german";
	MyHiddenWord = Hiden_Word;
	MyCurrentTry = 1;
	bGameIsWon = false;
	return;
}

int32 FBullCowGame::GetMaxTries() const{return MyMaxTries;}

int32 FBullCowGame::GetCurrentTry() const{return MyCurrentTry;}

int32 FBullCowGame::GetHiddenWordLength() const{return MyHiddenWord.length();}

bool FBullCowGame::IsGameWON() const{return bGameIsWon;}

EGuessStatus FBullCowGame::CheckGuessValidity(Fstring Guess) const
{
	if (false)
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (false)
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength())
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}
}

FBullCowCount FBullCowGame::SubmitGuess(Fstring Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLength = MyHiddenWord.length(); //assume like guess
	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++) //MyHiddenWordChar=MHWChar
	{
		for (int32 GChar = 0; GChar < WordLength; GChar++) //GuessChar=GChar
		{
			if (Guess[GChar]==MyHiddenWord[MHWChar])
			{
				if (MHWChar==GChar)
				{
					BullCowCount.Bulls++;

				}
				else
				{
					BullCowCount.Cows++;
				}

			}
		}

	} 
	if (BullCowCount.Bulls==WordLength)
	{
		bGameIsWon = true;
	}
	else
	{
		bGameIsWon = false;
	}
	return BullCowCount;
}
