#include <conio.h>

#include "Game.h"

Game::Game(int number_of_players)
	: number_of_players_(number_of_players)
{
}

void Game::run()
{
	bool have_winner{};
	
	start();
	while (!have_winner)
	{
		takeTurn();

		have_winner = haveWinner();

		if (!have_winner && isDraw()) {
			break;
		}

	}

	if (have_winner) 
	{
		std::cout << "Side '" << getWinner() << "' wins.\n";
	}
	else 
	{
		std::cout << "What a sweaty game, try one more time :)\n";
	}
}