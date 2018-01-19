#ifndef GAME_PLAY
#define GAME_PLAY

#include "init.h"

void deplacerUnite(Unite *unite, Monde *monde, int destX, int destY);
void enleverUnite(Unite *unite, Monde *monde);
int attaquer(Unite *unite, Monde *monde, int destX, int destY);
int deplacerOuAttaquer(Unite *unite, Monde *monde, int destX, int destY);
void placerUnite(Unite *unite, Monde *monde);
void resultat(Unite *unite, Monde monde);

#endif