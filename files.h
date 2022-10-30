#ifndef _files_H_INCLUDED
#define _files_H_INCLUDED

struct neudfile
{
	int entier;
	struct neudfile*suiv;
};
typedef struct neudfile NEUDFILE ;


NEUDFILE* defiler(NEUDFILE* tetefile);
NEUDFILE* enfiler(int nombre,NEUDFILE* tetefile);
void afficher_file(NEUDFILE* tetefile);

void defiler_tableau(int *tetefiletab,int *queuefiletab);
void enfiler_tableau(int *tetefiletab,int *queuefiletab,int nombre);
void afficher_file_tableau(int tetefiletab,int queuefiletab);


#endif
