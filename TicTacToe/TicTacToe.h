#pragma once

#include <vector>

#include "Game.h"
#include "Player.h"
#include "GameField.h"
#include "GameFieldRenderer.h"
#include "Cursor.h"

class TicTacToe : public Game
{
public:

	TicTacToe();

protected:
	void start() override;
	bool haveWinner() override;
	void takeTurn() override;
	char getWinner() override;
	bool isDraw() override;

private:
	char readInput();
	void moveCursor(char direction);

private:
	std::vector<std::unique_ptr<Player>> players_;
	std::shared_ptr<GameField> game_field_;
	std::unique_ptr<GameFieldRenderer> renderer_;
	std::unique_ptr<Cursor> cursor_;
};