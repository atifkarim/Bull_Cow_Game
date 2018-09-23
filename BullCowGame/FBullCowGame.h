#pragma once
#include<string>

using FString = std::string;
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
	EGuessStatus CheckGuessValidity(FString) const;
	
	FBullCowCount SubmitGuess(FString);

private:

	//see constructor for initialisation
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString  MyHiddenWord;
	bool bGameIsWon;
	bool IsIsogram(FString) const;
	bool IsLowercase(FString) const; //no need to give a specific name in the prototype.
									// In cpp we gave it a variable name called "Word" 
};