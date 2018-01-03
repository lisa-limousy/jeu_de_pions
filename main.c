//first commit lisa
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define LONG 12
#define LARG 18

/* l’origine est en haut a gauche */
#define ROUGE ’R’ //identifiant du premier joueur
#define BLEU ’B’ //identifiant du deuxi`eme joueur

/* les genres d’unites */
#define SERF ’s’
#define GUERRIER ’g’

typedef struct unite{
    int posX, posY; /*pour stocker les coordonn´ees de l’unit´e*/
    char couleur; /* ROUGE ou BLEU */
    char genre; /* GUERRIER ou SERF*/
    struct unite *suiv; /* liste des unit´es suivantes*/
} Unite;

typedef Unite* UListe;

typedef struct monde{
    Unite *plateau[LONG][LARG];
    int tour; /* Numero du tour */
    UListe rouge, bleu; /*Listes des deux joueurs*/
} Monde;

//mettre la valeur de tous ses pointeurs et des cases du plateau à NULL
void initializerMonde(Monde *monde){
    monde->tour = 0;
    monde->plateau[LONG][LARG] = NULL;
    //plateau[LONG][LARG] = {0};
    monde->rouge = NULL;
    monde->bleu = NULL;
}

int afficherPlateau(Monde monde){
	int i, j;
	for (i = 0; i < LONG; i++){
        for(i=0; i<=LONG; i++){
        	printf("+---");
    	}
    	printf("+\n");
        for (j = 0; j < LARG; j++){
            printf("| %c ", monde.plateau[LONG][LARG]);
        }
        printf("|\n");
	}
	for(i=0; i<=LONG; i++){
        printf("+---");
    }
    printf("+\n");
}

//type GUERRIER ou SERF
int creerUnite(char type, UListe *unite){

}

int main(){
    Monde monde;
    initializerMonde(&monde);
    afficherPlateau(monde);
    return 0;
}

/*typedef char Tab[10][10];

void ligne()
{
    for(int i=0; i<=9; i++)
    {
        printf("+---");
    }
    printf("+\n");
}

void tracerCadre(Tab Bataille){
	for (int i = 0; i < 10; i++){
        ligne();
        for (int j = 0; j < 10; j++){
            printf("| %c ", Bataille[i][j]);
        }
        printf("|\n");
	}
	ligne();
}

int tirerl(Tab Bataille)
{
	int i;
	printf ("Quelle ligne?");
	scanf("%d", &i);
	return i-1;
}

int tirerc(Tab Bataille)
{
	int j;
	printf ("Quelle colonne?");
	scanf("%d", &j);
	return j-1;
}
int main(void)
{
	int i,j,nb;
	nb=8;
    Tab Bataille;
    for (i=0; i<10; i++)
    {
    	for (j=0; j<10; j++)
    	{
    		Bataille[i][j]=' ';
    	}
    }

    while(nb>0)
    {
    	i=tirerl(Bataille);
    	j=tirerc(Bataille);
    	Bataille[i][j]='X';
    	nb--;
    }
    tracerCadre(Bataille);
    nb=8;
    while(nb>0)
    {
    	i=tirerl(Bataille);
    	j=tirerc(Bataille);
    	switch (Bataille[i][j])
    	{
    		case 'X':
    		{
    			Bataille[i][j]='T';
    			nb--;
    		}
    		break;
    		case ' ':
    		{
    			Bataille[i][j] = 'O';
    		}
    		break;
    	}
    	tracerCadre(Bataille);
     }

int cpt;

	int nbe=1;
	int nbes=30;
	printf("combien de lignes ? \n");
	scanf("%d",&nb);
	for (cpt=1; cpt<=nb; cpt++)
	{
        for(i=1; i<=nbes; i++)
            printf(" ");
        for(i=1; i<=nbe; i++)
            printf("*");
        printf("\n");
        nbes--;
        nbe+=2;
	}
	for (cpt=1; cpt<=2; cpt++)
	{
		for(i=1; i<=30-1; i++)
			printf(" ");
		printf("***");
		printf("\n");
	}
	return 0;
}*/
