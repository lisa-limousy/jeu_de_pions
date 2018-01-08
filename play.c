#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "init.h"
#include "play.h"

void deplacerUnite(Unite *unite, Monde *monde, int destX, int destY){
	if((unite->posX == destX || unite->posX == destX+1 || unite->posX == destX-1) && (unite->posY == destY || unite->posY == destY+1 || unite->posY == destY-1)){
		if((posY == 17 && destY > 17) || (posY == 0 && destY <0) || (posX == 11 && destX > 11) || (posX == 0 && destX <0)){
			unite->posX = destX;
			unite->posY = destY;	
			//monde->(unite->couleur)
		}
	}
	else{
		printf("Erreur, retentez avec une valeur valide");
	}	
}

//LONG y colonnes
//LARG x lignes