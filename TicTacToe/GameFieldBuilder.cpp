#include "GameFieldBuilder.h"

GameFieldBuilder::GameFieldBuilder()
	: game_field_{ nullptr }
{
}

void GameFieldBuilder::buildGameField()
{
	game_field_ = std::make_shared<GameField>(3,3); // creating GameField object with size of 3 by 3 matrix
	game_field_->initializeField(); // initializing matrix

	// filling initialized matrix with default symbol '-'
	for (int i{}; i < game_field_->rows_; i++) {
		for (int j{}; j < game_field_->columns_; j++) {
			game_field_->insert(game_field_->default_fill_character_, i, j);
		}
	}
}

std::shared_ptr<GameField> GameFieldBuilder::getGameField()
{
	return game_field_ ? game_field_ : nullptr; // checking if game field was created and returning pointer to it
}
