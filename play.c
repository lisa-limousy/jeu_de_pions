#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "init.h"
#include "play.h"

void deplacerUnite(Unite *unite, Monde *monde, int destX, int destY){

	if((unite->posX == destX || unite->posX == destX+1 || unite->posX == destX-1) && (unite->posY == destY || unite->posY == destY+1 || unite->posY == destY-1)){
		if(destY < LARG && destX >= 0 && destY >= 0 && destX < LONG){
			 if(monde->plateau[destX][destY] == NULL) {
                 monde->plateau[unite->posX][unite->posY] = NULL;
			     monde->plateau[destX][destY] = unite;
			     unite->posX = destX;
			     unite->posY = destY;
			
			}
            else {
                printf("La case est occupee\n");
            }
		}
		else {
			printf("Erreur, retentez avec une valeur valide");
		}	
	}
}

void enleverUnite(Unite *unite, Monde *monde){
	
	monde->plateau[unite->posX][unite->posY] = NULL;
	
	Unite *actuel, *precedent;
    precedent = NULL;
	
	if(unite->couleur == BLEU){
		actuel = monde->bleu;
    }
    else {
        actuel = monde->rouge;
    }
    
    while ( actuel != NULL ) {
        if ( actuel == unite ) {
            if ( actuel->suiv == NULL ) {
                precedent->suiv = NULL;
            } 
			else if(precedent != NULL){
                precedent->suiv = actuel->suiv;                    
            }
            //if precedent == NULL
            else {
                if(unite->couleur == BLEU){
                    monde->bleu = actuel->suiv;
                }
                else {
                    monde->rouge = actuel->suiv;
                }
			}
        }		
		precedent = actuel;
		actuel = actuel->suiv;
    }
}

int attaquer(Unite *unite, Monde *monde, int destX, int destY){

	Unite *adversaire = monde->plateau[destX][destY];
	
	if(unite->genre == GUERRIER && adversaire->genre == SERF){
		enleverUnite(adversaire, monde);
		return 1;
	}

	if(unite->genre == GUERRIER && adversaire->genre == GUERRIER){
		enleverUnite(adversaire, monde);
		return 1;
	}

	if(unite->genre == SERF && adversaire->genre == SERF){
		enleverUnite(adversaire, monde);
		return 1;
	}

	if(unite->genre == SERF && adversaire->genre == GUERRIER){
		enleverUnite(unite, monde);
		return 0;
	}
	return 0;
}
	
int deplacerOuAttaquer(Unite *unite, Monde *monde, int destX, int destY){
	//LONG 12 x lignes
	//LARG 18 y colonnes
    //Unite *adversaire = monde->plateau[destX][destY];
    
    //int resultAttaque;
    //resultAttaque = attaquer(unite, monde, destX, destY);
	
	if(destY > LARG-1 || destY < 0 || destX > LONG-1 || destX < 0){
		printf("\n");
        printf("Vous etes hors du plateau. \n");
        return -1;
	}
	if( (unite->posX) < destX -1 || (unite->posX) > destX +1 || (unite->posY) < destY -1 || (unite->posY) > destY +1 )	{
        printf("\n");
		printf("Vous ne pouvez avancer que d'une case. \n");
        return -2;
	}


	if(monde->plateau[destX][destY] != NULL && monde->plateau[destX][destY]->couleur == unite->couleur){
        printf("\n");
        printf("C'est un de vos pions ! \n");
		return -3;
	}

	if(monde->plateau[destX][destY] == NULL){
		deplacerUnite(unite, monde, destX, destY);
		return 1;
	}
    
	if(monde->plateau[destX][destY]->couleur != unite->couleur){
		if(attaquer(unite, monde, destX, destY) == 1){
			return 2;
		}
        else{
            return 3;
        }
	}
	return 0;
}