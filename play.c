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

void enleverUnite(Unite *unite, Monde *monde){
	
	monde->plateau[unite->posX][unite->posY] = NULL;
	
	Unite *actuel, *precedent;
	
	if(unite->couleur == BLEU){
		actuel = monde->bleu;
		precedent = NULL;
	
		while ( actuel != NULL ) {
			if ( actuel == unite ) {
				if ( actuel->suiv == NULL ) {
					precedent->suiv = NULL;
				} 
				else {
					precedent->suiv = actuel->suiv;
				}
			}		
			precedent = actuel;
			actuel = actuel->suiv;
		}
	}
	
	else {
		actuel = monde->rouge;
		precedent = NULL;
		
		while ( actuel != NULL ) {
			if ( actuel == unite ) {
				if ( actuel->suiv == NULL ) {
					precedent->suiv = NULL;
				} 
				else {
					precedent->suiv = actuel->suiv;
				}
			}		
			precedent = actuel;
			actuel = actuel->suiv;
		}
	}
}

// à tester dès que les problèmes sont reglé avec enleverUnite

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
	
	if(destY > LARG-1 || destY < 0 || destX > LONG-1 || destX < 0){
		return -1;
	}
	if( (unite->posX) < destX -1 || (unite->posX) > destX +1 || (unite->posY) < destY -1 || (unite->posY) > destY +1 )	{
		return -2;
	}
	if(monde->plateau[destY][destX] != NULL && monde->plateau[destY][destX]->couleur == unite->couleur){
		return -3;
	}
	if(monde->plateau[destY][destX] != NULL){
		deplacerUnite(unite, monde, destX, destY);
		return 1;
	}
	if(monde->plateau[destY][destX]->couleur != unite->couleur){
		attaquer(unite, monde, destX, destY);
		if(attaquer(unite, monde, destX, destY) == 1){
			return 2;
		}
		else {
			return 3;
		}
	}
	return 0;
}