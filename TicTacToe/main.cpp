#include <conio.h>

#include "TicTacToe.h"

int main(int argc, char** argv) {

	bool repeat_game{ true };
	while (repeat_game) {
		TicTacToe* game = new TicTacToe();
		game->run();

		std::cout << "Do you wish to try one more time? y/n\n";
		char answer;
		answer = _getch();

		if (answer == 'n')
		{
			repeat_game = false;
		}
		else if (answer == 'y') {
			continue;
		}

		delete game;
	}

	return EXIT_SUCCESS;
}
