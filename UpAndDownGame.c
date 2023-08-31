#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <time.h>

//Jogo do mais ou menos

void menu();
void niveis(int x);
void tentativas(int y);
void misterio(int w);
int sorteio();
void preparacao();
void jogo();
const int MIN = 1;
int max = 100, modoJogo = 0, nivel = 1, numVezes = 10, numMist = 0;

int main() {
	setlocale(LC_ALL, "");
	int opcao = 0;
	do {
		system("cls");
		menu();
		printf("\n\nEnter your option: ");
		while (scanf("%d", &opcao) != 1) {//Input validation
			printf("Invalid input!");//Input validation
			while (getchar() != '\n');//Input validation
		}
		switch (opcao) {
		case 1:
			jogo();
			break;
		case 2:
			preparacao();
			break;
		case 0:
			printf("\nGame over!\nGoodbye!\n");
			break;
		default:
			printf("\nInvalid input!");
			printf("\nPress enter to continue...");
			while(getchar()!='\n');//Alternative to getch() - not recognized on OnlineGDB. The duplicated line allow to wait for an enter
			while(getchar()!='\n');//Alternative to getch() - not recognized on OnlineGDB. The duplicated line allow to wait for an enter
		}
	} while (opcao != 0);


	return(0);
}

void menu() {
	printf("\n********* UP AND DOWN GAME **************");
	printf("\n1 - Play");
	printf("\n2 - Settings");
	printf("\n0 - Exit");
}

