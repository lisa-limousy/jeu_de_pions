#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "init.h"

//mettre la valeur de tous ses pointeurs et des cases du plateau à NULL
void initializerMonde(Monde *monde){
    monde->tour = 0;
    monde->plateau[LONG][LARG] = NULL;
    //plateau[LONG][LARG] = {0};
    monde->rouge = NULL;
    monde->bleu = NULL;

}

//type GUERRIER ou SERF
int creerUnite(char type, UListe *unite){

}

int afficherPlateau(Monde monde){

    //Afficher les cases du monde
    int i, j, n, a;
	int g=0;
	printf("   1    2    3    4    5    6    7    8    9   10   11   12\n");
    for (i = 0; i < LARG; i++){
        //int i, j;
		g++;
    	for(n=0; n< LONG; n++){
        	printf("+----");
    	}
    	printf("+\n");
        for (j = 1; j <= LONG; j++){
            printf("|  %c ", monde.plateau[LONG][LARG]);
        }
       	printf("| %d \n", g);
	}
    for(a=0; a< LONG; a++){
        printf("+----");
    }
    printf("+\n");
}