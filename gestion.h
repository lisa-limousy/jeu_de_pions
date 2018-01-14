#ifndef GESTION
#define GESTION

#include "init.h"
#include "play.h"

void afficheListeJoueur(Monde *monde);
void gererDemiTour(char joueur, Monde *monde);
void gererTour(Monde *monde);
void viderMonde(Monde *monde);
void gererPartie(void);

#endif