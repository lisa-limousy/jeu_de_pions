#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "init.h"

int main(void){
   
	//UListe *toutesU = NULL;
	
	Monde monde;
	UListe liste = NULL;
	
    initializerMonde(&monde);
	
	//création de tous les pions - 2 GUERRIER et 4 SERF
	
	creerUnite(SERF, &liste);
	placerAuMonde(liste, &monde, 8, 7, BLEU);
	creerUnite(SERF, &liste);
	placerAuMonde(liste, &monde, 1, 1, ROUGE);
	creerUnite(GUERRIER, &liste);
	placerAuMonde(liste, &monde, 2, 1, ROUGE);
	
	//boucle pour tester le chainage qui fonctionne à l'envers
	/*while(liste!=NULL){
        printf("%c", liste->genre);
        liste = liste->suiv;
    }*/
	
	//x = 8 et y = 7
	//printf("%d", unite->genre);
	afficherPlateau(monde);
	
<<<<<<< HEAD
	/*Unite* cur;
	while(cur!=NULL){
		printf("ok");
		cur = cur->suiv;
	}*/
	
	/*for(cur=liste ; cur!=NULL ; cur = cur->suiv) {
		printf("%c ", cur->genre);
		printf("ok ");
	}*/
	
=======
>>>>>>> 2e08efea4bda87c4a5346775498c1842357c82e2
    // Marchera pas : ça dépasse des bords du tableau
    // Par contre, LONG-1 et LARG-1 c'est OK :)
	// printf("%d\n", monde.plateau[LONG][LARG]);

<<<<<<< HEAD
	//printf("%c", unite.genre);
	
	//2 guerrier et 4 serfs 
=======
	printf("%c", unite.couleur);
>>>>>>> 2e08efea4bda87c4a5346775498c1842357c82e2
	
	//Placement d'une unité
	/*printf("Joueur Rouge, rentrez vos unités !\n");
	printf("Colonne (entre 1 et 12) de votre guerrier : ");
	scanf("%d", posX);
	printf("Ligne (entre 1 et 18) de votre guerrier : ");
	scanf("%d", posY);*/
	
    return 0;
}
