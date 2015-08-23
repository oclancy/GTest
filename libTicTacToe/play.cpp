
#include "stdafx.h"
#include "libTicTacToe.h"
#include "Player.h"
#include "Episode.h"
#include "QlearningIntelligence.h"
#include <memory>

namespace libTicTacToe
{
void Play()
{
	system("cls");

	std::unique_ptr<CPlayer> player1;
	std::unique_ptr<CPlayer> player2;


	std::cout << "Please enter type of intelligence: (q)learning, (s)arsa";
	char choice;
	std::cin >> choice;

	auto ai = GetArtificialIntelligence(tolower(choice));

	std::cout << "Please enter filename for intelligence. (enter 'none' for no file load)";
	
	std::string filename;
	std::cin >> filename;
	if(filename != "none")
		ai->Load(filename);

	std::cout << "You are 'x'. Would you like to go 1st or 2nd? (enter 1 or 2)";
	int response;
	std::cin >> response;

	if (response == 1)
	{
		player1.reset(new CManualPlayer('x'));
		player2.reset(new CAutoPlayer('o', *ai));
	}
	else
	{
		player2.reset(new CManualPlayer('x'));
		player1.reset(new CAutoPlayer('o', *ai));
	}

	CEpisode::Play(*player1, *player2);

	getchar();
	std::cin.get();
}
}