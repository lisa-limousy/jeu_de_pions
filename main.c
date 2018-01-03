#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "init.h"

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
