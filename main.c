#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "init.h"

int main(void){
   
	UListe *toutesU = NULL;
	
	Monde monde;
	Unite unite;
    initializerMonde(&monde);
	
	//création de tous les pions - 2 GUERRIER et 4 SERF
	//creerUnite(GUERRIER, toutesU);
	//creerUnite(SERF, toutesU);
	
	placerAuMonde(&unite, &monde, 8, 7, ROUGE);
	afficherPlateau(monde);
	
	printf("%d\n", monde.plateau[LONG][LARG]);
	printf("%c", unite.couleur);
	
	//Placement d'une unité
	/*printf("Joueur Rouge, rentrez vos unités !\n");
	printf("Colonne (entre 1 et 12) de votre guerrier : ");
	scanf("%d", posX);
	printf("Ligne (entre 1 et 18) de votre guerrier : ");
	scanf("%d", posY);*/
	
    return 0;
}
