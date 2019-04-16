/* programma che calcola e stampa i primi 4 numeri perfetti */
#include<stdio.h>
#include<stdlib.h>

/* funzione che calcola la somma dei divisori di n escluso n */
/* @param n numero di cui vengono sommati i divisori */
/* @return sdiv somma dei divisori eccetto n */

int sommaDiv(int n)
{
	int sdiv, div, r;
	sdiv=0;
	div=1;
	while(div<=n/2)
	{
		r=n%div;
		if(r==0)
		{
			sdiv=sdiv+div;
			
		}
		div++;
	}
	return (sdiv);
}

int main(int argc, char *argv[])
{
	int cperf, n, sdiv;
	cperf=0;
	n=1;
	
	while(cperf<4)
	{
		sdiv=sommaDiv(n);
		if(n==sdiv)
		{
			printf("%d\n",n);
			cperf++;
		}
		n++;
	}
	
	system("PAUSE");	
return 0;
	
}
