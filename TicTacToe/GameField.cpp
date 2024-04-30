#include <memory>

#include "Point.h"
#include "GameField.h"

GameField::GameField(int length, int height)
	: rows_{ length }, columns_{ height }, default_fill_character_{'-'}
{
}

GameField::~GameField()
{
	// deleting all allocated memory for matrix
	for (int i{}; i < rows_; i++) {
		delete[] field_[i];
	}

	delete[] field_;
}

char GameField::at(int row, int column) const
{
	return field_[row][column]; // returning symbol at requested position
}

int GameField::insert(char element, int row, int column)
{
	// checking if given location in bound of matrix
	// if true replacing/inserting new character at given location
	// else returning -1
	if (isInBounds(row, column)) {
		field_[row][column] = element;
		return 0;
	}
	return -1;
}

int GameField::size() const
{
	return rows_ * columns_; // returning full size of matrix
}


bool GameField::isInBounds(int row, int column) const
{
	// checking if given values are in bounds of current matrix
	return (
		(row >= 0 && row < rows_) &&
		(column >= 0 && column < columns_)
		);
}

bool GameField::isNeighbor(const std::shared_ptr<Point> left, const std::shared_ptr<Point> right) const 
{
	// checking if two points are neighbors to each other 
	return (
		(right->x_ - left->x_ < 2) &&
		(right->y_ - left->y_ < 2)
		);
}

void GameField::initializeField()
{
	field_ = new char* [rows_]; // initializing rows of matrix
	
	// initializing columns of matrix
	for (int i{}; i < rows_; i++) {
		field_[i] = new char[columns_];
	}
}
