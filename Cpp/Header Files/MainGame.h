#pragma once
#include<iostream>
#include<string>
#include<vector>
#include "../Source Files/Dictonary.cpp"

using std::cout;
using std::endl;
using std::cin;
using std::string;


class MainGame
{
public:

	enum class TURN : char
	{
		PLAYER1,
		PLAYER2
	};
	MainGame();
	~MainGame();
	void run();
private:
	void DisplayInstructions();
	string player1UserName,player2UsernName;
	void PlayRound(int i);
	bool PlayAgain();
	Dictonary dict;
	TURN _turn;
};
