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
    int i, j;
    for (i = 0; i < LARG; i++){
        int i, j;
    for(i=0; i< LARG; i++){
        printf("+---");
    }
    printf("+\n");
        for (j = 0; j < LONG; j++){
            printf("| %c ", monde.plateau[LONG][LARG]);
        }
        printf("|\n");
	}
    for(i=0; i< LONG; i++){
        printf("+---");
    }
    printf("+\n");
}