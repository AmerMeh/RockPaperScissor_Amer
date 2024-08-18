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
#include <time.h>


void clearInputBuffer() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
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

	printf("Please enter your choice, either 'R'(rock) - 'P'(paper) - 'S'(scissor): \n");
	scanf_s("%c", &player);

	return player;
}

char pcMove() {
	char pc;
	int r;

	r = rand() % 100;

	if (r <= 33) {
		pc = 'R';
	}
	else if (r >= 34 && r <= 66) {
		pc = 'P';
	}
	else if (r >= 67 && r <= 100) {
		pc = 'S';
	}

	return pc;
}


int main() {

	char player;
	char moves[3] = { 'R', 'P', 'S' };
	char pc;
	srand(time(NULL));

	char move = pcMove();

	do {
		player = playMove();

		if (isValidMove(player, moves, 3)) {
			printf("Valid move!\n");
			
			break;  
		}
		else {
			printf("Invalid move! Please try again.\n");
			clearInputBuffer();  
		}

	} while (1);

	printf("Computer move: %c\n", move);

	return 0;
}