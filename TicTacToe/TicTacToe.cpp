#include <iostream>
#include <vector>
#include <memory>
#include <conio.h>

#include "Point.h"
#include "EDirection.h"
#include "GameFieldBuilder.h"
#include "TicTacToe.h"

TicTacToe::TicTacToe()
	:Game{ 2 }
{
	std::unique_ptr<GameFieldBuilder> builder = std::make_unique<GameFieldBuilder>(); // creating builder to build game field
	builder->buildGameField(); // building game field
	game_field_ = builder->getGameField(); // requesting builded game field to initialize current game field

	renderer_ = std::make_unique<GameFieldRenderer>(game_field_); // initializing renderer and passing game field
	cursor_ = std::make_unique<Cursor>(game_field_, std::make_shared<Point>(0, 0)); // initializing cursor and passing matrix in which it will be located
}

void TicTacToe::start()
{
	bool is_input_correct{ false };

	// looping while user won't pass asked value
	while (!is_input_correct) {
		std::cout << "Welcome to 'Tic Tac Toe'. Please choose your side.\n1 - 'X' or 2 - 'O'\n";

		// getting value from user
		char choice;
		choice = _getch();

		// checking if given value satisfies statement
		switch (choice) {
		case '1':
			players_.push_back(std::make_unique<Player>('X'));
			players_.push_back(std::make_unique<Player>('O'));
			is_input_correct = true;
			break;
		case '2':
			players_.push_back(std::make_unique<Player>('O'));
			players_.push_back(std::make_unique<Player>('X'));
			is_input_correct = true;
			break;
		}
	}
}

bool TicTacToe::haveWinner()
{
	std::vector<std::shared_ptr<Point>> points;

	// getting all possible cells where sign same as user's sign
	for (int i{}; i < 3; i++) {
		for (int j{}; j < 3; j++) {
			if (game_field_->at(i,j) != players_[current_player_]->getSide()) {
				continue;
			}
			points.push_back(std::make_shared<Point>(i, j));
		}
	}

	// trying to suggest position of third sign in sequence to get winner
	// if sign found at suggested location, returning true, meaning that winner determined
	// else returning false
	for (int i{}; i < points.size(); i++) {
		for (int j{ i + 1 }; j < points.size(); j++) {
			if (game_field_->isNeighbor(points[i], points[j])) {
				int suggest_x = points[j]->x_ + (points[j]->x_ - points[i]->x_);
				int suggest_y = points[j]->y_ + (points[j]->y_ - points[i]->y_);
				if (game_field_->isInBounds(suggest_x, suggest_y) && game_field_->at(suggest_x,suggest_y) == players_[current_player_]->getSide()) {
					return true;
				}
			}
		}
	}

	return false;
}


bool TicTacToe::isDraw()
{
	// checking if users fill whole matrix with signs and no place left for playing
	return (players_[0]->amount_of_taken_cells_ + players_[1]->amount_of_taken_cells_) == game_field_->size();
}


void TicTacToe::takeTurn()
{
	bool cell_selected{ false }; // variable indicating if user select cell or not
	current_player_ = (current_player_ + 1) % number_of_players_; // determining whose turn now 

	// looping while user won't select cell to place its sign
	while (!cell_selected) {
		system("CLS"); // clearing console at each loop iteration
		std::cout << "Now turn of '" << players_[current_player_]->getSide() << "'\n";
		renderer_->printGameField(); // printing game field at current state
		char direction = readInput(); // reading user input

		// checking if user didn't press 'Enter'
		if (direction != '\r') { 
			moveCursor(direction); // moving cursor in given direction
			continue;
		}

		// checking if selected cell haven't been taken by current/another user
		// if not, placing current user's sign  at choosen location and giving turn to next one
		// else, going to begining of loop and repeating process
		if (cursor_->replaced_sign_ != players_[current_player_]->getSide() &&
			cursor_->replaced_sign_ != players_[(current_player_ + 1) % number_of_players_]->getSide()
			)
		{
			game_field_->insert(players_[current_player_]->getSide(), cursor_->getLocation()->x_, cursor_->getLocation()->y_);
			cursor_->updateCursor();
			players_[current_player_]->amount_of_taken_cells_++;
			cell_selected = true;
		}
	}
}

char TicTacToe::getWinner()
{
	// returning user's sign that collected winning sequence
	return players_[current_player_]->getSide();
}

char TicTacToe::readInput()
{
	// reading input from keyboard
	return _getch();
}

void TicTacToe::moveCursor(char direction)
{
	// passing given direction interpreted to needed type
	switch (direction) {
	case 'w':
		cursor_->moveCursor(EDirection::UP);
		break;
	case 's':
		cursor_->moveCursor(EDirection::DOWN);
		break;
	case 'a':
		cursor_->moveCursor(EDirection::LEFT);
		break;
	case 'd':
		cursor_->moveCursor(EDirection::RIGHT);
		break;
	}
}
