#include <iostream>
#include <iomanip>
#include <memory>

#include "GameFieldRenderer.h"

GameFieldRenderer::GameFieldRenderer(std::shared_ptr<GameField> game_field)
	: game_field_{game_field}
{
}

void GameFieldRenderer::printGameField()
{
	// printing game field with different formatting
	for (int i{}; i < game_field_->rows_; i++) {
		for (int j{}; j < game_field_->columns_; j++) {
			std::cout << std::setw(5) << game_field_->at(i, j);
		}
		std::cout << '\n';
	}
}
