#pragma once
#include<string>

using Fstring = std::string;
using int32 = int;
//all values initialised to zero
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum EGuessStatus
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Not_Lowercase,
	Wrong_Length,
};

class FBullCowGame
{
public:
	FBullCowGame(); //constructor
	void Reset();

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWON() const;
	EGuessStatus CheckGuessValidity(Fstring) const;
	
	FBullCowCount SubmitGuess(Fstring);

private:

	//see constructor for initialisation
	int32 MyCurrentTry;
	int32 MyMaxTries;
	Fstring  MyHiddenWord;
	bool bGameIsWon;
};