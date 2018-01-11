#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "init.h"
#include "play.h"

int main(){
	
	Monde monde;
	UListe unite = NULL;
	
    initializerMonde(&monde);
	
	//création de tous les pions - 2 GUERRIER et 4 SERF
	
	creerUnite(GUERRIER, &unite);
	placerAuMonde(unite, &monde, 2, 5, ROUGE);
	//(monde.rouge)->suiv->suiv
	creerUnite(SERF, &unite);
	placerAuMonde(unite, &monde, 1, 2, ROUGE);
	//(monde.rouge)->suiv
	creerUnite(GUERRIER, &unite);
	placerAuMonde(unite, &monde, 1, 3, ROUGE);
	//(monde.rouge)
	creerUnite(GUERRIER, &unite);
	placerAuMonde(unite, &monde, 1, 4, BLEU);
	//(monde.bleu)->suiv->suiv
	creerUnite(SERF, &unite);
	placerAuMonde(unite, &monde, 1, 5, BLEU);
	//(monde.bleu)->suiv
	creerUnite(SERF, &unite);
	placerAuMonde(unite, &monde, 1, 6, BLEU);
	//(monde.bleu)
	
	afficherPlateau(monde);
	
	//deplacerUnite((monde.rouge)->suiv->suiv, &monde, 2, 1);
	//enleverUnite((monde.rouge)->suiv, &monde);
	
	attaquer((monde.rouge)->suiv->suiv, &monde, 1, 4);
	afficherPlateau(monde);

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
	printf("\n");
	
    return 0;
}
