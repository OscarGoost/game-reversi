#include <stdio.h>
#include <stdlib.h>
#define DIM 8
typedef enum {start=1, load, help, close} menuOptions;

int menu();

int main(){

	menu();

    return EXIT_SUCCESS;
}

int menu(){
    int option = 0;

    system("clear");
    printf("Welcome to REVERSI!\n\n");

	while(option !=1 && option != 2){
		printf("What would you like to do?\n");
		printf("1. Start new game!\n");
		printf("2. Load game.(not available)\n");
		printf("3. How to play.\n");
		printf("4. Close.\n");

		scanf ("%i", &option);
		system ("clear");

		switch(option){
		    case start:
		        return 1;
			case load:
				return 1;
			case help:
				break;
			case close:
				printf ("Thanks for playing!\n\n");
				return 2;
			default:
				getchar();
				break;
		}
	}
}
