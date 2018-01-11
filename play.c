#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "init.h"
#include "play.h"

void deplacerUnite(Unite *unite, Monde *monde, int destX, int destY){
	
	//si la valeur est déjà occupé, reste à sa place
	
	
	if((unite->posX == destX || unite->posX == destX+1 || unite->posX == destX-1) && (unite->posY == destY || unite->posY == destY+1 || unite->posY == destY-1)){
		if(destY < LARG && destX >= 0 && destY >= 0 && destX < LONG){
			if(monde->plateau[destX][destY] == NULL) {
			monde->plateau[unite->posX][unite->posY] = NULL;
			monde->plateau[destX][destY] = unite;
			unite->posX = destX;
			unite->posY = destY;
			
			}
		}
		else {
			printf("Erreur, retentez avec une valeur valide");
		}	
	}
}

// fonctionne qu'avec le premier élément créé dans le main
// ne supprime pas l'unité dans la liste 

void enleverUnite(Unite *unite, Monde *monde){
	monde->plateau[unite->posY][unite->posX] = NULL;
	free(unite);
}

// à tester dès que les problèmes sont reglé avec enleverUnite

int attaquer(Unite *unite, Monde *monde, int destX, int destY){
	if(unite->genre == GUERRIER && monde->plateau[destY][destX]->genre == SERF){
		enleverUnite(unite, monde);
		return 1;
	}

	if(unite->genre == GUERRIER && monde->plateau[destY][destX]->genre == GUERRIER){
		enleverUnite(unite, monde);
		return 1;
	}

	if(unite->genre == SERF && monde->plateau[destY][destX]->genre == SERF){
		enleverUnite(unite, monde);
		return 1;
	}

	if(unite->genre == SERF && monde->plateau[destY][destX]->genre == GUERRIER){
		enleverUnite(unite, monde);
		return 0;
	}
	return 0;
}

/*int deplacerOuAttaquer(Unite *unite, Monde *monde, int destX, int destY){
	if(destY > 17 || destY <0 || destX > 11 || destX <0){
		return -1;
	}
	if( (unite->posX) < destX -1 || (unite->posX) > destX +1 || (unite->posY) < destY -1 || (unite->posY) > destY +1 ){
		return -2;
	}
	if(monde->plateau[destY][destX] != NULL && monde->plateau[destY][destX]->couleur == unite->couleur){
		return -3;
	}
	if(){
		deplacerUnite(unite , monde, destX, destY);
		return 1;
	}
	if(){
		attaquer(unite , monde, destX, destY);
		if(attaquer(unite , monde, destX, destY) == 1){
			return 2;
		}
		else {
			return 3;
		}
	}
	return 0;
}*/

//LONG y colonnes
//LARG x lignes