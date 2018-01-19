#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "init.h"
#include "play.h"
#include "gestion.h"


void afficheListeJoueur(Monde *monde){
	printf("\n");
    printf("Unites ROUGE : ");
	while(monde->rouge!=NULL){
		printf("%c ", monde->rouge->genre);
		monde->rouge = monde->rouge->suiv;
	}
	printf("\n");
	
	printf("Unites BLEU : ");
	while(monde->bleu!=NULL){
		printf("%c ", monde->bleu->genre);
		monde->bleu = monde->bleu->suiv;
	}
	printf("\n");
}

void gererDemiTour(char joueur, Monde *monde){
    
    Unite *unite = NULL;
    int result, ligne, colonne; 
	char reponse = ' ';
    
    if(joueur == ROUGE){
        unite = monde->rouge;
    }
    else {
        unite = monde->bleu;
    }
    
    afficherPlateau(*monde);
    
    if (unite == NULL){
        printf("C'est fini");
    }
    else {
        printf("Voici la liste de tes unites : \n");
        printf("1 - Type %c en (%d,%d)\n", unite->genre, unite->posY, unite->posX);
            
        if(unite->suiv == NULL) {
            printf("\n");
        }
        else {
            printf("2 - Type %c en (%d,%d)\n", unite->suiv->genre, unite->suiv->posY, unite->suiv->posX);
        
            if(unite->suiv->suiv == NULL){
                printf("\n");
            }
            else {
                printf("3 - Type %c en (%d,%d)\n", unite->suiv->suiv->genre, unite->suiv->suiv->posY, unite->suiv->suiv->posX);
            }
        }
    
    
    

    
    
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
			printf("\n");
    }
    

    // bug -> "as-tu fini" s'affiche deux fois
    
    while (reponse != 'o') {
		printf("As-tu fini de jouer ? (o/n) ");
		printf("\n");
    	scanf("%c", &reponse);
	}
    }
}

void gererTour(Monde *monde){
	
	monde->tour = 1;
    printf("\n");
		          printf("______________________________________________________________________________________________");
	printf("\n \n");
	printf("                                C'EST LE TOUR %d DU JOUEUR ROUGE ! \n", monde->tour);
		  printf("______________________________________________________________________________________________");
	printf("\n \n");
	gererDemiTour(ROUGE, monde);
    
    if (monde->bleu != NULL){
        printf("______________________________________________________________________________________________");
	printf("\n \n");
	printf("                                C'EST LE TOUR %d DU JOUEUR BLEU ! \n", monde->tour);
		printf("______________________________________________________________________________________________");
	printf("\n \n");
	gererDemiTour(BLEU, monde);
        
    }
            
    
    (monde->tour)++;
    
}

void viderMonde(Monde *monde){
	initializerMonde(monde);
	free(monde->rouge);
	free(monde->bleu);
}

void gererPartie(void){
	
	Monde monde;
	UListe unite = NULL;
	
	initializerMonde(&monde);
    
    afficherPlateau(monde);
    
    placerUnite(unite, &monde);
    
    while (monde.rouge != NULL && monde.bleu != NULL){
        gererTour(&monde);
    }
    
    resultat(unite, monde);
	
}