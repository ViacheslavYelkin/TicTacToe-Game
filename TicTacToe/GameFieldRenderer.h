#pragma once

#include "GameField.h"

class GameFieldRenderer {
public:

	GameFieldRenderer(std::shared_ptr<GameField> game_field);

	void printGameField();

private:
	std::shared_ptr<GameField> game_field_;
};