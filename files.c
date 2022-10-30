#include <stdio.h>
#include <stdlib.h>
#include "files.h"
int tabfile[5];


void enfiler_tableau(int *tetefiletab,int *queuefiletab,int nombre){
	if((*tetefiletab==-1)||(*queuefiletab==-1)){
		*tetefiletab=0;
		*queuefiletab=0;
		tabfile[*queuefiletab]=nombre;
	}
	else if((*tetefiletab-*queuefiletab)%5==1){
		printf("file pleine ...\n");
	}
	else{
		*queuefiletab=(*queuefiletab+1)%5;
		tabfile[*queuefiletab]=nombre;
	}
}

void defiler_tableau(int *tetefiletab,int *queuefiletab){
	if((*tetefiletab==-1)||(*queuefiletab==-1)){
		printf("file vide ...\n");
	}
	if((tabfile[*queuefiletab]==tabfile[*tetefiletab])||(*tetefiletab==*queuefiletab)){
		tabfile[*tetefiletab]=0;
		*tetefiletab=-1;
		*queuefiletab=-1;
	}
	else{
		tabfile[*tetefiletab]=0;
		*tetefiletab=(*tetefiletab+1)%5;
	}
}

void afficher_file_tableau(int tetefiletab,int queuefiletab){
	int i=tetefiletab;
	if((tetefiletab==-1)||(queuefiletab==-1)){
		printf("file vide ............\n");
	}
	else {
		if(i!=queuefiletab){
			while(i!=queuefiletab){
				printf("<--%d",tabfile[i]);
				i=(i+1)%5;	
			}	
		}
		printf("<--%d",tabfile[i]);
	}
	printf("\n");
}

//########################fin des fonction statiquees#########################



NEUDFILE* enfiler(int nombre,NEUDFILE* tetefile)
    {
        NEUDFILE*k;
        k=(NEUDFILE*)malloc(sizeof(NEUDFILE));
        k->entier=nombre;
        k->suiv=tetefile;
        tetefile=k;
        return tetefile;
    }

NEUDFILE* defiler(NEUDFILE* tetefile)
    {
        NEUDFILE*k , *j;
        if(tetefile==NULL){
            printf("file vide ...\n");
        }
        else if((tetefile->suiv)==NULL){
			 k=tetefile;
			 free(k);
			 tetefile=NULL;
		}
        else{
            k=tetefile;
            while((k->suiv)->suiv!=NULL){
            k=k->suiv;
            }
            j=k;
            k=k->suiv;
            j->suiv=NULL;
            free(k);
        }
        return tetefile;
    }

void afficher_file(NEUDFILE* tetefile)
    {
        NEUDFILE*k;
        if(tetefile==NULL){
            printf("file vide ...\n");
        }
        else{
            k=tetefile;
            while(k!=NULL){
                printf("-->%d",k->entier);
                k=k->suiv;
            }
            printf("\n");
        }
    }
