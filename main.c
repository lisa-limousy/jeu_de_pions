#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "init.h"
#include "play.h"
#include "gestion.h"

int main(){
	
	
	
	printf("\n");
		printf("______________________________________________________________________________________________");
		printf("\n \n");
		printf("                                BIENVENUE DANS CE JEU DE PIONS ! \n");
		printf("______________________________________________________________________________________________");
		printf("\n \n");
		printf("2 jours (rouge et bleu) s'affronte dans un combat. Chacun detient 1 guerrier et 2 serfs.\n");
		printf("Ces unites peuvent se deplacer d'une case dans n'importe quelle direction.\n");
		printf("Si la case est occupee par une unite du joueur adverse, le pion peut l'attaquer\n");
		printf("Un guerrier gagne sur un serf et si les deux unites sont du meme type, c'est l'attaquant qui gagne.\n");
		printf("\n \n");
		printf("                                BONNE CHANCE ! \n");
		printf("\n \n");
        
	
		gererPartie();

	
    return 0;
}
