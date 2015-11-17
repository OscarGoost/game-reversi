#include <stdio.h>
#include <stdlib.h>
#define DIM 8
typedef enum {start=1, load, help, close} menuOptions;

int menu();         /* Devuelve 1 para empezar a jugar y 2 para finalizar */
int checkMove(char position[4]);    /* Devuelve 0 si es valido y 1 si no */

int main(){
    int option; /* 1 para empezar a jugar y 2 para finalizar directamente */
    int turn = 0;   /* turno de los jugadores */
    int playing = 1;    /* 1 para el estado "jugando" y 0 para finalizar */
    int error= 0;   /* 1 si hay error y 0 si no lo hay */
    int check;
    char position[4];

    option = menu();

    if (option==1){ /* turno jugador 1 */
        /* pinta el tablero */
        printf ("Choose the position: <number><letter>\n\n");

        for(turn=0 ; playing ; turn++){
            if (turn%2 == 0){
                printf("Player 1: ");
                scanf("%s", position);
                getchar();

                do{
                    check = checkMove(position);
                    if(check == 1){
                        printf("\nThanks for playing!\n\n");
                        return EXIT_SUCCESS;
                    }

                    else if(!check){
                        /*pinta el tablero */
                        error = 0;
                    }

                    else{
                        /* pinta el tablero */
                        printf("Invalid position, try again.\n\n");
                        error = 1;
                    }
                }while(error);
            }

            else{   /* turno jugador 2 */
                printf("Player 2: ");
                scanf("%s", position);
                getchar();
                /* pinta el tablero */
            }
        }
    }

    /* esto se ejecuta siempre */
    printf("Thanks for playing!\n\n");
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
    	printf("4. Close.\n\n");

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
    	        return 2;
    	    default:
    	        getchar();
    	        break;
    	}
    }
}

int checkMove(char position[4]){
    char word[4] = "exit";

    if(strcmp(position, word)==0)
        return 1;

    return 0;
}
