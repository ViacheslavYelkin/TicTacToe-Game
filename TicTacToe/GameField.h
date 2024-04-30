#pragma once

struct Point;

class GameField {
	friend class TicTacToe;
	friend class GameFieldRenderer;
	friend class GameFieldBuilder;
	friend class Cursor;

public:

	GameField(int length, int height);
	~GameField();

	char at(int row, int column) const;
	int insert(char element, int row, int column);
	int size() const;

private:
	void initializeField();
	bool isInBounds(int row, int column) const;
	bool isNeighbor(const std::shared_ptr<Point> left, const std::shared_ptr<Point> right) const;

private:
	int rows_;
	int columns_;
	char** field_;
	char default_fill_character_;
};