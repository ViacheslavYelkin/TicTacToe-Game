#include <conio.h>

#include "TicTacToe.h"

int main(int argc, char** argv) {

	TicTacToe game = TicTacToe();
	game.run();

	_getch();
	return EXIT_SUCCESS;
}
