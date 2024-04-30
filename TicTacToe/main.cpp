#include <conio.h>

#include "TicTacToe.h"

int main(int argc, char** argv) {

	bool repeat_game{ true };
	while (repeat_game) {
		TicTacToe* game = new TicTacToe();
		game->run();

	repeat_question:
		std::cout << "Do you wish to try one more time? y/n\n";
		char answer;
		answer = _getch();

		switch (answer) {
			case 'y':
				continue;
				break;
			case 'n':
				repeat_game = false;
				break;
			default:
				goto repeat_question;
				break;
		}

		delete game;
	}

	return EXIT_SUCCESS;
}
