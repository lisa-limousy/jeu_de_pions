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
	
	creerUnite(SERF, &unite);
	placerAuMonde(unite, &monde, 1, 1, ROUGE);
	creerUnite(GUERRIER, &unite);
	placerAuMonde(unite, &monde, 1, 2, BLEU);
	creerUnite(GUERRIER, &unite);
	placerAuMonde(unite, &monde, 1, 3, BLEU);
	creerUnite(SERF, &unite);
	placerAuMonde(unite, &monde, 1, 4, BLEU);
	creerUnite(SERF, &unite);
	placerAuMonde(unite, &monde, 1, 5, ROUGE);
	creerUnite(SERF, &unite);
	placerAuMonde(unite, &monde, 1, 6, ROUGE);
	
	afficherPlateau(monde);
	
	//deplacerUnite((monde.bleu)->suiv, &monde, 2, 4);
	
	//fonctionne qu'avec le premier élément créé
	enleverUnite((monde.rouge)->suiv->suiv, &monde);
	
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
