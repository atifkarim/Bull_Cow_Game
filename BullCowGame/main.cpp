#pragma once

#include<iostream>
#include<string>
#include"FBullCowGame.h"
//using namespace std;

FBullCowGame BCGame;

using FText = std::string;
using int32 = int;

void PrintIntro();
FText GetvalidGuess(); // this is proto typing of a function
void PlayGame();
bool AskToPlayAgain();
void PrintGameSumarry();

// the entry point of our application
int main() {

	bool bPlayAgain = false;
	do {

		PrintIntro();
		PlayGame();
		bPlayAgain= AskToPlayAgain();
	} while (bPlayAgain);
	return 0;
}


void PrintIntro() {
	//introduce the game
	//constexpr int32 WORD_LENGTH = 9;
	std::cout << "\n\n Welcome to BullCoW Game !!!" << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I am thinking of?" << std::endl;
	return;
}

void PlayGame()
{
	BCGame.Reset();
	 // Instantiate a new game
	int32 Maxtries=BCGame.GetMaxTries();
	std::cout << Maxtries << std::endl;
	//loop asking for guesses
	//if NOT WON and still tries remaining
	while(!BCGame.IsGameWON() && BCGame.GetCurrentTry()<= Maxtries) //TODO check valid guess
	{
		FText Guess;
		Guess= GetvalidGuess();
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		std::cout << "Bulls= " << BullCowCount.Bulls;
		std::cout << ". Cows= " << BullCowCount.Cows << std::endl;
		std::cout << "your guess was: " << Guess << std::endl;
		std::cout << std::endl;
	} //std::cout << "Hurrah !! WIN !!!\n" << std::endl;

	PrintGameSumarry(); // Summary of the game OR result of the game
	return;
}





FText GetvalidGuess() {
	FText Guess;
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do
	{
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << " of " << BCGame.GetMaxTries()<<" ";
		//get guess from the player
		
		std::cout << " -- Enter your guess: ";
		std::getline(std::cin, Guess);
		//std::cout << "your guess is " << Guess << std::endl;

		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please Enter " << BCGame.GetHiddenWordLength() << " letter word" << std::endl;
			break;

		case EGuessStatus::Not_Isogram:
			std::cout << "Please don't use repeated words" << std::endl;
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please use all lower case word.\n";
			break;
		default:
			break;

	}  
	

	} while (Status != EGuessStatus::OK); //keep looping until we get valid input
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again(press y/Y to play again. Other input will close the game)? ";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}

void PrintGameSumarry()
{
	if (BCGame.IsGameWON())
	{
		std::cout << "You have WON the Game !!!\n";
	}
	else
	{
		std::cout << "Better luck next time\n";
	}
}