void niveis(int x) {	
	if (x == 1) nivel = (sorteio() % 3)+1;
	if (x == 2 || x == 3) {
		printf("\nLEVEL\n1 - Mystery number between 1 and 100\n2 - Mystery number between 1 and 1000\n3 - Mystery number between 1 and 10000\nSelect the level (1, 2 or 3) in which you pretend to play: ");
		while (scanf("%d", &nivel) != 1 || nivel < 1 || nivel > 3) {//Input validation
			printf("\nInvalid input! Select the level (1, 2, ou 3): ");//Input validation
			while (getchar() != '\n');//Input validation
		}
	}
	switch (nivel) {
	case 1:
		printf("\nSelected level 1 (1 to 100)\n");		
		max = 100;
		break;
	case 2:
		printf("\nSelected level 2 (1 to 1000)\n");
		max = 1000;
		break;
	case 3:
		printf("\nSelected level 3 (1 to 10000)\n");
		max = 10000;
		break;
	default:
		printf("\nInvalid input!");
	}	
	
}
void tentativas(int y) {
	int opcaoTent = 0;
	if (y == 1) opcaoTent = (sorteio() % 9)+1;
	if (y == 2 || y == 3) {
		printf("\nATTEMPTS\n1 - Number of attempts: 10\n2 - Number of attempts: 15\n3 - Number of attempts: 20\nSelect 1, 2 or 3 for the desired number of attempts: ");
		while (scanf("%d", &opcaoTent) != 1 || opcaoTent < 1 || opcaoTent > 3) {//Input validation
			printf("\nInvalid input! Select 1, 2 or 3 for the desired number of attempts: ");//Input validation
			while (getchar() != '\n');//Input validation
		}
	}
	switch (opcaoTent) {
	case 1:
	case 6:
	case 8:
		numVezes = 10;
		printf("\nSelected %d attempts.\n", numVezes);
		break;
	case 2:
	case 4:
	case 9:
		numVezes = 15;
		printf("\nSelected %d attempts.\n", numVezes);
		break;
	case 3:
	case 5:
	case 7:
		numVezes = 20;
		printf("\nSelected %d attempts.\n", numVezes);
		break;
	default:
		printf("\nInvalid input!");
	}
	if (y == 2) {
		printf("Press enter to continue");
		while (getchar() != '\n');
		while (getchar() != '\n');
	}
}
void misterio(int w) {	
	if (w == 0 || w == 1 || w == 2) {
		numMist = (sorteio() % (max - MIN + 1)) + MIN;		
	}
	if (w == 3) {
		printf("\nSELECTION OF MYSTERY NUMBER\nSelect a number between 1 e %d: ", max);
		while (scanf("%d", &numMist) != 1 || numMist < 1 || numMist > max) {//Input validation
			printf("\nInvalid input! Select a number between 1 e %d: ", max);//Input validation
			while (getchar() != '\n');//Input validation
		}		
		printf("\nMystery number selected: %d\nPress enter to continue", numMist);
		while (getchar() != '\n');//Alternative to getch() - not recognized on OnlineGDB. The duplicated line allow to wait for an enter
		while (getchar() != '\n');//Alternative to getch() - not recognized on OnlineGDB. The duplicated line allow to wait for an enter
	}	
}
int sorteio() {
	srand(time(NULL));
	int z = rand();
	return z;

}
void preparacao() {
	printf("\n********* UP AND DOWN GAME **************\n");
	printf("\nSETTINGS\n1 - All settings random (press 1)\n2 - Levels and attempts by manual choice and mystery number random (press 2)\n3 - All settings by manual choice (press 3)\nInput your option: ");
	while (scanf("%d", &modoJogo) != 1 || modoJogo < 1 || modoJogo > 3) {//Input validation
		printf("\nInvalid input! Enter one of the possible options (1, 2 or 3): ");//Input validation
		while (getchar() != '\n');//Input validation
	}
	niveis(modoJogo);
	tentativas(modoJogo);
	misterio(modoJogo);
	
}
void jogo() {
	int numJogado = 0, contador = 0;
	char jogarDeNovo;
	do {
		printf("\n********* UP AND DOWN GAME **************\n");
		printf("\nYou are playing on level %d (1 to %d)", nivel, max);
		printf(" and you have a maximum of %d attempts.\n", numVezes);
		if (numMist == 0) misterio(modoJogo);		
		for (int i = 0; i < numVezes; i++) {
			printf("\nAttempt number %d", i + 1);
			if (i == numVezes - 1) printf("\nLast attempt!");
			printf("\nGuess the mystery number - input here: ");
			while (scanf("%d", &numJogado) != 1 || numJogado < 1 || numJogado > max) {//Input validation
				printf("\nInvalid input! Input a whole number between 1 and %d: ", max);//Input validation
				while (getchar() != '\n');//Input validation
			}
			if (numJogado > numMist) printf("The mystery number is lower.");
			else if (numJogado < numMist) printf("The mystery number is higher.");
			else if (numJogado == numMist) {
				printf("\nCongratulations! The mystery number is %d. You took %d attempt(s) to guess it.", numMist, i + 1);
				break;
			}
			if (i < numVezes - 1) printf("\nYou still have %d attempt(s).\n", numVezes - (i + 1));
			else printf("\nYou ran out of attempts. You lost!\n");
		}
		printf("\nDo you want to play again (s), quit game (q) or return to main menu (m)? ");
		scanf(" %c", &jogarDeNovo);
		while (jogarDeNovo != 's' && jogarDeNovo != 'S' && jogarDeNovo != 'm' && jogarDeNovo != 'M' && jogarDeNovo != 'q' && jogarDeNovo != 'Q'){//Input validation
			printf("\nInvalid input! Select s, q or m: ");//Input validation
			scanf(" %c", &jogarDeNovo);//Input validation
		}		
		switch (jogarDeNovo) {
		case 's':
		case 'S':
			misterio(0);
			system("cls");			
			break;
		case 'q':
		case 'Q':
			printf("\nThe game is over!\nGoodbye!");
			Sleep(2000);
			exit(0);
			break;
		case 'm':
		case 'M':
			menu();
			break;
		default:
			printf("\nInvalid input!");
		}
	} while (jogarDeNovo == 's' || jogarDeNovo == 'S');
	
}