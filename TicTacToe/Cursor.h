#pragma once


#include "GameField.h"
#include "Point.h"
#include "EDirection.h"

class Cursor {
public:
	Cursor(std::shared_ptr<GameField> game_field, std::shared_ptr<Point> current_location);

	void moveCursor(EDirection direction);
	void updateCursor();
	std::shared_ptr<Point> getLocation() const;

public:
	char replaced_sign_;

private:
	std::shared_ptr<GameField> game_field_;
	std::shared_ptr<Point> location_;
	char sign_;
};