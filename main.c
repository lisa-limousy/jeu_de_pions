#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "init.h"

int main(void){
   
	//UListe *toutesU = NULL;
	
	Monde monde;
	UListe unite = NULL;
	
    initializerMonde(&monde);
	
	//création de tous les pions - 2 GUERRIER et 4 SERF
	
	creerUnite(SERF, &unite);
	placerAuMonde(unite, &monde, 7, 1, BLEU);
	//affiche TOUTES les unités
	creerUnite(SERF, &unite);
	placerAuMonde(unite, &monde, 4, 6, BLEU);
	creerUnite(SERF, &unite);
	placerAuMonde(unite, &monde, 8, 4, ROUGE);
	creerUnite(SERF, &unite);
	placerAuMonde(unite, &monde, 8, 7, ROUGE);
	creerUnite(GUERRIER, &unite);
	placerAuMonde(unite, &monde, 1, 2, BLEU);
	creerUnite(GUERRIER, &unite);
	placerAuMonde(unite, &monde, 2, 2, ROUGE);
	
	//deplacerUnite(unite, monde, 7, 7);
	afficherPlateau(monde);
	
	printf("TOUTES unites : ");
	while(unite!=NULL){
		printf("%c ", unite->genre);
		unite = unite->suiv;
	}
	printf("\n");
	//affiche liste unités rouge
	printf("Unites ROUGE : ");
	while(monde.rouge!=NULL){
		printf("%c ", monde.rouge->genre);
		monde.rouge = monde.rouge->suiv;
	}
	printf("\n");
	
	printf("Unites BLEU : ");
	while(monde.bleu!=NULL){
		printf("%c ", monde.bleu->genre);
		monde.bleu = monde.bleu->suiv;
	}
	
    return 0;
}
