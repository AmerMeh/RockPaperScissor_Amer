/*
	* Rock Paper Scissor is one of the most common games played by everyone once in his childhood, where two persons
	* use their hands and chooses random objects between rock, paper, or scissor, and their choice decides the winner between them.
	* What if a single person can play this game? With a computer, just by using a single C application, we can design the game Rock
	* Paper Scissor application just using basic C knowledge like if-else statements, random value generation, and input-output of values.
	* Created application has a feature where we can play the game, and maintain the score of Person 1 and Person 2.
*/

/*
* Amer Mehinbasic
* Rock Paper Scissor
* 18.08.2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function prototypes
void clearInputBuffer();
int isValidInput(char playAgain);
int isValidMove(char player, char moves[], int size);
char playMove();
char pcMove();
const char* checkWinner(char player, char move);
int updateScore(const char* result, int* yourWins, int* pcWins);



int main() {
	char player;
	char moves[6] = { 'R', 'P', 'S', 'r', 'p', 's' };
	char pc;
	srand((unsigned int)time(NULL));
	int playerWins = 0;
	int computerWins = 0;
	char playAgain;
	int gamemode[3] = { 1, 2, 3 };

	do {

	} while (1)


	do {
		pc = pcMove();

		do {
			player = playMove();

			if (isValidMove(player, moves, 6)) {
				printf("Valid move!\n");
				break;
			}
			else {
				printf("Invalid move! Please try again.\n");
				clearInputBuffer();
			}
		} while (1);

		const char* result = checkWinner(player, pc);
		updateScore(result, &playerWins, &computerWins);

		printf("Computer move: %c\n", pc);
		printf("%s\n", result);
		printf("Score is: %d for you, and %d for PC!\n", playerWins, computerWins);

		do {
			printf("Do you want to play again? (Y/N): ");
			scanf_s(" %c", &playAgain, 1);
			clearInputBuffer();

			if (isValidInput(playAgain)) {
				break;
			}
			else {
				printf("Invalid input! Please enter 'Y' or 'N'.\n");
			}
		} while (1);

	} while (playAgain == 'Y' || playAgain == 'y');

	printf("Thank you for playing! Amer :)");

	return 0;
}


// Function definitions
void clearInputBuffer() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

int isValidInput(char playAgain) {
	if (playAgain != 'Y' && playAgain != 'N' && playAgain != 'y' && playAgain != 'n') {
		return 0;  
	}
	else {
		return 1;  
	}
}


int isValidMove(char player, char moves[], int size) {
	for (int i = 0; i < size; i++) {
		if (player == moves[i]) {
			return 1;
		}
	}
	return 0;
}

char playMove() {
	char player;
	printf("Please enter your choice, either 'R'(rock) - 'P'(paper) - 'S'(scissors): \n");
	scanf_s(" %c", &player, 1);
	return player;
}

char pcMove() {
	char pc;
	int r = rand() % 3;

	switch (r) {
	case 0: pc = 'R'; break;
	case 1: pc = 'P'; break;
	case 2: pc = 'S'; break;
	}

	return pc;
}
const char* checkWinner(char player, char move) {
	static char result[20];  // Static buffer to hold the result

	// Handling both uppercase and lowercase moves
	if ((player == 'R' || player == 'r') && (move == 'S' || move == 's')) {
		strcpy_s(result, sizeof(result), "You won!");
	}
	else if ((player == 'P' || player == 'p') && (move == 'R' || move == 'r')) {
		strcpy_s(result, sizeof(result), "You won!");
	}
	else if ((player == 'S' || player == 's') && (move == 'P' || move == 'p')) {
		strcpy_s(result, sizeof(result), "You won!");
	}
	else if ((player == 'R' || player == 'r') && (move == 'R' || move == 'r')) {
		strcpy_s(result, sizeof(result), "Draw!");
	}
	else if ((player == 'P' || player == 'p') && (move == 'P' || move == 'p')) {
		strcpy_s(result, sizeof(result), "Draw!");
	}
	else if ((player == 'S' || player == 's') && (move == 'S' || move == 's')) {
		strcpy_s(result, sizeof(result), "Draw!");
	}
	else {
		strcpy_s(result, sizeof(result), "You lost!");
	}

	return result;
}

int updateScore(const char* result, int* yourWins, int* pcWins) {
	if (strcmp(result, "You won!") == 0) {
		(*yourWins)++;
	}
	else if (strcmp(result, "You lost!") == 0) {
		(*pcWins)++;
	}
	return *yourWins, * pcWins;
}