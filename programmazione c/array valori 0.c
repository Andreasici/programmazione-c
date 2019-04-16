#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	int vet[5];
	int i;
	
	for(i=0; i<5; i++)
	{
		vet[i]=0;
		printf("vet[%d] = %d",i,vet[i]);
	}
	
	return 0;
}
