#include "FBullCowGame.h"
#include<map>
#define TMap std::map
using int32 = int;

FBullCowGame::FBullCowGame()  // constructor
{
	Reset();
}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;
	const FString Hiden_Word = "german";
	MyHiddenWord = Hiden_Word;
	MyCurrentTry = 1;
	bGameIsWon = false;
	return;
}

int32 FBullCowGame::GetMaxTries() const{return MyMaxTries;}

int32 FBullCowGame::GetCurrentTry() const{return MyCurrentTry;}

int32 FBullCowGame::GetHiddenWordLength() const{return MyHiddenWord.length();}

bool FBullCowGame::IsGameWON() const{return bGameIsWon;}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess))
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

FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
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

bool FBullCowGame::IsIsogram(FString Word) const
{
	if (Word.length() <= 1) { return true; }
	TMap<char, bool> LetterSeen;
	for (auto Letter : Word)
	{
		Letter = tolower(Letter);
		if (LetterSeen[Letter])
		{
			return false;

		}
		else
		{
			LetterSeen[Letter] = true;
		}

	}

	return true;
}
