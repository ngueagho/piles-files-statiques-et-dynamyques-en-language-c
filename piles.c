#include <stdio.h>
#include <stdlib.h>
#include "piles.h"
int tabpile[5];

int enpiler_tableau(int nombre,int tetepiletab){
	if(tetepiletab==-1){
		tetepiletab=0;
		tabpile[tetepiletab]=nombre;
	}
	else if(tetepiletab==4){
		printf("pile pleine ...\n");
	}
	else{
		
		tetepiletab+=1;
		tabpile[tetepiletab]=nombre;	
	}
	return tetepiletab;
}


int depiler_tableau(int tetepiletab){
	if(tetepiletab==-1){
		printf("pile vide ...\n");
	}
	else if(tetepiletab==0){
			tetepiletab=-1;
			tabpile[tetepiletab]=0;	
	}
	else{
		tabpile[tetepiletab]=0;
		tetepiletab-=1;	
	}
	return tetepiletab;
}

void afficher_pile_tableau(int tetepiletab){
	int i;
	if(tetepiletab==-1){
		printf("pile vide ...\n");
	}
	else{
		for(i=tetepiletab;i>=0;i--){
			printf("-->%d",tabpile[i]);
		}	
	}
	printf("\n");
}
//########################fin des fonction statiquees#########################
NEUDPILE* enpiler(int nombre, NEUDPILE* tetepile){
	NEUDPILE* k;
	k=(NEUDPILE*)malloc(sizeof(NEUDPILE));
	k->entier=nombre;
	if(tetepile==NULL){
		k->suiv=NULL;
		tetepile=k;
	}
	else{
		k->suiv=tetepile;
		tetepile=k;
	}
	return tetepile;
}


NEUDPILE* depiler( NEUDPILE* tetepile){
	NEUDPILE* k;
	if(tetepile==NULL){
		printf("pile vide ...\n");
	}
	else{
		k=tetepile;
		tetepile=tetepile->suiv;
		free(k);
	}
	return tetepile;
}

void afficher_pile(NEUDPILE* tetepile){
	NEUDPILE* k;
	k=tetepile;
	if(tetepile==NULL){
		printf("pile vide ...\n");
	}
	else{
		while(k!=NULL){
			printf("-->%d",k->entier);
			k=k->suiv;
		}
	}	
	printf("\n");
}
