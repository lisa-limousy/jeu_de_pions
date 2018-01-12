#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "init.h"

//mettre la valeur de tous ses pointeurs et des cases du plateau à NULL
void initializerMonde(Monde *monde){
	int y, x;
    for(y=0 ; y<LONG ; y++) {
        for(x=0 ; x<LARG ; ++x) {
            monde->plateau[y][x] = NULL;
        }
    }
    monde->tour = 0;
	monde->bleu = NULL;
    monde->rouge = NULL;
}

int creerUnite(char type, UListe *unite) {   
	
	Unite *u = malloc(sizeof(Unite));
	
	if (u == NULL){
		return 0;
	}
	
	else {
		u->genre = type;
		//le dernier élément de la liste pointe sur notre élément
		u->suiv = *unite;
		// on place u dans la mémoire alloué
		*unite = u;
		return 1;
	}
}



int placerAuMonde(Unite *unite, Monde *monde, int posX, int posY, char couleur){
	
	/*Si la case est libre*/
	if(monde->plateau[posX][posY] == NULL) {
		monde->plateau[posX][posY] = unite;
		unite->couleur = couleur;
		unite->posX = posX;
		unite->posY = posY;
		
		if(couleur == BLEU) {
			unite->suiv = monde->bleu;
			monde->bleu = unite;
		}
		else if(couleur == ROUGE) {
			unite->suiv = monde->rouge;
			monde->rouge = unite;
		}
		return 1;
	}
	
	/* Si la case n'est pas vide */
	else {
		return 0;
	}
}

void ligne(){
	int i;
    for(i=0; i<LARG; i++) {
        printf("+----");
    }
    printf("+\n");
}

void afficherPlateau(Monde monde){
	printf("\n");
    printf("   0    1    2    3    4    5    6    7    8    9   10   11   12   13   14   15   16   17\n");
	int x, y;
	//colonnes
	for (y = 0; y < LONG; y++){
		ligne();
		//lignes
        for (x = 0; x < LARG; x++){
            const Unite* u = monde.plateau[y][x];
            if(u) {
                printf("| %c%c ", u->couleur, u->genre);
            } else {
                printf("|    "); // u est NULL (case vide)
            }
        }
        printf("| %d \n", y);
	}
	ligne();
	printf("\n");
}