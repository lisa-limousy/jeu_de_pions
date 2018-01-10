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
		}
		else {
			printf("Erreur, retentez avec une valeur valide");
		}	
	}
}

//LONG y colonnes
//LARG x lignes