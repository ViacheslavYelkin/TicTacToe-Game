#include <memory>

#include "Cursor.h"

Cursor::Cursor(std::shared_ptr<GameField> game_field, std::shared_ptr<Point> current_location)
	: game_field_{game_field}, location_ {std::move(current_location)}, sign_{ '_' }
{
	replaced_sign_ = game_field_->at(location_->x_,location_->y_); // memorizing replaced character for further substitution while moving cursor
	game_field_->insert(sign_, location_->x_, location_->y_); // placing cursor at given location
}

void Cursor::moveCursor(EDirection direction)
{
	game_field_->insert(replaced_sign_, location_->x_, location_->y_); // placing memorized character in its place

	// moving cursor depending on given direction, if location out of bounds, cycling and return to begin/end of row/column 
	switch (direction) { 
	case EDirection::UP:
		if (!game_field_->isInBounds(location_->x_ - 1, location_->y_)) {
			location_->x_ = game_field_->rows_ - 1;
			break;
		}
		location_->x_ -= 1;
		break;
	case EDirection::DOWN:
		if (!game_field_->isInBounds(location_->x_ + 1, location_->y_)) {
			location_->x_ = 0;
			break;
		}
		location_->x_ += 1;
		break;
	case EDirection::LEFT:
		if (!game_field_->isInBounds(location_->x_, location_->y_ - 1)) {
			location_->y_ = game_field_->columns_ - 1;
			break;
		}
		location_->y_ -= 1;
		break;
	case EDirection::RIGHT:
		if (!game_field_->isInBounds(location_->x_, location_->y_ + 1)) {
			location_->y_ = 0;
			break;
		}
		location_->y_ += 1;
		break;
	}

	replaced_sign_ = game_field_->at(location_->x_, location_->y_); // memorizing replaced character for further substitution while moving cursor
	game_field_->insert(sign_, location_->x_, location_->y_); // placing cursor at new location
}

void Cursor::updateCursor()
{
	replaced_sign_ = game_field_->at(location_->x_, location_->y_); // updating replaced_sign_ on game field change
}

std::shared_ptr<Point> Cursor::getLocation() const
{
	return location_; // returning current location of cursor
}
