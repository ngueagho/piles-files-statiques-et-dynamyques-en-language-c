#ifndef _piles_H_INCLUDED
#define _piles_H_INCLUDED
struct neudpile
{
	int entier;
	struct neudpile*suiv;
};
typedef struct neudpile NEUDPILE ;

NEUDPILE* depiler( NEUDPILE* tetepile);
NEUDPILE* enpiler(int nombre, NEUDPILE* tetepile);
void afficher_pile(NEUDPILE* tetepile);

int depiler_tableau(int tetepiletab);
int enpiler_tableau(int nombre,int tetepiletab);
void afficher_pile_tableau(int tetepiletab) ;



#endif
