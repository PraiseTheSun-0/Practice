#include "Header.h"
#include <iostream>

Game initGame(char Userchar) {
	Game start;
	for (int i = 0; i < 3; i++)
		for (int k = 0; k < 3; k++) {
			start.board[i][k] = ' ';
		}
	start.isUserTurn = rand() % 2;
	start.userChar = Userchar;
	if (Userchar == 'X')start.botChar = '0';
	else start.botChar = 'X';
	start.status = PLAY;
	updateDisplay(start);
	return start;
}

void updateDisplay(const Game game) {
	system("CLS");
	std::cout << "    1   2   3\n  -------------\n";
	for (int i = 0; i < 3; i++) {
		std::cout << i + 1 << " | ";
		for (int k = 0; k < 3; k++) {
			std::cout << game.board[i][k] << " | ";
		}
		std::cout << "\n  -------------\n";
	}
}

void botTurn(Game* game){
	int maxCounter = 0;
	for (int i = 0; i < 3; i++) {
		for (int k = 0; k < 3; k++) {
			if (game->board[i][k] != ' ') maxCounter++;
		}
	}
	if (!maxCounter) {
		game->board[1][1] = game->botChar;
		return;
	}
	maxCounter = 0;
	for (int i = 0; i < 3; i++) {
		if (game->board[i][i] == game->userChar) maxCounter++;
		else if (game->board[i][i] == game->botChar) maxCounter--;
	}
	if (maxCounter == 2) {
		for (int l = 0; l < 3; l++) {
			if (game->board[l][l] == ' ') {
				game->board[l][l] = game->botChar;
				return;
			}
		}
	}
	maxCounter = 0;
	for (int i = 0; i < 3; i++) {
		if (game->board[i][2 - i] == game->userChar) maxCounter++;
		else if (game->board[i][2 - i] == game->botChar) maxCounter--;
	}
	if (maxCounter == 2) {
		for (int l = 0; l < 3; l++) {
			if (game->board[l][2 - l] == ' ') {
				game->board[l][2 - l] = game->botChar;
				return;
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		maxCounter = 0;
		for (int k = 0; k < 3; k++) {
			if (game->board[i][k] == game->userChar) maxCounter++;
			else if (game->board[i][k] == game->botChar) maxCounter--;
		}
		if (maxCounter == 2) {
			for (int l = 0; l < 3; l++) {
				if (game->board[i][l] == ' ') {
					game->board[i][l] = game->botChar;
					return;
				}
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		maxCounter = 0;
		for (int k = 0; k < 3; k++) {
			if (game->board[k][i] == game->userChar) maxCounter++;
			else if (game->board[k][i] == game->botChar) maxCounter--;
		}
		if (maxCounter == 2) {
			for (int l = 0; l < 3; l++) {
				if (game->board[l][i] == ' ') {
					game->board[l][i] = game->botChar;
					return;
				}
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		maxCounter = 0;
		for (int k = 0; k < 3; k++) {
			if (game->board[i][k] == game->userChar) maxCounter++;
			else if (game->board[i][k] == game->botChar) maxCounter--;
		}
		if (maxCounter == 1) {
			for (int l = 0; l < 3; l++) {
				if (game->board[i][l] == ' ') {
					game->board[i][l] = game->botChar;
					return;
				}
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		maxCounter = 0;
		for (int k = 0; k < 3; k++) {
			if (game->board[k][i] == game->userChar) maxCounter++;
			else if (game->board[k][i] == game->botChar) maxCounter--;
		}
		if (maxCounter == 1) {
			for (int l = 0; l < 3; l++) {
				if (game->board[l][i] == ' ') {
					game->board[l][i] = game->botChar;
					return;
				}
			}
		}
	}
	for(int i = 0; i < 3; i++)
		for (int k = 0; k < 3; k++) 
			if (game->board[i][k] == ' ') {
				game->board[i][k] = game->botChar;
				return;
			}
}

void userTurn(Game* game) {
	int a, b;
	std::cout << "��� ���: ";
	std::cin >> a >> b;
	while (a < 1 || a > 3 || b < 1 || b > 3 || game->board[a - 1][b - 1] != ' ') {
		std::cout << "�������� ����������" << std::endl;
		std::cout << "��� ���: ";
		std::cin >> a >> b;
	} 
	game->board[a - 1][b - 1] = game->userChar;
}

void whoWon(Game* game, int a) {
	if (a == 3)game->status = USER_WIN;
	else if (a == -3)game->status = BOT_WIN;
}

bool updateGame(Game* game) {
	int counter;
	for (int i = 0; i < 3; i++) {
		counter = 0;
		for (int k = 0; k < 3; k++) {
			if (game->board[i][k] == game->userChar) counter++;
			else if (game->board[i][k] == game->botChar) counter--;
		}
		whoWon(game, counter);
	}
	for (int i = 0; i < 3; i++) {
		counter = 0;
		for (int k = 0; k < 3; k++) {
			if (game->board[k][i] == game->userChar) counter++;
			else if (game->board[k][i] == game->botChar) counter--;
		}
		whoWon(game, counter);
	}
	counter = 0;
	for (int i = 0; i < 3; i++) {
		if (game->board[i][i] == game->userChar) counter++;
		else if (game->board[i][i] == game->botChar) counter--;
	}
	whoWon(game, counter);
	counter = 0;
	for (int i = 0; i < 3; i++) {
		if (game->board[i][2-i] == game->userChar) counter++;
		else if (game->board[i][2-i] == game->botChar) counter--;
	}
	whoWon(game, counter);
	if (game->status == PLAY) {
		counter = 0;
		for (int i = 0; i < 3; i++){
			for (int k = 0; k < 3; k++) {
				if (game->board[i][k] == ' ')counter++;
			}
		}
		if (!counter) {
			game->status = NOT_WIN;
			return true;
		}
		game->isUserTurn = !game->isUserTurn;
		return false;
	}
	return true;
}