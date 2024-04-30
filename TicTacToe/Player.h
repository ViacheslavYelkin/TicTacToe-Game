#pragma once


class Player {
public:

	Player() = default;
	Player(char game_side);

	char getSide() const;

public:
	int amount_of_taken_cells_{};

private:
	char game_side_;
};