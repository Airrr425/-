#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int cash = 100;
void Play(int bet) {
	char C[3] = { 'J','Q','K' };
	printf("Shuffling...\n");
	srand(time(NULL));
	int i;
	for(i = 0; i < 5; i++) {
		int x = rand() % 3;
		int y = rand() % 3;
		int temp = C[x];
		C[x] = C[y];
		C[y] = temp;
	}
	int playersGuess;
	printf("What's the position of queen 1,2 or 3?");
	scanf_s("%d", &playersGuess);
	if (C[playersGuess - 1] == 'Q') {
		cash += 3 * bet;
		printf("You win!Result = %c%c%c Total cash = %d", C[0], C[1], C[2],cash);

	}
	else
	{
		cash -= bet;
		printf("you lose,result=%c%c%c total cash=%d", C[0], C[1], C[2],cash);

	}
}

int main() {
	int bet;
	printf("welcome");
	printf("total cash = $%d\n", cash);
	while (cash > 0)
	{
		printf("what's your bet?");
		scanf_s("%d", &bet);
		if (bet == 0 || bet > cash) break;
		Play(bet);
	}
}