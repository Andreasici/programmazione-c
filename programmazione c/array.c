#include <stdio.h>
#include <stdlib.h>

/* programma che gioca con gli array */

int main(int argc, char *argv[]) 
{
	int vet[5];
	int i; //valore dell'indice//
	
	vet[0]=0;
	vet[1]=10;
	vet[2]=20;
	vet[3]=30;
	vet[4]=40;
	
	for(i=0; i<5; i++)
	{
		vet[i]=0;
	}
	
	for(i=0; i<5; i++) //vedere valori dell'array//
	{
		printf("vet[%d] = %d\n", i, vet[i]);
	}
	
	return 0;
}
