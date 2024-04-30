#pragma once

#include <iostream>


class Game
{
public:
	explicit Game(int number_of_players);

	void run(); 

protected:
	virtual void start() = 0;
	virtual bool haveWinner() = 0;
	virtual bool isDraw() = 0;
	virtual void takeTurn() = 0;
	virtual char getWinner() = 0;

	int current_player_{ 0 };
	int number_of_players_;
};