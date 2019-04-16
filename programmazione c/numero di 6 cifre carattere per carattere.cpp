/* programma che legge un numero di 6 cifre carattere per carattere */
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

/* funzione che legge una cifra decimale come carattere e restituisce il valore numerico corrispondete*/
/* @return valore intero corrispondente alla cifra inserita */

int leggiCifra()
{
	char cifra;	
	int cifraInt;
	
	cifra=getch();
	
	while(cifra<'0' || cifra>'9')
	{
		cifra=getch();
	}
	printf("%c",cifra);
	cifraInt=cifra-'0';
	return (cifraInt);
	
}


int main(int argc, char *argv[])
{
	int c, n, cifra, cifrap, peso;
	
	peso=100000;
	n=0;
	printf("Introduci un numero di 6 cifre: ");
	
	for(c=0; c<6; c++)
	{
		cifra=leggiCifra();
		cifrap=cifra*peso;
		n=n+cifrap;
		
		peso=peso/10;
	}
	
	printf("\n n= %d\n",n);
	system("PAUSE");
	return 0;
}
