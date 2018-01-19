#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "init.h"
#include "play.h"
#include "gestion.h"

void deplacerUnite(Unite *unite, Monde *monde, int destX, int destY){

	if((unite->posX == destX || unite->posX == destX+1 || unite->posX == destX-1) && (unite->posY == destY || unite->posY == destY+1 || unite->posY == destY-1)){
		if(destY < LARG && destX >= 0 && destY >= 0 && destX < LONG){
			 if(monde->plateau[destX][destY] == NULL) {
                 monde->plateau[unite->posX][unite->posY] = NULL;
			     monde->plateau[destX][destY] = unite;
			     unite->posX = destX;
			     unite->posY = destY;
			
			}
            else {
				printf("\n");
                printf("La case est occupee\n");
            }
		}
		else {
			printf("\n");
			printf("Erreur, retentez avec une valeur valide");
		}	
	}
}

void enleverUnite(Unite *unite, Monde *monde){
	
    Unite *actuel, *precedent;
    precedent = NULL;
	
    monde->plateau[unite->posX][unite->posY] = NULL;
	
	if(unite->couleur == BLEU){
		actuel = monde->bleu;
    }
    else {
        actuel = monde->rouge;
    }
    
    /*C'est le premier de la liste et le seul*/
    if(actuel == unite && actuel->suiv == NULL){
        if(unite->couleur == BLEU){
            monde->bleu = NULL;
        }
        else {
            monde->rouge = NULL;
        }
        free (unite);
    }
    else {
        while ( actuel != NULL ) {
            if ( actuel == unite ) {
                /*if (actuel->suiv != NULL ) {
                    precedent = actuel;
                    actuel = actuel->suiv;
                }*/
                if(precedent != NULL){
                    precedent->suiv = actuel->suiv;                    
                }
            //if precedent == NULL
                else {
                    if(unite->couleur == BLEU){
                        monde->bleu = actuel->suiv;
                    }
                    else {
                        monde->rouge = actuel->suiv;
                    }
                }
            }		
            precedent = actuel;
            actuel = actuel->suiv;
        }
    
        free (unite);
    }
        
}

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
    //Unite *adversaire = monde->plateau[destX][destY];
    
    //int resultAttaque;
    //resultAttaque = attaquer(unite, monde, destX, destY);
	
	if(destY > LARG-1 || destY < 0 || destX > LONG-1 || destX < 0){
		printf("\n");
        printf("Vous etes hors du plateau. \n");
        return -1;
	}
	if( (unite->posX) < destX -1 || (unite->posX) > destX +1 || (unite->posY) < destY -1 || (unite->posY) > destY +1 )	{
        printf("\n");
		printf("Vous ne pouvez avancer que d'une case. \n");
        return -2;
	}


	if(monde->plateau[destX][destY] != NULL && monde->plateau[destX][destY]->couleur == unite->couleur){
        printf("\n");
        printf("C'est un de vos pions ! \n");
		return -3;
	}

	if(monde->plateau[destX][destY] == NULL){
		deplacerUnite(unite, monde, destX, destY);
		return 1;
	}
    
	if(monde->plateau[destX][destY]->couleur != unite->couleur){
		if(attaquer(unite, monde, destX, destY) == 1){
			return 2;
		}
        else{
            return 3;
        }
	}
	return 0;
}

void placerUnite(Unite *unite, Monde *monde){
    int colonne, ligne, i;
    
    printf("Joueur ROUGE, ou veux-tu placer ton guerrier ? \n\n");
    printf("Colonne ? (entre 0 et 17) : ");
    scanf("%d", &colonne);
    printf("Ligne ? (entre 0 et 11) : ");
    scanf("%d", &ligne);
    creerUnite(GUERRIER, &unite);
	placerAuMonde(unite, monde, ligne, colonne, ROUGE);
    afficherPlateau(*monde);
    
    printf("Joueur BLEU, ou veux-tu placer ton guerrier ? \n\n");
    printf("Colonne ? (entre 0 et 17) : ");
    scanf("%d", &colonne);
    printf("Ligne ? (entre 0 et 11) : ");
    scanf("%d", &ligne);
    creerUnite(GUERRIER, &unite);
	placerAuMonde(unite, monde, ligne, colonne, BLEU);
    afficherPlateau(*monde);
    
    for (i=0 ; i<2 ; i++){
        printf("Joueur ROUGE, ou veux-tu placer ton serf ? \n\n");
        printf("Colonne ? (entre 0 et 17) : ");
        scanf("%d", &colonne);
        printf("Ligne ? (entre 0 et 11) : ");
        scanf("%d", &ligne);
        creerUnite(SERF, &unite);
	    placerAuMonde(unite, monde, ligne, colonne, ROUGE);
        afficherPlateau(*monde);
    
        printf("Joueur BLEU, ou veux-tu placer ton serf ? \n\n");
        printf("Colonne ? (entre 0 et 17) : ");
        scanf("%d", &colonne);
        printf("Ligne ? (entre 0 et 11) : ");
        scanf("%d", &ligne);
        creerUnite(SERF, &unite);
	    placerAuMonde(unite, monde, ligne, colonne, BLEU);
        afficherPlateau(*monde);
    }
    

}

void resultat(Unite *unite, Monde monde){
    
    if (monde.rouge == NULL){
        
        printf("______________________________________________________________________________________________");
	printf("\n \n");
	printf("                                LE JOUEUR BLEU A GAGNE ! \n");
		  printf("______________________________________________________________________________________________");
	printf("\n \n");
        
    }
    
    else {
        
        printf("______________________________________________________________________________________________");
	printf("\n \n");
	printf("                                LE JOUEUR ROUGE A GAGNE ! \n");
		  printf("______________________________________________________________________________________________");
	printf("\n \n");

    }
    
}