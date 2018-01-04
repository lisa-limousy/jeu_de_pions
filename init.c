#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "init.h"

//mettre la valeur de tous ses pointeurs et des cases du plateau à NULL
void initializerMonde(Monde *monde){
    // Ou sinon, plus radical et en une seule ligne:
    // memset(monde, 0, sizeof(*monde));
    // Cette ligne pourrait remplacer tout le corps de cette fonction.

    for(int y=0 ; y<LONG ; ++y) {
        for(int x=0 ; x<LARG ; ++x) {
            monde->plateau[y][x] = NULL;
        }
    }
    monde->tour = 0;
    monde->rouge = NULL;
    monde->bleu = NULL;
}

//type = GUERRIER ou SERF
// int creerUnite(char type, UListe *unite){
    //(*unite)->genre = type; // GUERRIER ou SERF
    //unite = *(&unite);
	//printf("%c\n", (*unite)->genre);
//}


int placerAuMonde(Unite *unite, Monde *monde, int posX, int posY, char couleur){
	unite->posX = posX;
	unite->posY = posY;
	unite->couleur = couleur;
	
	monde->plateau[posY][posX] = unite;
    return 1; // Elle doit renvoyer quoi cette fonction ?
}

void ligne(){
	int i;
    for(i=0; i<LARG; i++) {
        printf("+---");
    }
    printf("+\n");
}

void afficherPlateau(Monde monde){
	printf("  1   2   3   4   5   6   7   8   9  10  11  12\n");
	for (int y = 0; y < LONG; y++){
		ligne();
        for (int x = 0; x < LARG; x++){
            const Unite* u = monde.plateau[y][x];
            if(u) {
                printf("| %c%c ", u->couleur, u->genre);
            } else {
                printf("| ** "); // u est NULL (case vide)
            }
        }
        printf("| %d \n", y+1);
	}
	ligne();
}

/*int afficherPlateau(Monde monde){
    int i, j, k, l;
	int g=0;
	printf("   1    2    3    4    5    6    7    8    9   10   11   12\n");
    for (i = 0; i < LARG; i++){
        //int i, j;
		g++;
    	for(j=0; j< LONG; j++){
        	printf("+----");
    	}
    	printf("+\n");
        for (k = 1; k <= LONG; k++){
            printf("|  %c ", monde.plateau[LONG][LARG]);
        }
       	printf("| %d \n", g);
	}
    for(l=0; l< LONG; l++){
        printf("+----");
    }
    printf("+\n");
}*/
