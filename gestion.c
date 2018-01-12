#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "init.h"
#include "play.h"
#include "gestion.h"

void gererDemiTour(char joueur, Monde *monde){
    
    Unite *unite = NULL;
    int result, ligne, colonne, reponse;
    
    if(joueur == ROUGE){
        unite = monde->rouge;
    }
    else {
        unite = monde->bleu;
    }
    
    afficherPlateau(*monde);
    printf("Voici la liste de tes unites : \n");
    
    printf("1 - Type %c en (%d,%d)\n", unite->genre, unite->posX, unite->posY);
    printf("2 - Type %c en (%d,%d)\n", unite->suiv->genre, unite->suiv->posX, unite->suiv->posY);
    printf("3 - Type %c en (%d,%d)\n", unite->suiv->suiv->genre, unite->suiv->suiv->posX, unite->suiv->suiv->posY);
    
    printf("\n");
    printf("Laquelle veux-tu utiliser ? ");
    scanf("%d", &result);
    
    switch(result) {
        case 1 : 
            
            printf("\n");
            printf("Quelle est ta destination ?");
            printf("\n");
            printf("Ligne : ");
            scanf("%d", &ligne);
            printf("Colonne : ");
            scanf("%d", &colonne);
            
            deplacerOuAttaquer(unite, monde, ligne, colonne);
            
            afficherPlateau(*monde);
            
            break;
        
        case 2 : 
            
            printf("\n");
            printf("Quelle est ta destination ?");
            printf("\n");
            printf("Ligne : ");
            scanf("%d", &ligne);
            printf("Colonne : ");
            scanf("%d", &colonne);
            
            deplacerOuAttaquer(unite->suiv, monde, ligne, colonne);
            
            afficherPlateau(*monde);
            
            break;
        
        case 3 : 
            
            printf("\n");
            printf("Quelle est ta destination ?");
            printf("\n");
            printf("Ligne : ");
            scanf("%d", &ligne);
            printf("Colonne : ");
            scanf("%d", &colonne);
            
            deplacerOuAttaquer(unite->suiv->suiv, monde, ligne, colonne);
            
            afficherPlateau(*monde);
            
            break;
            
        default: 
            printf("\n");
            printf("Tu n'as pas rentre de valeur adequate !\n");
    }
    
    // switch as tu fini ? o/n avec un while(result != o)
    // boucle infini
    
    printf("As-tu fini de jouer ? \n");
	printf("1 - Oui\n");
	printf("2 - Non\n");
    scanf("%d", &reponse);
    
	switch(reponse) {
        case 1 : 
            printf("Vous avez fini votre tour ! \n");
            break;
        
        case 2 : 
			printf("Tu ne peux pas rejouer, tu as donc fini, desole...");
			break;
			
		default: 
			printf("La valeur n'est pas valide. \n");

	}
}