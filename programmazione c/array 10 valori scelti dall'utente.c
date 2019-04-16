#include <stdio.h>
#include <stdlib.h>
#define DIM 10
/* programma che permette l'introduzione di 10 valori in un array e li stampa */

int main(int argc, char *argv[]) 
{
	int vet[DIM];
	int i;

	for(i=0; i<DIM; i++)
	{
		printf("inserisci valore vet[%d] = \n", i);
		scanf("%d",&vet[i]);
	}
	for(i=0; i<DIM; i++)
	{
		printf("\nvet[%d] = %d\n",i, vet[i]);
	}
	return 0;
}
