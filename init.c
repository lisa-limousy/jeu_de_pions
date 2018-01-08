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
    monde->rouge = NULL;
    monde->bleu = NULL;
}
//remplacer liste par unite
void creerUnite(char type, UListe *unite) {   
	
	if(*unite == NULL){
    	Unite* u1 = malloc(sizeof(Unite)); 
		u1->genre = type; 
		u1->suiv=NULL;
    	*unite = u1;
	}
	else{
		Unite* u = malloc(sizeof(Unite)); 
		u->genre = type; 
		u->suiv = *unite;
		*unite = u;
	}
}

int placerAuMonde(Unite *unite, Monde *monde, int posX, int posY, char couleur){
	unite->posX = posX;
	unite->posY = posY;
	unite->couleur = couleur;
	//ajouter l'unite à son joueur dans la liste chainée correspondante
	if(couleur == ROUGE){
		if(monde->rouge == NULL){
			monde->rouge = unite;
			monde->rouge->suiv = NULL;
		}
		else{
			monde->rouge->suiv = unite;
			monde->rouge->suiv->suiv = NULL;
		}
	}
	if(couleur == BLEU){
		if(monde->bleu == NULL){
			monde->bleu = unite;
			monde->bleu->suiv = NULL;
		}
		else{
			monde->bleu->suiv = unite;
			monde->bleu->suiv->suiv = NULL;
		}
	}
	
	monde->plateau[posY][posX] = unite;
    return 1; // Elle doit renvoyer quoi cette fonction ?
}

void ligne(){
	int i;
    for(i=0; i<LARG; i++) {
        printf("+----");
    }
    printf("+\n");
}

void afficherPlateau(Monde monde){
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
}
